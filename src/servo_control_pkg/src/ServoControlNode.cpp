#include "ServoControlNode.h"

//------------------------------------------------------------------------------
//				    --> READ NODES CONFIG <--
//------------------------------------------------------------------------------
bool ReadNodesConfig(ros::NodeHandle nh){

    if (!nh.getParam("/nodes_config/servo_control_node/id", nodeId)) return false;
    if (!nh.getParam("/nodes_config/main_node/id", mainNodeId)) return false;
    if (!nh.getParam("/nodes_config/safety_node/id", safetyNodeId)) return false;

    return true;
} 

//------------------------------------------------------------------------------
//				       --> ROS CALLBACKS <--
//------------------------------------------------------------------------------
bool ChangeStateServiceCallback(custom_msg_pkg::SCNChangeStateServiceMsg::Request &req,
                 custom_msg_pkg::SCNChangeStateServiceMsg::Response &res)
{  
  ROS_INFO("ChangeStateServiceCallback has been called"); 
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

    //change state from STANDBY to MOTION or to SHUTDOWN [accept req only from main node]
    if (_programState == STANDBY && (targetState == MOTION || targetState == SHUTDOWN)){
        return callerId == mainNodeId;
    }

    //change state from MOTION to STANDBY or to SHUTDOWN [accept req only from main node]
    if (_programState == MOTION && (targetState == STANDBY || targetState == SHUTDOWN)){
        return callerId == mainNodeId;
    }

    //change state from EMERGENCY or to EMERGENCY [accept req only from safety node]
    if (_programState == EMERGENCY || targetState == EMERGENCY){
        return callerId == safetyNodeId;
    }

    return false;
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

    // Stop servos, send ext signal about motion system alarm
    //while(getchar()!='\n')

    //ChangeProgramStateTo(INITIALIZATION);
}

//-----------------------------------------------------------------------------
//				            EMERGENCY
// 
//-----------------------------------------------------------------------------
void Emergency(){

    // Stop servos, send ext signal about motion system emergency
    //while(getchar()!='\n')

    //ChangeProgramStateTo(INITIALIZATION);
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
    ros::ServiceServer changeStateService = nh.advertiseService("servo_control_node/change_state_service", ChangeStateServiceCallback);

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
    else if (AnyServoInAlarmState(servos)) syscon = ALARM_YELLOW;
    
    switch(syscon){

        case COMM_FAILURE:
            ChangeProgramStateTo(EMERGENCY);
            return false;
            break;

        case AVAIL_FAILURE:
            ChangeProgramStateTo(EMERGENCY);
            return false;
            break;

        case ALARM_YELLOW:
            ChangeProgramStateTo(ALARM);
            return false;
            break;
    }

    return true;
} 
