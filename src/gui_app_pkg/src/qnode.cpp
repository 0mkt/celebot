/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "qnode.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace qtros {

/*****************************************************************************
** Callbacks
*****************************************************************************/

void QNode::MainNodeStateTopicSubscriberCallback(const std_msgs::Int32::ConstPtr& msg)
{
    mainNodeState = msg->data;
    Q_EMIT guiShowMainNodeStateDesc(mainNodeStatesMap[mainNodeState]);
}

void QNode::SafetyNodeStateTopicSubscriberCallback(const std_msgs::Int32::ConstPtr& msg)
{
    safetyNodeState = msg->data;
    Q_EMIT guiShowSafetyNodeStateDesc(safetyNodeStatesMap[safetyNodeState]);
}

void QNode::ServosNodeStateTopicSubscriberCallback(const std_msgs::Int32::ConstPtr& msg)
{
    servosNodeState = msg->data;
    Q_EMIT guiShowServosNodeStateDesc(servosNodeStatesMap[servosNodeState]);
}

void QNode::ServosNodeServosDataTopicSubscriberCallback(const custom_msg_pkg::EziServosData::ConstPtr& msg)
{
    Q_EMIT guiShowServosNodeServosData(*msg);
}

/*****************************************************************************
** Implementation
*****************************************************************************/

    QNode::QNode(int argc, char** argv) :
            init_argc(argc),
            init_argv(argv) {}

    QNode::~QNode() {
        if (ros::isStarted()) {
            ros::shutdown(); // explicitly needed since we use ros::start();
            ros::waitForShutdown();
        }
        wait();
    }

    bool QNode::init() {
        ros::init(init_argc, init_argv, "qtros");
        if (!ros::master::check()) {
            return false;
        }
        ros::start(); // explicitly needed since our nodehandle is going out of scope.
        ros::NodeHandle nh;

        //Load configuration from ros parameter server
        LoadParametersFromServer();

        // Add your ros communications here.
        // Register GUI topic publisher
        gui_publisher = nh.advertise<std_msgs::String>("gui", 1000);

        // Register GUI topic subscribers
        mainNode_state_subscriber = nh.subscribe("main_node/state", 1000, &QNode::MainNodeStateTopicSubscriberCallback, this);
        safetyNode_state_subscriber = nh.subscribe("safety_node/state", 1000, &QNode::SafetyNodeStateTopicSubscriberCallback, this);
        servosNode_state_subscriber = nh.subscribe("servo_control_node/state", 1000, &QNode::ServosNodeStateTopicSubscriberCallback, this);
        servosNode_servosData_subscriber = nh.subscribe("servo_control_node/servos_data", 1000, &QNode::ServosNodeServosDataTopicSubscriberCallback, this);

        // Register GUI service clients
        safetyNode_changeState_srvclient =
                nh.serviceClient<custom_msg_pkg::ChangeNodeStateSrv>("/safety_node/change_node_state_service");

        servosNode_changeState_srvclient =
                nh.serviceClient<custom_msg_pkg::ChangeNodeStateSrv>("/servo_control_node/change_node_state_service");

        start();
        return true;
    }

    bool QNode::init(const std::string& master_url, const std::string& host_url) {
        std::map<std::string, std::string> remappings;
        remappings["__master"] = master_url;
        remappings["__hostname"] = host_url;
        ros::init(remappings, "qtros");
        if (!ros::master::check()) {
            return false;
        }
        ros::start(); // explicitly needed since our nodehandle is going out of scope.
        ros::NodeHandle nh;

        //Load configuration from ros parameter server
        LoadParametersFromServer();

        // Add your ros communications here.
        gui_publisher = nh.advertise<std_msgs::String>("gui", 1000);

        mainNode_state_subscriber = nh.subscribe("main_node/state", 1000, &QNode::MainNodeStateTopicSubscriberCallback, this);
        safetyNode_state_subscriber = nh.subscribe("safety_node/state", 1000, &QNode::SafetyNodeStateTopicSubscriberCallback, this);
        servosNode_state_subscriber = nh.subscribe("servo_control_node/state", 1000, &QNode::ServosNodeStateTopicSubscriberCallback, this);
        servosNode_servosData_subscriber = nh.subscribe("servo_control_node/servos_data", 1000, &QNode::ServosNodeServosDataTopicSubscriberCallback, this);

        start();
        return true;
    }

    void QNode::run() {

        ros::Rate loop_rate(100);
        int count = 0;
        while (ros::ok()) {

            std_msgs::String msg;
            std::stringstream ss;
            ss << "gui heartbeat " << count;
            msg.data = ss.str();
            gui_publisher.publish(msg);

            CheckWhichNodesAreRunning();

            ros::spinOnce();
            loop_rate.sleep();
            ++count;
        }
        std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
        Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
    }

    // General methods
    void QNode::LoadParametersFromServer(){

        // FAKE LOAD FOR NOW
        mainNodeStatesMap[-1] = "not running";
        mainNodeStatesMap[0] = "running";

        safetyNodeStatesMap[-1] = "not running";
        safetyNodeStatesMap[0] = "initialization";
        safetyNodeStatesMap[1] = "disarmed";
        safetyNodeStatesMap[2] = "armed";
        safetyNodeStatesMap[3] = "shutdown";
        safetyNodeStatesMap[4] = "breach";
        safetyNodeStatesMap[5] = "failure";

        servosNodeStatesMap[-1] = "not running";
        servosNodeStatesMap[0] = "initialization";
        servosNodeStatesMap[1] = "standby";
        servosNodeStatesMap[2] = "motion";
        servosNodeStatesMap[3] = "shutdown";
        servosNodeStatesMap[4] = "alarm";
        servosNodeStatesMap[5] = "emergency";
        servosNodeStatesMap[6] = "failure";
    }

    void QNode::CheckWhichNodesAreRunning(){

        std::vector<std::string> v;
        if(!ros::master::getNodes(v))
        {
            ROS_ERROR("getNodes() error!");
            return;
        }

        // check if following nodes are running
        int mainNodeFound = std::find(v.begin(), v.end(), "/main_node") != v.end();
        int safetyNodeFound = std::find(v.begin(), v.end(), "/safety_node") != v.end();
        int servosNodeFound = std::find(v.begin(), v.end(), "/servo_control_node") != v.end();

        if (mainNodeFound <= 0){
            mainNodeState = -1;
            Q_EMIT guiShowMainNodeStateDesc(mainNodeStatesMap[mainNodeState]);
        }

        if (safetyNodeFound <= 0){
            safetyNodeState = -1;
            Q_EMIT guiShowSafetyNodeStateDesc(safetyNodeStatesMap[safetyNodeState]);
        }

        if (servosNodeFound <= 0){
            servosNodeState = -1;
            Q_EMIT guiShowServosNodeStateDesc(servosNodeStatesMap[servosNodeState]);
        }
    }

    // Safety Commands
    void QNode::SafetyArm(){

        custom_msg_pkg::ChangeNodeStateSrv msg;
        msg.request.callerId = 0;
        msg.request.targetState = 2;

        if (safetyNode_changeState_srvclient.call(msg)) ROS_INFO("Request sent to Safety Node: change state to [ARMED]");
        else ROS_INFO("Error while calling Safety Node changeState service!");
    }

    void QNode::SafetyDisarm(){

        custom_msg_pkg::ChangeNodeStateSrv msg;
        msg.request.callerId = 0;
        msg.request.targetState = 1;

        if (safetyNode_changeState_srvclient.call(msg)) ROS_INFO("Request sent to Safety Node: change state to [DISARMED]");
        else ROS_INFO("Error while calling Safety Node changeState service!");
    }

    void QNode::SafetyReset(){

        custom_msg_pkg::ChangeNodeStateSrv msg;
        msg.request.callerId = 0;
        msg.request.targetState = 1;

        if (safetyNode_changeState_srvclient.call(msg)) ROS_INFO("Request sent to Safety Node: reset safety!");
        else ROS_INFO("Error while calling Safety Node changeState service!");
    }

    void QNode::SafetyReinitialize(){

        custom_msg_pkg::ChangeNodeStateSrv msg;
        msg.request.callerId = 0;
        msg.request.targetState = 0;

        if (safetyNode_changeState_srvclient.call(msg)) ROS_INFO("Request sent to Safety Node: change state to [INITIALIZATION]");
        else ROS_INFO("Error while calling Safety Node changeState service!");
    }

    void QNode::SafetyShutdown(){

        custom_msg_pkg::ChangeNodeStateSrv msg;
        msg.request.callerId = 0;
        msg.request.targetState = 3;

        if (safetyNode_changeState_srvclient.call(msg)) ROS_INFO("Request sent to Safety Node: change state to [SHUTDOWN]");
        else ROS_INFO("Error while calling Safety Node changeState service!");
    }

    // Servo Control Commands
    void QNode::ServosMotion(){

        custom_msg_pkg::ChangeNodeStateSrv msg;
        msg.request.callerId = 0;
        msg.request.targetState = 2;

        if (servosNode_changeState_srvclient.call(msg)) ROS_INFO("Request sent to Servo Control Node: change state to [MOTION]");
        else ROS_INFO("Error while calling Servo Control Node changeState service!");
    }

    void QNode::ServosStandby(){

        custom_msg_pkg::ChangeNodeStateSrv msg;
        msg.request.callerId = 0;
        msg.request.targetState = 1;

        if (servosNode_changeState_srvclient.call(msg)) ROS_INFO("Request sent to Servo Control Node: change state to [STANDBY]");
        else ROS_INFO("Error while calling Servo Control Node changeState service!");
    }

    void QNode::ServosResetAlarm(){

        custom_msg_pkg::ChangeNodeStateSrv msg;
        msg.request.callerId = 0;
        msg.request.targetState = 1;

        if (servosNode_changeState_srvclient.call(msg)) ROS_INFO("Request sent to Servo Control Node: reset alarms!");
        else ROS_INFO("Error while calling Servo Control Node changeState service!");
    }

    void QNode::ServosReinitialize(){

        custom_msg_pkg::ChangeNodeStateSrv msg;
        msg.request.callerId = 0;
        msg.request.targetState = 0;

        if (servosNode_changeState_srvclient.call(msg)) ROS_INFO("Request sent to Servo Control Node: change state to [INITIALIZATION]");
        else ROS_INFO("Error while calling Servo Control Node changeState service!");
    }

    void QNode::ServosShutdown(){

        custom_msg_pkg::ChangeNodeStateSrv msg;
        msg.request.callerId = 0;
        msg.request.targetState = 3;

        if (servosNode_changeState_srvclient.call(msg)) ROS_INFO("Request sent to Servo Control Node: change state to [SHUTDOWN]");
        else ROS_INFO("Error while calling Servo Control Node changeState service!");
    }

}  // namespace qtros
