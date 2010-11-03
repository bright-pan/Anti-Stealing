/*
*********************************************************************************************************
*                                               MODULE
*********************************************************************************************************
*/

#ifndef  LIB_MODBUS_MODULE_PRESENT
#define  LIB_MODBUS_MODULE_PRESENT


/*$PAGE*/
/*
*********************************************************************************************************
*                                            INCLUDE FILES
*
* Note(s) : (1) The following common software files are located in the following directories :
*
*               (a) \<Custom Library Directory>\lib*.*
*
*               (b) (1) \<CPU-Compiler Directory>\cpu_def.h
*
*                   (2) \<CPU-Compiler Directory>\<cpu>\<compiler>\cpu*.*
*
*                           where
*                                   <Custom Library Directory>      directory path for custom   library      software
*                                   <CPU-Compiler Directory>        directory path for common   CPU-compiler software
*                                   <cpu>                           directory name for specific processor (CPU)
*                                   <compiler>                      directory name for specific compiler
*
*           (2) Compiler MUST be configured to include the '\<Custom Library Directory>\uC-LIB\',
*               '\<CPU-Compiler Directory>\' directory, & the specific CPU-compiler directory as 
*               additional include path directories.
*
*           (3) NO compiler-supplied standard library functions SHOULD be used.
*********************************************************************************************************
*/

//#include  <cpu.h> 
#include  <lib_def.h>
//#include <app_cfg.h>
//#include  <app_cfg.h>
//#include <bsp.h>
//#include <includes.h>

/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/
/* 电缆故障类型 */
#define CABLE_DISCONNECT_FAULT	0x01
#define CURRENT_ON					0x01

/* 数据帧正确 */
#define FRAME_CORRECT 				0x00

/* 短信帧功能分隔标记 */
#define POUND_SIGN 	0x2300//#井号
#define COMMA_SIGN 0x2c00
#define COLON_SIGN	0x3a00// :;
#define LINE_SIGN	0x2D00// :;

/* 汉字UCS2 编码 */

#define UCS2_LIAN	0XDE8F//连
#define UCS2_TONG	0X1A90//通
#define UCS2_DUAN	0XAD65//断
#define UCS2_KAI	0X005F//开
#define UCS2_YOU	0X0967//有
#define UCS2_DIAN	0X3575//电
#define UCS2_WU		0XE065//无
#define UCS2_DU 		0XA65E//度

#define YEAR			0X745e
#define MONTH		0X0867
#define DAY			0Xe565
#define HOUR			0XF665
#define MINUTE		0X0652
#define SECOND		0XD279

#define FAN			0xd153
#define SHENG	 	0x1f75//发生
#define SHI			0x8b4e
#define JIAN			0xf64e//事件

//请尽快处理;
#define 	QING		0xf78b
#define	JIN			0x3d5c
#define	KUAI		0xeb5f
#define	CHU			0x0459
#define	LI			0x0674

#define	YU			0x8e4e//于

#define SMS_ALARM_FRAME_TYPE		1
#define SMS_QUERY_FRAME_TYPE		2

#define MODBUS_DATA_QUERY 		0x03
#define MODBUS_TIME_SET			0x10

/*
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*/

typedef struct {
	unsigned int STI[8];
}STRING_TO_INT;

typedef struct {

	unsigned char SMSC_Length;//计算方式不同;
	unsigned char SMSC_Type_Of_Address;
	unsigned char SMSC_Address_Value[7];
	
}SMSC_TYPE;

typedef struct {

	unsigned char TP_OA_Length;//计算方式不同;
	unsigned char TP_OA_Type_Of_Address;
	unsigned char TP_OA_Address_Value[7];
	
}TP_OA_TYPE;
typedef struct {

	unsigned char TP_DA_Length;//计算方式不同;
	unsigned char TP_DA_Type_Of_Address;
	unsigned char TP_DA_Address_Value[7];
	
}TP_DA_TYPE;

typedef struct {
	
	unsigned char TP_SCTS_Year;//BCD;
	unsigned char TP_SCTS_Month;
	unsigned char TP_SCTS_Day;
	unsigned char TP_SCTS_Hour;
	unsigned char TP_SCTS_minute;
	unsigned char TP_SCTS_Second;
	unsigned char TP_SCTS_Time_Zone;
	
}TP_SCTS_TYPE;

typedef struct{
	unsigned char sms_head_length;
	unsigned char sms_laber_length;
	unsigned char sms_head_surplus_length;
	unsigned char sms_laber;
	unsigned char sms_numbers;
	unsigned char sms_index;
}SMS_HEAD_6;

typedef struct {
	
	unsigned char 	First_Octet;
	TP_OA_TYPE		TP_OA;//9字节;
	unsigned char 	TP_PID;
	unsigned char 	TP_DCS;
	TP_SCTS_TYPE	TP_SCTS;//7字节;
	unsigned char		TP_UDL;//用户长度必须小于140 个字节;
	unsigned char		TP_UD[140];
	
}SMS_RECEIVE_TPDU_TYPE;

typedef struct {
	
	unsigned char 	First_Octet;
	unsigned char		TP_MR;
	TP_DA_TYPE		TP_DA;//9字节;
	unsigned char 	TP_PID;
	unsigned char 	TP_DCS;
	unsigned char		TP_VP;// 1个字节;
	unsigned char		TP_UDL;//用户长度必须小于420 个字节;
	unsigned char		TP_UD[420];
	
}SMS_SEND_TPDU_TYPE;

typedef struct {
	
	SMSC_TYPE SMSC;
	SMS_RECEIVE_TPDU_TYPE TPDU;
	
}SMS_RECEIVE_PDU_FRAME;

typedef struct {
	
	SMSC_TYPE SMSC;
	SMS_SEND_TPDU_TYPE TPDU;
	
}SMS_SEND_PDU_FRAME;



typedef struct {

	unsigned int ZXSOFT[6];
	unsigned int SIGN_1;
	unsigned int SET[2];
	unsigned int SIGN_2;
	unsigned int PASSWORD[6];
	unsigned int SIGN_3;
	unsigned int FUCTION_CODE[2];
	unsigned int SIGN_4;
	unsigned int DATA[50];
	
}SMS_SET_FRAME;

typedef struct {
	
	unsigned int ZXSOFT[6];
	unsigned int SIGN_1;
	unsigned int LIST[2];
	unsigned int SIGN_2;	
	unsigned int FUCTION_CODE[2];
	unsigned int SIGN_3;
	unsigned int DATA[50];
	
}SMS_LIST_FRAME;

typedef struct{
	unsigned char second;
	unsigned char minute;
	unsigned char hour;
	unsigned char day;
	unsigned char month;
	unsigned char week;
	unsigned char year;
}TIME_FRAME;

 typedef struct {
 
	unsigned char device_id;
	unsigned char function_code;
	unsigned int 	address;
	unsigned int	length;
	unsigned int	crc;
	
}MODBUS_DATA_QUERY_FRAME;

 typedef struct {
 
	unsigned char device_id;
	unsigned char function_code;
	unsigned int 	address;
	unsigned int	length;
	TIME_FRAME	time;
	unsigned char invaild;
	unsigned int	crc;
	
}MODBUS_TIME_SET_FRAME;

 

typedef struct {
	unsigned char device_id;
	unsigned char function_code;
	unsigned char	length;
	unsigned char	cable_fault_type;
	TIME_FRAME 	time;
	unsigned char current_on_off;
	unsigned int	temperature;
	unsigned int 	current_intensity;
	unsigned int 	current_frequency;
	unsigned int	crc;
}MODBUS_RECEIVE_FRAME;

typedef struct {
	unsigned char device_index;
	unsigned char	cable_fault_type;
	unsigned int	temperature;
	unsigned char current_on_off;
	TIME_FRAME 	time;
}SMS_ALARM_FRAME;

typedef struct {
	TP_OA_TYPE		TP_OA;//9字节;
	unsigned char function_code;
	unsigned char cable_index;
}SMS_QUERY_FRAME;

typedef struct {
	unsigned int sms_mail_type;
	union {
		SMS_ALARM_FRAME sms_alarm_frame;
		SMS_QUERY_FRAME sms_query_frame;
	};
}SMS_MAIL_FRAME;

/*$PAGE*/
/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/

extern unsigned int NUM_UCS_MAP[16];
extern TIME_FRAME set_time;

/*$PAGE*/
/*
*********************************************************************************************************
*                                               MACRO'S
*********************************************************************************************************
*/
#define INT_REVERSER(a) ((a) >> 8 | (a) << 8)
/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/
unsigned int updcrc(unsigned int icrc, unsigned char *icp, unsigned int icnt );
unsigned char *Create_Send_Frame(unsigned char *frame_str, unsigned char dev_id, unsigned char func_code, unsigned int addr, unsigned int len);
void String_To_Hex(unsigned char *str_dest, unsigned char *str_src, unsigned int len);
unsigned char *String_To_Semi_Octet(unsigned char *str_dest, unsigned char *str_src, unsigned char len);
unsigned char UCS_Len(unsigned int *UCS, unsigned int end_sign);
unsigned char *UCS_To_String(unsigned int *UCS, unsigned char * str, unsigned char UCS_len);
unsigned int *UCS_Char(unsigned int *UCS, unsigned int ucs_char, unsigned char UCS_len);
void TP_Str_To_Octet(unsigned char *TP_octet, unsigned char *TP_str, unsigned char TP_type, unsigned char TP_len);

void Alarm_Mail_Data_To_UCS(CPU_INT16U *UCS, SMS_ALARM_FRAME *sms_alarm_mail, CPU_INT16U *UCS_Len);
unsigned int *SMS_Send_User_Data_Copy(CPU_INT16U *UCS, unsigned char *data_src, CPU_INT16U *UCS_Len, CPU_INT16U data_max_len);

void Send_PDU_To_GR64(SMS_SEND_PDU_FRAME *sms_pdu, SMS_HEAD_6 *sms_head);


/*$PAGE*/
/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif                                                          /* End of lib mem module include.                       */

