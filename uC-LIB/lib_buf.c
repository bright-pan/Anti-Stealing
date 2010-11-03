#include <Lib_buf.h>
#include <includes.h>

/*
extern OS_EVENT *SEM_RS485_SEND_BYTE;
extern OS_EVENT *SEM_GR64_SEND_BYTE;

extern OS_EVENT *MUTEX_GR64;
extern OS_EVENT *MUTEX_RS485;

extern BUFFER GR64_buf;
extern BUFFER RS485_buf;
*/



/**********************************************************************************
*
*				void Send_To_GR64(unsigned char *str, unsigned int str_len);
*                         
*
* Description :   向GR64模块发送指定数量的数据;
*
*
* Argument(s) : 	(1) unsigned char *str 
*					>需要发送的字符数据指针；
*   				(2) unsigned int str_len 
*					>str_len = 0, 发送一个长度为Str_Len()的字符串;
*					>str_len != 0, 发送长度为str_len的字符数据;
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************/

void Send_To_GR64(unsigned char *str, unsigned int str_len)
{
	CPU_INT08U err;
	if(str_len)
	{
		while(str_len--)
		{
			GR64_TX = *str++;
			OSSemPend(SEM_GR64_SEND_BYTE, 5, &err);
		}
	}
	else
	{
		str_len = Str_Len(str);
		while(str_len--)
		{
			GR64_TX = *str++;
			OSSemPend(SEM_GR64_SEND_BYTE, 5, &err);
		}		
	}
}

/**********************************************************************************
*
*				void Send_To_RS485(unsigned char *str, unsigned int str_len);
*                         
*
* Description :   向RS485模块发送指定数量的数据;
*
*
* Argument(s) : 	(1) unsigned char *str 
*					>需要发送的字符数据指针；
*   				(2) unsigned int str_len 
*					>str_len = 0, 发送一个长度为Str_Len()的字符串;
*					>str_len != 0, 发送长度为str_len的字符数据;
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
************************************************************************************/

void Send_To_RS485(unsigned char *str, unsigned int str_len)
{
	CPU_INT08U err;
	if(str_len)
	{
		while(str_len--)
		{
			RS485_TX = *str++;
			OSSemPend(SEM_RS485_SEND_BYTE, 5, &err);
			
		}
	}
	else
	{
		str_len = Str_Len(str);
		while(str_len--)
		{
			RS485_TX = *str++;
			OSSemPend(SEM_RS485_SEND_BYTE, 5, &err);
		}		
	}
	OSTimeDly(2);
}

/*******************************************************************************************************************
*
*						unsigned char *Receive_From_GR64(unsigned char *str, unsigned int str_len);
*                         
*
* Description :   从GR64_buf 缓冲区中接受指定数量的数据并返回接收数据的头指针;
*
*
* Argument(s) : 	(1) unsigned char *str 
*					>接收缓冲区的头指针;
*   				(2) unsigned int str_len 
*					>str_len = 0, 从GR64_buf 缓冲区读取所有数据;
*					>str_len != 0, 从GR64_buf 缓冲区读取长度为str_len 的数据;
*
* Return(s)   : 接收缓冲区的头指针(unsigned char *);
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************************/

unsigned char *Receive_From_GR64(unsigned char *str, unsigned int str_len)
{
#if OS_CRITICAL_METHOD == 3                      /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0;
#endif

	unsigned char *str_bk = str;
	unsigned char buf_length = 0;

	CPU_CRITICAL_ENTER();
	buf_length = CHARS(GR64_buf);
	CPU_CRITICAL_EXIT();
	if(buf_length == 0)
			return NULL;

	if(str_len)
	{

		if(str_len > buf_length)
			return NULL;	
		
		while(str_len--)
		{
			CPU_CRITICAL_ENTER();
			GETCH(GR64_buf, *str_bk++);
			CPU_CRITICAL_EXIT();
		}
	}
	else
	{
		str_len = buf_length;
		while(str_len--)
		{
			CPU_CRITICAL_ENTER();
			GETCH(GR64_buf, *str_bk++);
			CPU_CRITICAL_EXIT();
		}
		
	}
	return str;
}

/*******************************************************************************************************************
*
*						unsigned char *Receive_From_RS485(unsigned char *str, unsigned int str_len);
*                         
*
* Description :   从RS485_buf 缓冲区中接受指定数量的数据并返回接收数据的头指针;
*
*
* Argument(s) : 	(1) unsigned char *str 
*					>接收缓冲区的头指针;
*   				(2) unsigned int str_len 
*					>str_len = 0, 从RS485_buf 缓冲区读取所有数据;
*					>str_len != 0, 从RS485_buf 缓冲区读取长度为str_len 的数据;
*
* Return(s)   : 接收缓冲区的头指针(unsigned char *);
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************************/

unsigned char *Receive_From_RS485(unsigned char *str, unsigned int str_len)
{
#if OS_CRITICAL_METHOD == 3                      /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0;
#endif

	unsigned char *str_bk = str;
	unsigned char buf_length = 0;

	CPU_CRITICAL_ENTER();
	buf_length = CHARS(RS485_buf);
	CPU_CRITICAL_EXIT();
	if(buf_length == 0)
			return NULL;

	if(str_len)
	{

		if(str_len > buf_length)
			return NULL;	
		
		while(str_len--)
		{
			CPU_CRITICAL_ENTER();
			GETCH(RS485_buf, *str_bk++);
			CPU_CRITICAL_EXIT();
		}
	}
	else
	{
		str_len = buf_length;
		while(str_len--)
		{
			CPU_CRITICAL_ENTER();
			GETCH(RS485_buf, *str_bk++);
			CPU_CRITICAL_EXIT();
		}
		
	}
	return str;
}
/*******************************************************************************************************************
*
*						void Flush_GR64_Buffer(void);
*                         
*
* Description :   清空GR64_buf 缓冲区;
*
*
* Argument(s) : 	none. 
*	
* Return(s)   : 	none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************************/

void Flush_GR64_Buffer(void)
{
#if OS_CRITICAL_METHOD == 3                      /* Allocate storage for CPU status register           */
	OS_CPU_SR  cpu_sr = 0;
#endif
	CPU_CRITICAL_ENTER();
	FLUSH(GR64_buf);
	CPU_CRITICAL_EXIT();
}
/*******************************************************************************************************************
*
*						void Flush_RS48564_Buffer(void);
*                         
*
* Description :   清空RS485_buf 缓冲区;
*
*
* Argument(s) : 	none. 
*	
* Return(s)   : 	none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************************/

void Flush_RS485_Buffer(void)
{
#if OS_CRITICAL_METHOD == 3                      /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0;
#endif
	CPU_CRITICAL_ENTER();
	FLUSH(RS485_buf);
	CPU_CRITICAL_EXIT();
}

