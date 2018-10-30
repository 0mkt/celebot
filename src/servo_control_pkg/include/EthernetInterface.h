#pragma once

#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/param.h>
#include "Ethernet.h"
#include "PE/PROTOCOL_FRAME_DEFINE.h"
#include "PE/INTERNAL_MOTION_DEFINE.h"
#include "Wintypes.h"

//------------------------------------------------------------------------------
//				  Connect/Close Socket Functions
//------------------------------------------------------------------------------
bool FAS_Connect(char * ipAddress, BYTE iBdID);
void FAS_Close(BYTE iBdID);

//------------------------------------------------------------------------------
//					No-Motion Command Functions
//------------------------------------------------------------------------------
int FAS_GetSlaveInfoV6(int nBdID, unsigned char* pType, char* lpBuff, int nBuffSize);
int FAS_GetSlaveInfoV8(int nBdID, DRIVE_INFO* lpDriveInfo);
int FAS_GetSlaveInfoEx(int nBdID, DRIVE_INFO* lpDriveInfo);
int FAS_GetMotorInfo(int nBdID, unsigned char* pType, char* lpBuff, int nBuffSize);

//------------------------------------------------------------------------------
//					Parameter Functions
//------------------------------------------------------------------------------
int FAS_SaveAllParam(int nBdID);
int FAS_SetParameter(int nBdID, unsigned char iParaNo, int lParaValue);
int FAS_GetParameter(int nBdID, unsigned char iParaNo, int* lParamValue);
int FAS_GetROMParam(int nBdID, unsigned char iParaNo, int* lROMParam);

//------------------------------------------------------------------------------
//					IO Functions
//------------------------------------------------------------------------------
int FAS_SetIOInput(int nBdID, unsigned int dwIOSETMask, unsigned int dwIOCLRMask);
int FAS_GetIOInput(int nBdID, unsigned int* dwIOInput);

int FAS_SetIOOutput(int nBdID, unsigned int dwIOSETMask, unsigned int dwIOCLRMask);
int FAS_GetIOOutput(int nBdID, unsigned int* dwIOOutput);

int FAS_GetIOAssignMap(int nBdID, unsigned char iIOPinNo, unsigned int* dwIOLogicMask, unsigned char* bLevel);
int FAS_SetIOAssignMap(int nBdID, unsigned char iIOPinNo, unsigned int dwIOLogicMask, unsigned char bLevel);

int FAS_IOAssignMapReadROM(int nBdID);

//------------------------------------------------------------------------------
//					Servo Driver Control Functions
//------------------------------------------------------------------------------
int FAS_ServoEnable(int nBdID, int bOnOff);
int FAS_ServoAlarmReset(int nBdID);
int FAS_StepAlarmReset(int nBdID, int bReset);

//------------------------------------------------------------------------------
//					Read Status and Position
//------------------------------------------------------------------------------
int FAS_GetAxisStatus(int nBdID, unsigned int* dwAxisStatus);
int FAS_GetIOAxisStatus(int nBdID, unsigned int* dwInStatus, unsigned int* dwOutStatus, unsigned int* dwAxisStatus);
int FAS_GetMotionStatus(int nBdID, int* lCmdPos, int* lActPos, int* lPosErr, int* lActVel, unsigned short* wPosItemNo);
int FAS_GetAllStatus(int nBdID, unsigned int* dwInStatus, unsigned int* dwOutStatus, unsigned int* dwAxisStatus, int* lCmdPos, int* lActPos, int* lPosErr, int* lActVel, unsigned short* wPosItemNo);
int FAS_GetAllStatusEx(int nBdID, unsigned char* pTypes, int* pDatas);

int FAS_SetCommandPos(int nBdID, int lCmdPos);
int FAS_SetActualPos(int nBdID, int lActPos);
int FAS_ClearPosition(int nBdID);
int FAS_GetCommandPos(int nBdID, int* lCmdPos);
int FAS_GetActualPos(int nBdID, int* lActPos);
int FAS_GetPosError(int nBdID, int* lPosErr);
int FAS_GetActualVel(int nBdID, int* lActVel);

int FAS_GetAlarmType(int nBdID, unsigned char* nAlarmType);

int FAS_GetAllTorqueStatus(int nBdID, unsigned int* dwInStatus, unsigned int* dwOutStatus, unsigned int* dwAxisStatus, int* lCmdPos, int* lActPos, int* lPosErr, int* lActVel, unsigned short* wPosItemNo, unsigned short* wTorqueValue);
int FAS_GetTorqueStatus(int nBdID, unsigned short* wTorqueValue);

//------------------------------------------------------------------
//					Motion Functions.
//------------------------------------------------------------------
int FAS_MoveStop(int nBdID);
int FAS_EmergencyStop(int nBdID);

int FAS_MovePause(int nBdID, int bPause);

int FAS_MoveOriginSingleAxis(int nBdID);
int FAS_MoveSingleAxisAbsPos(int nBdID, int lAbsPos, unsigned int lVelocity);
int FAS_MoveSingleAxisIncPos(int nBdID, int lIncPos, unsigned int lVelocity);
int FAS_MoveToLimit(int nBdID, unsigned int lVelocity, int iLimitDir);
int FAS_MoveVelocity(int nBdID, unsigned int lVelocity, int iVelDir);

int FAS_PositionAbsOverride(int nBdID, int lOverridePos);
int FAS_PositionIncOverride(int nBdID, int lOverridePos);
int FAS_VelocityOverride(int nBdID, unsigned int lVelocity);

int FAS_TriggerPulseOutput(int nBdID, int bStartTrigger, int lStartPos, unsigned int dwPeriod, unsigned int dwPulseTime, unsigned char nOutputPin, unsigned int dwReserved);
int FAS_TriggerPulseStatus(int nBdID, unsigned char* bTriggerStatus);

int FAS_SetTriggerOutputEx(int nBdID, unsigned char nOutputNo, unsigned char bRun, unsigned short wOnTime, unsigned char nTriggerCount, int* arrTriggerPosition);
int FAS_GetTriggerOutputEx(int nBdID, unsigned char nOutputNo, unsigned char* bRun, unsigned short* wOnTime, unsigned char* nTriggerCount, int* arrTriggerPosition);

int FAS_MovePush(int nBdID, unsigned int dwStartSpd, unsigned int dwMoveSpd, int lPosition, unsigned short wAccel, unsigned short wDecel, unsigned short wPushRate, unsigned int dwPushSpd, int lEndPosition, unsigned short wPushMode);
int FAS_GetPushStatus(int nBdID, unsigned char* nPushStatus);

//------------------------------------------------------------------
//					Ex-Motion Functions.
//------------------------------------------------------------------
int FAS_MoveSingleAxisAbsPosEx(int nBdID, int lAbsPos, unsigned int lVelocity, MOTION_OPTION_EX* lpExOption);
int FAS_MoveSingleAxisIncPosEx(int nBdID, int lIncPos, unsigned int lVelocity, MOTION_OPTION_EX* lpExOption);
int FAS_MoveVelocityEx(int nBdID, unsigned int lVelocity, int iVelDir, VELOCITY_OPTION_EX* lpExOption);

//------------------------------------------------------------------
//					Position Table Functions.
//------------------------------------------------------------------
int FAS_PosTableReadItem(int nBdID, unsigned short wItemNo, LPITEM_NODE lpItem);
int FAS_PosTableWriteItem(int nBdID, unsigned short wItemNo, LPITEM_NODE lpItem);
int FAS_PosTableWriteROM(int nBdID);
int FAS_PosTableReadROM(int nBdID);
int FAS_PosTableRunItem(int nBdID, unsigned short wItemNo);
int FAS_PosTableIsData(int nBdID, LPPOSTABLE_DATAFLAG pBitFlag);
int FAS_PosTableIsDataEx(int nBdID, unsigned int dwSectionNo, LPPOSTABLE_DATAFLAG_EX pBitFlag);

int FAS_PosTableRunOneItem(int nBdID, int bNextMove, unsigned short wItemNo);
int FAS_PosTableCheckStopMode(int nBdID, unsigned char* pStopMode);

int FAS_PosTableReadOneItem(int nBdID, unsigned short wItemNo, unsigned short wOffset, int* lPosItemVal);
int FAS_PosTableWriteOneItem(int nBdID, unsigned short wItemNo, unsigned short wOffset, int lPosItemVal);

//------------------------------------------------------------------
//					Gap Control Functions.
//------------------------------------------------------------------
int FAS_GapControlEnable(int nBdID, unsigned short wItemNo, int lGapCompSpeed, int lGapAccTime, int lGapDecTime, int lGapStartSpeed);
int FAS_GapControlDisable(int nBdID);
int FAS_IsGapControlEnable(int nBdID, int* bIsEnable, unsigned short* wCurrentItemNo);

int FAS_GapControlGetADCValue(int nBdID, int* lADCValue);
int FAS_GapOneResultMonitor(int nBdID, unsigned char* bUpdated, int* iIndex, int* lGapValue, int* lCmdPos, int* lActPos, int* lCompValue, int* lReserved);

//------------------------------------------------------------------
//					Alarm Type History Functions.
//------------------------------------------------------------------
int FAS_GetAlarmLogs(int nBdID, ALARM_LOG* pAlarmLog);
int FAS_ResetAlarmLogs(int nBdID);

//------------------------------------------------------------------
//					I/O Module Functions.
//------------------------------------------------------------------
int FAS_GetInput(int nBdID, unsigned int* uInput, unsigned int* uLatch);

int FAS_ClearLatch(int nBdID, unsigned int uLatchMask);
int FAS_GetLatchCount(int nBdID, unsigned char iInputNo, unsigned int* uCount);
int FAS_GetLatchCountAll(int nBdID, unsigned int** ppuAllCount);
int FAS_ClearLatchCount(int nBdID, unsigned int uInputMask);

int FAS_GetOutput(int nBdID, unsigned int* uOutput, unsigned int* uStatus);
int FAS_SetOutput(int nBdID, unsigned int uSetMask, unsigned int uClearMask);

int FAS_SetTrigger(int nBdID, unsigned char uOutputNo, TRIGGER_INFO* pTrigger);
int FAS_SetRunStop(int nBdID, unsigned int uRunMask, unsigned int uStopMask);
int FAS_GetTriggerCount(int nBdID, unsigned char uOutputNo, unsigned int* uCount);

int FAS_GetIOLevel(int nBdID, unsigned int* uIOLevel);
int FAS_SetIOLevel(int nBdID, unsigned int uIOLevel);
int FAS_LoadIOLevel(int nBdID);
int FAS_SaveIOLevel(int nBdID);

int FAS_GetInputFilter(int nBdID, unsigned short* filter);
int FAS_SetInputFilter(int nBdID, unsigned short filter);

//------------------------------------------------------------------
//					Ez-IO Plus-AD Functions
//------------------------------------------------------------------
int FAS_GetAllADResult(int nBdID, AD_RESULT* result);
int FAS_GetADResult(int nBdID, unsigned char channel, float* adresult);
int FAS_SetADRange(int nBdID, unsigned char channel, int range);
