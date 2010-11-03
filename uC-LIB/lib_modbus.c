#include <Lib_modbus.h>
#include <includes.h>


#define   P    0x1021

#define W 16

#define B 8

static unsigned int crctab[1<<B] = { /* as calculated by initcrctab() */

	0x0000,  0x1021,  0x2042,  0x3063,  0x4084,  0x50a5,  0x60c6,  0x70e7,
	0x8108,  0x9129,  0xa14a,  0xb16b,  0xc18c,  0xd1ad,  0xe1ce,  0xf1ef,
	0x1231,  0x0210,  0x3273,  0x2252,  0x52b5,  0x4294,  0x72f7,  0x62d6,
	0x9339,  0x8318,  0xb37b,  0xa35a,  0xd3bd,  0xc39c,  0xf3ff,  0xe3de,
	0x2462,  0x3443,  0x0420,  0x1401,  0x64e6,  0x74c7,  0x44a4,  0x5485,
	0xa56a,  0xb54b,  0x8528,  0x9509,  0xe5ee,  0xf5cf,  0xc5ac,  0xd58d,
	0x3653,  0x2672,  0x1611,  0x0630,  0x76d7,  0x66f6,  0x5695,  0x46b4,
	0xb75b,  0xa77a,  0x9719,  0x8738,  0xf7df,  0xe7fe,  0xd79d,  0xc7bc,
	0x48c4,  0x58e5,  0x6886,  0x78a7,  0x0840,  0x1861,  0x2802,  0x3823,
	0xc9cc,  0xd9ed,  0xe98e,  0xf9af,  0x8948,  0x9969,  0xa90a,  0xb92b,
	0x5af5,  0x4ad4,  0x7ab7,  0x6a96,  0x1a71,  0x0a50,  0x3a33,  0x2a12,
	0xdbfd,  0xcbdc,  0xfbbf,  0xeb9e,  0x9b79,  0x8b58,  0xbb3b,  0xab1a,
	0x6ca6,  0x7c87,  0x4ce4,  0x5cc5,  0x2c22,  0x3c03,  0x0c60,  0x1c41,
	0xedae,  0xfd8f,  0xcdec,  0xddcd,  0xad2a,  0xbd0b,  0x8d68,  0x9d49,
	0x7e97,  0x6eb6,  0x5ed5,  0x4ef4,  0x3e13,  0x2e32,  0x1e51,  0x0e70,
	0xff9f,  0xefbe,  0xdfdd,  0xcffc,  0xbf1b,  0xaf3a,  0x9f59,  0x8f78,
	0x9188,  0x81a9,  0xb1ca,  0xa1eb,  0xd10c,  0xc12d,  0xf14e,  0xe16f,
	0x1080,  0x00a1,  0x30c2,  0x20e3,  0x5004,  0x4025,  0x7046,  0x6067,
	0x83b9,  0x9398,  0xa3fb,  0xb3da,  0xc33d,  0xd31c,  0xe37f,  0xf35e,
	0x02b1,  0x1290,  0x22f3,  0x32d2,  0x4235,  0x5214,  0x6277,  0x7256,
	0xb5ea,  0xa5cb,  0x95a8,  0x8589,  0xf56e,  0xe54f,  0xd52c,  0xc50d,
	0x34e2,  0x24c3,  0x14a0,  0x0481,  0x7466,  0x6447,  0x5424,  0x4405,
	0xa7db,  0xb7fa,  0x8799,  0x97b8,  0xe75f,  0xf77e,  0xc71d,  0xd73c,
	0x26d3,  0x36f2,  0x0691,  0x16b0,  0x6657,  0x7676,  0x4615,  0x5634,
	0xd94c,  0xc96d,  0xf90e,  0xe92f,  0x99c8,  0x89e9,  0xb98a,  0xa9ab,
	0x5844,  0x4865,  0x7806,  0x6827,  0x18c0,  0x08e1,  0x3882,  0x28a3,
	0xcb7d,  0xdb5c,  0xeb3f,  0xfb1e,  0x8bf9,  0x9bd8,  0xabbb,  0xbb9a,
	0x4a75,  0x5a54,  0x6a37,  0x7a16,  0x0af1,  0x1ad0,  0x2ab3,  0x3a92,
	0xfd2e,  0xed0f,  0xdd6c,  0xcd4d,  0xbdaa,  0xad8b,  0x9de8,  0x8dc9,
	0x7c26,  0x6c07,  0x5c64,  0x4c45,  0x3ca2,  0x2c83,  0x1ce0,  0x0cc1,
	0xef1f,  0xff3e,  0xcf5d,  0xdf7c,  0xaf9b,  0xbfba,  0x8fd9,  0x9ff8,
	0x6e17,  0x7e36,  0x4e55,  0x5e74,  0x2e93,  0x3eb2,  0x0ed1,  0x1ef0,

};

unsigned int NUM_UCS_MAP[16] = {

	0X3000,  0X3100, 
	0X3200,  0X3300,
	0X3400,  0X3500,
	0X3600,  0X3700,
	0X3800,  0X3900,
	0X4100,  0X4200,
	0X4300,  0X4400,
	0X4500,  0X4600,
};

static unsigned char HEX_CHAR_MAP[16] = {

	'0','1','2','3',
	'4','5','6','7',
	'8','9','A','B',
	'C','D','E','F'
};

static unsigned char NUM_MAP[10] = {

	'\x00','\x01','\x02','\x03','\x04',
	'\x05','\x06','\x07','\x08','\x09'

};

static unsigned char ALPHA_MAP[7] = {

	'\x00','\x0a','\x0b','\x0c',
	'\x0d','\x0e','\x0f'

};

unsigned int updcrc(unsigned int icrc, unsigned char *icp, unsigned int icnt)
{
      register unsigned int crc = icrc;
      register unsigned char *cp = icp;
      register unsigned int cnt = icnt;

      while(cnt--)
		crc = (crc<<B) ^ crctab[(crc>>(W-B)) ^ *cp++];

      return(crc);
}


unsigned char *Create_Send_Frame(unsigned char *frame_str, unsigned char dev_id, unsigned char func_code, unsigned int addr, unsigned int len)
{
	
	switch(func_code)
	{
		case MODBUS_DATA_QUERY :{

			MODBUS_DATA_QUERY_FRAME *frame = (MODBUS_DATA_QUERY_FRAME *)frame_str;

			frame->device_id = dev_id;
			frame->function_code = func_code;
			frame->address = addr;
			frame->length = len;
			frame->crc = INT_REVERSER(updcrc(0, frame_str, sizeof(MODBUS_DATA_QUERY_FRAME) - 2));
			//frame->crc = 0x9f79;//需要修改;

			break;
		}
		case MODBUS_TIME_SET : {
			MODBUS_TIME_SET_FRAME *frame = (MODBUS_TIME_SET_FRAME *)frame_str;

			frame->device_id = dev_id;
			frame->function_code = func_code;
			frame->address = addr;
			frame->length = len;
			frame->time = set_time;
			frame->invaild = 0;
			frame->crc = INT_REVERSER(updcrc(0, frame_str, sizeof(MODBUS_TIME_SET_FRAME) - 2));
			//frame->crc = 0x9f79;//需要修改;

			break;
		}

		default : 
			break;
	}
	
	return frame_str;
}

unsigned char *String_To_Semi_Octet(unsigned char *str_dest, unsigned char *str_src, unsigned char len)
{

	STRING_TO_INT *temp = (STRING_TO_INT *)str_src;
	register signed char len_bk = len >> 1;
	
	for (; len_bk >= 0;len_bk--)
	{
		str_dest[len_bk] = (unsigned char)((temp->STI[len_bk] & 0x0f00) >> 4) | ((temp->STI[len_bk] & 0x000f));
	}
	len >>= 1;
	str_dest[len++] |= 0xf0;
	str_dest[len] = '\0';
	return str_dest;
}

void String_To_Hex(unsigned char *str_dest, unsigned char *str_src, unsigned int len)
{

     len = len >> 1;

     for(; len > 0; --len)
     {
         if(Str_IsDigit(*str_src))
             *str_dest = NUM_MAP[(*str_src++ & 0x0f)] << 4;
		 else
		 	*str_dest = ALPHA_MAP[(*str_src++ & 0x0f)] << 4;
         if(Str_IsDigit(*str_src))
             *str_dest++ |= NUM_MAP[(*str_src++ & 0x0f)];
     	 else
     	 	 *str_dest++ |= ALPHA_MAP[(*str_src++ & 0x0f)];
     }
     *str_dest = '\0';
}

unsigned char UCS_Len(unsigned int *UCS, unsigned int end_sign)
{

	unsigned char length = 0;
	
	while(*UCS++ != end_sign)
		length++;
	
	return length;

}

unsigned char UCS_Len_Restraints(unsigned int *UCS, unsigned int end_sign, unsigned char max_len)
{

	unsigned char length = 0;
	
	while(*UCS++ != end_sign)
	{
		if(++length >= max_len)
			break;
	}
	
	return length;

}

unsigned char *UCS_To_String(unsigned int *UCS, unsigned char * str, unsigned char UCS_len)
{

	unsigned char *str_dest = str;
	unsigned char *str_src = (unsigned char *)UCS;

	while(UCS_len--)
	{
		*str_dest++ = *++str_src;

		str_src++;
	}
	*str_dest++ = '#';
	*str_dest = '\0';
	return str;
	
}

unsigned int *UCS_Char(unsigned int *UCS, unsigned int ucs_char, unsigned char UCS_len)
{

	while(UCS_len--)
	{

		if(*UCS++ == ucs_char)
			return UCS;
		
	}
	return NULL;
}

void TP_Str_To_Octet(unsigned char *TP_octet, unsigned char *TP_str, unsigned char TP_type, unsigned char TP_len)
{
	unsigned char length = ((TP_len & 0x01) ? TP_len + 1 : TP_len) >> 1;
	unsigned char *TP_octet_bk = TP_octet;
	if(TP_type == INTERNATIONAL_ADDRESS_TYPE)
	{
		*TP_octet++ = 0X68;//国际地址开头为86;
		while(length--)
		{
			*TP_octet = *(TP_str + 1) << 4;
			*TP_octet++ |= *TP_str++ & 0x0f;
			TP_str++;
		}
		if(TP_len & 0x01)
		{
			TP_len++;
			TP_len >>= 1;
			TP_octet_bk[TP_len] |= 0xf0;

		}
	}
	else
	{
		while(length--)
		{
			*TP_octet = *(TP_str + 1) << 4;
			*TP_octet++ |= *TP_str++ & 0x0f;
			TP_str++;
		}
		if(TP_len & 0x01)
		{
			TP_len++;
			TP_len >>= 1;
			TP_octet_bk[TP_len] |= 0xf0;

		}
	}	
}

unsigned int *SMS_Send_User_Data_Copy(unsigned int *UCS, unsigned char *data_src, unsigned int *UCS_Len, unsigned int data_max_len)
{
	unsigned char *data_dest = (unsigned char *)UCS;
	data_max_len >>= 1;
	while(data_max_len--)
	{
		if(*data_src == 0 && *(data_src+ 1) == 0)
			break;
		*data_dest++ = *data_src++;
		*data_dest++ = *data_src++;
		(*UCS_Len) ++;
	}
	return (unsigned int *)data_dest;
}

void Alarm_Mail_Data_To_UCS(CPU_INT16U *UCS, SMS_ALARM_FRAME *sms_alarm_mail, CPU_INT16U *UCS_Len)
{

/* 邮件时间解析格式为20XX-XX-XX,XX:XX:XX*/
	*UCS++ = YU;//于
	*UCS_Len += 1;
	
	*UCS++ = 0X3200;// 2;
	*UCS++ = 0X3000;// 0;
	*UCS++ = ((unsigned int )(sms_alarm_mail->time.year & 0xf0) << 4) | 0x3000;//解析年的高四为年的十位;
	*UCS++ = ((unsigned int )(sms_alarm_mail->time.year & 0x0f) << 8) | 0x3000;//解析年的高四为年的个位;
	*UCS++ = YEAR;// 年;
	*UCS++ = ((unsigned int )(sms_alarm_mail->time.month & 0xf0) << 4) | 0x3000;//解析年的高四为月的十位;
	*UCS++ = ((unsigned int )(sms_alarm_mail->time.month & 0x0f) << 8) | 0x3000;//解析年的高四为月的个位;
	*UCS++ = MONTH;// 月;
	*UCS++ = ((unsigned int )(sms_alarm_mail->time.day & 0xf0) << 4) | 0x3000;//解析年的高四为日的十位;
	*UCS++ = ((unsigned int )(sms_alarm_mail->time.day & 0x0f) << 8) | 0x3000;//解析年的高四为日的个位;
	*UCS++ = DAY;// 日;
	*UCS++ = ((unsigned int )(sms_alarm_mail->time.hour & 0xf0) << 4) | 0x3000;//解析年的高四为日的十位;
	*UCS++ = ((unsigned int )(sms_alarm_mail->time.hour & 0x0f) << 8) | 0x3000;//解析年的高四为日的个位;
	*UCS++ = HOUR;// 时;
	*UCS++ = ((unsigned int )(sms_alarm_mail->time.minute & 0xf0) << 4) | 0x3000;//解析年的高四为日的十位;
	*UCS++ = ((unsigned int )(sms_alarm_mail->time.minute & 0x0f) << 8) | 0x3000;//解析年的高四为日的个位;
	*UCS++ = MINUTE;// 分;
	*UCS++ = ((unsigned int )(sms_alarm_mail->time.second & 0xf0) << 4) | 0x3000;//解析年的高四为日的十位;
	*UCS++ = ((unsigned int )(sms_alarm_mail->time.second & 0x0f) << 8) | 0x3000;//解析年的高四为日的个位;
	*UCS++ = SECOND;// 秒;
	*UCS_Len += 20;
	*UCS++ = FAN;
	*UCS++ = SHENG;
	*UCS_Len += 2;
	/* 线缆通断状态解析{接通,断开} */
	if(sms_alarm_mail->cable_fault_type == CABLE_DISCONNECT_FAULT)
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
	*UCS_Len += 2;

	*UCS++ = SHI;
	*UCS++ = JIAN;
	*UCS_Len += 2;

	*UCS++ = COMMA_SIGN;
	*UCS++ = QING;
	*UCS++ = JIN;
	*UCS++ = KUAI;
	*UCS++ = CHU;
	*UCS++ = LI;
	*UCS_Len += 6;

	*UCS++ = POUND_SIGN;
	*UCS_Len += 1;
	/*
	// 线缆带电状况{有电,无电} 
	if(sms_alarm_mail->current_on_off == CURRENT_ON)
	{
		// 有电
		*UCS++ = UCS2_YOU;
		*UCS++ = UCS2_DIAN;
	}
	else
	{
		//无电 
		*UCS++ = UCS2_WU;
		*UCS++ = UCS2_DIAN;
	}
	*UCS++ = POUND_SIGN;
	*UCS_Len += 3;	

	//  线缆温度解析 XXX度/XX度
	switch(sms_alarm_mail->temperature & 0xf800)
	{
		case 0x0000 : {
			sms_alarm_mail->temperature &=  0x07FF;
			sms_alarm_mail->temperature >>= 4;
			if(sms_alarm_mail->temperature <= 9)
			{
				*UCS++ = NUM_UCS_MAP[sms_alarm_mail->temperature];
				*UCS++ = UCS2_DU;
				*UCS++ = POUND_SIGN;
				*UCS_Len += 3;				

			}
			else if(sms_alarm_mail->temperature <= 99)
			{
				*UCS++ = NUM_UCS_MAP[sms_alarm_mail->temperature / 10];
				*UCS++ = NUM_UCS_MAP[sms_alarm_mail->temperature % 10];
				*UCS++ = UCS2_DU;
				*UCS++ = POUND_SIGN;
				*UCS_Len += 4;				

			}else if(sms_alarm_mail->temperature <= 999)
			{
				
				*UCS++ = NUM_UCS_MAP[sms_alarm_mail->temperature / 100];//百位;
				sms_alarm_mail->temperature %= 100;
				*UCS++ = NUM_UCS_MAP[sms_alarm_mail->temperature / 10];
				*UCS++ = NUM_UCS_MAP[sms_alarm_mail->temperature % 10];
				*UCS++ = UCS2_DU;
				*UCS++ = POUND_SIGN;
				*UCS_Len += 5;
			}
			
			break;
		}

		case 0xf800 : {

			sms_alarm_mail->temperature &=  0x07FF;
			sms_alarm_mail->temperature >>= 4;
			if(sms_alarm_mail->temperature <= 9)
			{
				*UCS++ = LINE_SIGN;
				*UCS++ = NUM_UCS_MAP[sms_alarm_mail->temperature];
				*UCS++ = UCS2_DU;
				*UCS++ = POUND_SIGN;
				*UCS_Len += 4;				

			}
			else if(sms_alarm_mail->temperature <= 99)
			{
				*UCS++ = LINE_SIGN;
				*UCS++ = NUM_UCS_MAP[sms_alarm_mail->temperature / 10];
				*UCS++ = NUM_UCS_MAP[sms_alarm_mail->temperature % 10];
				*UCS++ = UCS2_DU;
				*UCS++ = POUND_SIGN;
				*UCS_Len += 5;				

			}else if(sms_alarm_mail->temperature <= 999)
			{
				*UCS++ = LINE_SIGN;
				*UCS++ = NUM_UCS_MAP[sms_alarm_mail->temperature / 100];//百位;
				sms_alarm_mail->temperature %= 100;
				*UCS++ = NUM_UCS_MAP[sms_alarm_mail->temperature / 10];
				*UCS++ = NUM_UCS_MAP[sms_alarm_mail->temperature % 10];
				*UCS++ = UCS2_DU;
				*UCS++ = POUND_SIGN;
				*UCS_Len += 6;
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
	*/
}

void Send_Hex_Char_To_GR64(unsigned char *Hex_char, unsigned int Hex_len, unsigned int off_set)
{
	CPU_INT08U err;
	
	Hex_char += off_set;
	
	while(Hex_len--)
	{
		GR64_TX = HEX_CHAR_MAP[*Hex_char >> 4];
		OSSemPend(SEM_GR64_SEND_BYTE, 5, &err);
		GR64_TX = HEX_CHAR_MAP[*Hex_char++ & 0x0f];
		OSSemPend(SEM_GR64_SEND_BYTE, 5, &err);

	}
}

void Send_PDU_To_GR64(SMS_SEND_PDU_FRAME *sms_pdu, SMS_HEAD_6 *sms_head)
{

	/* SMSC头的发送
	 *  如果长度为0，只需要发送长度那个字节;
	 *  否则则发送全部SMSC头;
	 */
	if(sms_pdu->SMSC.SMSC_Length)
	{
		Send_Hex_Char_To_GR64(&(sms_pdu->SMSC.SMSC_Length), 1, 0);
		Send_Hex_Char_To_GR64(&(sms_pdu->SMSC.SMSC_Type_Of_Address), sms_pdu->SMSC.SMSC_Length, 0);
	}
	else
	{
		Send_Hex_Char_To_GR64(&(sms_pdu->SMSC.SMSC_Length), 1, 0);
	}

	/*
	 * 	发送TPDU 头;
	 */
	Send_Hex_Char_To_GR64(&(sms_pdu->TPDU.First_Octet), sizeof(sms_pdu->TPDU) - sizeof(sms_pdu->TPDU.TP_UD), 0);

	/* 
	 * 	发送短信数据;
	 */
 	
	if(sms_head->sms_numbers > 1)
	{
		Send_Hex_Char_To_GR64((unsigned char *)sms_head, sizeof(SMS_HEAD_6), 0);
		Send_Hex_Char_To_GR64(sms_pdu->TPDU.TP_UD, sms_pdu->TPDU.TP_UDL - sizeof(SMS_HEAD_6), (sms_head->sms_index - 1)*(140 - sizeof(SMS_HEAD_6)));
	}
	else
	{
		Send_Hex_Char_To_GR64(sms_pdu->TPDU.TP_UD, sms_pdu->TPDU.TP_UDL, 0);
	
	}

	/*
	 *	发送结束字符;
	*/
	Send_To_GR64("\x1A", 1);
}

