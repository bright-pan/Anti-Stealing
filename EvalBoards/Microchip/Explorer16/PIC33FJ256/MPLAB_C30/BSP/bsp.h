#ifndef BSP_H
#define BSP_H

/*
*********************************************************************************************************
*                                               Microchip PIC33
*                                            Board Support Package
*
*                                                    Micrium
*                                    (c) Copyright 2005, Micrium, Weston, FL
*                                              All Rights Reserved
*
*
* File : BSP.H
* By   : Eric Shufro
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                      OSCILLATOR FREQUENCIES
*********************************************************************************************************
*/

#define  CPU_PRIMARY_OSC_FRQ         4000000L                               /* Primary External Oscillator Frequency                */
#define  CPU_FRC_OSC_FRQ             7370000L                               /* Internal Fast Oscillator Frequency                   */
#define  CPU_SECONDARY_OSC_FRQ         32768L                               /* Secondary External Oscillator Frequency              */

/*
*********************************************************************************************************
*                                      OS TICK TIMER SELECTION
*********************************************************************************************************
*/

#define  BSP_OS_TMR_SEL                    2                                /* Select a timer for the OS Tick Interrupt (2 or 4)    */
#define  TIMER_INT_PRIO                    4                                /* Configure the timer to use interrupt priority 4      */
#define  PROBE_INT_PRIO                    4                                /* Configure UART2 Interrupts to use priority 4         */


/*
*********************************************************************************************************
*                                             IRON MOMERY OP-CODE
********************************************************************************************************
*/

#define IRON_WREN		0x06
#define IRON_WRDI		0x04
#define IRON_RDSR		0x05
#define IRON_WRSR		0x01
#define IRON_READ		0x03
#define IRON_WRITE		0x02
/*
*********************************************************************************************************
*                                             IRON MOMERY ADDRESS
********************************************************************************************************
*/
#define OFF_SET(addr, type, step)		((addr) + (step) * sizeof(type))
#define OFF_SET_OF(TYPE, MEMBER) 		((unsigned int) &((TYPE *)0)->MEMBER)



#define 	IRON_PRIMARY_DEVICE_NAME			0
#define 	IRON_SLAVE_DEVICE_NUMBERS			IRON_PRIMARY_DEVICE_NAME + DEVICE_NAME_MAX_LENGTH
#define	IRON_SLAVE_DEVICE_ID					IRON_SLAVE_DEVICE_NUMBERS + 1
#define	IRON_SLAVE_DEVICE_NAME				IRON_SLAVE_DEVICE_ID + SLAVE_DEVICE_MAX_NUMBERS
#define	IRON_SLAVE_DEVICE_HISTORY_ALARM		IRON_SLAVE_DEVICE_NAME + DEVICE_NAME_MAX_LENGTH * SLAVE_DEVICE_MAX_NUMBERS
#define	IRON_ALARM_TELEPHONE_NUMBERS		IRON_SLAVE_DEVICE_HISTORY_ALARM + sizeof(SMS_ALARM_FRAME) * SLAVE_DEVICE_MAX_NUMBERS
#define	IRON_ALARM_TELEPHONE					IRON_ALARM_TELEPHONE_NUMBERS + 1
#define	IRON_SERVICE_CENTER_ADDRESS			IRON_ALARM_TELEPHONE + ALARM_TELEPHONE_MAX_NUMBERS * ALARM_TELEPHONE_NUMBER_SIZE
#define	IRON_PASSWORD							IRON_SERVICE_CENTER_ADDRESS + ALARM_TELEPHONE_NUMBER_SIZE


#define 	EEPROM_DEVICE_INIT_PARAMATERS_START		0
#define 	EEPROM_DEVICE_INIT_PARAMATERS_END			\
	OFF_SET(EEPROM_DEVICE_INIT_PARAMATERS_START, DEVICE_INIT_PARAMATERS, 1)
			

/*
*********************************************************************************************************
*                                             DATATYPES
*********************************************************************************************************
*/


extern OS_EVENT *SEM_RS485_SEND_BYTE;
extern OS_EVENT *SEM_GR64_SEND_BYTE;

extern OS_EVENT *MUTEX_GR64;
extern OS_EVENT *MUTEX_RS485;

extern BUFFER GR64_buf;
extern BUFFER RS485_buf;

extern OS_EVENT *SEM_SMS_MSG_INDICATOR;

/*
*************************************************************************
*				扩展芯片数据类型
*************************************************************************
*/
typedef struct
{

unsigned RSE_232 :
    2;
    //RS232控制使能，0x01为高阻状态，0x02为发送使能, 接收使能；
    
unsigned DIANKONG_LIGHT:
    1; //从左到右第4个灯
    
unsigned GONGKONG_LIGHT:
    1; //从左到右第3个灯
    
unsigned BAODIAN_LIGHT :
    1; //从左到右第2个灯
    
unsigned COMM_LIGHT:
    1; //从左到右第1个灯
    
unsigned GPRS_POWER_CTRL :
    1;//GPRS电源控制
    
unsigned LCD_K :
    1;//LED背光控制
    
unsigned ALARM_LIGHT:
    1; //从左到右第5个灯
    
unsigned BAOJING_LIGHT :
    1; //从左到右第6个灯
    
unsigned LUNKONG_LIGHT :
    4; //从左到右第7 - 10个灯
    
unsigned GPRS_NETWORK:
    1;//GPRS
    
unsigned GPRS_POWER :
    1;//GPRS
    
} LEDBITS;//LED位域字结构类型

/*
*************************************************************************
*				扩展芯片数据类型
*************************************************************************
*/
typedef union
{
    unsigned char port[2];
    //定义两个端口，其中port[0]为PORTA,port[1]为PORTB;
    LEDBITS led_bits;//定义LED位域字结构;
} LED_CONTROL_WORD;//LED控制字结构类型;

typedef  void (*PFNCT)(void);

/*
*********************************************************************************************************
*                                             MACROS
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                       CHIP SPECIFIC MACROS
*********************************************************************************************************
*/
                                                                        /* OSCCON register bits                                     */
#define  XT_HS_EC_PLL_SEL           (CPU_INT16U)(3 <<  0)
#define  COSC_MASK                  (CPU_INT16U)(7 << 12)
#define  LOCK                       (CPU_INT16U)(1 <<  5)
#define  OSWEN                      (CPU_INT16U)(1 <<  0)
                                                                        /* CLKDIV register bits                                     */
#define  FRCDIV_MASK                (CPU_INT16U)(7 <<  8)
#define  PLLPOST_MASK               (CPU_INT16U)(3 <<  6)
#define  PLLPRE_MASK                (CPU_INT16U)(0x1F <<  0)
#define  PLLDIV_MASK                (CPU_INT16U)(0xFF <<  0)
                                                                        /* Timer Control register bits                              */
#define  TON                        (CPU_INT16U)(1 << 15)
#define  T32				(CPU_INT16U)(1 << 3)
                                                                        /* IPC1 Interrupt Priority register bits                    */
#define  T3IP_MASK                  (CPU_INT16U)(7 << 0)
                                                                        /* IPC5 Interrupt Priority register bits                    */
#define  T4IP_MASK                  (CPU_INT16U)(7 << 12)
                                                                        /* IPC7 Interrupt Priority register bits                    */
//#define  U2TXIP_MASK                (CPU_INT16U)(7 << 12)
//#define  U2RXIP_MASK                (CPU_INT16U)(7 <<  8)
                                                                        /* IEC0 Interrupt Enable register bits                      */
#define  T3IE                       (CPU_INT16U)(1 <<  8)
                                                                        /* IEC1 Interrupt Enable register bits                      */
#define  T4IE                       (CPU_INT16U)(1 << 11)
//#define  U2TXIE                     (CPU_INT16U)(1 << 15)
//#define  U2RXIE                     (CPU_INT16U)(1 << 14)
                                                                        /* IFS0 Interrupt Flag register bits                        */
#define  T3IF                       (CPU_INT16U)(1 <<  8)
                                                                        /* IFS1 Interrupt Flag register bits                        */
#define  T4IF                       (CPU_INT16U)(1 << 11)
//#define  U2TXIF                     (CPU_INT16U)(1 << 15)
//#define  U2RXIF                     (CPU_INT16U)(1 << 14)
                                                                        /* UxMODE register bits                                     */
//#define  UART_EN                    (CPU_INT16U)(1 << 15)
                                                                        /* UxSTA register  bits                                     */
//#define  UTXISEL                    (CPU_INT16U)(1 << 15)
//#define  UTXEN                      (CPU_INT16U)(1 << 10)
//#define  TRMT                       (CPU_INT16U)(1 <<  8)
//#define  URXDA                      (CPU_INT16U)(1 <<  0)

                                                                        /* System Control register bits                             */
#define  SWDTEN                     (CPU_INT16U)(1 <<  5)

                                                                        /* Interrupt Configuration register 1 bits                  */
#define  NSTDIS                     (CPU_INT16U)(1 << 15)


//===================管脚定义==========================

/****************************************

	按键管脚定义

****************************************/


//上按键（引脚48-RC14）
#define	UP_BUTTON			PORTCbits.RC14
#define UP_BUTTON_DIR		TRISCbits.TRISC14
//下按键（引脚49-RD1）
#define DOWN_BUTTON			PORTDbits.RD1
#define	DOWN_BUTTON_DIR		TRISDbits.TRISD1
//左按键（引脚50-RD2）
#define	LEFT_BUTTON			PORTDbits.RD2
#define	LEFT_BUTTON_DIR		TRISDbits.TRISD2
//右按键（引脚51-RD3）
#define	RIGHT_BUTTON		PORTDbits.RD3
#define	RIGHT_BUTTON_DIR	TRISDbits.TRISD3
//确认按键（引脚62-RG14）
#define ENTER_BUTTON		PORTGbits.RG14
#define	ENTER_BUTTON_DIR	TRISGbits.TRISG14

/****************************************

	状态量

****************************************/

//In sw state 1(PIN17-RB6)
#define insw1state		PORTBbits.RB6
#define insw1state_dir	TRISBbits.TRISB6
//In sw state 2(PIN18-RB7)
#define insw2state		PORTBbits.RB7
#define insw2state_dir	TRISBbits.TRISB7
//In sw state 3(PIN30-RB15)
#define insw3state		PORTBbits.RB15
#define insw3state_dir	TRISBbits.TRISB15
//In sw state 4(PIN29-RB14)
#define insw4state		PORTBbits.RB14
#define insw4state_dir	TRISBbits.TRISB14
/****************************************

	脉冲量

****************************************/
//In sw state 5(PIN21-RB8)
#define insw5state		PORTBbits.RB8
#define insw5state_dir	TRISBbits.TRISB8
//In sw state 6(PIN22-RB9)
#define insw6state		PORTBbits.RB9
#define insw6state_dir	TRISBbits.TRISB9
//In sw state 7(新增)(PIN37-RG2)
#define insw7state		PORTGbits.RG2
#define insw7state_dir	TRISGbits.TRISG2
//In sw state 8(新增)(PIN44-RD10)
#define insw8state		PORTDbits.RD10
#define insw8state_dir	TRISDbits.TRISD10

/*****************************************

	内置电表通讯

******************************************/
//发送使能（PIN63-RG12）(EN = 0, DIS = 1)
#define enableTxMeter 		PORTGbits.RG12
#define enableTxMeter_LAT 	LATGbits.LATG12
#define enableTxMeter_dir 	TRISGbits.TRISG12

//接收使能（PIN23-RB10）(EN = 0, DIS = 1)
#define enableRxMeter		PORTBbits.RB10
#define enableRxMeter_LAT	LATBbits.LATB10
#define enableRxMeter_dir	TRISBbits.TRISB10

/*****************************************

	RS485通讯

******************************************/

//CH0发送使能(DE=1)（PIN27-RB12）
#define ch0enablesend		PORTBbits.RB12
#define ch0enablesend_LAT	LATBbits.LATRB12
#define ch0enablesend_dir	TRISBbits.TRISB12

//CH0接收使能(RE=0)（PIN28-RB13）
#define ch0enablerec		PORTBbits.RB13
#define ch0enablerec_LAT	LATBbits.LATB13
#define ch0enablerec_dir	TRISBbits.TRISB13



/*****************************************

	RS485II通讯

******************************************/

//CH0接收使能(PIN35-RF6)(RE = 0)
#define ch1enablerec		PORTFbits.RF6
#define ch1enablerec_LAT	LATFbits.LATF6
#define ch1enablerec_dir	TRISFbits.TRISF6

//CH1发送使能(PIN36-RG3)(DE = 1)
#define ch1enablesend		PORTGbits.RG3
#define ch1enablesend_LAT	LATGbits.LATG3
#define ch1enablesend_dir	TRISGbits.TRISG3

/*****************************************

	红外通讯

******************************************/

//Enable infra send(PIN46-RD0)(DE = 1)
#define enableTxInfra		PORTDbits.RD0
#define enableTxInfra_LAT	LATDbits.LATD0
#define enableTxInfra_dir	TRISDbits.TRISD0

//Enable infra rec(PIN24-RB11)(RE=0)
#define enableRxInfra		PORTBbits.RB11
#define	enableRxInfra_LAT	LATBbits.LATB11
#define enableRxInfra_dir	TRISBbits.TRISB11

/*****************************************************************

	GR64模块管脚定义

*****************************************************************/

// GR64启动关闭信号           PIN64 RG13
#define GR64ONOFF            PORTGbits.RG13
#define GR64ONOFF_LAT        LATGbits.LATG13
#define GR64ONOFF_dir	     TRISGbits.TRISG13

// GR64 RING                PIN8 RG9
//  常态为高（1） 来短信维持50ms的低电平
#define GR64RING            PORTGbits.RG9
#define GR64RING_LAT        LATGbits.LATG9
#define GR64RING_dir	    TRISGbits.TRISG9

//  GR64 TX               Pin33 RF3
#define GR64TX              PORTFbits.RF3
#define GR64TX_LAT          LATFbits.LATF3
#define GR64TX_dir	        TRISFbits.TRISF3

//  GR64 RX                Pin34 RF2
#define GR64RX              PORTFbits.RF2
#define GR64RX_LAT          LATFbits.LATF2
#define GR64RX_dir	        TRISFbits.TRISF2


// GR64 DCD                PIN14 RB2
// 短消息状态以及 高位    TCP连通状态 低电平
#define GR64DCD            PORTBbits.RB2
#define GR64DCD_LAT        LATBbits.LATB2
#define GR64DCD_dir	       TRISBbits.TRISB2

// GR64 DTR                PIN13 RB3
//
#define GR64DTR            PORTBbits.RB3
#define GR64DTR_LAT        LATBbits.LATB3
#define GR64DTR_dir	       TRISBbits.TRISB3

// GR64 VIO GSM模块电平输出     PIN6 RG8
//
#define GR64_VIO           PORTGbits.RG8
#define GR64_VIO_dir       TRISGbits.TRISG8

/*****************************************************************

	LCD 液晶屏控制管脚定义

*****************************************************************/
// LCD RST              PIN61  RG0
#define CS	     	PORTGbits.RG0
#define CS_LAT     	LATGbits.LATG0
#define CS_DIR  	TRISGbits.TRISG0
// LCD  WR              PIN52  RD4
#define SID	     	PORTDbits.RD4
#define SID_LAT     	LATDbits.LATD4
#define SID_DIR       TRISDbits.TRISD4
// LCD  E               PIN53  RD5
#define SCK	      	PORTDbits.RD5
#define SCK_LAT      	LATDbits.LATD5
#define SCK_DIR        TRISDbits.TRISD5



/*****************************************************************

	FLASH 存储器和LED控制芯片管脚定义

*****************************************************************/

//LED扩展芯片片选信号管脚
#define LED_CS 		PORTGbits.RG6
#define LED_CS_LAT	LATGbits.LATG6
#define LED_CS_DIR	TRISGbits.TRISG6

//FLASH 256K片选信号管脚
#define SPICS_FLASH1		PORTDbits.RD7
#define SPICS_FLASH1_LAT	LATDbits.LATD7
#define SPICS_FLASH1_dir	TRISDbits.TRISD7

//FLASH 2M片选信号管脚

#define SPICS_FLASH2		PORTDbits.RD6
#define SPICS_FLASH2_LAT	LATDbits.LATD6
#define SPICS_FLASH2_dir	TRISDbits.TRISD6

//LED扩展芯片以及FLASH芯片时钟信号管脚
#define SPISCK		PORTFbits.RF0
#define SPISCK_LAT	LATFbits.LATF0
#define SPISCK_dir	TRISFbits.TRISF0


//写LED扩展芯片以及FLASH芯片管脚
#define SPISO		PORTFbits.RF1
#define SPISO_LAT	LATFbits.LATF1
#define SPISO_dir	TRISFbits.TRISF1

//读LED扩展芯片以及FLASH芯片管脚
#define SPISI       PORTGbits.RG1
#define SPISI_LAT   LATGbits.LATG1
#define SPISI_dir	TRISGbits.TRISG1


/*****************************************************************

	 铁电存储器32K

*****************************************************************/


//READ铁电管脚
#define FMSPISI       PORTGbits.RG15
#define FMSPISI_lat   LATGbits.LATG15
#define FMSPISI_dir	  TRISGbits.TRISG15
//write铁电管脚
#define FMSPISO       PORTCbits.RC1
#define FMSPISO_lat   LATCbits.LATC1
#define FMSPISO_dir	  TRISCbits.TRISC1
//铁电时序信号
#define FMSPISCK      PORTCbits.RC2
#define FMSPISCK_lat  LATCbits.LATC2
#define FMSPISCK_dir  TRISCbits.TRISC2
//铁电片选信号
#define FMSPICS       PORTCbits.RC13
#define FMSPICS_lat	  LATCbits.LATC13
#define FMSPICS_dir	  TRISCbits.TRISC13
/**********************************************************************

				寄存器定义

***********************************************************************/
#define GR64_TX 		U1TXREG
#define GR64_RX		U1RXREG

#define RS485_TX 	U2TXREG
#define RS485_RX	U2RXREG
/*
*********************************************************************************************************
*                                               MACRO'S
*********************************************************************************************************
*/
#define ENABLE_RS485_SEND() 		{ch0enablesend = 1; Nop(); ch0enablerec = 1;}
#define ENABLE_RS485_RECEIVE() 		{ch0enablesend = 0; Nop(); ch0enablerec = 0;}
#define CLOSE_RS485()				{ch0enablesend = 0; Nop(); ch0enablerec = 1;}

/*
*********************************************************************************************************
*                                       FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void        BSP_Init(void);
void        BSP_IntEn(CPU_INT08U IntCont, CPU_INT08U IntNum, CPU_INT08U IntPol, CPU_INT08U IntAct, PFNCT pfnct);
void        BSP_IntDis(CPU_INT08U IntCont, CPU_INT08U IntNum);
void        BSP_IntDisAll(void);

CPU_INT32U  BSP_CPU_ClkFrq(void);

/*
*********************************************************************************************************
*                                          LED SERVICES
*********************************************************************************************************
*/

void     LED_Init(void);
void     LED_On(CPU_INT08U led);
void     LED_Off(CPU_INT08U led);
void     LED_Toggle(CPU_INT08U led);

/*
*********************************************************************************************************
*                                          LED SERVICES
*********************************************************************************************************
*/
CPU_VOID led_config(CPU_VOID);
CPU_VOID update_to_led(const CPU_INT08U *data);
CPU_VOID led_write(CPU_INT16U opcode_add, CPU_INT08U data);

/*
*********************************************************************************************************
*                                          IRON SERVICES
*********************************************************************************************************
*/
/*
unsigned char *Iron_Read(unsigned int address, unsigned char *data, unsigned int len);
void Iron_Write(unsigned int address, unsigned char *data, unsigned int len);
*/
void EEPROM_init(void);

void EEPROM_write_byte(unsigned int address, unsigned char data);
unsigned char EEPROM_read_byte(unsigned int address);

unsigned char *EEPROM_read(unsigned int address, unsigned char *data, unsigned int len);
void EEPROM_write(unsigned int address, unsigned char *data, unsigned int len);


/*
*********************************************************************************************************
*                                          TICK SERVICES
*********************************************************************************************************
*/

void     Tmr_TickISR_Handler(void);

/*
*********************************************************************************************************
*                                      CONFIGURATION CHECKING
*********************************************************************************************************
*/

#if ((BSP_OS_TMR_SEL != 2) && (BSP_OS_TMR_SEL != 4))
#error "BSP_OS_TMR_SEL is illegally defined in bsp.h. Allowed values: 2 or 4"
#endif

#endif
