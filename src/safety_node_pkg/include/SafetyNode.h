#pragma once
#include <ros/ros.h>
#include "std_msgs/Int32.h"
#include "custom_msg_pkg/ChangeNodeStateSrv.h"
#include "SafetySysMethods.h"

using namespace std;

static int nodeId;
static int mainNodeId;
static int servoControlNodeId;

static int _programState;
static bool _shutdown;

bool ReadNodesConfig(ros::NodeHandle nh);
bool ValidateChangeStateRequest(int targetState, int callerId);
void ChangeProgramStateTo(int programState);
bool EvaluateSafetySystemCondition(bool shouldBeConnected, bool shouldTransmitSafetyOkSignal);

enum PROGRAM_STATES {
	INITIALIZATION = 0,
    DISARMED = 1,
	ARMED = 2,
    SHUTDOWN = 3,
    BREACH = 4,
    FAILURE = 5
};

enum SAFETYSYS_CONDITION {
	ALL_GOOD = 0,
	SAFETY_BREACH = 1,
	COMM_FAILURE = 2
};