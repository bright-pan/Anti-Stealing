/*
*********************************************************************************************************
*                                             Microchip dsPIC33FJ
*                                            Board Support Package
*
*                                                   Micrium
*                                    (c) Copyright 2005, Micrium, Weston, FL
*                                              All Rights Reserved
*
*
* File : BSP.C
* By   : Eric Shufro
*********************************************************************************************************
*/

#include <includes.h>

/*
*********************************************************************************************************
*                                       MPLAB CONFIGURATION MACROS
*********************************************************************************************************
*/

_FOSCSEL(FNOSC_PRIPLL);
_FOSC(POSCMD_XT & OSCIOFNC_ON & FCKSM_CSDCMD);
_FWDT(FWDTEN_OFF);
/*
*********************************************************************************************************
*                                              CONSTANTS
*********************************************************************************************************
*/

/*****************************************
*	 端口方向
******************************************/
#define INPUT	1
#define OUTPUT	0
/*****************************************
*	 校验方式
******************************************/
#define PARITY_NONE		0 //无校验
#define PARITY_EVEN		1 //偶校验
#define PARITY_ODD		2 //奇校验
/*****************************************
*	 时钟频率40MIPS
******************************************/
#define FCY	40000000L
/*
*********************************************************************************************************
*                                              VARIABLES
*********************************************************************************************************
*/
/*
*********************************************************************************************************
*                                              PROTOTYPES
*********************************************************************************************************
*/

static  void  BSP_PLL_Init(void);
static  void  Tmr_TickInit(void);
static  void  CPU_PIN_Init(void);
static  void  CPU_UART_Init(void);
//static  void Iron_Init(void);

/*
*********************************************************************************************************
*                                         BSP INITIALIZATION
*
* Description : This function should be called by your application code before you make use of any of the
*               functions found in this module.
*
* Arguments   : none
*********************************************************************************************************
*/

void  BSP_Init (void)
{
    	RCON    &= ~SWDTEN;                                           /* Ensure Watchdog disabled via IDE CONFIG bits and SW.     */

    	BSP_PLL_Init();                                                    /* Initialize the PLL */
    	CPU_PIN_Init();								/* 初始化CPU管脚 */
	CPU_UART_Init();							/* 初始化UART 接口 */
	//Iron_Init();									/* 初始化铁电存储器 */
	EEPROM_init();
    	Tmr_TickInit();                                                     /* Initialize the uC/OS-II tick interrupt */
}

/*
*********************************************************************************************************
*                                      BSP_PLL_Init()
*
* Description : This function configures and enables the PLL with the external oscillator
*               selected as the input clock to the PLL.
*
* Notes       : 1) The PLL output frequency is calculated by FIN * (M / (N1 * N2)).
*               2) FIN is the PLL input clock frequency, defined in bsp.h as
*                  CPU_PRIMARY_OSC_FR. This is the same as the external primary
*                  oscillator on the Explorer 16 Evaluation Board.
*               3) M is the desired PLL multiplier
*               4) N1 is the divider for FIN before FIN enters the PLL block (Pre-Divider)
*               5) N2 is the PLL output divider (Post-Divider)
*
* Summary     :    The PLL is configured as (8MHZ) * (40 / (2 * 2)) = 80MHZ
*                  The processor clock is (1/2) of the PLL output.
*                  Performance = 40 MIPS.
*********************************************************************************************************
*/

static  void  BSP_PLL_Init (void)
{
    PLLFBD   =     78;                                                  /* Set the Multiplier (M) to 40 (2 added automatically) 	*/
    CLKDIV   =      0;                                                  /* Clear the PLL Pre Divider bits, N1 = N2 = 2              */
}
/*
*********************************************************************************************************
*                                      CPU_PLL_Init()
*
* Description : CPU  管脚定义及初始化
* 
*********************************************************************************************************
*/
static  void  CPU_PIN_Init(void)
{
    /***************************************
    	关闭所有模块功能
    ****************************************/
    PMD1 = 0xcf1f;//能够使用T2,T3,I2C1,U1,U2模块功能，其余模块功能都关闭;
    PMD2 = 0xffff;
    PMD3 = 0xffff;
    
    
    
    /********************************************
    
    	GR64
    
    ********************************************/
    GR64_VIO_dir  = INPUT;      // 模块电平输出
    GR64DCD_dir   = INPUT; // 短消息状态以及 高位    TCP连通状态 低电平
    GR64RING_dir  = INPUT;//  常态为高（1） 来短信维持50ms的低电平
    GR64DTR_dir   = OUTPUT;
    GR64DTR_LAT   = 0;
    GR64ONOFF_dir = OUTPUT;
    GR64ONOFF_LAT = 1;
    
    /*****************************************
    
    通讯接口
    
    *****************************************/
	COMM_CS_DIR = INPUT;
	COMM_RS_DIR = OUTPUT;
	RS485_CS_DIR = OUTPUT;
	W433_CS_DIR = OUTPUT;
	RS485_CS_LAT = 1;//不工作
	W433_CS_LAT = 1;//不工作
//	COMM_RS_LAT = 1;

}

/*
*********************************************************************************************************
*                                      BSP_CPU_ClkFrq()

* Description : This function determines the CPU clock frequency (Fcy)
* Returns     : The CPU frequency in (HZ)
*********************************************************************************************************
*/

CPU_INT32U  BSP_CPU_ClkFrq (void)
{
    CPU_INT08U  Clk_Selected;
    CPU_INT08U  PLL_n1;
    CPU_INT08U  PLL_n2;
    CPU_INT16U  PLL_m;
    CPU_INT16U  FRC_Div;
    CPU_INT32U  CPU_Clk_Frq;


    PLL_m         =  (PLLFBD & PLLDIV_MASK) + 2;                        /* Get the Multiplier value                                 */
    PLL_n1        =  (CLKDIV & PLLPRE_MASK) + 2;                        /* Computer the Pre Divider value                           */
    PLL_n2        = ((CLKDIV & PLLPOST_MASK) >> 6);                     /* Get the Post Divider register value                      */
    PLL_n2        = ((PLL_n2 * 2) + 2);                                 /* Compute the Post Divider value                           */

    FRC_Div       = ((CLKDIV & FRCDIV_MASK) >> 8);                      /* Get the FRC Oscillator Divider register value            */
    FRC_Div       = ((1 << FRC_Div) * 2);                               /* Compute the FRC Divider value                            */

    Clk_Selected  =  (OSCCON & COSC_MASK) >> 12;                        /* Determine which clock source is currently selected       */

    switch (Clk_Selected) {
        case 0:                                                         /* Fast Oscillator (FRC) Selected                           */
        case 7:
             CPU_Clk_Frq   =   CPU_FRC_OSC_FRQ;                         /* Return the frequency of the internal fast oscillator     */
             break;

        case 1:                                                         /* Fast Oscillator (FRC) with PLL Selected                  */
             CPU_Clk_Frq   = ((CPU_FRC_OSC_FRQ  * PLL_m) /              /* Compute the PLL output frequency using the FRC as FIN    */
                              (FRC_Div * PLL_n1 * PLL_n2));
             break;

        case 2:                                                         /* Primary External Oscillator Selected                     */
             CPU_Clk_Frq   =   CPU_PRIMARY_OSC_FRQ;                     /* Return the frequency of the primary external oscillator  */
             break;

        case 3:                                                         /* Primary External Oscillator with PLL Selected            */
             CPU_Clk_Frq   = ((CPU_PRIMARY_OSC_FRQ * PLL_m) /           /* Compute the PLL output frq using the PRI EXT OSC as FIN  */
                              (PLL_n1 * PLL_n2));
             break;

        case 4:                                                         /* Secondary External Low Power Oscillator (SOSC) Selected  */
        case 5:                                                         /* Internal Low Power RC Oscillator Selected                */
             CPU_Clk_Frq   =   CPU_SECONDARY_OSC_FRQ;                   /* Return the frq of the external secondary Low Power OSC   */
             break;

        case 6:
             CPU_Clk_Frq = 0;                                           /* Return 0 for the Reserved clock setting                  */
             break;

        default:
             CPU_Clk_Frq = 0;                                           /* Return 0 if the clock source cannot be determined        */
             break;
    }

    CPU_Clk_Frq   /=  2;                                                /* Divide the final frq by 2, get the actual CPU Frq (Fcy)  */

    return (CPU_Clk_Frq);                                               /* Return the operating frequency                           */
}

/*
*********************************************************************************************************
*                                     DISABLE ALL INTERRUPTS
*
* Description : This function disables all interrupts from the interrupt controller.
*
* Arguments   : none
*********************************************************************************************************
*/

void  BSP_IntDisAll (void)
{
}

/*
*********************************************************************************************************
*                                         LED I/O INITIALIZATION
*
* Description : This function initializes the I/O Pins used by the onboard LEDs
*
* Arguments   : none
*
* Notes       : 1) Jumper JP2 on the Explorer 16 board must be connected to enable the onboard LEDs
*               2) JTAG must be DISABLED in order to utilize all of PORTA I/O Lines for LEDs
*********************************************************************************************************
*/

void  LED_Init (void)
{
                                                    /* Shut off all LEDs                                        */
}

/*
*********************************************************************************************************
*                                             LED ON
*
* Description : This function is used to control any or all the LEDs on the board.
*
* Arguments   : led    is the number of the LED to control
*                      0    indicates that you want ALL the LEDs to be ON
*                      1    turns ON LED1
*                      2    turns ON LED2
*                      ...
*                      8    turns ON LED8
*
* Notes       : 1) Jumper JP2 on the Explorer 16 board must be connected to enable the onboard LEDs
*********************************************************************************************************
*/

void  LED_On (CPU_INT08U led)
{

}

/*
*********************************************************************************************************
*                                             LED OFF
*
* Description : This function is used to control any or all the LEDs on the board.
*
* Arguments   : led    is the number of the LED to turn OFF
*                      0    indicates that you want ALL the LEDs to be OFF
*                      1    turns OFF LED1
*                      2    turns OFF LED2
*                      .
*                      8    turns OFF LED8
*
* Notes       : 1) Jumper JP2 on the Explorer 16 board must be connected to enable the onboard LEDs
*********************************************************************************************************
*/

void  LED_Off (CPU_INT08U led)
{

}

/*
*********************************************************************************************************
*                                             LED TOGGLE
*
* Description : This function is used to toggle any or all the LEDs on the board.
*
* Arguments   : led    is the number of the LED to control
*                      0    indicates that you want to toggle ALL the LEDs
*                      1    toggles LED1
*                      2    toggles LED2
*                      .
*                      8    toggles LED8
*
* Notes       : 1) Jumper JP2 on the Explorer 16 board must be connected to enable the onboard LEDs
*********************************************************************************************************
*/

void  LED_Toggle (CPU_INT08U led)
{

}

/*
*********************************************************************************************************
*                                       TICKER INITIALIZATION
*
* Description : This function is called to initialize uC/OS-II's tick source (typically a timer generating
*               interrupts every 1 to 100 mS).
*
* Arguments   : none
*
* Note(s)     : 1) The timer operates at a frequency of Fosc / 4
*               2) The timer resets to 0 after period register match interrupt is generated
*********************************************************************************************************
*/

static  void  Tmr_TickInit (void)
{
    CPU_INT32U  tmr_frq;
    CPU_INT32U  cnts;


    tmr_frq   =   BSP_CPU_ClkFrq();                                     /* Get the CPU Clock Frequency (Hz) (Fcy)                   */
    cnts      =   (tmr_frq / OS_TICKS_PER_SEC) - 1;                     /* Calaculate the number of timer ticks between interrupts  */

#if BSP_OS_TMR_SEL == 2
    T2CON     =   0;                                                    /* Use Internal Osc (Fcy), 16 bit mode, prescaler = 1  		*/
	T2CON  |= T32;
    TMR2      =   0;                                                    /* Start counting from 0 and clear the prescaler count      */
	TMR3  = 0;
    PR2       =   (CPU_INT16U)cnts;                                                 /* Set the period register                                  */
    PR3       =   (CPU_INT16U)(cnts >> 16);                                                 /* Set the period register                                  */	
    IPC2     &=  ~T3IP_MASK;                                            /* Clear all timer 2 interrupt priority bits                */
    IPC2     |=  (TIMER_INT_PRIO << 0);                                /* Set timer 2 to operate with an interrupt priority of 4   */
    IFS0     &=  ~T3IF;                                                 /* Clear the interrupt for timer 2                          */
    IEC0     |=   T3IE;                                                 /* Enable interrupts for timer 2                            */
    T2CON    |=   TON;                                                  /* Start the timer                                          */
#endif

#if BSP_OS_TMR_SEL == 4
    T4CON     =   0;                                                    /* Use Internal Osc (Fcy), 16 bit mode, prescaler = 1  		*/
    TMR4      =   0;                                                    /* Start counting from 0 and clear the prescaler count      */
    PR4       =   cnts;                                                 /* Set the period register                                  */
    IPC6     &=  ~T4IP_MASK;                                            /* Clear all timer 4 interrupt priority bits                */
    IPC6     |=  (TIMER_INT_PRIO << 12);                                /* Set timer 4 to operate with an interrupt priority of 4   */
    IFS1     &=  ~T4IF;                                                 /* Clear the interrupt for timer 4                          */
    IEC1     |=   T4IE;                                                 /* Enable interrupts for timer 4                            */
    T4CON    |=   TON;                                                  /* Start the timer                                          */
#endif
}

/*
*********************************************************************************************************
*                                     OS TICK INTERRUPT SERVICE ROUTINE
*
* Description : This function handles the timer interrupt that is used to generate TICKs for uC/OS-II.
*********************************************************************************************************
*/

void OS_Tick_ISR_Handler (void)
{
#if  BSP_OS_TMR_SEL == 2
    IFS0 &= ~T3IF;
#endif

#if  BSP_OS_TMR_SEL == 4
    IFS1 &= ~T41F;
#endif

    OSTimeTick();
}

/*
*********************************************************************************************************
*                                     UART1RX INTERRUPT SERVICE ROUTINE
*
* Description : GR64 接受中断例程
*********************************************************************************************************
*/

void Uart1_RxISRHandler(void)
{
	IFS0bits.U1RXIF = 0;
	if(U1STAbits.OERR == 1)
	{
		U1STAbits.OERR = 0;
		return;
	}
	PUTCH(GR64_RX, GR64_buf);
}

/*
*********************************************************************************************************
*                                     UART1TX INTERRUPT SERVICE ROUTINE
*
* Description : GR64 发送中断例程
*********************************************************************************************************
*/

void Uart1_TxISRHandler(void)
{
	IFS0bits.U1TXIF = 0;
	OSSemPost(SEM_GR64_SEND_BYTE);

}

/*
*********************************************************************************************************
*                                     UART2RX INTERRUPT SERVICE ROUTINE
*
* Description : RS485 接受中断例程
*********************************************************************************************************
*/

void Uart2_RxISRHandler(void)
{
    	IFS1bits.U2RXIF = 0;
	if(U2STAbits.OERR == 1)
	{
		U2STAbits.OERR = 0;
		return;
	}
	PUTCH(RS485_RX, RS485_buf);
}

/*
*********************************************************************************************************
*                                     UART2TX INTERRUPT SERVICE ROUTINE
*
* Description : RS485 发送中断例程
*********************************************************************************************************
*/

void Uart2_TxISRHandler(void)
{
    IFS1bits.U2TXIF = 0;
	OSSemPost(SEM_RS485_SEND_BYTE);
}

/*
*******************************************************************
*					扩展芯片操作函数
*******************************************************************
*/


void __attribute__((__interrupt__)) _DMACError(void)
{
	while(1)
	{
		Nop();
		Nop();
		Nop();
		Nop();
	};
}


void __attribute__((__interrupt__)) _AddressError(void)
{
	while(1)
	{
		Nop();
		Nop();
		Nop();
		Nop();
	};
}

void __attribute__((__interrupt__)) _StackError(void)
{
	while(1)
	{

		Nop();
		Nop();
		Nop();
		Nop();
	};
}


void __attribute__((__interrupt__)) _MathError(void)
{
	while(1)
	{
		Nop();
		Nop();
		Nop();
		Nop();
	};
}


//
// 初始化串口1
// unsigned int baudrate,     //波特率
// unsigned char parity_check  //校验方式
//

void InitUART1(unsigned int baudrate, unsigned char parity_check)
{
U1MODEbits.UARTEN = 0;
    /* clear IF flags */
    IFS0bits.U1RXIF = 0;
    IFS0bits.U1TXIF = 0;
    /* set priority */
    IPC2bits.U1RXIP = 6;
    //IPC3bits.U1TXIP = 5;
    
    /* enable/disable interrupt */
    IEC0bits.U1RXIE = 1;  //enable-1
    IEC0bits.U1TXIE = 1;  //disable-0
    // baud rate
    U1BRG = ((FCY / 16) / baudrate) - 1;
    
    U1MODE = 0xC000;
    U1STA = 0x8550;
    
    
    //Parity and Data Selection bits
    //  11 = 9-bit data, no parity
    //  10 = 8-bit data, odd parity
    //  01 = 8-bit data, even parity
    //  00 = 8-bit data, no parity
    
    if (parity_check == PARITY_EVEN)
        U1MODEbits.PDSEL = 1;
    else if (parity_check == PARITY_ODD)
        U1MODEbits.PDSEL = 2;
    else
        U1MODEbits.PDSEL = 0x00;

    return;
}

// 初始化串口2
//    unsigned int baudrate,      //波特率
//    unsigned char parity_check  //校验方式

void InitUART2(unsigned int baudrate, unsigned char parity_check)
{
    U2MODEbits.UARTEN = 0;
    /* clear IF flags */
    IFS1bits.U2RXIF = 0;
    IFS1bits.U2TXIF = 0;
    
    /* set priority */
    IPC7bits.U2RXIP = 5;
//  IPC7bits.U2TXIP = 5;

    /* enable/disable interrupt */
    IEC1bits.U2RXIE = 1;  //enable-1
    IEC1bits.U2TXIE = 1;  //disable-0
    // baud rate
    U2BRG = ((FCY / 16) / baudrate) - 1;
    U2MODE = 0xC000;
    U2STA = 0x8550;

    if (parity_check == PARITY_EVEN)
        U2MODEbits.PDSEL = 1;
    else if (parity_check == PARITY_ODD)
        U2MODEbits.PDSEL = 2;
    else
        U2MODEbits.PDSEL = 0x00;


    return;
}


/*
*********************************************************************************************************
*                                      CPU_UART_Init()
*
* Description : CPU的异步串口模块初始化
* 
*********************************************************************************************************
*/
static  void  CPU_UART_Init(void){

	InitUART1(19200, PARITY_NONE);
	//InitUART1(9600, PARITY_NONE);
	InitUART2(1200, PARITY_NONE);
}

void App_TimeTickHook (void){
	static unsigned char HIS_Value = 0;
	static unsigned char RT_Value = 0;
	
	RT_Value = (GR64RING == 1) ? 1 : 0;
	
	if(!HIS_Value &&   RT_Value)
		OSSemPost(SEM_SMS_MSG_INDICATOR);

	HIS_Value = RT_Value;

	if(COMM_CS == 1)
	{
		RS485_CS_LAT = 1;
		W433_CS_LAT = 0;
	}
	else
	{
		RS485_CS_LAT = 0;
		W433_CS_LAT = 1;
	}
}
/*

void Iron_Byte_Write(unsigned char data)
{
    unsigned char  bits_index;
    
    for (bits_index = 0; bits_index < 8; bits_index++)
    {
        FMSPISCK = 0;
        
        if (data&0x80)
            FMSPISO = 1;
        else
            FMSPISO = 0;
            
        FMSPISCK = 1;
        
        data <<= 1;
    }
    
}

unsigned char Iron_Byte_Read(void)
{
    unsigned char data = 0;
    unsigned char  bits_index;
    
    for (bits_index = 0; bits_index < 8; bits_index++)
    {
        FMSPISCK = 0;
        data <<= 1;
        FMSPISCK = 1;
        
        if (FMSPISI == 1)
        {
           data |= 0x01;
        }
        
    }
    return data;
}

unsigned char *Iron_Read(unsigned int address, unsigned char *data, unsigned int len)
{
    	unsigned char *data_bk = data;

    	FMSPICS = 0;
	
    	Iron_Byte_Write(IRON_READ);
    	Iron_Byte_Write(address >> 8);
 	Iron_Byte_Write(address);
	
	while(len--)
	{
		*data++ = Iron_Byte_Read();
	}
	
	FMSPICS = 1;

    	return data_bk;
}
void Iron_Write(unsigned int address, unsigned char *data, unsigned int len)
{

	FMSPICS = 0;
    
    	Iron_Byte_Write(IRON_WREN);
    
    	FMSPICS = 1;
	Nop();
	FMSPICS = 0;
    
   	Iron_Byte_Write(IRON_WRITE);
    	Iron_Byte_Write(address>> 8);
   	Iron_Byte_Write(address);
    
    	while(len--)
    	{
        	Iron_Byte_Write(*data++);
    	}
    
    	FMSPICS = 1;
    	Nop();
    	FMSPICS = 0;
    	Iron_Byte_Write(IRON_WRDI);
    	FMSPICS = 1;

}
static void Iron_Init(void)
{
	FMSPISO_dir = OUTPUT;
	Nop();
    	FMSPISCK_dir = OUTPUT;
	Nop();
	FMSPISI_dir = INPUT;
	Nop();
	FMSPICS_dir = OUTPUT;
	Nop();
    	FMSPISCK = 0;
	Nop();
    	FMSPICS = 1;
}
*/

