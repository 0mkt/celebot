#include "ServoControlNode.h"

//------------------------------------------------------------------------------
//				    --> READ NODES CONFIG <--
//------------------------------------------------------------------------------
bool ReadNodesConfig(ros::NodeHandle nh){

    // self
    if (!nh.getParam("/nodes_config/servo_control_node/id", nodeId)) return false;

    // main
    if (!nh.getParam("/nodes_config/main_node/id", mainNodeId)) return false;

    // safety
    if (!nh.getParam("/nodes_config/safety_node/id", safetyNodeId)) return false;
    if (!nh.getParam("/nodes_config/safety_node/states/armed", safetyNodeArmedState)) return false;

    return true;
} 

//------------------------------------------------------------------------------
//				       --> ROS CALLBACKS <--
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//			CHANGE NODE STATE SERVICE PUBLISHER CALLBACK
//------------------------------------------------------------------------------
bool ChangeNodeStateServicePublisherCallback(custom_msg_pkg::ChangeNodeStateServiceMsg::Request &req,
                 custom_msg_pkg::ChangeNodeStateServiceMsg::Response &res)
{  
    ROS_INFO("ChangeNodeStateServiceCallback has been called"); 
    ROS_INFO("Request Data==> targetState=%d, callerId=%d", req.targetState, req.callerId);

    bool reqValid = ValidateChangeStateRequest(req.targetState, req.callerId);
    
    if (reqValid) {
        ROS_INFO("Request accepted!");

        ChangeProgramStateTo(req.targetState);
        res.result = _programState;
        res.errorDesc = "All good";
        
    } else {
        ROS_WARN("Request is invalid. Rejecting request!");

        res.result = -1; 
        res.errorDesc = "Request was rejected.";
    } 

    return true;
}

bool ValidateChangeStateRequest(int targetState, int callerId){

    if (callerId != mainNodeId) return false;
    if (_programState == EMERGENCY && targetState != STANDBY) return false;
    if (_programState == FAILURE && targetState != INITIALIZATION) return false;

    return true;
}

//------------------------------------------------------------------------------
//			SAFETY NODE STATE TOPIC SUBSCRIBER CALLBACK
//------------------------------------------------------------------------------
void SafetyNodeStateTopicSubscriberCallback(const std_msgs::Int32::ConstPtr& msg)
{
    _safetyNodeState = msg->data;
}

//------------------------------------------------------------------------------
//				      --> PROGRAM STATES <--
//------------------------------------------------------------------------------
void ChangeProgramStateTo(int programState) {
	_programState = programState;

    const char* desc;

    switch(programState){
        case INITIALIZATION:
            desc = "[INITIALIZATION]";
        break;
        case STANDBY:
            desc = "[STANDBY]";
        break;
        case MOTION:
            desc = "[MOTION]";
        break;
        case SHUTDOWN:
            desc = "[SHUTDOWN]";
        break;
        case ALARM:
            desc = "[ALARM]";
        break;
        case EMERGENCY:
            desc = "[EMERGENCY]";
        break;
        case FAILURE:
            desc = "[FAILURE]";
        break;
    }

    ROS_INFO_STREAM("Program state changed to: " << desc);
}

//------------------------------------------------------------------------------
//				          INITIALIZATION
// 
//------------------------------------------------------------------------------
void Initialization(){

    ConnectServos(servos);
    bool allGood = EvaluateMotionSystemCondition(true, false);
    if (!allGood) return;

    usleep(1000000);
    UpdateServosStatuses(servos);
    EnableServos(servos);

    usleep(1000000);
    UpdateServosStatuses(servos);

    allGood = EvaluateMotionSystemCondition(true, true);
    if (!allGood) return;

    ChangeProgramStateTo(STANDBY);
}

//-----------------------------------------------------------------------------
//				             STANDBY
// 
//-----------------------------------------------------------------------------
void Standby(){
    
    UpdateServosStatuses(servos);

    bool allGood = EvaluateMotionSystemCondition(true, true);
    if (!allGood) return;

    StopServos(servos);
}

//-----------------------------------------------------------------------------
//				             MOTION
// 
//-----------------------------------------------------------------------------
void Motion(){

    UpdateServosStatuses(servos);

    bool allGood = EvaluateMotionSystemCondition(true, true);
    if (!allGood) return;

    bool motionAllowed = IsMotionAllowed(_safetyNodeState);
    if (!motionAllowed){
        ChangeProgramStateTo(STANDBY); // Stop Motion Func
        return;
    }


}

//-----------------------------------------------------------------------------
//				            SHUTDOWN
// 
//-----------------------------------------------------------------------------
void Shutdown(){

    UpdateServosStatuses(servos);

    bool allGood = EvaluateMotionSystemCondition(true, true);
    if (!allGood) return;

    StopServos(servos);
    if (!AllServosStopped(servos)) return;

    DisableServos(servos);
    usleep(1000000);
    DisconnectServos(servos);

    _shutdown = true;
}

//-----------------------------------------------------------------------------
//				              ALARM
// 
//-----------------------------------------------------------------------------
void Alarm(){

}

//-----------------------------------------------------------------------------
//				            EMERGENCY
// 
//-----------------------------------------------------------------------------
void Emergency(){

}

//-----------------------------------------------------------------------------
//				             FAILURE
// 
//-----------------------------------------------------------------------------
void Failure(){

}

//------------------------------------------------------------------------------
//				           --> MAIN <--
//------------------------------------------------------------------------------
int main(int argc, char** argv) {

    ros::init(argc, argv, "servo_control_node");
    ros::NodeHandle nh;

    if (!ReadNodesConfig(nh)) {
        ROS_ERROR("Cannot read configuration from parameter server!");
        ROS_ERROR("Node shutting down!");
        return 0;
    }
        
    ros::Publisher pub = nh.advertise<std_msgs::Int32>("servo_control_node/state", 1000);
    ros::ServiceServer changeNodeStateService = nh.advertiseService("servo_control_node/change_node_state_service", ChangeNodeStateServicePublisherCallback);

    ros::Subscriber sub = nh.subscribe("safety_node/state", 1000, SafetyNodeStateTopicSubscriberCallback);

    ROS_INFO("Servo Control Node started.");
    ChangeProgramStateTo(INITIALIZATION);

    while(!_shutdown && ros::ok()){

        switch(_programState){

            case INITIALIZATION:
                Initialization();
                break;

            case STANDBY:
                Standby();
                break;

            case MOTION:
                Motion();
                break;
            
            case SHUTDOWN:
                Shutdown();
                break;

            case ALARM:
                Alarm();
                break;

            case EMERGENCY:
                Emergency();
                break;

            case FAILURE:
                Failure();
                break;
            
            default:
                break;
        }

        std_msgs::Int32 msg;
        msg.data = _programState;

        pub.publish(msg);
        ros::spinOnce();
        usleep(10000);
    }
    
    usleep(5000000);
    return 0;
}

//------------------------------------------------------------------------------
//				  --> MOTION SYSTEM CONDITION <--
//------------------------------------------------------------------------------
bool EvaluateMotionSystemCondition(bool shouldBeConnected, bool shouldBeEnabled){

    int syscon = ALL_GOOD;

    if (shouldBeConnected && !AllServosConnected(servos)) syscon = COMM_FAILURE;
    else if (shouldBeEnabled && !AllServosEnabled(servos)) syscon = AVAIL_FAILURE;
    else if (AnyServoInEmergencyState(servos)) syscon = IN_EMERGENCY;
    else if (AnyServoInAlarmState(servos)) syscon = IN_ALARM;
    
    switch(syscon){

        case COMM_FAILURE:
            ChangeProgramStateTo(FAILURE);
            return false;
            break;

        case AVAIL_FAILURE:
            ChangeProgramStateTo(FAILURE);
            return false;
            break;

        case IN_EMERGENCY:
            ChangeProgramStateTo(EMERGENCY);
            return false;
            break;

        case IN_ALARM:
            ChangeProgramStateTo(ALARM);
            return false;
            break;
    }

    return true;
} 

//------------------------------------------------------------------------------
//				     --> ALLOW MOTION <--
//------------------------------------------------------------------------------
bool IsMotionAllowed(int safetyNodeState){
    return (safetyNodeState == safetyNodeArmedState);
}