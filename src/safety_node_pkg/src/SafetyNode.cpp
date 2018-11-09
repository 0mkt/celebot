#include "SafetyNode.h"

//------------------------------------------------------------------------------
//				    --> READ NODES CONFIG <--
//------------------------------------------------------------------------------
bool ReadNodesConfig(ros::NodeHandle nh){

    if (!nh.getParam("/nodes_config/safety_node/id", nodeId)) return false;
    if (!nh.getParam("/nodes_config/main_node/id", mainNodeId)) return false;
    if (!nh.getParam("/nodes_config/servo_control_node/id", servoControlNodeId)) return false;

    return true;
} 

//------------------------------------------------------------------------------
//				       --> ROS CALLBACKS <--
//------------------------------------------------------------------------------
bool ChangeNodeStateServiceCallback(custom_msg_pkg::ChangeNodeStateSrv::Request &req,
                 custom_msg_pkg::ChangeNodeStateSrv::Response &res)
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

    //if (callerId != mainNodeId) return false;
    if (_programState == BREACH && targetState != DISARMED) return false;
    if (_programState == FAILURE && targetState != INITIALIZATION) return false;

    return true;
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
        case DISARMED:
            desc = "[DISARMED]";
        break;
        case ARMED:
            desc = "[ARMED]";
        break;
        case SHUTDOWN:
            desc = "[SHUTDOWN]";
        break;
        case BREACH:
            desc = "[BREACH]";
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

    // establish connection with external safety system

    bool allGood = EvaluateSafetySystemCondition(true, false);
    if (!allGood) return;

    ChangeProgramStateTo(DISARMED);
}

//-----------------------------------------------------------------------------
//				            DISARMED
// 
//-----------------------------------------------------------------------------
void Disarmed(){

    bool allGood = EvaluateSafetySystemCondition(true, false);
    if (!allGood) return;
}

//-----------------------------------------------------------------------------
//				              ARMED
// 
//-----------------------------------------------------------------------------
void Armed(){
    
    bool allGood = EvaluateSafetySystemCondition(true, true);
    if (!allGood) return;
}

//-----------------------------------------------------------------------------
//				            SHUTDOWN
// 
//-----------------------------------------------------------------------------
void Shutdown(){

    // disconnect external safety system

    _shutdown = true;
}

//-----------------------------------------------------------------------------
//				             BREACH
// 
//-----------------------------------------------------------------------------
void Breach(){

    bool allGood = EvaluateSafetySystemCondition(true, false);
    if (!allGood) return;

    // wait for reset signal from main node
    // goto Disarmed state 
}

//-----------------------------------------------------------------------------
//				             FAILURE
// 
//-----------------------------------------------------------------------------
void Failure(){

    // wait for restart
    // goto Initialization state
}

//------------------------------------------------------------------------------
//				           --> MAIN <--
//------------------------------------------------------------------------------
int main(int argc, char** argv) {

    ros::init(argc, argv, "safety_node");
    ros::NodeHandle nh;
    ros::Rate loop_rate(100);

    if (!ReadNodesConfig(nh)) {
        ROS_ERROR("Cannot read configuration from parameter server!");
        ROS_ERROR("Node shutting down!");
        return 0;
    }
        
    ros::Publisher pub = nh.advertise<std_msgs::Int32>("safety_node/state", 1000);
    ros::ServiceServer changeNodeStateService = nh.advertiseService("safety_node/change_node_state_service", ChangeNodeStateServiceCallback);

    ROS_INFO("Safety Node started.");
    ChangeProgramStateTo(INITIALIZATION);

    while(!_shutdown && ros::ok()){

        switch(_programState){

            case INITIALIZATION:
                Initialization();
                break;

            case DISARMED:
                Disarmed();
                break;

            case ARMED:
                Armed();
                break;
            
            case SHUTDOWN:
                Shutdown();
                break;

            case BREACH:
                Breach();
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
        loop_rate.sleep();
    }
    
    usleep(5000000);
    return 0;
}

//------------------------------------------------------------------------------
//				  --> SAFETY SYSTEM CONDITION <--
//------------------------------------------------------------------------------
bool EvaluateSafetySystemCondition(bool shouldBeConnected, bool shouldTransmitSafetyOkSignal){

    int syscon = ALL_GOOD;

    if (shouldBeConnected && !SafetySystemConnected()) syscon = COMM_FAILURE;
    else if (shouldTransmitSafetyOkSignal && !SafetySystemOkSignalActive()) syscon = SAFETY_BREACH;
    
    switch(syscon){

        case COMM_FAILURE:
            ChangeProgramStateTo(FAILURE);
            return false;
            break;

        case SAFETY_BREACH:
            ChangeProgramStateTo(BREACH);
            return false;
            break;
    }

    return true;
} 
