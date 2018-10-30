#pragma once

#include <string.h>
#include <sys/param.h>
#include "PE/ETHERNET_DEFINE.h"
#include "PE/ETHERNET_SETTING.h"
#include "PE/MOTION_EziSERVO_DEFINE.h"
#include "PE/RETURNCODES_DEFINE.h"

//------------------------------------------------------------------
//                 Timer Function which have to call in INT.
//------------------------------------------------------------------
void CommTimer_Tick();

//------------------------------------------------------------------
//                 Timer Functions which CommInterface use.
//------------------------------------------------------------------
void CommTimer_Reset(unsigned int nTime);
int  CommTimer_IsExpired();

//------------------------------------------------------------------
//                 Protocol Functions which CommInterface use.
//------------------------------------------------------------------
#define SOCKET_WAITTIME 	100

#ifdef _USE_TCP_PROTOCOL_
int SendTCPPacket(int nBdID, unsigned char FrameType, unsigned char* lpData, unsigned int dwLen);
int RecvTCPPacket(int nBdID, unsigned char FrameType, unsigned char* lpData, unsigned int dwLen, unsigned int dwWaitTime);
#else
int SendUDPPacket(int nBdID, unsigned char FrameType, unsigned char* lpData, unsigned int dwLen);
int RecvUDPPacket(int nBdID, unsigned char FrameType, unsigned char* lpData, unsigned int dwLen, unsigned int dwWaitTime);
#endif // _USE_TCP_PROTOCOL_

int DoSendCommand(int nBdID, unsigned char byCmd, unsigned char* lpIN, unsigned int dwINlen, unsigned char* lpOUT, unsigned int dwOUTlen, unsigned int dwWaitTime);
int DoSendCommandNoResp(int nBdID, unsigned char byCmd, unsigned char* lpIN, unsigned int dwINlen);
