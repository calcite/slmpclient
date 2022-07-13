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