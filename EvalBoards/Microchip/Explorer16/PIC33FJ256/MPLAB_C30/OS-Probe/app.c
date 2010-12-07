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

/* 任务栈定义区 */
OS_STK  AppStartTaskStk[APP_TASK_START_STK_SIZE];
OS_STK  AppGR64TaskStk[APP_TASK_GR64_STK_SIZE];
OS_STK  AppRS485TaskStk[APP_TASK_RS485_STK_SIZE];
OS_STK  AppSMSSendTaskStk[APP_TASK_SMSSend_STK_SIZE];
OS_STK  AppSMSReceiveTaskStk[APP_TASK_SMSReceive_STK_SIZE];
/* 设备运行参数 */
OS_EVENT *MUTEX_DEVICE_INIT_PARAMATERS;
DEVICE_INIT_PARAMATERS device_init_paramaters;
MODBUS_RECEIVE_FRAME slave_device_state_frame[SLAVE_DEVICE_MAX_NUMBERS];
TIME_FRAME set_time;
const DEVICE_INIT_PARAMATERS device_init_paramaters_const = {

	"高新区一号开闭所",
	1,
	{0x01, },
	{"比亚迪出线电缆",},
	{{0,},},
	1,
	{"13474656377",},
	"",
	"123456"
};
/* 设备使用分配信号量 */
OS_EVENT *MUTEX_GR64;//设备使用互斥信号量;
OS_EVENT *MUTEX_RS485;//设备使用互斥信号量;
OS_EVENT *MUTEX_EEPROM;

/* 用于发送中断完成指示 */
OS_EVENT *SEM_RS485_SEND_BYTE;//发送一个字节已完成信号量;
OS_EVENT *SEM_GR64_SEND_BYTE;//发送一个字节已完成信号量;

/* 用于内存分配 */
OS_EVENT *SEM_MEM_PART_ALLOC;//内存分配信号量;
OS_MEM	  *MEM_BUF;//内存缓冲区;
unsigned char MEM_PART[MEM_PART_NUMBER][MEM_PART_SIZE];//内存缓冲区MEM_PART_NUMBER 个分区,各个分区大小为MEM_PART_SIZE Bytes;

/* SMS发送告警发送邮件队列 */
OS_EVENT *Q_SMS_ALARM;
void *Q_SMS_ALARM_ARRAY[Q_SMS_ALARM_ARRAY_SIZE];//消息队列数组大小为10;

/* SMS 消息指示信号量 */
OS_EVENT *SEM_SMS_MSG_INDICATOR;

/* 接受缓冲区 */
BUFFER GR64_buf;//GR64
BUFFER RS485_buf;//RS485

/* 帧处理内存区*/
unsigned char GR64_SEND_BUF[256];
unsigned char GR64_RECEIVE_BUF[256];

unsigned char SMS_RECEIVE_PROCESS_BUF[256];
unsigned char SMS_SEND_PROCESS_BUF[512];
unsigned char SMS_UCS_PROCESS_BUF[DEVICE_NAME_MAX_LENGTH];

unsigned char RS485_SEND_BUF[32];
unsigned char RS485_RECEIVE_BUF[32];




OS_EVENT *SEM_SMS_OK;
OS_EVENT *SEM_SMS_FAULT;

/* 铁电存储器使用信号量 */


/* 用于GR64 的AT指令 */
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

unsigned char *ZXSOFT = "\x00\x7a\x00\x78\x00\x73\x00\x6f\x00\x66\x00\x74";//ZXSOFT帧头匹配;
unsigned char *SET = "\x8b\xbe\x7f\x6e";//设置命令匹配参数;

unsigned char *SET_PRIMARY_DEVICE_NAME = "\x00\x30\x00\x31\x00\x30";//010;设置主设备名称;
unsigned char *SET_SLAVE_DEVICE_NUMBERS = "\x00\x30\x00\x32\x00\x30";//020;设置从设备数;
unsigned char *SET_SLAVE_DEVICE_ID = "\x00\x30\x00\x32\x00\x31";//021;//设置从设备通讯ID;
unsigned char *SET_SLAVE_DEVICE_NAME = "\x00\x30\x00\x32\x00\x32";//022;//设置从设备名称;
unsigned char *SET_ALARM_TELEPHONE_NUMBERS = "\x00\x30\x00\x33\x00\x30";//030;设置告警电话数量;
unsigned char *SET_ALARM_TELEPHONE = "\x00\x30\x00\x33\x00\x31";//031;设置告警电话号码;

unsigned char *LIST = "\x67\xe5\x8b\xe2";//查询命令;


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

/* 创建MEM_PART_NUMBER 个内存分区且分区大小为MEM_PART_SIZE 供邮箱队列使用 */
SEM_MEM_PART_ALLOC = OSSemCreate(MEM_PART_NUMBER);
MEM_BUF = OSMemCreate(MEM_PART, MEM_PART_NUMBER, MEM_PART_SIZE, &err);

/* 创建邮件列表且列表大小为Q_SMS_ALARM_ARRAY_SIZE 个消息 */
Q_SMS_ALARM = OSQCreate(Q_SMS_ALARM_ARRAY, Q_SMS_ALARM_ARRAY_SIZE);

/* 创建短消息状态信号量 */
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
/* 全局变量初始化 */
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

				任务创建函数

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

				RS485 处理任务

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
			OSTimeDly(100);//接收间隔为1 S;
			CLOSE_RS485();
			frame_receive = (MODBUS_RECEIVE_FRAME *)Receive_From_RS485(RS485_RECEIVE_BUF, RECEIVE_ALL);
			OSMutexPost(MUTEX_RS485);

			/* 判断接受帧是否存在 */
			if(frame_receive != NULL)
			{
					/* 使用CRC 验证接受帧的完整性 */
				if(updcrc(0, (unsigned char *)frame_receive, sizeof(MODBUS_RECEIVE_FRAME)) == FRAME_CORRECT)
				{
					/*处理收到的数据*/
					/* 验证接受帧是不是所需要的设备发出的 帧*/
					if(frame_receive->device_id == device_parameters->slave_device_id[slave_device_cnt])
					{
						/* 如果出现电缆通断状态变化和电缆有无电流的状态变化时
						 * 发出告警邮件并保存为历史状态. 
						 *
						 */
						slave_device_state[slave_device_cnt] = *frame_receive;
						//if(frame_receive->cable_fault_type != device_parameters->slave_device_history_alarm[slave_device_cnt].cable_fault_type \
						//	||frame_receive->current_on_off != device_parameters->slave_device_history_alarm[slave_device_cnt].current_on_off)
						if(frame_receive->cable_fault_type != device_parameters->slave_device_history_alarm[slave_device_cnt].cable_fault_type)
						{

							/* 分配一个16 字节的内存分区 用于告警邮件的存储*/
							OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
							//sms_alarm_mail = (SMS_ALARM_FRAME *)OSMemGet(MEM_BUF, &err);
							sms_mail = (SMS_MAIL_FRAME *)OSMemGet(MEM_BUF, &err);
							sms_mail->sms_mail_type = SMS_ALARM_FRAME_TYPE;
							sms_alarm_mail = &(sms_mail->sms_alarm_frame);
							/* 构造短信告警邮件 */
							sms_alarm_mail->device_index= slave_device_cnt;//设备索引;
							sms_alarm_mail->cable_fault_type = frame_receive->cable_fault_type;
							sms_alarm_mail->temperature = frame_receive->temperature;
							sms_alarm_mail->current_on_off = frame_receive->current_on_off;
							sms_alarm_mail->time = frame_receive->time;
							/* 保存为历史状态 */
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
							/* 发送短信告警邮件 */
							OSQPostFront(Q_SMS_ALARM, (void *)sms_mail);
						}
					}
					else
					{
						/* 不是 所需设备发出的数据帧处理*/
						
					}
					
				}
				else
				{
					/* 帧CRC校验错误处理*/
					//continue;
				}

			}
			else
			{
				/* 没有收到帧时处理 */
			}
			
			OSTimeDly(50);//延时500ms;
		}

		OSTimeDly(50);//延时500ms;
	}
}

/*****************************************************

				SMS 发送 处理任务

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
		//单条短信;
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
		//多条短信;
		for (sms_index = 1; sms_index <= sms_head.sms_numbers; sms_index++)
		{

			//处理短信帧头;
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
	*((unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length) = POUND_SIGN;//添加#号;
	sms_data_length ++;//#号长度;

	SMS_Send_User_Data_Copy((unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length, \
								device_parameters->primary_device_name, \
								&(sms_data_length), \
								DEVICE_NAME_MAX_LENGTH);
	*((unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length) = LINE_SIGN;//添加-号;
	sms_data_length ++;//-号长度;

	SMS_Send_User_Data_Copy((unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length, \
								device_parameters->slave_device_name[sms_alarm_mail->device_index], \
								&(sms_data_length), \
								DEVICE_NAME_MAX_LENGTH);

	*((unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length) = POUND_SIGN;//添加#号;
	sms_data_length ++;//#号长度;	

	Alarm_Mail_Data_To_UCS((unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length, \
								sms_alarm_mail, \
								&(sms_data_length));

	sms_data_length <<= 1;//字节数;			

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
	*((unsigned int *)(sms_send_pdu_frame->TPDU.TP_UD) + sms_data_length) = POUND_SIGN;//添加#号;
	sms_data_length ++;//#号长度;
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
							/* 线缆通断状态解析{接通,断开} */
				if(slave_device_state->cable_fault_type == CABLE_DISCONNECT_FAULT)
				{
					/* 断开 */
					*UCS++ = UCS2_DUAN;
					*UCS++ = UCS2_KAI;
				}
				else
				{
					/* 连通 */
					*UCS++ = UCS2_LIAN;
					*UCS++ = UCS2_TONG;
				}
				*UCS++ = POUND_SIGN;
				*UCS_len += 3;

							/* 线缆温度解析 XXX度/XX度*/
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
							
							*UCS++ = NUM_UCS_MAP[slave_device_state->temperature / 100];//百位;
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
							*UCS++ = NUM_UCS_MAP[slave_device_state->temperature / 100];//百位;
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

				/* 邮件时间解析格式为20XX-XX-XX,XX:XX:XX*/
				*UCS++ = 0X3200;// 2;
				*UCS++ = 0X3000;// 0;
				*UCS++ = ((unsigned int )(slave_device_state->time.year & 0xf0) << 4) | 0x3000;//解析年的高四为年的十位;
				*UCS++ = ((unsigned int )(slave_device_state->time.year & 0x0f) << 8) | 0x3000;//解析年的高四为年的个位;
				*UCS++ = LINE_SIGN;// -;
				*UCS++ = ((unsigned int )(slave_device_state->time.month & 0xf0) << 4) | 0x3000;//解析年的高四为月的十位;
				*UCS++ = ((unsigned int )(slave_device_state->time.month & 0x0f) << 8) | 0x3000;//解析年的高四为月的个位;
				*UCS++ = LINE_SIGN;// -;
				*UCS++ = ((unsigned int )(slave_device_state->time.day & 0xf0) << 4) | 0x3000;//解析年的高四为日的十位;
				*UCS++ = ((unsigned int )(slave_device_state->time.day & 0x0f) << 8) | 0x3000;//解析年的高四为日的个位;
				*UCS++ = COMMA_SIGN;// ,;
				*UCS++ = ((unsigned int )(slave_device_state->time.hour & 0xf0) << 4) | 0x3000;//解析年的高四为日的十位;
				*UCS++ = ((unsigned int )(slave_device_state->time.hour & 0x0f) << 8) | 0x3000;//解析年的高四为日的个位;
				*UCS++ = COLON_SIGN;// :;
				*UCS++ = ((unsigned int )(slave_device_state->time.minute & 0xf0) << 4) | 0x3000;//解析年的高四为日的十位;
				*UCS++ = ((unsigned int )(slave_device_state->time.minute & 0x0f) << 8) | 0x3000;//解析年的高四为日的个位;
				*UCS++ = COLON_SIGN;// :;
				*UCS++ = ((unsigned int )(slave_device_state->time.second & 0xf0) << 4) | 0x3000;//解析年的高四为日的十位;
				*UCS++ = ((unsigned int )(slave_device_state->time.second & 0x0f) << 8) | 0x3000;//解析年的高四为日的个位;
				*UCS++ = POUND_SIGN;// #;
				*UCS_len += 20;
			
			}
			break;
		}
		default : 
			break;
	}
	
	sms_data_length <<= 1;//字节数;	
	sms_send_pdu_frame->TPDU.TP_DA = *((TP_DA_TYPE *)&(sms_query_mail->TP_OA));//目标电话号码;


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
		OSSemPend(SEM_SMS_OK, 0, &err);//等待短信状态OK信号;
		while(1)
		{

			/* 接受告警邮件 */
			//sms_alarm_mail = (SMS_ALARM_FRAME *)OSQPend(Q_SMS_ALARM, 30000, &err);
			sms_mail = (SMS_MAIL_FRAME *)OSQPend(Q_SMS_ALARM, 30000, &err);
			
			if(err == OS_TIMEOUT)//如果空闲300秒没有邮件需要处理则检查SMS状态;
			{
				OSSemPost(SEM_SMS_FAULT);//启动SMS状态检测任务GR64Task;
				break;//跳出循环进入等待短信OK信号;
			}
			/* 处理收到的邮件 */

			if(sms_mail->sms_mail_type == SMS_ALARM_FRAME_TYPE)
			{
				//短信告警邮件处理;
				sms_alarm_mail = &(sms_mail->sms_alarm_frame);
				sms_alarm_mail_analysis(sms_send_pdu_frame, sms_alarm_mail, device_parameters);
			}
			else if(sms_mail->sms_mail_type == SMS_QUERY_FRAME_TYPE)
			{
				//短信查询邮件处理;
				sms_query_mail = &(sms_mail->sms_query_frame);
				sms_query_mail_analysis(sms_send_pdu_frame, sms_query_mail, device_parameters);
			}
			else
			{
				//其他短信邮件处理;
			}
			
			/* 告警邮件处理完成释放告警邮件所占用的空间 */
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


	/* 由于SSCANF函数%d输出数据时必须是偶地址 */
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
		OSSemPend(SEM_SMS_MSG_INDICATOR, 0, &err);//有短消息信号;

		
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
		
		sms_receive_pdu_frame = (SMS_RECEIVE_PDU_FRAME *)SMS_RECEIVE_PROCESS_BUF;//用PDU结构体解析出PDU格式中的短信数据;
		/* 检测帧尾必须为# 标记 */
		if(sms_receive_pdu_frame->TPDU.TP_UD[sms_receive_pdu_frame->TPDU.TP_UDL- 1] == (unsigned char)(POUND_SIGN >> 8) &&\
			sms_receive_pdu_frame->TPDU.TP_UD[sms_receive_pdu_frame->TPDU.TP_UDL - 2] == (unsigned char)(POUND_SIGN))
		{
			/* 
			 * 由于以后需要用到整型数据来解析帧数据并且该数据
			 * 地址为奇地址所以必须把数据定位到偶地址上,这样用
			 * 整型解析数据的时候就不会出错.整型变量在奇地址的
			 * 时候就会出现总线取值错误;16位数据总线一次取得数
			 * 据为两个字节所以每次取数据的地址应该为偶地址
			 * 如果是奇地址的时候，去字符数据时取一次数据就可以
			 * 但是如果取整型数据是理论上则需要取两次数据才可以
			 * 取到所需要的数据,但是有的CPU则不支持奇地址取数据;
			 */
			TP_OA_temp = sms_receive_pdu_frame->TPDU.TP_OA;
			Mem_Copy((void *)SMS_RECEIVE_PROCESS_BUF, \
						(void *)(sms_receive_pdu_frame->TPDU.TP_UD), \
						(CPU_SIZE_T)(sms_receive_pdu_frame->TPDU.TP_UDL));
			
			sms_list_frame = (SMS_LIST_FRAME *)SMS_RECEIVE_PROCESS_BUF;//用LIST短信结构体来解析短信数据;

			err = Mem_Cmp((void *)sms_list_frame->ZXSOFT, \
							(void *)ZXSOFT, \
							sizeof(sms_list_frame->ZXSOFT));
			/* 帧头匹配处理 */
			if(err)
			{
				/* 功能间隔符# 匹配处理 */
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
									/* 功能码为#10#的时候数据处理 */
									case 0x10 : {
											/* 查询主设备名称 */
												/* 分配一个16 字节的内存分区 用于告警邮件的存储*/
												OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
												//sms_alarm_mail = (SMS_ALARM_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail = (SMS_MAIL_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail->sms_mail_type = SMS_QUERY_FRAME_TYPE;
												sms_query_mail = &(sms_mail->sms_query_frame);
												sms_query_mail->TP_OA = TP_OA_temp;
												sms_query_mail->function_code = 0x10;

												/* 发送短信告警邮件 */
												OSQPostFront(Q_SMS_ALARM, (void *)sms_mail);
											break;
		
									}
									/* 功能码为#11#的时候数据处理 */
									case 0x11 : {
											/* 设置主设备密码 */
											
											break;
		
									}
									/* 功能码为#20#的时候数据处理 */
									case 0x20 : {
											/* 查询从设备数量 */
											
												/* 分配一个16 字节的内存分区 用于告警邮件的存储*/
												OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
												//sms_alarm_mail = (SMS_ALARM_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail = (SMS_MAIL_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail->sms_mail_type = SMS_QUERY_FRAME_TYPE;
												sms_query_mail = &(sms_mail->sms_query_frame);
												sms_query_mail->TP_OA = TP_OA_temp;
												sms_query_mail->function_code = 0x20;

												/* 发送短信告警邮件 */
												OSQPostFront(Q_SMS_ALARM, (void *)sms_mail);
											break;
		
									}
									/*****************/
									/* 功能码为#21#的时候数据处理 */
									case 0x21 : {
											/* 查询从设备ID */
												/* 分配一个16 字节的内存分区 用于告警邮件的存储*/
												OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
												//sms_alarm_mail = (SMS_ALARM_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail = (SMS_MAIL_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail->sms_mail_type = SMS_QUERY_FRAME_TYPE;
												sms_query_mail = &(sms_mail->sms_query_frame);
												sms_query_mail->TP_OA = TP_OA_temp;
												sms_query_mail->function_code = 0x21;

												/* 发送短信告警邮件 */
												OSQPostFront(Q_SMS_ALARM, (void *)sms_mail);
											break;
		
										}
									/***********/
									/* 功能码为#22#的时候数据处理 */
									case 0x22 : {
											/* 设置从设备名称 */
																							/* 分配一个16 字节的内存分区 用于告警邮件的存储*/
												OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
												//sms_alarm_mail = (SMS_ALARM_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail = (SMS_MAIL_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail->sms_mail_type = SMS_QUERY_FRAME_TYPE;
												sms_query_mail = &(sms_mail->sms_query_frame);
												sms_query_mail->TP_OA = TP_OA_temp;
												sms_query_mail->function_code = 0x22;

												/* 发送短信告警邮件 */
												OSQPostFront(Q_SMS_ALARM, (void *)sms_mail);
											break;
		
										}
									
									/* 功能码为#30#的时候数据处理 */
									case 0x30 : {
											/* 设置报警手机号码数量 */
																							/* 分配一个16 字节的内存分区 用于告警邮件的存储*/
												OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
												//sms_alarm_mail = (SMS_ALARM_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail = (SMS_MAIL_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail->sms_mail_type = SMS_QUERY_FRAME_TYPE;
												sms_query_mail = &(sms_mail->sms_query_frame);
												sms_query_mail->TP_OA = TP_OA_temp;
												sms_query_mail->function_code = 0x30;

												/* 发送短信告警邮件 */
												OSQPostFront(Q_SMS_ALARM, (void *)sms_mail);
											break;
		
										}
									
									/* 功能码为#31#的时候数据处理 */
									case 0x31 : {
											/* 设置手机号码 */
																							/* 分配一个16 字节的内存分区 用于告警邮件的存储*/
												OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
												//sms_alarm_mail = (SMS_ALARM_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail = (SMS_MAIL_FRAME *)OSMemGet(MEM_BUF, &err);
												sms_mail->sms_mail_type = SMS_QUERY_FRAME_TYPE;
												sms_query_mail = &(sms_mail->sms_query_frame);
												sms_query_mail->TP_OA = TP_OA_temp;
												sms_query_mail->function_code = 0x31;

												/* 发送短信告警邮件 */
												OSQPostFront(Q_SMS_ALARM, (void *)sms_mail);
											break;
		
										}
									/* 功能码为#40#的时候数据处理 */
									case 0x40 : {
											/* 查询电缆状态*/

											length = UCS_Len(sms_list_frame->DATA, POUND_SIGN);//设置从设备数量数据长度;
											if(length)
											{
												if(length <= 2)
												{
													/* 分配内存 */
													OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
													match = (CPU_INT08U *)OSMemGet(MEM_BUF, &err);
													
													Str_FmtScan(UCS_To_String(sms_list_frame->DATA, match, length),\
																"%d[^#]",\
																&index);
													
													/* 释放内存 */
													OSMemPut(MEM_BUF, (void *)match);
													OSSemPost(SEM_MEM_PART_ALLOC);

													/* 分配一个16 字节的内存分区 用于告警邮件的存储*/
													OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
													//sms_alarm_mail = (SMS_ALARM_FRAME *)OSMemGet(MEM_BUF, &err);
													sms_mail = (SMS_MAIL_FRAME *)OSMemGet(MEM_BUF, &err);
													sms_mail->sms_mail_type = SMS_QUERY_FRAME_TYPE;
													sms_query_mail = &(sms_mail->sms_query_frame);
													sms_query_mail->TP_OA = TP_OA_temp;
													sms_query_mail->function_code = 0x40;
													sms_query_mail->cable_index = (unsigned char)index;

													/* 发送短信告警邮件 */
													OSQPostFront(Q_SMS_ALARM, (void *)sms_mail);
												}
												else
												{
													//长度大于5个字符数据;
												}
											}
											else
											{
												//无数据项;
											}
											
											break;
		
										}
									/* 无效功能码时不做处理 */
									default :

										break;
							}
						}
						else
						{
							//帧格式不匹配;
						}
					}
					else
					{
						/* SET 命令类型匹配处理 */
						sms_set_frame = (SMS_SET_FRAME *)sms_list_frame;//用SET 命令结构来解析数据;

						/* 功能间隔符# 匹配处理 */
						if((sms_set_frame->SIGN_3 == POUND_SIGN) && (sms_set_frame->SIGN_4 == POUND_SIGN))
						{
							/* 设置操作密码处理 */
							/*err = Mem_Cmp((void *)sms_set_frame->PASSWORD, \
											(void *)device_init_paramaters.password, \
											sizeof(sms_set_frame->PASSWORD));
							*/
							if(err)
							{
								/* 设置操作密码正确,处理功能码 */
								switch ((unsigned char)((sms_set_frame->FUCTION_CODE[0] >> 4) & 0xf0) | \
										((sms_set_frame->FUCTION_CODE[1] >> 8) & 0x0f)) 
								{
									/* 功能码为#10#的时候数据处理 */
									case 0x10 : {
											/* 设置主设备名称 */
											length = UCS_Len(sms_set_frame->DATA, POUND_SIGN);//取得设备名称长度;
											if(length)
											{
												Mem_Set((void *)device_parameters->primary_device_name, \
															0, \
															(CPU_SIZE_T)DEVICE_NAME_MAX_LENGTH);
												if(length <= (DEVICE_NAME_MAX_LENGTH >> 1))//不能超出预设长度;
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
									/* 功能码为#11#的时候数据处理 */
									case 0x11 : {
											/* 设置主设备密码 */
											length = UCS_Len(sms_set_frame->DATA, POUND_SIGN);//取得密码长度;
											if(length)
											{
												Mem_Set((void *)device_parameters->password, \
															0, \
															(CPU_SIZE_T)DEVICE_PASSWORD_MAX_LENGTH);
												if(length <= (DEVICE_PASSWORD_MAX_LENGTH >> 1))//不能超出预设长度;
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
									/* 功能码为#20#的时候数据处理 */
									case 0x20 : {
											/* 设置从设备数量 */
											length = UCS_Len(sms_set_frame->DATA, POUND_SIGN);//设置从设备数量数据长度;
											if(length)
											{
												if(length <= 5)
												{
													/* 分配内存 */
													OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
													match = (CPU_INT08U *)OSMemGet(MEM_BUF, &err);
													
													Str_FmtScan(UCS_To_String(sms_set_frame->DATA, match, length),\
																"%d[^#]",\
																&length);
													
													/* 释放内存 */
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
													//长度大于5个字符数据;
												}
											}
											else
											{
												//无数据项;
											}
											break;
		
									}
									/*****************/
									/* 功能码为#21#的时候数据处理 */
									case 0x21 : {
											/* 设置从设备ID */
											length = UCS_Len(sms_set_frame->DATA, POUND_SIGN);//设置从设备数量数据长度;
											if(length)
											{
												if(length <= 10)
												{
													if(UCS_Char(sms_set_frame->DATA, COMMA_SIGN, length))//查找逗号分隔符;
													{
														/* 分配内存 */
														OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
														match = OSMemGet(MEM_BUF, &err);
														
														Str_FmtScan(UCS_To_String(sms_set_frame->DATA, match, length),\
																	"%d,%x[^#]",\
																	&index, &id);
														/* 释放内存 */
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
															//设置序号不符合要求
														}
													}
													else
													{
														//没有逗号分隔符;
													}

												}
												else
												{
													//长度大于2个字符数据;
												}
											}
											else
											{
												//无数据项;
											}
											break;
		
										}
									/***********/
									/* 功能码为#22#的时候数据处理 */
									case 0x22 : {
											/* 设置从设备名称 */
											length = UCS_Len(sms_set_frame->DATA, POUND_SIGN);//设置从设备数量数据长度;
											if(length)
											{
												if(length <= 20)
												{
													temp = UCS_Char(sms_set_frame->DATA, COMMA_SIGN, length);//查找逗号分隔符;
													if(temp)
													{
														length = UCS_Len(sms_set_frame->DATA, COMMA_SIGN);
														/* 分配内存 */
														OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
														match = OSMemGet(MEM_BUF, &err);
														
														Str_FmtScan(UCS_To_String(sms_set_frame->DATA, match, length), \
																	"%d[^#]", \
																	&index);
														/* 释放内存 */
														OSMemPut(MEM_BUF, (void *)match);
														OSSemPost(SEM_MEM_PART_ALLOC);
														if(index && (index <= device_parameters->slave_device_numbers))
														{
															length = UCS_Len(sms_set_frame->DATA, POUND_SIGN) - length;//名称域长度;
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
																//名称数据域为空;
															}
														}
														else
														{
															//设置序号不符合要求
														}
													}
													else
													{
														//无逗号分隔符;
													}
													
												}
												else
												{
													//长度大于20个字符数据;
												}
											}
											else
											{
												//无数据项;
											}
											break;
		
										}
									
									/* 功能码为#30#的时候数据处理 */
									case 0x30 : {
											/* 设置报警手机号码数量 */
											length = UCS_Len(sms_set_frame->DATA, POUND_SIGN);//设置从设备数量数据长度;
											if(length)
											{
												if(length <= 5)
												{
													/* 分配内存 */
													OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
													match = OSMemGet(MEM_BUF, &err);
													
													Str_FmtScan(UCS_To_String(sms_set_frame->DATA, match, length), \
																"%d[^#]", \
																&length);
													
													/* 释放内存 */
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
													//长度大于5个字符数据;
												}
											}
											else
											{
												//无数据项;
											}
													
											break;
		
										}
									
									/* 功能码为#31#的时候数据处理 */
									case 0x31 : {
											/* 设置手机号码 */
											length = UCS_Len(sms_set_frame->DATA, POUND_SIGN);//设置从设备数量数据长度;
											if(length)
											{
												if(length <= 20)
												{
													temp = UCS_Char(sms_set_frame->DATA, COMMA_SIGN, length);//查找逗号分隔符;
													if(temp)
													{
														length = UCS_Len(sms_set_frame->DATA, COMMA_SIGN);
														/* 分配内存 */
														OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
														match = OSMemGet(MEM_BUF, &err);
														
														Str_FmtScan(UCS_To_String(sms_set_frame->DATA, match, length),\
																	"%d[^#]",\
																	&index);
														/* 释放内存 */
														OSMemPut(MEM_BUF, (void *)match);
														OSSemPost(SEM_MEM_PART_ALLOC);
														if(index && (index <= device_parameters->alarm_telephone_numbers))
														{
															length = UCS_Len(sms_set_frame->DATA, POUND_SIGN) - length;//名称域长度;
															if(--length)
															{
																if(length == ALARM_TELEPHONE_NUMBER_SIZE)
																{
																	/* 分配内存 */
																	OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
																	match = OSMemGet(MEM_BUF, &err);
																	
																	Str_FmtScan(UCS_To_String(temp, match, length),\
																				"%11s[^#]",\
																				device_parameters->alarm_telephone[index - 1]);
																	/* 释放内存 */
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
																	//长度不等于11位手机号码;
																}
															}
															else
															{
																//名称数据域为空;
															}
														}
														else
														{
															//设置序号不符合要求
														}
													}
													else
													{
														//无逗号分隔符;
													}
													
												}
												else
												{
													//长度大于20个字符数据;
												}
											}
											else
											{
												//无数据项;
											}
													
											Nop();
											break;
		
										}
																		/* 功能码为#31#的时候数据处理 */
									case 0x40 : {
											/* 设置从设备时间*/
											length = UCS_Len(sms_set_frame->DATA, POUND_SIGN);//设置从设备数量数据长度;
											if(length)
											{
												if(length <= 16)
												{
													if(UCS_Char(sms_set_frame->DATA, COMMA_SIGN, length))//查找逗号分隔符;
													{
														/* 分配内存 */
														OSSemPend(SEM_MEM_PART_ALLOC, 0, &err);
														match = OSMemGet(MEM_BUF, &err);
														CPU_INT16U TEMP[5];
														Str_FmtScan(UCS_To_String(sms_set_frame->DATA, match, length),\
																	"%d,%d,%d,%d,%d[^#]",\
																	&TEMP[0],&TEMP[1],&TEMP[2],&TEMP[3],&TEMP[4]);
														/* 释放内存 */
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
															OSTimeDly(100);//接收间隔为1 S;
														}
													}
													else
													{
														//没有逗号分隔符;
													}

												}
												else
												{
													//长度大于2个字符数据;
												}
											}
											else
											{
												//无数据项;
											}
											break;
		
										}
									
									/* 无效功能码时不做处理 */
									default :

										break;
								}
							}
							else
							{
								/* 设置操作密码不正确处理 */
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
					/* 功能间隔符# 不匹配处理 */
					continue;
				}
			}
			else
			{
				/* 非法帧头处理 */
				Nop();
				continue;
			}
		}
		else
		{
			/* 非法帧尾 处理*/
			continue;
		}

		Nop();

		OSTimeDly(50);
		
	}
}

/*****************************************************

				GR64 处理任务

******************************************************/
static void AppGR64Task(void *p_arg)
{
	CPU_INT08U err;
	CPU_INT08U *match;
	(void)p_arg;
	CPU_INT08U counts = 0;
	OSTimeDly(1000);//冷却模块否则GR64_VIO状态不对;
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
					验证芯片与GR64 通讯是否正常
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
						验证通讯网络注册状况
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
				设置短信数据格式为PDU;
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
				设置短信数据接受提醒消息;
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
				设置短信读取、写入、存储空间类型都为ME;(模块内部存储)
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
				设置短信接受指示信号持续时间
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
								删除无用短信数据
		******************************************************************************/
		OSMutexPend(MUTEX_GR64, 0, &err);
		//Flush_GR64_Buffer();
		Send_To_GR64("AT+CMGD=1,2\r", SEND_ALL);
		OSTimeDly(50);
		Receive_From_GR64(GR64_RECEIVE_BUF, RECEIVE_ALL);
		OSMutexPost(MUTEX_GR64);
		/*****************************************************
					读取短消息中心号码
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
			
			OSSemPost(SEM_SMS_OK);//启动SMSSend 任务;
			OSSemPend(SEM_SMS_FAULT, 0, &err);//等待SMS发送失败信号;
			//OSTimeDlyHMSM(0, 5, 0, 0);//检验完成以后每五分钟检测一次;
		}
	}
}


