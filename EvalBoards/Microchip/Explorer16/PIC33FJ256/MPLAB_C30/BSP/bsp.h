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



/*****************************************

	通讯接口

******************************************/
//PIN45-RD11(RS485:0|W433:1)
#define COMM_CS		PORTDbits.RD11
#define COMM_CS_LAT	LATDbits.LATD11
#define COMM_CS_DIR	TRISDbits.TRISD11

//RS484 CS PIN50-RD2
#define RS485_CS		PORTDbits.RD2
#define RS485_CS_LAT	LATDbits.LATD2
#define RS485_CS_DIR	TRISDbits.TRISD2
//W433 CS PIN51-RD3
#define W433_CS			PORTDbits.RD3
#define W433_CS_LAT	LATDbits.LATD3
#define W433_CS_DIR		TRISDbits.TRISD3

//COMM 使能(S:1|R	:0)（PIN49-RD1）
#define COMM_RS			PORTDbits.RD1
#define COMM_RS_LAT	LATDbits.LATD1
#define COMM_RS_DIR	TRISDbits.TRISD1



/*****************************************************************

	GR64模块管脚定义

*****************************************************************/

// GR64启动关闭信号           PIN64 RG13
#define GR64ONOFF            PORTGbits.RG13
#define GR64ONOFF_LAT        LATGbits.LATG13
#define GR64ONOFF_dir	     TRISGbits.TRISG13

// GR64 RING                PIN2 RC1
//  常态为高（1） 来短信维持50ms的低电平
#define GR64RING            PORTCbits.RC1
#define GR64RING_LAT        LATCbits.LATC1
#define GR64RING_dir	    TRISCbits.TRISC1

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

// GR64 VIO GSM模块电平输出     PIN1 RG15
//
#define GR64_VIO           PORTGbits.RG15
#define GR64_VIO_dir       TRISGbits.TRISG15

// GR64 RUNNING LED  PIN16 RB0 (EN:0)
#define GR64_RUNNING_LED	PORTBbits.RB0
#define GR64_RUNNING_LED_LAT	LATBbits.LATB0
#define GR64_RUNNING_LED_DIR	TRISBbits.TRISB0

// GR64 DCD LED  PIN15 RB1 (EN:0)
#define GR64_DCD_LED	PORTBbits.RB1
#define GR64_DCD_LED_LAT	LATBbits.LATB1
#define GR64_DCD_LED_DIR	TRISBbits.TRISB1


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
#define ENABLE_COMM_SEND() 		{COMM_RS_LAT = 1;}
#define ENABLE_COMM_RECEIVE() 		{COMM_RS_LAT = 0;}
#define CLOSE_COMM()				{RS485_CS_LAT = 1;W433_CS_LAT=1;}

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
