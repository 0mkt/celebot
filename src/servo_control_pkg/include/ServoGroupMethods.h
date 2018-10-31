#pragma once
#include <ros/console.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "Servo.h"

using namespace std;

void ConnectServos(vector<Servo> &servos);
void DisconnectServos(vector<Servo> &servos);
bool AllServosConnected(vector<Servo> &servos);
void EnableServos(vector<Servo> &servos);
void DisableServos(vector<Servo> &servos);
bool AllServosEnabled(vector<Servo> &servos);
void StopServos(vector<Servo> &servos);
bool AllServosStopped(vector<Servo> &servos);
void EmergencyStopServos(vector<Servo> &servos);
void UpdateServosStatuses(vector<Servo> &servos);
bool AnyServoInAlarmState(vector<Servo> &servos);
bool AnyServoInEmergencyState(vector<Servo> &servos);