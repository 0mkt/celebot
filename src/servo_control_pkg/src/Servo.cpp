#include "Servo.h"

using namespace std;

Servo::Servo(BYTE _iBdID, string _ipAddress) {
	
	// constructor parameters
	iBdID = _iBdID;
	ipAddress = _ipAddress;

	// initialize pid regulator
	InitializePID();
}

Servo::~Servo(){}

void Servo::InitializePID() {
	
	pid.setPID(settingsPID.p, settingsPID.i, settingsPID.d);
	pid.setOutputLimits(settingsPID.limitMin, settingsPID.limitMax);
}

bool Servo::Connect() {
	char lpBuff[256]; int nBuffSize = 256; BYTE nType; bool success; 
	
	ROS_INFO_STREAM(ipAddress << ": Connecting servo...");

	char * ipAddress_arr = new char [ipAddress.length()+1];
	strcpy (ipAddress_arr, ipAddress.c_str());

	success = FAS_Connect(ipAddress_arr, iBdID);
	if (!success) return false;

	success = EvaluateCommandResult(FAS_GetSlaveInfoV6(iBdID, &nType, lpBuff, nBuffSize));
	if (!success) return false;

	status.connected = true;
	ROS_INFO_STREAM(ipAddress << ": Servo connected!");
	ROS_INFO_STREAM(ipAddress << ": Board: " << (unsigned)iBdID);
	ROS_INFO_STREAM(ipAddress << ": Type: " << (unsigned)nType);
	ROS_INFO_STREAM(ipAddress << ": Version: " << lpBuff);

	return true;
};

void Servo::Disconnect() {
	ROS_INFO_STREAM(ipAddress << ": Disconnecting servo...");
	FAS_Close(iBdID);

	status.connected = false;
	ROS_INFO_STREAM(ipAddress << ": Servo disconnected!");
};

void Servo::Enable() {
	ROS_INFO_STREAM(ipAddress << ": Enabling servo...");

	bool success = EvaluateCommandResult(FAS_ServoEnable(iBdID, true));
	if (!success) return;

	ROS_INFO_STREAM(ipAddress << ": Command sent successfuly!");
}

void Servo::Disable() {
	ROS_INFO_STREAM(ipAddress << ": Disabling servo...");

	bool success = EvaluateCommandResult(FAS_ServoEnable(iBdID, false));
	if (!success) return;

	ROS_INFO_STREAM(ipAddress << ": Command sent successfuly!");
}

void Servo::ResetMotionTarget() {
	targetMotionState.position = actualMotionState.position;
	targetMotionState.velocity = 0;
}

void Servo::Stop() {
	ROS_INFO_STREAM(ipAddress << ": Stopping servo...");

	bool success = 	EvaluateCommandResult(FAS_MoveStop(iBdID));
	if (!success) return;

	ROS_INFO_STREAM(ipAddress << ": Command sent successfuly!");
}

void Servo::EmergencyStop() {
	ROS_INFO_STREAM(ipAddress << ": Stopping servo [E-STOP]!..");
	
	bool success = EvaluateCommandResult(FAS_EmergencyStop(iBdID));
	if (!success) return;

	ROS_INFO_STREAM(ipAddress << ": Command sent successfuly!");
}

void Servo::ReadDataAndUpdateStatus() {
	DWORD dwInStatus, dwOutStatus, dwAxisStatus;
	int lCmdPos = 0, lActPos = 0, lPosErr = 0, lActVel = 0;
	WORD wPosItemNo;
	EZISERVO_AXISSTATUS stAxisStatus;

	bool success = EvaluateCommandResult(
		FAS_GetAllStatus(iBdID, &dwInStatus, &dwOutStatus, &dwAxisStatus, &lCmdPos, &lActPos, &lPosErr, &lActVel, &wPosItemNo)
	);
	if (!success) return;

	stAxisStatus.dwValue = dwAxisStatus;
	status.enabled = stAxisStatus.FFLAG_SERVOON;
	status.alarm = stAxisStatus.FFLAG_ERRORALL;
	status.moving = stAxisStatus.FFLAG_MOTIONING;
	status.stopping = stAxisStatus.FFLAG_SLOWSTOP || stAxisStatus.FFLAG_EMGSTOP;

	actualMotionState.position = lActPos;
	actualMotionState.velocity = lActVel;
	actualMotionState.positionError = lPosErr;
	
	if (lActVel < 0) actualMotionState.direction = DIR_DEC;
	else actualMotionState.direction = DIR_INC;
}

void Servo::ControlMotion() {

	int targetVel = pid.getOutput(actualMotionState.position, targetMotionState.position);

	bool stop = false;
	if (actualMotionState.velocity > 0 && targetVel < 0) stop = true;
	if (actualMotionState.velocity < 0 && targetVel > 0) stop = true;
	if (abs(targetVel) < settingsPID.p * 2) stop = true;
	if (stop) targetVel = 0;

	bool outDir;
	if (targetVel >= 0) outDir = DIR_INC;
	if (targetVel < 0) outDir = DIR_DEC;

	int outVel = abs(targetVel);

	if (!status.moving) {

		if (outVel == 0) return;

		int minStartVel = 20000;
		EvaluateCommandResult(FAS_MoveVelocity(iBdID, minStartVel, outDir));
		EvaluateCommandResult(FAS_VelocityOverride(iBdID, outVel));
	}
	else {

		EvaluateCommandResult(FAS_VelocityOverride(iBdID, outVel));
	}
}

ostringstream Servo::ConstructMotionDataLog() {

	ostringstream log;

	log << ipAddress << ": \n"
		<< "actual position: " << actualMotionState.position << " \n"
		<< "target position: " << targetMotionState.position << " \n"
		<< "position error: " << actualMotionState.positionError << " \n"
		<< "actual velocity: " << actualMotionState.velocity << " \n"
		<< "target velocity: " << targetMotionState.velocity << " \n";

	return log;
}

bool Servo::EvaluateCommandResult(INT nRtn) {

	if (nRtn == FMC_TIMEOUT_ERROR || nRtn == FMC_DISCONNECTED) {
		ROS_ERROR_STREAM(ipAddress << ": No communication with servo!");

		FAS_Close(iBdID);
		status.connected = false;

		return false;
	}

	if (nRtn == FMP_RUNFAIL) {
		ROS_WARN_STREAM(ipAddress << ": Servo is busy!");
		return false;
	}

	if (nRtn != FMM_OK) {
		ROS_ERROR_STREAM(ipAddress << ": Unknown error!");
		return false;
	}

	return true;
}

