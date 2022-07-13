/********************************************************************************/
/*	Object Name		�FHeader file of function for SLMP library					*/
/*	File Name		�FSLMP.h													*/
/*	Data			�F2015/03/02												*/
/*	Version			�F1.00														*/
/*																				*/
/*	COPYRIGHT (C) 2015 CC-Link Partner Association ALL RIGHTS RESERVED			*/
/********************************************************************************/

#ifndef		__SLMP_H__
#define		__SLMP_H__

/*[ Structure of SLMP Info  ]*/
typedef struct
{
	unsigned long	ulFrameType;			/* Frame Type */
	unsigned short	usSerialNumber;			/* Serial Number */
	unsigned short	usNetNumber;			/* Network Number */
	unsigned short	usNodeNumber;			/* Node Number */
	unsigned short	usProcNumber;			/* Processor Number */
	unsigned short	usDataLength;			/* Data Length */
	unsigned short	usTimer;				/* Timer Value */
	unsigned short	usCommand;				/* Command */
	unsigned short	usSubCommand;			/* Sub Command */
	unsigned short	usEndCode;				/* End Code */
	unsigned char *	pucData;				/* Data */
}SLMP_INFO;

/*[ Definition of Frame Type ]*/
#define	SLMP_FTYPE_BIN_REQ_ST							(0x5000)
#define SLMP_FTYPE_BIN_RES_ST							(0xD000)
#define	SLMP_FTYPE_BIN_REQ_MT							(0x5400)
#define SLMP_FTYPE_BIN_RES_MT							(0xD400)
#define	SLMP_FTYPE_ASCII_REQ_ST							(0x35303030) /* '5000' */
#define	SLMP_FTYPE_ASCII_RES_ST							(0x44303030) /* 'D000' */
#define	SLMP_FTYPE_ASCII_REQ_MT							(0x35343030) /* '5400' */
#define	SLMP_FTYPE_ASCII_RES_MT							(0x44343030) /* 'D400' */

/*[ Definition of Index per frame type ]*/
#define	SLMP_FTYPE_BIN_REQ_ST_INDEX						(0x00)
#define SLMP_FTYPE_BIN_RES_ST_INDEX						(0x01)
#define	SLMP_FTYPE_BIN_REQ_MT_INDEX						(0x02)
#define SLMP_FTYPE_BIN_RES_MT_INDEX						(0x03)
#define	SLMP_FTYPE_ASCII_REQ_ST_INDEX					(0x04)
#define	SLMP_FTYPE_ASCII_RES_ST_INDEX					(0x05)
#define	SLMP_FTYPE_ASCII_REQ_MT_INDEX					(0x06)
#define	SLMP_FTYPE_ASCII_RES_MT_INDEX					(0x07)

/*[ Definition of Data Code ]*/
#define	SLMP_DATA_CODE_BIN								0
#define	SLMP_DATA_CODE_ASCII							1
#define SLMP_DATA_CODE(a)\
	(((a == SLMP_FTYPE_BIN_REQ_ST) | (a == SLMP_FTYPE_BIN_RES_ST) | (a == SLMP_FTYPE_BIN_REQ_MT) | (a == SLMP_FTYPE_BIN_RES_MT)) ? SLMP_DATA_CODE_BIN :\
	 ((a == SLMP_FTYPE_ASCII_REQ_ST) | (a == SLMP_FTYPE_ASCII_RES_ST) | (a == SLMP_FTYPE_ASCII_REQ_MT) | (a == SLMP_FTYPE_ASCII_RES_MT)) ? SLMP_DATA_CODE_ASCII : -1)

/*[ Definition of Response Frame Type ]*/
#define SLMP_RESPONSE_FRAME_TYPE(a)\
	((a == SLMP_FTYPE_BIN_REQ_ST) ? SLMP_FTYPE_BIN_RES_ST :\
	((a == SLMP_FTYPE_BIN_REQ_MT) ? SLMP_FTYPE_BIN_RES_MT :\
	((a == SLMP_FTYPE_ASCII_REQ_ST) ? SLMP_FTYPE_ASCII_RES_ST :\
	((a == SLMP_FTYPE_ASCII_REQ_MT) ? SLMP_FTYPE_ASCII_RES_MT : -1))))

/*[ Definition of SLMP Frame Header Size ]*/
#define SLMP_HEADER_SIZE(a)\
	(((a == SLMP_FTYPE_BIN_REQ_ST) | (a == SLMP_FTYPE_BIN_RES_ST)) ? 11 :\
	(((a == SLMP_FTYPE_BIN_REQ_MT) | (a == SLMP_FTYPE_BIN_RES_MT)) ? 15 :\
	(((a == SLMP_FTYPE_ASCII_REQ_ST) | (a == SLMP_FTYPE_ASCII_RES_ST)) ? 22 :\
	(((a == SLMP_FTYPE_ASCII_REQ_MT) | (a == SLMP_FTYPE_ASCII_RES_MT)) ? 30 : 0))))

/*[ Definition of SLMP Commands ]*/
/* Device */
#define	SLMP_COMMAND_DEVICE_READ							(0x0401)
#define	SLMP_COMMAND_DEVICE_WRITE							(0x1401)
#define	SLMP_COMMAND_DEVICE_READ_RANDOM						(0x0403)
#define	SLMP_COMMAND_DEVICE_WRITE_RANDOM					(0x1402)
#define	SLMP_COMMAND_DEVICE_ENTRY_MONITOR_DEVICE			(0x0801)
#define	SLMP_COMMAND_DEVICE_EXECUTE_MONITOR					(0x0802)
#define	SLMP_COMMAND_DEVICE_READ_BLOCK						(0x0406)
#define SLMP_COMMAND_DEVICE_WRITE_BLOCK						(0x1406)

/* Memory */
#define	SLMP_COMMAND_MEMORY_READ							(0x0613)
#define	SLMP_COMMAND_MEMORY_WRITE							(0x1613)

/* ExtendUnit */
#define	SLMP_COMMAND_EXTEND_UNIT_READ						(0x0601)
#define	SLMP_COMMAND_EXTEND_UNIT_WRITE						(0x1601)

/* RemoteControl */
#define	SLMP_COMMAND_REMOTE_RUN								(0x1001)
#define	SLMP_COMMAND_REMOTE_STOP							(0x1002)
#define	SLMP_COMMAND_REMOTE_PAUSE							(0x1003)
#define	SLMP_COMMAND_REMOTE_LATCH_CLEAR						(0x1005)
#define	SLMP_COMMAND_REMOTE_RESET							(0x1006)
#define	SLMP_COMMAND_REMOTE_READ_TYPE_NAME					(0x0101)

/* Drive */
#define	SLMP_COMMAND_DRIVE_READ_DISK_STATE					(0x0205)
#define	SLMP_COMMAND_DRIVE_DEFRAG							(0x1207)

/* FILE */
#define SLMP_COMMAND_FILE_READ_FILE_INFO					(0x0201)
#define	SLMP_COMMAND_FILE_READ_FILE_INFO_DETAIL				(0x0202)
#define	SLMP_COMMAND_FILE_READ_FILE_INFO_FILE_NUMBER_USAGE	(0x0204)
#define	SLMP_COMMAND_FILE_CHANGE_FILE_INFO					(0x1204)
#define	SLMP_COMMAND_FILE_SEARCH							(0x0203)
#define	SLMP_COMMAND_FILE_READ_ACCESS_TYPE_A				(0x0206)
#define	SLMP_COMMAND_FILE_WRITE_ACCESS_TYPE_A				(0x1203)
#define	SLMP_COMMAND_FILE_LOCK_CONTROL						(0x0808)
#define	SLMP_COMMAND_FILE_COPY_ACCESS_TYPE_A				(0x1206)
#define	SLMP_COMMAND_FILE_COPY_ACCESS_TYPE_B				(0x1824)
#define	SLMP_COMMAND_FILE_DELETE_ACCESS_TYPE_A				(0x1205)
#define	SLMP_COMMAND_FILE_DELETE_ACCESS_TYPE_B				(0x1822)
#define	SLMP_COMMAND_FILE_READ_DEIRECTORY_FILE				(0x1810)
#define	SLMP_COMMAND_FILE_SEARCH_DIRECTORY_FILE				(0x1811)
#define	SLMP_COMMAND_FILE_CREATE_NEW_FILE_ACCESS_TYPE_A		(0x1202)
#define	SLMP_COMMAND_FILE_CREATE_NEW_FILE_ACCESS_TYPE_B		(0x1820)
#define	SLMP_COMMAND_FILE_CHANGE_FILE_STATE					(0x1825)
#define	SLMP_COMMAND_FILE_CHANGE_FILE_DATE					(0x1826)
#define	SLMP_COMMAND_FILE_OPEN_FILE							(0x1827)
#define	SLMP_COMMAND_FILE_READ_ACCESS_TYPE_B				(0x1828)
#define	SLMP_COMMAND_FILE_WRITE_ACCESS_TYPE_B				(0x1829)
#define	SLMP_COMMAND_FILE_CLOSE_FILE						(0x182A)

/* TEST */
#define	SLMP_COMMAND_SELF_TEST								(0x0619)

/* CLEAR ERROR */
#define	SLMP_COMMAND_CLEAR_ERROR_CODE						(0x1617)

/* REMOTE PASSWORD */
#define	SLMP_COMMAND_PASSWORD_LOCK							(0x1630)
#define	SLMP_COMMAND_PASSWORD_UNLOCK						(0x1631)

/* ONDEMAND */
#define	SLMP_COMMAND_ONDEMAND								(0x2101)

/* NODE CONNECT */
#define	SLMP_COMMAND_NODE_SEARCH							(0x0E30)
#define	SLMP_COMMAND_IP_ADDRESS_SET							(0x0E31)

/* PARAMETER SETTING */
#define	SLMP_COMMAND_DEVICE_INFO_COMPARE					(0x0E32)
#define	SLMP_COMMAND_PARAMETER_GET							(0x0E33)
#define	SLMP_COMMAND_PARAMETER_SET							(0x0E34)
#define	SLMP_COMMAND_PARAMETER_SET_START					(0x0E35)
#define	SLMP_COMMAND_PARAMETER_SET_END						(0x0E36)
#define	SLMP_COMMAND_PARAMETER_SET_CANCEL					(0x0E3A)

/* NODE MONITORING */
#define	SLMP_COMMAND_STATUS_READ							(0x0E44)
#define	SLMP_COMMAND_COMMUNICATION_SETTING_GET				(0x0E45)
#define	SLMP_COMMAND_STATUS_READ2							(0x0E53)

/*[ Definition of Processor Number ]*/
#define	SLMP_CPU_ACTIVE										(0x03D0)
#define	SLMP_CPU_STANDBY									(0x03D1)
#define	SLMP_CPU_TYPE_A										(0x03D2)
#define SLMP_CPU_TYPE_B										(0x03D3)
#define	SLMP_CPU_1											(0x03E0)
#define	SLMP_CPU_2											(0x03E1)
#define	SLMP_CPU_3											(0x03E2)
#define	SLMP_CPU_4											(0x03E3)
#define	SLMP_CPU_DEFAULT									(0x03FF)

/*[ Definition of Timer Value ]*/
#define	SLMP_TIMER_WAIT_FOREVER								(0x0000)

/*[ Definition of SLMP Error Codes ]*/
#define SLMP_ERR_COMMAND_SUBCOMMAND							(0xC059)
#define SLMP_ERR_WRONG_DATA									(0xC05C)
#define SLMP_ERR_DATA_LENGTH								(0xC061)
#define SLMP_ERR_UNDER_EXECUTION							(0xCEE0)
#define SLMP_ERR_REQ_DATA_SIZE								(0xCEE1)
#define SLMP_ERR_RES_DATA_SIZE								(0xCEE2)
#define SLMP_ERR_NO_EXIST_SERVER_NO							(0xCF10)
#define SLMP_ERR_CAN_NOT_COMMUNICATION_SETTING				(0xCF20)
#define SLMP_ERR_NO_EXIST_PARAM_ID							(0xCF30)
#define SLMP_ERR_CAN_NOT_PARAMETER_SET						(0xCF31)

/*[ Definition of value ]*/
#define SLMP_ERR_OK		0
#define SLMP_ERR_NG		(-1)
#ifndef	NULL
#define NULL			0
#endif

/*[ Definition of mask value ]*/
#define MASK_UPPER4BIT		(0xF0)
#define MASK_LOWER4BIT		(0x0F)

/*[ Definition of bit operation ]*/
#define SHIFT_R24(a)			((unsigned char)((a) >> 24))
#define SHIFT_R20(a)			((unsigned char)((a) >> 20))
#define SHIFT_R16(a)			((unsigned char)((a) >> 16))
#define SHIFT_R12(a)			((unsigned char)((a) >> 12))
#define SHIFT_R8(a)				((unsigned char)((a) >>  8))
#define SHIFT_R7(a)				((unsigned char)((a) >>  7))
#define SHIFT_R6(a)				((unsigned char)((a) >>  6))
#define SHIFT_R5(a)				((unsigned char)((a) >>  5))
#define SHIFT_R4(a)				((unsigned char)((a) >>  4))
#define SHIFT_R3(a)				((unsigned char)((a) >>  3))
#define SHIFT_R2(a)				((unsigned char)((a) >>  2))
#define SHIFT_R1(a)				((unsigned char)((a) >>  1))
#define SHIFT_R0(a)				((unsigned char)((a)      ))

#define SHIFT_L0(a)				((unsigned char)((a)      ))
#define SHIFT_L1(a)				((unsigned char)((a) <<  1))
#define SHIFT_L2(a)				((unsigned char)((a) <<  2))
#define SHIFT_L3(a)				((unsigned char)((a) <<  3))
#define SHIFT_L4(a)				((unsigned char)((a) <<  4))
#define SHIFT_L5(a)				((unsigned char)((a) <<  5))
#define SHIFT_L6(a)				((unsigned char)((a) <<  6))
#define SHIFT_L7(a)				((unsigned char)((a) <<  7))
#define SHIFT_L8(a)				((unsigned short)((a) <<  8))
#define SHIFT_L16(a)			((unsigned long)((a) << 16))
#define SHIFT_L24(a)			((unsigned long)((a) << 24))

#define CONCAT_2ASCII(a, b)				(((unsigned short)(a) <<  4) | (b))
#define CONCAT_4ASCII(a, b, c, d)		(((unsigned short)(a) << 12) | ((unsigned short)(b) <<  8) | ((unsigned short)(c) << 4) | (d))
#define CONCAT_6ASCII(a, b, c, d, e, f)	(((unsigned short)(a) << 20) | ((unsigned short)(b) << 16) | ((unsigned short)(c) << 12) |\
										 ((unsigned short)(d) <<  8) | ((unsigned short)(e) <<  4) | (f))
#define CONCAT_8ASCII(a, b, c, d, e, f, g, h)	(((unsigned short)(a) << 28) | ((unsigned short)(b) << 24) | ((unsigned short)(c) << 20) |\
												 ((unsigned short)(d) << 16) | ((unsigned short)(e) << 12) | ((unsigned short)(f) << 8) |\
												 ((unsigned short)(g) << 4) | (h))
#define CONCAT_2BIN(a, b)			(((unsigned short)(a) <<  8) | (b))
#define CONCAT_3BIN(a, b, c)		(((unsigned short)(a) << 16) | ((unsigned short)(b) << 8) | (c))
#define CONCAT_4BIN(a, b, c, d)		(((unsigned long) (a) << 24) | ((unsigned long)(b) << 16) | ((unsigned long)(c) << 8) | (d))

#define BIT_GET(a, b)				(((((unsigned char*)a)[(b)/8]) >> ((b)%8)) & 0x01)
#define BIT_SET(a, b, c)			((((c) & 0x01) == 0x01) ? ((((unsigned char*)a)[(b)/8]) |= (0x01 << ((b)%8))) : \
									((((unsigned char*)a)[(b)/8]) &= ~(0x01 << ((b)%8))))

/*[ Definition of Public API ]*/
int SLMP_MakePacketStream ( unsigned long ulFrameType, const SLMP_INFO * p, unsigned char * pucStream );
int SLMP_GetSlmpInfo ( SLMP_INFO * p, const unsigned char * pucStream );
int SLMP_MakeErrorData ( const SLMP_INFO * p, unsigned char * pucStream, unsigned int * puiDataSize );
unsigned char local_itoa( unsigned char ucInt );
unsigned char local_atoi( unsigned char ucInt );

#endif
/*EOF*/
/********************************************************************************/
/*	Object Name		�FFunction for SLMP	library									*/
/*	File Name		�FSLMP.c													*/
/*	Data			�F2015/03/02												*/
/*	Version			�F1.00														*/
/*																				*/
/*	COPYRIGHT (C) 2015 CC-Link Partner Association ALL RIGHTS RESERVED			*/
/********************************************************************************/

//#include "SLMP.h"
#include "string.h"
#include "stdlib.h"

static unsigned int uiHeaderLength[]		= {  6,  2,  6,  2, 12,  4, 12,  4};
static unsigned int uiDataAddr[]			= { 15, 11, 19, 15, 30, 22, 38, 30};

/* A Function for making packet stream from the SLMP_Info structure */
int SLMP_MakePacketStream ( unsigned long ulFrameType, const SLMP_INFO * p, unsigned char * pucStream )
{
	int i = 0;
	int iLength = 0;
	int iIndex = 0;

	if ( (p == NULL) || (pucStream == NULL) )
	{
		return SLMP_ERR_NG;
	}

	/*[ Request : Binary Mode, Single Transmission Type ]*/
	if( (unsigned short)ulFrameType == SLMP_FTYPE_BIN_REQ_ST )
	{
		iIndex = SLMP_FTYPE_BIN_REQ_ST_INDEX;
		iLength = (p->usDataLength)-uiHeaderLength[iIndex];
		if ( iLength < 0 )
		{
			return SLMP_ERR_NG;
		}
		else if ( iLength > 0 )
		{
			if ( p->pucData == NULL )
			{
				return SLMP_ERR_NG;
			}
		}

		pucStream[ 0] = SHIFT_R8(SLMP_FTYPE_BIN_REQ_ST);
		pucStream[ 1] = SHIFT_R0(SLMP_FTYPE_BIN_REQ_ST);
		pucStream[ 2] = SHIFT_R0(p->usNetNumber);
		pucStream[ 3] = SHIFT_R0(p->usNodeNumber);
		pucStream[ 4] = SHIFT_R0(p->usProcNumber);
		pucStream[ 5] = SHIFT_R8(p->usProcNumber);
		pucStream[ 6] = 0x00;
		pucStream[ 7] = SHIFT_R0(p->usDataLength);
		pucStream[ 8] = SHIFT_R8(p->usDataLength);
		pucStream[ 9] = SHIFT_R0(p->usTimer);
		pucStream[10] = SHIFT_R8(p->usTimer);
		pucStream[11] = SHIFT_R0(p->usCommand);
		pucStream[12] = SHIFT_R8(p->usCommand);
		pucStream[13] = SHIFT_R0(p->usSubCommand);
		pucStream[14] = SHIFT_R8(p->usSubCommand);
		for( i=0; i<iLength; i++ )
		{
			pucStream[uiDataAddr[iIndex]+i] = p->pucData[i];
		}
		return SLMP_ERR_OK;
	}

	/*[ Response : Binary Mode, Single Transmission Type ]*/
	else if( (unsigned short)ulFrameType == SLMP_FTYPE_BIN_RES_ST )
	{
		iIndex = SLMP_FTYPE_BIN_RES_ST_INDEX;
		iLength = (p->usDataLength)-uiHeaderLength[iIndex]+2;
		if ( iLength < 0 )
		{
			return SLMP_ERR_NG;
		}
		else if ( iLength > 0 )
		{
			if ( p->pucData == NULL )
			{
				return SLMP_ERR_NG;
			}
		}

		pucStream[ 0] = SHIFT_R8(SLMP_FTYPE_BIN_RES_ST);
		pucStream[ 1] = SHIFT_R0(SLMP_FTYPE_BIN_RES_ST);
		pucStream[ 2] = SHIFT_R0(p->usNetNumber);
		pucStream[ 3] = SHIFT_R0(p->usNodeNumber);
		pucStream[ 4] = SHIFT_R0(p->usProcNumber);
		pucStream[ 5] = SHIFT_R8(p->usProcNumber);
		pucStream[ 6] = 0x00;
		pucStream[ 7] = SHIFT_R0(p->usDataLength+2);
		pucStream[ 8] = SHIFT_R8(p->usDataLength+2);
		pucStream[ 9] = SHIFT_R0(p->usEndCode);
		pucStream[10] = SHIFT_R8(p->usEndCode);

		for( i=0; i<iLength+2; i++ )
		{
			pucStream[uiDataAddr[iIndex]+i] = p->pucData[i];
		}
		return SLMP_ERR_OK;
	}

	/*[ Request : Binary Mode, Multiple Transmission Type ]*/
	else if( (unsigned short)ulFrameType == SLMP_FTYPE_BIN_REQ_MT )
	{
		iIndex = SLMP_FTYPE_BIN_REQ_MT_INDEX;
		iLength = (p->usDataLength)-uiHeaderLength[iIndex];
		if ( iLength < 0 )
		{
			return SLMP_ERR_NG;
		}
		else if ( iLength > 0 )
		{
			if ( p->pucData == NULL )
			{
				return SLMP_ERR_NG;
			}
		}

		pucStream[ 0] = SHIFT_R8(SLMP_FTYPE_BIN_REQ_MT);
		pucStream[ 1] = SHIFT_R0(SLMP_FTYPE_BIN_REQ_MT);
		pucStream[ 2] = SHIFT_R0(p->usSerialNumber);
		pucStream[ 3] = SHIFT_R8(p->usSerialNumber);
		pucStream[ 4] = 0x00;
		pucStream[ 5] = 0x00;
		pucStream[ 6] = SHIFT_R0(p->usNetNumber);
		pucStream[ 7] = SHIFT_R0(p->usNodeNumber);
		pucStream[ 8] = SHIFT_R0(p->usProcNumber);
		pucStream[ 9] = SHIFT_R8(p->usProcNumber);
		pucStream[10] = 0x00;
		pucStream[11] = SHIFT_R0(p->usDataLength);
		pucStream[12] = SHIFT_R8(p->usDataLength);
		pucStream[13] = SHIFT_R0(p->usTimer);
		pucStream[14] = SHIFT_R8(p->usTimer);
		pucStream[15] = SHIFT_R0(p->usCommand);
		pucStream[16] = SHIFT_R8(p->usCommand);
		pucStream[17] = SHIFT_R0(p->usSubCommand);
		pucStream[18] = SHIFT_R8(p->usSubCommand);

		for( i=0; i<iLength; i++ )
		{
			pucStream[uiDataAddr[iIndex]+i] = p->pucData[i];
		}
		return SLMP_ERR_OK;
	}

	/*[ Response : Binary Mode, Multiple Transmission Type ]*/
	else if( (unsigned short)ulFrameType == SLMP_FTYPE_BIN_RES_MT )
	{
		iIndex = SLMP_FTYPE_BIN_RES_MT_INDEX;
		iLength = (p->usDataLength)-uiHeaderLength[iIndex]+2;
		if ( iLength < 0 )
		{
			return SLMP_ERR_NG;
		}
		else if ( iLength > 0 )
		{
			if ( p->pucData == NULL )
			{
				return SLMP_ERR_NG;
			}
		}

		pucStream[ 0] = SHIFT_R8(SLMP_FTYPE_BIN_RES_MT);
		pucStream[ 1] = SHIFT_R0(SLMP_FTYPE_BIN_RES_MT);
		pucStream[ 2] = SHIFT_R0(p->usSerialNumber);
		pucStream[ 3] = SHIFT_R8(p->usSerialNumber);
		pucStream[ 4] = 0x00;
		pucStream[ 5] = 0x00;
		pucStream[ 6] = SHIFT_R0(p->usNetNumber);
		pucStream[ 7] = SHIFT_R0(p->usNodeNumber);
		pucStream[ 8] = SHIFT_R0(p->usProcNumber);
		pucStream[ 9] = SHIFT_R8(p->usProcNumber);
		pucStream[10] = 0x00;
		pucStream[11] = SHIFT_R0(p->usDataLength+2);
		pucStream[12] = SHIFT_R8(p->usDataLength+2);
		pucStream[13] = SHIFT_R0(p->usEndCode);
		pucStream[14] = SHIFT_R8(p->usEndCode);

		for( i=0; i<iLength+2; i++ )
		{
			pucStream[uiDataAddr[iIndex]+i] = p->pucData[i];
		}
		return SLMP_ERR_OK;
	}

	/*[ Request : ASCII Mode, Single Transmission Type ]*/
	else if( ulFrameType == SLMP_FTYPE_ASCII_REQ_ST )
	{
		iIndex = SLMP_FTYPE_ASCII_REQ_ST_INDEX;
		iLength = (p->usDataLength)-uiHeaderLength[iIndex];
		if ( iLength < 0 )
		{
			return SLMP_ERR_NG;
		}
		else if ( iLength > 0 )
		{
			if ( p->pucData == NULL )
			{
				return SLMP_ERR_NG;
			}
		}

		pucStream[ 0] = SHIFT_R24(SLMP_FTYPE_ASCII_REQ_ST);
		pucStream[ 1] = SHIFT_R16(SLMP_FTYPE_ASCII_REQ_ST);
		pucStream[ 2] = SHIFT_R8 (SLMP_FTYPE_ASCII_REQ_ST);
		pucStream[ 3] = SHIFT_R0 (SLMP_FTYPE_ASCII_REQ_ST);
		pucStream[ 4] = local_itoa(SHIFT_R4(p->usNetNumber) & MASK_LOWER4BIT);
		pucStream[ 5] = local_itoa(SHIFT_R0(p->usNetNumber) & MASK_LOWER4BIT);
		pucStream[ 6] = local_itoa(SHIFT_R4(p->usNodeNumber) & MASK_LOWER4BIT);
		pucStream[ 7] = local_itoa(SHIFT_R0(p->usNodeNumber) & MASK_LOWER4BIT);
		pucStream[ 8] = local_itoa(SHIFT_R12(p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[ 9] = local_itoa(SHIFT_R8 (p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[10] = local_itoa(SHIFT_R4 (p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[11] = local_itoa(SHIFT_R0 (p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[12] = local_itoa(0x00);
		pucStream[13] = local_itoa(0x00);
		pucStream[14] = local_itoa(SHIFT_R12(p->usDataLength) & MASK_LOWER4BIT);
		pucStream[15] = local_itoa(SHIFT_R8 (p->usDataLength) & MASK_LOWER4BIT);
		pucStream[16] = local_itoa(SHIFT_R4 (p->usDataLength) & MASK_LOWER4BIT);
		pucStream[17] = local_itoa(SHIFT_R0 (p->usDataLength) & MASK_LOWER4BIT);
		pucStream[18] = local_itoa(SHIFT_R12(p->usTimer) & MASK_LOWER4BIT);
		pucStream[19] = local_itoa(SHIFT_R8 (p->usTimer) & MASK_LOWER4BIT);
		pucStream[20] = local_itoa(SHIFT_R4 (p->usTimer) & MASK_LOWER4BIT);
		pucStream[21] = local_itoa(SHIFT_R0 (p->usTimer) & MASK_LOWER4BIT);
		pucStream[22] = local_itoa(SHIFT_R12(p->usCommand) & MASK_LOWER4BIT);
		pucStream[23] = local_itoa(SHIFT_R8 (p->usCommand) & MASK_LOWER4BIT);
		pucStream[24] = local_itoa(SHIFT_R4 (p->usCommand) & MASK_LOWER4BIT);
		pucStream[25] = local_itoa(SHIFT_R0 (p->usCommand) & MASK_LOWER4BIT);
		pucStream[26] = local_itoa(SHIFT_R12(p->usSubCommand) & MASK_LOWER4BIT);
		pucStream[27] = local_itoa(SHIFT_R8 (p->usSubCommand) & MASK_LOWER4BIT);
		pucStream[28] = local_itoa(SHIFT_R4 (p->usSubCommand) & MASK_LOWER4BIT);
		pucStream[29] = local_itoa(SHIFT_R0 (p->usSubCommand) & MASK_LOWER4BIT);

		for( i=0; i<iLength; i++ )
		{
			pucStream[uiDataAddr[iIndex]+i] = p->pucData[i];
		}
		return SLMP_ERR_OK;
	}

	/*[ Response : ASCII Mode, Single Transmission Type ]*/
	else if( ulFrameType == SLMP_FTYPE_ASCII_RES_ST )
	{
		iIndex = SLMP_FTYPE_ASCII_RES_ST_INDEX;
		iLength = (p->usDataLength)-uiHeaderLength[iIndex]+4;
		if ( iLength < 0 )
		{
			return SLMP_ERR_NG;
		}
		else if ( iLength > 0 )
		{
			if ( p->pucData == NULL )
			{
				return SLMP_ERR_NG;
			}
		}

		pucStream[ 0] = SHIFT_R24(SLMP_FTYPE_ASCII_RES_ST);
		pucStream[ 1] = SHIFT_R16(SLMP_FTYPE_ASCII_RES_ST);
		pucStream[ 2] = SHIFT_R8 (SLMP_FTYPE_ASCII_RES_ST);
		pucStream[ 3] = SHIFT_R0 (SLMP_FTYPE_ASCII_RES_ST);
		pucStream[ 4] = local_itoa(SHIFT_R4(p->usNetNumber) & MASK_LOWER4BIT);
		pucStream[ 5] = local_itoa(SHIFT_R0(p->usNetNumber) & MASK_LOWER4BIT);
		pucStream[ 6] = local_itoa(SHIFT_R4(p->usNodeNumber) & MASK_LOWER4BIT);
		pucStream[ 7] = local_itoa(SHIFT_R0(p->usNodeNumber) & MASK_LOWER4BIT);
		pucStream[ 8] = local_itoa(SHIFT_R12(p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[ 9] = local_itoa(SHIFT_R8 (p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[10] = local_itoa(SHIFT_R4 (p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[11] = local_itoa(SHIFT_R0 (p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[12] = local_itoa(0x00);
		pucStream[13] = local_itoa(0x00);
		pucStream[14] = local_itoa(SHIFT_R12(p->usDataLength+4) & MASK_LOWER4BIT);
		pucStream[15] = local_itoa(SHIFT_R8 (p->usDataLength+4) & MASK_LOWER4BIT);
		pucStream[16] = local_itoa(SHIFT_R4 (p->usDataLength+4) & MASK_LOWER4BIT);
		pucStream[17] = local_itoa(SHIFT_R0 (p->usDataLength+4) & MASK_LOWER4BIT);
		pucStream[18] = local_itoa(SHIFT_R12(p->usEndCode) & MASK_LOWER4BIT);
		pucStream[19] = local_itoa(SHIFT_R8 (p->usEndCode) & MASK_LOWER4BIT);
		pucStream[20] = local_itoa(SHIFT_R4 (p->usEndCode) & MASK_LOWER4BIT);
		pucStream[21] = local_itoa(SHIFT_R0 (p->usEndCode) & MASK_LOWER4BIT);

		for( i=0; i<iLength+4; i++ )
		{
			pucStream[uiDataAddr[iIndex]+i] = p->pucData[i];
		}
		return SLMP_ERR_OK;
	}

	/*[ Request : ASCII Mode, Multiple Transmission Type ]*/
	else if( ulFrameType == SLMP_FTYPE_ASCII_REQ_MT )
	{
		iIndex = SLMP_FTYPE_ASCII_REQ_MT_INDEX;
		iLength = (p->usDataLength)-uiHeaderLength[iIndex];
		if ( iLength < 0 )
		{
			return SLMP_ERR_NG;
		}
		else if ( iLength > 0 )
		{
			if ( p->pucData == NULL )
			{
				return SLMP_ERR_NG;
			}
		}

		pucStream[ 0] = SHIFT_R24(SLMP_FTYPE_ASCII_REQ_MT);
		pucStream[ 1] = SHIFT_R16(SLMP_FTYPE_ASCII_REQ_MT);
		pucStream[ 2] = SHIFT_R8 (SLMP_FTYPE_ASCII_REQ_MT);
		pucStream[ 3] = SHIFT_R0 (SLMP_FTYPE_ASCII_REQ_MT);
		pucStream[ 4] = local_itoa(SHIFT_R12(p->usSerialNumber) & MASK_LOWER4BIT);
		pucStream[ 5] = local_itoa(SHIFT_R8 (p->usSerialNumber) & MASK_LOWER4BIT);
		pucStream[ 6] = local_itoa(SHIFT_R4 (p->usSerialNumber) & MASK_LOWER4BIT);
		pucStream[ 7] = local_itoa(SHIFT_R0 (p->usSerialNumber) & MASK_LOWER4BIT);
		pucStream[ 8] = local_itoa(0x00);
		pucStream[ 9] = local_itoa(0x00);
		pucStream[10] = local_itoa(0x00);
		pucStream[11] = local_itoa(0x00);
		pucStream[12] = local_itoa(SHIFT_R4(p->usNetNumber) & MASK_LOWER4BIT);
		pucStream[13] = local_itoa(SHIFT_R0(p->usNetNumber) & MASK_LOWER4BIT);
		pucStream[14] = local_itoa(SHIFT_R4(p->usNodeNumber) & MASK_LOWER4BIT);
		pucStream[15] = local_itoa(SHIFT_R0(p->usNodeNumber) & MASK_LOWER4BIT);
		pucStream[16] = local_itoa(SHIFT_R12(p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[17] = local_itoa(SHIFT_R8 (p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[18] = local_itoa(SHIFT_R4 (p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[19] = local_itoa(SHIFT_R0 (p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[20] = local_itoa(0x00);
		pucStream[21] = local_itoa(0x00);
		pucStream[22] = local_itoa(SHIFT_R12(p->usDataLength) & MASK_LOWER4BIT);
		pucStream[23] = local_itoa(SHIFT_R8 (p->usDataLength) & MASK_LOWER4BIT);
		pucStream[24] = local_itoa(SHIFT_R4 (p->usDataLength) & MASK_LOWER4BIT);
		pucStream[25] = local_itoa(SHIFT_R0 (p->usDataLength) & MASK_LOWER4BIT);
		pucStream[26] = local_itoa(SHIFT_R12(p->usTimer) & MASK_LOWER4BIT);
		pucStream[27] = local_itoa(SHIFT_R8 (p->usTimer) & MASK_LOWER4BIT);
		pucStream[28] = local_itoa(SHIFT_R4 (p->usTimer) & MASK_LOWER4BIT);
		pucStream[29] = local_itoa(SHIFT_R0 (p->usTimer) & MASK_LOWER4BIT);
		pucStream[30] = local_itoa(SHIFT_R12(p->usCommand) & MASK_LOWER4BIT);
		pucStream[31] = local_itoa(SHIFT_R8 (p->usCommand) & MASK_LOWER4BIT);
		pucStream[32] = local_itoa(SHIFT_R4 (p->usCommand) & MASK_LOWER4BIT);
		pucStream[33] = local_itoa(SHIFT_R0 (p->usCommand) & MASK_LOWER4BIT);
		pucStream[34] = local_itoa(SHIFT_R12(p->usSubCommand) & MASK_LOWER4BIT);
		pucStream[35] = local_itoa(SHIFT_R8 (p->usSubCommand) & MASK_LOWER4BIT);
		pucStream[36] = local_itoa(SHIFT_R4 (p->usSubCommand) & MASK_LOWER4BIT);
		pucStream[37] = local_itoa(SHIFT_R0 (p->usSubCommand) & MASK_LOWER4BIT);

		for( i=0; i<iLength; i++ )
		{
			pucStream[uiDataAddr[iIndex]+i] = p->pucData[i];
		}
		return SLMP_ERR_OK;
	}

	/*[ Response : ASCII Mode, Multiple Transmission Type ]*/
	else if( ulFrameType == SLMP_FTYPE_ASCII_RES_MT )
	{
		iIndex = SLMP_FTYPE_ASCII_RES_MT_INDEX;
		iLength = (p->usDataLength)-uiHeaderLength[iIndex]+4;
		if ( iLength < 0 )
		{
			return SLMP_ERR_NG;
		}
		else if ( iLength > 0 )
		{
			if ( p->pucData == NULL )
			{
				return SLMP_ERR_NG;
			}
		}

		pucStream[ 0] = SHIFT_R24(SLMP_FTYPE_ASCII_RES_MT);
		pucStream[ 1] = SHIFT_R16(SLMP_FTYPE_ASCII_RES_MT);
		pucStream[ 2] = SHIFT_R8 (SLMP_FTYPE_ASCII_RES_MT);
		pucStream[ 3] = SHIFT_R0 (SLMP_FTYPE_ASCII_RES_MT);
		pucStream[ 4] = local_itoa(SHIFT_R12(p->usSerialNumber) & MASK_LOWER4BIT);
		pucStream[ 5] = local_itoa(SHIFT_R8 (p->usSerialNumber) & MASK_LOWER4BIT);
		pucStream[ 6] = local_itoa(SHIFT_R4 (p->usSerialNumber) & MASK_LOWER4BIT);
		pucStream[ 7] = local_itoa(SHIFT_R0 (p->usSerialNumber) & MASK_LOWER4BIT);
		pucStream[ 8] = local_itoa(0x00);
		pucStream[ 9] = local_itoa(0x00);
		pucStream[10] = local_itoa(0x00);
		pucStream[11] = local_itoa(0x00);
		pucStream[12] = local_itoa(SHIFT_R4(p->usNetNumber) & MASK_LOWER4BIT);
		pucStream[13] = local_itoa(SHIFT_R0(p->usNetNumber) & MASK_LOWER4BIT);
		pucStream[14] = local_itoa(SHIFT_R4(p->usNodeNumber) & MASK_LOWER4BIT);
		pucStream[15] = local_itoa(SHIFT_R0(p->usNodeNumber) & MASK_LOWER4BIT);
		pucStream[16] = local_itoa(SHIFT_R12(p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[17] = local_itoa(SHIFT_R8 (p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[18] = local_itoa(SHIFT_R4 (p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[19] = local_itoa(SHIFT_R0 (p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[20] = local_itoa(0x00);
		pucStream[21] = local_itoa(0x00);
		pucStream[22] = local_itoa(SHIFT_R12(p->usDataLength+4) & MASK_LOWER4BIT);
		pucStream[23] = local_itoa(SHIFT_R8 (p->usDataLength+4) & MASK_LOWER4BIT);
		pucStream[24] = local_itoa(SHIFT_R4 (p->usDataLength+4) & MASK_LOWER4BIT);
		pucStream[25] = local_itoa(SHIFT_R0 (p->usDataLength+4) & MASK_LOWER4BIT);
		pucStream[26] = local_itoa(SHIFT_R12(p->usEndCode) & MASK_LOWER4BIT);
		pucStream[27] = local_itoa(SHIFT_R8 (p->usEndCode) & MASK_LOWER4BIT);
		pucStream[28] = local_itoa(SHIFT_R4 (p->usEndCode) & MASK_LOWER4BIT);
		pucStream[29] = local_itoa(SHIFT_R0 (p->usEndCode) & MASK_LOWER4BIT);

		for( i=0; i<iLength+4; i++ )
		{
			pucStream[uiDataAddr[iIndex]+i] = p->pucData[i];
		}
		return SLMP_ERR_OK;
	}

	return SLMP_ERR_NG;
}

/* A Function for getting SLMP_Info from packet stream */
int SLMP_GetSlmpInfo ( SLMP_INFO * p, const unsigned char * pucStream )
{
	int i = 0;
	int iIndex = 0;
	int iLength = 0;
	unsigned int uiTempLength = 0;
	unsigned int uiTemp0 = 0, uiTemp1 = 0, uiTemp2 = 0, uiTemp3 = 0;
	unsigned short	usFrameType = 0;
	unsigned long	ulFrameType = 0;

	if ( (p == NULL) || (pucStream == NULL) )
	{
		return SLMP_ERR_NG;
	}

	usFrameType = CONCAT_2BIN(pucStream[0], pucStream[1]);

	(p->ulFrameType) = usFrameType;

	/*[ Request : Binary Mode, Single Transmission Type ]*/
	if( usFrameType == SLMP_FTYPE_BIN_REQ_ST )
	{
		iIndex = SLMP_FTYPE_BIN_REQ_ST_INDEX;
		uiTempLength = CONCAT_2BIN(pucStream[ 8], pucStream[ 7]);

		iLength = uiTempLength - uiHeaderLength[iIndex];
		if ( iLength < 0 )
		{
			return SLMP_ERR_NG;
		}
		else if ( iLength > 0 )
		{
			if ( p->pucData == NULL )
			{
				return SLMP_ERR_NG;
			}
		}

		(p->usNetNumber)	= pucStream[2];
		(p->usNodeNumber)	= pucStream[3];
		(p->usProcNumber)	= CONCAT_2BIN(pucStream[ 5], pucStream[ 4]);
		(p->usDataLength)	= uiTempLength;
		(p->usTimer)		= CONCAT_2BIN(pucStream[10], pucStream[ 9]);
		(p->usCommand)		= CONCAT_2BIN(pucStream[12], pucStream[11]);
		(p->usSubCommand)	= CONCAT_2BIN(pucStream[14], pucStream[13]);

		for( i=0; i<iLength; i++ )
		{
			p->pucData[i] = pucStream[uiDataAddr[iIndex]+i];
		}

		return SLMP_ERR_OK;
	}

	/*[ Response : Binary Mode, Single Transmission Type ]*/
	else if( usFrameType == SLMP_FTYPE_BIN_RES_ST )
	{
		iIndex = SLMP_FTYPE_BIN_RES_ST_INDEX;
		uiTempLength = CONCAT_2BIN(pucStream[ 8], pucStream[ 7]);

		iLength = uiTempLength - uiHeaderLength[iIndex];
		if ( iLength < 0 )
		{
			return SLMP_ERR_NG;
		}
		else if ( iLength > 0 )
		{
			if ( p->pucData == NULL )
			{
				return SLMP_ERR_NG;
			}
		}

		(p->usNetNumber)	= pucStream[2];
		(p->usNodeNumber)	= pucStream[3];
		(p->usProcNumber)	= CONCAT_2BIN(pucStream[ 5], pucStream[ 4]);
		(p->usDataLength)	= uiTempLength;
		(p->usEndCode)		= CONCAT_2BIN(pucStream[10], pucStream[ 9]);

		for( i=0; i<iLength; i++ )
		{
			p->pucData[i] = pucStream[uiDataAddr[iIndex]+i];
		}

		return SLMP_ERR_OK;
	}

	/*[ Request : Binary Mode, Multiple Transmission Type ]*/
	else if( usFrameType == SLMP_FTYPE_BIN_REQ_MT )
	{
		iIndex = SLMP_FTYPE_BIN_REQ_MT_INDEX;
		uiTempLength = CONCAT_2BIN(pucStream[12], pucStream[11]);

		iLength = uiTempLength - uiHeaderLength[iIndex];
		if ( iLength < 0 )
		{
			return SLMP_ERR_NG;
		}
		else if ( iLength > 0 )
		{
			if ( p->pucData == NULL )
			{
				return SLMP_ERR_NG;
			}
		}

		(p->usSerialNumber)	= CONCAT_2BIN(pucStream[3], pucStream[2]);
		(p->usNetNumber)	= pucStream[6];
		(p->usNodeNumber)	= pucStream[7];
		(p->usProcNumber)	= CONCAT_2BIN(pucStream[ 9], pucStream[ 8]);
		(p->usDataLength)	= uiTempLength;
		(p->usTimer)		= CONCAT_2BIN(pucStream[14], pucStream[13]);
		(p->usCommand)		= CONCAT_2BIN(pucStream[16], pucStream[15]);
		(p->usSubCommand)	= CONCAT_2BIN(pucStream[18], pucStream[17]);

		for( i=0; i<iLength; i++ )
		{
			p->pucData[i] = pucStream[uiDataAddr[iIndex]+i];
		}

		return SLMP_ERR_OK;
	}

	/*[ Response : Binary Mode, Multiple Transmission Type ]*/
	else if( usFrameType == SLMP_FTYPE_BIN_RES_MT )
	{
		iIndex = SLMP_FTYPE_BIN_RES_MT_INDEX;
		uiTempLength = CONCAT_2BIN(pucStream[12], pucStream[11]);

		iLength = uiTempLength - uiHeaderLength[iIndex];
		if ( iLength < 0 )
		{
			return SLMP_ERR_NG;
		}
		else if ( iLength > 0 )
		{
			if ( p->pucData == NULL )
			{
				return SLMP_ERR_NG;
			}
		}

		(p->usSerialNumber)	= CONCAT_2BIN(pucStream[3], pucStream[2]);
		(p->usNetNumber)	= pucStream[6];
		(p->usNodeNumber)	= pucStream[7];
		(p->usProcNumber)	= CONCAT_2BIN(pucStream[ 9], pucStream[ 8]);
		(p->usDataLength)	= uiTempLength;
		(p->usEndCode)		= CONCAT_2BIN(pucStream[14], pucStream[13]);

		for( i=0; i<iLength; i++ )
		{
			p->pucData[i] = pucStream[uiDataAddr[iIndex]+i];
		}

		return SLMP_ERR_OK;
	}

	ulFrameType = CONCAT_4BIN(pucStream[0], pucStream[1], pucStream[2], pucStream[3]);

	(p->ulFrameType) = ulFrameType;

	/*[ Request : ASCII Mode, Single Transmission Type ]*/
	if( ulFrameType == SLMP_FTYPE_ASCII_REQ_ST )
	{
		iIndex = SLMP_FTYPE_ASCII_REQ_ST_INDEX;
		uiTemp0 = local_atoi(pucStream[14]);
		uiTemp1 = local_atoi(pucStream[15]);
		uiTemp2 = local_atoi(pucStream[16]);
		uiTemp3 = local_atoi(pucStream[17]);
		uiTempLength = CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);

		iLength = uiTempLength - uiHeaderLength[iIndex];
		if ( iLength < 0 )
		{
			return SLMP_ERR_NG;
		}
		else if ( iLength > 0 )
		{
			if ( p->pucData == NULL )
			{
				return SLMP_ERR_NG;
			}
		}

		uiTemp0 = local_atoi(pucStream[ 4]);
		uiTemp1 = local_atoi(pucStream[ 5]);
		(p->usNetNumber)	= CONCAT_2ASCII(uiTemp0, uiTemp1);

		uiTemp0 = local_atoi(pucStream[ 6]);
		uiTemp1 = local_atoi(pucStream[ 7]);
		(p->usNodeNumber)	= CONCAT_2ASCII(uiTemp0, uiTemp1);

		uiTemp0 = local_atoi(pucStream[ 8]);
		uiTemp1 = local_atoi(pucStream[ 9]);
		uiTemp2 = local_atoi(pucStream[10]);
		uiTemp3 = local_atoi(pucStream[11]);
		(p->usProcNumber)	= CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);

		(p->usDataLength)	= uiTempLength;

		uiTemp0 = local_atoi(pucStream[18]);
		uiTemp1 = local_atoi(pucStream[19]);
		uiTemp2 = local_atoi(pucStream[20]);
		uiTemp3 = local_atoi(pucStream[21]);
		(p->usTimer)		= CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);

		uiTemp0 = local_atoi(pucStream[22]);
		uiTemp1 = local_atoi(pucStream[23]);
		uiTemp2 = local_atoi(pucStream[24]);
		uiTemp3 = local_atoi(pucStream[25]);
		(p->usCommand)		= CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);

		uiTemp0 = local_atoi(pucStream[26]);
		uiTemp1 = local_atoi(pucStream[27]);
		uiTemp2 = local_atoi(pucStream[28]);
		uiTemp3 = local_atoi(pucStream[29]);
		(p->usSubCommand)	= CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);

		for( i=0; i<iLength; i++ )
		{
			p->pucData[i] = pucStream[uiDataAddr[iIndex]+i];
		}

		return SLMP_ERR_OK;
	}

	/*[ Response : ASCII Mode, Single Transmission Type ]*/
	else if( ulFrameType == SLMP_FTYPE_ASCII_RES_ST )
	{
		iIndex = SLMP_FTYPE_ASCII_RES_ST_INDEX;
		uiTemp0 = local_atoi(pucStream[14]);
		uiTemp1 = local_atoi(pucStream[15]);
		uiTemp2 = local_atoi(pucStream[16]);
		uiTemp3 = local_atoi(pucStream[17]);
		uiTempLength = CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);

		iLength = uiTempLength - uiHeaderLength[iIndex];
		if ( iLength < 0 )
		{
			return SLMP_ERR_NG;
		}
		else if ( iLength > 0 )
		{
			if ( p->pucData == NULL )
			{
				return SLMP_ERR_NG;
			}
		}

		uiTemp0 = local_atoi(pucStream[ 4]);
		uiTemp1 = local_atoi(pucStream[ 5]);
		(p->usNetNumber)	= CONCAT_2ASCII(uiTemp0, uiTemp1);

		uiTemp0 = local_atoi(pucStream[ 6]);
		uiTemp1 = local_atoi(pucStream[ 7]);
		(p->usNodeNumber)	= CONCAT_2ASCII(uiTemp0, uiTemp1);

		uiTemp0 = local_atoi(pucStream[ 8]);
		uiTemp1 = local_atoi(pucStream[ 9]);
		uiTemp2 = local_atoi(pucStream[10]);
		uiTemp3 = local_atoi(pucStream[11]);
		(p->usProcNumber)	= CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);

		(p->usDataLength)	= uiTempLength;

		uiTemp0 = local_atoi(pucStream[18]);
		uiTemp1 = local_atoi(pucStream[19]);
		uiTemp2 = local_atoi(pucStream[20]);
		uiTemp3 = local_atoi(pucStream[21]);
		(p->usEndCode)		= CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);

		for( i=0; i<iLength; i++ )
		{
			p->pucData[i] = pucStream[uiDataAddr[iIndex]+i];
		}

		return SLMP_ERR_OK;
	}

	/*[ Request : ASCII Mode, Multiple Transmission Type ]*/
	else if( ulFrameType == SLMP_FTYPE_ASCII_REQ_MT )
	{
		iIndex = SLMP_FTYPE_ASCII_REQ_MT_INDEX;
		uiTemp0 = local_atoi(pucStream[22]);
		uiTemp1 = local_atoi(pucStream[23]);
		uiTemp2 = local_atoi(pucStream[24]);
		uiTemp3 = local_atoi(pucStream[25]);
		uiTempLength = CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);

		iLength = uiTempLength - uiHeaderLength[iIndex];
		if ( iLength < 0 )
		{
			return SLMP_ERR_NG;
		}
		else if ( iLength > 0 )
		{
			if ( p->pucData == NULL )
			{
				return SLMP_ERR_NG;
			}
		}

		uiTemp0 = local_atoi(pucStream[ 4]);
		uiTemp1 = local_atoi(pucStream[ 5]);
		uiTemp2 = local_atoi(pucStream[ 6]);
		uiTemp3 = local_atoi(pucStream[ 7]);
		(p->usSerialNumber)	= CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);

		uiTemp0 = local_atoi(pucStream[12]);
		uiTemp1 = local_atoi(pucStream[13]);
		(p->usNetNumber)	= CONCAT_2ASCII(uiTemp0, uiTemp1);

		uiTemp0 = local_atoi(pucStream[14]);
		uiTemp1 = local_atoi(pucStream[15]);
		(p->usNodeNumber)	= CONCAT_2ASCII(uiTemp0, uiTemp1);

		uiTemp0 = local_atoi(pucStream[16]);
		uiTemp1 = local_atoi(pucStream[17]);
		uiTemp2 = local_atoi(pucStream[18]);
		uiTemp3 = local_atoi(pucStream[19]);
		(p->usProcNumber)	= CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);

		(p->usDataLength)	= uiTempLength;

		uiTemp0 = local_atoi(pucStream[26]);
		uiTemp1 = local_atoi(pucStream[27]);
		uiTemp2 = local_atoi(pucStream[28]);
		uiTemp3 = local_atoi(pucStream[29]);
		(p->usTimer)		= CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);

		uiTemp0 = local_atoi(pucStream[30]);
		uiTemp1 = local_atoi(pucStream[31]);
		uiTemp2 = local_atoi(pucStream[32]);
		uiTemp3 = local_atoi(pucStream[33]);
		(p->usCommand)		= CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);

		uiTemp0 = local_atoi(pucStream[34]);
		uiTemp1 = local_atoi(pucStream[35]);
		uiTemp2 = local_atoi(pucStream[36]);
		uiTemp3 = local_atoi(pucStream[37]);
		(p->usSubCommand)	= CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);

		for( i=0; i<iLength; i++ )
		{
			p->pucData[i] = pucStream[uiDataAddr[iIndex]+i];
		}

		return SLMP_ERR_OK;
	}

	/*[ Response : ASCII Mode, Multiple Transmission Type ]*/
	else if( ulFrameType == SLMP_FTYPE_ASCII_RES_MT )
	{
		iIndex = SLMP_FTYPE_ASCII_RES_MT_INDEX;
		uiTemp0 = local_atoi(pucStream[22]);
		uiTemp1 = local_atoi(pucStream[23]);
		uiTemp2 = local_atoi(pucStream[24]);
		uiTemp3 = local_atoi(pucStream[25]);
		uiTempLength = CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);
		
		iLength = uiTempLength - uiHeaderLength[iIndex];
		if ( iLength < 0 )
		{
			return SLMP_ERR_NG;
		}
		else if ( iLength > 0 )
		{
			if ( p->pucData == NULL )
			{
				return SLMP_ERR_NG;
			}
		}

		uiTemp0 = local_atoi(pucStream[ 4]);
		uiTemp1 = local_atoi(pucStream[ 5]);
		uiTemp2 = local_atoi(pucStream[ 6]);
		uiTemp3 = local_atoi(pucStream[ 7]);
		(p->usSerialNumber)	= CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);

		uiTemp0 = local_atoi(pucStream[12]);
		uiTemp1 = local_atoi(pucStream[13]);
		(p->usNetNumber)	= CONCAT_2ASCII(uiTemp0, uiTemp1);

		uiTemp0 = local_atoi(pucStream[14]);
		uiTemp1 = local_atoi(pucStream[15]);
		(p->usNodeNumber)	= CONCAT_2ASCII(uiTemp0, uiTemp1);

		uiTemp0 = local_atoi(pucStream[16]);
		uiTemp1 = local_atoi(pucStream[17]);
		uiTemp2 = local_atoi(pucStream[18]);
		uiTemp3 = local_atoi(pucStream[19]);
		(p->usProcNumber)	= CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);

		(p->usDataLength)	= uiTempLength;

		uiTemp0 = local_atoi(pucStream[26]);
		uiTemp1 = local_atoi(pucStream[27]);
		uiTemp2 = local_atoi(pucStream[28]);
		uiTemp3 = local_atoi(pucStream[29]);
		(p->usEndCode)		= CONCAT_4ASCII(uiTemp0, uiTemp1, uiTemp2, uiTemp3);

		for( i=0; i<iLength; i++ )
		{
			p->pucData[i] = pucStream[uiDataAddr[iIndex]+i];
		}

		return SLMP_ERR_OK;
	}
	return SLMP_ERR_NG;
}

/*[ translating from integer to ascii ]*/
unsigned char local_itoa( unsigned char ucInt){
	unsigned char ucTable[] = {	'0','1','2','3','4','5','6','7','8','9',
						'A','B','C','D','E','F'};
	return ucTable[ucInt];
}

/*[ translating from ascii to integer ]*/
unsigned char local_atoi( unsigned char ucInt){
	switch(ucInt)
	{
		case 'A' :
			return 0x0A;
		case 'B' :
			return 0x0B;
		case 'C' :
			return 0x0C;
		case 'D' :
			return 0x0D;
		case 'E' :
			return 0x0E;
		case 'F' :
			return 0x0F;
		default :
			return (ucInt-'0');
	}
}

/* A Function for making error response data from the SLMP_Info structure */
int SLMP_MakeErrorData ( const SLMP_INFO * p, unsigned char * pucStream, unsigned int * puiDataSize )
{
	if ( (p == NULL) || (pucStream == NULL) )
	{
		return SLMP_ERR_NG;
	}

	/*[ Binary Mode ]*/
	if ( SLMP_DATA_CODE(p->ulFrameType) == SLMP_DATA_CODE_BIN )
	{
		pucStream[ 0] = SHIFT_R0(p->usNetNumber);
		pucStream[ 1] = SHIFT_R0(p->usNodeNumber);
		pucStream[ 2] = SHIFT_R0(p->usProcNumber);
		pucStream[ 3] = SHIFT_R8(p->usProcNumber);
		pucStream[ 4] = 0x00;
		pucStream[ 5] = SHIFT_R0(p->usCommand);
		pucStream[ 6] = SHIFT_R8(p->usCommand);
		pucStream[ 7] = SHIFT_R0(p->usSubCommand);
		pucStream[ 8] = SHIFT_R8(p->usSubCommand);
		(*puiDataSize) = 0x0009;
	}

	/*[ ASCII Mode ]*/
	else if ( SLMP_DATA_CODE(p->ulFrameType) == SLMP_DATA_CODE_ASCII )
	{
		pucStream[ 0] = local_itoa(SHIFT_R4(p->usNetNumber) & MASK_LOWER4BIT);
		pucStream[ 1] = local_itoa(SHIFT_R0(p->usNetNumber) & MASK_LOWER4BIT);
		pucStream[ 2] = local_itoa(SHIFT_R4(p->usNodeNumber) & MASK_LOWER4BIT);
		pucStream[ 3] = local_itoa(SHIFT_R0(p->usNodeNumber) & MASK_LOWER4BIT);
		pucStream[ 4] = local_itoa(SHIFT_R12(p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[ 5] = local_itoa(SHIFT_R8 (p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[ 6] = local_itoa(SHIFT_R4 (p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[ 7] = local_itoa(SHIFT_R0 (p->usProcNumber) & MASK_LOWER4BIT);
		pucStream[ 8] = local_itoa(0x00);
		pucStream[ 9] = local_itoa(0x00);
		pucStream[10] = local_itoa(SHIFT_R12(p->usCommand) & MASK_LOWER4BIT);
		pucStream[11] = local_itoa(SHIFT_R8 (p->usCommand) & MASK_LOWER4BIT);
		pucStream[12] = local_itoa(SHIFT_R4 (p->usCommand) & MASK_LOWER4BIT);
		pucStream[13] = local_itoa(SHIFT_R0 (p->usCommand) & MASK_LOWER4BIT);
		pucStream[14] = local_itoa(SHIFT_R12(p->usSubCommand) & MASK_LOWER4BIT);
		pucStream[15] = local_itoa(SHIFT_R8 (p->usSubCommand) & MASK_LOWER4BIT);
		pucStream[16] = local_itoa(SHIFT_R4 (p->usSubCommand) & MASK_LOWER4BIT);
		pucStream[17] = local_itoa(SHIFT_R0 (p->usSubCommand) & MASK_LOWER4BIT);
		(*puiDataSize) = 0x0012;
	}

	/*[ Data Code Error ]*/
	else
	{
		return SLMP_ERR_NG;
	}

	return SLMP_ERR_OK;
}
