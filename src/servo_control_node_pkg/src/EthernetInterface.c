#include "EthernetInterface.h"
#include <sys/time.h>

#ifndef NULL
#define NULL	0
#endif // NULL

//------------------------------------------------------------------------------
//				  Connect/Close Socket Functions
//------------------------------------------------------------------------------
bool FAS_Connect(char * ipAddress, BYTE iBdID)
{
	// prepare socket struct
	struct sockaddr_in sockaddr_in_ = { };
	sockaddr_in_.sin_family = AF_INET;
	sockaddr_in_.sin_port = htons( UDP_PORT_NO1 );

	// translate ipAddress to PC language
	if (inet_pton( sockaddr_in_.sin_family, ipAddress, & sockaddr_in_.sin_addr ) <= 0)
	{
		perror( "inet_pton() ERROR" );
        return false;
	}

	// create socket
 	const int socket_ = socket( AF_INET, SOCK_DGRAM, 0 );
    if( socket_ < 0 )
    {
        perror( "socket() ERROR" );
        return false;
    } 

	// set socket timeout
	struct timeval tv;
	tv.tv_sec = 0;
	tv.tv_usec = 10000;
	if (setsockopt(socket_, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv) < 0)
	{
		perror( "setsockopt() ERROR" );
        return false;
	}

	_socket[iBdID] = socket_;
	_server[iBdID] = sockaddr_in_;

	return true;	
}

void FAS_Close(BYTE iBdID)
{
	if (_socket[iBdID] == 0) return;

	close_socket(iBdID);

	struct sockaddr_in sockaddr_in_ = { };
	_server[iBdID] = sockaddr_in_;
	_socket[iBdID] = 0;
}

//------------------------------------------------------------------------------
//					No-Motion Command Functions
//------------------------------------------------------------------------------
int FAS_GetSlaveInfoV6(int nBdID, unsigned char* pType, char* lpBuff, int nBuffSize)
{
	char chBuff[MAX_BUFFER_SIZE] = "";
	int nRtn;

	memset(lpBuff, 0x00, nBuffSize);

	int desc = _socket[nBdID];
	struct sockaddr_in add = _server[nBdID];

	nRtn = DoSendCommand(nBdID, FRAME_GETSLAVEINFO, NULL, 0, (unsigned char*)chBuff, MAX_BUFFER_SIZE, SOCKET_WAITTIME);
	if (nRtn == FMM_OK)
	{
		if (pType != NULL)
			*pType = chBuff[0];

		if (lpBuff != NULL)
			memcpy(lpBuff, &(chBuff[1]), MIN(nBuffSize, MAX_SWINFO_LENGTH));
	}

	return nRtn;
}

int FAS_GetSlaveInfoV8(int nBdID, DRIVE_INFO* lpDriveInfo)
{
	DRIVE_INFO driveinfo = {0};
	int nBuffSize = sizeof(DRIVE_INFO);
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_GETSLAVEINFO, NULL, 0, (unsigned char*)&driveinfo, nBuffSize, SOCKET_WAITTIME);
	if (nRtn == FMM_OK)
	{
		if (lpDriveInfo != NULL)
			memcpy(lpDriveInfo, &driveinfo, nBuffSize);
	}

	return nRtn;
}

int FAS_GetSlaveInfoEx(int nBdID, DRIVE_INFO* lpDriveInfo)
{
	DRIVE_INFO driveinfo = {0};
	int nBuffSize = sizeof(DRIVE_INFO);
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_GETSLAVEINFO_EX, NULL, 0, (unsigned char*)&driveinfo, nBuffSize, SOCKET_WAITTIME);
	if (nRtn == FMM_OK)
	{
		if (lpDriveInfo != NULL)
			memcpy(lpDriveInfo, &driveinfo, nBuffSize);
	}

	return nRtn;
}

int FAS_GetMotorInfo(int nBdID, unsigned char* pType, char* lpBuff, int nBuffSize)
{
	char chBuff[MAX_BUFFER_SIZE] = "";
	int nRtn;

	memset(lpBuff, 0x00, nBuffSize);

	nRtn = DoSendCommand(nBdID, FRAME_GETMOTORINFO, NULL, 0, (unsigned char*)chBuff, MAX_BUFFER_SIZE, SOCKET_WAITTIME);
	if (nRtn == FMM_OK)
	{
		*pType = chBuff[0];
		memcpy(lpBuff, &(chBuff[1]), MIN(nBuffSize, MAX_SWINFO_LENGTH));
	}

	return nRtn;
}

//------------------------------------------------------------------------------
//             Parameter Functions
//------------------------------------------------------------------------------
int FAS_SaveAllParam(int nBdID)
{
	return DoSendCommand(nBdID, FRAME_FAS_SAVEALLPARAM, NULL, 0, NULL, 0, SOCKET_WAITTIME * 50);
}

int FAS_SetParameter(int nBdID, unsigned char iParaNo, int lParaValue)
{
	unsigned char byValue[5];
	UNION_4DATA data;

	byValue[0] = iParaNo;
	data.lValue = lParaValue;
	byValue[1] = data.byValue[0];
	byValue[2] = data.byValue[1];
	byValue[3] = data.byValue[2];
	byValue[4] = data.byValue[3];

	return DoSendCommand(nBdID, FRAME_FAS_SETPARAMETER, byValue, 5, NULL, 0, SOCKET_WAITTIME);
}

int FAS_GetParameter(int nBdID, unsigned char iParaNo, int* lParamValue)
{
	int lValue = 0;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GETPARAMETER, &iParaNo, 1, (unsigned char*)&lValue, sizeof(int), SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
		*lParamValue = lValue;

	return nRtn;
}

int FAS_GetROMParam(int nBdID, unsigned char iParaNo, int* lROMParam)
{
	int lValue = 0;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GETROMPARAM, &iParaNo, 1, (unsigned char*)&lValue, sizeof(int), SOCKET_WAITTIME * 5);

	if (nRtn == FMM_OK)
		*lROMParam = lValue;

	return nRtn;
}

//------------------------------------------------------------------------------
//            IO Functions
//------------------------------------------------------------------------------
int FAS_SetIOInput(int nBdID, unsigned int dwIOSETMask, unsigned int dwIOCLRMask)
{
	unsigned char byValue[8];
	UNION_4DATA data;

	data.dwValue = dwIOSETMask;
	byValue[0] = data.byValue[0];
	byValue[1] = data.byValue[1];
	byValue[2] = data.byValue[2];
	byValue[3] = data.byValue[3];

	data.dwValue = dwIOCLRMask;
	byValue[4] = data.byValue[0];
	byValue[5] = data.byValue[1];
	byValue[6] = data.byValue[2];
	byValue[7] = data.byValue[3];

	return DoSendCommand(nBdID, FRAME_FAS_SETIO_INPUT, byValue, 8, NULL, 0, SOCKET_WAITTIME);
}

int FAS_GetIOInput(int nBdID, unsigned int* dwIOInput)
{
	unsigned int dwValue;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GETIO_INPUT, NULL, 0,  (unsigned char*)&dwValue, 4, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
		*dwIOInput = dwValue;

	return nRtn;
}

int FAS_SetIOOutput(int nBdID, unsigned int dwIOSETMask, unsigned int dwIOCLRMask)
{
	unsigned char byValue[8];
	UNION_4DATA data;

	data.dwValue = dwIOSETMask;
	byValue[0] = data.byValue[0];
	byValue[1] = data.byValue[1];
	byValue[2] = data.byValue[2];
	byValue[3] = data.byValue[3];

	data.dwValue = dwIOCLRMask;
	byValue[4] = data.byValue[0];
	byValue[5] = data.byValue[1];
	byValue[6] = data.byValue[2];
	byValue[7] = data.byValue[3];

	return DoSendCommand(nBdID, FRAME_FAS_SETIO_OUTPUT, byValue, 8, NULL, 0, SOCKET_WAITTIME);
}

int FAS_GetIOOutput(int nBdID, unsigned int* dwIOOutput)
{
	unsigned int dwValue;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GETIO_OUTPUT, NULL, 0, (unsigned char*)&dwValue, 4, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
		*dwIOOutput = dwValue;

	return nRtn;
}

int FAS_GetIOAssignMap(int nBdID, unsigned char iIOPinNo, unsigned int* dwIOLogicMask, unsigned char* bLevel)
{
	unsigned char byValue[5];
	UNION_4DATA data;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GET_IO_ASSGN_MAP, &iIOPinNo, 1, byValue, 5, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		data.byValue[0] = byValue[0];
		data.byValue[1] = byValue[1];
		data.byValue[2] = byValue[2];
		data.byValue[3] = byValue[3];
		*dwIOLogicMask = data.dwValue;

		*bLevel = (byValue[4]) ? 0x01 : 0x00;
	}

	return nRtn;
}

int FAS_SetIOAssignMap(int nBdID, unsigned char iIOPinNo, unsigned int dwIOLogicMask, unsigned char bLevel)
{
	unsigned char byValue[6];
	UNION_4DATA data;

	byValue[0] = iIOPinNo;

	data.dwValue = dwIOLogicMask;
	byValue[1] = data.byValue[0];
	byValue[2] = data.byValue[1];
	byValue[3] = data.byValue[2];
	byValue[4] = data.byValue[3];
	byValue[5] = (bLevel) ? 0x01 : 0x00;

	return DoSendCommand(nBdID, FRAME_FAS_SET_IO_ASSGN_MAP, byValue, 6, NULL, 0, SOCKET_WAITTIME);
}

int FAS_IOAssignMapReadROM(int nBdID)
{
	unsigned char nRtnCode;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_IO_ASSGN_MAP_READROM, NULL, 0, &nRtnCode, 1, SOCKET_WAITTIME * 5);

	if (nRtnCode != 0)
	{
	}

	return nRtn;
}

//------------------------------------------------------------------------------
//             Servo Driver Control Functions
//------------------------------------------------------------------------------
int FAS_ServoEnable(int nBdID, int bOnOff)
{
	unsigned char byValue = (unsigned char)(bOnOff) ? 0x01 : 0x00;

	return DoSendCommand(nBdID, FRAME_FAS_SERVOENABLE, &byValue, 1, NULL, 0, SOCKET_WAITTIME * 5);
}

int FAS_ServoAlarmReset(int nBdID)
{
	return DoSendCommand(nBdID, FRAME_FAS_ALARMRESET, NULL, 0, NULL, 0, SOCKET_WAITTIME);
}

int FAS_StepAlarmReset(int nBdID, int bReset)
{
	unsigned char byValue = (unsigned char)(bReset) ? 0x01 : 0x00;

	return DoSendCommand(nBdID, FRAME_FAS_STEPALARMRESET, &byValue, 1, NULL, 0, SOCKET_WAITTIME);
}


//------------------------------------------------------------------------------
//            Read Status and Position
//------------------------------------------------------------------------------
int FAS_GetAxisStatus(int nBdID, unsigned int* dwAxisStatus)
{
	unsigned int dwValue;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GETAXISSTATUS, NULL, 0, (unsigned char*)&dwValue, 4, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
		*dwAxisStatus = dwValue;

	return nRtn;
}

int FAS_GetIOAxisStatus(int nBdID, unsigned int* dwInStatus, unsigned int* dwOutStatus, unsigned int* dwAxisStatus)
{
	int nRtn;
	unsigned int Data[3];

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GETIOAXISSTATUS, NULL, 0, (unsigned char*)Data, 12, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		*dwInStatus= Data[0];
		*dwOutStatus= Data[1];
		*dwAxisStatus= Data[2];
	}

	return nRtn;
}

int FAS_GetMotionStatus(int nBdID, int* lCmdPos, int* lActPos, int* lPosErr, int* lActVel, unsigned short* wPosItemNo)
{
	unsigned int Data[5];
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GETMOTIONSTATUS, NULL, 0, (unsigned char*)Data, 20, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		*lCmdPos= Data[0];
		*lActPos= Data[1];
		*lPosErr= Data[2];
		*lActVel= Data[3];
		*wPosItemNo= (unsigned short)Data[4];
	}

	return nRtn;
}

int FAS_GetAllStatus(int nBdID, unsigned int* dwInStatus, unsigned int* dwOutStatus, unsigned int* dwAxisStatus, int* lCmdPos, int* lActPos, int* lPosErr, int* lActVel, unsigned short* wPosItemNo)
{
	unsigned int Data[8];
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GETALLSTATUS, NULL, 0, (unsigned char*)Data, 32, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		*dwInStatus= Data[0];
		*dwOutStatus= Data[1];
		*dwAxisStatus= Data[2];
		*lCmdPos= Data[3];
		*lActPos= Data[4];
		*lPosErr= Data[5];
		*lActVel= Data[6];
		*wPosItemNo= (unsigned short)Data[7];
	}

	return nRtn;
}

int FAS_GetAllStatusEx(int nBdID, unsigned char* pTypes, int* pDatas)
{
	if (pTypes == NULL)
		return FMP_RUNFAIL;

	return DoSendCommand(nBdID, FRAME_FAS_GETALLSTATUSEX, pTypes, ALLSTATUSEX_ITEM_COUNT, (unsigned char*)pDatas, ALLSTATUSEX_ITEM_COUNT * 4, SOCKET_WAITTIME);
}

int FAS_SetCommandPos(int nBdID, int lCmdPos)
{
	UNION_4DATA data;

	data.lValue = lCmdPos;

	return DoSendCommand(nBdID, FRAME_FAS_SETCMDPOS, data.byValue, 4, NULL, 0, SOCKET_WAITTIME);
}

int FAS_SetActualPos(int nBdID, int lActPos)
{
	UNION_4DATA data;

	data.lValue = lActPos;

	return DoSendCommand(nBdID, FRAME_FAS_SETACTPOS, data.byValue, 4, NULL, 0, SOCKET_WAITTIME);
}

int FAS_ClearPosition(int nBdID)
{
	return DoSendCommand(nBdID, FRAME_FAS_CLEARPOS, NULL, 0, NULL, 0, SOCKET_WAITTIME * 15);
}

int FAS_GetCommandPos(int nBdID, int* lCmdPos)
{
	int lValue = 0;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GETCMDPOS, NULL, 0, (unsigned char*)&lValue, sizeof(int), SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
		*lCmdPos = lValue;

	return nRtn;
}

int FAS_GetActualPos(int nBdID, int* lActPos)
{
	int lValue = 0;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GETACTPOS, NULL, 0, (unsigned char*)&lValue, sizeof(int), SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
		*lActPos = lValue;

	return nRtn;
}

int FAS_GetPosError(int nBdID, int* lPosErr)
{
	int lValue = 0;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GETPOSERR, NULL, 0, (unsigned char*)&lValue, sizeof(int), SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
		*lPosErr = lValue;

	return nRtn;
}

int FAS_GetActualVel(int nBdID, int* lActVel)
{
	int lValue = 0;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GETACTVEL, NULL, 0, (unsigned char*)&lValue, sizeof(int), SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
		*lActVel = lValue;

	return nRtn;
}

int FAS_GetAlarmType(int nBdID, unsigned char* nAlarmType)
{
	unsigned char byValue;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GETALARMTYPE, NULL, 0, &byValue, 1, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		if (nAlarmType != NULL)
			*nAlarmType = byValue;
	}

	return nRtn;
}

int FAS_GetAllTorqueStatus(int nBdID, unsigned int* dwInStatus, unsigned int* dwOutStatus, unsigned int* dwAxisStatus, int* lCmdPos, int* lActPos, int* lPosErr, int* lActVel, unsigned short* wPosItemNo, unsigned short* wTorqueValue)
{
	unsigned int Data[9] = {0};
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GETALLTORQUESTATUS, NULL, 0, (unsigned char*)Data, 34, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		*dwInStatus= Data[0];
		*dwOutStatus= Data[1];
		*dwAxisStatus= Data[2];
		*lCmdPos= Data[3];
		*lActPos= Data[4];
		*lPosErr= Data[5];
		*lActVel= Data[6];
		*wPosItemNo= (unsigned short)Data[7];
		*wTorqueValue= (unsigned short)Data[8];
	}

	return nRtn;
}

int FAS_GetTorqueStatus(int nBdID, unsigned short* wTorqueValue)
{
	unsigned short wValue = 0;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GETTORQUESTATUS, NULL, 0, (unsigned char*)&wValue, sizeof(unsigned short), SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
		*wTorqueValue = wValue;

	return nRtn;
}

//------------------------------------------------------------------
//                Motion Functions.
//------------------------------------------------------------------
int FAS_MoveStop(int nBdID)
{
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_MOVESTOP, NULL, 0, NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_EmergencyStop(int nBdID)
{
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_EMERGENCYSTOP, NULL, 0, NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_MovePause(int nBdID, int bPause)
{
	unsigned char byValue;
	int nRtn;

	byValue = bPause;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_MOVEPAUSE, &byValue, 1, NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_MoveOriginSingleAxis(int nBdID)
{
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_MOVEORIGIN, NULL, 0, NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_MoveSingleAxisAbsPos(int nBdID, int lAbsPos, unsigned int lVelocity)
{
	unsigned char byValue[8];
	UNION_4DATA data;
	int nRtn;

	data.lValue = lAbsPos;
	byValue[0] = data.byValue[0];
	byValue[1] = data.byValue[1];
	byValue[2] = data.byValue[2];
	byValue[3] = data.byValue[3];

	data.lValue = lVelocity;
	byValue[4] = data.byValue[0];
	byValue[5] = data.byValue[1];
	byValue[6] = data.byValue[2];
	byValue[7] = data.byValue[3];

	nRtn = DoSendCommand(nBdID, FRAME_FAS_MOVESINGLEABS, byValue, 8, NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_MoveSingleAxisIncPos(int nBdID, int lIncPos, unsigned int lVelocity)
{
	unsigned char byValue[8];
	UNION_4DATA data;
	int nRtn;

	data.lValue = lIncPos;
	byValue[0] = data.byValue[0];
	byValue[1] = data.byValue[1];
	byValue[2] = data.byValue[2];
	byValue[3] = data.byValue[3];

	data.lValue = lVelocity;
	byValue[4] = data.byValue[0];
	byValue[5] = data.byValue[1];
	byValue[6] = data.byValue[2];
	byValue[7] = data.byValue[3];

	nRtn = DoSendCommand(nBdID, FRAME_FAS_MOVESINGLEINC, byValue, 8, NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_MoveToLimit(int nBdID, unsigned int lVelocity, int iLimitDir)
{
	unsigned char byValue[5];
	UNION_4DATA data;
	int nRtn;

	data.lValue = lVelocity;
	byValue[0] = data.byValue[0];
	byValue[1] = data.byValue[1];
	byValue[2] = data.byValue[2];
	byValue[3] = data.byValue[3];

	byValue[4] = (unsigned char)iLimitDir;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_MOVETOLIMIT, byValue, 5, NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_MoveVelocity(int nBdID, unsigned int lVelocity, int iVelDir)
{
	unsigned char byValue[5];
	UNION_4DATA data;

	data.lValue = lVelocity;
	byValue[0] = data.byValue[0];
	byValue[1] = data.byValue[1];
	byValue[2] = data.byValue[2];
	byValue[3] = data.byValue[3];
	byValue[4] = (unsigned char)iVelDir;

	return DoSendCommand(nBdID, FRAME_FAS_MOVEVELOCITY, byValue, 5, NULL, 0, SOCKET_WAITTIME);
}

int FAS_PositionAbsOverride(int nBdID, int lOverridePos)
{
	UNION_4DATA data;

	data.lValue = lOverridePos;

	return DoSendCommand(nBdID, FRAME_FAS_POSABSOVERRIDE, data.byValue, 4, NULL, 0, SOCKET_WAITTIME);
}

int FAS_PositionIncOverride(int nBdID, int lOverridePos)
{
	UNION_4DATA data;

	data.lValue = lOverridePos;

	return DoSendCommand(nBdID, FRAME_FAS_POSINCOVERRIDE, data.byValue, 4, NULL, 0, SOCKET_WAITTIME);
}

int FAS_VelocityOverride(int nBdID, unsigned int lVelocity)
{
	UNION_4DATA data;

	data.dwValue = lVelocity;

	return DoSendCommand(nBdID, FRAME_FAS_VELOVERRIDE, data.byValue, 4, NULL, 0, SOCKET_WAITTIME);
}

int FAS_TriggerPulseOutput(int nBdID, int bStartTrigger, int lStartPos, unsigned int dwPeriod, unsigned int dwPulseTime, unsigned char nOutputPin, unsigned int dwReserved)
{
	unsigned char byValue[18] = {0};
	UNION_4DATA data;
	int nRtn;

	byValue[0] = (bStartTrigger) ? 1 : 0;

	data.lValue = lStartPos;
	byValue[1] = data.byValue[0];
	byValue[2] = data.byValue[1];
	byValue[3] = data.byValue[2];
	byValue[4] = data.byValue[3];

	data.dwValue = dwPeriod;
	byValue[5] = data.byValue[0];
	byValue[6] = data.byValue[1];
	byValue[7] = data.byValue[2];
	byValue[8] = data.byValue[3];

	data.dwValue = dwPulseTime;
	byValue[9] = data.byValue[0];
	byValue[10] = data.byValue[1];
	byValue[11] = data.byValue[2];
	byValue[12] = data.byValue[3];

	byValue[13] = nOutputPin;

	data.dwValue = dwReserved;
	byValue[14] = data.byValue[0];
	byValue[15] = data.byValue[1];
	byValue[16] = data.byValue[2];
	byValue[17] = data.byValue[3];

	nRtn = DoSendCommand(nBdID, FRAME_FAS_TRIGGER_OUTPUT, byValue, sizeof(byValue), NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_TriggerPulseStatus(int nBdID, unsigned char* bTriggerStatus)
{
	unsigned char byValue;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_TRIGGER_STATUS, NULL, 0, &byValue, 1, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		if (bTriggerStatus != NULL)
			*bTriggerStatus = byValue;
	}

	return nRtn;
}

int FAS_SetTriggerOutputEx(int nBdID, unsigned char nOutputNo, unsigned char bRun, unsigned short wOnTime, unsigned char nTriggerCount, int* arrTriggerPosition)
{
	unsigned char byValue[245] = {0};
	UNION_4DATA data4;
	UNION_2DATA data2;
	int nRtn;
	int i;

	byValue[0] = nOutputNo;
	byValue[1] = bRun;

	data2.wValue = wOnTime;
	byValue[2] = data2.byValue[0];
	byValue[3] = data2.byValue[1];

	byValue[4] = nTriggerCount;

	for (i=0; i<MIN(nTriggerCount, 60); i++)
	{
		data4.lValue = *(arrTriggerPosition + i);

		byValue[5 + i * 4] = data4.byValue[0];
		byValue[6 + i * 4] = data4.byValue[1];
		byValue[7 + i * 4] = data4.byValue[2];
		byValue[8 + i * 4] = data4.byValue[3];
	}

	nRtn = DoSendCommand(nBdID, FRAME_SET_TRIGGEROUTPUT_EX, byValue, 245, NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_GetTriggerOutputEx(int nBdID, unsigned char nOutputNo, unsigned char* bRun, unsigned short* wOnTime, unsigned char* nTriggerCount, int* arrTriggerPosition)
{
	unsigned char byValue[244] = {0};
	UNION_4DATA data4;
	UNION_2DATA data2;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_GET_TRIGGEROUTPUT_EX, &nOutputNo, 1, byValue, 244, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		if (bRun != NULL)
			*bRun = byValue[0];

		if (wOnTime != NULL)
		{
			data2.byValue[0] = byValue[1];
			data2.byValue[1] = byValue[2];
			*wOnTime = data2.wValue;
		}

		if (nTriggerCount != NULL)
			*nTriggerCount = byValue[3];

		if (arrTriggerPosition != NULL)
		{
			int i;
			for (i=0; i<MIN(byValue[3], 60); i++)
			{
				data4.byValue[0] = byValue[4 + i * 4];
				data4.byValue[1] = byValue[5 + i * 4];
				data4.byValue[2] = byValue[6 + i * 4];
				data4.byValue[3] = byValue[7 + i * 4];

				*(arrTriggerPosition + i) = data4.lValue;
			}
		}
	}

	return nRtn;
}

int FAS_MovePush(int nBdID, unsigned int dwStartSpd, unsigned int dwMoveSpd, int lPosition, unsigned short wAccel, unsigned short wDecel, unsigned short wPushRate, unsigned int dwPushSpd, int lEndPosition, unsigned short wPushMode)
{
	unsigned char byValue[28] = {0};
	UNION_2DATA data2;
	UNION_4DATA data4;
	int nRtn;

	data4.dwValue = dwStartSpd;
	byValue[0] = data4.byValue[0];
	byValue[1] = data4.byValue[1];
	byValue[2] = data4.byValue[2];
	byValue[3] = data4.byValue[3];

	data4.dwValue = dwMoveSpd;
	byValue[4] = data4.byValue[0];
	byValue[5] = data4.byValue[1];
	byValue[6] = data4.byValue[2];
	byValue[7] = data4.byValue[3];

	data4.lValue = lPosition;
	byValue[8] = data4.byValue[0];
	byValue[9] = data4.byValue[1];
	byValue[10] = data4.byValue[2];
	byValue[11] = data4.byValue[3];

	data2.wValue = wAccel;
	byValue[12] = data2.byValue[0];
	byValue[13] = data2.byValue[1];

	data2.wValue = wDecel;
	byValue[14] = data2.byValue[0];
	byValue[15] = data2.byValue[1];

	data2.wValue = wPushRate;
	byValue[16] = data2.byValue[0];
	byValue[17] = data2.byValue[1];

	data4.dwValue = dwPushSpd;
	byValue[18] = data4.byValue[0];
	byValue[19] = data4.byValue[1];
	byValue[20] = data4.byValue[2];
	byValue[21] = data4.byValue[3];

	data4.lValue = lEndPosition;
	byValue[22] = data4.byValue[0];
	byValue[23] = data4.byValue[1];
	byValue[24] = data4.byValue[2];
	byValue[25] = data4.byValue[3];

	data2.wValue = wPushMode;
	byValue[26] = data2.byValue[0];
	byValue[27] = data2.byValue[1];

	nRtn = DoSendCommand(nBdID, FRAME_FAS_MOVEPUSH, byValue, sizeof(byValue), NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_GetPushStatus(int nBdID, unsigned char* nPushStatus)
{
	unsigned char byValue;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GETPUSHSTATUS, NULL, 0, &byValue, 1, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		if (nPushStatus != NULL)
			*nPushStatus = byValue;
	}

	return nRtn;
}

//------------------------------------------------------------------
//					Ex-Motion Functions.
//------------------------------------------------------------------
int FAS_MoveSingleAxisAbsPosEx(int nBdID, int lAbsPos, unsigned int lVelocity, MOTION_OPTION_EX* lpExOption)
{
	unsigned char byValue[40];
	UNION_4DATA data;
	int nRtn;

	data.lValue = lAbsPos;
	byValue[0] = data.byValue[0];
	byValue[1] = data.byValue[1];
	byValue[2] = data.byValue[2];
	byValue[3] = data.byValue[3];

	data.lValue = lVelocity;
	byValue[4] = data.byValue[0];
	byValue[5] = data.byValue[1];
	byValue[6] = data.byValue[2];
	byValue[7] = data.byValue[3];

	memcpy(&(byValue[8]), lpExOption, (sizeof(byValue) - 8));

	nRtn = DoSendCommand(nBdID, FRAME_FAS_MOVESINGLEABS_EX, byValue, sizeof(byValue), NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_MoveSingleAxisIncPosEx(int nBdID, int lIncPos, unsigned int lVelocity, MOTION_OPTION_EX* lpExOption)
{
	unsigned char byValue[40];
	UNION_4DATA data;
	int nRtn;

	data.lValue = lIncPos;
	byValue[0] = data.byValue[0];
	byValue[1] = data.byValue[1];
	byValue[2] = data.byValue[2];
	byValue[3] = data.byValue[3];

	data.lValue = lVelocity;
	byValue[4] = data.byValue[0];
	byValue[5] = data.byValue[1];
	byValue[6] = data.byValue[2];
	byValue[7] = data.byValue[3];

	memcpy(&(byValue[8]), lpExOption, (sizeof(byValue) - 8));

	nRtn = DoSendCommand(nBdID, FRAME_FAS_MOVESINGLEINC_EX, byValue, sizeof(byValue), NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_MoveVelocityEx(int nBdID, unsigned int lVelocity, int iVelDir, VELOCITY_OPTION_EX* lpExOption)
{
	unsigned char byValue[37];
	UNION_4DATA data;

	data.lValue = lVelocity;
	byValue[0] = data.byValue[0];
	byValue[1] = data.byValue[1];
	byValue[2] = data.byValue[2];
	byValue[3] = data.byValue[3];
	byValue[4] = (unsigned char)iVelDir;

	memcpy(&(byValue[5]), lpExOption, (sizeof(byValue) - 5));

	return DoSendCommand(nBdID, FRAME_FAS_MOVEVELOCITY_EX, byValue, sizeof(byValue), NULL, 0, SOCKET_WAITTIME);
}

//------------------------------------------------------------------
//					Position Table Functions.
//------------------------------------------------------------------
int FAS_PosTableReadItem(int nBdID, unsigned short wItemNo, LPITEM_NODE lpItem)
{
	UNION_2DATA data;

	data.wValue = wItemNo;

	return DoSendCommand(nBdID, FRAME_FAS_POSTAB_READ_ITEM, data.byValue, 2, (unsigned char*)lpItem, sizeof(ITEM_NODE), SOCKET_WAITTIME);
}

int FAS_PosTableWriteItem(int nBdID, unsigned short wItemNo, LPITEM_NODE lpItem)
{
	UNION_2DATA data;
	unsigned char byValue[sizeof(wItemNo) + sizeof(ITEM_NODE)];
	unsigned char nRtnCode;
	int nRtn;

	data.wValue = wItemNo;
	byValue[0] = data.byValue[0];
	byValue[1] = data.byValue[1];
	memcpy(&(byValue[2]), lpItem, sizeof(ITEM_NODE));

	nRtn = DoSendCommand(nBdID, FRAME_FAS_POSTAB_WRITE_ITEM, byValue, sizeof(byValue), &nRtnCode, 1, SOCKET_WAITTIME);

	if (nRtnCode == 0)
		return FMM_POSTABLE_ERROR;

	return nRtn;
}

int FAS_PosTableWriteROM(int nBdID)
{
	unsigned char nRtnCode;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_POSTAB_WRITE_ROM, NULL, 0, &nRtnCode, 1, SOCKET_WAITTIME * 20);

	if (nRtnCode != 0)
		return FMM_POSTABLE_ERROR;

	return nRtn;
}

int FAS_PosTableReadROM(int nBdID)
{
	unsigned char nRtnCode;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_POSTAB_READ_ROM, NULL, 0, &nRtnCode, 1, SOCKET_WAITTIME * 5);

	if (nRtnCode != 0)
		return FMM_POSTABLE_ERROR;

	return nRtn;
}

int FAS_PosTableRunItem(int nBdID, unsigned short wItemNo)
{
	UNION_2DATA data;

	data.wValue = wItemNo;

	return DoSendCommand(nBdID, FRAME_FAS_POSTAB_RUN_ITEM, data.byValue, 2, NULL, 0, SOCKET_WAITTIME);
}

int FAS_PosTableIsData(int nBdID, LPPOSTABLE_DATAFLAG pBitFlag)
{
	return DoSendCommand(nBdID, FRAME_FAS_POSTAB_IS_DATA, NULL, 0, (unsigned char*)pBitFlag, sizeof(POSTABLE_DATAFLAG), SOCKET_WAITTIME);
}

int FAS_PosTableIsDataEx(int nBdID, unsigned int dwSectionNo, LPPOSTABLE_DATAFLAG_EX pBitFlag)
{
	return DoSendCommand(nBdID, FRAME_FAS_POSTAB_IS_DATA_EX, (unsigned char*)&dwSectionNo, 4, (unsigned char*)pBitFlag, sizeof(POSTABLE_DATAFLAG_EX), SOCKET_WAITTIME);
}

int FAS_PosTableRunOneItem(int nBdID, int bNextMove, unsigned short wItemNo)
{
	unsigned char byValue[3];
	UNION_2DATA data;

	byValue[0] = (bNextMove) ? 1 : 0;		// Start / Next
	data.wValue = wItemNo;
	byValue[1] = data.byValue[0];
	byValue[2] = data.byValue[1];

	return DoSendCommand(nBdID, FRAME_FAS_POSTAB_RUN_ONEITEM, byValue, 3, NULL, 0, SOCKET_WAITTIME);
}

int FAS_PosTableCheckStopMode(int nBdID, unsigned char* pStopMode)
{
	unsigned char byValue;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_POSTAB_CHECK_STOPMODE, NULL, 0, &byValue, 1, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
		*pStopMode = byValue;

	return nRtn;
}

int FAS_PosTableReadOneItem(int nBdID, unsigned short wItemNo, unsigned short wOffset, int* lPosItemVal)
{
	unsigned char byValue[4];
	UNION_2DATA data;
	int lValue;
	int nRtn;

	data.wValue = wItemNo;
	byValue[0] = data.byValue[0];
	byValue[1] = data.byValue[1];
	data.wValue = wOffset;
	byValue[2] = data.byValue[0];
	byValue[3] = data.byValue[1];

	nRtn = DoSendCommand(nBdID, FRAME_FAS_POSTAB_READ_ONEITEM, byValue, 4, (unsigned char*)&lValue, 4, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		*lPosItemVal = lValue;
	}

	return nRtn;
}

int FAS_PosTableWriteOneItem(int nBdID, unsigned short wItemNo, unsigned short wOffset, int lPosItemVal)
{
	unsigned char byValue[8];
	UNION_2DATA data2;
	UNION_4DATA data4;

	data2.wValue = wItemNo;
	byValue[0] = data2.byValue[0];
	byValue[1] = data2.byValue[1];
	data2.wValue = wOffset;
	byValue[2] = data2.byValue[0];
	byValue[3] = data2.byValue[1];
	data4.dwValue = lPosItemVal;
	byValue[4] = data4.byValue[0];
	byValue[5] = data4.byValue[1];
	byValue[6] = data4.byValue[2];
	byValue[7] = data4.byValue[3];

	return DoSendCommand(nBdID, FRAME_FAS_POSTAB_WRITE_ONEITEM, byValue, 8, NULL, 0, SOCKET_WAITTIME);
}

//------------------------------------------------------------------
//					Gap Control Functions.
//------------------------------------------------------------------
int FAS_GapControlEnable(int nBdID, unsigned short wItemNo, int lGapCompSpeed, int lGapAccTime, int lGapDecTime, int lGapStartSpeed)
{
	unsigned char byData[18];
	UNION_2DATA data2;
	UNION_4DATA data4;

	data2.wValue = wItemNo;
	byData[0] = data2.byValue[0];
	byData[1] = data2.byValue[1];

	data4.lValue = lGapCompSpeed;
	byData[2] = data4.byValue[0];
	byData[3] = data4.byValue[1];
	byData[4] = data4.byValue[2];
	byData[5] = data4.byValue[3];

	data4.lValue = lGapAccTime;
	byData[6] = data4.byValue[0];
	byData[7] = data4.byValue[1];
	byData[8] = data4.byValue[2];
	byData[9] = data4.byValue[3];

	data4.lValue = lGapDecTime;
	byData[10] = data4.byValue[0];
	byData[11] = data4.byValue[1];
	byData[12] = data4.byValue[2];
	byData[13] = data4.byValue[3];

	data4.lValue = lGapStartSpeed;
	byData[14] = data4.byValue[0];
	byData[15] = data4.byValue[1];
	byData[16] = data4.byValue[2];
	byData[17] = data4.byValue[3];

	return DoSendCommand(nBdID, FRAME_FAS_GAPCONTROL_ENABLE, byData, 18, NULL, 0, SOCKET_WAITTIME);
}

int FAS_GapControlDisable(int nBdID)
{
	return DoSendCommand(nBdID, FRAME_FAS_GAPCONTROL_DISABLE, NULL, 0, NULL, 0, SOCKET_WAITTIME);
}

int FAS_IsGapControlEnable(int nBdID, int* bIsEnable, unsigned short* wCurrentItemNo)
{
	unsigned char byData[3];
	UNION_2DATA data;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GAPCONTROL_ISENABLE, NULL, 0, byData, 3, SOCKET_WAITTIME);
	if (nRtn == FMM_OK)
	{
		if (bIsEnable != NULL)
			*bIsEnable = byData[0];

		data.byValue[0] = byData[1];
		data.byValue[1] = byData[2];
		if (wCurrentItemNo != NULL)
			*wCurrentItemNo = data.wValue;
	}

	return nRtn;
}

int FAS_GapControlGetADCValue(int nBdID, int* lADCValue)
{
	int lValue = 0;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GAPCONTROL_GETADCVALUE, NULL, 0, (unsigned char*)&lValue, 4, SOCKET_WAITTIME);
	if (nRtn == FMM_OK)
	{
		if (lADCValue != NULL)
			*lADCValue = lValue;
	}

	return nRtn;
}

int FAS_GapOneResultMonitor(int nBdID, unsigned char* bUpdated, int* iIndex, int* lGapValue, int* lCmdPos, int* lActPos, int* lCompValue, int* lReserved)
{
	unsigned char byData[25];
	UNION_4DATA data;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_FAS_GAPONERESULT_MONITOR, NULL, 0, byData, 25, SOCKET_WAITTIME);
	if (nRtn == FMM_OK)
	{
		if (bUpdated != NULL)
			*bUpdated = byData[0];

		data.byValue[0] = byData[1];
		data.byValue[1] = byData[2];
		data.byValue[2] = byData[3];
		data.byValue[3] = byData[4];
		if (iIndex != NULL)
			*iIndex = data.lValue;

		data.byValue[0] = byData[5];
		data.byValue[1] = byData[6];
		data.byValue[2] = byData[7];
		data.byValue[3] = byData[8];
		if (lGapValue != NULL)
			*lGapValue = data.lValue;

		data.byValue[0] = byData[9];
		data.byValue[1] = byData[10];
		data.byValue[2] = byData[11];
		data.byValue[3] = byData[12];
		if (lCmdPos != NULL)
			*lCmdPos = data.lValue;

		data.byValue[0] = byData[13];
		data.byValue[1] = byData[14];
		data.byValue[2] = byData[15];
		data.byValue[3] = byData[16];
		if (lActPos != NULL)
			*lActPos = data.lValue;

		data.byValue[0] = byData[17];
		data.byValue[1] = byData[18];
		data.byValue[2] = byData[19];
		data.byValue[3] = byData[20];
		if (lCompValue != NULL)
			*lCompValue = data.lValue;

		data.byValue[0] = byData[21];
		data.byValue[1] = byData[22];
		data.byValue[2] = byData[23];
		data.byValue[3] = byData[24];
		if (lReserved != NULL)
			*lReserved = data.lValue;
	}

	return nRtn;
}

//------------------------------------------------------------------
//					Alarm Type History Functions.
//------------------------------------------------------------------
int FAS_GetAlarmLogs(int nBdID, ALARM_LOG* pAlarmLog)
{
	unsigned char byValue[MAX_ALARM_LOG + 1];
	int nRtn;
	int i = 0;
	int j;

	nRtn = DoSendCommand(nBdID, FRAME_ALARM_GETLOGS, NULL, 0, byValue, (MAX_ALARM_LOG + 1), SOCKET_WAITTIME);
	if (nRtn == FMM_OK)
	{
		if (pAlarmLog != NULL)
		{
			pAlarmLog->nAlarmCount = byValue[i++];

			for (j=0; j<MAX_ALARM_LOG; j++)
				pAlarmLog->nAlarmLog[j] = byValue[i++];
		}
	}

	return nRtn;
}

int FAS_ResetAlarmLogs(int nBdID)
{
	return DoSendCommand(nBdID, FRAME_ALARM_RESETLOGS, NULL, 0, NULL, 0, SOCKET_WAITTIME);
}

//------------------------------------------------------------------
//					I/O Module Functions.
//------------------------------------------------------------------
int FAS_GetInput(int nBdID, unsigned int* uInput, unsigned int* uLatch)
{
	unsigned int uData[2] = {0};
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_IO_GET_INPUT, NULL, 0, (unsigned char*)uData, 8, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		if (uInput != NULL)
			*uInput = uData[0];

		if (uLatch != NULL)
			*uLatch = uData[1];
	}

	return nRtn;
}

int FAS_ClearLatch(int nBdID, unsigned int uLatchMask)
{
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_IO_CLEAR_LATCH, (unsigned char*)&uLatchMask, 4, NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_GetLatchCount(int nBdID, unsigned char iInputNo, unsigned int* uCount)
{
	unsigned int lValue = 0;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_IO_GET_LATCH_COUNT, &iInputNo, 1, (unsigned char*)&lValue, 4, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		if (uCount != NULL)
			*uCount = lValue;
	}

	return nRtn;
}

int FAS_GetLatchCountAll(int nBdID, unsigned int** ppuAllCount)
{
	unsigned char byData[64];
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_IO_GET_LATCH_COUNT_ALL, NULL, 0, byData, 64, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		if (ppuAllCount != NULL)
		{
			memcpy(ppuAllCount, byData, sizeof(byData));
		}
	}

	return nRtn;
}

int FAS_ClearLatchCount(int nBdID, unsigned int uInputMask)
{
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_IO_CLEAR_LATCH_COUNT, (unsigned char*)&uInputMask, 4, NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_GetOutput(int nBdID, unsigned int* uOutput, unsigned int* uStatus)
{
	unsigned int uData[2] = {0};
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_IO_GET_OUTPUT, NULL, 0, (unsigned char*)uData, 8, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		if (uOutput != NULL)
			*uOutput = uData[0];

		if (uStatus != NULL)
			*uStatus = uData[1];
	}

	return nRtn;
}

int FAS_SetOutput(int nBdID, unsigned int uSetMask, unsigned int uClearMask)
{
	unsigned int uData[2] = {uSetMask, uClearMask};
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_IO_SET_OUTPUT, (unsigned char*)uData, 8, NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_SetTrigger(int nBdID, unsigned char uOutputNo, TRIGGER_INFO* pTrigger)
{
	unsigned char byData[13];
	int nRtn;
	int i;

	byData[0] = uOutputNo;

	for (i=0; i<12; i++)
	{
		byData[i+1] = pTrigger->byBuffer[i];
	}

	nRtn = DoSendCommand(nBdID, FRAME_IO_SET_TRIGGER, byData, 13, NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_SetRunStop(int nBdID, unsigned int uRunMask, unsigned int uStopMask)
{
	unsigned int lData[2] = {uRunMask, uStopMask};
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_IO_SET_RUNSTOP, (unsigned char*)lData, 8, NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_GetTriggerCount(int nBdID, unsigned char uOutputNo, unsigned int* uCount)
{
	unsigned int lData = 0;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_IO_GET_TRIGGER_COUNT, &uOutputNo, 1, (unsigned char*)&lData, 4, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		if (uCount != NULL)
			*uCount = lData;
	}

	return nRtn;
}

int FAS_GetIOLevel(int nBdID, unsigned int* uIOLevel)
{
	unsigned int lValue = 0;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_IO_GET_IO_LEVEL, NULL, 0, (unsigned char*)&lValue, 4, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		if (uIOLevel != NULL)
			*uIOLevel = lValue;
	}

	return nRtn;
}

int FAS_SetIOLevel(int nBdID, unsigned int uIOLevel)
{
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_IO_SET_IO_LEVEL, (unsigned char*)&uIOLevel, 4, NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_LoadIOLevel(int nBdID)
{
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_IO_LOAD_IO_LEVEL, NULL, 0, NULL, 0, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
	}

	return nRtn;
}

int FAS_SaveIOLevel(int nBdID)
{
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_IO_SAVE_IO_LEVEL, NULL, 0, NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

int FAS_GetInputFilter(int nBdID, unsigned short* filter)
{
	unsigned short value = 0;
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_IO_GET_INPUTFINTER, NULL, 0, (unsigned char*)&value, 2, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		if (filter != NULL)
			*filter = value;
	}

	return nRtn;
}

int FAS_SetInputFilter(int nBdID, unsigned short filter)
{
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_IO_SET_INPUTFINTER, (unsigned char*)&filter, 2, NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}

//------------------------------------------------------------------
//					Ez-IO Plus-AD Functions
//------------------------------------------------------------------
int FAS_GetAllADResult(int nBdID, AD_RESULT* result)
{
	unsigned char byValue[48];
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_GET_AD_RESULT, NULL, 0, byValue, 48, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		if (result != NULL)
		{
			char range;
			short rawdata;
			float converted;
			int i;

			for (i=0; i<MAX_AD_CHANNEL; i++)
			{
				range = byValue[(i * 3)];
				rawdata = byValue[(i * 3 + 1)] | (byValue[(i * 3 + 2)] << 8);

				switch (range)
				{
				case ADRANGE_10_to_10:	converted = (float)rawdata * 20 / 8192; break;
				case ADRANGE_5_to_5:	converted = (float)rawdata * 10 / 8192; break;
				case ADRANGE_2_5_to_2_5:converted = (float)rawdata * 5 / 8192; break;
				case ADRANGE_0_to_10:	converted = (float)(rawdata + 4096) * 10 / 8192; break;
				default:				converted = 0; break;
				}

				result->channel[i].range = range;
				result->channel[i].rawdata = rawdata;
				result->channel[i].converted = converted;
			}
		}
	}

	return nRtn;
}

int FAS_GetADResult(int nBdID, unsigned char channel, float* adresult)
{
	unsigned char byValue[48];
	int nRtn;

	nRtn = DoSendCommand(nBdID, FRAME_GET_AD_RESULT, NULL, 0, byValue, 48, SOCKET_WAITTIME);

	if (nRtn == FMM_OK)
	{
		if ((channel < MAX_AD_CHANNEL) && (adresult != NULL))
		{
			char range = byValue[(channel * 3)];
			short rawdata = byValue[(channel * 3 + 1)] | (byValue[(channel * 3 + 2)] << 8);

			switch (range)
			{
			case ADRANGE_10_to_10:	*adresult = (float)rawdata * 20 / 8192; break;
			case ADRANGE_5_to_5:	*adresult = (float)rawdata * 10 / 8192; break;
			case ADRANGE_2_5_to_2_5:*adresult = (float)rawdata * 5 / 8192; break;
			case ADRANGE_0_to_10:	*adresult = (float)(rawdata + 4096) * 10 / 8192; break;
			default:				*adresult = 0; break;
			}
		}
	}

	return nRtn;
}

int FAS_SetADRange(int nBdID, unsigned char channel, int range)
{
	unsigned char byValue[2];
	int nRtn;

	byValue[0] = channel;
	byValue[1] = (unsigned char)range;

	nRtn = DoSendCommand(nBdID, FRAME_SET_AD_RANGE, byValue, 2, NULL, 0, SOCKET_WAITTIME);

	return nRtn;
}
