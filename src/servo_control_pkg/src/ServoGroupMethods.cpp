#include "ServoGroupMethods.h"

void ConnectServos(vector<Servo> &servos){

    for (int i = 0; i < servos.size(); i++){
        if (!servos[i].status.connected){
            servos[i].Connect();
        }
    }
}

void DisconnectServos(vector<Servo> &servos){

    for (int i = 0; i < servos.size(); i++){
        if (servos[i].status.connected){
            servos[i].Disconnect();
        }
    }
}

bool AllServosConnected(vector<Servo> &servos){

    bool result = true;

    for (int i = 0; i < servos.size(); i++){
        if (!servos[i].status.connected){

            ROS_WARN_STREAM(servos[i].ipAddress << " is not connected!");
            result = false;
        } 
    }
        
    return result;
}

void EnableServos(vector<Servo> &servos){

    for (int i = 0; i < servos.size(); i++){
        if (!servos[i].status.enabled){
            servos[i].Enable();
        }
    }
}

void DisableServos(vector<Servo> &servos){

    for (int i = 0; i < servos.size(); i++){
        if (servos[i].status.enabled){
            servos[i].Disable();
        }
    }
}

bool AllServosEnabled(vector<Servo> &servos){

    bool result = true;

    for (int i = 0; i < servos.size(); i++){
        if (!servos[i].status.enabled){

            ROS_WARN_STREAM(servos[i].ipAddress << " is not enabled!");
            result = false;
        } 
    }
        
    return result;
}

void StopServos(vector<Servo> &servos){

   for (int i = 0; i < servos.size(); i++){
        if (!servos[i].status.stopping && servos[i].status.moving){
            servos[i].Stop();
            servos[i].ResetMotionTarget();
        } 
    }
}

void EmergencyStopServos(vector<Servo> &servos){

    for (int i = 0; i < servos.size(); i++){
        if (!servos[i].status.stopping && servos[i].status.moving){
            servos[i].EmergencyStop();
            servos[i].ResetMotionTarget();
        } 
    }
}

bool AllServosStopped(vector<Servo> &servos){

    bool result = true;

    for (int i = 0; i < servos.size(); i++){
        if (servos[i].status.moving) {

            ROS_WARN_STREAM(servos[i].ipAddress << " is not stopped!");
            result = false;
        }
    }

    return result;
}

void UpdateServosStatuses(vector<Servo> &servos){

    for (int i = 0; i < servos.size(); i++){
        if (servos[i].status.connected) {
            servos[i].ReadDataAndUpdateStatus();
        }
    }
}

bool AnyServoInAlarmState(vector<Servo> &servos){

    bool result = false;

    for (int i = 0; i < servos.size(); i++){
        if (servos[i].status.alarm){

            ROS_WARN_STREAM(servos[i].ipAddress << " is in alarm state!");
            result = true;
        } 
    }
        
    return result;
}
