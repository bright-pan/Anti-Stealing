#include <includes.h>


#define EEPROM_ADDR	(0xA2)

#define EEPROM_WRITE	(EEPROM_ADDR & 0xfe)

#define EEPROM_READ	(EEPROM_ADDR | 0x01)


//发送开始标志;
#define I2C1_S()		(I2C1CONbits.SEN = 1)
//发送重启标志;
#define I2C1_RS()	(I2C1CONbits.RSEN = 1)
//发送停止标志;
#define I2C1_P()		(I2C1CONbits.PEN = 1)
//发送有效确认标志;
#define I2C1_A()		{\
						I2C1CONbits.ACKDT = 0;\
						I2C1CONbits.ACKEN = 1;\
					}
//发送无效确认标志;
#define I2C1_N()		{\
						I2C1CONbits.ACKDT = 1;\
						I2C1CONbits.ACKEN = 1;\
					}

#define I2C1_RC()		(I2C1CONbits.RCEN = 1)

void EEPROM_init(void)
{
	//初始化I2C寄存器;

	
	IFS1bits.MI2C1IF = 0;
	IPC4bits.MI2C1IP = 3;
	IEC1bits.MI2C1IE = 0;

	//初始化波特率;
	I2C1BRG = 95;//400KBPS;
	I2C1CONbits.A10M = 0;//7位地址;
	I2C1CONbits.I2CEN = 1;

	

}

void EEPROM_write_byte(unsigned int address, unsigned char data)
{
	unsigned char i = 100;
	I2C1_S();
	while(I2C1CONbits.SEN == 1);
	
	I2C1TRN = EEPROM_WRITE;
	
	while(I2C1STATbits.TRSTAT == 1);

	I2C1TRN = address >> 8;
	while(I2C1STATbits.TRSTAT == 1);

	I2C1TRN = address & 0xff;
	while(I2C1STATbits.TRSTAT == 1);

	I2C1TRN = data;
	while(I2C1STATbits.TRSTAT == 1);
	//asm(" REPEAT #4000 \n NOP");

	I2C1_P();
	while(I2C1CONbits.PEN == 1);

	while(i-- > 0)
	{
		asm(" REPEAT #4000 \n NOP");
	}
	
}


unsigned char EEPROM_read_byte(unsigned int address)
{
	unsigned char data = 0;
	
	I2C1_S();
	while(I2C1CONbits.SEN == 1);
	
	I2C1TRN = EEPROM_WRITE;
	while(I2C1STATbits.TRSTAT == 1);

	I2C1TRN = address >> 8;
	while(I2C1STATbits.TRSTAT == 1);

	I2C1TRN = address & 0xff;
	while(I2C1STATbits.TRSTAT == 1);
	
	I2C1_RS();
	while(I2C1CONbits.RSEN == 1);
	
	I2C1TRN = EEPROM_READ;
	while(I2C1STATbits.TRSTAT == 1);
	
	I2C1_RC();
	
	while(I2C1STATbits.RBF == 0);

	data = I2C1RCV;
	
	I2C1_N();
	while(I2C1CONbits.ACKEN == 1);

	I2C1_P();
	while(I2C1CONbits.PEN == 1);
	
	return data;	
}

void EEPROM_write(unsigned int address, unsigned char *data, unsigned int len)
{
	unsigned  char *data_bk = data;
	while(len--)
	{
		EEPROM_write_byte(address++, *data_bk++);
	}
}

unsigned char *EEPROM_read(unsigned int address, unsigned char *data, unsigned int len)
{
	unsigned char *data_bk = data;

	while(len--)
	{
		*data_bk++ = EEPROM_read_byte(address++);
	}
	return data_bk;
}
