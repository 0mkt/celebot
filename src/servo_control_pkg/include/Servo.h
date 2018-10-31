#pragma once
#include <ros/console.h>
#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include "PE/RETURNCODES_DEFINE.h"
#include "PE/MOTION_EziSERVO_DEFINE.h"
#include "PE/COMM_DEFINE.h"

#ifdef __cplusplus
extern "C" {
#include "EthernetInterface.h"
}
#endif

#include "MiniPID.h"
#include "Wintypes.h"

class Servo
{
public:
	BYTE iBdID;
	std::string ipAddress;
	
	MiniPID pid = MiniPID(0,0,0);
	struct SettingsPID {
		double p = 10;
		double i = 0.0001;
		double d = 10;
		double limitMin = -100000;
		double limitMax = 100000;
	} settingsPID;
	
	struct Status {
		bool connected = false;
		bool enabled = false;
		bool alarm = false;
		bool emergency = false;
		bool stopping = false;
		bool moving = false;
	} status;
	
	struct Parameters {
	} parameters;
	
	struct ActualMotionState {
		int position = 0;
		int velocity = 0;
		int direction = 0;
		int positionError = 0;
	} actualMotionState;

	struct TargetMotionState {
		int position = 0;
		int velocity = 0;
		int direction = 0;
	} targetMotionState;

	Servo(BYTE iBdID, std::string ipAddress);
	~Servo();

	void InitializePID();
	bool Connect();
	void Disconnect();
	void Enable();
	void Disable();
	void ResetMotionTarget();
	void Stop();
	void EmergencyStop();
	void ReadDataAndUpdateStatus();
	void ControlMotion();
	void ResetAlarm();
	std::ostringstream ConstructMotionDataLog();

private:
	bool EvaluateCommandResult(INT nRtn);
};