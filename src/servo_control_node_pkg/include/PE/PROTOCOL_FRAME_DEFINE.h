#pragma once

//------------------------------------------------------------------
//                 FRAME TYPE Defines.
//------------------------------------------------------------------
#define FRAME_GETSLAVEINFO				0x01
#define FRAME_GETMOTORINFO				0x05

#define FRAME_GETSLAVEINFO_EX			0x09

#define FRAME_FAS_SAVEALLPARAM			0x10
#define FRAME_FAS_GETROMPARAM			0x11
#define FRAME_FAS_SETPARAMETER			0x12
#define FRAME_FAS_GETPARAMETER			0x13

#define FRAME_FAS_SETIO_OUTPUT			0x20
#define FRAME_FAS_SETIO_INPUT			0x21
#define FRAME_FAS_GETIO_INPUT			0x22
#define FRAME_FAS_GETIO_OUTPUT			0x23

#define FRAME_FAS_SET_IO_ASSGN_MAP		0x24
#define FRAME_FAS_GET_IO_ASSGN_MAP		0x25
#define FRAME_FAS_IO_ASSGN_MAP_READROM	0x26

// Trigger commands.
#define FRAME_FAS_TRIGGER_OUTPUT		0x27
#define FRAME_FAS_TRIGGER_STATUS		0x28

#define FRAME_FAS_SERVOENABLE			0x2A
#define FRAME_FAS_ALARMRESET			0x2B
#define FRAME_FAS_STEPALARMRESET		0x2C	// Step Alarm Reset function.

#define FRAME_FAS_GETALARMTYPE			0x2E	// Alarm Type

#define FRAME_FAS_GETAXISSTATUS			0x40
#define FRAME_FAS_GETIOAXISSTATUS		0x41
#define FRAME_FAS_GETMOTIONSTATUS		0x42
#define FRAME_FAS_GETALLSTATUS			0x43
#define FRAME_FAS_GETALLSTATUSEX		0x4D

#define FRAME_FAS_GETALLTORQUESTATUS	0x45
#define FRAME_FAS_GETTORQUESTATUS		0x46

#define FRAME_FAS_SETCMDPOS				0x50
#define FRAME_FAS_GETCMDPOS				0x51
#define FRAME_FAS_SETACTPOS				0x52
#define FRAME_FAS_GETACTPOS				0x53
#define FRAME_FAS_GETPOSERR				0x54
#define FRAME_FAS_GETACTVEL				0x55
#define FRAME_FAS_CLEARPOS				0x56

#define FRAME_FAS_MOVEPAUSE				0x58

#define FRAME_FAS_MOVESTOP				0x31
#define FRAME_FAS_EMERGENCYSTOP			0x32

#define FRAME_FAS_MOVEORIGIN			0x33
#define FRAME_FAS_MOVESINGLEABS			0x34
#define FRAME_FAS_MOVESINGLEINC			0x35
#define FRAME_FAS_MOVETOLIMIT			0x36
#define FRAME_FAS_MOVEVELOCITY			0x37

#define FRAME_FAS_POSABSOVERRIDE		0x38
#define FRAME_FAS_POSINCOVERRIDE		0x39
#define FRAME_FAS_VELOVERRIDE			0x3A

#define FRAME_FAS_ALLMOVESTOP			0x3B
#define FRAME_FAS_ALLEMERGENCYSTOP		0x3C
#define FRAME_FAS_ALLMOVEORIGIN			0x3D
#define FRAME_FAS_ALLMOVESINGLEABS		0x3E
#define FRAME_FAS_ALLMOVESINGLEINC		0x3F

// Position Table specific commands.
#define FRAME_FAS_POSTAB_READ_ITEM			0x60
#define FRAME_FAS_POSTAB_WRITE_ITEM			0x61
#define FRAME_FAS_POSTAB_READ_ROM			0x62
#define FRAME_FAS_POSTAB_WRITE_ROM			0x63
#define FRAME_FAS_POSTAB_RUN_ITEM			0x64
#define FRAME_FAS_POSTAB_IS_DATA			0x65

#define FRAME_FAS_POSTAB_IS_DATA_EX			0x6C

#define FRAME_FAS_POSTAB_RUN_ONEITEM		0x68
#define FRAME_FAS_POSTAB_CHECK_STOPMODE		0x69

#define FRAME_FAS_POSTAB_READ_ONEITEM		0x6A
#define FRAME_FAS_POSTAB_WRITE_ONEITEM		0x6B

// Linear Motion Commands
#define FRAME_FAS_SETLINEARINFO				0x70
#define FRAME_FAS_MOVELINEARINC				0x71

// Push Motion Commands
#define FRAME_FAS_MOVEPUSH					0x78
#define FRAME_FAS_GETPUSHSTATUS				0x79

// Trigger Ex Commands
#define FRAME_SET_TRIGGEROUTPUT_EX			0x7E
#define FRAME_GET_TRIGGEROUTPUT_EX			0x7F

// Ex-Motion Commands
#define FRAME_FAS_MOVESINGLEABS_EX			0x80
#define FRAME_FAS_MOVESINGLEINC_EX			0x81
#define FRAME_FAS_MOVEVELOCITY_EX			0x82

// Controlling GAP Commands
#define FRAME_FAS_GAPCONTROL_ENABLE			0x94
#define FRAME_FAS_GAPCONTROL_DISABLE		0x95
#define FRAME_FAS_GAPCONTROL_ISENABLE		0x96

#define FRAME_FAS_GAPCONTROL_GETADCVALUE	0x97
#define FRAME_FAS_GAPONERESULT_MONITOR		0x98

// Alarm Log Functions
#define FRAME_ALARM_GETLOGS					0x9C
#define FRAME_ALARM_RESETLOGS				0x9D

// I/O Module Functions.
#define FRAME_IO_GET_INPUT					0xC0
#define FRAME_IO_CLEAR_LATCH				0xC1
#define FRAME_IO_GET_LATCH_COUNT			0xC2
#define FRAME_IO_GET_LATCH_COUNT_ALL		0xC3
#define FRAME_IO_CLEAR_LATCH_COUNT			0xC4
#define FRAME_IO_GET_OUTPUT					0xC5
#define FRAME_IO_SET_OUTPUT					0xC6
#define FRAME_IO_SET_TRIGGER				0xC7
#define FRAME_IO_SET_RUNSTOP				0xC8
#define FRAME_IO_GET_TRIGGER_COUNT			0xC9
#define FRAME_IO_GET_IO_LEVEL				0xCA
#define FRAME_IO_SET_IO_LEVEL				0xCB
#define FRAME_IO_LOAD_IO_LEVEL				0xCC
#define FRAME_IO_SAVE_IO_LEVEL				0xCD

#define FRAME_IO_GET_INPUTFINTER			0xCE
#define FRAME_IO_SET_INPUTFINTER			0xCF

// Ez-IO Plus-AD Functions
#define FRAME_GET_AD_RESULT					0x6E
#define FRAME_SET_AD_RANGE					0x6F
