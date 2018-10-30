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
    }

    ROS_INFO_STREAM("Program state changed to: " << desc);
}

//------------------------------------------------------------------------------
//				          INITIALIZATION
// 
//------------------------------------------------------------------------------
void Initialization(){

    // establish connection with external safety system

    // check connection with external system
    // if ok - goto Disarmed state.
    // if not ok - goto Failure state
}

//-----------------------------------------------------------------------------
//				            DISARMED
// 
//-----------------------------------------------------------------------------
void Disarmed(){

    // check connection with external system
    // if not ok goto Failure state
}

//-----------------------------------------------------------------------------
//				              ARMED
// 
//-----------------------------------------------------------------------------
void Armed(){
    
    // check connection with external system
    // if not ok goto Failure state

    // check safetyOk signal from external system
    // if not ok goto Breach state
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

    ros::init(argc, argv, "safety_node");
    ros::NodeHandle nh;

    if (!ReadNodesConfig(nh)) {
        ROS_ERROR("Cannot read configuration from parameter server!");
        ROS_ERROR("Node shutting down!");
        return 0;
    }
        
    ros::Publisher pub = nh.advertise<std_msgs::Int32>("safety_node/state", 1000);
    ros::ServiceServer changeStateService = nh.advertiseService("safety_node/change_state_service", ChangeStateServiceCallback);

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
        usleep(10000);
    }
    
    usleep(5000000);
    return 0;
}