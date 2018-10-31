#pragma once
#include <ros/ros.h>
#include "std_msgs/Int32.h"
#include "custom_msg_pkg/ChangeNodeStateServiceMsg.h"
#include "ServoGroupMethods.h"

using namespace std;

static vector<Servo> servos = {
	Servo(0, "192.168.0.2"),
};

static int nodeId;
static int mainNodeId;
static int safetyNodeId;
static int safetyNodeArmedState;

static int _programState;
static bool _shutdown;
static bool _motionAllowed;
static int _safetyNodeState;

bool ReadNodesConfig(ros::NodeHandle nh);
bool ValidateChangeStateRequest(int targetState, int callerId);
void ChangeProgramStateTo(int programState);
bool EvaluateMotionSystemCondition(bool shouldBeConnected, bool shouldBeEnabled);
bool IsMotionAllowed(int safetyNodeState);

enum PROGRAM_STATES {
	INITIALIZATION = 0,
	STANDBY = 1,
	MOTION = 2,
	SHUTDOWN = 3,
	ALARM = 4,
	EMERGENCY = 5,
	FAILURE = 6
};

enum MOTIONSYS_CONDITION {
	ALL_GOOD = 0,
	IN_ALARM = 1,
	IN_EMERGENCY = 2,
	AVAIL_FAILURE = 3,
	COMM_FAILURE = 4
};



