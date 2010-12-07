/*
*********************************************************************************************************
*                                               uC/OS-II
*                                         The Real-Time Kernel
*
*                               (c) Copyright 2006, Micrium, Weston, FL
*                                          All Rights Reserved
*
*
*                                      Microchip Application Code
*
* File : APP.C
* By   : Eric Shufo
*********************************************************************************************************
*/

#include <includes.h>

/*
*********************************************************************************************************
*                                                VARIABLES
*********************************************************************************************************
*/

/* ����ջ������ */
OS_STK  AppStartTaskStk[APP_TASK_START_STK_SIZE];
OS_STK  AppGR64TaskStk[APP_TASK_GR64_STK_SIZE];
OS_STK  AppRS485TaskStk[APP_TASK_RS485_STK_SIZE];
OS_STK  AppSMSSendTaskStk[APP_TASK_SMSSend_STK_SIZE];
OS_STK  AppSMSReceiveTaskStk[APP_TASK_SMSReceive_STK_SIZE];
/* �豸���в��� */
OS_EVENT *MUTEX_DEVICE_INIT_PARAMATERS;
DEVICE_INIT_PARAMATERS device_init_paramaters;
MODBUS_RECEIVE_FRAME slave_device_state_frame[SLAVE_DEVICE_MAX_NUMBERS];
TIME_FRAME set_time;
const DEVICE_INIT_PARAMATERS device_init_paramaters_const = {

	"������һ�ſ�����",
	1,
	{0x01, },
	{"���ǵϳ��ߵ���",},
	{{0,},},
	1,
	{"13474656377",},
	"",
	"123456"
};
/* �豸ʹ�÷����ź��� */
OS_EVENT *MUTEX_GR64;//�豸ʹ�û����ź���;
OS_EVENT *MUTEX_RS485;//�豸ʹ�û����ź���;
OS_EVENT *MUTEX_EEPROM;

/* ���ڷ����ж����ָʾ */
OS_EVENT *SEM_RS485_SEND_BYTE;//����һ���ֽ�������ź���;
OS_EVENT *SEM_GR64_SEND_BYTE;//����һ���ֽ�������ź���;

/* �����ڴ���� */
OS_EVENT *SEM_MEM_PART_ALLOC;//�ڴ�����ź���;
OS_MEM	  *MEM_BUF;//�ڴ滺����;
unsigned char MEM_PART[MEM_PART_NUMBER][MEM_PART_SIZE];//�ڴ滺����MEM_PART_NUMBER ������,����������СΪMEM_PART_SIZE Bytes;

/* SMS���͸澯�����ʼ����� */
OS_EVENT *Q_SMS_ALARM;
void *Q_SMS_ALARM_ARRAY[Q_SMS_ALARM_ARRAY_SIZE];//��Ϣ���������СΪ10;

/* SMS ��Ϣָʾ�ź��� */
OS_EVENT *SEM_SMS_MSG_INDICATOR;

/* ���ܻ����� */
BUFFER GR64_buf;//GR64
BUFFER RS485_buf;//RS485

/* ֡�����ڴ���*/
unsigned char GR64_SEND_BUF[256];
unsigned char GR64_RECEIVE_BUF[256];

unsigned char SMS_RECEIVE_PROCESS_BUF[256];
unsigned char SMS_SEND_PROCESS_BUF[512];
unsigned char SMS_UCS_PROCESS_BUF[DEVICE_NAME_MAX_LENGTH];

unsigned char RS485_SEND_BUF[32];
unsigned char RS485_RECEIVE_BUF[32];




OS_EVENT *SEM_SMS_OK;
OS_EVENT *SEM_SMS_FAULT;

/* ����洢��ʹ���ź��� */


/* ����GR64 ��ATָ�� */
char *AT = "AT\r";
char *ATE0 = "ATE0\r";
char *ATIPR = "AT+IPR=9600\r";
char *ATCSQ       = "AT+CSQ\r";
char *ATCMGF      = "AT+CMGF=0\r";
//char *ATCNMI     = "AT+CNMI=3,1\r";
char *ATCMGL     = "AT+CMGL=4\r";
char *ATCNMI    = "AT+CNMI=1,1,0,2,1\r";
char *ATCSCA     = "AT+CSCA?\r";
char *ATCCLK     = "AT+CCLK?\r";
char *ATOK     = "OK\r\n";
char *ATCPMS      = "AT+CPMS=\"ME\",\"ME\",\"ME\"\r";
char *ATSMSRI    = "AT*E2SMSRI=50\r";
char *ATE2IPA   = "AT*E2IPA=1,1\r";
char *ATE2IPA0     = "AT*E2IPA=0,1\r";
char *ATCT        = "CONNECT\r\n";
char *ATO         = "ATO\r";
char *ATE2IPC    = "AT*E2IPC\r";
char *ATASKCGDCONT  = "AT+CGDCONT?\r";
char *ATE2IPS  = "AT*E2IPS=2,8,2,1020,1\r";
char *ATGETIP  = "AT*E2IPI=0\r";
char *ATCIMI  = "AT+CIMI\r";

unsigned char *ZXSOFT = "\x00\x7a\x00\x78\x00\x73\x00\x6f\x00\x66\x00\x74";//ZXSOFT֡ͷƥ��;
unsigned char *SET = "\x8b\xbe\x7f\x6e";//��������ƥ�����;

unsigned char *SET_PRIMARY_DEVICE_NAME = "\x00\x30\x00\x31\x00\x30";//010;�������豸����;
unsigned char *SET_SLAVE_DEVICE_NUMBERS = "\x00\x30\x00\x32\x00\x30";//020;���ô��豸��;
unsigned char *SET_SLAVE_DEVICE_ID = "\x00\x30\x00\x32\x00\x31";//021;//���ô��豸ͨѶID;
unsigned char *SET_SLAVE_DEVICE_NAME = "\x00\x30\x00\x32\x00\x32";//022;//���ô��豸����;
unsigned char *SET_ALARM_TELEPHONE_NUMBERS = "\x00\x30\x00\x33\x00\x30";//030;���ø澯�绰����;
unsigned char *SET_ALARM_TELEPHONE = "\x00\x30\x00\x33\x00\x31";//031;���ø澯�绰����;

unsigned char *LIST = "\x67\xe5\x8b\xe2";//��ѯ����;


/*
*********************************************************************************************************
*                                            FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  AppStartTask(void *p_arg);
//static  void  AppLCDTask(void *p_arg);
static  void  AppTaskCreate(void);
static void AppGR64Task(void *p_arg);
static void AppRS485Task(void *p_arg);
static void AppSMSSendTask(void *p_arg);
static void AppSMSReceiveTask(void *p_arg);

/*
*********************************************************************************************************
*                                                main()
*
* Description : This is the standard entry point for C code.
* Arguments   : none
*********************************************************************************************************
*/
static unsigned char byte2BCD(unsigned char bVal)
{
  return  ( (bVal/10)<<4) + (bVal%10);
}
CPU_INT16S  main (void)
{
    CPU_INT08U  err;



    BSP_IntDisAll();                                                    /* Disable all interrupts until we are ready to accept them */

    OSInit();                                                           /* Initialize "uC/OS-II, The Real-Time Kernel"              */

    OSTaskCreateExt(AppStartTask,
                    (void *)0,
                    (OS_STK *)&AppStartTaskStk[0],
                    APP_TASK_START_PRIO,
                    APP_TASK_START_PRIO,
                    (OS_STK *)&AppStartTaskStk[APP_TASK_START_STK_SIZE-1],
                    APP_TASK_START_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CLR);

#if OS_TASK_NAME_SIZE > 11
    OSTaskNameSet(APP_TASK_START_PRIO, (CPU_INT08U *)"Start Task", &err);
#endif

    OSStart();                                                          /* Start multitasking (i.e. give control to uC/OS-II)       */

	return (-1);                                                        /* Return an error - This line of code is unreachable       */
}


/*
*********************************************************************************************************
*                                          STARTUP TASK
*
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Arguments   : p_arg   is the argument passed to 'AppStartTask()' by 'OSTaskCreate()'.
*
* Notes       : 1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                  used.  The compiler should not generate any code for this statement.
*               2) Interrupts are enabled once the task start because the I-bit of the CCR register was
*                  set to 0 by 'OSTaskCreate()'.
*********************************************************************************************************
*/

static  void  AppStartTask (void *p_arg)
{
    CPU_INT08U  i;
    CPU_INT08U  j;
CPU_INT08U err;

SEM_RS485_SEND_BYTE = OSSemCreate(0);
SEM_GR64_SEND_BYTE = OSSemCreate(0);

MUTEX_GR64 = OSMutexCreate(MUTEX_GR64_PIP, &err);
MUTEX_RS485 = OSMutexCreate(MUTEX_RS485_PIP, &err);
MUTEX_EEPROM = OSMutexCreate(MUTEX_EEPROM_PIP, &err);

/* ����MEM_PART_NUMBER ���ڴ�����ҷ�����СΪMEM_PART_SIZE ���������ʹ�� */
SEM_MEM_PART_ALLOC = OSSemCreate(MEM_PART_NUMBER);
MEM_BUF = OSMemCreate(MEM_PART, MEM_PART_NUMBER, MEM_PART_SIZE, &err);

/* �����ʼ��б����б��СΪQ_SMS_ALARM_ARRAY_SIZE ����Ϣ */
Q_SMS_ALARM = OSQCreate(Q_SMS_ALARM_ARRAY, Q_SMS_ALARM_ARRAY_SIZE);

/* ��������Ϣ״̬�ź��� */
SEM_SMS_OK = OSSemCreate(0);
SEM_SMS_FAULT = OSSemCreate(0);

MUTEX_DEVICE_INIT_PARAMATERS = OSMutexCreate(MUTEX_DEVICE_INIT_PARAMETERS_PIP, &err);

SEM_SMS_MSG_INDICATOR = OSSemCreate(0);

   (void)p_arg;

    BSP_Init();                                                         /* Initialize BSP functions                                 */

	while(GR64_VIO == 1)
	{
		GR64ONOFF_LAT = 0;
		OSTimeDly(60);
		GR64ONOFF_LAT = 1;
		OSTimeDly(1000);	
	}
	OSTimeDly(1000);
/* ȫ�ֱ�����ʼ�� */
	OSMutexPend(MUTEX_EEPROM, 0, &err);
	device_init_paramaters = device_init_paramaters_const;
	EEPROM_write(EEPROM_DEVICE_INIT_PARAMATERS_START, (unsigned char *)&device_init_paramaters, sizeof(DEVICE_INIT_PARAMATERS));
	EEPROM_read(EEPROM_DEVICE_INIT_PARAMATERS_START, (unsigned char *)&device_init_paramaters, sizeof(DEVICE_INIT_PARAMATERS));
	OSMutexPost(MUTEX_EEPROM);
/*
	Iron_Read(IRON_PRIMARY_DEVICE_NAME, \
				device_init_paramaters.primary_device_name, \
				DEVICE_PASSWORD_MAX_LENGTH);

	Iron_Read(IRON_PASSWORD, \
				device_init_paramaters.password, \
				DEVICE_PASSWORD_MAX_LENGTH);
	
	Iron_Read(IRON_SLAVE_DEVICE_NUMBERS, \
				(unsigned char *)&(device_init_paramaters.slave_device_numbers), \
				1);
	for(i = 0; i < SLAVE_DEVICE_MAX_NUMBERS; i++)
	{
		Iron_Read(IRON_SLAVE_DEVICE_ID + i, \
					(unsigned char *)&(device_init_paramaters.slave_device_id[i]), \
					1);

	}
	for(i = 0; i < SLAVE_DEVICE_MAX_NUMBERS; i++)
	{
		Iron_Read(IRON_SLAVE_DEVICE_NAME + i * DEVICE_NAME_MAX_LENGTH, \
					device_init_paramaters.slave_device_name[i], \
					DEVICE_NAME_MAX_LENGTH);

	}
	for(i = 0; i < SLAVE_DEVICE_MAX_NUMBERS; i++)
	{
		Iron_Read(IRON_SLAVE_DEVICE_HISTORY_ALARM + i * sizeof(SMS_ALARM_FRAME), \
					(unsigned char *)&(device_init_paramaters.slave_device_history_alarm[i]), \
					sizeof(SMS_ALARM_FRAME));

	}
		Iron_Read(IRON_ALARM_TELEPHONE_NUMBERS, \
				(unsigned char *)&(device_init_paramaters.alarm_telephone_numbers), \
				1);
	for(i = 0; i < ALARM_TELEPHONE_MAX_NUMBERS; i++)
	{
		Iron_Read(IRON_ALARM_TELEPHONE + i * ALARM_TELEPHONE_NUMBER_SIZE, \
					device_init_paramaters.alarm_telephone[i], \
					ALARM_TELEPHONE_NUMBER_SIZE);
	}


	Iron_Read(IRON_SERVICE_CENTER_ADDRESS, \
				device_init_paramaters.service_center_address, \
				ALARM_TELEPHONE_NUMBER_SIZE);
	*/	


	
    AppTaskCreate();                                                    /* Create additional user tasks                             */

    LED_Off(0);                                                         /* Turn OFF all the LEDs                                    */

    while (DEF_TRUE) {                                                  /* Task body, always written as an infinite loop.           */
        for (i = 0; i < 4; i++) {                                       /* Sweep right then left 4 times                            */
    		for (j = 1; j <= 8; j++) {			                        /* Scroll the LEDs to the right	                            */
    			LED_On(j);
    			OSTimeDlyHMSM(0, 0, 0, 25);                             /* Delay 25ms                                               */
    			LED_Off(j);
    		} 	

    		for (j = 7; j >= 2; j--) {                                  /* Scroll the LEDs to the left 	                            */
    			LED_On(j);
    			OSTimeDlyHMSM(0, 0, 0, 25);
				
    			LED_Off(j);
    		}
        }

		for (i = 0; i < 4; i++) {                                       /* Blink all 8 LEDs 4 times                                 */
			LED_On(0);
			OSTimeDlyHMSM(0, 0, 0, 25);
			
			LED_Off(0);
			OSTimeDlyHMSM(0, 0, 0, 25);			
		}
    }
}
/*****************************************************

				���񴴽�����

******************************************************/
static  void  AppTaskCreate(void)
{
	    OSTaskCreateExt(AppRS485Task,
                    (void *)0,
                    (OS_STK *)&AppRS485TaskStk[0],
                    APP_TASK_RS485_PRIO,
                    APP_TASK_RS485_PRIO,
                    (OS_STK *)&AppRS485TaskStk[APP_TASK_RS485_STK_SIZE-1],
                    APP_TASK_RS485_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CLR);
    OSTaskCreateExt(AppGR64Task,
                    (void *)0,
                    (OS_STK *)&AppGR64TaskStk[0],
                    APP_TASK_GR64_PRIO,
                    APP_TASK_GR64_PRIO,
                    (OS_STK *)&AppGR64TaskStk[APP_TASK_GR64_STK_SIZE-1],
                    APP_TASK_GR64_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CLR);

    OSTaskCreateExt(AppSMSSendTask,
                    (void *)0,
                    (OS_STK *)&AppSMSSendTaskStk[0],
                    APP_TASK_SMSSend_PRIO,
                    APP_TASK_SMSSend_PRIO,
                    (OS_STK *)&AppSMSSendTaskStk[APP_TASK_SMSSend_STK_SIZE-1],
                    APP_TASK_SMSSend_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CLR);

    OSTaskCreateExt(AppSMSReceiveTask,
                    (void *)0,
                    (OS_STK *)&AppSMSReceiveTaskStk[0],
                    APP_TASK_SMSReceive_PRIO,
                    APP_TASK_SMSReceive_PRIO,
                    (OS_STK *)&AppSMSReceiveTaskStk[APP_TASK_SMSReceive_STK_SIZE -1],
                    APP_TASK_SMSReceive_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CLR);
}


/*****************************************************

				RS485 ��������

******************************************************/
static void AppRS485Task(void *p_arg)
{
	CPU_INT08U err;
	CPU_INT08U slave_device_cnt;
	
//	unsigned char *frame_process;
	
	(void)p_arg;
	//MODBUS_RECEIVE_FRAME *frame_receive = (MODBUS_RECEIVE_FRAME *)msg_485;
	MODBUS_RECEIVE_FRAME *frame_receive = NULL;
	SMS_ALARM_FRAME *sms_alarm_mail = NULL;
	SMS_MAIL_FRAME *sms_mail = NULL;
	DEVICE_INIT_PARAMATERS *device_parameters = &device_init_paramaters;
	MODBUS_RECEIVE_FRAME *slave_device_state = slave_device_state_frame;
	while(1)
	{
		if(device_parameters->slave_device_numbers <= SLAVE_DEVICE_MAX_NUMBERS)
		for(slave_device_cnt = 0;slave_device_cnt < device_parameters->slave_device_numbers; slave_device_cnt++)
		{
			OSMutexPend(MUTEX_RS485, 0, &err);
			ENABLE_RS485_SEND();
			Flush_RS485_Buffer();
			Send_To_RS485(Create_Send_Frame(RS485_SEND_BUF, device_parameters->slave_device_id[slave_device_cnt], MODBUS_DATA_QUERY, 0x0100, 0x000f), sizeof(MODBUS_DATA_QUERY_FRAME));
			ENABLE_RS485_RECEIVE();
			OSTimeDly(100);//���ռ��Ϊ1 S;
			CLOSE_RS485();
			frame_receive = (MODBUS_RECEIVE_FRAME *)Receive_From_RS485(RS485_RECEIVE_BUF, RECEIVE_ALL);
			OSMutexPost(MUTEX_RS485);

			/* �жϽ���֡�Ƿ���� */
			if(frame_receive != NULL)
			{
					/* ʹ��CRC ��֤����֡�������� */
				if(updcrc(0, (unsigned char *)frame_receive, sizeof(MODBUS_RECEIVE_FRAME)) == FRAME_CORRECT)
				{
					/*�����յ�������*/
					/* ��֤����֡�ǲ�������Ҫ���豸������ ֡*/
					if(frame_receive->device_id == device_parameters->slave_device_id[slave_device_cnt])
					{
						/* ������ֵ���ͨ��״̬�仯�͵������޵�����״̬�仯ʱ
						 * �����澯�ʼ�������Ϊ��ʷ״̬. 
						 *
						 */
						slave_device_state[slave_device_cnt] = *frame_receive;
						//if(frame_receive->cable_fault_type != device_parameters->slave_device_history_alarm[slave_device_cnt].cable_fault_type \
						//	||frame_receive->current_on_off != device_parameters->slave_device_history_alarm[slave_device_cnt].current_on_off)
						if(frame_receive->cable_fault_type != device_parameters->slave_device_history_alarm[slave_device_cnt].cable_fault_type)
						{

							/* ����һ��16 �ֽڵ��ڴ���� ���ڸ澯�ʼ��Ĵ洢*/
							OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
							//sms_alarm_mail = (SMS_ALARM_FRAME *)OSMemGet(MEM_BUF, &err);
							sms_mail = (SMS_MAIL_FRAME *)OSMemGet(MEM_BUF, &err);
							sms_mail->sms_mail_type = SMS_ALARM_FRAME_TYPE;
							sms_alarm_mail = &(sms_mail->sms_alarm_frame);
							/* ������Ÿ澯�ʼ� */
							sms_alarm_mail->device_index= slave_device_cnt;//�豸����;
							sms_alarm_mail->cable_fault_type = frame_receive->cable_fault_type;
							sms_alarm_mail->temperature = frame_receive->temperature;
							sms_alarm_mail->current_on_off = frame_receive->current_on_off;
							sms_alarm_mail->time = frame_receive->time;
							/* ����Ϊ��ʷ״̬ */
							device_parameters->slave_device_history_alarm[slave_device_cnt] = *sms_alarm_mail;

							OSMutexPend(MUTEX_EEPROM, 0, &err);
							/*
							Iron_Write(IRON_SLAVE_DEVICE_HISTORY_ALARM + slave_device_cnt * sizeof(SMS_ALARM_FRAME), \
										(unsigned char *)&(device_paramaters->slave_device_history_alarm[slave_device_cnt]), \
										sizeof(SMS_ALARM_FRAME));
							*/
							EEPROM_write(EEPROM_DEVICE_INIT_PARAMATERS_START + \
											OFF_SET_OF(DEVICE_INIT_PARAMATERS, slave_device_history_alarm) + \
											slave_device_cnt * sizeof(SMS_ALARM_FRAME), (unsigned char *)&(device_parameters->slave_device_history_alarm[slave_device_cnt]), sizeof(SMS_ALARM_FRAME));
							OSMutexPost(MUTEX_EEPROM);
							/* ���Ͷ��Ÿ澯�ʼ� */
							OSQPostFront(Q_SMS_ALARM, (void *)sms_mail);
						}
					}
					else
					{
						/* ���� �����豸����������֡����*/
						
					}
					
				}
				else
				{
					/* ֡CRCУ�������*/
					//continue;
				}

			}
			else
			{
				/* û���յ�֡ʱ���� */
			}
			
			OSTimeDly(50);//��ʱ500ms;
		}

		OSTimeDly(50);//��ʱ500ms;
	}
}

/*****************************************************

				SMS ���� ��������

******************************************************/
/*
CPU_INT08U *sms_send(SMS_SEND_PDU_FRAME *sms_send_pdu_frame, CPU_INT16U sms_data_length)
{
	CPU_INT08U *match = NULL;
	Str_FmtPrint(GR64_SEND_BUF, \
				"AT+CMGS=%d\x0D", \
				sms_send_pdu_frame->TPDU.TP_UDL + \
				(sizeof(sms_send_pdu_frame->TPDU) - sizeof(sms_send_pdu_frame->TPDU.TP_UD)));
	Send_To_GR64(GR64_SEND_BUF, SEND_ALL);
	OSTimeDly(50);
	Receive_From_GR64(GR64_RECEIVE_BUF, RECEIVE_ALL);
	match = Str_Char(GR64_RECEIVE_BUF, '>');
	if(!match)
	{
		return match;
	}
	Mem_Set((void *)match, 2, 5);
	Send_PDU_To_GR64(sms_send_pdu_frame);
	OSTimeDly(50);
	Receive_From_GR64(GR64_RECEIVE_BUF, RECEIVE_ALL);
	match = Str_Str(GR64_RECEIVE_BUF, "ERROR");

	return match;
}
*/


CPU_INT08U *sms_send(SMS_SEND_PDU_FRAME *sms_send_pdu_frame, CPU_INT16U sms_data_length)
{
	CPU_INT08U *match = NULL;
	//CPU_INT16U sms_length = sms_send_pdu_frame->TPDU.TP_UDL;
	SMS_HEAD_6 sms_head = {0x05, 0x00, 0x03, 0x86, 0x00, 0x00};
	CPU_INT16U temp;
	CPU_INT08U sms_index;
	sms_head.sms_numbers = sms_data_length / 140;

	if(sms_head.sms_numbers)
	{
		if(sms_data_length % 140)
		{
			sms_head.sms_numbers++;
			
		}
		else
		{
			if(sms_head.sms_numbers == 1)
				goto PROCESS;
		}
		temp = sms_data_length + sms_head.sms_numbers * sizeof(SMS_HEAD_6);

		sms_head.sms_numbers = temp / 140;

		if(temp % 140)
		{
			sms_head.sms_numbers++;
			
		}

			
			
	}
	
PROCESS:	


	if(sms_head.sms_numbers <= 1)
	{
		//��������;
		sms_send_pdu_frame->TPDU.TP_UDL = sms_data_length;
		Str_FmtPrint(GR64_SEND_BUF, \
						"AT+CMGS=%d\x0D", \
						sms_send_pdu_frame->TPDU.TP_UDL + \
						(sizeof(sms_send_pdu_frame->TPDU) - sizeof(sms_send_pdu_frame->TPDU.TP_UD)));
		Send_To_GR64(GR64_SEND_BUF, SEND_ALL);
		OSTimeDly(50);
		Receive_From_GR64(GR64_RECEIVE_BUF, RECEIVE_ALL);
		match = Str_Char(GR64_RECEIVE_BUF, '>');
		if(!match)
		{
			return match;
		}
		Mem_Set((void *)match, 2, 5);
		Send_PDU_To_GR64(sms_send_pdu_frame, &sms_head);
		OSTimeDly(50);
		Receive_From_GR64(GR64_RECEIVE_BUF, RECEIVE_ALL);
		match = Str_Str(GR64_RECEIVE_BUF, "ERROR");
	}
	else
	{
		//��������;
		for (sms_index = 1; sms_index <= sms_head.sms_numbers; sms_index++)
		{

			//�������֡ͷ;
			sms_head.sms_index = sms_index;
			if(sms_index == sms_head.sms_numbers)
			{
				sms_send_pdu_frame->TPDU.TP_UDL = (sms_data_length + sms_head.sms_numbers * sizeof(SMS_HEAD_6)) % 140;

			}
			else
			{
				sms_send_pdu_frame->TPDU.TP_UDL = 140;
			}
			
			Str_FmtPrint(GR64_SEND_BUF, \
				"AT+CMGS=%d\x0D", \
				sms_send_pdu_frame->TPDU.TP_UDL + \
				(sizeof(sms_send_pdu_frame->TPDU) - sizeof(sms_send_pdu_frame->TPDU.TP_UD)));
			Send_To_GR64(GR64_SEND_BUF, SEND_ALL);
			OSTimeDly(50);
			Receive_From_GR64(GR64_RECEIVE_BUF, RECEIVE_ALL);
			match = Str_Char(GR64_RECEIVE_BUF, '>');
			if(!match)
			{
			return match;
			}
			Mem_Set((void *)match, 2, 5);
			Send_PDU_To_GR64(sms_send_pdu_frame, &sms_head);
			OSTimeDly(50);
			Receive_From_GR64(GR64_RECEIVE_BUF, RECEIVE_ALL);
			match = Str_Str(GR64_RECEIVE_BUF, "ERROR");
		}
	}

	
	return match;
}


void sms_alarm_mail_analysis(SMS_SEND_PDU_FRAME *sms_send_pdu_frame, SMS_ALARM_FRAME *sms_alarm_mail, DEVICE_INIT_PARAMATERS *device_parameters)
{
	CPU_INT08U *match = NULL;
	CPU_INT08U alarm_telephone_cnt;
	CPU_INT08U err;
	CPU_INT16U sms_data_length;

	sms_send_pdu_frame->SMSC.SMSC_Length = SMSC_DEFAULT;
	if(sms_send_pdu_frame->SMSC.SMSC_Length)
	{
		sms_send_pdu_frame->SMSC.SMSC_Type_Of_Address = TP_TYPE_DEFAULT;
		TP_Str_To_Octet(sms_send_pdu_frame->SMSC.SMSC_Address_Value, \
						device_parameters->service_center_address, \
						TP_TYPE_DEFAULT, \
						ALARM_TELEPHONE_NUMBER_SIZE);
	}

	sms_send_pdu_frame->TPDU.First_Octet = FIRST_OCTET_DEFAULT;
	sms_send_pdu_frame->TPDU.TP_MR = TP_MR_DEFAULT;
	sms_send_pdu_frame->TPDU.TP_DA.TP_DA_Length = (TP_TYPE_DEFAULT == INTERNATIONAL_ADDRESS_TYPE) ? 0X0D : 0X0B;
	sms_send_pdu_frame->TPDU.TP_DA.TP_DA_Type_Of_Address = TP_TYPE_DEFAULT;
	sms_send_pdu_frame->TPDU.TP_PID = TP_PID_DEFAULT;
	sms_send_pdu_frame->TPDU.TP_DCS = TP_DCS_DEFAULT;
	sms_send_pdu_frame->TPDU.TP_VP = TP_VP_DEFAULT;
	sms_send_pdu_frame->TPDU.TP_UDL = 0;
	sms_data_length = 0;
	*((unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length) = POUND_SIGN;//���#��;
	sms_data_length ++;//#�ų���;

	SMS_Send_User_Data_Copy((unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length, \
								device_parameters->primary_device_name, \
								&(sms_data_length), \
								DEVICE_NAME_MAX_LENGTH);
	*((unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length) = LINE_SIGN;//���-��;
	sms_data_length ++;//-�ų���;

	SMS_Send_User_Data_Copy((unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length, \
								device_parameters->slave_device_name[sms_alarm_mail->device_index], \
								&(sms_data_length), \
								DEVICE_NAME_MAX_LENGTH);

	*((unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length) = POUND_SIGN;//���#��;
	sms_data_length ++;//#�ų���;	

	Alarm_Mail_Data_To_UCS((unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length, \
								sms_alarm_mail, \
								&(sms_data_length));

	sms_data_length <<= 1;//�ֽ���;			

	for(alarm_telephone_cnt = 0; \
		alarm_telephone_cnt < device_parameters->alarm_telephone_numbers; \
		alarm_telephone_cnt++)
	{


		
		TP_Str_To_Octet(sms_send_pdu_frame->TPDU.TP_DA.TP_DA_Address_Value, \
						device_parameters->alarm_telephone[alarm_telephone_cnt], \
						TP_TYPE_DEFAULT, \
						ALARM_TELEPHONE_NUMBER_SIZE);
		
		OSMutexPend(MUTEX_GR64, 0, &err);
		match = sms_send(sms_send_pdu_frame, sms_data_length);
		
		if(match)
		{
			Mem_Set((void *)match, 0, 5);
			OSMutexPost(MUTEX_GR64);
			continue;
		}
		OSMutexPost(MUTEX_GR64);
		OSTimeDly(1000);

	}
}

void sms_query_mail_analysis(SMS_SEND_PDU_FRAME *sms_send_pdu_frame, SMS_QUERY_FRAME *sms_query_mail, DEVICE_INIT_PARAMATERS *device_parameters)
{
	CPU_INT08U *match = NULL;
//	CPU_INT08U alarm_telephone_cnt;
	CPU_INT08U err;
	CPU_INT16U *UCS = NULL;
	CPU_INT16U *UCS_len = NULL;
	CPU_INT08U temp,index;
	MODBUS_RECEIVE_FRAME *slave_device_state = NULL;
	CPU_INT16U sms_data_length;
	sms_send_pdu_frame->SMSC.SMSC_Length = SMSC_DEFAULT;
	if(sms_send_pdu_frame->SMSC.SMSC_Length)
	{
		sms_send_pdu_frame->SMSC.SMSC_Type_Of_Address = TP_TYPE_DEFAULT;
		TP_Str_To_Octet(sms_send_pdu_frame->SMSC.SMSC_Address_Value, \
						device_parameters->service_center_address, \
						TP_TYPE_DEFAULT, \
						ALARM_TELEPHONE_NUMBER_SIZE);
	}

	sms_send_pdu_frame->TPDU.First_Octet = FIRST_OCTET_DEFAULT;
	sms_send_pdu_frame->TPDU.TP_MR = TP_MR_DEFAULT;
	sms_send_pdu_frame->TPDU.TP_DA.TP_DA_Length = (TP_TYPE_DEFAULT == INTERNATIONAL_ADDRESS_TYPE) ? 0X0D : 0X0B;
	sms_send_pdu_frame->TPDU.TP_DA.TP_DA_Type_Of_Address = TP_TYPE_DEFAULT;
	sms_send_pdu_frame->TPDU.TP_PID = TP_PID_DEFAULT;
	sms_send_pdu_frame->TPDU.TP_DCS = TP_DCS_DEFAULT;
	sms_send_pdu_frame->TPDU.TP_VP = TP_VP_DEFAULT;
	sms_send_pdu_frame->TPDU.TP_UDL = 0;
	sms_data_length = 0;
	*((unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length) = POUND_SIGN;//���#��;
	sms_data_length ++;//#�ų���;
	switch(sms_query_mail->function_code)
	{
		case 0x10 : {
			UCS = (unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length;
			UCS_len = &(sms_data_length);
			UCS = SMS_Send_User_Data_Copy(UCS, \
										device_parameters->primary_device_name, \
										UCS_len, \
										DEVICE_NAME_MAX_LENGTH);

			*UCS++ = POUND_SIGN;
			(*UCS_len)++;

			break;
		}
		case 0x20 : {
			
			UCS = (unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length;
			UCS_len = &(sms_data_length);
			temp = device_parameters->slave_device_numbers;
			if(temp <= SLAVE_DEVICE_MAX_NUMBERS)
			{
				if(temp < 10)
				{
					*UCS++ = NUM_UCS_MAP[temp];
					(*UCS_len)++;				
					
				}else if(temp < 100)
				{

					*UCS++ = NUM_UCS_MAP[temp / 10];
					*UCS++ = NUM_UCS_MAP[temp % 10];
					*UCS_len += 2;
				}
				*UCS++ = POUND_SIGN;
				(*UCS_len)++;
				
			}
			break;
		}
		case 0x21 : {
			UCS = (unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length;
			UCS_len = &(sms_data_length);
			if(device_parameters->slave_device_numbers <= SLAVE_DEVICE_MAX_NUMBERS)			
			{
				for(index = 0; index < device_parameters->slave_device_numbers; index++)
				{
					temp = index + 1;
					if(temp < 10)
					{
						*UCS++ = NUM_UCS_MAP[temp];
						(*UCS_len)++;				
						
					}else if(temp < 100)
					{

						*UCS++ = NUM_UCS_MAP[temp / 10];
						*UCS++ = NUM_UCS_MAP[temp % 10];
						*UCS_len += 2;
					}
					*UCS++ = COMMA_SIGN;
					(*UCS_len)++;
					*UCS++ = NUM_UCS_MAP[device_parameters->slave_device_id[index] >> 4];
					*UCS++ = NUM_UCS_MAP[device_parameters->slave_device_id[index] & 0X0F];
					*UCS_len += 2;
					*UCS++ = POUND_SIGN;
					(*UCS_len)++;
				}
			
			}
			break;
		}
		case 0x22 : {
			UCS = (unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length;
			UCS_len = &(sms_data_length);
			if(device_parameters->slave_device_numbers <= SLAVE_DEVICE_MAX_NUMBERS)			
			{
				for(index = 0; index < device_parameters->slave_device_numbers; index++)
				{
					temp = index + 1;
					if(temp < 10)
					{
						*UCS++ = NUM_UCS_MAP[temp];
						(*UCS_len)++;				
						
					}else if(temp < 100)
					{

						*UCS++ = NUM_UCS_MAP[temp / 10];
						*UCS++ = NUM_UCS_MAP[temp % 10];
						*UCS_len += 2;
					}
					*UCS++ = COMMA_SIGN;
					(*UCS_len)++;
					UCS = SMS_Send_User_Data_Copy(UCS, \
												device_parameters->slave_device_name[index], \
												UCS_len, \
												DEVICE_NAME_MAX_LENGTH);
					*UCS++ = POUND_SIGN;
					(*UCS_len)++;
				}
			
			}
			break;
		}
		case 0x30 : {
			
			UCS = (unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length;
			UCS_len = &(sms_data_length);
			temp = device_parameters->alarm_telephone_numbers;
			if(temp <= ALARM_TELEPHONE_MAX_NUMBERS)
			{
				if(temp < 10)
				{
					*UCS++ = NUM_UCS_MAP[temp];
					(*UCS_len)++;				
					
				}else if(temp < 100)
				{

					*UCS++ = NUM_UCS_MAP[temp / 10];
					*UCS++ = NUM_UCS_MAP[temp % 10];
					*UCS_len += 2;
				}
						
				*UCS++ = POUND_SIGN;
				(*UCS_len)++;			

			}
			break;
		}
		case 0x31 : {
			UCS = (unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length;
			UCS_len = &(sms_data_length);
			if(device_parameters->alarm_telephone_numbers <= ALARM_TELEPHONE_MAX_NUMBERS)			
			{
				for(index = 0; index < device_parameters->alarm_telephone_numbers; index++)
				{
					temp = index + 1;
					if(temp < 10)
					{
						*UCS++ = NUM_UCS_MAP[temp];
						(*UCS_len)++;				
						
					}else if(temp < 100)
					{

						*UCS++ = NUM_UCS_MAP[temp / 10];
						*UCS++ = NUM_UCS_MAP[temp % 10];
						*UCS_len += 2;
					}

					
					*UCS++ = COMMA_SIGN;
					(*UCS_len)++;
					
					for(temp = 0; temp < ALARM_TELEPHONE_NUMBER_SIZE; temp++)
					{
						*UCS++ = NUM_UCS_MAP[device_parameters->alarm_telephone[index][temp] - 0x30];
					}
					*UCS_len += ALARM_TELEPHONE_NUMBER_SIZE;

					*UCS++ = POUND_SIGN;
					(*UCS_len)++;
				}
			
			}
			break;
		}
		case 0x40 : {
			UCS = (unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length;
			UCS_len = &(sms_data_length);
			temp = sms_query_mail->cable_index;
			index = temp -1;
			if(temp <= SLAVE_DEVICE_MAX_NUMBERS)			
			{
				slave_device_state = &slave_device_state_frame[index];
				if(temp < 10)
				{
					*UCS++ = NUM_UCS_MAP[temp];
					(*UCS_len)++;				
					
				}else if(temp < 100)
				{

					*UCS++ = NUM_UCS_MAP[temp / 10];
					*UCS++ = NUM_UCS_MAP[temp % 10];
					*UCS_len += 2;
				}

			
				*UCS++ = POUND_SIGN;
				(*UCS_len)++;
				UCS = SMS_Send_User_Data_Copy(UCS, \
											device_parameters->slave_device_name[index], \
											UCS_len, \
											DEVICE_NAME_MAX_LENGTH);
				*UCS++ = POUND_SIGN;
				(*UCS_len)++;
							/* ����ͨ��״̬����{��ͨ,�Ͽ�} */
				if(slave_device_state->cable_fault_type == CABLE_DISCONNECT_FAULT)
				{
					/* �Ͽ� */
					*UCS++ = UCS2_DUAN;
					*UCS++ = UCS2_KAI;
				}
				else
				{
					/* ��ͨ */
					*UCS++ = UCS2_LIAN;
					*UCS++ = UCS2_TONG;
				}
				*UCS++ = POUND_SIGN;
				*UCS_len += 3;

							/* �����¶Ƚ��� XXX��/XX��*/
				switch(slave_device_state->temperature & 0xf800)
				{
					case 0x0000 : {
						slave_device_state->temperature &=  0x07FF;
						slave_device_state->temperature >>= 4;
						if(slave_device_state->temperature <= 9)
						{
							*UCS++ = NUM_UCS_MAP[slave_device_state->temperature];
							*UCS++ = UCS2_DU;
							*UCS++ = POUND_SIGN;
							*UCS_len += 3;				

						}
						else if(slave_device_state->temperature <= 99)
						{
							*UCS++ = NUM_UCS_MAP[slave_device_state->temperature / 10];
							*UCS++ = NUM_UCS_MAP[slave_device_state->temperature % 10];
							*UCS++ = UCS2_DU;
							*UCS++ = POUND_SIGN;
							*UCS_len += 4;				

						}else if(slave_device_state->temperature <= 999)
						{
							
							*UCS++ = NUM_UCS_MAP[slave_device_state->temperature / 100];//��λ;
							slave_device_state->temperature %= 100;
							*UCS++ = NUM_UCS_MAP[slave_device_state->temperature / 10];
							*UCS++ = NUM_UCS_MAP[slave_device_state->temperature % 10];
							*UCS++ = UCS2_DU;
							*UCS++ = POUND_SIGN;
							*UCS_len += 5;
						}
						
						break;
					}

					case 0xf800 : {

						slave_device_state->temperature &=  0x07FF;
						slave_device_state->temperature >>= 4;
						if(slave_device_state->temperature <= 9)
						{
							*UCS++ = LINE_SIGN;
							*UCS++ = NUM_UCS_MAP[slave_device_state->temperature];
							*UCS++ = UCS2_DU;
							*UCS++ = POUND_SIGN;
							*UCS_len += 4;				

						}
						else if(slave_device_state->temperature <= 99)
						{
							*UCS++ = LINE_SIGN;
							*UCS++ = NUM_UCS_MAP[slave_device_state->temperature / 10];
							*UCS++ = NUM_UCS_MAP[slave_device_state->temperature % 10];
							*UCS++ = UCS2_DU;
							*UCS++ = POUND_SIGN;
							*UCS_len += 5;				

						}else if(slave_device_state->temperature <= 999)
						{
							*UCS++ = LINE_SIGN;
							*UCS++ = NUM_UCS_MAP[slave_device_state->temperature / 100];//��λ;
							slave_device_state->temperature %= 100;
							*UCS++ = NUM_UCS_MAP[slave_device_state->temperature / 10];
							*UCS++ = NUM_UCS_MAP[slave_device_state->temperature % 10];
							*UCS++ = UCS2_DU;
							*UCS++ = POUND_SIGN;
							*UCS_len += 6;
						}
							break;
					}
					case 0xA000 : {

						break;
					}
					case 0xB000 : {

						break;
					}
					default : {

						break;
					}
				}

				/* �ʼ�ʱ�������ʽΪ20XX-XX-XX,XX:XX:XX*/
				*UCS++ = 0X3200;// 2;
				*UCS++ = 0X3000;// 0;
				*UCS++ = ((unsigned int )(slave_device_state->time.year & 0xf0) << 4) | 0x3000;//������ĸ���Ϊ���ʮλ;
				*UCS++ = ((unsigned int )(slave_device_state->time.year & 0x0f) << 8) | 0x3000;//������ĸ���Ϊ��ĸ�λ;
				*UCS++ = LINE_SIGN;// -;
				*UCS++ = ((unsigned int )(slave_device_state->time.month & 0xf0) << 4) | 0x3000;//������ĸ���Ϊ�µ�ʮλ;
				*UCS++ = ((unsigned int )(slave_device_state->time.month & 0x0f) << 8) | 0x3000;//������ĸ���Ϊ�µĸ�λ;
				*UCS++ = LINE_SIGN;// -;
				*UCS++ = ((unsigned int )(slave_device_state->time.day & 0xf0) << 4) | 0x3000;//������ĸ���Ϊ�յ�ʮλ;
				*UCS++ = ((unsigned int )(slave_device_state->time.day & 0x0f) << 8) | 0x3000;//������ĸ���Ϊ�յĸ�λ;
				*UCS++ = COMMA_SIGN;// ,;
				*UCS++ = ((unsigned int )(slave_device_state->time.hour & 0xf0) << 4) | 0x3000;//������ĸ���Ϊ�յ�ʮλ;
				*UCS++ = ((unsigned int )(slave_device_state->time.hour & 0x0f) << 8) | 0x3000;//������ĸ���Ϊ�յĸ�λ;
				*UCS++ = COLON_SIGN;// :;
				*UCS++ = ((unsigned int )(slave_device_state->time.minute & 0xf0) << 4) | 0x3000;//������ĸ���Ϊ�յ�ʮλ;
				*UCS++ = ((unsigned int )(slave_device_state->time.minute & 0x0f) << 8) | 0x3000;//������ĸ���Ϊ�յĸ�λ;
				*UCS++ = COLON_SIGN;// :;
				*UCS++ = ((unsigned int )(slave_device_state->time.second & 0xf0) << 4) | 0x3000;//������ĸ���Ϊ�յ�ʮλ;
				*UCS++ = ((unsigned int )(slave_device_state->time.second & 0x0f) << 8) | 0x3000;//������ĸ���Ϊ�յĸ�λ;
				*UCS++ = POUND_SIGN;// #;
				*UCS_len += 20;
			
			}
			break;
		}
		default : 
			break;
	}
	
	sms_data_length <<= 1;//�ֽ���;	
	sms_send_pdu_frame->TPDU.TP_DA = *((TP_DA_TYPE *)&(sms_query_mail->TP_OA));//Ŀ��绰����;


	OSMutexPend(MUTEX_GR64, 0, &err);
	match = sms_send(sms_send_pdu_frame, sms_data_length);
	
	if(match)
	{

		OSMutexPost(MUTEX_GR64);

	}
	OSMutexPost(MUTEX_GR64);
	OSTimeDly(1000);
}


static void AppSMSSendTask(void *p_arg)
{

	CPU_INT08U err;
	SMS_ALARM_FRAME *sms_alarm_mail = NULL;
	SMS_MAIL_FRAME *sms_mail = NULL;
	SMS_QUERY_FRAME *sms_query_mail = NULL;
	SMS_SEND_PDU_FRAME *sms_send_pdu_frame = (SMS_SEND_PDU_FRAME *)SMS_SEND_PROCESS_BUF;

	DEVICE_INIT_PARAMATERS *device_parameters = &device_init_paramaters;

	(void)p_arg;
	while(1)
	{
		OSSemPend(SEM_SMS_OK, 0, &err);//�ȴ�����״̬OK�ź�;
		while(1)
		{

			/* ���ܸ澯�ʼ� */
			//sms_alarm_mail = (SMS_ALARM_FRAME *)OSQPend(Q_SMS_ALARM, 30000, &err);
			sms_mail = (SMS_MAIL_FRAME *)OSQPend(Q_SMS_ALARM, 30000, &err);
			
			if(err == OS_TIMEOUT)//�������300��û���ʼ���Ҫ��������SMS״̬;
			{
				OSSemPost(SEM_SMS_FAULT);//����SMS״̬�������GR64Task;
				break;//����ѭ������ȴ�����OK�ź�;
			}
			/* �����յ����ʼ� */

			if(sms_mail->sms_mail_type == SMS_ALARM_FRAME_TYPE)
			{
				//���Ÿ澯�ʼ�����;
				sms_alarm_mail = &(sms_mail->sms_alarm_frame);
				sms_alarm_mail_analysis(sms_send_pdu_frame, sms_alarm_mail, device_parameters);
			}
			else if(sms_mail->sms_mail_type == SMS_QUERY_FRAME_TYPE)
			{
				//���Ų�ѯ�ʼ�����;
				sms_query_mail = &(sms_mail->sms_query_frame);
				sms_query_mail_analysis(sms_send_pdu_frame, sms_query_mail, device_parameters);
			}
			else
			{
				//���������ʼ�����;
			}
			
			/* �澯�ʼ���������ͷŸ澯�ʼ���ռ�õĿռ� */
			OSMemPut(MEM_BUF, (void *)sms_mail);
			OSSemPost(SEM_MEM_PART_ALLOC);



		}
		
	}
}

TP_OA_TYPE TP_OA_temp;
static void AppSMSReceiveTask(void *p_arg)
{
	CPU_INT08U err;
	CPU_INT08U *match = NULL;
	CPU_INT16U *temp = NULL;


	/* ����SSCANF����%d�������ʱ������ż��ַ */
	CPU_INT16U unread_sms_index = 0;

	CPU_INT16U length = 0;
	CPU_INT16U index = 0;
	CPU_INT16U id = 0;
	
	SMS_RECEIVE_PDU_FRAME *sms_receive_pdu_frame = NULL; 
	SMS_SET_FRAME *sms_set_frame = NULL;
	SMS_LIST_FRAME *sms_list_frame = NULL;
	SMS_MAIL_FRAME * sms_mail = NULL;
	SMS_QUERY_FRAME *sms_query_mail = NULL;
	DEVICE_INIT_PARAMATERS *device_parameters = &device_init_paramaters;
	
	(void)p_arg;
	while(1)
	{
		OSSemPend(SEM_SMS_MSG_INDICATOR, 0, &err);//�ж���Ϣ�ź�;

		
		OSMutexPend(MUTEX_GR64, 0, &err);
		//Flush_GR64_Buffer();
		Receive_From_GR64(GR64_RECEIVE_BUF, RECEIVE_ALL);
		match = Str_Str(GR64_RECEIVE_BUF, "+CMTI");
		
		if(!match)
		{
			OSMutexPost(MUTEX_GR64);
			continue;
		}
		OSTimeDly(100);
		Str_FmtScan(match, "%*[^,],%d[^\x0D]", &unread_sms_index);

		Str_FmtNPrint(GR64_SEND_BUF, 20,"AT+CMGR=%d\r", unread_sms_index);
		Send_To_GR64(GR64_SEND_BUF, SEND_ALL);
		OSTimeDly(100);
		Receive_From_GR64(GR64_RECEIVE_BUF, RECEIVE_ALL);
		Str_FmtScan(GR64_RECEIVE_BUF, "%*[^:]%*[^\x0D]\x0D\x0A%s[^\x0D]", SMS_RECEIVE_PROCESS_BUF);
		String_To_Hex(SMS_RECEIVE_PROCESS_BUF, SMS_RECEIVE_PROCESS_BUF, Str_Len(SMS_RECEIVE_PROCESS_BUF));
		OSMutexPost(MUTEX_GR64);
		
		sms_receive_pdu_frame = (SMS_RECEIVE_PDU_FRAME *)SMS_RECEIVE_PROCESS_BUF;//��PDU�ṹ�������PDU��ʽ�еĶ�������;
		/* ���֡β����Ϊ# ��� */
		if(sms_receive_pdu_frame->TPDU.TP_UD[sms_receive_pdu_frame->TPDU.TP_UDL- 1] == (unsigned char)(POUND_SIGN >> 8) &&\
			sms_receive_pdu_frame->TPDU.TP_UD[sms_receive_pdu_frame->TPDU.TP_UDL - 2] == (unsigned char)(POUND_SIGN))
		{
			/* 
			 * �����Ժ���Ҫ�õ���������������֡���ݲ��Ҹ�����
			 * ��ַΪ���ַ���Ա�������ݶ�λ��ż��ַ��,������
			 * ���ͽ������ݵ�ʱ��Ͳ������.���ͱ��������ַ��
			 * ʱ��ͻ��������ȡֵ����;16λ��������һ��ȡ����
			 * ��Ϊ�����ֽ�����ÿ��ȡ���ݵĵ�ַӦ��Ϊż��ַ
			 * ��������ַ��ʱ��ȥ�ַ�����ʱȡһ�����ݾͿ���
			 * �������ȡ��������������������Ҫȡ�������ݲſ���
			 * ȡ������Ҫ������,�����е�CPU��֧�����ַȡ����;
			 */
			TP_OA_temp = sms_receive_pdu_frame->TPDU.TP_OA;
			Mem_Copy((void *)SMS_RECEIVE_PROCESS_BUF, \
						(void *)(sms_receive_pdu_frame->TPDU.TP_UD), \
						(CPU_SIZE_T)(sms_receive_pdu_frame->TPDU.TP_UDL));
			
			sms_list_frame = (SMS_LIST_FRAME *)SMS_RECEIVE_PROCESS_BUF;//��LIST���Žṹ����������������;

			err = Mem_Cmp((void *)sms_list_frame->ZXSOFT, \
							(void *)ZXSOFT, \
							sizeof(sms_list_frame->ZXSOFT));
			/* ֡ͷƥ�䴦�� */
			if(err)
			{
				/* ���ܼ����# ƥ�䴦�� */
				if((sms_list_frame->SIGN_1 == POUND_SIGN) && (sms_list_frame->SIGN_2 == POUND_SIGN))
				{
					err = Mem_Cmp((void *)sms_list_frame->LIST, \
									(void *)SET, \
									sizeof(sms_list_frame->LIST));
					if(!err)
					{
						if(sms_list_frame->SIGN_3 == POUND_SIGN)
						{
							switch ((unsigned char)((sms_list_frame->FUCTION_CODE[0] >> 4) & 0xf0) | \
									((sms_list_frame->FUCTION_CODE[1] >> 8) & 0x0f))
							{
									/* ������Ϊ#10#��ʱ�����ݴ��� */
									case 0x10 : {
											/* ��ѯ���豸���� */
												/* ����һ��16 �ֽڵ��ڴ���� ���ڸ澯�ʼ��Ĵ洢*/
												OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
												//sms_alarm_mail = (SMS_ALARM_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail = (SMS_MAIL_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail->sms_mail_type = SMS_QUERY_FRAME_TYPE;
												sms_query_mail = &(sms_mail->sms_query_frame);
												sms_query_mail->TP_OA = TP_OA_temp;
												sms_query_mail->function_code = 0x10;

												/* ���Ͷ��Ÿ澯�ʼ� */
												OSQPostFront(Q_SMS_ALARM, (void *)sms_mail);
											break;
		
									}
									/* ������Ϊ#11#��ʱ�����ݴ��� */
									case 0x11 : {
											/* �������豸���� */
											
											break;
		
									}
									/* ������Ϊ#20#��ʱ�����ݴ��� */
									case 0x20 : {
											/* ��ѯ���豸���� */
											
												/* ����һ��16 �ֽڵ��ڴ���� ���ڸ澯�ʼ��Ĵ洢*/
												OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
												//sms_alarm_mail = (SMS_ALARM_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail = (SMS_MAIL_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail->sms_mail_type = SMS_QUERY_FRAME_TYPE;
												sms_query_mail = &(sms_mail->sms_query_frame);
												sms_query_mail->TP_OA = TP_OA_temp;
												sms_query_mail->function_code = 0x20;

												/* ���Ͷ��Ÿ澯�ʼ� */
												OSQPostFront(Q_SMS_ALARM, (void *)sms_mail);
											break;
		
									}
									/*****************/
									/* ������Ϊ#21#��ʱ�����ݴ��� */
									case 0x21 : {
											/* ��ѯ���豸ID */
												/* ����һ��16 �ֽڵ��ڴ���� ���ڸ澯�ʼ��Ĵ洢*/
												OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
												//sms_alarm_mail = (SMS_ALARM_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail = (SMS_MAIL_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail->sms_mail_type = SMS_QUERY_FRAME_TYPE;
												sms_query_mail = &(sms_mail->sms_query_frame);
												sms_query_mail->TP_OA = TP_OA_temp;
												sms_query_mail->function_code = 0x21;

												/* ���Ͷ��Ÿ澯�ʼ� */
												OSQPostFront(Q_SMS_ALARM, (void *)sms_mail);
											break;
		
										}
									/***********/
									/* ������Ϊ#22#��ʱ�����ݴ��� */
									case 0x22 : {
											/* ���ô��豸���� */
																							/* ����һ��16 �ֽڵ��ڴ���� ���ڸ澯�ʼ��Ĵ洢*/
												OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
												//sms_alarm_mail = (SMS_ALARM_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail = (SMS_MAIL_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail->sms_mail_type = SMS_QUERY_FRAME_TYPE;
												sms_query_mail = &(sms_mail->sms_query_frame);
												sms_query_mail->TP_OA = TP_OA_temp;
												sms_query_mail->function_code = 0x22;

												/* ���Ͷ��Ÿ澯�ʼ� */
												OSQPostFront(Q_SMS_ALARM, (void *)sms_mail);
											break;
		
										}
									
									/* ������Ϊ#30#��ʱ�����ݴ��� */
									case 0x30 : {
											/* ���ñ����ֻ��������� */
																							/* ����һ��16 �ֽڵ��ڴ���� ���ڸ澯�ʼ��Ĵ洢*/
												OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
												//sms_alarm_mail = (SMS_ALARM_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail = (SMS_MAIL_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail->sms_mail_type = SMS_QUERY_FRAME_TYPE;
												sms_query_mail = &(sms_mail->sms_query_frame);
												sms_query_mail->TP_OA = TP_OA_temp;
												sms_query_mail->function_code = 0x30;

												/* ���Ͷ��Ÿ澯�ʼ� */
												OSQPostFront(Q_SMS_ALARM, (void *)sms_mail);
											break;
		
										}
									
									/* ������Ϊ#31#��ʱ�����ݴ��� */
									case 0x31 : {
											/* �����ֻ����� */
																							/* ����һ��16 �ֽڵ��ڴ���� ���ڸ澯�ʼ��Ĵ洢*/
												OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
												//sms_alarm_mail = (SMS_ALARM_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail = (SMS_MAIL_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail->sms_mail_type = SMS_QUERY_FRAME_TYPE;
												sms_query_mail = &(sms_mail->sms_query_frame);
												sms_query_mail->TP_OA = TP_OA_temp;
												sms_query_mail->function_code = 0x31;

												/* ���Ͷ��Ÿ澯�ʼ� */
												OSQPostFront(Q_SMS_ALARM, (void *)sms_mail);
											break;
		
										}
									/* ������Ϊ#40#��ʱ�����ݴ��� */
									case 0x40 : {
											/* ��ѯ����״̬*/

											length = UCS_Len(sms_list_frame->DATA, POUND_SIGN);//���ô��豸�������ݳ���;
											if(length)
											{
												if(length <= 2)
												{
													/* �����ڴ� */
													OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
													match = (CPU_INT08U *)OSMemGet(MEM_BUF, &err);
													
													Str_FmtScan(UCS_To_String(sms_list_frame->DATA, match, length),\
																"%d[^#]",\
																&index);
													
													/* �ͷ��ڴ� */
													OSMemPut(MEM_BUF, (void *)match);
													OSSemPost(SEM_MEM_PART_ALLOC);

													/* ����һ��16 �ֽڵ��ڴ���� ���ڸ澯�ʼ��Ĵ洢*/
													OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
													//sms_alarm_mail = (SMS_ALARM_FRAME *)OSMemGet(MEM_BUF, &err);
													sms_mail = (SMS_MAIL_FRAME *)OSMemGet(MEM_BUF, &err);
													sms_mail->sms_mail_type = SMS_QUERY_FRAME_TYPE;
													sms_query_mail = &(sms_mail->sms_query_frame);
													sms_query_mail->TP_OA = TP_OA_temp;
													sms_query_mail->function_code = 0x40;
													sms_query_mail->cable_index = (unsigned char)index;

													/* ���Ͷ��Ÿ澯�ʼ� */
													OSQPostFront(Q_SMS_ALARM, (void *)sms_mail);
												}
												else
												{
													//���ȴ���5���ַ�����;
												}
											}
											else
											{
												//��������;
											}
											
											break;
		
										}
									/* ��Ч������ʱ�������� */
									default :

										break;
							}
						}
						else
						{
							//֡��ʽ��ƥ��;
						}
					}
					else
					{
						/* SET ��������ƥ�䴦�� */
						sms_set_frame = (SMS_SET_FRAME *)sms_list_frame;//��SET ����ṹ����������;

						/* ���ܼ����# ƥ�䴦�� */
						if((sms_set_frame->SIGN_3 == POUND_SIGN) && (sms_set_frame->SIGN_4 == POUND_SIGN))
						{
							/* ���ò������봦�� */
							/*err = Mem_Cmp((void *)sms_set_frame->PASSWORD, \
											(void *)device_init_paramaters.password, \
											sizeof(sms_set_frame->PASSWORD));
							*/
							if(err)
							{
								/* ���ò���������ȷ,�������� */
								switch ((unsigned char)((sms_set_frame->FUCTION_CODE[0] >> 4) & 0xf0) | \
										((sms_set_frame->FUCTION_CODE[1] >> 8) & 0x0f)) 
								{
									/* ������Ϊ#10#��ʱ�����ݴ��� */
									case 0x10 : {
											/* �������豸���� */
											length = UCS_Len(sms_set_frame->DATA, POUND_SIGN);//ȡ���豸���Ƴ���;
											if(length)
											{
												Mem_Set((void *)device_parameters->primary_device_name, \
															0, \
															(CPU_SIZE_T)DEVICE_NAME_MAX_LENGTH);
												if(length <= (DEVICE_NAME_MAX_LENGTH >> 1))//���ܳ���Ԥ�賤��;
												{
													Mem_Copy((void *)device_parameters->primary_device_name, \
																(void *)sms_set_frame->DATA, \
																(CPU_SIZE_T)(length << 1));
												}
												else
												{
													Mem_Copy((void *)device_parameters->primary_device_name, \
																(void *)sms_set_frame->DATA, \
																(CPU_SIZE_T)(DEVICE_NAME_MAX_LENGTH));
												}
												OSMutexPend(MUTEX_EEPROM, 0, &err);
												/*
												Iron_Write(IRON_PRIMARY_DEVICE_NAME, \
															device_parameters->primary_device_name, \
															DEVICE_NAME_MAX_LENGTH);
												*/
												EEPROM_write(EEPROM_DEVICE_INIT_PARAMATERS_START + \
													OFF_SET_OF(DEVICE_INIT_PARAMATERS, primary_device_name), \
													device_parameters->primary_device_name, DEVICE_NAME_MAX_LENGTH);
												OSMutexPost(MUTEX_EEPROM);
											}
											break;
		
									}
									/* ������Ϊ#11#��ʱ�����ݴ��� */
									case 0x11 : {
											/* �������豸���� */
											length = UCS_Len(sms_set_frame->DATA, POUND_SIGN);//ȡ�����볤��;
											if(length)
											{
												Mem_Set((void *)device_parameters->password, \
															0, \
															(CPU_SIZE_T)DEVICE_PASSWORD_MAX_LENGTH);
												if(length <= (DEVICE_PASSWORD_MAX_LENGTH >> 1))//���ܳ���Ԥ�賤��;
												{
													Mem_Copy((void *)device_parameters->password, \
																(void *)sms_set_frame->DATA, \
																(CPU_SIZE_T)(length << 1));
												}
												else
												{
													Mem_Copy((void *)device_parameters->password, \
																(void *)sms_set_frame->DATA, \
																(CPU_SIZE_T)(DEVICE_PASSWORD_MAX_LENGTH));
												}								
												
												OSMutexPend(MUTEX_EEPROM, 0, &err);
												/*
												Iron_Write(IRON_PASSWORD, \
															device_parameters->password, \
															DEVICE_PASSWORD_MAX_LENGTH);
												*/
												EEPROM_write(EEPROM_DEVICE_INIT_PARAMATERS_START + \
													OFF_SET_OF(DEVICE_INIT_PARAMATERS, password), \
													device_parameters->password, DEVICE_PASSWORD_MAX_LENGTH);
													
												OSMutexPost(MUTEX_EEPROM);

											}
											break;
		
									}
									/* ������Ϊ#20#��ʱ�����ݴ��� */
									case 0x20 : {
											/* ���ô��豸���� */
											length = UCS_Len(sms_set_frame->DATA, POUND_SIGN);//���ô��豸�������ݳ���;
											if(length)
											{
												if(length <= 5)
												{
													/* �����ڴ� */
													OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
													match = (CPU_INT08U *)OSMemGet(MEM_BUF, &err);
													
													Str_FmtScan(UCS_To_String(sms_set_frame->DATA, match, length),\
																"%d[^#]",\
																&length);
													
													/* �ͷ��ڴ� */
													OSMemPut(MEM_BUF, (void *)match);
													OSSemPost(SEM_MEM_PART_ALLOC);

													if(length >= SLAVE_DEVICE_MAX_NUMBERS)
													{
														device_parameters->slave_device_numbers = SLAVE_DEVICE_MAX_NUMBERS;
													}
													else
													{
														device_parameters->slave_device_numbers = length;
													}
													OSMutexPend(MUTEX_EEPROM, 0, &err);
													/*
													Iron_Write(IRON_SLAVE_DEVICE_NUMBERS, \
																(unsigned char *)&(device_parameters->slave_device_numbers), \
																1);
													*/		
													EEPROM_write(EEPROM_DEVICE_INIT_PARAMATERS_START + \
															OFF_SET_OF(DEVICE_INIT_PARAMATERS, slave_device_numbers), \
															(unsigned char *)&(device_parameters->slave_device_numbers), \
															1);
															
													OSMutexPost(MUTEX_EEPROM);
												}
												else
												{
													//���ȴ���5���ַ�����;
												}
											}
											else
											{
												//��������;
											}
											break;
		
									}
									/*****************/
									/* ������Ϊ#21#��ʱ�����ݴ��� */
									case 0x21 : {
											/* ���ô��豸ID */
											length = UCS_Len(sms_set_frame->DATA, POUND_SIGN);//���ô��豸�������ݳ���;
											if(length)
											{
												if(length <= 10)
												{
													if(UCS_Char(sms_set_frame->DATA, COMMA_SIGN, length))//���Ҷ��ŷָ���;
													{
														/* �����ڴ� */
														OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
														match = OSMemGet(MEM_BUF, &err);
														
														Str_FmtScan(UCS_To_String(sms_set_frame->DATA, match, length),\
																	"%d,%x[^#]",\
																	&index, &id);
														/* �ͷ��ڴ� */
														OSMemPut(MEM_BUF, (void *)match);
														OSSemPost(SEM_MEM_PART_ALLOC);
														if(index && index <= device_parameters->slave_device_numbers)
														{
															device_parameters->slave_device_id[index - 1] = id;
															OSMutexPend(MUTEX_EEPROM, 0, &err);
															/*
															Iron_Write(IRON_SLAVE_DEVICE_ID + index - 1, \
																		(unsigned char *)&(device_parameters->slave_device_id[index - 1]), \
																		1);
															*/
															EEPROM_write(EEPROM_DEVICE_INIT_PARAMATERS_START + \
																		OFF_SET_OF(DEVICE_INIT_PARAMATERS, slave_device_id) + index - 1, \
																		(unsigned char *)&(device_parameters->slave_device_id[index - 1]), \
																		1);
															OSMutexPost(MUTEX_EEPROM);
														}
														else
														{
															//������Ų�����Ҫ��
														}
													}
													else
													{
														//û�ж��ŷָ���;
													}

												}
												else
												{
													//���ȴ���2���ַ�����;
												}
											}
											else
											{
												//��������;
											}
											break;
		
										}
									/***********/
									/* ������Ϊ#22#��ʱ�����ݴ��� */
									case 0x22 : {
											/* ���ô��豸���� */
											length = UCS_Len(sms_set_frame->DATA, POUND_SIGN);//���ô��豸�������ݳ���;
											if(length)
											{
												if(length <= 20)
												{
													temp = UCS_Char(sms_set_frame->DATA, COMMA_SIGN, length);//���Ҷ��ŷָ���;
													if(temp)
													{
														length = UCS_Len(sms_set_frame->DATA, COMMA_SIGN);
														/* �����ڴ� */
														OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
														match = OSMemGet(MEM_BUF, &err);
														
														Str_FmtScan(UCS_To_String(sms_set_frame->DATA, match, length), \
																	"%d[^#]", \
																	&index);
														/* �ͷ��ڴ� */
														OSMemPut(MEM_BUF, (void *)match);
														OSSemPost(SEM_MEM_PART_ALLOC);
														if(index && (index <= device_parameters->slave_device_numbers))
														{
															length = UCS_Len(sms_set_frame->DATA, POUND_SIGN) - length;//�����򳤶�;
															if(--length)
															{
																Mem_Set((void *)device_parameters->slave_device_name[index - 1], \
																			0, \
																			(CPU_SIZE_T)DEVICE_NAME_MAX_LENGTH);
																if(length >= (DEVICE_NAME_MAX_LENGTH >> 1))
																{
																	Mem_Copy((void *)device_parameters->slave_device_name[index - 1], \
																				(void *)temp, \
																				(CPU_SIZE_T)DEVICE_NAME_MAX_LENGTH);
																}
																else
																{
																	Mem_Copy((void *)device_parameters->slave_device_name[index - 1], \
																				(void *)temp, \
																				(CPU_SIZE_T)(length << 1));
																}
																OSMutexPend(MUTEX_EEPROM, 0, &err);
																/*
																Iron_Write(IRON_SLAVE_DEVICE_NAME + (index - 1) * DEVICE_NAME_MAX_LENGTH, \
																			device_parameters->slave_device_name[index - 1], \
																			DEVICE_NAME_MAX_LENGTH);
																*/	
																EEPROM_write(EEPROM_DEVICE_INIT_PARAMATERS_START + \
																			OFF_SET_OF(DEVICE_INIT_PARAMATERS, slave_device_name) + (index - 1) * DEVICE_NAME_MAX_LENGTH, \
																			device_parameters->slave_device_name[index - 1], \
																			DEVICE_NAME_MAX_LENGTH);
																OSMutexPost(MUTEX_EEPROM);
															}
															else
															{
																//����������Ϊ��;
															}
														}
														else
														{
															//������Ų�����Ҫ��
														}
													}
													else
													{
														//�޶��ŷָ���;
													}
													
												}
												else
												{
													//���ȴ���20���ַ�����;
												}
											}
											else
											{
												//��������;
											}
											break;
		
										}
									
									/* ������Ϊ#30#��ʱ�����ݴ��� */
									case 0x30 : {
											/* ���ñ����ֻ��������� */
											length = UCS_Len(sms_set_frame->DATA, POUND_SIGN);//���ô��豸�������ݳ���;
											if(length)
											{
												if(length <= 5)
												{
													/* �����ڴ� */
													OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
													match = OSMemGet(MEM_BUF, &err);
													
													Str_FmtScan(UCS_To_String(sms_set_frame->DATA, match, length), \
																"%d[^#]", \
																&length);
													
													/* �ͷ��ڴ� */
													OSMemPut(MEM_BUF, (void *)match);
													OSSemPost(SEM_MEM_PART_ALLOC);
													if(length >= ALARM_TELEPHONE_MAX_NUMBERS)
													{
														device_parameters->alarm_telephone_numbers = ALARM_TELEPHONE_MAX_NUMBERS;
													}
													else
													{
														device_parameters->alarm_telephone_numbers = length;
													}
													OSMutexPend(MUTEX_EEPROM, 0, &err);
													/*
													Iron_Write(IRON_ALARM_TELEPHONE_NUMBERS, \
																(unsigned char *)&(device_parameters->alarm_telephone_numbers), \
																1);
													*/
													EEPROM_write(EEPROM_DEVICE_INIT_PARAMATERS_START + \
																OFF_SET_OF(DEVICE_INIT_PARAMATERS, alarm_telephone_numbers), \
																(unsigned char *)&(device_parameters->alarm_telephone_numbers), \
																1);
													OSMutexPost(MUTEX_EEPROM);
												}
												else
												{
													//���ȴ���5���ַ�����;
												}
											}
											else
											{
												//��������;
											}
													
											break;
		
										}
									
									/* ������Ϊ#31#��ʱ�����ݴ��� */
									case 0x31 : {
											/* �����ֻ����� */
											length = UCS_Len(sms_set_frame->DATA, POUND_SIGN);//���ô��豸�������ݳ���;
											if(length)
											{
												if(length <= 20)
												{
													temp = UCS_Char(sms_set_frame->DATA, COMMA_SIGN, length);//���Ҷ��ŷָ���;
													if(temp)
													{
														length = UCS_Len(sms_set_frame->DATA, COMMA_SIGN);
														/* �����ڴ� */
														OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
														match = OSMemGet(MEM_BUF, &err);
														
														Str_FmtScan(UCS_To_String(sms_set_frame->DATA, match, length),\
																	"%d[^#]",\
																	&index);
														/* �ͷ��ڴ� */
														OSMemPut(MEM_BUF, (void *)match);
														OSSemPost(SEM_MEM_PART_ALLOC);
														if(index && (index <= device_parameters->alarm_telephone_numbers))
														{
															length = UCS_Len(sms_set_frame->DATA, POUND_SIGN) - length;//�����򳤶�;
															if(--length)
															{
																if(length == ALARM_TELEPHONE_NUMBER_SIZE)
																{
																	/* �����ڴ� */
																	OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
																	match = OSMemGet(MEM_BUF, &err);
																	
																	Str_FmtScan(UCS_To_String(temp, match, length),\
																				"%11s[^#]",\
																				device_parameters->alarm_telephone[index - 1]);
																	/* �ͷ��ڴ� */
																	OSMemPut(MEM_BUF, (void *)match);
																	OSSemPost(SEM_MEM_PART_ALLOC);
																	/*
																	Iron_Write(IRON_ALARM_TELEPHONE + (index - 1) * ALARM_TELEPHONE_NUMBER_SIZE, \
																				device_parameters->alarm_telephone[index - 1], \
																				ALARM_TELEPHONE_NUMBER_SIZE);
																				*/
																	EEPROM_write(EEPROM_DEVICE_INIT_PARAMATERS_START + \
																			OFF_SET_OF(DEVICE_INIT_PARAMATERS, alarm_telephone) + (index - 1) * ALARM_TELEPHONE_NUMBER_SIZE, \
																			device_parameters->alarm_telephone[index - 1], \
																			ALARM_TELEPHONE_NUMBER_SIZE);
																	OSMutexPost(MUTEX_EEPROM);
																}
																else
																{
																	//���Ȳ�����11λ�ֻ�����;
																}
															}
															else
															{
																//����������Ϊ��;
															}
														}
														else
														{
															//������Ų�����Ҫ��
														}
													}
													else
													{
														//�޶��ŷָ���;
													}
													
												}
												else
												{
													//���ȴ���20���ַ�����;
												}
											}
											else
											{
												//��������;
											}
													
											Nop();
											break;
		
										}
																		/* ������Ϊ#31#��ʱ�����ݴ��� */
									case 0x40 : {
											/* ���ô��豸ʱ��*/
											length = UCS_Len(sms_set_frame->DATA, POUND_SIGN);//���ô��豸�������ݳ���;
											if(length)
											{
												if(length <= 16)
												{
													if(UCS_Char(sms_set_frame->DATA, COMMA_SIGN, length))//���Ҷ��ŷָ���;
													{
														/* �����ڴ� */
														OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
														match = OSMemGet(MEM_BUF, &err);
														CPU_INT16U TEMP[5];
														Str_FmtScan(UCS_To_String(sms_set_frame->DATA, match, length),\
																	"%d,%d,%d,%d,%d[^#]",\
																	&TEMP[0],&TEMP[1],&TEMP[2],&TEMP[3],&TEMP[4]);
														/* �ͷ��ڴ� */
														OSMemPut(MEM_BUF, (void *)match);
														OSSemPost(SEM_MEM_PART_ALLOC);
														
														set_time.year = byte2BCD((unsigned char)(TEMP[0] % 100));
														set_time.month = byte2BCD((unsigned char)(TEMP[1] % 100));
														set_time.day = byte2BCD((unsigned char)(TEMP[2] % 100));
														set_time.hour = byte2BCD((unsigned char)(TEMP[3] % 100));
														set_time.minute = byte2BCD((unsigned char)(TEMP[4] % 100));
														if(device_parameters->slave_device_numbers <= SLAVE_DEVICE_MAX_NUMBERS)
														for(index= 0;index < device_parameters->slave_device_numbers; index++)
														{
															OSMutexPend(MUTEX_RS485, 0, &err);
															ENABLE_RS485_SEND();
															Flush_RS485_Buffer();
															Send_To_RS485(Create_Send_Frame(RS485_SEND_BUF, device_parameters->slave_device_id[index], MODBUS_TIME_SET, 0x0200, 0x0008), sizeof(MODBUS_TIME_SET_FRAME));
															OSMutexPost(MUTEX_RS485);
															OSTimeDly(100);//���ռ��Ϊ1 S;
														}
													}
													else
													{
														//û�ж��ŷָ���;
													}

												}
												else
												{
													//���ȴ���2���ַ�����;
												}
											}
											else
											{
												//��������;
											}
											break;
		
										}
									
									/* ��Ч������ʱ�������� */
									default :

										break;
								}
							}
							else
							{
								/* ���ò������벻��ȷ���� */
								continue;
							}
						}
						else
						{
							continue;
						}
					}
				}
				else
				{
					/* ���ܼ����# ��ƥ�䴦�� */
					continue;
				}
			}
			else
			{
				/* �Ƿ�֡ͷ���� */
				Nop();
				continue;
			}
		}
		else
		{
			/* �Ƿ�֡β ����*/
			continue;
		}

		Nop();

		OSTimeDly(50);
		
	}
}

/*****************************************************

				GR64 ��������

******************************************************/
static void AppGR64Task(void *p_arg)
{
	CPU_INT08U err;
	CPU_INT08U *match;
	(void)p_arg;
	CPU_INT08U counts = 0;
	OSTimeDly(1000);//��ȴģ�����GR64_VIO״̬����;
	while(1)
	{
		if(GR64_VIO == 0)
		{
			GR64ONOFF_LAT = 0;
			OSTimeDly(60);
			GR64ONOFF_LAT = 1;
			OSTimeDly(1000);
			continue;
			
		}
		else
		{
		/*****************************************************
					��֤оƬ��GR64 ͨѶ�Ƿ�����
		******************************************************/
			OSMutexPend(MUTEX_GR64, 0, &err);
			//Flush_GR64_Buffer();
			Send_To_GR64(AT, SEND_ALL);
			OSTimeDly(50);
			Receive_From_GR64(GR64_RECEIVE_BUF, RECEIVE_ALL);

			match = Str_Str(GR64_RECEIVE_BUF, ATOK);
			OSMutexPost(MUTEX_GR64);
			if(!match)
			{
				continue;
			}
		/*****************************************************
						��֤ͨѶ����ע��״��
		******************************************************/
			OSMutexPend(MUTEX_GR64, 0, &err);
			//Flush_GR64_Buffer();
			Send_To_GR64("AT+CREG?\r", SEND_ALL);
			OSTimeDly(50);
			Receive_From_GR64(GR64_RECEIVE_BUF, RECEIVE_ALL);
			
			match = Str_Str(GR64_RECEIVE_BUF, "+CREG: 0,1\r\n\r\nOK\r\n");
			
			
			if(!(match || Str_Str(GR64_RECEIVE_BUF, "+CREG: 0,5\r\n\r\nOK\r\n")))
			{
				OSMutexPost(MUTEX_GR64);
				counts++;
				if(counts > 10)
				{
					counts = 0;
					if(GR64_VIO == 1)
					{
						GR64ONOFF_LAT = 0;
						OSTimeDly(60);
						GR64ONOFF_LAT = 1;
						OSTimeDly(1000);	
					}
					
				}
				else
				{
					OSTimeDly(500);	
				
				}
				continue;
			}
			OSMutexPost(MUTEX_GR64);

		/******************************************************************
				���ö������ݸ�ʽΪPDU;
		*******************************************************************/
			OSMutexPend(MUTEX_GR64, 0, &err);
			//Flush_GR64_Buffer();
			Send_To_GR64(ATCMGF, SEND_ALL);
			OSTimeDly(50);
			Receive_From_GR64(GR64_RECEIVE_BUF, RECEIVE_ALL);
			
			match = Str_Str(GR64_RECEIVE_BUF, ATOK);
			OSMutexPost(MUTEX_GR64);
			if(!match)
			{
				continue;
			}
		/******************************************************************
				���ö������ݽ���������Ϣ;
		*******************************************************************/
			OSMutexPend(MUTEX_GR64, 0, &err);
			//Flush_GR64_Buffer();
			Send_To_GR64(ATCNMI, SEND_ALL);
			OSTimeDly(50);
			Receive_From_GR64(GR64_RECEIVE_BUF, RECEIVE_ALL);
			
			match = Str_Str(GR64_RECEIVE_BUF, ATOK);
			OSMutexPost(MUTEX_GR64);
			if(!match)
			{
				continue;
			}
		/******************************************************************
				���ö��Ŷ�ȡ��д�롢�洢�ռ����Ͷ�ΪME;(ģ���ڲ��洢)
		*******************************************************************/
			OSMutexPend(MUTEX_GR64, 0, &err);
			//Flush_GR64_Buffer();
			//Send_To_GR64(ATCPMS, SEND_ALL);
			
			Send_To_GR64("AT+CPMS?\r", SEND_ALL);
			OSTimeDly(50);
			Receive_From_GR64(GR64_RECEIVE_BUF, RECEIVE_ALL);
			
			match = Str_Str(GR64_RECEIVE_BUF, ATOK);
			OSMutexPost(MUTEX_GR64);
			if(!match)
			{
				continue;
			}
		/******************************************************************
				���ö��Ž���ָʾ�źų���ʱ��
		*******************************************************************/
			OSMutexPend(MUTEX_GR64, 0, &err);
			//Flush_GR64_Buffer();
			Send_To_GR64(ATSMSRI, SEND_ALL);
			OSTimeDly(50);
			Receive_From_GR64(GR64_RECEIVE_BUF, RECEIVE_ALL);
			
			match = Str_Str(GR64_RECEIVE_BUF, ATOK);
			OSMutexPost(MUTEX_GR64);
			if(!match)
			{
				continue;
			}


		/*****************************************************************************
								ɾ�����ö�������
		******************************************************************************/
		OSMutexPend(MUTEX_GR64, 0, &err);
		//Flush_GR64_Buffer();
		Send_To_GR64("AT+CMGD=1,2\r", SEND_ALL);
		OSTimeDly(50);
		Receive_From_GR64(GR64_RECEIVE_BUF, RECEIVE_ALL);
		OSMutexPost(MUTEX_GR64);
		/*****************************************************
					��ȡ����Ϣ���ĺ���
		******************************************************/
			OSMutexPend(MUTEX_GR64, 0, &err);
			//Flush_GR64_Buffer();
			Send_To_GR64("AT+CSCA?\r", SEND_ALL);
			OSTimeDly(50);
			Receive_From_GR64(GR64_RECEIVE_BUF, RECEIVE_ALL);
			
			match = Str_Str(GR64_RECEIVE_BUF, ATOK);
			if(match)
			{
				Str_FmtScan(GR64_RECEIVE_BUF, "%*[^86]86%[^\"]", GR64_SEND_BUF);
				Mem_Copy((void *)(device_init_paramaters.service_center_address), GR64_SEND_BUF, (CPU_SIZE_T)ALARM_TELEPHONE_NUMBER_SIZE);
				OSMutexPost(MUTEX_GR64);
				OSMutexPend(MUTEX_EEPROM, 0, &err);
				/*
				Iron_Write(IRON_SERVICE_CENTER_ADDRESS, \
							device_init_paramaters.service_center_address, \
							ALARM_TELEPHONE_NUMBER_SIZE);*/
				EEPROM_write(EEPROM_DEVICE_INIT_PARAMATERS_START + \
						OFF_SET_OF(DEVICE_INIT_PARAMATERS, service_center_address) ,\
						device_init_paramaters.service_center_address, \
						ALARM_TELEPHONE_NUMBER_SIZE);
				OSMutexPost(MUTEX_EEPROM);
			}
			else
			{
				OSMutexPost(MUTEX_GR64);
				continue;
			}
			/*  */
			
			OSSemPost(SEM_SMS_OK);//����SMSSend ����;
			OSSemPend(SEM_SMS_FAULT, 0, &err);//�ȴ�SMS����ʧ���ź�;
			//OSTimeDlyHMSM(0, 5, 0, 0);//��������Ժ�ÿ����Ӽ��һ��;
		}
	}
}


