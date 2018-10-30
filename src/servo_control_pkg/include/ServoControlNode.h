#pragma once
#include <ros/ros.h>
#include "std_msgs/Int32.h"
#include "custom_msg_pkg/SCNChangeStateServiceMsg.h"
#include "ServoGroupMethods.h"

using namespace std;

static vector<Servo> servos = {
	Servo(0, "192.168.0.2"),
};

static int nodeId;
static int mainNodeId;
static int safetyNodeId;

static int _programState;
static bool _shutdown;

bool ReadNodesConfig(ros::NodeHandle nh);
bool ValidateChangeStateRequest(int targetState, int callerId);
void ChangeProgramStateTo(int programState);
bool EvaluateMotionSystemCondition(bool shouldBeConnected, bool shouldBeEnabled);

enum PROGRAM_STATES {
	INITIALIZATION = 0,
	STANDBY = 1,
	MOTION = 2,
	SHUTDOWN = 3,
	ALARM = 4,
	EMERGENCY = 5
};

enum MOTIONSYS_CONDITION {
	ALL_GOOD = 0,
	ALARM_YELLOW = 1,
	ALARM_RED = 2,
	AVAIL_FAILURE = 3,
	COMM_FAILURE = 4
};



