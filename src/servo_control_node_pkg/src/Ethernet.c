#include "Ethernet.h"

// Command
unsigned char		m_BuffSend[MAX_BUFFER_SIZE];
unsigned char		m_BuffRecv[MAX_BUFFER_SIZE];

unsigned char		m_nSyncNo = 0;

#ifdef _USE_TCP_PROTOCOL_
int SendTCPPacket(int nBdID, unsigned char FrameType, unsigned char* lpData, unsigned int dwLen)
{
	int byLen;

	byLen = (dwLen + SENDOFFSET_DATA);	// (Header, Length, Sync, CMD) + dwLen

	// Make Packet -----------------------------------------------------
	m_BuffSend[SENDOFFSET_HEADER] = PACKET_HEADER;
	m_BuffSend[SENDOFFSET_LENGTH] = (unsigned char)(dwLen + (SENDOFFSET_CMD - SENDOFFSET_LENGTH));	// Sync, CMD
	m_BuffSend[SENDOFFSET_SYNC] = m_nSyncNo;
	m_BuffSend[SENDOFFSET_AXIS] = 0;
	m_BuffSend[SENDOFFSET_CMD] = FrameType;
	if (dwLen > 0)
		memcpy(&(m_BuffSend[SENDOFFSET_DATA]), lpData, dwLen);

	// Send Packet ----------------------------------------------------
	if (!send_tcp(nBdID, (const char*)m_BuffSend, byLen))
	{
		// Close Socket
		close_socket(nBdID);

		return 0;
	}

	return 1;
}

int RecvTCPPacket(int nBdID, unsigned char FrameType, unsigned char* lpData, unsigned int dwLen, unsigned int dwWaitTime)
{
	int nRead;
	int nTotalRecv;
	int nRemain;

	nRemain = MAX_BUFFER_SIZE;
	nTotalRecv = 0;

	CommTimer_Reset(dwWaitTime);

	while (nRemain > 0)
	{
		// Packet
		nRead = recv_tcp(nBdID, (m_BuffRecv + nTotalRecv), nRemain);
		if (nRead == SOCKET_ERROR)
		{
			// Socket error
			if (CommTimer_IsExpired())
			{
				return FMC_TIMEOUT_ERROR;
			}
			else
			{
				continue;
			}
		}
		else if (nRead == 0)
		{
			// Close Socket
			close_socket(nBdID);
			return FMC_DISCONNECTED;
		}

		CommTimer_Reset(dwWaitTime);

		nTotalRecv += nRead;
		nRemain -= nRead;

		if (m_BuffRecv[RECVOFFSET_HEADER] != PACKET_HEADER)
		{
			// Reset
			nRemain = MAX_BUFFER_SIZE;
			nTotalRecv = 0;

			continue;
		}

		if (nTotalRecv < (m_BuffRecv[RECVOFFSET_LENGTH] + RECVOFFSET_SYNC))
		{
			// Not enough
			continue;
		}

		if ((m_BuffRecv[RECVOFFSET_SYNC] != m_nSyncNo) ||
			(m_BuffRecv[RECVOFFSET_AXIS] != 0) ||
			(m_BuffRecv[RECVOFFSET_CMD] != FrameType))
		{
			// Not mine. Reset
			nRemain = MAX_BUFFER_SIZE;
			nTotalRecv = 0;

			continue;
		}

		if (m_BuffRecv[RECVOFFSET_STATUS] != FMM_OK)
		{
			// Communication Status is NOT OK.
			return m_BuffRecv[RECVOFFSET_STATUS];
		}

		if ((nTotalRecv != (dwLen + RECVOFFSET_DATA)) &&
			(((int)dwLen != MAX_BUFFER_SIZE) || (nTotalRecv > (int)dwLen)))
		{
			// Not enough
			return FMC_RECVPACKET_ERROR;
		}

		// everything is FINE.
		if ((dwLen > 0) && (nTotalRecv > RECVOFFSET_DATA))
		{
			memcpy(lpData, &(m_BuffRecv[RECVOFFSET_DATA]), MIN(nTotalRecv, (int)dwLen));
		}

		return FMM_OK;
	}

	// Buffer full
	return FMC_RECVPACKET_ERROR;
}
#endif // _USE_TCP_PROTOCOL_

#ifndef _USE_TCP_PROTOCOL_
int SendUDPPacket(int nBdID, unsigned char FrameType, unsigned char* lpData, unsigned int dwLen)
{
	int byLen;

	byLen = (dwLen + SENDOFFSET_DATA);	// (Header, Length, Sync, CMD) + dwLen

	// Make Packet -----------------------------------------------------
	m_BuffSend[SENDOFFSET_HEADER] = PACKET_HEADER;
	m_BuffSend[SENDOFFSET_LENGTH] = (unsigned char)(dwLen + (SENDOFFSET_CMD - SENDOFFSET_LENGTH));	// Sync, CMD
	m_BuffSend[SENDOFFSET_SYNC] = m_nSyncNo;
	m_BuffSend[SENDOFFSET_AXIS] = 0;
	m_BuffSend[SENDOFFSET_CMD] = FrameType;

	if (dwLen > 0)
		memcpy(&(m_BuffSend[SENDOFFSET_DATA]), lpData, dwLen);

	// Send Packet ----------------------------------------------------
	if (!send_udp(nBdID, (const char*)m_BuffSend, byLen))
	{
		// Close Socket
		if (_socket[nBdID] != 0) close_socket(nBdID);
		
		return 0;
	}

	return 1;
}

int RecvUDPPacket(int nBdID, unsigned char FrameType, unsigned char* lpData, unsigned int dwLen, unsigned int dwWaitTime)
{
	int nRead = 0;

	// I dont use additional timer for controlling timeout 
	// linux socket has built-in timeout for recv commands
	
	//CommTimer_Reset(dwWaitTime);

	do
	{
		// Packet
		nRead = recv_udp(nBdID, (char*)m_BuffRecv, MAX_BUFFER_SIZE);

		if (nRead == SOCKET_ERROR)
		{
			return FMC_TIMEOUT_ERROR;

			/* // Socket error
			if (CommTimer_IsExpired())
			{
				return FMC_TIMEOUT_ERROR;
			}
			else
			{
				continue;
			} */
		}

		//CommTimer_Reset(dwWaitTime);

		if (m_BuffRecv[RECVOFFSET_HEADER] != PACKET_HEADER)
		{
			// Reset
			continue;
		}

		if (nRead < (m_BuffRecv[RECVOFFSET_LENGTH] + RECVOFFSET_SYNC))
		{
			// Not enough
			return FMC_RECVPACKET_ERROR;
		}

		if ((m_BuffRecv[RECVOFFSET_SYNC] != m_nSyncNo) ||
			(m_BuffRecv[RECVOFFSET_AXIS] != 0) ||
			(m_BuffRecv[RECVOFFSET_CMD] != FrameType))
		{
			// Not mine. Reset
			continue;
		}

		if (m_BuffRecv[RECVOFFSET_STATUS] != FMM_OK)
		{
			// Communication Status is NOT OK.
			return m_BuffRecv[RECVOFFSET_STATUS];
		}

		if ((nRead != (dwLen + RECVOFFSET_DATA)) &&
			(((int)dwLen != MAX_BUFFER_SIZE) || (nRead > (int)dwLen)))
		{
			// Not enough
			return FMC_RECVPACKET_ERROR;
		}

		// everything is FINE.
		if ((dwLen > 0) && (nRead > RECVOFFSET_DATA))
		{
			memcpy(lpData, &(m_BuffRecv[RECVOFFSET_DATA]), MIN(nRead, (int)dwLen));
		}

		return FMM_OK;
	}
	while (1);
}
#endif // _USE_TCP_PROTOCOL_

int DoSendCommand(int nBdID, unsigned char byCmd, unsigned char* lpIN, unsigned int dwINlen, unsigned char* lpOUT, unsigned int dwOUTlen, unsigned int dwWaitTime)
{
	int nRtn = FMM_OK;

	m_nSyncNo++;

#ifdef _USE_TCP_PROTOCOL_
	{
		// Send
		if (SendTCPPacket(nBdID, byCmd, (unsigned char*)lpIN, dwINlen))
		{
			// Recv
			nRtn = RecvTCPPacket(nBdID, byCmd, (unsigned char*)lpOUT, dwOUTlen, dwWaitTime);
		}
		else
		{
			nRtn = FMC_DISCONNECTED;
		}
	}
#else
	{
		int nRetry = 3;

		do
		{
			// Send
			if (SendUDPPacket(nBdID, byCmd, (unsigned char*)lpIN, dwINlen))
			{
				// Recv
				nRtn = RecvUDPPacket(nBdID, byCmd, (unsigned char*)lpOUT, dwOUTlen, dwWaitTime);

				// reduce retry-counter
				nRetry--;
			}
			else
			{
				// Send Failed!
				nRtn = FMC_DISCONNECTED;
				break;
			}
		}
		while ((nRtn != FMM_OK) && (nRtn != FMC_DISCONNECTED) && (nRetry > 0));
	}
#endif // _USE_TCP_PROTOCOL_

	return nRtn;
}

int DoSendCommandNoResp(int nBdID, unsigned char byCmd, unsigned char* lpIN, unsigned int dwINlen)
{
	int nRtn = FMM_OK;

	m_nSyncNo++;

	// Send
#ifdef _USE_TCP_PROTOCOL_
	{
		if (!SendTCPPacket(nBdID, byCmd, (unsigned char*)lpIN, dwINlen))
		{
			nRtn = FMC_DISCONNECTED;
		}
	}
#else
	{
		if (!SendUDPPacket(nBdID, byCmd, (unsigned char*)lpIN, dwINlen))
		{
			nRtn = FMC_DISCONNECTED;
		}
	}
#endif // _USE_TCP_PROTOCOL_

	return nRtn;
}

//------------------------------------------------------------------
//                 Timer Function which have to call in INT.
//------------------------------------------------------------------
volatile unsigned int glb_CommTimer_Remain = 0;

void CommTimer_Tick()
{
	if (glb_CommTimer_Remain > 0)
		glb_CommTimer_Remain--;
}

//------------------------------------------------------------------
//                 Timer Functions which CommInterface use.
//------------------------------------------------------------------
void CommTimer_Reset(unsigned int nTime)
{
	glb_CommTimer_Remain = nTime;
}

int CommTimer_IsExpired()
{
	return (glb_CommTimer_Remain == 0);
}
