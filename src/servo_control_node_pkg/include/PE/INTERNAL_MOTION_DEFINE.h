#pragma once

//------------------------------------------------------------------
//                 SLAVE TYPE Defines.
//------------------------------------------------------------------

#define	SLAVE_ALL_COMMAND		(99)

//----------------------------------------------------------------
//           Motor DB Structure
//------------------------------------------------------------------

typedef struct
{
	int	nMotorNo[16];
} LIST_MOTORDB;

//------------------------------------------------------------------
//                 POSITION TABLE Defines.
//------------------------------------------------------------------
// Device�� Position Table ������ ������ üũ�ϱ� ���� ����.
typedef struct
{
	unsigned int dwBitArray[8];	// 256 bit -> 8 DWORD
} POSTABLE_DATAFLAG, *LPPOSTABLE_DATAFLAG;

typedef struct
{
	unsigned char byBitArray[8];		// 64 bit -> 8 BYTE
} POSTABLE_DATAFLAG_EX, *LPPOSTABLE_DATAFLAG_EX;

static const unsigned short	INVALID_ITEM_NO =	0xFFFF;

//------------------------------------------------------------------
//                 etc.
//------------------------------------------------------------------

typedef union
{
	char			chValue[4];
	unsigned char	byValue[4];
	int			lValue;
	unsigned int	dwValue;
} UNION_4DATA;

typedef union
{
	char			chValue[2];
	unsigned char	byValue[2];
	short			shValue;
	unsigned short	wValue;
} UNION_2DATA;
