/*
*********************************************************************************************************
*                              uC/OS-II Application Configuration
*
*                       DO NOT DELETE THIS FILE, IT IS REQUIRED FOR OS_VER > 2.80
*
*                                   CHANGE SETTINGS ACCORDINGLY
*
*
* File : app_cfg.h
* By   : Eric Shufro
*********************************************************************************************************
*/

#ifndef  APP_CFG_H
#define  APP_CFG_H


/*
*********************************************************************************************************
*                                       INCLUDES
*********************************************************************************************************
*/

#include <lib_def.h>
#include <lib_modbus.h>

/*
*********************************************************************************************************
*                                       ADDITIONAL uC/MODULE ENABLES
*********************************************************************************************************
*/

#define  LIB_STR_CFG_FP_EN                DEF_DISABLED
//#define  uC_PROBE_OS_PLUGIN               DEF_ENABLED
//#define  uC_PROBE_COM_MODULE              DEF_ENABLED


/*
*********************************************************************************************************
*                                       TASK PRIORITIES
*********************************************************************************************************
*/

#define  APP_TASK_START_PRIO                    		0                       /* Lower numbers are of higher priority                     */
#define  MUTEX_GR64_PIP					  		1
#define  MUTEX_RS485_PIP				  		2		
#define  MUTEX_EEPROM_PIP							3
#define  MUTEX_DEVICE_INIT_PARAMETERS_PIP 		4

//#define  APP_TASK_LCD_PRIO                      6
#define  APP_TASK_RS485_PRIO                     8                       /* RS485 �������� */
#define  APP_TASK_GR64_PRIO                       9				/* GR64 �������� */
#define  APP_TASK_SMSSend_PRIO			 10				/* SMS �������� */
#define  APP_TASK_SMSReceive_PRIO		 7				/* SMS �������� */




#define  OS_TASK_TMR_PRIO                      10


/*
*********************************************************************************************************
*                                       TASK STACK SIZES
*
* Notes :   1) Warming, setting a stack size too small may result in the OS crashing. It the OS crashes
*              within a deep nested function call, the stack size may be to blame. The current maximum
*              stack usage for each task may be checked by using uC/OS-View or the stack checking
*              features of uC/OS-II.
*********************************************************************************************************
*/

#define  APP_TASK_START_STK_SIZE              128
//#define  APP_TASK_LCD_STK_SIZE                256
//#define  OS_PROBE_TASK_STK_SIZE               160                       /* See probe_com_cfg for RS-232 commication task stack size */
#define  APP_TASK_GR64_STK_SIZE		128
#define APP_TASK_RS485_STK_SIZE		128
#define APP_TASK_SMSSend_STK_SIZE		256
#define APP_TASK_SMSReceive_STK_SIZE	256



/*
*********************************************************************************************************
*                                                CONSTANTS
*********************************************************************************************************
*/
#define 	Q_SMS_ALARM_ARRAY_SIZE			20//���Ÿ澯�ʼ����д�С;
#define 	MEM_PART_NUMBER					30//�ڴ��������;
#define 	MEM_PART_SIZE						16//�ڴ������С;


#define 	SLAVE_DEVICE_MAX_NUMBERS		10//���豸����;
#define 	DEVICE_NAME_MAX_LENGTH			32//�豸���Ƴ���;
#define 	ALARM_TELEPHONE_MAX_NUMBERS	10 //�澯�ֻ��������;
#define 	ALARM_TELEPHONE_NUMBER_SIZE 	11//�ֻ����볤��(SEMI_OCTET��ʽ);
#define   DEVICE_PASSWORD_MAX_LENGTH		12

/* PDU���� */
#define	INTERNATIONAL_ADDRESS_TYPE		0x91
#define	LOCAL_ADDRESS_TYPE				0xA1


#define  	SMSC_DEFAULT 						0x00
#define 	FIRST_OCTET_DEFAULT				0x11
#define	TP_MR_DEFAULT						0x00
#define	TP_TYPE_DEFAULT					INTERNATIONAL_ADDRESS_TYPE//���ʵ�ַ;
#define	TP_PID_DEFAULT					0x00//��ͨGSM Э��,��Ե㷽ʽ;
#define	TP_DCS_DEFAULT					0X08//UCS2���뷽ʽ;
#define	TP_VP_DEFAULT						0XC2//5������Ч����;

/*
*********************************************************************************************************
*                                          					DATA TYPES
*********************************************************************************************************
*/


typedef struct {

	unsigned char	primary_device_name[DEVICE_NAME_MAX_LENGTH];//���豸����;
	unsigned char	slave_device_numbers;//���豸����,�ұ���С��SLAVE_DEVICE_MAX_NUMBERS;
	unsigned char slave_device_id[SLAVE_DEVICE_MAX_NUMBERS];//���豸ID����,��СΪSLAVE_DEVICE_MAX_NUMBERS;
	unsigned char slave_device_name[SLAVE_DEVICE_MAX_NUMBERS][DEVICE_NAME_MAX_LENGTH];
	SMS_ALARM_FRAME slave_device_history_alarm[SLAVE_DEVICE_MAX_NUMBERS];
	unsigned char alarm_telephone_numbers;
	unsigned char alarm_telephone[ALARM_TELEPHONE_MAX_NUMBERS][ALARM_TELEPHONE_NUMBER_SIZE];
	unsigned char service_center_address[ALARM_TELEPHONE_NUMBER_SIZE];
	unsigned char password[DEVICE_PASSWORD_MAX_LENGTH];
	
}DEVICE_INIT_PARAMATERS;



/*
*********************************************************************************************************
*                               uC/Probe plug-in for uC/OS-II CONFIGURATION
*********************************************************************************************************
*/

//#define  OS_PROBE_TASK                          1                       /* Task will be created for uC/Probe OS Plug-In             */
//#define  OS_PROBE_TMR_32_BITS                   0                       /* Timer is 16 bits                                         */
//#define  OS_PROBE_TIMER_SEL                     3                       /* Use TPM3 or TPM5                                         */
//#define  OS_PROBE_HOOKS_EN                      1                       /* Enable uC/Probe application hooks                        */
//#define  OS_PROBE_USE_FP                        1                       /* Override uC/Probe floating point support, use integers   */


#endif                                                                  /* End of file                                              */



