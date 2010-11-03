/*-------------------------------------------------------------------------
 * MPLAB-Cxx  dsPIC33FJ256GP506 processor header
 *
 * (c) Copyright 1999-2007 Microchip Technology, All rights reserved
 *-------------------------------------------------------------------------*/

#ifndef __dsPIC33FJ256GP506__
#error "Include file does not match processor setting"
#endif

#ifndef __33FJ256GP506_H
#define __33FJ256GP506_H

extern volatile unsigned int  WREG0 __attribute__((__sfr__, __deprecated__, __unsafe__));
extern volatile unsigned int  WREG1 __attribute__((__sfr__, __deprecated__, __unsafe__));
extern volatile unsigned int  WREG2 __attribute__((__sfr__, __deprecated__, __unsafe__));
extern volatile unsigned int  WREG3 __attribute__((__sfr__, __deprecated__, __unsafe__));
extern volatile unsigned int  WREG4 __attribute__((__sfr__, __deprecated__, __unsafe__));
extern volatile unsigned int  WREG5 __attribute__((__sfr__, __deprecated__, __unsafe__));
extern volatile unsigned int  WREG6 __attribute__((__sfr__, __deprecated__, __unsafe__));
extern volatile unsigned int  WREG7 __attribute__((__sfr__, __deprecated__, __unsafe__));
extern volatile unsigned int  WREG8 __attribute__((__sfr__, __deprecated__, __unsafe__));
extern volatile unsigned int  WREG9 __attribute__((__sfr__, __deprecated__, __unsafe__));
extern volatile unsigned int  WREG10 __attribute__((__sfr__, __deprecated__, __unsafe__));
extern volatile unsigned int  WREG11 __attribute__((__sfr__, __deprecated__, __unsafe__));
extern volatile unsigned int  WREG12 __attribute__((__sfr__, __deprecated__, __unsafe__));
extern volatile unsigned int  WREG13 __attribute__((__sfr__, __deprecated__, __unsafe__));
extern volatile unsigned int  WREG14 __attribute__((__sfr__, __deprecated__, __unsafe__));
extern volatile unsigned int  WREG15 __attribute__((__sfr__, __deprecated__, __unsafe__));
extern volatile unsigned int  SPLIM __attribute__((__sfr__));
extern volatile unsigned int  ACCAL __attribute__((__sfr__));
extern volatile unsigned int  ACCAH __attribute__((__sfr__));
extern volatile unsigned char ACCAU __attribute__((__sfr__));
extern volatile unsigned int  ACCBL __attribute__((__sfr__));
extern volatile unsigned int  ACCBH __attribute__((__sfr__));
extern volatile unsigned char ACCBU __attribute__((__sfr__));
extern volatile unsigned int  PCL __attribute__((__sfr__));
extern volatile unsigned char PCH __attribute__((__sfr__));
extern volatile unsigned char TBLPAG __attribute__((__sfr__));
extern volatile unsigned char PSVPAG __attribute__((__sfr__));
extern volatile unsigned int  RCOUNT __attribute__((__sfr__));
extern volatile unsigned int  DCOUNT __attribute__((__sfr__));
extern volatile unsigned int  DOSTARTL __attribute__((__sfr__));
extern volatile unsigned int  DOSTARTH __attribute__((__sfr__));
extern volatile unsigned int  DOENDL __attribute__((__sfr__));
extern volatile unsigned int  DOENDH __attribute__((__sfr__));
extern volatile unsigned int  SR __attribute__((__sfr__));

__extension__ typedef struct tagSRBITS
{
    union
    {
    
        struct
        {
        
unsigned C:
            1;
            
unsigned Z:
            1;
            
unsigned OV:
            1;
            
unsigned N:
            1;
            
unsigned RA:
            1;
            
unsigned IPL:
            3;
            
unsigned DC:
            1;
            
unsigned DA:
            1;
            
unsigned SAB:
            1;
            
unsigned OAB:
            1;
            
unsigned SB:
            1;
            
unsigned SA:
            1;
            
unsigned OB:
            1;
            
unsigned OA:
            1;
        };
        
        struct
        {
        
unsigned :
            5;
            
unsigned IPL0:
            1;
            
unsigned IPL1:
            1;
            
unsigned IPL2:
            1;
        };
    };
} SRBITS;

extern volatile SRBITS SRbits __attribute__((__sfr__));

extern volatile unsigned int  CORCON __attribute__((__sfr__));

__extension__ typedef struct tagCORCONBITS
{
    union
    {
    
        struct
        {
        
unsigned IF:
            1;
            
unsigned RND:
            1;
            
unsigned PSV:
            1;
            
unsigned IPL3:
            1;
            
unsigned ACCSAT:
            1;
            
unsigned SATDW:
            1;
            
unsigned SATB:
            1;
            
unsigned SATA:
            1;
            
unsigned DL:
            3;
            
unsigned EDT:
            1;
            
unsigned US:
            1;
        };
        
        struct
        {
        
unsigned :
            8;
            
unsigned DL0:
            1;
            
unsigned DL1:
            1;
            
unsigned DL2:
            1;
        };
    };
} CORCONBITS;

extern volatile CORCONBITS CORCONbits __attribute__((__sfr__));

extern volatile unsigned int  MODCON __attribute__((__sfr__));

__extension__ typedef struct tagMODCONBITS
{
    union
    {
    
        struct
        {
        
unsigned XWM:
            4;
            
unsigned YWM:
            4;
            
unsigned BWM:
            4;
            
unsigned :
            2;
            
unsigned YMODEN:
            1;
            
unsigned XMODEN:
            1;
        };
        
        struct
        {
        
unsigned XWM0:
            1;
            
unsigned XWM1:
            1;
            
unsigned XWM2:
            1;
            
unsigned XWM3:
            1;
            
unsigned YWM0:
            1;
            
unsigned YWM1:
            1;
            
unsigned YWM2:
            1;
            
unsigned YWM3:
            1;
            
unsigned BWM0:
            1;
            
unsigned BWM1:
            1;
            
unsigned BWM2:
            1;
            
unsigned BWM3:
            1;
        };
    };
} MODCONBITS;

extern volatile MODCONBITS MODCONbits __attribute__((__sfr__));

extern volatile unsigned int  XMODSRT __attribute__((__sfr__));
extern volatile unsigned int  XMODEND __attribute__((__sfr__));
extern volatile unsigned int  YMODSRT __attribute__((__sfr__));
extern volatile unsigned int  YMODEND __attribute__((__sfr__));
extern volatile unsigned int  XBREV __attribute__((__sfr__));

__extension__ typedef struct tagXBREVBITS
{
    union
    {
    
        struct
        {
        
unsigned XB:
            15;
            
unsigned BREN:
            1;
        };
        
        struct
        {
        
unsigned XB0:
            1;
            
unsigned XB1:
            1;
            
unsigned XB2:
            1;
            
unsigned XB3:
            1;
            
unsigned XB4:
            1;
            
unsigned XB5:
            1;
            
unsigned XB6:
            1;
            
unsigned XB7:
            1;
            
unsigned XB8:
            1;
            
unsigned XB9:
            1;
            
unsigned XB10:
            1;
            
unsigned XB11:
            1;
            
unsigned XB12:
            1;
            
unsigned XB13:
            1;
            
unsigned XB14:
            1;
        };
    };
} XBREVBITS;

extern volatile XBREVBITS XBREVbits __attribute__((__sfr__));

extern volatile unsigned int  DISICNT __attribute__((__sfr__));
extern volatile unsigned int  CNEN1 __attribute__((__sfr__));

typedef struct tagCNEN1BITS
{

unsigned CN0IE:
    1;
    
unsigned CN1IE:
    1;
    
unsigned CN2IE:
    1;
    
unsigned CN3IE:
    1;
    
unsigned CN4IE:
    1;
    
unsigned CN5IE:
    1;
    
unsigned CN6IE:
    1;
    
unsigned CN7IE:
    1;
    
unsigned CN8IE:
    1;
    
unsigned CN9IE:
    1;
    
unsigned CN10IE:
    1;
    
unsigned CN11IE:
    1;
    
unsigned CN12IE:
    1;
    
unsigned CN13IE:
    1;
    
unsigned CN14IE:
    1;
    
unsigned CN15IE:
    1;
} CNEN1BITS;

extern volatile CNEN1BITS CNEN1bits __attribute__((__sfr__));

extern volatile unsigned int  CNEN2 __attribute__((__sfr__));

typedef struct tagCNEN2BITS
{

unsigned CN16IE:
    1;
    
unsigned CN17IE:
    1;
    
unsigned CN18IE:
    1;
} CNEN2BITS;

extern volatile CNEN2BITS CNEN2bits __attribute__((__sfr__));

extern volatile unsigned int  CNPU1 __attribute__((__sfr__));

typedef struct tagCNPU1BITS
{

unsigned CN0PUE:
    1;
    
unsigned CN1PUE:
    1;
    
unsigned CN2PUE:
    1;
    
unsigned CN3PUE:
    1;
    
unsigned CN4PUE:
    1;
    
unsigned CN5PUE:
    1;
    
unsigned CN6PUE:
    1;
    
unsigned CN7PUE:
    1;
    
unsigned CN8PUE:
    1;
    
unsigned CN9PUE:
    1;
    
unsigned CN10PUE:
    1;
    
unsigned CN11PUE:
    1;
    
unsigned CN12PUE:
    1;
    
unsigned CN13PUE:
    1;
    
unsigned CN14PUE:
    1;
    
unsigned CN15PUE:
    1;
} CNPU1BITS;

extern volatile CNPU1BITS CNPU1bits __attribute__((__sfr__));

extern volatile unsigned int  CNPU2 __attribute__((__sfr__));

typedef struct tagCNPU2BITS
{

unsigned CN16PUE:
    1;
    
unsigned CN17PUE:
    1;
    
unsigned CN18PUE:
    1;
} CNPU2BITS;

extern volatile CNPU2BITS CNPU2bits __attribute__((__sfr__));

extern volatile unsigned int  INTCON1 __attribute__((__sfr__));

typedef struct tagINTCON1BITS
{

unsigned :
    1;
    
unsigned OSCFAIL:
    1;
    
unsigned STKERR:
    1;
    
unsigned ADDRERR:
    1;
    
unsigned MATHERR:
    1;
    
unsigned DMACERR:
    1;
    
unsigned DIV0ERR:
    1;
    
unsigned SFTACERR:
    1;
    
unsigned COVTE:
    1;
    
unsigned OVBTE:
    1;
    
unsigned OVATE:
    1;
    
unsigned COVBERR:
    1;
    
unsigned COVAERR:
    1;
    
unsigned OVBERR:
    1;
    
unsigned OVAERR:
    1;
    
unsigned NSTDIS:
    1;
} INTCON1BITS;

extern volatile INTCON1BITS INTCON1bits __attribute__((__sfr__));

extern volatile unsigned int  INTCON2 __attribute__((__sfr__));

typedef struct tagINTCON2BITS
{

unsigned INT0EP:
    1;
    
unsigned INT1EP:
    1;
    
unsigned INT2EP:
    1;
    
unsigned INT3EP:
    1;
    
unsigned INT4EP:
    1;
    
unsigned :
    9;
    
unsigned DISI:
    1;
    
unsigned ALTIVT:
    1;
} INTCON2BITS;

extern volatile INTCON2BITS INTCON2bits __attribute__((__sfr__));

extern volatile unsigned int  IFS0 __attribute__((__sfr__));

typedef struct tagIFS0BITS
{

unsigned INT0IF:
    1;
    
unsigned IC1IF:
    1;
    
unsigned OC1IF:
    1;
    
unsigned T1IF:
    1;
    
unsigned DMA0IF:
    1;
    
unsigned IC2IF:
    1;
    
unsigned OC2IF:
    1;
    
unsigned T2IF:
    1;
    
unsigned T3IF:
    1;
    
unsigned SPI1EIF:
    1;
    
unsigned SPI1IF:
    1;
    
unsigned U1RXIF:
    1;
    
unsigned U1TXIF:
    1;
    
unsigned AD1IF:
    1;
    
unsigned DMA1IF:
    1;
} IFS0BITS;

extern volatile IFS0BITS IFS0bits __attribute__((__sfr__));

extern volatile unsigned int  IFS1 __attribute__((__sfr__));

__extension__ typedef struct tagIFS1BITS
{
    union
    {
    
        struct
        {
        
unsigned SI2C1IF:
            1;
            
unsigned MI2C1IF:
            1;
            
unsigned :
            1;
            
unsigned CNIF:
            1;
            
unsigned INT1IF:
            1;
            
unsigned :
            1;
            
unsigned IC7IF:
            1;
            
unsigned IC8IF:
            1;
            
unsigned DMA2IF:
            1;
            
unsigned OC3IF:
            1;
            
unsigned OC4IF:
            1;
            
unsigned T4IF:
            1;
            
unsigned T5IF:
            1;
            
unsigned INT2IF:
            1;
            
unsigned U2RXIF:
            1;
            
unsigned U2TXIF:
            1;
        };
        
        struct
        {
        
unsigned SI2CIF:
            1;
        };
    };
} IFS1BITS;

extern volatile IFS1BITS IFS1bits __attribute__((__sfr__));

extern volatile unsigned int  IFS2 __attribute__((__sfr__));

typedef struct tagIFS2BITS
{

unsigned SPI2EIF:
    1;
    
unsigned SPI2IF:
    1;
    
unsigned C1RXIF:
    1;
    
unsigned C1IF:
    1;
    
unsigned DMA3IF:
    1;
    
unsigned IC3IF:
    1;
    
unsigned IC4IF:
    1;
    
unsigned IC5IF:
    1;
    
unsigned IC6IF:
    1;
    
unsigned OC5IF:
    1;
    
unsigned OC6IF:
    1;
    
unsigned OC7IF:
    1;
    
unsigned OC8IF:
    1;
    
unsigned :
    1;
    
unsigned DMA4IF:
    1;
    
unsigned T6IF:
    1;
} IFS2BITS;

extern volatile IFS2BITS IFS2bits __attribute__((__sfr__));

extern volatile unsigned int  IFS3 __attribute__((__sfr__));

typedef struct tagIFS3BITS
{

unsigned T7IF:
    1;
    
unsigned SI2C2IF:
    1;
    
unsigned MI2C2IF:
    1;
    
unsigned T8IF:
    1;
    
unsigned T9IF:
    1;
    
unsigned INT3IF:
    1;
    
unsigned INT4IF:
    1;
    
unsigned :
    4;
    
unsigned DCIEIF:
    1;
    
unsigned DCIIF:
    1;
    
unsigned DMA5IF:
    1;
} IFS3BITS;

extern volatile IFS3BITS IFS3bits __attribute__((__sfr__));

extern volatile unsigned int  IFS4 __attribute__((__sfr__));

typedef struct tagIFS4BITS
{

unsigned :
    1;
    
unsigned U1EIF:
    1;
    
unsigned U2EIF:
    1;
    
unsigned :
    1;
    
unsigned DMA6IF:
    1;
    
unsigned DMA7IF:
    1;
    
unsigned C1TXIF:
    1;
} IFS4BITS;

extern volatile IFS4BITS IFS4bits __attribute__((__sfr__));

extern volatile unsigned int  IEC0 __attribute__((__sfr__));

typedef struct tagIEC0BITS
{

unsigned INT0IE:
    1;
    
unsigned IC1IE:
    1;
    
unsigned OC1IE:
    1;
    
unsigned T1IE:
    1;
    
unsigned DMA0IE:
    1;
    
unsigned IC2IE:
    1;
    
unsigned OC2IE:
    1;
    
unsigned T2IE:
    1;
    
unsigned T3IE:
    1;
    
unsigned SPI1EIE:
    1;
    
unsigned SPI1IE:
    1;
    
unsigned U1RXIE:
    1;
    
unsigned U1TXIE:
    1;
    
unsigned AD1IE:
    1;
    
unsigned DMA1IE:
    1;
} IEC0BITS;

extern volatile IEC0BITS IEC0bits __attribute__((__sfr__));

extern volatile unsigned int  IEC1 __attribute__((__sfr__));

__extension__ typedef struct tagIEC1BITS
{
    union
    {
    
        struct
        {
        
unsigned SI2C1IE:
            1;
            
unsigned MI2C1IE:
            1;
            
unsigned :
            1;
            
unsigned CNIE:
            1;
            
unsigned INT1IE:
            1;
            
unsigned :
            1;
            
unsigned IC7IE:
            1;
            
unsigned IC8IE:
            1;
            
unsigned DMA2IE:
            1;
            
unsigned OC3IE:
            1;
            
unsigned OC4IE:
            1;
            
unsigned T4IE:
            1;
            
unsigned T5IE:
            1;
            
unsigned INT2IE:
            1;
            
unsigned U2RXIE:
            1;
            
unsigned U2TXIE:
            1;
        };
        
        struct
        {
        
unsigned SI2CIE:
            1;
        };
    };
} IEC1BITS;

extern volatile IEC1BITS IEC1bits __attribute__((__sfr__));

extern volatile unsigned int  IEC2 __attribute__((__sfr__));

typedef struct tagIEC2BITS
{

unsigned SPI2EIE:
    1;
    
unsigned SPI2IE:
    1;
    
unsigned C1RXIE:
    1;
    
unsigned C1IE:
    1;
    
unsigned DMA3IE:
    1;
    
unsigned IC3IE:
    1;
    
unsigned IC4IE:
    1;
    
unsigned IC5IE:
    1;
    
unsigned IC6IE:
    1;
    
unsigned OC5IE:
    1;
    
unsigned OC6IE:
    1;
    
unsigned OC7IE:
    1;
    
unsigned OC8IE:
    1;
    
unsigned :
    1;
    
unsigned DMA4IE:
    1;
    
unsigned T6IE:
    1;
} IEC2BITS;

extern volatile IEC2BITS IEC2bits __attribute__((__sfr__));

extern volatile unsigned int  IEC3 __attribute__((__sfr__));

typedef struct tagIEC3BITS
{

unsigned T7IE:
    1;
    
unsigned SI2C2IE:
    1;
    
unsigned MI2C2IE:
    1;
    
unsigned T8IE:
    1;
    
unsigned T9IE:
    1;
    
unsigned INT3IE:
    1;
    
unsigned INT4IE:
    1;
    
unsigned :
    4;
    
unsigned DCIEIE:
    1;
    
unsigned DCIIE:
    1;
    
unsigned DMA5IE:
    1;
} IEC3BITS;

extern volatile IEC3BITS IEC3bits __attribute__((__sfr__));

extern volatile unsigned int  IEC4 __attribute__((__sfr__));

typedef struct tagIEC4BITS
{

unsigned :
    1;
    
unsigned U1EIE:
    1;
    
unsigned U2EIE:
    1;
    
unsigned :
    1;
    
unsigned DMA6IE:
    1;
    
unsigned DMA7IE:
    1;
    
unsigned C1TXIE:
    1;
} IEC4BITS;

extern volatile IEC4BITS IEC4bits __attribute__((__sfr__));

extern volatile unsigned int  IPC0 __attribute__((__sfr__));

__extension__ typedef struct tagIPC0BITS
{
    union
    {
    
        struct
        {
        
unsigned INT0IP:
            3;
            
unsigned :
            1;
            
unsigned IC1IP:
            3;
            
unsigned :
            1;
            
unsigned OC1IP:
            3;
            
unsigned :
            1;
            
unsigned T1IP:
            3;
        };
        
        struct
        {
        
unsigned INT0IP0:
            1;
            
unsigned INT0IP1:
            1;
            
unsigned INT0IP2:
            1;
            
unsigned :
            1;
            
unsigned IC1IP0:
            1;
            
unsigned IC1IP1:
            1;
            
unsigned IC1IP2:
            1;
            
unsigned :
            1;
            
unsigned OC1IP0:
            1;
            
unsigned OC1IP1:
            1;
            
unsigned OC1IP2:
            1;
            
unsigned :
            1;
            
unsigned T1IP0:
            1;
            
unsigned T1IP1:
            1;
            
unsigned T1IP2:
            1;
        };
    };
} IPC0BITS;

extern volatile IPC0BITS IPC0bits __attribute__((__sfr__));

extern volatile unsigned int  IPC1 __attribute__((__sfr__));

__extension__ typedef struct tagIPC1BITS
{
    union
    {
    
        struct
        {
        
unsigned DMA0IP:
            3;
            
unsigned :
            1;
            
unsigned IC2IP:
            3;
            
unsigned :
            1;
            
unsigned OC2IP:
            3;
            
unsigned :
            1;
            
unsigned T2IP:
            3;
        };
        
        struct
        {
        
unsigned DMA0IP0:
            1;
            
unsigned DMA0IP1:
            1;
            
unsigned DMA0IP2:
            1;
            
unsigned :
            1;
            
unsigned IC2IP0:
            1;
            
unsigned IC2IP1:
            1;
            
unsigned IC2IP2:
            1;
            
unsigned :
            1;
            
unsigned OC2IP0:
            1;
            
unsigned OC2IP1:
            1;
            
unsigned OC2IP2:
            1;
            
unsigned :
            1;
            
unsigned T2IP0:
            1;
            
unsigned T2IP1:
            1;
            
unsigned T2IP2:
            1;
        };
    };
} IPC1BITS;

extern volatile IPC1BITS IPC1bits __attribute__((__sfr__));

extern volatile unsigned int  IPC2 __attribute__((__sfr__));

__extension__ typedef struct tagIPC2BITS
{
    union
    {
    
        struct
        {
        
unsigned T3IP:
            3;
            
unsigned :
            1;
            
unsigned SPI1EIP:
            3;
            
unsigned :
            1;
            
unsigned SPI1IP:
            3;
            
unsigned :
            1;
            
unsigned U1RXIP:
            3;
        };
        
        struct
        {
        
unsigned T3IP0:
            1;
            
unsigned T3IP1:
            1;
            
unsigned T3IP2:
            1;
            
unsigned :
            1;
            
unsigned SPI1EIP0:
            1;
            
unsigned SPI1EIP1:
            1;
            
unsigned SPI1EIP2:
            1;
            
unsigned :
            1;
            
unsigned SPI1IP0:
            1;
            
unsigned SPI1IP1:
            1;
            
unsigned SPI1IP2:
            1;
            
unsigned :
            1;
            
unsigned U1RXIP0:
            1;
            
unsigned U1RXIP1:
            1;
            
unsigned U1RXIP2:
            1;
        };
    };
} IPC2BITS;

extern volatile IPC2BITS IPC2bits __attribute__((__sfr__));

extern volatile unsigned int  IPC3 __attribute__((__sfr__));

__extension__ typedef struct tagIPC3BITS
{
    union
    {
    
        struct
        {
        
unsigned U1TXIP:
            3;
            
unsigned :
            1;
            
unsigned AD1IP:
            3;
            
unsigned :
            1;
            
unsigned DMA1IP:
            3;
        };
        
        struct
        {
        
unsigned U1TXIP0:
            1;
            
unsigned U1TXIP1:
            1;
            
unsigned U1TXIP2:
            1;
            
unsigned :
            1;
            
unsigned AD1IP0:
            1;
            
unsigned AD1IP1:
            1;
            
unsigned AD1IP2:
            1;
            
unsigned :
            1;
            
unsigned DMA1IP0:
            1;
            
unsigned DMA1IP1:
            1;
            
unsigned DMA1IP2:
            1;
        };
    };
} IPC3BITS;

extern volatile IPC3BITS IPC3bits __attribute__((__sfr__));

extern volatile unsigned int  IPC4 __attribute__((__sfr__));

__extension__ typedef struct tagIPC4BITS
{
    union
    {
    
        struct
        {
        
unsigned SI2C1IP:
            3;
            
unsigned :
            1;
            
unsigned MI2C1IP:
            3;
            
unsigned :
            5;
            
unsigned CNIP:
            3;
        };
        
        struct
        {
        
unsigned SI2C1IP0:
            1;
            
unsigned SI2C1IP1:
            1;
            
unsigned SI2C1IP2:
            1;
            
unsigned :
            1;
            
unsigned MI2C1IP0:
            1;
            
unsigned MI2C1IP1:
            1;
            
unsigned MI2C1IP2:
            1;
            
unsigned :
            5;
            
unsigned CNIP0:
            1;
            
unsigned CNIP1:
            1;
            
unsigned CNIP2:
            1;
        };
    };
} IPC4BITS;

extern volatile IPC4BITS IPC4bits __attribute__((__sfr__));

extern volatile unsigned int  IPC5 __attribute__((__sfr__));

__extension__ typedef struct tagIPC5BITS
{
    union
    {
    
        struct
        {
        
unsigned INT1IP:
            3;
            
unsigned :
            5;
            
unsigned IC7IP:
            3;
            
unsigned :
            1;
            
unsigned IC8IP:
            3;
        };
        
        struct
        {
        
unsigned INT1IP0:
            1;
            
unsigned INT1IP1:
            1;
            
unsigned INT1IP2:
            1;
            
unsigned :
            5;
            
unsigned IC7IP0:
            1;
            
unsigned IC7IP1:
            1;
            
unsigned IC7IP2:
            1;
            
unsigned :
            1;
            
unsigned IC8IP0:
            1;
            
unsigned IC8IP1:
            1;
            
unsigned IC8IP2:
            1;
        };
    };
} IPC5BITS;

extern volatile IPC5BITS IPC5bits __attribute__((__sfr__));

extern volatile unsigned int  IPC6 __attribute__((__sfr__));

__extension__ typedef struct tagIPC6BITS
{
    union
    {
    
        struct
        {
        
unsigned DMA2IP:
            3;
            
unsigned :
            1;
            
unsigned OC3IP:
            3;
            
unsigned :
            1;
            
unsigned OC4IP:
            3;
            
unsigned :
            1;
            
unsigned T4IP:
            3;
        };
        
        struct
        {
        
unsigned DMA2IP0:
            1;
            
unsigned DMA2IP1:
            1;
            
unsigned DMA2IP2:
            1;
            
unsigned :
            1;
            
unsigned OC3IP0:
            1;
            
unsigned OC3IP1:
            1;
            
unsigned OC3IP2:
            1;
            
unsigned :
            1;
            
unsigned OC4IP0:
            1;
            
unsigned OC4IP1:
            1;
            
unsigned OC4IP2:
            1;
            
unsigned :
            1;
            
unsigned T4IP0:
            1;
            
unsigned T4IP1:
            1;
            
unsigned T4IP2:
            1;
        };
    };
} IPC6BITS;

extern volatile IPC6BITS IPC6bits __attribute__((__sfr__));

extern volatile unsigned int  IPC7 __attribute__((__sfr__));

__extension__ typedef struct tagIPC7BITS
{
    union
    {
    
        struct
        {
        
unsigned T5IP:
            3;
            
unsigned :
            1;
            
unsigned INT2IP:
            3;
            
unsigned :
            1;
            
unsigned U2RXIP:
            3;
            
unsigned :
            1;
            
unsigned U2TXIP:
            3;
        };
        
        struct
        {
        
unsigned T5IP0:
            1;
            
unsigned T5IP1:
            1;
            
unsigned T5IP2:
            1;
            
unsigned :
            1;
            
unsigned INT2IP0:
            1;
            
unsigned INT2IP1:
            1;
            
unsigned INT2IP2:
            1;
            
unsigned :
            1;
            
unsigned U2RXIP0:
            1;
            
unsigned U2RXIP1:
            1;
            
unsigned U2RXIP2:
            1;
            
unsigned :
            1;
            
unsigned U2TXIP0:
            1;
            
unsigned U2TXIP1:
            1;
            
unsigned U2TXIP2:
            1;
        };
    };
} IPC7BITS;

extern volatile IPC7BITS IPC7bits __attribute__((__sfr__));

extern volatile unsigned int  IPC8 __attribute__((__sfr__));

__extension__ typedef struct tagIPC8BITS
{
    union
    {
    
        struct
        {
        
unsigned SPI2EIP:
            3;
            
unsigned :
            1;
            
unsigned SPI2IP:
            3;
            
unsigned :
            1;
            
unsigned C1RXIP:
            3;
            
unsigned :
            1;
            
unsigned C1IP:
            3;
        };
        
        struct
        {
        
unsigned SPI2EIP0:
            1;
            
unsigned SPI2EIP1:
            1;
            
unsigned SPI2EIP2:
            1;
            
unsigned :
            1;
            
unsigned SPI2IP0:
            1;
            
unsigned SPI2IP1:
            1;
            
unsigned SPI2IP2:
            1;
            
unsigned :
            1;
            
unsigned C1RXIP0:
            1;
            
unsigned C1RXIP1:
            1;
            
unsigned C1RXIP2:
            1;
            
unsigned :
            1;
            
unsigned C1IP0:
            1;
            
unsigned C1IP1:
            1;
            
unsigned C1IP2:
            1;
        };
    };
} IPC8BITS;

extern volatile IPC8BITS IPC8bits __attribute__((__sfr__));

extern volatile unsigned int  IPC9 __attribute__((__sfr__));

__extension__ typedef struct tagIPC9BITS
{
    union
    {
    
        struct
        {
        
unsigned DMA3IP:
            3;
            
unsigned :
            1;
            
unsigned IC3IP:
            3;
            
unsigned :
            1;
            
unsigned IC4IP:
            3;
            
unsigned :
            1;
            
unsigned IC5IP:
            3;
        };
        
        struct
        {
        
unsigned DMA3IP0:
            1;
            
unsigned DMA3IP1:
            1;
            
unsigned DMA3IP2:
            1;
            
unsigned :
            1;
            
unsigned IC3IP0:
            1;
            
unsigned IC3IP1:
            1;
            
unsigned IC3IP2:
            1;
            
unsigned :
            1;
            
unsigned IC4IP0:
            1;
            
unsigned IC4IP1:
            1;
            
unsigned IC4IP2:
            1;
            
unsigned :
            1;
            
unsigned IC5IP0:
            1;
            
unsigned IC5IP1:
            1;
            
unsigned IC5IP2:
            1;
        };
    };
} IPC9BITS;

extern volatile IPC9BITS IPC9bits __attribute__((__sfr__));

extern volatile unsigned int  IPC10 __attribute__((__sfr__));

__extension__ typedef struct tagIPC10BITS
{
    union
    {
    
        struct
        {
        
unsigned IC6IP:
            3;
            
unsigned :
            1;
            
unsigned OC5IP:
            3;
            
unsigned :
            1;
            
unsigned OC6IP:
            3;
            
unsigned :
            1;
            
unsigned OC7IP:
            3;
        };
        
        struct
        {
        
unsigned IC6IP0:
            1;
            
unsigned IC6IP1:
            1;
            
unsigned IC6IP2:
            1;
            
unsigned :
            1;
            
unsigned OC5IP0:
            1;
            
unsigned OC5IP1:
            1;
            
unsigned OC5IP2:
            1;
            
unsigned :
            1;
            
unsigned OC6IP0:
            1;
            
unsigned OC6IP1:
            1;
            
unsigned OC6IP2:
            1;
            
unsigned :
            1;
            
unsigned OC7IP0:
            1;
            
unsigned OC7IP1:
            1;
            
unsigned OC7IP2:
            1;
        };
    };
} IPC10BITS;

extern volatile IPC10BITS IPC10bits __attribute__((__sfr__));

extern volatile unsigned int  IPC11 __attribute__((__sfr__));

__extension__ typedef struct tagIPC11BITS
{
    union
    {
    
        struct
        {
        
unsigned OC8IP:
            3;
            
unsigned :
            5;
            
unsigned DMA4IP:
            3;
            
unsigned :
            1;
            
unsigned T6IP:
            3;
        };
        
        struct
        {
        
unsigned OC8IP0:
            1;
            
unsigned OC8IP1:
            1;
            
unsigned OC8IP2:
            1;
            
unsigned :
            5;
            
unsigned DMA4IP0:
            1;
            
unsigned DMA4IP1:
            1;
            
unsigned DMA4IP2:
            1;
            
unsigned :
            1;
            
unsigned T6IP0:
            1;
            
unsigned T6IP1:
            1;
            
unsigned T6IP2:
            1;
        };
    };
} IPC11BITS;

extern volatile IPC11BITS IPC11bits __attribute__((__sfr__));

extern volatile unsigned int  IPC12 __attribute__((__sfr__));

__extension__ typedef struct tagIPC12BITS
{
    union
    {
    
        struct
        {
        
unsigned T7IP:
            3;
            
unsigned :
            1;
            
unsigned SI2C2IP:
            3;
            
unsigned :
            1;
            
unsigned MI2C2IP:
            3;
            
unsigned :
            1;
            
unsigned T8IP:
            3;
        };
        
        struct
        {
        
unsigned T7IP0:
            1;
            
unsigned T7IP1:
            1;
            
unsigned T7IP2:
            1;
            
unsigned :
            1;
            
unsigned SI2C2IP0:
            1;
            
unsigned SI2C2IP1:
            1;
            
unsigned SI2C2IP2:
            1;
            
unsigned :
            1;
            
unsigned MI2C2IP0:
            1;
            
unsigned MI2C2IP1:
            1;
            
unsigned MI2C2IP2:
            1;
            
unsigned :
            1;
            
unsigned T8IP0:
            1;
            
unsigned T8IP1:
            1;
            
unsigned T8IP2:
            1;
        };
    };
} IPC12BITS;

extern volatile IPC12BITS IPC12bits __attribute__((__sfr__));

extern volatile unsigned int  IPC13 __attribute__((__sfr__));

__extension__ typedef struct tagIPC13BITS
{
    union
    {
    
        struct
        {
        
unsigned T9IP:
            3;
            
unsigned :
            1;
            
unsigned INT3IP:
            3;
            
unsigned :
            1;
            
unsigned INT4IP:
            3;
        };
        
        struct
        {
        
unsigned T9IP0:
            1;
            
unsigned T9IP1:
            1;
            
unsigned T9IP2:
            1;
            
unsigned :
            1;
            
unsigned INT3IP0:
            1;
            
unsigned INT3IP1:
            1;
            
unsigned INT3IP2:
            1;
            
unsigned :
            1;
            
unsigned INT4IP0:
            1;
            
unsigned INT4IP1:
            1;
            
unsigned INT4IP2:
            1;
        };
    };
} IPC13BITS;

extern volatile IPC13BITS IPC13bits __attribute__((__sfr__));

extern volatile unsigned int  IPC14 __attribute__((__sfr__));

__extension__ typedef struct tagIPC14BITS
{
    union
    {
    
        struct
        {
        
unsigned C2IP:
            3;
            
unsigned :
            9;
            
unsigned DCIEIP:
            3;
        };
        
        struct
        {
        
unsigned :
            12;
            
unsigned DCIEIP0:
            1;
            
unsigned DCIEIP1:
            1;
            
unsigned DCIEIP2:
            1;
        };
    };
} IPC14BITS;

extern volatile IPC14BITS IPC14bits __attribute__((__sfr__));

extern volatile unsigned int  IPC15 __attribute__((__sfr__));

__extension__ typedef struct tagIPC15BITS
{
    union
    {
    
        struct
        {
        
unsigned DCIIP:
            3;
            
unsigned :
            1;
            
unsigned DMA5IP:
            3;
        };
        
        struct
        {
        
unsigned DCIIP0:
            1;
            
unsigned DCIIP1:
            1;
            
unsigned DCIIP2:
            1;
            
unsigned :
            1;
            
unsigned DMA5IP0:
            1;
            
unsigned DMA5IP1:
            1;
            
unsigned DMA5IP2:
            1;
        };
    };
} IPC15BITS;

extern volatile IPC15BITS IPC15bits __attribute__((__sfr__));

extern volatile unsigned int  IPC16 __attribute__((__sfr__));

__extension__ typedef struct tagIPC16BITS
{
    union
    {
    
        struct
        {
        
unsigned :
            4;
            
unsigned U1EIP:
            3;
            
unsigned :
            1;
            
unsigned U2EIP:
            3;
        };
        
        struct
        {
        
unsigned :
            4;
            
unsigned U1EIP0:
            1;
            
unsigned U1EIP1:
            1;
            
unsigned U1EIP2:
            1;
            
unsigned :
            1;
            
unsigned U2EIP0:
            1;
            
unsigned U2EIP1:
            1;
            
unsigned U2EIP2:
            1;
        };
    };
} IPC16BITS;

extern volatile IPC16BITS IPC16bits __attribute__((__sfr__));

extern volatile unsigned int  IPC17 __attribute__((__sfr__));

__extension__ typedef struct tagIPC17BITS
{
    union
    {
    
        struct
        {
        
unsigned DMA6IP:
            3;
            
unsigned :
            1;
            
unsigned DMA7IP:
            3;
            
unsigned :
            1;
            
unsigned C1TXIP:
            3;
        };
        
        struct
        {
        
unsigned DMA6IP0:
            1;
            
unsigned DMA6IP1:
            1;
            
unsigned DMA6IP2:
            1;
            
unsigned :
            1;
            
unsigned DMA7IP0:
            1;
            
unsigned DMA7IP1:
            1;
            
unsigned DMA7IP2:
            1;
            
unsigned :
            1;
            
unsigned C1TXIP0:
            1;
            
unsigned C1TXIP1:
            1;
            
unsigned C1TXIP2:
            1;
        };
    };
} IPC17BITS;

extern volatile IPC17BITS IPC17bits __attribute__((__sfr__));

extern volatile unsigned int  INTTREG __attribute__((__sfr__));

__extension__ typedef struct tagINTTREGBITS
{
    union
    {
    
        struct
        {
        
unsigned VECNUM:
            7;
            
unsigned :
            1;
            
unsigned ILR:
            4;
        };
        
        struct
        {
        
unsigned VECNUM0:
            1;
            
unsigned VECNUM1:
            1;
            
unsigned VECNUM2:
            1;
            
unsigned VECNUM3:
            1;
            
unsigned VECNUM4:
            1;
            
unsigned VECNUM5:
            1;
            
unsigned VECNUM6:
            1;
            
unsigned :
            1;
            
unsigned ILR0:
            1;
            
unsigned ILR1:
            1;
            
unsigned ILR2:
            1;
            
unsigned ILR3:
            1;
        };
    };
} INTTREGBITS;

extern volatile INTTREGBITS INTTREGbits __attribute__((__sfr__));

extern volatile unsigned int  TMR1 __attribute__((__sfr__));
extern volatile unsigned int  PR1 __attribute__((__sfr__));
extern volatile unsigned int  T1CON __attribute__((__sfr__));

__extension__ typedef struct tagT1CONBITS
{
    union
    {
    
        struct
        {
        
unsigned :
            1;
            
unsigned TCS:
            1;
            
unsigned TSYNC:
            1;
            
unsigned :
            1;
            
unsigned TCKPS:
            2;
            
unsigned TGATE:
            1;
            
unsigned :
            6;
            
unsigned TSIDL:
            1;
            
unsigned :
            1;
            
unsigned TON:
            1;
        };
        
        struct
        {
        
unsigned :
            4;
            
unsigned TCKPS0:
            1;
            
unsigned TCKPS1:
            1;
        };
    };
} T1CONBITS;

extern volatile T1CONBITS T1CONbits __attribute__((__sfr__));

extern volatile unsigned int  TMR2 __attribute__((__sfr__));
extern volatile unsigned int  TMR3HLD __attribute__((__sfr__));
extern volatile unsigned int  TMR3 __attribute__((__sfr__));
extern volatile unsigned int  PR2 __attribute__((__sfr__));
extern volatile unsigned int  PR3 __attribute__((__sfr__));
extern volatile unsigned int  T2CON __attribute__((__sfr__));

__extension__ typedef struct tagT2CONBITS
{
    union
    {
    
        struct
        {
        
unsigned :
            1;
            
unsigned TCS:
            1;
            
unsigned :
            1;
            
unsigned T32:
            1;
            
unsigned TCKPS:
            2;
            
unsigned TGATE:
            1;
            
unsigned :
            6;
            
unsigned TSIDL:
            1;
            
unsigned :
            1;
            
unsigned TON:
            1;
        };
        
        struct
        {
        
unsigned :
            4;
            
unsigned TCKPS0:
            1;
            
unsigned TCKPS1:
            1;
        };
    };
} T2CONBITS;

extern volatile T2CONBITS T2CONbits __attribute__((__sfr__));

extern volatile unsigned int  T3CON __attribute__((__sfr__));

__extension__ typedef struct tagT3CONBITS
{
    union
    {
    
        struct
        {
        
unsigned :
            1;
            
unsigned TCS:
            1;
            
unsigned :
            2;
            
unsigned TCKPS:
            2;
            
unsigned TGATE:
            1;
            
unsigned :
            6;
            
unsigned TSIDL:
            1;
            
unsigned :
            1;
            
unsigned TON:
            1;
        };
        
        struct
        {
        
unsigned :
            4;
            
unsigned TCKPS0:
            1;
            
unsigned TCKPS1:
            1;
        };
    };
} T3CONBITS;

extern volatile T3CONBITS T3CONbits __attribute__((__sfr__));

extern volatile unsigned int  TMR4 __attribute__((__sfr__));
extern volatile unsigned int  TMR5HLD __attribute__((__sfr__));
extern volatile unsigned int  TMR5 __attribute__((__sfr__));
extern volatile unsigned int  PR4 __attribute__((__sfr__));
extern volatile unsigned int  PR5 __attribute__((__sfr__));
extern volatile unsigned int  T4CON __attribute__((__sfr__));

__extension__ typedef struct tagT4CONBITS
{
    union
    {
    
        struct
        {
        
unsigned :
            1;
            
unsigned TCS:
            1;
            
unsigned :
            1;
            
unsigned T32:
            1;
            
unsigned TCKPS:
            2;
            
unsigned TGATE:
            1;
            
unsigned :
            6;
            
unsigned TSIDL:
            1;
            
unsigned :
            1;
            
unsigned TON:
            1;
        };
        
        struct
        {
        
unsigned :
            4;
            
unsigned TCKPS0:
            1;
            
unsigned TCKPS1:
            1;
        };
    };
} T4CONBITS;

extern volatile T4CONBITS T4CONbits __attribute__((__sfr__));

extern volatile unsigned int  T5CON __attribute__((__sfr__));

__extension__ typedef struct tagT5CONBITS
{
    union
    {
    
        struct
        {
        
unsigned :
            1;
            
unsigned TCS:
            1;
            
unsigned :
            2;
            
unsigned TCKPS:
            2;
            
unsigned TGATE:
            1;
            
unsigned :
            6;
            
unsigned TSIDL:
            1;
            
unsigned :
            1;
            
unsigned TON:
            1;
        };
        
        struct
        {
        
unsigned :
            4;
            
unsigned TCKPS0:
            1;
            
unsigned TCKPS1:
            1;
        };
    };
} T5CONBITS;

extern volatile T5CONBITS T5CONbits __attribute__((__sfr__));

extern volatile unsigned int  TMR6 __attribute__((__sfr__));
extern volatile unsigned int  TMR7HLD __attribute__((__sfr__));
extern volatile unsigned int  TMR7 __attribute__((__sfr__));
extern volatile unsigned int  PR6 __attribute__((__sfr__));
extern volatile unsigned int  PR7 __attribute__((__sfr__));
extern volatile unsigned int  T6CON __attribute__((__sfr__));

__extension__ typedef struct tagT6CONBITS
{
    union
    {
    
        struct
        {
        
unsigned :
            1;
            
unsigned TCS:
            1;
            
unsigned :
            1;
            
unsigned T32:
            1;
            
unsigned TCKPS:
            2;
            
unsigned TGATE:
            1;
            
unsigned :
            6;
            
unsigned TSIDL:
            1;
            
unsigned :
            1;
            
unsigned TON:
            1;
        };
        
        struct
        {
        
unsigned :
            4;
            
unsigned TCKPS0:
            1;
            
unsigned TCKPS1:
            1;
        };
    };
} T6CONBITS;

extern volatile T6CONBITS T6CONbits __attribute__((__sfr__));

extern volatile unsigned int  T7CON __attribute__((__sfr__));

__extension__ typedef struct tagT7CONBITS
{
    union
    {
    
        struct
        {
        
unsigned :
            1;
            
unsigned TCS:
            1;
            
unsigned :
            2;
            
unsigned TCKPS:
            2;
            
unsigned TGATE:
            1;
            
unsigned :
            6;
            
unsigned TSIDL:
            1;
            
unsigned :
            1;
            
unsigned TON:
            1;
        };
        
        struct
        {
        
unsigned :
            4;
            
unsigned TCKPS0:
            1;
            
unsigned TCKPS1:
            1;
        };
    };
} T7CONBITS;

extern volatile T7CONBITS T7CONbits __attribute__((__sfr__));

extern volatile unsigned int  TMR8 __attribute__((__sfr__));
extern volatile unsigned int  TMR9HLD __attribute__((__sfr__));
extern volatile unsigned int  TMR9 __attribute__((__sfr__));
extern volatile unsigned int  PR8 __attribute__((__sfr__));
extern volatile unsigned int  PR9 __attribute__((__sfr__));
extern volatile unsigned int  T8CON __attribute__((__sfr__));

__extension__ typedef struct tagT8CONBITS
{
    union
    {
    
        struct
        {
        
unsigned :
            1;
            
unsigned TCS:
            1;
            
unsigned :
            1;
            
unsigned T32:
            1;
            
unsigned TCKPS:
            2;
            
unsigned TGATE:
            1;
            
unsigned :
            6;
            
unsigned TSIDL:
            1;
            
unsigned :
            1;
            
unsigned TON:
            1;
        };
        
        struct
        {
        
unsigned :
            4;
            
unsigned TCKPS0:
            1;
            
unsigned TCKPS1:
            1;
        };
    };
} T8CONBITS;

extern volatile T8CONBITS T8CONbits __attribute__((__sfr__));

extern volatile unsigned int  T9CON __attribute__((__sfr__));

__extension__ typedef struct tagT9CONBITS
{
    union
    {
    
        struct
        {
        
unsigned :
            1;
            
unsigned TCS:
            1;
            
unsigned :
            2;
            
unsigned TCKPS:
            2;
            
unsigned TGATE:
            1;
            
unsigned :
            6;
            
unsigned TSIDL:
            1;
            
unsigned :
            1;
            
unsigned TON:
            1;
        };
        
        struct
        {
        
unsigned :
            4;
            
unsigned TCKPS0:
            1;
            
unsigned TCKPS1:
            1;
        };
    };
} T9CONBITS;

extern volatile T9CONBITS T9CONbits __attribute__((__sfr__));


/* Generic structure of entire SFR area for Input Capture modules */

typedef struct tagIC
{
    unsigned int icxbuf;
    unsigned int icxcon;
} IC, *PIC;

/* SFR blocks for Input Capture modules */
extern volatile IC IC1 __attribute__((__sfr__));
extern volatile IC IC2 __attribute__((__sfr__));
extern volatile IC IC3 __attribute__((__sfr__));
extern volatile IC IC4 __attribute__((__sfr__));
extern volatile IC IC5 __attribute__((__sfr__));
extern volatile IC IC6 __attribute__((__sfr__));
extern volatile IC IC7 __attribute__((__sfr__));
extern volatile IC IC8 __attribute__((__sfr__));

extern volatile unsigned int  IC1BUF __attribute__((__sfr__));
extern volatile unsigned int  IC1CON __attribute__((__sfr__));

__extension__ typedef struct tagIC1CONBITS
{
    union
    {
    
        struct
        {
        
unsigned ICM:
            3;
            
unsigned ICBNE:
            1;
            
unsigned ICOV:
            1;
            
unsigned ICI:
            2;
            
unsigned ICTMR:
            1;
            
unsigned :
            5;
            
unsigned ICSIDL:
            1;
        };
        
        struct
        {
        
unsigned ICM0:
            1;
            
unsigned ICM1:
            1;
            
unsigned ICM2:
            1;
            
unsigned :
            2;
            
unsigned ICI0:
            1;
            
unsigned ICI1:
            1;
        };
    };
} IC1CONBITS;

extern volatile IC1CONBITS IC1CONbits __attribute__((__sfr__));

extern volatile unsigned int  IC2BUF __attribute__((__sfr__));
extern volatile unsigned int  IC2CON __attribute__((__sfr__));

__extension__ typedef struct tagIC2CONBITS
{
    union
    {
    
        struct
        {
        
unsigned ICM:
            3;
            
unsigned ICBNE:
            1;
            
unsigned ICOV:
            1;
            
unsigned ICI:
            2;
            
unsigned ICTMR:
            1;
            
unsigned :
            5;
            
unsigned ICSIDL:
            1;
        };
        
        struct
        {
        
unsigned ICM0:
            1;
            
unsigned ICM1:
            1;
            
unsigned ICM2:
            1;
            
unsigned :
            2;
            
unsigned ICI0:
            1;
            
unsigned ICI1:
            1;
        };
    };
} IC2CONBITS;

extern volatile IC2CONBITS IC2CONbits __attribute__((__sfr__));

extern volatile unsigned int  IC3BUF __attribute__((__sfr__));
extern volatile unsigned int  IC3CON __attribute__((__sfr__));

__extension__ typedef struct tagIC3CONBITS
{
    union
    {
    
        struct
        {
        
unsigned ICM:
            3;
            
unsigned ICBNE:
            1;
            
unsigned ICOV:
            1;
            
unsigned ICI:
            2;
            
unsigned ICTMR:
            1;
            
unsigned :
            5;
            
unsigned ICSIDL:
            1;
        };
        
        struct
        {
        
unsigned ICM0:
            1;
            
unsigned ICM1:
            1;
            
unsigned ICM2:
            1;
            
unsigned :
            2;
            
unsigned ICI0:
            1;
            
unsigned ICI1:
            1;
        };
    };
} IC3CONBITS;

extern volatile IC3CONBITS IC3CONbits __attribute__((__sfr__));

extern volatile unsigned int  IC4BUF __attribute__((__sfr__));
extern volatile unsigned int  IC4CON __attribute__((__sfr__));

__extension__ typedef struct tagIC4CONBITS
{
    union
    {
    
        struct
        {
        
unsigned ICM:
            3;
            
unsigned ICBNE:
            1;
            
unsigned ICOV:
            1;
            
unsigned ICI:
            2;
            
unsigned ICTMR:
            1;
            
unsigned :
            5;
            
unsigned ICSIDL:
            1;
        };
        
        struct
        {
        
unsigned ICM0:
            1;
            
unsigned ICM1:
            1;
            
unsigned ICM2:
            1;
            
unsigned :
            2;
            
unsigned ICI0:
            1;
            
unsigned ICI1:
            1;
        };
    };
} IC4CONBITS;

extern volatile IC4CONBITS IC4CONbits __attribute__((__sfr__));

extern volatile unsigned int  IC5BUF __attribute__((__sfr__));
extern volatile unsigned int  IC5CON __attribute__((__sfr__));

__extension__ typedef struct tagIC5CONBITS
{
    union
    {
    
        struct
        {
        
unsigned ICM:
            3;
            
unsigned ICBNE:
            1;
            
unsigned ICOV:
            1;
            
unsigned ICI:
            2;
            
unsigned ICTMR:
            1;
            
unsigned :
            5;
            
unsigned ICSIDL:
            1;
        };
        
        struct
        {
        
unsigned ICM0:
            1;
            
unsigned ICM1:
            1;
            
unsigned ICM2:
            1;
            
unsigned :
            2;
            
unsigned ICI0:
            1;
            
unsigned ICI1:
            1;
        };
    };
} IC5CONBITS;

extern volatile IC5CONBITS IC5CONbits __attribute__((__sfr__));

extern volatile unsigned int  IC6BUF __attribute__((__sfr__));
extern volatile unsigned int  IC6CON __attribute__((__sfr__));

__extension__ typedef struct tagIC6CONBITS
{
    union
    {
    
        struct
        {
        
unsigned ICM:
            3;
            
unsigned ICBNE:
            1;
            
unsigned ICOV:
            1;
            
unsigned ICI:
            2;
            
unsigned ICTMR:
            1;
            
unsigned :
            5;
            
unsigned ICSIDL:
            1;
        };
        
        struct
        {
        
unsigned ICM0:
            1;
            
unsigned ICM1:
            1;
            
unsigned ICM2:
            1;
            
unsigned :
            2;
            
unsigned ICI0:
            1;
            
unsigned ICI1:
            1;
        };
    };
} IC6CONBITS;

extern volatile IC6CONBITS IC6CONbits __attribute__((__sfr__));

extern volatile unsigned int  IC7BUF __attribute__((__sfr__));
extern volatile unsigned int  IC7CON __attribute__((__sfr__));

__extension__ typedef struct tagIC7CONBITS
{
    union
    {
    
        struct
        {
        
unsigned ICM:
            3;
            
unsigned ICBNE:
            1;
            
unsigned ICOV:
            1;
            
unsigned ICI:
            2;
            
unsigned ICTMR:
            1;
            
unsigned :
            5;
            
unsigned ICSIDL:
            1;
        };
        
        struct
        {
        
unsigned ICM0:
            1;
            
unsigned ICM1:
            1;
            
unsigned ICM2:
            1;
            
unsigned :
            2;
            
unsigned ICI0:
            1;
            
unsigned ICI1:
            1;
        };
    };
} IC7CONBITS;

extern volatile IC7CONBITS IC7CONbits __attribute__((__sfr__));

extern volatile unsigned int  IC8BUF __attribute__((__sfr__));
extern volatile unsigned int  IC8CON __attribute__((__sfr__));

__extension__ typedef struct tagIC8CONBITS
{
    union
    {
    
        struct
        {
        
unsigned ICM:
            3;
            
unsigned ICBNE:
            1;
            
unsigned ICOV:
            1;
            
unsigned ICI:
            2;
            
unsigned ICTMR:
            1;
            
unsigned :
            5;
            
unsigned ICSIDL:
            1;
        };
        
        struct
        {
        
unsigned ICM0:
            1;
            
unsigned ICM1:
            1;
            
unsigned ICM2:
            1;
            
unsigned :
            2;
            
unsigned ICI0:
            1;
            
unsigned ICI1:
            1;
        };
    };
} IC8CONBITS;

extern volatile IC8CONBITS IC8CONbits __attribute__((__sfr__));


/* Generic structure of entire SFR area for Output Compare modules */

typedef struct tagOC
{
    unsigned int ocxrs;
    unsigned int ocxr;
    unsigned int ocxcon;
} OC, *POC;

/* SFR blocks for Output Compare modules */
extern volatile OC OC1 __attribute__((__sfr__));
extern volatile OC OC2 __attribute__((__sfr__));
extern volatile OC OC3 __attribute__((__sfr__));
extern volatile OC OC4 __attribute__((__sfr__));
extern volatile OC OC5 __attribute__((__sfr__));
extern volatile OC OC6 __attribute__((__sfr__));
extern volatile OC OC7 __attribute__((__sfr__));
extern volatile OC OC8 __attribute__((__sfr__));

extern volatile unsigned int  OC1RS __attribute__((__sfr__));
extern volatile unsigned int  OC1R __attribute__((__sfr__));
extern volatile unsigned int  OC1CON __attribute__((__sfr__));

__extension__ typedef struct tagOC1CONBITS
{
    union
    {
    
        struct
        {
        
unsigned OCM:
            3;
            
unsigned OCTSEL:
            1;
            
unsigned OCFLT:
            1;
            
unsigned :
            8;
            
unsigned OCSIDL:
            1;
        };
        
        struct
        {
        
unsigned OCM0:
            1;
            
unsigned OCM1:
            1;
            
unsigned OCM2:
            1;
        };
    };
} OC1CONBITS;

extern volatile OC1CONBITS OC1CONbits __attribute__((__sfr__));

extern volatile unsigned int  OC2RS __attribute__((__sfr__));
extern volatile unsigned int  OC2R __attribute__((__sfr__));
extern volatile unsigned int  OC2CON __attribute__((__sfr__));

__extension__ typedef struct tagOC2CONBITS
{
    union
    {
    
        struct
        {
        
unsigned OCM:
            3;
            
unsigned OCTSEL:
            1;
            
unsigned OCFLT:
            1;
            
unsigned :
            8;
            
unsigned OCSIDL:
            1;
        };
        
        struct
        {
        
unsigned OCM0:
            1;
            
unsigned OCM1:
            1;
            
unsigned OCM2:
            1;
        };
    };
} OC2CONBITS;

extern volatile OC2CONBITS OC2CONbits __attribute__((__sfr__));

extern volatile unsigned int  OC3RS __attribute__((__sfr__));
extern volatile unsigned int  OC3R __attribute__((__sfr__));
extern volatile unsigned int  OC3CON __attribute__((__sfr__));

__extension__ typedef struct tagOC3CONBITS
{
    union
    {
    
        struct
        {
        
unsigned OCM:
            3;
            
unsigned OCTSEL:
            1;
            
unsigned OCFLT:
            1;
            
unsigned :
            8;
            
unsigned OCSIDL:
            1;
        };
        
        struct
        {
        
unsigned OCM0:
            1;
            
unsigned OCM1:
            1;
            
unsigned OCM2:
            1;
        };
    };
} OC3CONBITS;

extern volatile OC3CONBITS OC3CONbits __attribute__((__sfr__));

extern volatile unsigned int  OC4RS __attribute__((__sfr__));
extern volatile unsigned int  OC4R __attribute__((__sfr__));
extern volatile unsigned int  OC4CON __attribute__((__sfr__));

__extension__ typedef struct tagOC4CONBITS
{
    union
    {
    
        struct
        {
        
unsigned OCM:
            3;
            
unsigned OCTSEL:
            1;
            
unsigned OCFLT:
            1;
            
unsigned :
            8;
            
unsigned OCSIDL:
            1;
        };
        
        struct
        {
        
unsigned OCM0:
            1;
            
unsigned OCM1:
            1;
            
unsigned OCM2:
            1;
        };
    };
} OC4CONBITS;

extern volatile OC4CONBITS OC4CONbits __attribute__((__sfr__));

extern volatile unsigned int  OC5RS __attribute__((__sfr__));
extern volatile unsigned int  OC5R __attribute__((__sfr__));
extern volatile unsigned int  OC5CON __attribute__((__sfr__));

__extension__ typedef struct tagOC5CONBITS
{
    union
    {
    
        struct
        {
        
unsigned OCM:
            3;
            
unsigned OCTSEL:
            1;
            
unsigned OCFLT:
            1;
            
unsigned :
            8;
            
unsigned OCSIDL:
            1;
        };
        
        struct
        {
        
unsigned OCM0:
            1;
            
unsigned OCM1:
            1;
            
unsigned OCM2:
            1;
        };
    };
} OC5CONBITS;

extern volatile OC5CONBITS OC5CONbits __attribute__((__sfr__));

extern volatile unsigned int  OC6RS __attribute__((__sfr__));
extern volatile unsigned int  OC6R __attribute__((__sfr__));
extern volatile unsigned int  OC6CON __attribute__((__sfr__));

__extension__ typedef struct tagOC6CONBITS
{
    union
    {
    
        struct
        {
        
unsigned OCM:
            3;
            
unsigned OCTSEL:
            1;
            
unsigned OCFLT:
            1;
            
unsigned :
            8;
            
unsigned OCSIDL:
            1;
        };
        
        struct
        {
        
unsigned OCM0:
            1;
            
unsigned OCM1:
            1;
            
unsigned OCM2:
            1;
        };
    };
} OC6CONBITS;

extern volatile OC6CONBITS OC6CONbits __attribute__((__sfr__));

extern volatile unsigned int  OC7RS __attribute__((__sfr__));
extern volatile unsigned int  OC7R __attribute__((__sfr__));
extern volatile unsigned int  OC7CON __attribute__((__sfr__));

__extension__ typedef struct tagOC7CONBITS
{
    union
    {
    
        struct
        {
        
unsigned OCM:
            3;
            
unsigned OCTSEL:
            1;
            
unsigned OCFLT:
            1;
            
unsigned :
            8;
            
unsigned OCSIDL:
            1;
        };
        
        struct
        {
        
unsigned OCM0:
            1;
            
unsigned OCM1:
            1;
            
unsigned OCM2:
            1;
        };
    };
} OC7CONBITS;

extern volatile OC7CONBITS OC7CONbits __attribute__((__sfr__));

extern volatile unsigned int  OC8RS __attribute__((__sfr__));
extern volatile unsigned int  OC8R __attribute__((__sfr__));
extern volatile unsigned int  OC8CON __attribute__((__sfr__));

__extension__ typedef struct tagOC8CONBITS
{
    union
    {
    
        struct
        {
        
unsigned OCM:
            3;
            
unsigned OCTSEL:
            1;
            
unsigned OCFLT:
            1;
            
unsigned :
            8;
            
unsigned OCSIDL:
            1;
        };
        
        struct
        {
        
unsigned OCM0:
            1;
            
unsigned OCM1:
            1;
            
unsigned OCM2:
            1;
        };
    };
} OC8CONBITS;

extern volatile OC8CONBITS OC8CONbits __attribute__((__sfr__));

extern volatile unsigned int  I2C1RCV __attribute__((__sfr__));
extern volatile unsigned int  I2C1TRN __attribute__((__sfr__));
extern volatile unsigned int  I2C1BRG __attribute__((__sfr__));
extern volatile unsigned int  I2C1CON __attribute__((__sfr__));

typedef struct tagI2C1CONBITS
{

unsigned SEN:
    1;
    
unsigned RSEN:
    1;
    
unsigned PEN:
    1;
    
unsigned RCEN:
    1;
    
unsigned ACKEN:
    1;
    
unsigned ACKDT:
    1;
    
unsigned STREN:
    1;
    
unsigned GCEN:
    1;
    
unsigned SMEN:
    1;
    
unsigned DISSLW:
    1;
    
unsigned A10M:
    1;
    
unsigned IPMIEN:
    1;
    
unsigned SCLREL:
    1;
    
unsigned I2CSIDL:
    1;
    
unsigned :
    1;
    
unsigned I2CEN:
    1;
} I2C1CONBITS;

extern volatile I2C1CONBITS I2C1CONbits __attribute__((__sfr__));

extern volatile unsigned int  I2C1STAT __attribute__((__sfr__));

typedef struct tagI2C1STATBITS
{

unsigned TBF:
    1;
    
unsigned RBF:
    1;
    
unsigned R_W:
    1;
    
unsigned S:
    1;
    
unsigned P:
    1;
    
unsigned D_A:
    1;
    
unsigned I2COV:
    1;
    
unsigned IWCOL:
    1;
    
unsigned ADD10:
    1;
    
unsigned GCSTAT:
    1;
    
unsigned BCL:
    1;
    
unsigned :
    3;
    
unsigned TRSTAT:
    1;
    
unsigned ACKSTAT:
    1;
} I2C1STATBITS;

extern volatile I2C1STATBITS I2C1STATbits __attribute__((__sfr__));

extern volatile unsigned int  I2C1ADD __attribute__((__sfr__));
extern volatile unsigned int  I2C1MSK __attribute__((__sfr__));
extern volatile unsigned int  I2C2RCV __attribute__((__sfr__));
extern volatile unsigned int  I2C2TRN __attribute__((__sfr__));
extern volatile unsigned int  I2C2BRG __attribute__((__sfr__));
extern volatile unsigned int  I2C2CON __attribute__((__sfr__));

typedef struct tagI2C2CONBITS
{

unsigned SEN:
    1;
    
unsigned RSEN:
    1;
    
unsigned PEN:
    1;
    
unsigned RCEN:
    1;
    
unsigned ACKEN:
    1;
    
unsigned ACKDT:
    1;
    
unsigned STREN:
    1;
    
unsigned GCEN:
    1;
    
unsigned SMEN:
    1;
    
unsigned DISSLW:
    1;
    
unsigned A10M:
    1;
    
unsigned IPMIEN:
    1;
    
unsigned SCLREL:
    1;
    
unsigned I2CSIDL:
    1;
    
unsigned :
    1;
    
unsigned I2CEN:
    1;
} I2C2CONBITS;

extern volatile I2C2CONBITS I2C2CONbits __attribute__((__sfr__));

extern volatile unsigned int  I2C2STAT __attribute__((__sfr__));

typedef struct tagI2C2STATBITS
{

unsigned TBF:
    1;
    
unsigned RBF:
    1;
    
unsigned R_W:
    1;
    
unsigned S:
    1;
    
unsigned P:
    1;
    
unsigned D_A:
    1;
    
unsigned I2COV:
    1;
    
unsigned IWCOL:
    1;
    
unsigned ADD10:
    1;
    
unsigned GCSTAT:
    1;
    
unsigned BCL:
    1;
    
unsigned :
    3;
    
unsigned TRSTAT:
    1;
    
unsigned ACKSTAT:
    1;
} I2C2STATBITS;

extern volatile I2C2STATBITS I2C2STATbits __attribute__((__sfr__));

extern volatile unsigned int  I2C2ADD __attribute__((__sfr__));
extern volatile unsigned int  I2C2MSK __attribute__((__sfr__));

/* Generic structure of entire SFR area for each UART module */

typedef struct tagUART
{
    unsigned int uxmode;
    unsigned int uxsta;
    unsigned int uxtxreg;
    unsigned int uxrxreg;
    unsigned int uxbrg;
} UART, *PUART;

#define UxMODEBITS U1MODEBITS
#define UxSTABITS U1STABITS
#define UxTXREGBITS U1TXREGBITS
#define UxRXREGBITS U1RXREGBITS
#define UxBRGBITS U1BRGBITS

/* SFR blocks for each UART module */
extern volatile UART UART1 __attribute__((__sfr__));
extern volatile UART UART2 __attribute__((__sfr__));

extern volatile unsigned int  U1MODE __attribute__((__sfr__));

__extension__ typedef struct tagU1MODEBITS
{
    union
    {
    
        struct
        {
        
unsigned STSEL:
            1;
            
unsigned PDSEL:
            2;
            
unsigned BRGH:
            1;
            
unsigned URXINV:
            1;
            
unsigned ABAUD:
            1;
            
unsigned LPBACK:
            1;
            
unsigned WAKE:
            1;
            
unsigned UEN:
            2;
            
unsigned :
            1;
            
unsigned RTSMD:
            1;
            
unsigned IREN:
            1;
            
unsigned USIDL:
            1;
            
unsigned :
            1;
            
unsigned UARTEN:
            1;
        };
        
        struct
        {
        
unsigned :
            1;
            
unsigned PDSEL0:
            1;
            
unsigned PDSEL1:
            1;
            
unsigned :
            5;
            
unsigned UEN0:
            1;
            
unsigned UEN1:
            1;
        };
    };
} U1MODEBITS;

extern volatile U1MODEBITS U1MODEbits __attribute__((__sfr__));

extern volatile unsigned int  U1STA __attribute__((__sfr__));

__extension__ typedef struct tagU1STABITS
{
    union
    {
    
        struct
        {
        
unsigned URXDA:
            1;
            
unsigned OERR:
            1;
            
unsigned FERR:
            1;
            
unsigned PERR:
            1;
            
unsigned RIDLE:
            1;
            
unsigned ADDEN:
            1;
            
unsigned URXISEL:
            2;
            
unsigned TRMT:
            1;
            
unsigned UTXBF:
            1;
            
unsigned UTXEN:
            1;
            
unsigned UTXBRK:
            1;
            
unsigned :
            1;
            
unsigned UTXISEL0:
            1;
            
unsigned UTXINV:
            1;
            
unsigned UTXISEL1:
            1;
        };
        
        struct
        {
        
unsigned :
            6;
            
unsigned URXISEL0:
            1;
            
unsigned URXISEL1:
            1;
        };
    };
} U1STABITS;

extern volatile U1STABITS U1STAbits __attribute__((__sfr__));

extern volatile unsigned int  U1TXREG __attribute__((__sfr__));

typedef struct tagU1TXREGBITS
{

unsigned UTXREG0:
    1;
    
unsigned UTXREG1:
    1;
    
unsigned UTXREG2:
    1;
    
unsigned UTXREG3:
    1;
    
unsigned UTXREG4:
    1;
    
unsigned UTXREG5:
    1;
    
unsigned UTXREG6:
    1;
    
unsigned UTXREG7:
    1;
    
unsigned UTX8:
    1;
} U1TXREGBITS;

extern volatile U1TXREGBITS U1TXREGbits __attribute__((__sfr__));

extern volatile unsigned int  U1RXREG __attribute__((__sfr__));

typedef struct tagU1RXREGBITS
{

unsigned URXREG0:
    1;
    
unsigned URXREG1:
    1;
    
unsigned URXREG2:
    1;
    
unsigned URXREG3:
    1;
    
unsigned URXREG4:
    1;
    
unsigned URXREG5:
    1;
    
unsigned URXREG6:
    1;
    
unsigned URXREG7:
    1;
    
unsigned URX8:
    1;
} U1RXREGBITS;

extern volatile U1RXREGBITS U1RXREGbits __attribute__((__sfr__));

extern volatile unsigned int  U1BRG __attribute__((__sfr__));
extern volatile unsigned int  U2MODE __attribute__((__sfr__));

__extension__ typedef struct tagU2MODEBITS
{
    union
    {
    
        struct
        {
        
unsigned STSEL:
            1;
            
unsigned PDSEL:
            2;
            
unsigned BRGH:
            1;
            
unsigned URXINV:
            1;
            
unsigned ABAUD:
            1;
            
unsigned LPBACK:
            1;
            
unsigned WAKE:
            1;
            
unsigned UEN:
            2;
            
unsigned :
            1;
            
unsigned RTSMD:
            1;
            
unsigned IREN:
            1;
            
unsigned USIDL:
            1;
            
unsigned :
            1;
            
unsigned UARTEN:
            1;
        };
        
        struct
        {
        
unsigned :
            1;
            
unsigned PDSEL0:
            1;
            
unsigned PDSEL1:
            1;
            
unsigned :
            5;
            
unsigned UEN0:
            1;
            
unsigned UEN1:
            1;
        };
    };
} U2MODEBITS;

extern volatile U2MODEBITS U2MODEbits __attribute__((__sfr__));

extern volatile unsigned int  U2STA __attribute__((__sfr__));

__extension__ typedef struct tagU2STABITS
{
    union
    {
    
        struct
        {
        
unsigned URXDA:
            1;
            
unsigned OERR:
            1;
            
unsigned FERR:
            1;
            
unsigned PERR:
            1;
            
unsigned RIDLE:
            1;
            
unsigned ADDEN:
            1;
            
unsigned URXISEL:
            2;
            
unsigned TRMT:
            1;
            
unsigned UTXBF:
            1;
            
unsigned UTXEN:
            1;
            
unsigned UTXBRK:
            1;
            
unsigned :
            1;
            
unsigned UTXISEL0:
            1;
            
unsigned UTXINV:
            1;
            
unsigned UTXISEL1:
            1;
        };
        
        struct
        {
        
unsigned :
            6;
            
unsigned URXISEL0:
            1;
            
unsigned URXISEL1:
            1;
        };
    };
} U2STABITS;

extern volatile U2STABITS U2STAbits __attribute__((__sfr__));

extern volatile unsigned int  U2TXREG __attribute__((__sfr__));

typedef struct tagU2TXREGBITS
{

unsigned UTXREG0:
    1;
    
unsigned UTXREG1:
    1;
    
unsigned UTXREG2:
    1;
    
unsigned UTXREG3:
    1;
    
unsigned UTXREG4:
    1;
    
unsigned UTXREG5:
    1;
    
unsigned UTXREG6:
    1;
    
unsigned UTXREG7:
    1;
    
unsigned UTX8:
    1;
} U2TXREGBITS;

extern volatile U2TXREGBITS U2TXREGbits __attribute__((__sfr__));

extern volatile unsigned int  U2RXREG __attribute__((__sfr__));

typedef struct tagU2RXREGBITS
{

unsigned URXREG0:
    1;
    
unsigned URXREG1:
    1;
    
unsigned URXREG2:
    1;
    
unsigned URXREG3:
    1;
    
unsigned URXREG4:
    1;
    
unsigned URXREG5:
    1;
    
unsigned URXREG6:
    1;
    
unsigned URXREG7:
    1;
    
unsigned URX8:
    1;
} U2RXREGBITS;

extern volatile U2RXREGBITS U2RXREGbits __attribute__((__sfr__));

extern volatile unsigned int  U2BRG __attribute__((__sfr__));

/* Generic structure of entire SFR area for each SPI module */

typedef struct tagSPI
{
    unsigned int spixstat;
    unsigned int spixcon1;
    unsigned int spixcon2;
    unsigned int spixbuf;
} SPI, *PSPI;

#define SPIxSTATBITS SPI1STATBITS
#define SPIxCONBITS SPI1CONBITS

/* SFR blocks for each SPI module */
extern volatile SPI SPI1 __attribute__((__sfr__));
extern volatile SPI SPI2 __attribute__((__sfr__));

extern volatile unsigned int  SPI1STAT __attribute__((__sfr__));

__extension__ typedef struct tagSPI1STATBITS
{
    union
    {
    
        struct
        {
        
unsigned SPIRBF:
            1;
            
unsigned SPITBF:
            1;
            
unsigned :
            4;
            
unsigned SPIROV:
            1;
            
unsigned :
            1;
            
unsigned BUFELM:
            3;
            
unsigned :
            2;
            
unsigned SPISIDL:
            1;
            
unsigned :
            1;
            
unsigned SPIEN:
            1;
        };
        
        struct
        {
        
unsigned :
            8;
            
unsigned BUFELM0:
            1;
            
unsigned BUFELM1:
            1;
            
unsigned BUFELM2:
            1;
        };
    };
} SPI1STATBITS;

extern volatile SPI1STATBITS SPI1STATbits __attribute__((__sfr__));

extern volatile unsigned int  SPI1CON1 __attribute__((__sfr__));

__extension__ typedef struct tagSPI1CON1BITS
{
    union
    {
    
        struct
        {
        
unsigned PPRE:
            2;
            
unsigned SPRE:
            3;
            
unsigned MSTEN:
            1;
            
unsigned CKP:
            1;
            
unsigned SSEN:
            1;
            
unsigned CKE:
            1;
            
unsigned SMP:
            1;
            
unsigned MODE16:
            1;
            
unsigned DISSDO:
            1;
            
unsigned DISSCK:
            1;
        };
        
        struct
        {
        
unsigned PPRE0:
            1;
            
unsigned PPRE1:
            1;
            
unsigned SPRE0:
            1;
            
unsigned SPRE1:
            1;
            
unsigned SPRE2:
            1;
        };
    };
} SPI1CON1BITS;

extern volatile SPI1CON1BITS SPI1CON1bits __attribute__((__sfr__));

extern volatile unsigned int  SPI1CON2 __attribute__((__sfr__));

typedef struct tagSPI1CON2BITS
{

unsigned :
    1;
    
unsigned FRMDLY:
    1;
    
unsigned :
    11;
    
unsigned FRMPOL:
    1;
    
unsigned SPIFSD:
    1;
    
unsigned FRMEN:
    1;
} SPI1CON2BITS;

extern volatile SPI1CON2BITS SPI1CON2bits __attribute__((__sfr__));

extern volatile unsigned int  SPI1BUF __attribute__((__sfr__));
extern volatile unsigned int  SPI2STAT __attribute__((__sfr__));

__extension__ typedef struct tagSPI2STATBITS
{
    union
    {
    
        struct
        {
        
unsigned SPIRBF:
            1;
            
unsigned SPITBF:
            1;
            
unsigned :
            4;
            
unsigned SPIROV:
            1;
            
unsigned :
            1;
            
unsigned BUFELM:
            3;
            
unsigned :
            2;
            
unsigned SPISIDL:
            1;
            
unsigned :
            1;
            
unsigned SPIEN:
            1;
        };
        
        struct
        {
        
unsigned :
            8;
            
unsigned BUFELM0:
            1;
            
unsigned BUFELM1:
            1;
            
unsigned BUFELM2:
            1;
        };
    };
} SPI2STATBITS;

extern volatile SPI2STATBITS SPI2STATbits __attribute__((__sfr__));

extern volatile unsigned int  SPI2CON1 __attribute__((__sfr__));

__extension__ typedef struct tagSPI2CON1BITS
{
    union
    {
    
        struct
        {
        
unsigned PPRE:
            2;
            
unsigned SPRE:
            3;
            
unsigned MSTEN:
            1;
            
unsigned CKP:
            1;
            
unsigned SSEN:
            1;
            
unsigned CKE:
            1;
            
unsigned SMP:
            1;
            
unsigned MODE16:
            1;
            
unsigned DISSDO:
            1;
            
unsigned DISSCK:
            1;
        };
        
        struct
        {
        
unsigned PPRE0:
            1;
            
unsigned PPRE1:
            1;
            
unsigned SPRE0:
            1;
            
unsigned SPRE1:
            1;
            
unsigned SPRE2:
            1;
        };
    };
} SPI2CON1BITS;

extern volatile SPI2CON1BITS SPI2CON1bits __attribute__((__sfr__));

extern volatile unsigned int  SPI2CON2 __attribute__((__sfr__));

typedef struct tagSPI2CON2BITS
{

unsigned :
    1;
    
unsigned FRMDLY:
    1;
    
unsigned :
    11;
    
unsigned FRMPOL:
    1;
    
unsigned SPIFSD:
    1;
    
unsigned FRMEN:
    1;
} SPI2CON2BITS;

extern volatile SPI2CON2BITS SPI2CON2bits __attribute__((__sfr__));

extern volatile unsigned int  SPI2BUF __attribute__((__sfr__));
extern volatile unsigned int  DCICON1 __attribute__((__sfr__));

__extension__ typedef struct tagDCICON1BITS
{
    union
    {
    
        struct
        {
        
unsigned COFSM:
            2;
            
unsigned :
            3;
            
unsigned DJST:
            1;
            
unsigned CSDOM:
            1;
            
unsigned UNFM:
            1;
            
unsigned COFSD:
            1;
            
unsigned CSCKE:
            1;
            
unsigned CSCKD:
            1;
            
unsigned DLOOP:
            1;
            
unsigned :
            1;
            
unsigned DCISIDL:
            1;
            
unsigned :
            1;
            
unsigned DCIEN:
            1;
        };
        
        struct
        {
        
unsigned COFSM0:
            1;
            
unsigned COFSM1:
            1;
        };
    };
} DCICON1BITS;

extern volatile DCICON1BITS DCICON1bits __attribute__((__sfr__));

extern volatile unsigned int  DCICON2 __attribute__((__sfr__));

__extension__ typedef struct tagDCICON2BITS
{
    union
    {
    
        struct
        {
        
unsigned WS:
            4;
            
unsigned :
            1;
            
unsigned COFSG:
            4;
            
unsigned :
            1;
            
unsigned BLEN:
            2;
        };
        
        struct
        {
        
unsigned WS0:
            1;
            
unsigned WS1:
            1;
            
unsigned WS2:
            1;
            
unsigned WS3:
            1;
            
unsigned :
            1;
            
unsigned COFSG0:
            1;
            
unsigned COFSG1:
            1;
            
unsigned COFSG2:
            1;
            
unsigned COFSG3:
            1;
            
unsigned :
            1;
            
unsigned BLEN0:
            1;
            
unsigned BLEN1:
            1;
        };
    };
} DCICON2BITS;

extern volatile DCICON2BITS DCICON2bits __attribute__((__sfr__));

extern volatile unsigned int  DCICON3 __attribute__((__sfr__));

typedef struct tagDCICON3BITS
{

unsigned BCG:
    12;
} DCICON3BITS;

extern volatile DCICON3BITS DCICON3bits __attribute__((__sfr__));

extern volatile unsigned int  DCISTAT __attribute__((__sfr__));

__extension__ typedef struct tagDCISTATBITS
{
    union
    {
    
        struct
        {
        
unsigned TMPTY:
            1;
            
unsigned TUNF:
            1;
            
unsigned RFUL:
            1;
            
unsigned ROV:
            1;
            
unsigned :
            4;
            
unsigned SLOT:
            4;
        };
        
        struct
        {
        
unsigned :
            8;
            
unsigned SLOT0:
            1;
            
unsigned SLOT1:
            1;
            
unsigned SLOT2:
            1;
            
unsigned SLOT3:
            1;
        };
    };
} DCISTATBITS;

extern volatile DCISTATBITS DCISTATbits __attribute__((__sfr__));

extern volatile unsigned int  TSCON __attribute__((__sfr__));

typedef struct tagTSCONBITS
{

unsigned TSE0:
    1;
    
unsigned TSE1:
    1;
    
unsigned TSE2:
    1;
    
unsigned TSE3:
    1;
    
unsigned TSE4:
    1;
    
unsigned TSE5:
    1;
    
unsigned TSE6:
    1;
    
unsigned TSE7:
    1;
    
unsigned TSE8:
    1;
    
unsigned TSE9:
    1;
    
unsigned TSE10:
    1;
    
unsigned TSE11:
    1;
    
unsigned TSE12:
    1;
    
unsigned TSE13:
    1;
    
unsigned TSE14:
    1;
    
unsigned TSE15:
    1;
} TSCONBITS;

extern volatile TSCONBITS TSCONbits __attribute__((__sfr__));

extern volatile unsigned int  RSCON __attribute__((__sfr__));

typedef struct tagRSCONBITS
{

unsigned RSE0:
    1;
    
unsigned RSE1:
    1;
    
unsigned RSE2:
    1;
    
unsigned RSE3:
    1;
    
unsigned RSE4:
    1;
    
unsigned RSE5:
    1;
    
unsigned RSE6:
    1;
    
unsigned RSE7:
    1;
    
unsigned RSE8:
    1;
    
unsigned RSE9:
    1;
    
unsigned RSE10:
    1;
    
unsigned RSE11:
    1;
    
unsigned RSE12:
    1;
    
unsigned RSE13:
    1;
    
unsigned RSE14:
    1;
    
unsigned RSE15:
    1;
} RSCONBITS;

extern volatile RSCONBITS RSCONbits __attribute__((__sfr__));

extern volatile unsigned int  RXBUF0 __attribute__((__sfr__));
extern volatile unsigned int  RXBUF1 __attribute__((__sfr__));
extern volatile unsigned int  RXBUF2 __attribute__((__sfr__));
extern volatile unsigned int  RXBUF3 __attribute__((__sfr__));
extern volatile unsigned int  TXBUF0 __attribute__((__sfr__));
extern volatile unsigned int  TXBUF1 __attribute__((__sfr__));
extern volatile unsigned int  TXBUF2 __attribute__((__sfr__));
extern volatile unsigned int  TXBUF3 __attribute__((__sfr__));
extern volatile unsigned int  TRISB __attribute__((__sfr__));

typedef struct tagTRISBBITS
{

unsigned TRISB0:
    1;
    
unsigned TRISB1:
    1;
    
unsigned TRISB2:
    1;
    
unsigned TRISB3:
    1;
    
unsigned TRISB4:
    1;
    
unsigned TRISB5:
    1;
    
unsigned TRISB6:
    1;
    
unsigned TRISB7:
    1;
    
unsigned TRISB8:
    1;
    
unsigned TRISB9:
    1;
    
unsigned TRISB10:
    1;
    
unsigned TRISB11:
    1;
    
unsigned TRISB12:
    1;
    
unsigned TRISB13:
    1;
    
unsigned TRISB14:
    1;
    
unsigned TRISB15:
    1;
} TRISBBITS;

extern volatile TRISBBITS TRISBbits __attribute__((__sfr__));

extern volatile unsigned int  PORTB __attribute__((__sfr__));

typedef struct tagPORTBBITS
{

unsigned RB0:
    1;
    
unsigned RB1:
    1;
    
unsigned RB2:
    1;
    
unsigned RB3:
    1;
    
unsigned RB4:
    1;
    
unsigned RB5:
    1;
    
unsigned RB6:
    1;
    
unsigned RB7:
    1;
    
unsigned RB8:
    1;
    
unsigned RB9:
    1;
    
unsigned RB10:
    1;
    
unsigned RB11:
    1;
    
unsigned RB12:
    1;
    
unsigned RB13:
    1;
    
unsigned RB14:
    1;
    
unsigned RB15:
    1;
} PORTBBITS;

extern volatile PORTBBITS PORTBbits __attribute__((__sfr__));

extern volatile unsigned int  LATB __attribute__((__sfr__));

typedef struct tagLATBBITS
{

unsigned LATB0:
    1;
    
unsigned LATB1:
    1;
    
unsigned LATB2:
    1;
    
unsigned LATB3:
    1;
    
unsigned LATB4:
    1;
    
unsigned LATB5:
    1;
    
unsigned LATB6:
    1;
    
unsigned LATB7:
    1;
    
unsigned LATB8:
    1;
    
unsigned LATB9:
    1;
    
unsigned LATB10:
    1;
    
unsigned LATB11:
    1;
    
unsigned LATB12:
    1;
    
unsigned LATB13:
    1;
    
unsigned LATB14:
    1;
    
unsigned LATB15:
    1;
} LATBBITS;

extern volatile LATBBITS LATBbits __attribute__((__sfr__));

extern volatile unsigned int  TRISC __attribute__((__sfr__));

typedef struct tagTRISCBITS
{

unsigned :
    1;
    
unsigned TRISC1:
    1;
    
unsigned TRISC2:
    1;
    
unsigned :
    9;
    
unsigned TRISC12:
    1;
    
unsigned TRISC13:
    1;
    
unsigned TRISC14:
    1;
    
unsigned TRISC15:
    1;
} TRISCBITS;

extern volatile TRISCBITS TRISCbits __attribute__((__sfr__));

extern volatile unsigned int  PORTC __attribute__((__sfr__));

typedef struct tagPORTCBITS
{

unsigned :
    1;
    
unsigned RC1:
    1;
    
unsigned RC2:
    1;
    
unsigned :
    9;
    
unsigned RC12:
    1;
    
unsigned RC13:
    1;
    
unsigned RC14:
    1;
    
unsigned RC15:
    1;
} PORTCBITS;

extern volatile PORTCBITS PORTCbits __attribute__((__sfr__));

extern volatile unsigned int  LATC __attribute__((__sfr__));

typedef struct tagLATCBITS
{

unsigned :
    1;
    
unsigned LATC1:
    1;
    
unsigned LATC2:
    1;
    
unsigned :
    9;
    
unsigned LATC12:
    1;
    
unsigned LATC13:
    1;
    
unsigned LATC14:
    1;
    
unsigned LATC15:
    1;
} LATCBITS;

extern volatile LATCBITS LATCbits __attribute__((__sfr__));

extern volatile unsigned int  TRISD __attribute__((__sfr__));

typedef struct tagTRISDBITS
{

unsigned TRISD0:
    1;
    
unsigned TRISD1:
    1;
    
unsigned TRISD2:
    1;
    
unsigned TRISD3:
    1;
    
unsigned TRISD4:
    1;
    
unsigned TRISD5:
    1;
    
unsigned TRISD6:
    1;
    
unsigned TRISD7:
    1;
    
unsigned TRISD8:
    1;
    
unsigned TRISD9:
    1;
    
unsigned TRISD10:
    1;
    
unsigned TRISD11:
    1;
} TRISDBITS;

extern volatile TRISDBITS TRISDbits __attribute__((__sfr__));

extern volatile unsigned int  PORTD __attribute__((__sfr__));

typedef struct tagPORTDBITS
{

unsigned RD0:
    1;
    
unsigned RD1:
    1;
    
unsigned RD2:
    1;
    
unsigned RD3:
    1;
    
unsigned RD4:
    1;
    
unsigned RD5:
    1;
    
unsigned RD6:
    1;
    
unsigned RD7:
    1;
    
unsigned RD8:
    1;
    
unsigned RD9:
    1;
    
unsigned RD10:
    1;
    
unsigned RD11:
    1;
} PORTDBITS;

extern volatile PORTDBITS PORTDbits __attribute__((__sfr__));

extern volatile unsigned int  LATD __attribute__((__sfr__));

typedef struct tagLATDBITS
{

unsigned LATD0:
    1;
    
unsigned LATD1:
    1;
    
unsigned LATD2:
    1;
    
unsigned LATD3:
    1;
    
unsigned LATD4:
    1;
    
unsigned LATD5:
    1;
    
unsigned LATD6:
    1;
    
unsigned LATD7:
    1;
    
unsigned LATD8:
    1;
    
unsigned LATD9:
    1;
    
unsigned LATD10:
    1;
    
unsigned LATD11:
    1;
} LATDBITS;

extern volatile LATDBITS LATDbits __attribute__((__sfr__));

extern volatile unsigned int  TRISF __attribute__((__sfr__));

typedef struct tagTRISFBITS
{

unsigned TRISF0:
    1;
    
unsigned TRISF1:
    1;
    
unsigned TRISF2:
    1;
    
unsigned TRISF3:
    1;
    
unsigned TRISF4:
    1;
    
unsigned TRISF5:
    1;
    
unsigned TRISF6:
    1;
} TRISFBITS;

extern volatile TRISFBITS TRISFbits __attribute__((__sfr__));

extern volatile unsigned int  PORTF __attribute__((__sfr__));

typedef struct tagPORTFBITS
{

unsigned RF0:
    1;
    
unsigned RF1:
    1;
    
unsigned RF2:
    1;
    
unsigned RF3:
    1;
    
unsigned RF4:
    1;
    
unsigned RF5:
    1;
    
unsigned RF6:
    1;
} PORTFBITS;

extern volatile PORTFBITS PORTFbits __attribute__((__sfr__));

extern volatile unsigned int  LATF __attribute__((__sfr__));

typedef struct tagLATFBITS
{

unsigned LATF0:
    1;
    
unsigned LATF1:
    1;
    
unsigned LATF2:
    1;
    
unsigned LATF3:
    1;
    
unsigned LATF4:
    1;
    
unsigned LATF5:
    1;
    
unsigned LATF6:
    1;
} LATFBITS;

extern volatile LATFBITS LATFbits __attribute__((__sfr__));

extern volatile unsigned int  TRISG __attribute__((__sfr__));

typedef struct tagTRISGBITS
{

unsigned TRISG0:
    1;
    
unsigned TRISG1:
    1;
    
unsigned TRISG2:
    1;
    
unsigned TRISG3:
    1;
    
unsigned :
    2;
    
unsigned TRISG6:
    1;
    
unsigned TRISG7:
    1;
    
unsigned TRISG8:
    1;
    
unsigned TRISG9:
    1;
    
unsigned :
    2;
    
unsigned TRISG12:
    1;
    
unsigned TRISG13:
    1;
    
unsigned TRISG14:
    1;
    
unsigned TRISG15:
    1;
} TRISGBITS;

extern volatile TRISGBITS TRISGbits __attribute__((__sfr__));

extern volatile unsigned int  PORTG __attribute__((__sfr__));

typedef struct tagPORTGBITS
{

unsigned RG0:
    1;
    
unsigned RG1:
    1;
    
unsigned RG2:
    1;
    
unsigned RG3:
    1;
    
unsigned :
    2;
    
unsigned RG6:
    1;
    
unsigned RG7:
    1;
    
unsigned RG8:
    1;
    
unsigned RG9:
    1;
    
unsigned :
    2;
    
unsigned RG12:
    1;
    
unsigned RG13:
    1;
    
unsigned RG14:
    1;
    
unsigned RG15:
    1;
} PORTGBITS;

extern volatile PORTGBITS PORTGbits __attribute__((__sfr__));

extern volatile unsigned int  LATG __attribute__((__sfr__));

typedef struct tagLATGBITS
{

unsigned LATG0:
    1;
    
unsigned LATG1:
    1;
    
unsigned LATG2:
    1;
    
unsigned LATG3:
    1;
    
unsigned :
    2;
    
unsigned LATG6:
    1;
    
unsigned LATG7:
    1;
    
unsigned LATG8:
    1;
    
unsigned LATG9:
    1;
    
unsigned :
    2;
    
unsigned LATG12:
    1;
    
unsigned LATG13:
    1;
    
unsigned LATG14:
    1;
    
unsigned LATG15:
    1;
} LATGBITS;

extern volatile LATGBITS LATGbits __attribute__((__sfr__));

extern volatile unsigned int  ADC1BUF0 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF0 __attribute__((__sfr__));
extern volatile unsigned int  AD1CON1 __attribute__((__sfr__));

__extension__ typedef struct tagAD1CON1BITS
{
    union
    {
    
        struct
        {
        
unsigned DONE:
            1;
            
unsigned SAMP:
            1;
            
unsigned ASAM:
            1;
            
unsigned SIMSAM:
            1;
            
unsigned :
            1;
            
unsigned SSRC:
            3;
            
unsigned FORM:
            2;
            
unsigned AD12B:
            1;
            
unsigned :
            1;
            
unsigned ADDMABM:
            1;
            
unsigned ADSIDL:
            1;
            
unsigned :
            1;
            
unsigned ADON:
            1;
        };
        
        struct
        {
        
unsigned :
            5;
            
unsigned SSRC0:
            1;
            
unsigned SSRC1:
            1;
            
unsigned SSRC2:
            1;
            
unsigned FORM0:
            1;
            
unsigned FORM1:
            1;
        };
    };
} AD1CON1BITS;

extern volatile AD1CON1BITS AD1CON1bits __attribute__((__sfr__));

extern volatile unsigned int  AD1CON2 __attribute__((__sfr__));

__extension__ typedef struct tagAD1CON2BITS
{
    union
    {
    
        struct
        {
        
unsigned ALTS:
            1;
            
unsigned BUFM:
            1;
            
unsigned SMPI:
            4;
            
unsigned :
            1;
            
unsigned BUFS:
            1;
            
unsigned CHPS:
            2;
            
unsigned CSCNA:
            1;
            
unsigned :
            2;
            
unsigned VCFG:
            3;
        };
        
        struct
        {
        
unsigned :
            2;
            
unsigned SMPI0:
            1;
            
unsigned SMPI1:
            1;
            
unsigned SMPI2:
            1;
            
unsigned SMPI3:
            1;
            
unsigned :
            2;
            
unsigned CHPS0:
            1;
            
unsigned CHPS1:
            1;
            
unsigned :
            3;
            
unsigned VCFG0:
            1;
            
unsigned VCFG1:
            1;
            
unsigned VCFG2:
            1;
        };
    };
} AD1CON2BITS;

extern volatile AD1CON2BITS AD1CON2bits __attribute__((__sfr__));

extern volatile unsigned int  AD1CON3 __attribute__((__sfr__));

__extension__ typedef struct tagAD1CON3BITS
{
    union
    {
    
        struct
        {
        
unsigned ADCS:
            8;
            
unsigned SAMC:
            5;
            
unsigned :
            2;
            
unsigned ADRC:
            1;
        };
        
        struct
        {
        
unsigned ADCS0:
            1;
            
unsigned ADCS1:
            1;
            
unsigned ADCS2:
            1;
            
unsigned ADCS3:
            1;
            
unsigned ADCS4:
            1;
            
unsigned ADCS5:
            1;
            
unsigned :
            2;
            
unsigned SAMC0:
            1;
            
unsigned SAMC1:
            1;
            
unsigned SAMC2:
            1;
            
unsigned SAMC3:
            1;
            
unsigned SAMC4:
            1;
        };
    };
} AD1CON3BITS;

extern volatile AD1CON3BITS AD1CON3bits __attribute__((__sfr__));

extern volatile unsigned int  AD1CHS123 __attribute__((__sfr__));

__extension__ typedef struct tagAD1CHS123BITS
{
    union
    {
    
        struct
        {
        
unsigned CH123SA:
            1;
            
unsigned CH123NA:
            2;
            
unsigned :
            5;
            
unsigned CH123SB:
            1;
            
unsigned CH123NB:
            2;
        };
        
        struct
        {
        
unsigned :
            1;
            
unsigned CH123NA0:
            1;
            
unsigned CH123NA1:
            1;
            
unsigned :
            6;
            
unsigned CH123NB0:
            1;
            
unsigned CH123NB1:
            1;
        };
    };
} AD1CHS123BITS;

extern volatile AD1CHS123BITS AD1CHS123bits __attribute__((__sfr__));

extern volatile unsigned int  AD1CHS0 __attribute__((__sfr__));

__extension__ typedef struct tagAD1CHS0BITS
{
    union
    {
    
        struct
        {
        
unsigned CH0SA:
            5;
            
unsigned :
            2;
            
unsigned CH0NA:
            1;
            
unsigned CH0SB:
            5;
            
unsigned :
            2;
            
unsigned CH0NB:
            1;
        };
        
        struct
        {
        
unsigned CH0SA0:
            1;
            
unsigned CH0SA1:
            1;
            
unsigned CH0SA2:
            1;
            
unsigned CH0SA3:
            1;
            
unsigned CH0SA4:
            1;
            
unsigned :
            3;
            
unsigned CH0SB0:
            1;
            
unsigned CH0SB1:
            1;
            
unsigned CH0SB2:
            1;
            
unsigned CH0SB3:
            1;
            
unsigned CH0SB4:
            1;
        };
    };
} AD1CHS0BITS;

extern volatile AD1CHS0BITS AD1CHS0bits __attribute__((__sfr__));

extern volatile unsigned int  AD1PCFGH __attribute__((__sfr__));

typedef struct tagAD1PCFGHBITS
{

unsigned PCFG16:
    1;
    
unsigned PCFG17:
    1;
} AD1PCFGHBITS;

extern volatile AD1PCFGHBITS AD1PCFGHbits __attribute__((__sfr__));

extern volatile unsigned int  AD1PCFGL __attribute__((__sfr__));

typedef struct tagAD1PCFGLBITS
{

unsigned PCFG0:
    1;
    
unsigned PCFG1:
    1;
    
unsigned PCFG2:
    1;
    
unsigned PCFG3:
    1;
    
unsigned PCFG4:
    1;
    
unsigned PCFG5:
    1;
    
unsigned PCFG6:
    1;
    
unsigned PCFG7:
    1;
    
unsigned PCFG8:
    1;
    
unsigned PCFG9:
    1;
    
unsigned PCFG10:
    1;
    
unsigned PCFG11:
    1;
    
unsigned PCFG12:
    1;
    
unsigned PCFG13:
    1;
    
unsigned PCFG14:
    1;
    
unsigned PCFG15:
    1;
} AD1PCFGLBITS;

extern volatile AD1PCFGLBITS AD1PCFGLbits __attribute__((__sfr__));

extern volatile unsigned int  ADPCFG __attribute__((__sfr__));
extern volatile unsigned int  AD1CSSH __attribute__((__sfr__));

typedef struct tagAD1CSSHBITS
{

unsigned CSS16:
    1;
    
unsigned CSS17:
    1;
} AD1CSSHBITS;

extern volatile AD1CSSHBITS AD1CSSHbits __attribute__((__sfr__));

extern volatile unsigned int  AD1CSSL __attribute__((__sfr__));

typedef struct tagAD1CSSLBITS
{

unsigned CSS0:
    1;
    
unsigned CSS1:
    1;
    
unsigned CSS2:
    1;
    
unsigned CSS3:
    1;
    
unsigned CSS4:
    1;
    
unsigned CSS5:
    1;
    
unsigned CSS6:
    1;
    
unsigned CSS7:
    1;
    
unsigned CSS8:
    1;
    
unsigned CSS9:
    1;
    
unsigned CSS10:
    1;
    
unsigned CSS11:
    1;
    
unsigned CSS12:
    1;
    
unsigned CSS13:
    1;
    
unsigned CSS14:
    1;
    
unsigned CSS15:
    1;
} AD1CSSLBITS;

extern volatile AD1CSSLBITS AD1CSSLbits __attribute__((__sfr__));

extern volatile unsigned int  AD1CON4 __attribute__((__sfr__));

__extension__ typedef struct tagAD1CON4BITS
{
    union
    {
    
        struct
        {
        
unsigned DMABL:
            3;
        };
        
        struct
        {
        
unsigned DMABL0:
            1;
            
unsigned DMABL1:
            1;
            
unsigned DMABL2:
            1;
        };
    };
} AD1CON4BITS;

extern volatile AD1CON4BITS AD1CON4bits __attribute__((__sfr__));

extern volatile unsigned int  DMA0CON __attribute__((__sfr__));

__extension__ typedef struct tagDMA0CONBITS
{
    union
    {
    
        struct
        {
        
unsigned MODE:
            2;
            
unsigned :
            2;
            
unsigned AMODE:
            2;
            
unsigned :
            5;
            
unsigned NULLW:
            1;
            
unsigned HALF:
            1;
            
unsigned DIR:
            1;
            
unsigned SIZE:
            1;
            
unsigned CHEN:
            1;
        };
        
        struct
        {
        
unsigned MODE0:
            1;
            
unsigned MODE1:
            1;
            
unsigned :
            2;
            
unsigned AMODE0:
            1;
            
unsigned AMODE1:
            1;
        };
    };
} DMA0CONBITS;

extern volatile DMA0CONBITS DMA0CONbits __attribute__((__sfr__));

extern volatile unsigned int  DMA0REQ __attribute__((__sfr__));

__extension__ typedef struct tagDMA0REQBITS
{
    union
    {
    
        struct
        {
        
unsigned IRQSEL:
            7;
            
unsigned :
            8;
            
unsigned FORCE:
            1;
        };
        
        struct
        {
        
unsigned IRQSEL0:
            1;
            
unsigned IRQSEL1:
            1;
            
unsigned IRQSEL2:
            1;
            
unsigned IRQSEL3:
            1;
            
unsigned IRQSEL4:
            1;
            
unsigned IRQSEL5:
            1;
            
unsigned IRQSEL6:
            1;
        };
    };
} DMA0REQBITS;

extern volatile DMA0REQBITS DMA0REQbits __attribute__((__sfr__));

extern volatile unsigned int  DMA0STA __attribute__((__sfr__));
extern volatile unsigned int  DMA0STB __attribute__((__sfr__));
extern volatile unsigned int  DMA0PAD __attribute__((__sfr__));
extern volatile unsigned int  DMA0CNT __attribute__((__sfr__));
extern volatile unsigned int  DMA1CON __attribute__((__sfr__));

__extension__ typedef struct tagDMA1CONBITS
{
    union
    {
    
        struct
        {
        
unsigned MODE:
            2;
            
unsigned :
            2;
            
unsigned AMODE:
            2;
            
unsigned :
            5;
            
unsigned NULLW:
            1;
            
unsigned HALF:
            1;
            
unsigned DIR:
            1;
            
unsigned SIZE:
            1;
            
unsigned CHEN:
            1;
        };
        
        struct
        {
        
unsigned MODE0:
            1;
            
unsigned MODE1:
            1;
            
unsigned :
            2;
            
unsigned AMODE0:
            1;
            
unsigned AMODE1:
            1;
        };
    };
} DMA1CONBITS;

extern volatile DMA1CONBITS DMA1CONbits __attribute__((__sfr__));

extern volatile unsigned int  DMA1REQ __attribute__((__sfr__));

__extension__ typedef struct tagDMA1REQBITS
{
    union
    {
    
        struct
        {
        
unsigned IRQSEL:
            7;
            
unsigned :
            8;
            
unsigned FORCE:
            1;
        };
        
        struct
        {
        
unsigned IRQSEL0:
            1;
            
unsigned IRQSEL1:
            1;
            
unsigned IRQSEL2:
            1;
            
unsigned IRQSEL3:
            1;
            
unsigned IRQSEL4:
            1;
            
unsigned IRQSEL5:
            1;
            
unsigned IRQSEL6:
            1;
        };
    };
} DMA1REQBITS;

extern volatile DMA1REQBITS DMA1REQbits __attribute__((__sfr__));

extern volatile unsigned int  DMA1STA __attribute__((__sfr__));
extern volatile unsigned int  DMA1STB __attribute__((__sfr__));
extern volatile unsigned int  DMA1PAD __attribute__((__sfr__));
extern volatile unsigned int  DMA1CNT __attribute__((__sfr__));
extern volatile unsigned int  DMA2CON __attribute__((__sfr__));

__extension__ typedef struct tagDMA2CONBITS
{
    union
    {
    
        struct
        {
        
unsigned MODE:
            2;
            
unsigned :
            2;
            
unsigned AMODE:
            2;
            
unsigned :
            5;
            
unsigned NULLW:
            1;
            
unsigned HALF:
            1;
            
unsigned DIR:
            1;
            
unsigned SIZE:
            1;
            
unsigned CHEN:
            1;
        };
        
        struct
        {
        
unsigned MODE0:
            1;
            
unsigned MODE1:
            1;
            
unsigned :
            2;
            
unsigned AMODE0:
            1;
            
unsigned AMODE1:
            1;
        };
    };
} DMA2CONBITS;

extern volatile DMA2CONBITS DMA2CONbits __attribute__((__sfr__));

extern volatile unsigned int  DMA2REQ __attribute__((__sfr__));

__extension__ typedef struct tagDMA2REQBITS
{
    union
    {
    
        struct
        {
        
unsigned IRQSEL:
            7;
            
unsigned :
            8;
            
unsigned FORCE:
            1;
        };
        
        struct
        {
        
unsigned IRQSEL0:
            1;
            
unsigned IRQSEL1:
            1;
            
unsigned IRQSEL2:
            1;
            
unsigned IRQSEL3:
            1;
            
unsigned IRQSEL4:
            1;
            
unsigned IRQSEL5:
            1;
            
unsigned IRQSEL6:
            1;
        };
    };
} DMA2REQBITS;

extern volatile DMA2REQBITS DMA2REQbits __attribute__((__sfr__));

extern volatile unsigned int  DMA2STA __attribute__((__sfr__));
extern volatile unsigned int  DMA2STB __attribute__((__sfr__));
extern volatile unsigned int  DMA2PAD __attribute__((__sfr__));
extern volatile unsigned int  DMA2CNT __attribute__((__sfr__));
extern volatile unsigned int  DMA3CON __attribute__((__sfr__));

__extension__ typedef struct tagDMA3CONBITS
{
    union
    {
    
        struct
        {
        
unsigned MODE:
            2;
            
unsigned :
            2;
            
unsigned AMODE:
            2;
            
unsigned :
            5;
            
unsigned NULLW:
            1;
            
unsigned HALF:
            1;
            
unsigned DIR:
            1;
            
unsigned SIZE:
            1;
            
unsigned CHEN:
            1;
        };
        
        struct
        {
        
unsigned MODE0:
            1;
            
unsigned MODE1:
            1;
            
unsigned :
            2;
            
unsigned AMODE0:
            1;
            
unsigned AMODE1:
            1;
        };
    };
} DMA3CONBITS;

extern volatile DMA3CONBITS DMA3CONbits __attribute__((__sfr__));

extern volatile unsigned int  DMA3REQ __attribute__((__sfr__));

__extension__ typedef struct tagDMA3REQBITS
{
    union
    {
    
        struct
        {
        
unsigned IRQSEL:
            7;
            
unsigned :
            8;
            
unsigned FORCE:
            1;
        };
        
        struct
        {
        
unsigned IRQSEL0:
            1;
            
unsigned IRQSEL1:
            1;
            
unsigned IRQSEL2:
            1;
            
unsigned IRQSEL3:
            1;
            
unsigned IRQSEL4:
            1;
            
unsigned IRQSEL5:
            1;
            
unsigned IRQSEL6:
            1;
        };
    };
} DMA3REQBITS;

extern volatile DMA3REQBITS DMA3REQbits __attribute__((__sfr__));

extern volatile unsigned int  DMA3STA __attribute__((__sfr__));
extern volatile unsigned int  DMA3STB __attribute__((__sfr__));
extern volatile unsigned int  DMA3PAD __attribute__((__sfr__));
extern volatile unsigned int  DMA3CNT __attribute__((__sfr__));
extern volatile unsigned int  DMA4CON __attribute__((__sfr__));

__extension__ typedef struct tagDMA4CONBITS
{
    union
    {
    
        struct
        {
        
unsigned MODE:
            2;
            
unsigned :
            2;
            
unsigned AMODE:
            2;
            
unsigned :
            5;
            
unsigned NULLW:
            1;
            
unsigned HALF:
            1;
            
unsigned DIR:
            1;
            
unsigned SIZE:
            1;
            
unsigned CHEN:
            1;
        };
        
        struct
        {
        
unsigned MODE0:
            1;
            
unsigned MODE1:
            1;
            
unsigned :
            2;
            
unsigned AMODE0:
            1;
            
unsigned AMODE1:
            1;
        };
    };
} DMA4CONBITS;

extern volatile DMA4CONBITS DMA4CONbits __attribute__((__sfr__));

extern volatile unsigned int  DMA4REQ __attribute__((__sfr__));

__extension__ typedef struct tagDMA4REQBITS
{
    union
    {
    
        struct
        {
        
unsigned IRQSEL:
            7;
            
unsigned :
            8;
            
unsigned FORCE:
            1;
        };
        
        struct
        {
        
unsigned IRQSEL0:
            1;
            
unsigned IRQSEL1:
            1;
            
unsigned IRQSEL2:
            1;
            
unsigned IRQSEL3:
            1;
            
unsigned IRQSEL4:
            1;
            
unsigned IRQSEL5:
            1;
            
unsigned IRQSEL6:
            1;
        };
    };
} DMA4REQBITS;

extern volatile DMA4REQBITS DMA4REQbits __attribute__((__sfr__));

extern volatile unsigned int  DMA4STA __attribute__((__sfr__));
extern volatile unsigned int  DMA4STB __attribute__((__sfr__));
extern volatile unsigned int  DMA4PAD __attribute__((__sfr__));
extern volatile unsigned int  DMA4CNT __attribute__((__sfr__));
extern volatile unsigned int  DMA5CON __attribute__((__sfr__));

__extension__ typedef struct tagDMA5CONBITS
{
    union
    {
    
        struct
        {
        
unsigned MODE:
            2;
            
unsigned :
            2;
            
unsigned AMODE:
            2;
            
unsigned :
            5;
            
unsigned NULLW:
            1;
            
unsigned HALF:
            1;
            
unsigned DIR:
            1;
            
unsigned SIZE:
            1;
            
unsigned CHEN:
            1;
        };
        
        struct
        {
        
unsigned MODE0:
            1;
            
unsigned MODE1:
            1;
            
unsigned :
            2;
            
unsigned AMODE0:
            1;
            
unsigned AMODE1:
            1;
        };
    };
} DMA5CONBITS;

extern volatile DMA5CONBITS DMA5CONbits __attribute__((__sfr__));

extern volatile unsigned int  DMA5REQ __attribute__((__sfr__));

__extension__ typedef struct tagDMA5REQBITS
{
    union
    {
    
        struct
        {
        
unsigned IRQSEL:
            7;
            
unsigned :
            8;
            
unsigned FORCE:
            1;
        };
        
        struct
        {
        
unsigned IRQSEL0:
            1;
            
unsigned IRQSEL1:
            1;
            
unsigned IRQSEL2:
            1;
            
unsigned IRQSEL3:
            1;
            
unsigned IRQSEL4:
            1;
            
unsigned IRQSEL5:
            1;
            
unsigned IRQSEL6:
            1;
        };
    };
} DMA5REQBITS;

extern volatile DMA5REQBITS DMA5REQbits __attribute__((__sfr__));

extern volatile unsigned int  DMA5STA __attribute__((__sfr__));
extern volatile unsigned int  DMA5STB __attribute__((__sfr__));
extern volatile unsigned int  DMA5PAD __attribute__((__sfr__));
extern volatile unsigned int  DMA5CNT __attribute__((__sfr__));
extern volatile unsigned int  DMA6CON __attribute__((__sfr__));

__extension__ typedef struct tagDMA6CONBITS
{
    union
    {
    
        struct
        {
        
unsigned MODE:
            2;
            
unsigned :
            2;
            
unsigned AMODE:
            2;
            
unsigned :
            5;
            
unsigned NULLW:
            1;
            
unsigned HALF:
            1;
            
unsigned DIR:
            1;
            
unsigned SIZE:
            1;
            
unsigned CHEN:
            1;
        };
        
        struct
        {
        
unsigned MODE0:
            1;
            
unsigned MODE1:
            1;
            
unsigned :
            2;
            
unsigned AMODE0:
            1;
            
unsigned AMODE1:
            1;
        };
    };
} DMA6CONBITS;

extern volatile DMA6CONBITS DMA6CONbits __attribute__((__sfr__));

extern volatile unsigned int  DMA6REQ __attribute__((__sfr__));

__extension__ typedef struct tagDMA6REQBITS
{
    union
    {
    
        struct
        {
        
unsigned IRQSEL:
            7;
            
unsigned :
            8;
            
unsigned FORCE:
            1;
        };
        
        struct
        {
        
unsigned IRQSEL0:
            1;
            
unsigned IRQSEL1:
            1;
            
unsigned IRQSEL2:
            1;
            
unsigned IRQSEL3:
            1;
            
unsigned IRQSEL4:
            1;
            
unsigned IRQSEL5:
            1;
            
unsigned IRQSEL6:
            1;
        };
    };
} DMA6REQBITS;

extern volatile DMA6REQBITS DMA6REQbits __attribute__((__sfr__));

extern volatile unsigned int  DMA6STA __attribute__((__sfr__));
extern volatile unsigned int  DMA6STB __attribute__((__sfr__));
extern volatile unsigned int  DMA6PAD __attribute__((__sfr__));
extern volatile unsigned int  DMA6CNT __attribute__((__sfr__));
extern volatile unsigned int  DMA7CON __attribute__((__sfr__));

__extension__ typedef struct tagDMA7CONBITS
{
    union
    {
    
        struct
        {
        
unsigned MODE:
            2;
            
unsigned :
            2;
            
unsigned AMODE:
            2;
            
unsigned :
            5;
            
unsigned NULLW:
            1;
            
unsigned HALF:
            1;
            
unsigned DIR:
            1;
            
unsigned SIZE:
            1;
            
unsigned CHEN:
            1;
        };
        
        struct
        {
        
unsigned MODE0:
            1;
            
unsigned MODE1:
            1;
            
unsigned :
            2;
            
unsigned AMODE0:
            1;
            
unsigned AMODE1:
            1;
        };
    };
} DMA7CONBITS;

extern volatile DMA7CONBITS DMA7CONbits __attribute__((__sfr__));

extern volatile unsigned int  DMA7REQ __attribute__((__sfr__));

__extension__ typedef struct tagDMA7REQBITS
{
    union
    {
    
        struct
        {
        
unsigned IRQSEL:
            7;
            
unsigned :
            8;
            
unsigned FORCE:
            1;
        };
        
        struct
        {
        
unsigned IRQSEL0:
            1;
            
unsigned IRQSEL1:
            1;
            
unsigned IRQSEL2:
            1;
            
unsigned IRQSEL3:
            1;
            
unsigned IRQSEL4:
            1;
            
unsigned IRQSEL5:
            1;
            
unsigned IRQSEL6:
            1;
        };
    };
} DMA7REQBITS;

extern volatile DMA7REQBITS DMA7REQbits __attribute__((__sfr__));

extern volatile unsigned int  DMA7STA __attribute__((__sfr__));
extern volatile unsigned int  DMA7STB __attribute__((__sfr__));
extern volatile unsigned int  DMA7PAD __attribute__((__sfr__));
extern volatile unsigned int  DMA7CNT __attribute__((__sfr__));
extern volatile unsigned int  DMACS0 __attribute__((__sfr__));

__extension__ typedef struct tagDMACS0BITS
{
    union
    {
    
        struct
        {
        
unsigned XWCOL:
            8;
            
unsigned PWCOL:
            8;
        };
        
        struct
        {
        
unsigned XWCOL0:
            1;
            
unsigned XWCOL1:
            1;
            
unsigned XWCOL2:
            1;
            
unsigned XWCOL3:
            1;
            
unsigned XWCOL4:
            1;
            
unsigned XWCOL5:
            1;
            
unsigned XWCOL6:
            1;
            
unsigned XWCOL7:
            1;
            
unsigned PWCOL0:
            1;
            
unsigned PWCOL1:
            1;
            
unsigned PWCOL2:
            1;
            
unsigned PWCOL3:
            1;
            
unsigned PWCOL4:
            1;
            
unsigned PWCOL5:
            1;
            
unsigned PWCOL6:
            1;
            
unsigned PWCOL7:
            1;
        };
    };
} DMACS0BITS;

extern volatile DMACS0BITS DMACS0bits __attribute__((__sfr__));

extern volatile unsigned int  DMACS1 __attribute__((__sfr__));

__extension__ typedef struct tagDMACS1BITS
{
    union
    {
    
        struct
        {
        
unsigned PPST:
            8;
            
unsigned LSTCH:
            4;
        };
        
        struct
        {
        
unsigned PPST0:
            1;
            
unsigned PPST1:
            1;
            
unsigned PPST2:
            1;
            
unsigned PPST3:
            1;
            
unsigned PPST4:
            1;
            
unsigned PPST5:
            1;
            
unsigned PPST6:
            1;
            
unsigned PPST7:
            1;
            
unsigned LSTCH0:
            1;
            
unsigned LSTCH1:
            1;
            
unsigned LSTCH2:
            1;
            
unsigned LSTCH3:
            1;
        };
    };
} DMACS1BITS;

extern volatile DMACS1BITS DMACS1bits __attribute__((__sfr__));

extern volatile unsigned int  DSADR __attribute__((__sfr__));
extern volatile unsigned int  C1CTRL1 __attribute__((__sfr__));

__extension__ typedef struct tagC1CTRL1BITS
{
    union
    {
    
        struct
        {
        
unsigned WIN:
            1;
            
unsigned :
            2;
            
unsigned CANCAP:
            1;
            
unsigned :
            1;
            
unsigned OPMODE:
            3;
            
unsigned REQOP:
            3;
            
unsigned CANCKS:
            1;
            
unsigned ABAT:
            1;
            
unsigned CSIDL:
            1;
        };
        
        struct
        {
        
unsigned :
            5;
            
unsigned OPMODE0:
            1;
            
unsigned OPMODE1:
            1;
            
unsigned OPMODE2:
            1;
            
unsigned REQOP0:
            1;
            
unsigned REQOP1:
            1;
            
unsigned REQOP2:
            1;
        };
    };
} C1CTRL1BITS;

extern volatile C1CTRL1BITS C1CTRL1bits __attribute__((__sfr__));

extern volatile unsigned int  C1CTRL2 __attribute__((__sfr__));

__extension__ typedef struct tagC1CTRL2BITS
{
    union
    {
    
        struct
        {
        
unsigned DNCNT:
            5;
        };
        
        struct
        {
        
unsigned DNCNT0:
            1;
            
unsigned DNCNT1:
            1;
            
unsigned DNCNT2:
            1;
            
unsigned DNCNT3:
            1;
            
unsigned DNCNT4:
            1;
        };
    };
} C1CTRL2BITS;

extern volatile C1CTRL2BITS C1CTRL2bits __attribute__((__sfr__));

extern volatile unsigned int  C1VEC __attribute__((__sfr__));

__extension__ typedef struct tagC1VECBITS
{
    union
    {
    
        struct
        {
        
unsigned ICODE:
            7;
            
unsigned :
            1;
            
unsigned FILHIT:
            5;
        };
        
        struct
        {
        
unsigned ICODE0:
            1;
            
unsigned ICODE1:
            1;
            
unsigned ICODE2:
            1;
            
unsigned ICODE3:
            1;
            
unsigned ICODE4:
            1;
            
unsigned ICODE5:
            1;
            
unsigned ICODE6:
            1;
            
unsigned :
            1;
            
unsigned FILHIT0:
            1;
            
unsigned FILHIT1:
            1;
            
unsigned FILHIT2:
            1;
            
unsigned FILHIT3:
            1;
            
unsigned FILHIT4:
            1;
        };
    };
} C1VECBITS;

extern volatile C1VECBITS C1VECbits __attribute__((__sfr__));

extern volatile unsigned int  C1FCTRL __attribute__((__sfr__));

__extension__ typedef struct tagC1FCTRLBITS
{
    union
    {
    
        struct
        {
        
unsigned FSA:
            5;
            
unsigned :
            8;
            
unsigned DMABS:
            3;
        };
        
        struct
        {
        
unsigned FSA0:
            1;
            
unsigned FSA1:
            1;
            
unsigned FSA2:
            1;
            
unsigned FSA3:
            1;
            
unsigned FSA4:
            1;
            
unsigned :
            8;
            
unsigned DMABS0:
            1;
            
unsigned DMABS1:
            1;
            
unsigned DMABS2:
            1;
        };
    };
} C1FCTRLBITS;

extern volatile C1FCTRLBITS C1FCTRLbits __attribute__((__sfr__));

extern volatile unsigned int  C1FIFO __attribute__((__sfr__));

__extension__ typedef struct tagC1FIFOBITS
{
    union
    {
    
        struct
        {
        
unsigned FNRB:
            6;
            
unsigned :
            2;
            
unsigned FBP:
            6;
        };
        
        struct
        {
        
unsigned FNRB0:
            1;
            
unsigned FNRB1:
            1;
            
unsigned FNRB2:
            1;
            
unsigned FNRB3:
            1;
            
unsigned FNRB4:
            1;
            
unsigned FNRB5:
            1;
            
unsigned :
            2;
            
unsigned FBP0:
            1;
            
unsigned FBP1:
            1;
            
unsigned FBP2:
            1;
            
unsigned FBP3:
            1;
            
unsigned FBP4:
            1;
            
unsigned FBP5:
            1;
        };
    };
} C1FIFOBITS;

extern volatile C1FIFOBITS C1FIFObits __attribute__((__sfr__));

extern volatile unsigned int  C1INTF __attribute__((__sfr__));

typedef struct tagC1INTFBITS
{

unsigned TBIF:
    1;
    
unsigned RBIF:
    1;
    
unsigned RBOVIF:
    1;
    
unsigned FIFOIF:
    1;
    
unsigned :
    1;
    
unsigned ERRIF:
    1;
    
unsigned WAKIF:
    1;
    
unsigned IVRIF:
    1;
    
unsigned EWARN:
    1;
    
unsigned RXWAR:
    1;
    
unsigned TXWAR:
    1;
    
unsigned RXBP:
    1;
    
unsigned TXBP:
    1;
    
unsigned TXBO:
    1;
} C1INTFBITS;

extern volatile C1INTFBITS C1INTFbits __attribute__((__sfr__));

extern volatile unsigned int  C1INTE __attribute__((__sfr__));

typedef struct tagC1INTEBITS
{

unsigned TBIE:
    1;
    
unsigned RBIE:
    1;
    
unsigned RBOVIE:
    1;
    
unsigned FIFOIE:
    1;
    
unsigned :
    1;
    
unsigned ERRIE:
    1;
    
unsigned WAKIE:
    1;
    
unsigned IVRIE:
    1;
} C1INTEBITS;

extern volatile C1INTEBITS C1INTEbits __attribute__((__sfr__));

extern volatile unsigned int  C1EC __attribute__((__sfr__));

__extension__ typedef struct tagC1ECBITS
{
    union
    {
    
        struct
        {
        
unsigned RERRCNT:
            8;
            
unsigned TERRCNT:
            8;
        };
        
        struct
        {
        
unsigned RERRCNT0:
            1;
            
unsigned RERRCNT1:
            1;
            
unsigned RERRCNT2:
            1;
            
unsigned RERRCNT3:
            1;
            
unsigned RERRCNT4:
            1;
            
unsigned RERRCNT5:
            1;
            
unsigned RERRCNT6:
            1;
            
unsigned RERRCNT7:
            1;
            
unsigned TERRCNT0:
            1;
            
unsigned TERRCNT1:
            1;
            
unsigned TERRCNT2:
            1;
            
unsigned TERRCNT3:
            1;
            
unsigned TERRCNT4:
            1;
            
unsigned TERRCNT5:
            1;
            
unsigned TERRCNT6:
            1;
            
unsigned TERRCNT7:
            1;
        };
    };
} C1ECBITS;

extern volatile C1ECBITS C1ECbits __attribute__((__sfr__));

extern volatile unsigned char C1RERRCNT __attribute__((__sfr__));
extern volatile unsigned char C1TERRCNT __attribute__((__sfr__));
extern volatile unsigned int  C1CFG1 __attribute__((__sfr__));

__extension__ typedef struct tagC1CFG1BITS
{
    union
    {
    
        struct
        {
        
unsigned BRP:
            6;
            
unsigned SJW:
            2;
        };
        
        struct
        {
        
unsigned BRP0:
            1;
            
unsigned BRP1:
            1;
            
unsigned BRP2:
            1;
            
unsigned BRP3:
            1;
            
unsigned BRP4:
            1;
            
unsigned BRP5:
            1;
            
unsigned SJW0:
            1;
            
unsigned SJW1:
            1;
        };
    };
} C1CFG1BITS;

extern volatile C1CFG1BITS C1CFG1bits __attribute__((__sfr__));

extern volatile unsigned int  C1CFG2 __attribute__((__sfr__));

__extension__ typedef struct tagC1CFG2BITS
{
    union
    {
    
        struct
        {
        
unsigned PRSEG:
            3;
            
unsigned SEG1PH:
            3;
            
unsigned SAM:
            1;
            
unsigned SEG2PHTS:
            1;
            
unsigned SEG2PH:
            3;
            
unsigned :
            3;
            
unsigned WAKFIL:
            1;
        };
        
        struct
        {
        
unsigned PRSEG0:
            1;
            
unsigned PRSEG1:
            1;
            
unsigned PRSEG2:
            1;
            
unsigned SEG1PH0:
            1;
            
unsigned SEG1PH1:
            1;
            
unsigned SEG1PH2:
            1;
            
unsigned :
            2;
            
unsigned SEG2PH0:
            1;
            
unsigned SEG2PH1:
            1;
            
unsigned SEG2PH2:
            1;
        };
    };
} C1CFG2BITS;

extern volatile C1CFG2BITS C1CFG2bits __attribute__((__sfr__));

extern volatile unsigned int  C1FEN1 __attribute__((__sfr__));

__extension__ typedef struct tagC1FEN1BITS
{
    union
    {
    
        struct
        {
        
unsigned FLTEN:
            16;
        };
        
        struct
        {
        
unsigned FLTEN0:
            1;
            
unsigned FLTEN1:
            1;
            
unsigned FLTEN2:
            1;
            
unsigned FLTEN3:
            1;
            
unsigned FLTEN4:
            1;
            
unsigned FLTEN5:
            1;
            
unsigned FLTEN6:
            1;
            
unsigned FLTEN7:
            1;
            
unsigned FLTEN8:
            1;
            
unsigned FLTEN9:
            1;
            
unsigned FLTEN10:
            1;
            
unsigned FLTEN11:
            1;
            
unsigned FLTEN12:
            1;
            
unsigned FLTEN13:
            1;
            
unsigned FLTEN14:
            1;
            
unsigned FLTEN15:
            1;
        };
    };
} C1FEN1BITS;

extern volatile C1FEN1BITS C1FEN1bits __attribute__((__sfr__));

extern volatile unsigned int  C1FMSKSEL1 __attribute__((__sfr__));

__extension__ typedef struct tagC1FMSKSEL1BITS
{
    union
    {
    
        struct
        {
        
unsigned F0MSK:
            2;
            
unsigned F1MSK:
            2;
            
unsigned F2MSK:
            2;
            
unsigned F3MSK:
            2;
            
unsigned F4MSK:
            2;
            
unsigned F5MSK:
            2;
            
unsigned F6MSK:
            2;
            
unsigned F7MSK:
            2;
        };
        
        struct
        {
        
unsigned F0MSK0:
            1;
            
unsigned F0MSK1:
            1;
            
unsigned F1MSK0:
            1;
            
unsigned F1MSK1:
            1;
            
unsigned F2MSK0:
            1;
            
unsigned F2MSK1:
            1;
            
unsigned F3MSK0:
            1;
            
unsigned F3MSK1:
            1;
            
unsigned F4MSK0:
            1;
            
unsigned F4MSK1:
            1;
            
unsigned F5MSK0:
            1;
            
unsigned F5MSK1:
            1;
            
unsigned F6MSK0:
            1;
            
unsigned F6MSK1:
            1;
            
unsigned F7MSK0:
            1;
            
unsigned F7MSK1:
            1;
        };
    };
} C1FMSKSEL1BITS;

extern volatile C1FMSKSEL1BITS C1FMSKSEL1bits __attribute__((__sfr__));

extern volatile unsigned int  C1FMSKSEL2 __attribute__((__sfr__));

__extension__ typedef struct tagC1FMSKSEL2BITS
{
    union
    {
    
        struct
        {
        
unsigned F8MSK:
            2;
            
unsigned F9MSK:
            2;
            
unsigned F10MSK:
            2;
            
unsigned F11MSK:
            2;
            
unsigned F12MSK:
            2;
            
unsigned F13MSK:
            2;
            
unsigned F14MSK:
            2;
            
unsigned F15MSK:
            2;
        };
        
        struct
        {
        
unsigned F8MSK0:
            1;
            
unsigned F8MSK1:
            1;
            
unsigned F9MSK0:
            1;
            
unsigned F9MSK1:
            1;
            
unsigned F10MSK0:
            1;
            
unsigned F10MSK1:
            1;
            
unsigned F11MSK0:
            1;
            
unsigned F11MSK1:
            1;
            
unsigned F12MSK0:
            1;
            
unsigned F12MSK1:
            1;
            
unsigned F13MSK0:
            1;
            
unsigned F13MSK1:
            1;
            
unsigned F14MSK0:
            1;
            
unsigned F14MSK1:
            1;
            
unsigned F15MSK0:
            1;
            
unsigned F15MSK1:
            1;
        };
    };
} C1FMSKSEL2BITS;

extern volatile C1FMSKSEL2BITS C1FMSKSEL2bits __attribute__((__sfr__));

extern volatile unsigned int  C1BUFPNT1 __attribute__((__sfr__));

__extension__ typedef struct tagC1BUFPNT1BITS
{
    union
    {
    
        struct
        {
        
unsigned F0BP:
            4;
            
unsigned F1BP:
            4;
            
unsigned F2BP:
            4;
            
unsigned F3BP:
            4;
        };
        
        struct
        {
        
unsigned F0BP0:
            1;
            
unsigned F0BP1:
            1;
            
unsigned F0BP2:
            1;
            
unsigned F0BP3:
            1;
            
unsigned F1BP0:
            1;
            
unsigned F1BP1:
            1;
            
unsigned F1BP2:
            1;
            
unsigned F1BP3:
            1;
            
unsigned F2BP0:
            1;
            
unsigned F2BP1:
            1;
            
unsigned F2BP2:
            1;
            
unsigned F2BP3:
            1;
            
unsigned F3BP0:
            1;
            
unsigned F3BP1:
            1;
            
unsigned F3BP2:
            1;
            
unsigned F3BP3:
            1;
        };
    };
} C1BUFPNT1BITS;

extern volatile C1BUFPNT1BITS C1BUFPNT1bits __attribute__((__sfr__));

extern volatile unsigned int  C1RXFUL1 __attribute__((__sfr__));

typedef struct tagC1RXFUL1BITS
{

unsigned RXFUL0:
    1;
    
unsigned RXFUL1:
    1;
    
unsigned RXFUL2:
    1;
    
unsigned RXFUL3:
    1;
    
unsigned RXFUL4:
    1;
    
unsigned RXFUL5:
    1;
    
unsigned RXFUL6:
    1;
    
unsigned RXFUL7:
    1;
    
unsigned RXFUL8:
    1;
    
unsigned RXFUL9:
    1;
    
unsigned RXFUL10:
    1;
    
unsigned RXFUL11:
    1;
    
unsigned RXFUL12:
    1;
    
unsigned RXFUL13:
    1;
    
unsigned RXFUL14:
    1;
    
unsigned RXFUL15:
    1;
} C1RXFUL1BITS;

extern volatile C1RXFUL1BITS C1RXFUL1bits __attribute__((__sfr__));

extern volatile unsigned int  C1BUFPNT2 __attribute__((__sfr__));

__extension__ typedef struct tagC1BUFPNT2BITS
{
    union
    {
    
        struct
        {
        
unsigned F4BP:
            4;
            
unsigned F5BP:
            4;
            
unsigned F6BP:
            4;
            
unsigned F7BP:
            4;
        };
        
        struct
        {
        
unsigned F4BP0:
            1;
            
unsigned F4BP1:
            1;
            
unsigned F4BP2:
            1;
            
unsigned F4BP3:
            1;
            
unsigned F5BP0:
            1;
            
unsigned F5BP1:
            1;
            
unsigned F5BP2:
            1;
            
unsigned F5BP3:
            1;
            
unsigned F6BP0:
            1;
            
unsigned F6BP1:
            1;
            
unsigned F6BP2:
            1;
            
unsigned F6BP3:
            1;
            
unsigned F7BP0:
            1;
            
unsigned F7BP1:
            1;
            
unsigned F7BP2:
            1;
            
unsigned F7BP3:
            1;
        };
    };
} C1BUFPNT2BITS;

extern volatile C1BUFPNT2BITS C1BUFPNT2bits __attribute__((__sfr__));

extern volatile unsigned int  C1RXFUL2 __attribute__((__sfr__));

typedef struct tagC1RXFUL2BITS
{

unsigned RXFUL16:
    1;
    
unsigned RXFUL17:
    1;
    
unsigned RXFUL18:
    1;
    
unsigned RXFUL19:
    1;
    
unsigned RXFUL20:
    1;
    
unsigned RXFUL21:
    1;
    
unsigned RXFUL22:
    1;
    
unsigned RXFUL23:
    1;
    
unsigned RXFUL24:
    1;
    
unsigned RXFUL25:
    1;
    
unsigned RXFUL26:
    1;
    
unsigned RXFUL27:
    1;
    
unsigned RXFUL28:
    1;
    
unsigned RXFUL29:
    1;
    
unsigned RXFUL30:
    1;
    
unsigned RXFUL31:
    1;
} C1RXFUL2BITS;

extern volatile C1RXFUL2BITS C1RXFUL2bits __attribute__((__sfr__));

extern volatile unsigned int  C1BUFPNT3 __attribute__((__sfr__));

__extension__ typedef struct tagC1BUFPNT3BITS
{
    union
    {
    
        struct
        {
        
unsigned F8BP:
            4;
            
unsigned F9BP:
            4;
            
unsigned F10BP:
            4;
            
unsigned F11BP:
            4;
        };
        
        struct
        {
        
unsigned F8BP0:
            1;
            
unsigned F8BP1:
            1;
            
unsigned F8BP2:
            1;
            
unsigned F8BP3:
            1;
            
unsigned F9BP0:
            1;
            
unsigned F9BP1:
            1;
            
unsigned F9BP2:
            1;
            
unsigned F9BP3:
            1;
            
unsigned F10BP0:
            1;
            
unsigned F10BP1:
            1;
            
unsigned F10BP2:
            1;
            
unsigned F10BP3:
            1;
            
unsigned F11BP0:
            1;
            
unsigned F11BP1:
            1;
            
unsigned F11BP2:
            1;
            
unsigned F11BP3:
            1;
        };
    };
} C1BUFPNT3BITS;

extern volatile C1BUFPNT3BITS C1BUFPNT3bits __attribute__((__sfr__));

extern volatile unsigned int  C1BUFPNT4 __attribute__((__sfr__));

__extension__ typedef struct tagC1BUFPNT4BITS
{
    union
    {
    
        struct
        {
        
unsigned F12BP:
            4;
            
unsigned F13BP:
            4;
            
unsigned F14BP:
            4;
            
unsigned F15BP:
            4;
        };
        
        struct
        {
        
unsigned F12BP0:
            1;
            
unsigned F12BP1:
            1;
            
unsigned F12BP2:
            1;
            
unsigned F12BP3:
            1;
            
unsigned F13BP0:
            1;
            
unsigned F13BP1:
            1;
            
unsigned F13BP2:
            1;
            
unsigned F13BP3:
            1;
            
unsigned F14BP0:
            1;
            
unsigned F14BP1:
            1;
            
unsigned F14BP2:
            1;
            
unsigned F14BP3:
            1;
            
unsigned F15BP0:
            1;
            
unsigned F15BP1:
            1;
            
unsigned F15BP2:
            1;
            
unsigned F15BP3:
            1;
        };
    };
} C1BUFPNT4BITS;

extern volatile C1BUFPNT4BITS C1BUFPNT4bits __attribute__((__sfr__));

extern volatile unsigned int  C1RXOVF1 __attribute__((__sfr__));

typedef struct tagC1RXOVF1BITS
{

unsigned RXOVF0:
    1;
    
unsigned RXOVF1:
    1;
    
unsigned RXOVF2:
    1;
    
unsigned RXOVF3:
    1;
    
unsigned RXOVF4:
    1;
    
unsigned RXOVF5:
    1;
    
unsigned RXOVF6:
    1;
    
unsigned RXOVF7:
    1;
    
unsigned RXOVF8:
    1;
    
unsigned RXOVF9:
    1;
    
unsigned RXOVF10:
    1;
    
unsigned RXOVF11:
    1;
    
unsigned RXOVF12:
    1;
    
unsigned RXOVF13:
    1;
    
unsigned RXOVF14:
    1;
    
unsigned RXOVF15:
    1;
} C1RXOVF1BITS;

extern volatile C1RXOVF1BITS C1RXOVF1bits __attribute__((__sfr__));

extern volatile unsigned int  C1RXOVF2 __attribute__((__sfr__));

typedef struct tagC1RXOVF2BITS
{

unsigned RXOVF16:
    1;
    
unsigned RXOVF17:
    1;
    
unsigned RXOVF18:
    1;
    
unsigned RXOVF19:
    1;
    
unsigned RXOVF20:
    1;
    
unsigned RXOVF21:
    1;
    
unsigned RXOVF22:
    1;
    
unsigned RXOVF23:
    1;
    
unsigned RXOVF24:
    1;
    
unsigned RXOVF25:
    1;
    
unsigned RXOVF26:
    1;
    
unsigned RXOVF27:
    1;
    
unsigned RXOVF28:
    1;
    
unsigned RXOVF29:
    1;
    
unsigned RXOVF30:
    1;
    
unsigned RXOVF31:
    1;
} C1RXOVF2BITS;

extern volatile C1RXOVF2BITS C1RXOVF2bits __attribute__((__sfr__));

extern volatile unsigned int  C1RXM0SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXM0SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned MIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXM0SIDBITS;

extern volatile C1RXM0SIDBITS C1RXM0SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1TR01CON __attribute__((__sfr__));

__extension__ typedef struct tagC1TR01CONBITS
{
    union
    {
    
        struct
        {
        
unsigned TX0PRI:
            2;
            
unsigned RTREN0:
            1;
            
unsigned TXREQ0:
            1;
            
unsigned TXERR0:
            1;
            
unsigned TXLARB0:
            1;
            
unsigned TXABT0:
            1;
            
unsigned TXEN0:
            1;
            
unsigned TX1PRI:
            2;
            
unsigned RTREN1:
            1;
            
unsigned TXREQ1:
            1;
            
unsigned TXERR1:
            1;
            
unsigned TXLARB1:
            1;
            
unsigned TXABT1:
            1;
            
unsigned TXEN1:
            1;
        };
        
        struct
        {
        
unsigned TX0PRI0:
            1;
            
unsigned TX0PRI1:
            1;
            
unsigned :
            6;
            
unsigned TX1PRI0:
            1;
            
unsigned TX1PRI1:
            1;
        };
    };
} C1TR01CONBITS;

extern volatile C1TR01CONBITS C1TR01CONbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXM0EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXM0EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXM0EIDBITS;

extern volatile C1RXM0EIDBITS C1RXM0EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1TR23CON __attribute__((__sfr__));

__extension__ typedef struct tagC1TR23CONBITS
{
    union
    {
    
        struct
        {
        
unsigned TX2PRI:
            2;
            
unsigned RTREN2:
            1;
            
unsigned TXREQ2:
            1;
            
unsigned TXERR2:
            1;
            
unsigned TXLARB2:
            1;
            
unsigned TXABT2:
            1;
            
unsigned TXEN2:
            1;
            
unsigned TX3PRI:
            2;
            
unsigned RTREN3:
            1;
            
unsigned TXREQ3:
            1;
            
unsigned TXERR3:
            1;
            
unsigned TXLARB3:
            1;
            
unsigned TXABT3:
            1;
            
unsigned TXEN3:
            1;
        };
        
        struct
        {
        
unsigned TX2PRI0:
            1;
            
unsigned TX2PRI1:
            1;
            
unsigned :
            6;
            
unsigned TX3PRI0:
            1;
            
unsigned TX3PRI1:
            1;
        };
    };
} C1TR23CONBITS;

extern volatile C1TR23CONBITS C1TR23CONbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXM1SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXM1SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned MIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXM1SIDBITS;

extern volatile C1RXM1SIDBITS C1RXM1SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1TR45CON __attribute__((__sfr__));

__extension__ typedef struct tagC1TR45CONBITS
{
    union
    {
    
        struct
        {
        
unsigned TX4PRI:
            2;
            
unsigned RTREN4:
            1;
            
unsigned TXREQ4:
            1;
            
unsigned TXERR4:
            1;
            
unsigned TXLARB4:
            1;
            
unsigned TXABT4:
            1;
            
unsigned TXEN4:
            1;
            
unsigned TX5PRI:
            2;
            
unsigned RTREN5:
            1;
            
unsigned TXREQ5:
            1;
            
unsigned TXERR5:
            1;
            
unsigned TXLARB5:
            1;
            
unsigned TXABT5:
            1;
            
unsigned TXEN5:
            1;
        };
        
        struct
        {
        
unsigned TX4PRI0:
            1;
            
unsigned TX4PRI1:
            1;
            
unsigned :
            6;
            
unsigned TX5PRI0:
            1;
            
unsigned TX5PRI1:
            1;
        };
    };
} C1TR45CONBITS;

extern volatile C1TR45CONBITS C1TR45CONbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXM1EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXM1EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXM1EIDBITS;

extern volatile C1RXM1EIDBITS C1RXM1EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1TR67CON __attribute__((__sfr__));

__extension__ typedef struct tagC1TR67CONBITS
{
    union
    {
    
        struct
        {
        
unsigned TX6PRI:
            2;
            
unsigned RTREN6:
            1;
            
unsigned TXREQ6:
            1;
            
unsigned TXERR6:
            1;
            
unsigned TXLARB6:
            1;
            
unsigned TXABT6:
            1;
            
unsigned TXEN6:
            1;
            
unsigned TX7PRI:
            2;
            
unsigned RTREN7:
            1;
            
unsigned TXREQ7:
            1;
            
unsigned TXERR7:
            1;
            
unsigned TXLARB7:
            1;
            
unsigned TXABT7:
            1;
            
unsigned TXEN7:
            1;
        };
        
        struct
        {
        
unsigned TX6PRI0:
            1;
            
unsigned TX6PRI1:
            1;
            
unsigned :
            6;
            
unsigned TX7PRI0:
            1;
            
unsigned TX7PRI1:
            1;
        };
    };
} C1TR67CONBITS;

extern volatile C1TR67CONBITS C1TR67CONbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXM2SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXM2SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned MIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXM2SIDBITS;

extern volatile C1RXM2SIDBITS C1RXM2SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXM2EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXM2EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXM2EIDBITS;

extern volatile C1RXM2EIDBITS C1RXM2EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXD __attribute__((__sfr__));
extern volatile unsigned int  C1RXF0SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF0SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned EXIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXF0SIDBITS;

extern volatile C1RXF0SIDBITS C1RXF0SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF0EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF0EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXF0EIDBITS;

extern volatile C1RXF0EIDBITS C1RXF0EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1TXD __attribute__((__sfr__));
extern volatile unsigned int  C1RXF1SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF1SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned EXIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXF1SIDBITS;

extern volatile C1RXF1SIDBITS C1RXF1SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF1EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF1EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXF1EIDBITS;

extern volatile C1RXF1EIDBITS C1RXF1EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF2SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF2SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned EXIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXF2SIDBITS;

extern volatile C1RXF2SIDBITS C1RXF2SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF2EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF2EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXF2EIDBITS;

extern volatile C1RXF2EIDBITS C1RXF2EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF3SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF3SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned EXIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXF3SIDBITS;

extern volatile C1RXF3SIDBITS C1RXF3SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF3EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF3EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXF3EIDBITS;

extern volatile C1RXF3EIDBITS C1RXF3EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF4SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF4SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned EXIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXF4SIDBITS;

extern volatile C1RXF4SIDBITS C1RXF4SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF4EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF4EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXF4EIDBITS;

extern volatile C1RXF4EIDBITS C1RXF4EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF5SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF5SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned EXIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXF5SIDBITS;

extern volatile C1RXF5SIDBITS C1RXF5SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF5EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF5EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXF5EIDBITS;

extern volatile C1RXF5EIDBITS C1RXF5EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF6SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF6SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned EXIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXF6SIDBITS;

extern volatile C1RXF6SIDBITS C1RXF6SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF6EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF6EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXF6EIDBITS;

extern volatile C1RXF6EIDBITS C1RXF6EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF7SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF7SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned EXIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXF7SIDBITS;

extern volatile C1RXF7SIDBITS C1RXF7SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF7EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF7EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXF7EIDBITS;

extern volatile C1RXF7EIDBITS C1RXF7EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF8SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF8SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned EXIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXF8SIDBITS;

extern volatile C1RXF8SIDBITS C1RXF8SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF8EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF8EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXF8EIDBITS;

extern volatile C1RXF8EIDBITS C1RXF8EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF9SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF9SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned EXIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXF9SIDBITS;

extern volatile C1RXF9SIDBITS C1RXF9SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF9EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF9EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXF9EIDBITS;

extern volatile C1RXF9EIDBITS C1RXF9EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF10SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF10SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned EXIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXF10SIDBITS;

extern volatile C1RXF10SIDBITS C1RXF10SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF10EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF10EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXF10EIDBITS;

extern volatile C1RXF10EIDBITS C1RXF10EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF11SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF11SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned EXIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXF11SIDBITS;

extern volatile C1RXF11SIDBITS C1RXF11SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF11EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF11EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXF11EIDBITS;

extern volatile C1RXF11EIDBITS C1RXF11EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF12SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF12SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned EXIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXF12SIDBITS;

extern volatile C1RXF12SIDBITS C1RXF12SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF12EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF12EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXF12EIDBITS;

extern volatile C1RXF12EIDBITS C1RXF12EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF13SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF13SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned EXIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXF13SIDBITS;

extern volatile C1RXF13SIDBITS C1RXF13SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF13EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF13EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXF13EIDBITS;

extern volatile C1RXF13EIDBITS C1RXF13EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF14SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF14SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned EXIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXF14SIDBITS;

extern volatile C1RXF14SIDBITS C1RXF14SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF14EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF14EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXF14EIDBITS;

extern volatile C1RXF14EIDBITS C1RXF14EIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF15SID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF15SIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            2;
            
unsigned :
            1;
            
unsigned EXIDE:
            1;
            
unsigned :
            1;
            
unsigned SID:
            11;
        };
        
        struct
        {
        
unsigned EID16:
            1;
            
unsigned EID17:
            1;
            
unsigned :
            3;
            
unsigned SID0:
            1;
            
unsigned SID1:
            1;
            
unsigned SID2:
            1;
            
unsigned SID3:
            1;
            
unsigned SID4:
            1;
            
unsigned SID5:
            1;
            
unsigned SID6:
            1;
            
unsigned SID7:
            1;
            
unsigned SID8:
            1;
            
unsigned SID9:
            1;
            
unsigned SID10:
            1;
        };
    };
} C1RXF15SIDBITS;

extern volatile C1RXF15SIDBITS C1RXF15SIDbits __attribute__((__sfr__));

extern volatile unsigned int  C1RXF15EID __attribute__((__sfr__));

__extension__ typedef struct tagC1RXF15EIDBITS
{
    union
    {
    
        struct
        {
        
unsigned EID:
            16;
        };
        
        struct
        {
        
unsigned EID0:
            1;
            
unsigned EID1:
            1;
            
unsigned EID2:
            1;
            
unsigned EID3:
            1;
            
unsigned EID4:
            1;
            
unsigned EID5:
            1;
            
unsigned EID6:
            1;
            
unsigned EID7:
            1;
            
unsigned EID8:
            1;
            
unsigned EID9:
            1;
            
unsigned EID10:
            1;
            
unsigned EID11:
            1;
            
unsigned EID12:
            1;
            
unsigned EID13:
            1;
            
unsigned EID14:
            1;
            
unsigned EID15:
            1;
        };
    };
} C1RXF15EIDBITS;

extern volatile C1RXF15EIDBITS C1RXF15EIDbits __attribute__((__sfr__));

extern volatile unsigned int  ODCD __attribute__((__sfr__));

typedef struct tagODCDBITS
{

unsigned ODCD0:
    1;
    
unsigned ODCD1:
    1;
    
unsigned ODCD2:
    1;
    
unsigned ODCD3:
    1;
    
unsigned ODCD4:
    1;
    
unsigned ODCD5:
    1;
    
unsigned ODCD6:
    1;
    
unsigned ODCD7:
    1;
    
unsigned ODCD8:
    1;
    
unsigned ODCD9:
    1;
    
unsigned ODCD10:
    1;
    
unsigned ODCD11:
    1;
} ODCDBITS;

extern volatile ODCDBITS ODCDbits __attribute__((__sfr__));

extern volatile unsigned int  ODCF __attribute__((__sfr__));

typedef struct tagODCFBITS
{

unsigned ODCF0:
    1;
    
unsigned ODCF1:
    1;
    
unsigned ODCF2:
    1;
    
unsigned ODCF3:
    1;
    
unsigned ODCF4:
    1;
    
unsigned ODCF5:
    1;
    
unsigned ODCF6:
    1;
} ODCFBITS;

extern volatile ODCFBITS ODCFbits __attribute__((__sfr__));

extern volatile unsigned int  ODCG __attribute__((__sfr__));

typedef struct tagODCGBITS
{

unsigned ODCG0:
    1;
    
unsigned ODCG1:
    1;
    
unsigned ODCG2:
    1;
    
unsigned ODCG3:
    1;
    
unsigned :
    2;
    
unsigned ODCG6:
    1;
    
unsigned ODCG7:
    1;
    
unsigned ODCG8:
    1;
    
unsigned ODCG9:
    1;
    
unsigned :
    2;
    
unsigned ODCG12:
    1;
    
unsigned ODCG13:
    1;
    
unsigned ODCG14:
    1;
    
unsigned ODCG15:
    1;
} ODCGBITS;

extern volatile ODCGBITS ODCGbits __attribute__((__sfr__));

extern volatile unsigned int  RCON __attribute__((__sfr__));

typedef struct tagRCONBITS
{

unsigned POR:
    1;
    
unsigned BOR:
    1;
    
unsigned IDLE:
    1;
    
unsigned SLEEP:
    1;
    
unsigned WDTO:
    1;
    
unsigned SWDTEN:
    1;
    
unsigned SWR:
    1;
    
unsigned EXTR:
    1;
    
unsigned VREGS:
    1;
    
unsigned :
    5;
    
unsigned IOPUWR:
    1;
    
unsigned TRAPR:
    1;
} RCONBITS;

extern volatile RCONBITS RCONbits __attribute__((__sfr__));

extern volatile unsigned int  OSCCON __attribute__((__sfr__));

__extension__ typedef struct tagOSCCONBITS
{
    union
    {
    
        struct
        {
        
unsigned OSWEN:
            1;
            
unsigned LPOSCEN:
            1;
            
unsigned :
            1;
            
unsigned CF:
            1;
            
unsigned :
            1;
            
unsigned LOCK:
            1;
            
unsigned :
            1;
            
unsigned CLKLOCK:
            1;
            
unsigned NOSC:
            3;
            
unsigned :
            1;
            
unsigned COSC:
            3;
        };
        
        struct
        {
        
unsigned :
            8;
            
unsigned NOSC0:
            1;
            
unsigned NOSC1:
            1;
            
unsigned NOSC2:
            1;
            
unsigned :
            1;
            
unsigned COSC0:
            1;
            
unsigned COSC1:
            1;
            
unsigned COSC2:
            1;
        };
    };
} OSCCONBITS;

extern volatile OSCCONBITS OSCCONbits __attribute__((__sfr__));

extern volatile unsigned char OSCCONL __attribute__((__sfr__));
extern volatile unsigned char OSCCONH __attribute__((__sfr__));
extern volatile unsigned int  CLKDIV __attribute__((__sfr__));

__extension__ typedef struct tagCLKDIVBITS
{
    union
    {
    
        struct
        {
        
unsigned PLLPRE:
            5;
            
unsigned :
            1;
            
unsigned PLLPOST:
            2;
            
unsigned FRCDIV:
            3;
            
unsigned DOZEN:
            1;
            
unsigned DOZE:
            3;
            
unsigned ROI:
            1;
        };
        
        struct
        {
        
unsigned PLLPRE0:
            1;
            
unsigned PLLPRE1:
            1;
            
unsigned PLLPRE2:
            1;
            
unsigned PLLPRE3:
            1;
            
unsigned PLLPRE4:
            1;
            
unsigned :
            1;
            
unsigned PLLPOST0:
            1;
            
unsigned PLLPOST1:
            1;
            
unsigned FRCDIV0:
            1;
            
unsigned FRCDIV1:
            1;
            
unsigned FRCDIV2:
            1;
            
unsigned :
            1;
            
unsigned DOZE0:
            1;
            
unsigned DOZE1:
            1;
            
unsigned DOZE2:
            1;
        };
    };
} CLKDIVBITS;

extern volatile CLKDIVBITS CLKDIVbits __attribute__((__sfr__));

extern volatile unsigned int  PLLFBD __attribute__((__sfr__));

__extension__ typedef struct tagPLLFBDBITS
{
    union
    {
    
        struct
        {
        
unsigned PLLDIV:
            9;
        };
        
        struct
        {
        
unsigned PLLDIV0:
            1;
            
unsigned PLLDIV1:
            1;
            
unsigned PLLDIV2:
            1;
            
unsigned PLLDIV3:
            1;
            
unsigned PLLDIV4:
            1;
            
unsigned PLLDIV5:
            1;
            
unsigned PLLDIV6:
            1;
            
unsigned PLLDIV7:
            1;
            
unsigned PLLDIV8:
            1;
        };
    };
} PLLFBDBITS;

extern volatile PLLFBDBITS PLLFBDbits __attribute__((__sfr__));

extern volatile unsigned int  OSCTUN __attribute__((__sfr__));

__extension__ typedef struct tagOSCTUNBITS
{
    union
    {
    
        struct
        {
        
unsigned TUN:
            6;
        };
        
        struct
        {
        
unsigned TUN0:
            1;
            
unsigned TUN1:
            1;
            
unsigned TUN2:
            1;
            
unsigned TUN3:
            1;
            
unsigned TUN4:
            1;
            
unsigned TUN5:
            1;
        };
    };
} OSCTUNBITS;

extern volatile OSCTUNBITS OSCTUNbits __attribute__((__sfr__));

extern volatile unsigned int  BSRAM __attribute__((__sfr__));

typedef struct tagBSRAMBITS
{

unsigned RL_BSR:
    1;
    
unsigned IR_BSR:
    1;
    
unsigned IW_BSR:
    1;
} BSRAMBITS;

extern volatile BSRAMBITS BSRAMbits __attribute__((__sfr__));

extern volatile unsigned int  SSRAM __attribute__((__sfr__));

typedef struct tagSSRAMBITS
{

unsigned RL_SSR:
    1;
    
unsigned IR_SSR:
    1;
    
unsigned IW_SSR:
    1;
} SSRAMBITS;

extern volatile SSRAMBITS SSRAMbits __attribute__((__sfr__));

extern volatile unsigned int  NVMCON __attribute__((__sfr__));

__extension__ typedef struct tagNVMCONBITS
{
    union
    {
    
        struct
        {
        
unsigned NVMOP:
            4;
            
unsigned :
            2;
            
unsigned ERASE:
            1;
            
unsigned :
            6;
            
unsigned WRERR:
            1;
            
unsigned WREN:
            1;
            
unsigned WR:
            1;
        };
        
        struct
        {
        
unsigned NVMOP0:
            1;
            
unsigned NVMOP1:
            1;
            
unsigned NVMOP2:
            1;
            
unsigned NVMOP3:
            1;
        };
    };
} NVMCONBITS;

extern volatile NVMCONBITS NVMCONbits __attribute__((__sfr__));

extern volatile unsigned int  NVMKEY __attribute__((__sfr__));
extern volatile unsigned int  PMD1 __attribute__((__sfr__));

typedef struct tagPMD1BITS
{

unsigned AD1MD:
    1;
    
unsigned C1MD:
    1;
    
unsigned C2MD:
    1;
    
unsigned SPI1MD:
    1;
    
unsigned SPI2MD:
    1;
    
unsigned U1MD:
    1;
    
unsigned U2MD:
    1;
    
unsigned I2C1MD:
    1;
    
unsigned DCIMD:
    1;
    
unsigned :
    2;
    
unsigned T1MD:
    1;
    
unsigned T2MD:
    1;
    
unsigned T3MD:
    1;
    
unsigned T4MD:
    1;
    
unsigned T5MD:
    1;
} PMD1BITS;

extern volatile PMD1BITS PMD1bits __attribute__((__sfr__));

extern volatile unsigned int  PMD2 __attribute__((__sfr__));

typedef struct tagPMD2BITS
{

unsigned OC1MD:
    1;
    
unsigned OC2MD:
    1;
    
unsigned OC3MD:
    1;
    
unsigned OC4MD:
    1;
    
unsigned OC5MD:
    1;
    
unsigned OC6MD:
    1;
    
unsigned OC7MD:
    1;
    
unsigned OC8MD:
    1;
    
unsigned IC1MD:
    1;
    
unsigned IC2MD:
    1;
    
unsigned IC3MD:
    1;
    
unsigned IC4MD:
    1;
    
unsigned IC5MD:
    1;
    
unsigned IC6MD:
    1;
    
unsigned IC7MD:
    1;
    
unsigned IC8MD:
    1;
} PMD2BITS;

extern volatile PMD2BITS PMD2bits __attribute__((__sfr__));

extern volatile unsigned int  PMD3 __attribute__((__sfr__));

typedef struct tagPMD3BITS
{

unsigned AD2MD:
    1;
    
unsigned I2C2MD:
    1;
    
unsigned :
    10;
    
unsigned T6MD:
    1;
    
unsigned T7MD:
    1;
    
unsigned T8MD:
    1;
    
unsigned T9MD:
    1;
} PMD3BITS;

extern volatile PMD3BITS PMD3bits __attribute__((__sfr__));



/* ---------------------------------------------------------- */
/* Defines for unique SFR bit names                           */
/* ---------------------------------------------------------- */

/* SR */
#define _C SRbits.C
#define _Z SRbits.Z
#define _OV SRbits.OV
#define _N SRbits.N
#define _RA SRbits.RA
#define _IPL SRbits.IPL
#define _DC SRbits.DC
#define _DA SRbits.DA
#define _SAB SRbits.SAB
#define _OAB SRbits.OAB
#define _SB SRbits.SB
#define _SA SRbits.SA
#define _OB SRbits.OB
#define _OA SRbits.OA
#define _IPL0 SRbits.IPL0
#define _IPL1 SRbits.IPL1
#define _IPL2 SRbits.IPL2

/* CORCON */
#define _IF CORCONbits.IF
#define _RND CORCONbits.RND
#define _PSV CORCONbits.PSV
#define _IPL3 CORCONbits.IPL3
#define _ACCSAT CORCONbits.ACCSAT
#define _SATDW CORCONbits.SATDW
#define _SATB CORCONbits.SATB
#define _SATA CORCONbits.SATA
#define _DL CORCONbits.DL
#define _EDT CORCONbits.EDT
#define _US CORCONbits.US
#define _DL0 CORCONbits.DL0
#define _DL1 CORCONbits.DL1
#define _DL2 CORCONbits.DL2

/* MODCON */
#define _XWM MODCONbits.XWM
#define _YWM MODCONbits.YWM
#define _BWM MODCONbits.BWM
#define _YMODEN MODCONbits.YMODEN
#define _XMODEN MODCONbits.XMODEN
#define _XWM0 MODCONbits.XWM0
#define _XWM1 MODCONbits.XWM1
#define _XWM2 MODCONbits.XWM2
#define _XWM3 MODCONbits.XWM3
#define _YWM0 MODCONbits.YWM0
#define _YWM1 MODCONbits.YWM1
#define _YWM2 MODCONbits.YWM2
#define _YWM3 MODCONbits.YWM3
#define _BWM0 MODCONbits.BWM0
#define _BWM1 MODCONbits.BWM1
#define _BWM2 MODCONbits.BWM2
#define _BWM3 MODCONbits.BWM3

/* XBREV */
#define _XB XBREVbits.XB
#define _BREN XBREVbits.BREN
#define _XB0 XBREVbits.XB0
#define _XB1 XBREVbits.XB1
#define _XB2 XBREVbits.XB2
#define _XB3 XBREVbits.XB3
#define _XB4 XBREVbits.XB4
#define _XB5 XBREVbits.XB5
#define _XB6 XBREVbits.XB6
#define _XB7 XBREVbits.XB7
#define _XB8 XBREVbits.XB8
#define _XB9 XBREVbits.XB9
#define _XB10 XBREVbits.XB10
#define _XB11 XBREVbits.XB11
#define _XB12 XBREVbits.XB12
#define _XB13 XBREVbits.XB13
#define _XB14 XBREVbits.XB14

/* CNEN1 */
#define _CN0IE CNEN1bits.CN0IE
#define _CN1IE CNEN1bits.CN1IE
#define _CN2IE CNEN1bits.CN2IE
#define _CN3IE CNEN1bits.CN3IE
#define _CN4IE CNEN1bits.CN4IE
#define _CN5IE CNEN1bits.CN5IE
#define _CN6IE CNEN1bits.CN6IE
#define _CN7IE CNEN1bits.CN7IE
#define _CN8IE CNEN1bits.CN8IE
#define _CN9IE CNEN1bits.CN9IE
#define _CN10IE CNEN1bits.CN10IE
#define _CN11IE CNEN1bits.CN11IE
#define _CN12IE CNEN1bits.CN12IE
#define _CN13IE CNEN1bits.CN13IE
#define _CN14IE CNEN1bits.CN14IE
#define _CN15IE CNEN1bits.CN15IE

/* CNEN2 */
#define _CN16IE CNEN2bits.CN16IE
#define _CN17IE CNEN2bits.CN17IE
#define _CN18IE CNEN2bits.CN18IE

/* CNPU1 */
#define _CN0PUE CNPU1bits.CN0PUE
#define _CN1PUE CNPU1bits.CN1PUE
#define _CN2PUE CNPU1bits.CN2PUE
#define _CN3PUE CNPU1bits.CN3PUE
#define _CN4PUE CNPU1bits.CN4PUE
#define _CN5PUE CNPU1bits.CN5PUE
#define _CN6PUE CNPU1bits.CN6PUE
#define _CN7PUE CNPU1bits.CN7PUE
#define _CN8PUE CNPU1bits.CN8PUE
#define _CN9PUE CNPU1bits.CN9PUE
#define _CN10PUE CNPU1bits.CN10PUE
#define _CN11PUE CNPU1bits.CN11PUE
#define _CN12PUE CNPU1bits.CN12PUE
#define _CN13PUE CNPU1bits.CN13PUE
#define _CN14PUE CNPU1bits.CN14PUE
#define _CN15PUE CNPU1bits.CN15PUE

/* CNPU2 */
#define _CN16PUE CNPU2bits.CN16PUE
#define _CN17PUE CNPU2bits.CN17PUE
#define _CN18PUE CNPU2bits.CN18PUE

/* INTCON1 */
#define _OSCFAIL INTCON1bits.OSCFAIL
#define _STKERR INTCON1bits.STKERR
#define _ADDRERR INTCON1bits.ADDRERR
#define _MATHERR INTCON1bits.MATHERR
#define _DMACERR INTCON1bits.DMACERR
#define _DIV0ERR INTCON1bits.DIV0ERR
#define _SFTACERR INTCON1bits.SFTACERR
#define _COVTE INTCON1bits.COVTE
#define _OVBTE INTCON1bits.OVBTE
#define _OVATE INTCON1bits.OVATE
#define _COVBERR INTCON1bits.COVBERR
#define _COVAERR INTCON1bits.COVAERR
#define _OVBERR INTCON1bits.OVBERR
#define _OVAERR INTCON1bits.OVAERR
#define _NSTDIS INTCON1bits.NSTDIS

/* INTCON2 */
#define _INT0EP INTCON2bits.INT0EP
#define _INT1EP INTCON2bits.INT1EP
#define _INT2EP INTCON2bits.INT2EP
#define _INT3EP INTCON2bits.INT3EP
#define _INT4EP INTCON2bits.INT4EP
#define _DISI INTCON2bits.DISI
#define _ALTIVT INTCON2bits.ALTIVT

/* IFS0 */
#define _INT0IF IFS0bits.INT0IF
#define _IC1IF IFS0bits.IC1IF
#define _OC1IF IFS0bits.OC1IF
#define _T1IF IFS0bits.T1IF
#define _DMA0IF IFS0bits.DMA0IF
#define _IC2IF IFS0bits.IC2IF
#define _OC2IF IFS0bits.OC2IF
#define _T2IF IFS0bits.T2IF
#define _T3IF IFS0bits.T3IF
#define _SPI1EIF IFS0bits.SPI1EIF
#define _SPI1IF IFS0bits.SPI1IF
#define _U1RXIF IFS0bits.U1RXIF
#define _U1TXIF IFS0bits.U1TXIF
#define _AD1IF IFS0bits.AD1IF
#define _DMA1IF IFS0bits.DMA1IF

/* IFS1 */
#define _SI2C1IF IFS1bits.SI2C1IF
#define _MI2C1IF IFS1bits.MI2C1IF
#define _CNIF IFS1bits.CNIF
#define _INT1IF IFS1bits.INT1IF
#define _IC7IF IFS1bits.IC7IF
#define _IC8IF IFS1bits.IC8IF
#define _DMA2IF IFS1bits.DMA2IF
#define _OC3IF IFS1bits.OC3IF
#define _OC4IF IFS1bits.OC4IF
#define _T4IF IFS1bits.T4IF
#define _T5IF IFS1bits.T5IF
#define _INT2IF IFS1bits.INT2IF
#define _U2RXIF IFS1bits.U2RXIF
#define _U2TXIF IFS1bits.U2TXIF
#define _SI2CIF IFS1bits.SI2CIF

/* IFS2 */
#define _SPI2EIF IFS2bits.SPI2EIF
#define _SPI2IF IFS2bits.SPI2IF
#define _C1RXIF IFS2bits.C1RXIF
#define _C1IF IFS2bits.C1IF
#define _DMA3IF IFS2bits.DMA3IF
#define _IC3IF IFS2bits.IC3IF
#define _IC4IF IFS2bits.IC4IF
#define _IC5IF IFS2bits.IC5IF
#define _IC6IF IFS2bits.IC6IF
#define _OC5IF IFS2bits.OC5IF
#define _OC6IF IFS2bits.OC6IF
#define _OC7IF IFS2bits.OC7IF
#define _OC8IF IFS2bits.OC8IF
#define _DMA4IF IFS2bits.DMA4IF
#define _T6IF IFS2bits.T6IF

/* IFS3 */
#define _T7IF IFS3bits.T7IF
#define _SI2C2IF IFS3bits.SI2C2IF
#define _MI2C2IF IFS3bits.MI2C2IF
#define _T8IF IFS3bits.T8IF
#define _T9IF IFS3bits.T9IF
#define _INT3IF IFS3bits.INT3IF
#define _INT4IF IFS3bits.INT4IF
#define _DCIEIF IFS3bits.DCIEIF
#define _DCIIF IFS3bits.DCIIF
#define _DMA5IF IFS3bits.DMA5IF

/* IFS4 */
#define _U1EIF IFS4bits.U1EIF
#define _U2EIF IFS4bits.U2EIF
#define _DMA6IF IFS4bits.DMA6IF
#define _DMA7IF IFS4bits.DMA7IF
#define _C1TXIF IFS4bits.C1TXIF

/* IEC0 */
#define _INT0IE IEC0bits.INT0IE
#define _IC1IE IEC0bits.IC1IE
#define _OC1IE IEC0bits.OC1IE
#define _T1IE IEC0bits.T1IE
#define _DMA0IE IEC0bits.DMA0IE
#define _IC2IE IEC0bits.IC2IE
#define _OC2IE IEC0bits.OC2IE
#define _T2IE IEC0bits.T2IE
#define _T3IE IEC0bits.T3IE
#define _SPI1EIE IEC0bits.SPI1EIE
#define _SPI1IE IEC0bits.SPI1IE
#define _U1RXIE IEC0bits.U1RXIE
#define _U1TXIE IEC0bits.U1TXIE
#define _AD1IE IEC0bits.AD1IE
#define _DMA1IE IEC0bits.DMA1IE

/* IEC1 */
#define _SI2C1IE IEC1bits.SI2C1IE
#define _MI2C1IE IEC1bits.MI2C1IE
#define _CNIE IEC1bits.CNIE
#define _INT1IE IEC1bits.INT1IE
#define _IC7IE IEC1bits.IC7IE
#define _IC8IE IEC1bits.IC8IE
#define _DMA2IE IEC1bits.DMA2IE
#define _OC3IE IEC1bits.OC3IE
#define _OC4IE IEC1bits.OC4IE
#define _T4IE IEC1bits.T4IE
#define _T5IE IEC1bits.T5IE
#define _INT2IE IEC1bits.INT2IE
#define _U2RXIE IEC1bits.U2RXIE
#define _U2TXIE IEC1bits.U2TXIE
#define _SI2CIE IEC1bits.SI2CIE

/* IEC2 */
#define _SPI2EIE IEC2bits.SPI2EIE
#define _SPI2IE IEC2bits.SPI2IE
#define _C1RXIE IEC2bits.C1RXIE
#define _C1IE IEC2bits.C1IE
#define _DMA3IE IEC2bits.DMA3IE
#define _IC3IE IEC2bits.IC3IE
#define _IC4IE IEC2bits.IC4IE
#define _IC5IE IEC2bits.IC5IE
#define _IC6IE IEC2bits.IC6IE
#define _OC5IE IEC2bits.OC5IE
#define _OC6IE IEC2bits.OC6IE
#define _OC7IE IEC2bits.OC7IE
#define _OC8IE IEC2bits.OC8IE
#define _DMA4IE IEC2bits.DMA4IE
#define _T6IE IEC2bits.T6IE

/* IEC3 */
#define _T7IE IEC3bits.T7IE
#define _SI2C2IE IEC3bits.SI2C2IE
#define _MI2C2IE IEC3bits.MI2C2IE
#define _T8IE IEC3bits.T8IE
#define _T9IE IEC3bits.T9IE
#define _INT3IE IEC3bits.INT3IE
#define _INT4IE IEC3bits.INT4IE
#define _DCIEIE IEC3bits.DCIEIE
#define _DCIIE IEC3bits.DCIIE
#define _DMA5IE IEC3bits.DMA5IE

/* IEC4 */
#define _U1EIE IEC4bits.U1EIE
#define _U2EIE IEC4bits.U2EIE
#define _DMA6IE IEC4bits.DMA6IE
#define _DMA7IE IEC4bits.DMA7IE
#define _C1TXIE IEC4bits.C1TXIE

/* IPC0 */
#define _INT0IP IPC0bits.INT0IP
#define _IC1IP IPC0bits.IC1IP
#define _OC1IP IPC0bits.OC1IP
#define _T1IP IPC0bits.T1IP
#define _INT0IP0 IPC0bits.INT0IP0
#define _INT0IP1 IPC0bits.INT0IP1
#define _INT0IP2 IPC0bits.INT0IP2
#define _IC1IP0 IPC0bits.IC1IP0
#define _IC1IP1 IPC0bits.IC1IP1
#define _IC1IP2 IPC0bits.IC1IP2
#define _OC1IP0 IPC0bits.OC1IP0
#define _OC1IP1 IPC0bits.OC1IP1
#define _OC1IP2 IPC0bits.OC1IP2
#define _T1IP0 IPC0bits.T1IP0
#define _T1IP1 IPC0bits.T1IP1
#define _T1IP2 IPC0bits.T1IP2

/* IPC1 */
#define _DMA0IP IPC1bits.DMA0IP
#define _IC2IP IPC1bits.IC2IP
#define _OC2IP IPC1bits.OC2IP
#define _T2IP IPC1bits.T2IP
#define _DMA0IP0 IPC1bits.DMA0IP0
#define _DMA0IP1 IPC1bits.DMA0IP1
#define _DMA0IP2 IPC1bits.DMA0IP2
#define _IC2IP0 IPC1bits.IC2IP0
#define _IC2IP1 IPC1bits.IC2IP1
#define _IC2IP2 IPC1bits.IC2IP2
#define _OC2IP0 IPC1bits.OC2IP0
#define _OC2IP1 IPC1bits.OC2IP1
#define _OC2IP2 IPC1bits.OC2IP2
#define _T2IP0 IPC1bits.T2IP0
#define _T2IP1 IPC1bits.T2IP1
#define _T2IP2 IPC1bits.T2IP2

/* IPC2 */
#define _T3IP IPC2bits.T3IP
#define _SPI1EIP IPC2bits.SPI1EIP
#define _SPI1IP IPC2bits.SPI1IP
#define _U1RXIP IPC2bits.U1RXIP
#define _T3IP0 IPC2bits.T3IP0
#define _T3IP1 IPC2bits.T3IP1
#define _T3IP2 IPC2bits.T3IP2
#define _SPI1EIP0 IPC2bits.SPI1EIP0
#define _SPI1EIP1 IPC2bits.SPI1EIP1
#define _SPI1EIP2 IPC2bits.SPI1EIP2
#define _SPI1IP0 IPC2bits.SPI1IP0
#define _SPI1IP1 IPC2bits.SPI1IP1
#define _SPI1IP2 IPC2bits.SPI1IP2
#define _U1RXIP0 IPC2bits.U1RXIP0
#define _U1RXIP1 IPC2bits.U1RXIP1
#define _U1RXIP2 IPC2bits.U1RXIP2

/* IPC3 */
#define _U1TXIP IPC3bits.U1TXIP
#define _AD1IP IPC3bits.AD1IP
#define _DMA1IP IPC3bits.DMA1IP
#define _U1TXIP0 IPC3bits.U1TXIP0
#define _U1TXIP1 IPC3bits.U1TXIP1
#define _U1TXIP2 IPC3bits.U1TXIP2
#define _AD1IP0 IPC3bits.AD1IP0
#define _AD1IP1 IPC3bits.AD1IP1
#define _AD1IP2 IPC3bits.AD1IP2
#define _DMA1IP0 IPC3bits.DMA1IP0
#define _DMA1IP1 IPC3bits.DMA1IP1
#define _DMA1IP2 IPC3bits.DMA1IP2

/* IPC4 */
#define _SI2C1IP IPC4bits.SI2C1IP
#define _MI2C1IP IPC4bits.MI2C1IP
#define _CNIP IPC4bits.CNIP
#define _SI2C1IP0 IPC4bits.SI2C1IP0
#define _SI2C1IP1 IPC4bits.SI2C1IP1
#define _SI2C1IP2 IPC4bits.SI2C1IP2
#define _MI2C1IP0 IPC4bits.MI2C1IP0
#define _MI2C1IP1 IPC4bits.MI2C1IP1
#define _MI2C1IP2 IPC4bits.MI2C1IP2
#define _CNIP0 IPC4bits.CNIP0
#define _CNIP1 IPC4bits.CNIP1
#define _CNIP2 IPC4bits.CNIP2

/* IPC5 */
#define _INT1IP IPC5bits.INT1IP
#define _IC7IP IPC5bits.IC7IP
#define _IC8IP IPC5bits.IC8IP
#define _INT1IP0 IPC5bits.INT1IP0
#define _INT1IP1 IPC5bits.INT1IP1
#define _INT1IP2 IPC5bits.INT1IP2
#define _IC7IP0 IPC5bits.IC7IP0
#define _IC7IP1 IPC5bits.IC7IP1
#define _IC7IP2 IPC5bits.IC7IP2
#define _IC8IP0 IPC5bits.IC8IP0
#define _IC8IP1 IPC5bits.IC8IP1
#define _IC8IP2 IPC5bits.IC8IP2

/* IPC6 */
#define _DMA2IP IPC6bits.DMA2IP
#define _OC3IP IPC6bits.OC3IP
#define _OC4IP IPC6bits.OC4IP
#define _T4IP IPC6bits.T4IP
#define _DMA2IP0 IPC6bits.DMA2IP0
#define _DMA2IP1 IPC6bits.DMA2IP1
#define _DMA2IP2 IPC6bits.DMA2IP2
#define _OC3IP0 IPC6bits.OC3IP0
#define _OC3IP1 IPC6bits.OC3IP1
#define _OC3IP2 IPC6bits.OC3IP2
#define _OC4IP0 IPC6bits.OC4IP0
#define _OC4IP1 IPC6bits.OC4IP1
#define _OC4IP2 IPC6bits.OC4IP2
#define _T4IP0 IPC6bits.T4IP0
#define _T4IP1 IPC6bits.T4IP1
#define _T4IP2 IPC6bits.T4IP2

/* IPC7 */
#define _T5IP IPC7bits.T5IP
#define _INT2IP IPC7bits.INT2IP
#define _U2RXIP IPC7bits.U2RXIP
#define _U2TXIP IPC7bits.U2TXIP
#define _T5IP0 IPC7bits.T5IP0
#define _T5IP1 IPC7bits.T5IP1
#define _T5IP2 IPC7bits.T5IP2
#define _INT2IP0 IPC7bits.INT2IP0
#define _INT2IP1 IPC7bits.INT2IP1
#define _INT2IP2 IPC7bits.INT2IP2
#define _U2RXIP0 IPC7bits.U2RXIP0
#define _U2RXIP1 IPC7bits.U2RXIP1
#define _U2RXIP2 IPC7bits.U2RXIP2
#define _U2TXIP0 IPC7bits.U2TXIP0
#define _U2TXIP1 IPC7bits.U2TXIP1
#define _U2TXIP2 IPC7bits.U2TXIP2

/* IPC8 */
#define _SPI2EIP IPC8bits.SPI2EIP
#define _SPI2IP IPC8bits.SPI2IP
#define _C1RXIP IPC8bits.C1RXIP
#define _C1IP IPC8bits.C1IP
#define _SPI2EIP0 IPC8bits.SPI2EIP0
#define _SPI2EIP1 IPC8bits.SPI2EIP1
#define _SPI2EIP2 IPC8bits.SPI2EIP2
#define _SPI2IP0 IPC8bits.SPI2IP0
#define _SPI2IP1 IPC8bits.SPI2IP1
#define _SPI2IP2 IPC8bits.SPI2IP2
#define _C1RXIP0 IPC8bits.C1RXIP0
#define _C1RXIP1 IPC8bits.C1RXIP1
#define _C1RXIP2 IPC8bits.C1RXIP2
#define _C1IP0 IPC8bits.C1IP0
#define _C1IP1 IPC8bits.C1IP1
#define _C1IP2 IPC8bits.C1IP2

/* IPC9 */
#define _DMA3IP IPC9bits.DMA3IP
#define _IC3IP IPC9bits.IC3IP
#define _IC4IP IPC9bits.IC4IP
#define _IC5IP IPC9bits.IC5IP
#define _DMA3IP0 IPC9bits.DMA3IP0
#define _DMA3IP1 IPC9bits.DMA3IP1
#define _DMA3IP2 IPC9bits.DMA3IP2
#define _IC3IP0 IPC9bits.IC3IP0
#define _IC3IP1 IPC9bits.IC3IP1
#define _IC3IP2 IPC9bits.IC3IP2
#define _IC4IP0 IPC9bits.IC4IP0
#define _IC4IP1 IPC9bits.IC4IP1
#define _IC4IP2 IPC9bits.IC4IP2
#define _IC5IP0 IPC9bits.IC5IP0
#define _IC5IP1 IPC9bits.IC5IP1
#define _IC5IP2 IPC9bits.IC5IP2

/* IPC10 */
#define _IC6IP IPC10bits.IC6IP
#define _OC5IP IPC10bits.OC5IP
#define _OC6IP IPC10bits.OC6IP
#define _OC7IP IPC10bits.OC7IP
#define _IC6IP0 IPC10bits.IC6IP0
#define _IC6IP1 IPC10bits.IC6IP1
#define _IC6IP2 IPC10bits.IC6IP2
#define _OC5IP0 IPC10bits.OC5IP0
#define _OC5IP1 IPC10bits.OC5IP1
#define _OC5IP2 IPC10bits.OC5IP2
#define _OC6IP0 IPC10bits.OC6IP0
#define _OC6IP1 IPC10bits.OC6IP1
#define _OC6IP2 IPC10bits.OC6IP2
#define _OC7IP0 IPC10bits.OC7IP0
#define _OC7IP1 IPC10bits.OC7IP1
#define _OC7IP2 IPC10bits.OC7IP2

/* IPC11 */
#define _OC8IP IPC11bits.OC8IP
#define _DMA4IP IPC11bits.DMA4IP
#define _T6IP IPC11bits.T6IP
#define _OC8IP0 IPC11bits.OC8IP0
#define _OC8IP1 IPC11bits.OC8IP1
#define _OC8IP2 IPC11bits.OC8IP2
#define _DMA4IP0 IPC11bits.DMA4IP0
#define _DMA4IP1 IPC11bits.DMA4IP1
#define _DMA4IP2 IPC11bits.DMA4IP2
#define _T6IP0 IPC11bits.T6IP0
#define _T6IP1 IPC11bits.T6IP1
#define _T6IP2 IPC11bits.T6IP2

/* IPC12 */
#define _T7IP IPC12bits.T7IP
#define _SI2C2IP IPC12bits.SI2C2IP
#define _MI2C2IP IPC12bits.MI2C2IP
#define _T8IP IPC12bits.T8IP
#define _T7IP0 IPC12bits.T7IP0
#define _T7IP1 IPC12bits.T7IP1
#define _T7IP2 IPC12bits.T7IP2
#define _SI2C2IP0 IPC12bits.SI2C2IP0
#define _SI2C2IP1 IPC12bits.SI2C2IP1
#define _SI2C2IP2 IPC12bits.SI2C2IP2
#define _MI2C2IP0 IPC12bits.MI2C2IP0
#define _MI2C2IP1 IPC12bits.MI2C2IP1
#define _MI2C2IP2 IPC12bits.MI2C2IP2
#define _T8IP0 IPC12bits.T8IP0
#define _T8IP1 IPC12bits.T8IP1
#define _T8IP2 IPC12bits.T8IP2

/* IPC13 */
#define _T9IP IPC13bits.T9IP
#define _INT3IP IPC13bits.INT3IP
#define _INT4IP IPC13bits.INT4IP
#define _T9IP0 IPC13bits.T9IP0
#define _T9IP1 IPC13bits.T9IP1
#define _T9IP2 IPC13bits.T9IP2
#define _INT3IP0 IPC13bits.INT3IP0
#define _INT3IP1 IPC13bits.INT3IP1
#define _INT3IP2 IPC13bits.INT3IP2
#define _INT4IP0 IPC13bits.INT4IP0
#define _INT4IP1 IPC13bits.INT4IP1
#define _INT4IP2 IPC13bits.INT4IP2

/* IPC14 */
#define _C2IP IPC14bits.C2IP
#define _DCIEIP IPC14bits.DCIEIP
#define _DCIEIP0 IPC14bits.DCIEIP0
#define _DCIEIP1 IPC14bits.DCIEIP1
#define _DCIEIP2 IPC14bits.DCIEIP2

/* IPC15 */
#define _DCIIP IPC15bits.DCIIP
#define _DMA5IP IPC15bits.DMA5IP
#define _DCIIP0 IPC15bits.DCIIP0
#define _DCIIP1 IPC15bits.DCIIP1
#define _DCIIP2 IPC15bits.DCIIP2
#define _DMA5IP0 IPC15bits.DMA5IP0
#define _DMA5IP1 IPC15bits.DMA5IP1
#define _DMA5IP2 IPC15bits.DMA5IP2

/* IPC16 */
#define _U1EIP IPC16bits.U1EIP
#define _U2EIP IPC16bits.U2EIP
#define _U1EIP0 IPC16bits.U1EIP0
#define _U1EIP1 IPC16bits.U1EIP1
#define _U1EIP2 IPC16bits.U1EIP2
#define _U2EIP0 IPC16bits.U2EIP0
#define _U2EIP1 IPC16bits.U2EIP1
#define _U2EIP2 IPC16bits.U2EIP2

/* IPC17 */
#define _DMA6IP IPC17bits.DMA6IP
#define _DMA7IP IPC17bits.DMA7IP
#define _C1TXIP IPC17bits.C1TXIP
#define _DMA6IP0 IPC17bits.DMA6IP0
#define _DMA6IP1 IPC17bits.DMA6IP1
#define _DMA6IP2 IPC17bits.DMA6IP2
#define _DMA7IP0 IPC17bits.DMA7IP0
#define _DMA7IP1 IPC17bits.DMA7IP1
#define _DMA7IP2 IPC17bits.DMA7IP2
#define _C1TXIP0 IPC17bits.C1TXIP0
#define _C1TXIP1 IPC17bits.C1TXIP1
#define _C1TXIP2 IPC17bits.C1TXIP2

/* INTTREG */
#define _VECNUM INTTREGbits.VECNUM
#define _ILR INTTREGbits.ILR
#define _VECNUM0 INTTREGbits.VECNUM0
#define _VECNUM1 INTTREGbits.VECNUM1
#define _VECNUM2 INTTREGbits.VECNUM2
#define _VECNUM3 INTTREGbits.VECNUM3
#define _VECNUM4 INTTREGbits.VECNUM4
#define _VECNUM5 INTTREGbits.VECNUM5
#define _VECNUM6 INTTREGbits.VECNUM6
#define _ILR0 INTTREGbits.ILR0
#define _ILR1 INTTREGbits.ILR1
#define _ILR2 INTTREGbits.ILR2
#define _ILR3 INTTREGbits.ILR3

/* T1CON */
#define _TCS T1CONbits.TCS
#define _TSYNC T1CONbits.TSYNC
#define _TCKPS T1CONbits.TCKPS
#define _TGATE T1CONbits.TGATE
#define _TSIDL T1CONbits.TSIDL
#define _TON T1CONbits.TON
#define _TCKPS0 T1CONbits.TCKPS0
#define _TCKPS1 T1CONbits.TCKPS1

/* T2CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
/* Bitname _T32 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* T3CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* T4CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
/* Bitname _T32 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* T5CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* T6CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
/* Bitname _T32 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* T7CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* T8CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
/* Bitname _T32 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* T9CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* IC1CON */
#define _ICM IC1CONbits.ICM
#define _ICBNE IC1CONbits.ICBNE
#define _ICOV IC1CONbits.ICOV
#define _ICI IC1CONbits.ICI
#define _ICTMR IC1CONbits.ICTMR
#define _ICSIDL IC1CONbits.ICSIDL
#define _ICM0 IC1CONbits.ICM0
#define _ICM1 IC1CONbits.ICM1
#define _ICM2 IC1CONbits.ICM2
#define _ICI0 IC1CONbits.ICI0
#define _ICI1 IC1CONbits.ICI1

/* IC2CON */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTMR cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */

/* IC3CON */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTMR cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */

/* IC4CON */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTMR cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */

/* IC5CON */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTMR cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */

/* IC6CON */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTMR cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */

/* IC7CON */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTMR cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */

/* IC8CON */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTMR cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */

/* OC1CON */
#define _OCM OC1CONbits.OCM
#define _OCTSEL OC1CONbits.OCTSEL
#define _OCFLT OC1CONbits.OCFLT
#define _OCSIDL OC1CONbits.OCSIDL
#define _OCM0 OC1CONbits.OCM0
#define _OCM1 OC1CONbits.OCM1
#define _OCM2 OC1CONbits.OCM2

/* OC2CON */
/* Bitname _OCM cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT cannot be defined because it is used by more than one SFR */
/* Bitname _OCSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _OCM0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM2 cannot be defined because it is used by more than one SFR */

/* OC3CON */
/* Bitname _OCM cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT cannot be defined because it is used by more than one SFR */
/* Bitname _OCSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _OCM0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM2 cannot be defined because it is used by more than one SFR */

/* OC4CON */
/* Bitname _OCM cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT cannot be defined because it is used by more than one SFR */
/* Bitname _OCSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _OCM0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM2 cannot be defined because it is used by more than one SFR */

/* OC5CON */
/* Bitname _OCM cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT cannot be defined because it is used by more than one SFR */
/* Bitname _OCSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _OCM0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM2 cannot be defined because it is used by more than one SFR */

/* OC6CON */
/* Bitname _OCM cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT cannot be defined because it is used by more than one SFR */
/* Bitname _OCSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _OCM0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM2 cannot be defined because it is used by more than one SFR */

/* OC7CON */
/* Bitname _OCM cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT cannot be defined because it is used by more than one SFR */
/* Bitname _OCSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _OCM0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM2 cannot be defined because it is used by more than one SFR */

/* OC8CON */
/* Bitname _OCM cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT cannot be defined because it is used by more than one SFR */
/* Bitname _OCSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _OCM0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM2 cannot be defined because it is used by more than one SFR */

/* I2C1CON */
#define _SEN I2C1CONbits.SEN
#define _RSEN I2C1CONbits.RSEN
#define _PEN I2C1CONbits.PEN
#define _RCEN I2C1CONbits.RCEN
#define _ACKEN I2C1CONbits.ACKEN
#define _ACKDT I2C1CONbits.ACKDT
#define _STREN I2C1CONbits.STREN
#define _GCEN I2C1CONbits.GCEN
#define _SMEN I2C1CONbits.SMEN
#define _DISSLW I2C1CONbits.DISSLW
#define _A10M I2C1CONbits.A10M
#define _IPMIEN I2C1CONbits.IPMIEN
#define _SCLREL I2C1CONbits.SCLREL
#define _I2CSIDL I2C1CONbits.I2CSIDL
#define _I2CEN I2C1CONbits.I2CEN

/* I2C1STAT */
#define _TBF I2C1STATbits.TBF
#define _RBF I2C1STATbits.RBF
#define _R_W I2C1STATbits.R_W
#define _S I2C1STATbits.S
#define _P I2C1STATbits.P
#define _D_A I2C1STATbits.D_A
#define _I2COV I2C1STATbits.I2COV
#define _IWCOL I2C1STATbits.IWCOL
#define _ADD10 I2C1STATbits.ADD10
#define _GCSTAT I2C1STATbits.GCSTAT
#define _BCL I2C1STATbits.BCL
#define _TRSTAT I2C1STATbits.TRSTAT
#define _ACKSTAT I2C1STATbits.ACKSTAT

/* I2C2CON */
/* Bitname _SEN cannot be defined because it is used by more than one SFR */
/* Bitname _RSEN cannot be defined because it is used by more than one SFR */
/* Bitname _PEN cannot be defined because it is used by more than one SFR */
/* Bitname _RCEN cannot be defined because it is used by more than one SFR */
/* Bitname _ACKEN cannot be defined because it is used by more than one SFR */
/* Bitname _ACKDT cannot be defined because it is used by more than one SFR */
/* Bitname _STREN cannot be defined because it is used by more than one SFR */
/* Bitname _GCEN cannot be defined because it is used by more than one SFR */
/* Bitname _SMEN cannot be defined because it is used by more than one SFR */
/* Bitname _DISSLW cannot be defined because it is used by more than one SFR */
/* Bitname _A10M cannot be defined because it is used by more than one SFR */
/* Bitname _IPMIEN cannot be defined because it is used by more than one SFR */
/* Bitname _SCLREL cannot be defined because it is used by more than one SFR */
/* Bitname _I2CSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _I2CEN cannot be defined because it is used by more than one SFR */

/* I2C2STAT */
/* Bitname _TBF cannot be defined because it is used by more than one SFR */
/* Bitname _RBF cannot be defined because it is used by more than one SFR */
/* Bitname _R_W cannot be defined because it is used by more than one SFR */
/* Bitname _S cannot be defined because it is used by more than one SFR */
/* Bitname _P cannot be defined because it is used by more than one SFR */
/* Bitname _D_A cannot be defined because it is used by more than one SFR */
/* Bitname _I2COV cannot be defined because it is used by more than one SFR */
/* Bitname _IWCOL cannot be defined because it is used by more than one SFR */
/* Bitname _ADD10 cannot be defined because it is used by more than one SFR */
/* Bitname _GCSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _BCL cannot be defined because it is used by more than one SFR */
/* Bitname _TRSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _ACKSTAT cannot be defined because it is used by more than one SFR */

/* U1MODE */
#define _STSEL U1MODEbits.STSEL
#define _PDSEL U1MODEbits.PDSEL
#define _BRGH U1MODEbits.BRGH
#define _URXINV U1MODEbits.URXINV
#define _ABAUD U1MODEbits.ABAUD
#define _LPBACK U1MODEbits.LPBACK
#define _WAKE U1MODEbits.WAKE
#define _UEN U1MODEbits.UEN
#define _RTSMD U1MODEbits.RTSMD
#define _IREN U1MODEbits.IREN
#define _USIDL U1MODEbits.USIDL
#define _UARTEN U1MODEbits.UARTEN
#define _PDSEL0 U1MODEbits.PDSEL0
#define _PDSEL1 U1MODEbits.PDSEL1
#define _UEN0 U1MODEbits.UEN0
#define _UEN1 U1MODEbits.UEN1

/* U1STA */
#define _URXDA U1STAbits.URXDA
#define _OERR U1STAbits.OERR
#define _FERR U1STAbits.FERR
#define _PERR U1STAbits.PERR
#define _RIDLE U1STAbits.RIDLE
#define _ADDEN U1STAbits.ADDEN
#define _URXISEL U1STAbits.URXISEL
#define _TRMT U1STAbits.TRMT
#define _UTXBF U1STAbits.UTXBF
#define _UTXEN U1STAbits.UTXEN
#define _UTXBRK U1STAbits.UTXBRK
#define _UTXISEL0 U1STAbits.UTXISEL0
#define _UTXINV U1STAbits.UTXINV
#define _UTXISEL1 U1STAbits.UTXISEL1
#define _URXISEL0 U1STAbits.URXISEL0
#define _URXISEL1 U1STAbits.URXISEL1

/* U1TXREG */
#define _UTXREG0 U1TXREGbits.UTXREG0
#define _UTXREG1 U1TXREGbits.UTXREG1
#define _UTXREG2 U1TXREGbits.UTXREG2
#define _UTXREG3 U1TXREGbits.UTXREG3
#define _UTXREG4 U1TXREGbits.UTXREG4
#define _UTXREG5 U1TXREGbits.UTXREG5
#define _UTXREG6 U1TXREGbits.UTXREG6
#define _UTXREG7 U1TXREGbits.UTXREG7
#define _UTX8 U1TXREGbits.UTX8

/* U1RXREG */
#define _URXREG0 U1RXREGbits.URXREG0
#define _URXREG1 U1RXREGbits.URXREG1
#define _URXREG2 U1RXREGbits.URXREG2
#define _URXREG3 U1RXREGbits.URXREG3
#define _URXREG4 U1RXREGbits.URXREG4
#define _URXREG5 U1RXREGbits.URXREG5
#define _URXREG6 U1RXREGbits.URXREG6
#define _URXREG7 U1RXREGbits.URXREG7
#define _URX8 U1RXREGbits.URX8

/* U2MODE */
/* Bitname _STSEL cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL cannot be defined because it is used by more than one SFR */
/* Bitname _BRGH cannot be defined because it is used by more than one SFR */
/* Bitname _URXINV cannot be defined because it is used by more than one SFR */
/* Bitname _ABAUD cannot be defined because it is used by more than one SFR */
/* Bitname _LPBACK cannot be defined because it is used by more than one SFR */
/* Bitname _WAKE cannot be defined because it is used by more than one SFR */
/* Bitname _UEN cannot be defined because it is used by more than one SFR */
/* Bitname _RTSMD cannot be defined because it is used by more than one SFR */
/* Bitname _IREN cannot be defined because it is used by more than one SFR */
/* Bitname _USIDL cannot be defined because it is used by more than one SFR */
/* Bitname _UARTEN cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _UEN0 cannot be defined because it is used by more than one SFR */
/* Bitname _UEN1 cannot be defined because it is used by more than one SFR */

/* U2STA */
/* Bitname _URXDA cannot be defined because it is used by more than one SFR */
/* Bitname _OERR cannot be defined because it is used by more than one SFR */
/* Bitname _FERR cannot be defined because it is used by more than one SFR */
/* Bitname _PERR cannot be defined because it is used by more than one SFR */
/* Bitname _RIDLE cannot be defined because it is used by more than one SFR */
/* Bitname _ADDEN cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL cannot be defined because it is used by more than one SFR */
/* Bitname _TRMT cannot be defined because it is used by more than one SFR */
/* Bitname _UTXBF cannot be defined because it is used by more than one SFR */
/* Bitname _UTXEN cannot be defined because it is used by more than one SFR */
/* Bitname _UTXBRK cannot be defined because it is used by more than one SFR */
/* Bitname _UTXISEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXINV cannot be defined because it is used by more than one SFR */
/* Bitname _UTXISEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL1 cannot be defined because it is used by more than one SFR */

/* U2TXREG */
/* Bitname _UTXREG0 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG1 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG2 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG3 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG4 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG5 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG6 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG7 cannot be defined because it is used by more than one SFR */
/* Bitname _UTX8 cannot be defined because it is used by more than one SFR */

/* U2RXREG */
/* Bitname _URXREG0 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG1 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG2 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG3 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG4 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG5 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG6 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG7 cannot be defined because it is used by more than one SFR */
/* Bitname _URX8 cannot be defined because it is used by more than one SFR */

/* SPI1STAT */
#define _SPIRBF SPI1STATbits.SPIRBF
#define _SPITBF SPI1STATbits.SPITBF
#define _SPIROV SPI1STATbits.SPIROV
#define _BUFELM SPI1STATbits.BUFELM
#define _SPISIDL SPI1STATbits.SPISIDL
#define _SPIEN SPI1STATbits.SPIEN
#define _BUFELM0 SPI1STATbits.BUFELM0
#define _BUFELM1 SPI1STATbits.BUFELM1
#define _BUFELM2 SPI1STATbits.BUFELM2

/* SPI1CON1 */
#define _PPRE SPI1CON1bits.PPRE
#define _SPRE SPI1CON1bits.SPRE
#define _MSTEN SPI1CON1bits.MSTEN
#define _CKP SPI1CON1bits.CKP
#define _SSEN SPI1CON1bits.SSEN
#define _CKE SPI1CON1bits.CKE
#define _SMP SPI1CON1bits.SMP
#define _MODE16 SPI1CON1bits.MODE16
#define _DISSDO SPI1CON1bits.DISSDO
#define _DISSCK SPI1CON1bits.DISSCK
#define _PPRE0 SPI1CON1bits.PPRE0
#define _PPRE1 SPI1CON1bits.PPRE1
#define _SPRE0 SPI1CON1bits.SPRE0
#define _SPRE1 SPI1CON1bits.SPRE1
#define _SPRE2 SPI1CON1bits.SPRE2

/* SPI1CON2 */
#define _FRMDLY SPI1CON2bits.FRMDLY
#define _FRMPOL SPI1CON2bits.FRMPOL
#define _SPIFSD SPI1CON2bits.SPIFSD
#define _FRMEN SPI1CON2bits.FRMEN

/* SPI2STAT */
/* Bitname _SPIRBF cannot be defined because it is used by more than one SFR */
/* Bitname _SPITBF cannot be defined because it is used by more than one SFR */
/* Bitname _SPIROV cannot be defined because it is used by more than one SFR */
/* Bitname _BUFELM cannot be defined because it is used by more than one SFR */
/* Bitname _SPISIDL cannot be defined because it is used by more than one SFR */
/* Bitname _SPIEN cannot be defined because it is used by more than one SFR */
/* Bitname _BUFELM0 cannot be defined because it is used by more than one SFR */
/* Bitname _BUFELM1 cannot be defined because it is used by more than one SFR */
/* Bitname _BUFELM2 cannot be defined because it is used by more than one SFR */

/* SPI2CON1 */
/* Bitname _PPRE cannot be defined because it is used by more than one SFR */
/* Bitname _SPRE cannot be defined because it is used by more than one SFR */
/* Bitname _MSTEN cannot be defined because it is used by more than one SFR */
/* Bitname _CKP cannot be defined because it is used by more than one SFR */
/* Bitname _SSEN cannot be defined because it is used by more than one SFR */
/* Bitname _CKE cannot be defined because it is used by more than one SFR */
/* Bitname _SMP cannot be defined because it is used by more than one SFR */
/* Bitname _MODE16 cannot be defined because it is used by more than one SFR */
/* Bitname _DISSDO cannot be defined because it is used by more than one SFR */
/* Bitname _DISSCK cannot be defined because it is used by more than one SFR */
/* Bitname _PPRE0 cannot be defined because it is used by more than one SFR */
/* Bitname _PPRE1 cannot be defined because it is used by more than one SFR */
/* Bitname _SPRE0 cannot be defined because it is used by more than one SFR */
/* Bitname _SPRE1 cannot be defined because it is used by more than one SFR */
/* Bitname _SPRE2 cannot be defined because it is used by more than one SFR */

/* SPI2CON2 */
/* Bitname _FRMDLY cannot be defined because it is used by more than one SFR */
/* Bitname _FRMPOL cannot be defined because it is used by more than one SFR */
/* Bitname _SPIFSD cannot be defined because it is used by more than one SFR */
/* Bitname _FRMEN cannot be defined because it is used by more than one SFR */

/* DCICON1 */
#define _COFSM DCICON1bits.COFSM
#define _DJST DCICON1bits.DJST
#define _CSDOM DCICON1bits.CSDOM
#define _UNFM DCICON1bits.UNFM
#define _COFSD DCICON1bits.COFSD
#define _CSCKE DCICON1bits.CSCKE
#define _CSCKD DCICON1bits.CSCKD
#define _DLOOP DCICON1bits.DLOOP
#define _DCISIDL DCICON1bits.DCISIDL
#define _DCIEN DCICON1bits.DCIEN
#define _COFSM0 DCICON1bits.COFSM0
#define _COFSM1 DCICON1bits.COFSM1

/* DCICON2 */
#define _WS DCICON2bits.WS
#define _COFSG DCICON2bits.COFSG
#define _BLEN DCICON2bits.BLEN
#define _WS0 DCICON2bits.WS0
#define _WS1 DCICON2bits.WS1
#define _WS2 DCICON2bits.WS2
#define _WS3 DCICON2bits.WS3
#define _COFSG0 DCICON2bits.COFSG0
#define _COFSG1 DCICON2bits.COFSG1
#define _COFSG2 DCICON2bits.COFSG2
#define _COFSG3 DCICON2bits.COFSG3
#define _BLEN0 DCICON2bits.BLEN0
#define _BLEN1 DCICON2bits.BLEN1

/* DCICON3 */
#define _BCG DCICON3bits.BCG

/* DCISTAT */
#define _TMPTY DCISTATbits.TMPTY
#define _TUNF DCISTATbits.TUNF
#define _RFUL DCISTATbits.RFUL
#define _ROV DCISTATbits.ROV
#define _SLOT DCISTATbits.SLOT
#define _SLOT0 DCISTATbits.SLOT0
#define _SLOT1 DCISTATbits.SLOT1
#define _SLOT2 DCISTATbits.SLOT2
#define _SLOT3 DCISTATbits.SLOT3

/* TSCON */
#define _TSE0 TSCONbits.TSE0
#define _TSE1 TSCONbits.TSE1
#define _TSE2 TSCONbits.TSE2
#define _TSE3 TSCONbits.TSE3
#define _TSE4 TSCONbits.TSE4
#define _TSE5 TSCONbits.TSE5
#define _TSE6 TSCONbits.TSE6
#define _TSE7 TSCONbits.TSE7
#define _TSE8 TSCONbits.TSE8
#define _TSE9 TSCONbits.TSE9
#define _TSE10 TSCONbits.TSE10
#define _TSE11 TSCONbits.TSE11
#define _TSE12 TSCONbits.TSE12
#define _TSE13 TSCONbits.TSE13
#define _TSE14 TSCONbits.TSE14
#define _TSE15 TSCONbits.TSE15

/* RSCON */
#define _RSE0 RSCONbits.RSE0
#define _RSE1 RSCONbits.RSE1
#define _RSE2 RSCONbits.RSE2
#define _RSE3 RSCONbits.RSE3
#define _RSE4 RSCONbits.RSE4
#define _RSE5 RSCONbits.RSE5
#define _RSE6 RSCONbits.RSE6
#define _RSE7 RSCONbits.RSE7
#define _RSE8 RSCONbits.RSE8
#define _RSE9 RSCONbits.RSE9
#define _RSE10 RSCONbits.RSE10
#define _RSE11 RSCONbits.RSE11
#define _RSE12 RSCONbits.RSE12
#define _RSE13 RSCONbits.RSE13
#define _RSE14 RSCONbits.RSE14
#define _RSE15 RSCONbits.RSE15

/* TRISB */
#define _TRISB0 TRISBbits.TRISB0
#define _TRISB1 TRISBbits.TRISB1
#define _TRISB2 TRISBbits.TRISB2
#define _TRISB3 TRISBbits.TRISB3
#define _TRISB4 TRISBbits.TRISB4
#define _TRISB5 TRISBbits.TRISB5
#define _TRISB6 TRISBbits.TRISB6
#define _TRISB7 TRISBbits.TRISB7
#define _TRISB8 TRISBbits.TRISB8
#define _TRISB9 TRISBbits.TRISB9
#define _TRISB10 TRISBbits.TRISB10
#define _TRISB11 TRISBbits.TRISB11
#define _TRISB12 TRISBbits.TRISB12
#define _TRISB13 TRISBbits.TRISB13
#define _TRISB14 TRISBbits.TRISB14
#define _TRISB15 TRISBbits.TRISB15

/* PORTB */
#define _RB0 PORTBbits.RB0
#define _RB1 PORTBbits.RB1
#define _RB2 PORTBbits.RB2
#define _RB3 PORTBbits.RB3
#define _RB4 PORTBbits.RB4
#define _RB5 PORTBbits.RB5
#define _RB6 PORTBbits.RB6
#define _RB7 PORTBbits.RB7
#define _RB8 PORTBbits.RB8
#define _RB9 PORTBbits.RB9
#define _RB10 PORTBbits.RB10
#define _RB11 PORTBbits.RB11
#define _RB12 PORTBbits.RB12
#define _RB13 PORTBbits.RB13
#define _RB14 PORTBbits.RB14
#define _RB15 PORTBbits.RB15

/* LATB */
#define _LATB0 LATBbits.LATB0
#define _LATB1 LATBbits.LATB1
#define _LATB2 LATBbits.LATB2
#define _LATB3 LATBbits.LATB3
#define _LATB4 LATBbits.LATB4
#define _LATB5 LATBbits.LATB5
#define _LATB6 LATBbits.LATB6
#define _LATB7 LATBbits.LATB7
#define _LATB8 LATBbits.LATB8
#define _LATB9 LATBbits.LATB9
#define _LATB10 LATBbits.LATB10
#define _LATB11 LATBbits.LATB11
#define _LATB12 LATBbits.LATB12
#define _LATB13 LATBbits.LATB13
#define _LATB14 LATBbits.LATB14
#define _LATB15 LATBbits.LATB15

/* TRISC */
#define _TRISC1 TRISCbits.TRISC1
#define _TRISC2 TRISCbits.TRISC2
#define _TRISC12 TRISCbits.TRISC12
#define _TRISC13 TRISCbits.TRISC13
#define _TRISC14 TRISCbits.TRISC14
#define _TRISC15 TRISCbits.TRISC15

/* PORTC */
#define _RC1 PORTCbits.RC1
#define _RC2 PORTCbits.RC2
#define _RC12 PORTCbits.RC12
#define _RC13 PORTCbits.RC13
#define _RC14 PORTCbits.RC14
#define _RC15 PORTCbits.RC15

/* LATC */
#define _LATC1 LATCbits.LATC1
#define _LATC2 LATCbits.LATC2
#define _LATC12 LATCbits.LATC12
#define _LATC13 LATCbits.LATC13
#define _LATC14 LATCbits.LATC14
#define _LATC15 LATCbits.LATC15

/* TRISD */
#define _TRISD0 TRISDbits.TRISD0
#define _TRISD1 TRISDbits.TRISD1
#define _TRISD2 TRISDbits.TRISD2
#define _TRISD3 TRISDbits.TRISD3
#define _TRISD4 TRISDbits.TRISD4
#define _TRISD5 TRISDbits.TRISD5
#define _TRISD6 TRISDbits.TRISD6
#define _TRISD7 TRISDbits.TRISD7
#define _TRISD8 TRISDbits.TRISD8
#define _TRISD9 TRISDbits.TRISD9
#define _TRISD10 TRISDbits.TRISD10
#define _TRISD11 TRISDbits.TRISD11

/* PORTD */
#define _RD0 PORTDbits.RD0
#define _RD1 PORTDbits.RD1
#define _RD2 PORTDbits.RD2
#define _RD3 PORTDbits.RD3
#define _RD4 PORTDbits.RD4
#define _RD5 PORTDbits.RD5
#define _RD6 PORTDbits.RD6
#define _RD7 PORTDbits.RD7
#define _RD8 PORTDbits.RD8
#define _RD9 PORTDbits.RD9
#define _RD10 PORTDbits.RD10
#define _RD11 PORTDbits.RD11

/* LATD */
#define _LATD0 LATDbits.LATD0
#define _LATD1 LATDbits.LATD1
#define _LATD2 LATDbits.LATD2
#define _LATD3 LATDbits.LATD3
#define _LATD4 LATDbits.LATD4
#define _LATD5 LATDbits.LATD5
#define _LATD6 LATDbits.LATD6
#define _LATD7 LATDbits.LATD7
#define _LATD8 LATDbits.LATD8
#define _LATD9 LATDbits.LATD9
#define _LATD10 LATDbits.LATD10
#define _LATD11 LATDbits.LATD11

/* TRISF */
#define _TRISF0 TRISFbits.TRISF0
#define _TRISF1 TRISFbits.TRISF1
#define _TRISF2 TRISFbits.TRISF2
#define _TRISF3 TRISFbits.TRISF3
#define _TRISF4 TRISFbits.TRISF4
#define _TRISF5 TRISFbits.TRISF5
#define _TRISF6 TRISFbits.TRISF6

/* PORTF */
#define _RF0 PORTFbits.RF0
#define _RF1 PORTFbits.RF1
#define _RF2 PORTFbits.RF2
#define _RF3 PORTFbits.RF3
#define _RF4 PORTFbits.RF4
#define _RF5 PORTFbits.RF5
#define _RF6 PORTFbits.RF6

/* LATF */
#define _LATF0 LATFbits.LATF0
#define _LATF1 LATFbits.LATF1
#define _LATF2 LATFbits.LATF2
#define _LATF3 LATFbits.LATF3
#define _LATF4 LATFbits.LATF4
#define _LATF5 LATFbits.LATF5
#define _LATF6 LATFbits.LATF6

/* TRISG */
#define _TRISG0 TRISGbits.TRISG0
#define _TRISG1 TRISGbits.TRISG1
#define _TRISG2 TRISGbits.TRISG2
#define _TRISG3 TRISGbits.TRISG3
#define _TRISG6 TRISGbits.TRISG6
#define _TRISG7 TRISGbits.TRISG7
#define _TRISG8 TRISGbits.TRISG8
#define _TRISG9 TRISGbits.TRISG9
#define _TRISG12 TRISGbits.TRISG12
#define _TRISG13 TRISGbits.TRISG13
#define _TRISG14 TRISGbits.TRISG14
#define _TRISG15 TRISGbits.TRISG15

/* PORTG */
#define _RG0 PORTGbits.RG0
#define _RG1 PORTGbits.RG1
#define _RG2 PORTGbits.RG2
#define _RG3 PORTGbits.RG3
#define _RG6 PORTGbits.RG6
#define _RG7 PORTGbits.RG7
#define _RG8 PORTGbits.RG8
#define _RG9 PORTGbits.RG9
#define _RG12 PORTGbits.RG12
#define _RG13 PORTGbits.RG13
#define _RG14 PORTGbits.RG14
#define _RG15 PORTGbits.RG15

/* LATG */
#define _LATG0 LATGbits.LATG0
#define _LATG1 LATGbits.LATG1
#define _LATG2 LATGbits.LATG2
#define _LATG3 LATGbits.LATG3
#define _LATG6 LATGbits.LATG6
#define _LATG7 LATGbits.LATG7
#define _LATG8 LATGbits.LATG8
#define _LATG9 LATGbits.LATG9
#define _LATG12 LATGbits.LATG12
#define _LATG13 LATGbits.LATG13
#define _LATG14 LATGbits.LATG14
#define _LATG15 LATGbits.LATG15

/* AD1CON1 */
#define _DONE AD1CON1bits.DONE
#define _SAMP AD1CON1bits.SAMP
#define _ASAM AD1CON1bits.ASAM
#define _SIMSAM AD1CON1bits.SIMSAM
#define _SSRC AD1CON1bits.SSRC
#define _FORM AD1CON1bits.FORM
#define _AD12B AD1CON1bits.AD12B
#define _ADDMABM AD1CON1bits.ADDMABM
#define _ADSIDL AD1CON1bits.ADSIDL
#define _ADON AD1CON1bits.ADON
#define _SSRC0 AD1CON1bits.SSRC0
#define _SSRC1 AD1CON1bits.SSRC1
#define _SSRC2 AD1CON1bits.SSRC2
#define _FORM0 AD1CON1bits.FORM0
#define _FORM1 AD1CON1bits.FORM1

/* AD1CON2 */
#define _ALTS AD1CON2bits.ALTS
#define _BUFM AD1CON2bits.BUFM
#define _SMPI AD1CON2bits.SMPI
#define _BUFS AD1CON2bits.BUFS
#define _CHPS AD1CON2bits.CHPS
#define _CSCNA AD1CON2bits.CSCNA
#define _VCFG AD1CON2bits.VCFG
#define _SMPI0 AD1CON2bits.SMPI0
#define _SMPI1 AD1CON2bits.SMPI1
#define _SMPI2 AD1CON2bits.SMPI2
#define _SMPI3 AD1CON2bits.SMPI3
#define _CHPS0 AD1CON2bits.CHPS0
#define _CHPS1 AD1CON2bits.CHPS1
#define _VCFG0 AD1CON2bits.VCFG0
#define _VCFG1 AD1CON2bits.VCFG1
#define _VCFG2 AD1CON2bits.VCFG2

/* AD1CON3 */
#define _ADCS AD1CON3bits.ADCS
#define _SAMC AD1CON3bits.SAMC
#define _ADRC AD1CON3bits.ADRC
#define _ADCS0 AD1CON3bits.ADCS0
#define _ADCS1 AD1CON3bits.ADCS1
#define _ADCS2 AD1CON3bits.ADCS2
#define _ADCS3 AD1CON3bits.ADCS3
#define _ADCS4 AD1CON3bits.ADCS4
#define _ADCS5 AD1CON3bits.ADCS5
#define _SAMC0 AD1CON3bits.SAMC0
#define _SAMC1 AD1CON3bits.SAMC1
#define _SAMC2 AD1CON3bits.SAMC2
#define _SAMC3 AD1CON3bits.SAMC3
#define _SAMC4 AD1CON3bits.SAMC4

/* AD1CHS123 */
#define _CH123SA AD1CHS123bits.CH123SA
#define _CH123NA AD1CHS123bits.CH123NA
#define _CH123SB AD1CHS123bits.CH123SB
#define _CH123NB AD1CHS123bits.CH123NB
#define _CH123NA0 AD1CHS123bits.CH123NA0
#define _CH123NA1 AD1CHS123bits.CH123NA1
#define _CH123NB0 AD1CHS123bits.CH123NB0
#define _CH123NB1 AD1CHS123bits.CH123NB1

/* AD1CHS0 */
#define _CH0SA AD1CHS0bits.CH0SA
#define _CH0NA AD1CHS0bits.CH0NA
#define _CH0SB AD1CHS0bits.CH0SB
#define _CH0NB AD1CHS0bits.CH0NB
#define _CH0SA0 AD1CHS0bits.CH0SA0
#define _CH0SA1 AD1CHS0bits.CH0SA1
#define _CH0SA2 AD1CHS0bits.CH0SA2
#define _CH0SA3 AD1CHS0bits.CH0SA3
#define _CH0SA4 AD1CHS0bits.CH0SA4
#define _CH0SB0 AD1CHS0bits.CH0SB0
#define _CH0SB1 AD1CHS0bits.CH0SB1
#define _CH0SB2 AD1CHS0bits.CH0SB2
#define _CH0SB3 AD1CHS0bits.CH0SB3
#define _CH0SB4 AD1CHS0bits.CH0SB4

/* AD1PCFGH */
#define _PCFG16 AD1PCFGHbits.PCFG16
#define _PCFG17 AD1PCFGHbits.PCFG17

/* AD1PCFGL */
#define _PCFG0 AD1PCFGLbits.PCFG0
#define _PCFG1 AD1PCFGLbits.PCFG1
#define _PCFG2 AD1PCFGLbits.PCFG2
#define _PCFG3 AD1PCFGLbits.PCFG3
#define _PCFG4 AD1PCFGLbits.PCFG4
#define _PCFG5 AD1PCFGLbits.PCFG5
#define _PCFG6 AD1PCFGLbits.PCFG6
#define _PCFG7 AD1PCFGLbits.PCFG7
#define _PCFG8 AD1PCFGLbits.PCFG8
#define _PCFG9 AD1PCFGLbits.PCFG9
#define _PCFG10 AD1PCFGLbits.PCFG10
#define _PCFG11 AD1PCFGLbits.PCFG11
#define _PCFG12 AD1PCFGLbits.PCFG12
#define _PCFG13 AD1PCFGLbits.PCFG13
#define _PCFG14 AD1PCFGLbits.PCFG14
#define _PCFG15 AD1PCFGLbits.PCFG15

/* AD1CSSH */
#define _CSS16 AD1CSSHbits.CSS16
#define _CSS17 AD1CSSHbits.CSS17

/* AD1CSSL */
#define _CSS0 AD1CSSLbits.CSS0
#define _CSS1 AD1CSSLbits.CSS1
#define _CSS2 AD1CSSLbits.CSS2
#define _CSS3 AD1CSSLbits.CSS3
#define _CSS4 AD1CSSLbits.CSS4
#define _CSS5 AD1CSSLbits.CSS5
#define _CSS6 AD1CSSLbits.CSS6
#define _CSS7 AD1CSSLbits.CSS7
#define _CSS8 AD1CSSLbits.CSS8
#define _CSS9 AD1CSSLbits.CSS9
#define _CSS10 AD1CSSLbits.CSS10
#define _CSS11 AD1CSSLbits.CSS11
#define _CSS12 AD1CSSLbits.CSS12
#define _CSS13 AD1CSSLbits.CSS13
#define _CSS14 AD1CSSLbits.CSS14
#define _CSS15 AD1CSSLbits.CSS15

/* AD1CON4 */
#define _DMABL AD1CON4bits.DMABL
#define _DMABL0 AD1CON4bits.DMABL0
#define _DMABL1 AD1CON4bits.DMABL1
#define _DMABL2 AD1CON4bits.DMABL2

/* DMA0CON */
#define _MODE DMA0CONbits.MODE
#define _AMODE DMA0CONbits.AMODE
#define _NULLW DMA0CONbits.NULLW
#define _HALF DMA0CONbits.HALF
#define _DIR DMA0CONbits.DIR
#define _SIZE DMA0CONbits.SIZE
#define _CHEN DMA0CONbits.CHEN
#define _MODE0 DMA0CONbits.MODE0
#define _MODE1 DMA0CONbits.MODE1
#define _AMODE0 DMA0CONbits.AMODE0
#define _AMODE1 DMA0CONbits.AMODE1

/* DMA0REQ */
#define _IRQSEL DMA0REQbits.IRQSEL
#define _FORCE DMA0REQbits.FORCE
#define _IRQSEL0 DMA0REQbits.IRQSEL0
#define _IRQSEL1 DMA0REQbits.IRQSEL1
#define _IRQSEL2 DMA0REQbits.IRQSEL2
#define _IRQSEL3 DMA0REQbits.IRQSEL3
#define _IRQSEL4 DMA0REQbits.IRQSEL4
#define _IRQSEL5 DMA0REQbits.IRQSEL5
#define _IRQSEL6 DMA0REQbits.IRQSEL6

/* DMA1CON */
/* Bitname _MODE cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE cannot be defined because it is used by more than one SFR */
/* Bitname _NULLW cannot be defined because it is used by more than one SFR */
/* Bitname _HALF cannot be defined because it is used by more than one SFR */
/* Bitname _DIR cannot be defined because it is used by more than one SFR */
/* Bitname _SIZE cannot be defined because it is used by more than one SFR */
/* Bitname _CHEN cannot be defined because it is used by more than one SFR */
/* Bitname _MODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _MODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE1 cannot be defined because it is used by more than one SFR */

/* DMA1REQ */
/* Bitname _IRQSEL cannot be defined because it is used by more than one SFR */
/* Bitname _FORCE cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL5 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL6 cannot be defined because it is used by more than one SFR */

/* DMA2CON */
/* Bitname _MODE cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE cannot be defined because it is used by more than one SFR */
/* Bitname _NULLW cannot be defined because it is used by more than one SFR */
/* Bitname _HALF cannot be defined because it is used by more than one SFR */
/* Bitname _DIR cannot be defined because it is used by more than one SFR */
/* Bitname _SIZE cannot be defined because it is used by more than one SFR */
/* Bitname _CHEN cannot be defined because it is used by more than one SFR */
/* Bitname _MODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _MODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE1 cannot be defined because it is used by more than one SFR */

/* DMA2REQ */
/* Bitname _IRQSEL cannot be defined because it is used by more than one SFR */
/* Bitname _FORCE cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL5 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL6 cannot be defined because it is used by more than one SFR */

/* DMA3CON */
/* Bitname _MODE cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE cannot be defined because it is used by more than one SFR */
/* Bitname _NULLW cannot be defined because it is used by more than one SFR */
/* Bitname _HALF cannot be defined because it is used by more than one SFR */
/* Bitname _DIR cannot be defined because it is used by more than one SFR */
/* Bitname _SIZE cannot be defined because it is used by more than one SFR */
/* Bitname _CHEN cannot be defined because it is used by more than one SFR */
/* Bitname _MODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _MODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE1 cannot be defined because it is used by more than one SFR */

/* DMA3REQ */
/* Bitname _IRQSEL cannot be defined because it is used by more than one SFR */
/* Bitname _FORCE cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL5 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL6 cannot be defined because it is used by more than one SFR */

/* DMA4CON */
/* Bitname _MODE cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE cannot be defined because it is used by more than one SFR */
/* Bitname _NULLW cannot be defined because it is used by more than one SFR */
/* Bitname _HALF cannot be defined because it is used by more than one SFR */
/* Bitname _DIR cannot be defined because it is used by more than one SFR */
/* Bitname _SIZE cannot be defined because it is used by more than one SFR */
/* Bitname _CHEN cannot be defined because it is used by more than one SFR */
/* Bitname _MODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _MODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE1 cannot be defined because it is used by more than one SFR */

/* DMA4REQ */
/* Bitname _IRQSEL cannot be defined because it is used by more than one SFR */
/* Bitname _FORCE cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL5 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL6 cannot be defined because it is used by more than one SFR */

/* DMA5CON */
/* Bitname _MODE cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE cannot be defined because it is used by more than one SFR */
/* Bitname _NULLW cannot be defined because it is used by more than one SFR */
/* Bitname _HALF cannot be defined because it is used by more than one SFR */
/* Bitname _DIR cannot be defined because it is used by more than one SFR */
/* Bitname _SIZE cannot be defined because it is used by more than one SFR */
/* Bitname _CHEN cannot be defined because it is used by more than one SFR */
/* Bitname _MODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _MODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE1 cannot be defined because it is used by more than one SFR */

/* DMA5REQ */
/* Bitname _IRQSEL cannot be defined because it is used by more than one SFR */
/* Bitname _FORCE cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL5 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL6 cannot be defined because it is used by more than one SFR */

/* DMA6CON */
/* Bitname _MODE cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE cannot be defined because it is used by more than one SFR */
/* Bitname _NULLW cannot be defined because it is used by more than one SFR */
/* Bitname _HALF cannot be defined because it is used by more than one SFR */
/* Bitname _DIR cannot be defined because it is used by more than one SFR */
/* Bitname _SIZE cannot be defined because it is used by more than one SFR */
/* Bitname _CHEN cannot be defined because it is used by more than one SFR */
/* Bitname _MODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _MODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE1 cannot be defined because it is used by more than one SFR */

/* DMA6REQ */
/* Bitname _IRQSEL cannot be defined because it is used by more than one SFR */
/* Bitname _FORCE cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL5 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL6 cannot be defined because it is used by more than one SFR */

/* DMA7CON */
/* Bitname _MODE cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE cannot be defined because it is used by more than one SFR */
/* Bitname _NULLW cannot be defined because it is used by more than one SFR */
/* Bitname _HALF cannot be defined because it is used by more than one SFR */
/* Bitname _DIR cannot be defined because it is used by more than one SFR */
/* Bitname _SIZE cannot be defined because it is used by more than one SFR */
/* Bitname _CHEN cannot be defined because it is used by more than one SFR */
/* Bitname _MODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _MODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _AMODE1 cannot be defined because it is used by more than one SFR */

/* DMA7REQ */
/* Bitname _IRQSEL cannot be defined because it is used by more than one SFR */
/* Bitname _FORCE cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL5 cannot be defined because it is used by more than one SFR */
/* Bitname _IRQSEL6 cannot be defined because it is used by more than one SFR */

/* DMACS0 */
#define _XWCOL DMACS0bits.XWCOL
#define _PWCOL DMACS0bits.PWCOL
#define _XWCOL0 DMACS0bits.XWCOL0
#define _XWCOL1 DMACS0bits.XWCOL1
#define _XWCOL2 DMACS0bits.XWCOL2
#define _XWCOL3 DMACS0bits.XWCOL3
#define _XWCOL4 DMACS0bits.XWCOL4
#define _XWCOL5 DMACS0bits.XWCOL5
#define _XWCOL6 DMACS0bits.XWCOL6
#define _XWCOL7 DMACS0bits.XWCOL7
#define _PWCOL0 DMACS0bits.PWCOL0
#define _PWCOL1 DMACS0bits.PWCOL1
#define _PWCOL2 DMACS0bits.PWCOL2
#define _PWCOL3 DMACS0bits.PWCOL3
#define _PWCOL4 DMACS0bits.PWCOL4
#define _PWCOL5 DMACS0bits.PWCOL5
#define _PWCOL6 DMACS0bits.PWCOL6
#define _PWCOL7 DMACS0bits.PWCOL7

/* DMACS1 */
#define _PPST DMACS1bits.PPST
#define _LSTCH DMACS1bits.LSTCH
#define _PPST0 DMACS1bits.PPST0
#define _PPST1 DMACS1bits.PPST1
#define _PPST2 DMACS1bits.PPST2
#define _PPST3 DMACS1bits.PPST3
#define _PPST4 DMACS1bits.PPST4
#define _PPST5 DMACS1bits.PPST5
#define _PPST6 DMACS1bits.PPST6
#define _PPST7 DMACS1bits.PPST7
#define _LSTCH0 DMACS1bits.LSTCH0
#define _LSTCH1 DMACS1bits.LSTCH1
#define _LSTCH2 DMACS1bits.LSTCH2
#define _LSTCH3 DMACS1bits.LSTCH3

/* C1CTRL1 */
#define _WIN C1CTRL1bits.WIN
#define _CANCAP C1CTRL1bits.CANCAP
#define _OPMODE C1CTRL1bits.OPMODE
#define _REQOP C1CTRL1bits.REQOP
#define _CANCKS C1CTRL1bits.CANCKS
#define _ABAT C1CTRL1bits.ABAT
#define _CSIDL C1CTRL1bits.CSIDL
#define _OPMODE0 C1CTRL1bits.OPMODE0
#define _OPMODE1 C1CTRL1bits.OPMODE1
#define _OPMODE2 C1CTRL1bits.OPMODE2
#define _REQOP0 C1CTRL1bits.REQOP0
#define _REQOP1 C1CTRL1bits.REQOP1
#define _REQOP2 C1CTRL1bits.REQOP2

/* C1CTRL2 */
#define _DNCNT C1CTRL2bits.DNCNT
#define _DNCNT0 C1CTRL2bits.DNCNT0
#define _DNCNT1 C1CTRL2bits.DNCNT1
#define _DNCNT2 C1CTRL2bits.DNCNT2
#define _DNCNT3 C1CTRL2bits.DNCNT3
#define _DNCNT4 C1CTRL2bits.DNCNT4

/* C1VEC */
#define _ICODE C1VECbits.ICODE
#define _FILHIT C1VECbits.FILHIT
#define _ICODE0 C1VECbits.ICODE0
#define _ICODE1 C1VECbits.ICODE1
#define _ICODE2 C1VECbits.ICODE2
#define _ICODE3 C1VECbits.ICODE3
#define _ICODE4 C1VECbits.ICODE4
#define _ICODE5 C1VECbits.ICODE5
#define _ICODE6 C1VECbits.ICODE6
#define _FILHIT0 C1VECbits.FILHIT0
#define _FILHIT1 C1VECbits.FILHIT1
#define _FILHIT2 C1VECbits.FILHIT2
#define _FILHIT3 C1VECbits.FILHIT3
#define _FILHIT4 C1VECbits.FILHIT4

/* C1FCTRL */
#define _FSA C1FCTRLbits.FSA
#define _DMABS C1FCTRLbits.DMABS
#define _FSA0 C1FCTRLbits.FSA0
#define _FSA1 C1FCTRLbits.FSA1
#define _FSA2 C1FCTRLbits.FSA2
#define _FSA3 C1FCTRLbits.FSA3
#define _FSA4 C1FCTRLbits.FSA4
#define _DMABS0 C1FCTRLbits.DMABS0
#define _DMABS1 C1FCTRLbits.DMABS1
#define _DMABS2 C1FCTRLbits.DMABS2

/* C1FIFO */
#define _FNRB C1FIFObits.FNRB
#define _FBP C1FIFObits.FBP
#define _FNRB0 C1FIFObits.FNRB0
#define _FNRB1 C1FIFObits.FNRB1
#define _FNRB2 C1FIFObits.FNRB2
#define _FNRB3 C1FIFObits.FNRB3
#define _FNRB4 C1FIFObits.FNRB4
#define _FNRB5 C1FIFObits.FNRB5
#define _FBP0 C1FIFObits.FBP0
#define _FBP1 C1FIFObits.FBP1
#define _FBP2 C1FIFObits.FBP2
#define _FBP3 C1FIFObits.FBP3
#define _FBP4 C1FIFObits.FBP4
#define _FBP5 C1FIFObits.FBP5

/* C1INTF */
#define _TBIF C1INTFbits.TBIF
#define _RBIF C1INTFbits.RBIF
#define _RBOVIF C1INTFbits.RBOVIF
#define _FIFOIF C1INTFbits.FIFOIF
#define _ERRIF C1INTFbits.ERRIF
#define _WAKIF C1INTFbits.WAKIF
#define _IVRIF C1INTFbits.IVRIF
#define _EWARN C1INTFbits.EWARN
#define _RXWAR C1INTFbits.RXWAR
#define _TXWAR C1INTFbits.TXWAR
#define _RXBP C1INTFbits.RXBP
#define _TXBP C1INTFbits.TXBP
#define _TXBO C1INTFbits.TXBO

/* C1INTE */
#define _TBIE C1INTEbits.TBIE
#define _RBIE C1INTEbits.RBIE
#define _RBOVIE C1INTEbits.RBOVIE
#define _FIFOIE C1INTEbits.FIFOIE
#define _ERRIE C1INTEbits.ERRIE
#define _WAKIE C1INTEbits.WAKIE
#define _IVRIE C1INTEbits.IVRIE

/* C1EC */
#define _RERRCNT C1ECbits.RERRCNT
#define _TERRCNT C1ECbits.TERRCNT
#define _RERRCNT0 C1ECbits.RERRCNT0
#define _RERRCNT1 C1ECbits.RERRCNT1
#define _RERRCNT2 C1ECbits.RERRCNT2
#define _RERRCNT3 C1ECbits.RERRCNT3
#define _RERRCNT4 C1ECbits.RERRCNT4
#define _RERRCNT5 C1ECbits.RERRCNT5
#define _RERRCNT6 C1ECbits.RERRCNT6
#define _RERRCNT7 C1ECbits.RERRCNT7
#define _TERRCNT0 C1ECbits.TERRCNT0
#define _TERRCNT1 C1ECbits.TERRCNT1
#define _TERRCNT2 C1ECbits.TERRCNT2
#define _TERRCNT3 C1ECbits.TERRCNT3
#define _TERRCNT4 C1ECbits.TERRCNT4
#define _TERRCNT5 C1ECbits.TERRCNT5
#define _TERRCNT6 C1ECbits.TERRCNT6
#define _TERRCNT7 C1ECbits.TERRCNT7

/* C1CFG1 */
#define _BRP C1CFG1bits.BRP
#define _SJW C1CFG1bits.SJW
#define _BRP0 C1CFG1bits.BRP0
#define _BRP1 C1CFG1bits.BRP1
#define _BRP2 C1CFG1bits.BRP2
#define _BRP3 C1CFG1bits.BRP3
#define _BRP4 C1CFG1bits.BRP4
#define _BRP5 C1CFG1bits.BRP5
#define _SJW0 C1CFG1bits.SJW0
#define _SJW1 C1CFG1bits.SJW1

/* C1CFG2 */
#define _PRSEG C1CFG2bits.PRSEG
#define _SEG1PH C1CFG2bits.SEG1PH
#define _SAM C1CFG2bits.SAM
#define _SEG2PHTS C1CFG2bits.SEG2PHTS
#define _SEG2PH C1CFG2bits.SEG2PH
#define _WAKFIL C1CFG2bits.WAKFIL
#define _PRSEG0 C1CFG2bits.PRSEG0
#define _PRSEG1 C1CFG2bits.PRSEG1
#define _PRSEG2 C1CFG2bits.PRSEG2
#define _SEG1PH0 C1CFG2bits.SEG1PH0
#define _SEG1PH1 C1CFG2bits.SEG1PH1
#define _SEG1PH2 C1CFG2bits.SEG1PH2
#define _SEG2PH0 C1CFG2bits.SEG2PH0
#define _SEG2PH1 C1CFG2bits.SEG2PH1
#define _SEG2PH2 C1CFG2bits.SEG2PH2

/* C1FEN1 */
#define _FLTEN C1FEN1bits.FLTEN
#define _FLTEN0 C1FEN1bits.FLTEN0
#define _FLTEN1 C1FEN1bits.FLTEN1
#define _FLTEN2 C1FEN1bits.FLTEN2
#define _FLTEN3 C1FEN1bits.FLTEN3
#define _FLTEN4 C1FEN1bits.FLTEN4
#define _FLTEN5 C1FEN1bits.FLTEN5
#define _FLTEN6 C1FEN1bits.FLTEN6
#define _FLTEN7 C1FEN1bits.FLTEN7
#define _FLTEN8 C1FEN1bits.FLTEN8
#define _FLTEN9 C1FEN1bits.FLTEN9
#define _FLTEN10 C1FEN1bits.FLTEN10
#define _FLTEN11 C1FEN1bits.FLTEN11
#define _FLTEN12 C1FEN1bits.FLTEN12
#define _FLTEN13 C1FEN1bits.FLTEN13
#define _FLTEN14 C1FEN1bits.FLTEN14
#define _FLTEN15 C1FEN1bits.FLTEN15

/* C1FMSKSEL1 */
#define _F0MSK C1FMSKSEL1bits.F0MSK
#define _F1MSK C1FMSKSEL1bits.F1MSK
#define _F2MSK C1FMSKSEL1bits.F2MSK
#define _F3MSK C1FMSKSEL1bits.F3MSK
#define _F4MSK C1FMSKSEL1bits.F4MSK
#define _F5MSK C1FMSKSEL1bits.F5MSK
#define _F6MSK C1FMSKSEL1bits.F6MSK
#define _F7MSK C1FMSKSEL1bits.F7MSK
#define _F0MSK0 C1FMSKSEL1bits.F0MSK0
#define _F0MSK1 C1FMSKSEL1bits.F0MSK1
#define _F1MSK0 C1FMSKSEL1bits.F1MSK0
#define _F1MSK1 C1FMSKSEL1bits.F1MSK1
#define _F2MSK0 C1FMSKSEL1bits.F2MSK0
#define _F2MSK1 C1FMSKSEL1bits.F2MSK1
#define _F3MSK0 C1FMSKSEL1bits.F3MSK0
#define _F3MSK1 C1FMSKSEL1bits.F3MSK1
#define _F4MSK0 C1FMSKSEL1bits.F4MSK0
#define _F4MSK1 C1FMSKSEL1bits.F4MSK1
#define _F5MSK0 C1FMSKSEL1bits.F5MSK0
#define _F5MSK1 C1FMSKSEL1bits.F5MSK1
#define _F6MSK0 C1FMSKSEL1bits.F6MSK0
#define _F6MSK1 C1FMSKSEL1bits.F6MSK1
#define _F7MSK0 C1FMSKSEL1bits.F7MSK0
#define _F7MSK1 C1FMSKSEL1bits.F7MSK1

/* C1FMSKSEL2 */
#define _F8MSK C1FMSKSEL2bits.F8MSK
#define _F9MSK C1FMSKSEL2bits.F9MSK
#define _F10MSK C1FMSKSEL2bits.F10MSK
#define _F11MSK C1FMSKSEL2bits.F11MSK
#define _F12MSK C1FMSKSEL2bits.F12MSK
#define _F13MSK C1FMSKSEL2bits.F13MSK
#define _F14MSK C1FMSKSEL2bits.F14MSK
#define _F15MSK C1FMSKSEL2bits.F15MSK
#define _F8MSK0 C1FMSKSEL2bits.F8MSK0
#define _F8MSK1 C1FMSKSEL2bits.F8MSK1
#define _F9MSK0 C1FMSKSEL2bits.F9MSK0
#define _F9MSK1 C1FMSKSEL2bits.F9MSK1
#define _F10MSK0 C1FMSKSEL2bits.F10MSK0
#define _F10MSK1 C1FMSKSEL2bits.F10MSK1
#define _F11MSK0 C1FMSKSEL2bits.F11MSK0
#define _F11MSK1 C1FMSKSEL2bits.F11MSK1
#define _F12MSK0 C1FMSKSEL2bits.F12MSK0
#define _F12MSK1 C1FMSKSEL2bits.F12MSK1
#define _F13MSK0 C1FMSKSEL2bits.F13MSK0
#define _F13MSK1 C1FMSKSEL2bits.F13MSK1
#define _F14MSK0 C1FMSKSEL2bits.F14MSK0
#define _F14MSK1 C1FMSKSEL2bits.F14MSK1
#define _F15MSK0 C1FMSKSEL2bits.F15MSK0
#define _F15MSK1 C1FMSKSEL2bits.F15MSK1

/* C1BUFPNT1 */
#define _F0BP C1BUFPNT1bits.F0BP
#define _F1BP C1BUFPNT1bits.F1BP
#define _F2BP C1BUFPNT1bits.F2BP
#define _F3BP C1BUFPNT1bits.F3BP
#define _F0BP0 C1BUFPNT1bits.F0BP0
#define _F0BP1 C1BUFPNT1bits.F0BP1
#define _F0BP2 C1BUFPNT1bits.F0BP2
#define _F0BP3 C1BUFPNT1bits.F0BP3
#define _F1BP0 C1BUFPNT1bits.F1BP0
#define _F1BP1 C1BUFPNT1bits.F1BP1
#define _F1BP2 C1BUFPNT1bits.F1BP2
#define _F1BP3 C1BUFPNT1bits.F1BP3
#define _F2BP0 C1BUFPNT1bits.F2BP0
#define _F2BP1 C1BUFPNT1bits.F2BP1
#define _F2BP2 C1BUFPNT1bits.F2BP2
#define _F2BP3 C1BUFPNT1bits.F2BP3
#define _F3BP0 C1BUFPNT1bits.F3BP0
#define _F3BP1 C1BUFPNT1bits.F3BP1
#define _F3BP2 C1BUFPNT1bits.F3BP2
#define _F3BP3 C1BUFPNT1bits.F3BP3

/* C1RXFUL1 */
#define _RXFUL0 C1RXFUL1bits.RXFUL0
#define _RXFUL1 C1RXFUL1bits.RXFUL1
#define _RXFUL2 C1RXFUL1bits.RXFUL2
#define _RXFUL3 C1RXFUL1bits.RXFUL3
#define _RXFUL4 C1RXFUL1bits.RXFUL4
#define _RXFUL5 C1RXFUL1bits.RXFUL5
#define _RXFUL6 C1RXFUL1bits.RXFUL6
#define _RXFUL7 C1RXFUL1bits.RXFUL7
#define _RXFUL8 C1RXFUL1bits.RXFUL8
#define _RXFUL9 C1RXFUL1bits.RXFUL9
#define _RXFUL10 C1RXFUL1bits.RXFUL10
#define _RXFUL11 C1RXFUL1bits.RXFUL11
#define _RXFUL12 C1RXFUL1bits.RXFUL12
#define _RXFUL13 C1RXFUL1bits.RXFUL13
#define _RXFUL14 C1RXFUL1bits.RXFUL14
#define _RXFUL15 C1RXFUL1bits.RXFUL15

/* C1BUFPNT2 */
#define _F4BP C1BUFPNT2bits.F4BP
#define _F5BP C1BUFPNT2bits.F5BP
#define _F6BP C1BUFPNT2bits.F6BP
#define _F7BP C1BUFPNT2bits.F7BP
#define _F4BP0 C1BUFPNT2bits.F4BP0
#define _F4BP1 C1BUFPNT2bits.F4BP1
#define _F4BP2 C1BUFPNT2bits.F4BP2
#define _F4BP3 C1BUFPNT2bits.F4BP3
#define _F5BP0 C1BUFPNT2bits.F5BP0
#define _F5BP1 C1BUFPNT2bits.F5BP1
#define _F5BP2 C1BUFPNT2bits.F5BP2
#define _F5BP3 C1BUFPNT2bits.F5BP3
#define _F6BP0 C1BUFPNT2bits.F6BP0
#define _F6BP1 C1BUFPNT2bits.F6BP1
#define _F6BP2 C1BUFPNT2bits.F6BP2
#define _F6BP3 C1BUFPNT2bits.F6BP3
#define _F7BP0 C1BUFPNT2bits.F7BP0
#define _F7BP1 C1BUFPNT2bits.F7BP1
#define _F7BP2 C1BUFPNT2bits.F7BP2
#define _F7BP3 C1BUFPNT2bits.F7BP3

/* C1RXFUL2 */
#define _RXFUL16 C1RXFUL2bits.RXFUL16
#define _RXFUL17 C1RXFUL2bits.RXFUL17
#define _RXFUL18 C1RXFUL2bits.RXFUL18
#define _RXFUL19 C1RXFUL2bits.RXFUL19
#define _RXFUL20 C1RXFUL2bits.RXFUL20
#define _RXFUL21 C1RXFUL2bits.RXFUL21
#define _RXFUL22 C1RXFUL2bits.RXFUL22
#define _RXFUL23 C1RXFUL2bits.RXFUL23
#define _RXFUL24 C1RXFUL2bits.RXFUL24
#define _RXFUL25 C1RXFUL2bits.RXFUL25
#define _RXFUL26 C1RXFUL2bits.RXFUL26
#define _RXFUL27 C1RXFUL2bits.RXFUL27
#define _RXFUL28 C1RXFUL2bits.RXFUL28
#define _RXFUL29 C1RXFUL2bits.RXFUL29
#define _RXFUL30 C1RXFUL2bits.RXFUL30
#define _RXFUL31 C1RXFUL2bits.RXFUL31

/* C1BUFPNT3 */
#define _F8BP C1BUFPNT3bits.F8BP
#define _F9BP C1BUFPNT3bits.F9BP
#define _F10BP C1BUFPNT3bits.F10BP
#define _F11BP C1BUFPNT3bits.F11BP
#define _F8BP0 C1BUFPNT3bits.F8BP0
#define _F8BP1 C1BUFPNT3bits.F8BP1
#define _F8BP2 C1BUFPNT3bits.F8BP2
#define _F8BP3 C1BUFPNT3bits.F8BP3
#define _F9BP0 C1BUFPNT3bits.F9BP0
#define _F9BP1 C1BUFPNT3bits.F9BP1
#define _F9BP2 C1BUFPNT3bits.F9BP2
#define _F9BP3 C1BUFPNT3bits.F9BP3
#define _F10BP0 C1BUFPNT3bits.F10BP0
#define _F10BP1 C1BUFPNT3bits.F10BP1
#define _F10BP2 C1BUFPNT3bits.F10BP2
#define _F10BP3 C1BUFPNT3bits.F10BP3
#define _F11BP0 C1BUFPNT3bits.F11BP0
#define _F11BP1 C1BUFPNT3bits.F11BP1
#define _F11BP2 C1BUFPNT3bits.F11BP2
#define _F11BP3 C1BUFPNT3bits.F11BP3

/* C1BUFPNT4 */
#define _F12BP C1BUFPNT4bits.F12BP
#define _F13BP C1BUFPNT4bits.F13BP
#define _F14BP C1BUFPNT4bits.F14BP
#define _F15BP C1BUFPNT4bits.F15BP
#define _F12BP0 C1BUFPNT4bits.F12BP0
#define _F12BP1 C1BUFPNT4bits.F12BP1
#define _F12BP2 C1BUFPNT4bits.F12BP2
#define _F12BP3 C1BUFPNT4bits.F12BP3
#define _F13BP0 C1BUFPNT4bits.F13BP0
#define _F13BP1 C1BUFPNT4bits.F13BP1
#define _F13BP2 C1BUFPNT4bits.F13BP2
#define _F13BP3 C1BUFPNT4bits.F13BP3
#define _F14BP0 C1BUFPNT4bits.F14BP0
#define _F14BP1 C1BUFPNT4bits.F14BP1
#define _F14BP2 C1BUFPNT4bits.F14BP2
#define _F14BP3 C1BUFPNT4bits.F14BP3
#define _F15BP0 C1BUFPNT4bits.F15BP0
#define _F15BP1 C1BUFPNT4bits.F15BP1
#define _F15BP2 C1BUFPNT4bits.F15BP2
#define _F15BP3 C1BUFPNT4bits.F15BP3

/* C1RXOVF1 */
#define _RXOVF0 C1RXOVF1bits.RXOVF0
#define _RXOVF1 C1RXOVF1bits.RXOVF1
#define _RXOVF2 C1RXOVF1bits.RXOVF2
#define _RXOVF3 C1RXOVF1bits.RXOVF3
#define _RXOVF4 C1RXOVF1bits.RXOVF4
#define _RXOVF5 C1RXOVF1bits.RXOVF5
#define _RXOVF6 C1RXOVF1bits.RXOVF6
#define _RXOVF7 C1RXOVF1bits.RXOVF7
#define _RXOVF8 C1RXOVF1bits.RXOVF8
#define _RXOVF9 C1RXOVF1bits.RXOVF9
#define _RXOVF10 C1RXOVF1bits.RXOVF10
#define _RXOVF11 C1RXOVF1bits.RXOVF11
#define _RXOVF12 C1RXOVF1bits.RXOVF12
#define _RXOVF13 C1RXOVF1bits.RXOVF13
#define _RXOVF14 C1RXOVF1bits.RXOVF14
#define _RXOVF15 C1RXOVF1bits.RXOVF15

/* C1RXOVF2 */
#define _RXOVF16 C1RXOVF2bits.RXOVF16
#define _RXOVF17 C1RXOVF2bits.RXOVF17
#define _RXOVF18 C1RXOVF2bits.RXOVF18
#define _RXOVF19 C1RXOVF2bits.RXOVF19
#define _RXOVF20 C1RXOVF2bits.RXOVF20
#define _RXOVF21 C1RXOVF2bits.RXOVF21
#define _RXOVF22 C1RXOVF2bits.RXOVF22
#define _RXOVF23 C1RXOVF2bits.RXOVF23
#define _RXOVF24 C1RXOVF2bits.RXOVF24
#define _RXOVF25 C1RXOVF2bits.RXOVF25
#define _RXOVF26 C1RXOVF2bits.RXOVF26
#define _RXOVF27 C1RXOVF2bits.RXOVF27
#define _RXOVF28 C1RXOVF2bits.RXOVF28
#define _RXOVF29 C1RXOVF2bits.RXOVF29
#define _RXOVF30 C1RXOVF2bits.RXOVF30
#define _RXOVF31 C1RXOVF2bits.RXOVF31

/* C1RXM0SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _MIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1TR01CON */
#define _TX0PRI C1TR01CONbits.TX0PRI
#define _RTREN0 C1TR01CONbits.RTREN0
#define _TXREQ0 C1TR01CONbits.TXREQ0
#define _TXERR0 C1TR01CONbits.TXERR0
#define _TXLARB0 C1TR01CONbits.TXLARB0
#define _TXABT0 C1TR01CONbits.TXABT0
#define _TXEN0 C1TR01CONbits.TXEN0
#define _TX1PRI C1TR01CONbits.TX1PRI
#define _RTREN1 C1TR01CONbits.RTREN1
#define _TXREQ1 C1TR01CONbits.TXREQ1
#define _TXERR1 C1TR01CONbits.TXERR1
#define _TXLARB1 C1TR01CONbits.TXLARB1
#define _TXABT1 C1TR01CONbits.TXABT1
#define _TXEN1 C1TR01CONbits.TXEN1
#define _TX0PRI0 C1TR01CONbits.TX0PRI0
#define _TX0PRI1 C1TR01CONbits.TX0PRI1
#define _TX1PRI0 C1TR01CONbits.TX1PRI0
#define _TX1PRI1 C1TR01CONbits.TX1PRI1

/* C1RXM0EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1TR23CON */
#define _TX2PRI C1TR23CONbits.TX2PRI
#define _RTREN2 C1TR23CONbits.RTREN2
#define _TXREQ2 C1TR23CONbits.TXREQ2
#define _TXERR2 C1TR23CONbits.TXERR2
#define _TXLARB2 C1TR23CONbits.TXLARB2
#define _TXABT2 C1TR23CONbits.TXABT2
#define _TXEN2 C1TR23CONbits.TXEN2
#define _TX3PRI C1TR23CONbits.TX3PRI
#define _RTREN3 C1TR23CONbits.RTREN3
#define _TXREQ3 C1TR23CONbits.TXREQ3
#define _TXERR3 C1TR23CONbits.TXERR3
#define _TXLARB3 C1TR23CONbits.TXLARB3
#define _TXABT3 C1TR23CONbits.TXABT3
#define _TXEN3 C1TR23CONbits.TXEN3
#define _TX2PRI0 C1TR23CONbits.TX2PRI0
#define _TX2PRI1 C1TR23CONbits.TX2PRI1
#define _TX3PRI0 C1TR23CONbits.TX3PRI0
#define _TX3PRI1 C1TR23CONbits.TX3PRI1

/* C1RXM1SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _MIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1TR45CON */
#define _TX4PRI C1TR45CONbits.TX4PRI
#define _RTREN4 C1TR45CONbits.RTREN4
#define _TXREQ4 C1TR45CONbits.TXREQ4
#define _TXERR4 C1TR45CONbits.TXERR4
#define _TXLARB4 C1TR45CONbits.TXLARB4
#define _TXABT4 C1TR45CONbits.TXABT4
#define _TXEN4 C1TR45CONbits.TXEN4
#define _TX5PRI C1TR45CONbits.TX5PRI
#define _RTREN5 C1TR45CONbits.RTREN5
#define _TXREQ5 C1TR45CONbits.TXREQ5
#define _TXERR5 C1TR45CONbits.TXERR5
#define _TXLARB5 C1TR45CONbits.TXLARB5
#define _TXABT5 C1TR45CONbits.TXABT5
#define _TXEN5 C1TR45CONbits.TXEN5
#define _TX4PRI0 C1TR45CONbits.TX4PRI0
#define _TX4PRI1 C1TR45CONbits.TX4PRI1
#define _TX5PRI0 C1TR45CONbits.TX5PRI0
#define _TX5PRI1 C1TR45CONbits.TX5PRI1

/* C1RXM1EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1TR67CON */
#define _TX6PRI C1TR67CONbits.TX6PRI
#define _RTREN6 C1TR67CONbits.RTREN6
#define _TXREQ6 C1TR67CONbits.TXREQ6
#define _TXERR6 C1TR67CONbits.TXERR6
#define _TXLARB6 C1TR67CONbits.TXLARB6
#define _TXABT6 C1TR67CONbits.TXABT6
#define _TXEN6 C1TR67CONbits.TXEN6
#define _TX7PRI C1TR67CONbits.TX7PRI
#define _RTREN7 C1TR67CONbits.RTREN7
#define _TXREQ7 C1TR67CONbits.TXREQ7
#define _TXERR7 C1TR67CONbits.TXERR7
#define _TXLARB7 C1TR67CONbits.TXLARB7
#define _TXABT7 C1TR67CONbits.TXABT7
#define _TXEN7 C1TR67CONbits.TXEN7
#define _TX6PRI0 C1TR67CONbits.TX6PRI0
#define _TX6PRI1 C1TR67CONbits.TX6PRI1
#define _TX7PRI0 C1TR67CONbits.TX7PRI0
#define _TX7PRI1 C1TR67CONbits.TX7PRI1

/* C1RXM2SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _MIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1RXM2EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1RXF0SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EXIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1RXF0EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1RXF1SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EXIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1RXF1EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1RXF2SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EXIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1RXF2EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1RXF3SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EXIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1RXF3EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1RXF4SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EXIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1RXF4EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1RXF5SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EXIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1RXF5EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1RXF6SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EXIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1RXF6EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1RXF7SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EXIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1RXF7EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1RXF8SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EXIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1RXF8EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1RXF9SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EXIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1RXF9EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1RXF10SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EXIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1RXF10EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1RXF11SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EXIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1RXF11EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1RXF12SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EXIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1RXF12EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1RXF13SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EXIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1RXF13EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1RXF14SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EXIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1RXF14EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* C1RXF15SID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EXIDE cannot be defined because it is used by more than one SFR */
/* Bitname _SID cannot be defined because it is used by more than one SFR */
/* Bitname _EID16 cannot be defined because it is used by more than one SFR */
/* Bitname _EID17 cannot be defined because it is used by more than one SFR */
/* Bitname _SID0 cannot be defined because it is used by more than one SFR */
/* Bitname _SID1 cannot be defined because it is used by more than one SFR */
/* Bitname _SID2 cannot be defined because it is used by more than one SFR */
/* Bitname _SID3 cannot be defined because it is used by more than one SFR */
/* Bitname _SID4 cannot be defined because it is used by more than one SFR */
/* Bitname _SID5 cannot be defined because it is used by more than one SFR */
/* Bitname _SID6 cannot be defined because it is used by more than one SFR */
/* Bitname _SID7 cannot be defined because it is used by more than one SFR */
/* Bitname _SID8 cannot be defined because it is used by more than one SFR */
/* Bitname _SID9 cannot be defined because it is used by more than one SFR */
/* Bitname _SID10 cannot be defined because it is used by more than one SFR */

/* C1RXF15EID */
/* Bitname _EID cannot be defined because it is used by more than one SFR */
/* Bitname _EID0 cannot be defined because it is used by more than one SFR */
/* Bitname _EID1 cannot be defined because it is used by more than one SFR */
/* Bitname _EID2 cannot be defined because it is used by more than one SFR */
/* Bitname _EID3 cannot be defined because it is used by more than one SFR */
/* Bitname _EID4 cannot be defined because it is used by more than one SFR */
/* Bitname _EID5 cannot be defined because it is used by more than one SFR */
/* Bitname _EID6 cannot be defined because it is used by more than one SFR */
/* Bitname _EID7 cannot be defined because it is used by more than one SFR */
/* Bitname _EID8 cannot be defined because it is used by more than one SFR */
/* Bitname _EID9 cannot be defined because it is used by more than one SFR */
/* Bitname _EID10 cannot be defined because it is used by more than one SFR */
/* Bitname _EID11 cannot be defined because it is used by more than one SFR */
/* Bitname _EID12 cannot be defined because it is used by more than one SFR */
/* Bitname _EID13 cannot be defined because it is used by more than one SFR */
/* Bitname _EID14 cannot be defined because it is used by more than one SFR */
/* Bitname _EID15 cannot be defined because it is used by more than one SFR */

/* ODCD */
#define _ODCD0 ODCDbits.ODCD0
#define _ODCD1 ODCDbits.ODCD1
#define _ODCD2 ODCDbits.ODCD2
#define _ODCD3 ODCDbits.ODCD3
#define _ODCD4 ODCDbits.ODCD4
#define _ODCD5 ODCDbits.ODCD5
#define _ODCD6 ODCDbits.ODCD6
#define _ODCD7 ODCDbits.ODCD7
#define _ODCD8 ODCDbits.ODCD8
#define _ODCD9 ODCDbits.ODCD9
#define _ODCD10 ODCDbits.ODCD10
#define _ODCD11 ODCDbits.ODCD11

/* ODCF */
#define _ODCF0 ODCFbits.ODCF0
#define _ODCF1 ODCFbits.ODCF1
#define _ODCF2 ODCFbits.ODCF2
#define _ODCF3 ODCFbits.ODCF3
#define _ODCF4 ODCFbits.ODCF4
#define _ODCF5 ODCFbits.ODCF5
#define _ODCF6 ODCFbits.ODCF6

/* ODCG */
#define _ODCG0 ODCGbits.ODCG0
#define _ODCG1 ODCGbits.ODCG1
#define _ODCG2 ODCGbits.ODCG2
#define _ODCG3 ODCGbits.ODCG3
#define _ODCG6 ODCGbits.ODCG6
#define _ODCG7 ODCGbits.ODCG7
#define _ODCG8 ODCGbits.ODCG8
#define _ODCG9 ODCGbits.ODCG9
#define _ODCG12 ODCGbits.ODCG12
#define _ODCG13 ODCGbits.ODCG13
#define _ODCG14 ODCGbits.ODCG14
#define _ODCG15 ODCGbits.ODCG15

/* RCON */
#define _POR RCONbits.POR
#define _BOR RCONbits.BOR
#define _IDLE RCONbits.IDLE
#define _SLEEP RCONbits.SLEEP
#define _WDTO RCONbits.WDTO
#define _SWDTEN RCONbits.SWDTEN
#define _SWR RCONbits.SWR
#define _EXTR RCONbits.EXTR
#define _VREGS RCONbits.VREGS
#define _IOPUWR RCONbits.IOPUWR
#define _TRAPR RCONbits.TRAPR

/* OSCCON */
#define _OSWEN OSCCONbits.OSWEN
#define _LPOSCEN OSCCONbits.LPOSCEN
#define _CF OSCCONbits.CF
#define _LOCK OSCCONbits.LOCK
#define _CLKLOCK OSCCONbits.CLKLOCK
#define _NOSC OSCCONbits.NOSC
#define _COSC OSCCONbits.COSC
#define _NOSC0 OSCCONbits.NOSC0
#define _NOSC1 OSCCONbits.NOSC1
#define _NOSC2 OSCCONbits.NOSC2
#define _COSC0 OSCCONbits.COSC0
#define _COSC1 OSCCONbits.COSC1
#define _COSC2 OSCCONbits.COSC2

/* CLKDIV */
#define _PLLPRE CLKDIVbits.PLLPRE
#define _PLLPOST CLKDIVbits.PLLPOST
#define _FRCDIV CLKDIVbits.FRCDIV
#define _DOZEN CLKDIVbits.DOZEN
#define _DOZE CLKDIVbits.DOZE
#define _ROI CLKDIVbits.ROI
#define _PLLPRE0 CLKDIVbits.PLLPRE0
#define _PLLPRE1 CLKDIVbits.PLLPRE1
#define _PLLPRE2 CLKDIVbits.PLLPRE2
#define _PLLPRE3 CLKDIVbits.PLLPRE3
#define _PLLPRE4 CLKDIVbits.PLLPRE4
#define _PLLPOST0 CLKDIVbits.PLLPOST0
#define _PLLPOST1 CLKDIVbits.PLLPOST1
#define _FRCDIV0 CLKDIVbits.FRCDIV0
#define _FRCDIV1 CLKDIVbits.FRCDIV1
#define _FRCDIV2 CLKDIVbits.FRCDIV2
#define _DOZE0 CLKDIVbits.DOZE0
#define _DOZE1 CLKDIVbits.DOZE1
#define _DOZE2 CLKDIVbits.DOZE2

/* PLLFBD */
#define _PLLDIV PLLFBDbits.PLLDIV
#define _PLLDIV0 PLLFBDbits.PLLDIV0
#define _PLLDIV1 PLLFBDbits.PLLDIV1
#define _PLLDIV2 PLLFBDbits.PLLDIV2
#define _PLLDIV3 PLLFBDbits.PLLDIV3
#define _PLLDIV4 PLLFBDbits.PLLDIV4
#define _PLLDIV5 PLLFBDbits.PLLDIV5
#define _PLLDIV6 PLLFBDbits.PLLDIV6
#define _PLLDIV7 PLLFBDbits.PLLDIV7
#define _PLLDIV8 PLLFBDbits.PLLDIV8

/* OSCTUN */
#define _TUN OSCTUNbits.TUN
#define _TUN0 OSCTUNbits.TUN0
#define _TUN1 OSCTUNbits.TUN1
#define _TUN2 OSCTUNbits.TUN2
#define _TUN3 OSCTUNbits.TUN3
#define _TUN4 OSCTUNbits.TUN4
#define _TUN5 OSCTUNbits.TUN5

/* BSRAM */
#define _RL_BSR BSRAMbits.RL_BSR
#define _IR_BSR BSRAMbits.IR_BSR
#define _IW_BSR BSRAMbits.IW_BSR

/* SSRAM */
#define _RL_SSR SSRAMbits.RL_SSR
#define _IR_SSR SSRAMbits.IR_SSR
#define _IW_SSR SSRAMbits.IW_SSR

/* NVMCON */
#define _NVMOP NVMCONbits.NVMOP
#define _ERASE NVMCONbits.ERASE
#define _WRERR NVMCONbits.WRERR
#define _WREN NVMCONbits.WREN
#define _WR NVMCONbits.WR
#define _NVMOP0 NVMCONbits.NVMOP0
#define _NVMOP1 NVMCONbits.NVMOP1
#define _NVMOP2 NVMCONbits.NVMOP2
#define _NVMOP3 NVMCONbits.NVMOP3

/* PMD1 */
#define _AD1MD PMD1bits.AD1MD
#define _C1MD PMD1bits.C1MD
#define _C2MD PMD1bits.C2MD
#define _SPI1MD PMD1bits.SPI1MD
#define _SPI2MD PMD1bits.SPI2MD
#define _U1MD PMD1bits.U1MD
#define _U2MD PMD1bits.U2MD
#define _I2C1MD PMD1bits.I2C1MD
#define _DCIMD PMD1bits.DCIMD
#define _T1MD PMD1bits.T1MD
#define _T2MD PMD1bits.T2MD
#define _T3MD PMD1bits.T3MD
#define _T4MD PMD1bits.T4MD
#define _T5MD PMD1bits.T5MD

/* PMD2 */
#define _OC1MD PMD2bits.OC1MD
#define _OC2MD PMD2bits.OC2MD
#define _OC3MD PMD2bits.OC3MD
#define _OC4MD PMD2bits.OC4MD
#define _OC5MD PMD2bits.OC5MD
#define _OC6MD PMD2bits.OC6MD
#define _OC7MD PMD2bits.OC7MD
#define _OC8MD PMD2bits.OC8MD
#define _IC1MD PMD2bits.IC1MD
#define _IC2MD PMD2bits.IC2MD
#define _IC3MD PMD2bits.IC3MD
#define _IC4MD PMD2bits.IC4MD
#define _IC5MD PMD2bits.IC5MD
#define _IC6MD PMD2bits.IC6MD
#define _IC7MD PMD2bits.IC7MD
#define _IC8MD PMD2bits.IC8MD

/* PMD3 */
#define _AD2MD PMD3bits.AD2MD
#define _I2C2MD PMD3bits.I2C2MD
#define _T6MD PMD3bits.T6MD
#define _T7MD PMD3bits.T7MD
#define _T8MD PMD3bits.T8MD
#define _T9MD PMD3bits.T9MD


/* ---------------------------------------------------------- */
/* Some useful macros for inline assembly stuff               */
/* ---------------------------------------------------------- */

#define Nop()    {__asm__ volatile ("nop");}
#define ClrWdt() {__asm__ volatile ("clrwdt");}
#define Sleep()  {__asm__ volatile ("pwrsav #0");}
#define Idle()   {__asm__ volatile ("pwrsav #1");}

/*----------------------------------------------------------- */
/* Some useful macros for allocating data memory              */
/*----------------------------------------------------------- */

/* The following macros require an argument N that specifies  */
/* alignment. N must a power of two, minimum value = 2.       */
/* For example, to declare an uninitialized array in X memory */
/* that is aligned to a 32 byte address:                      */
/*                                                            */
/* int _XBSS(32) xbuf[16];                                    */
/*                                                            */
#define _XBSS(N)    __attribute__((space(xmemory),far,aligned(N)))
#define _XDATA(N)   __attribute__((space(xmemory),far,aligned(N)))
#define _YBSS(N)    __attribute__((space(ymemory),far,aligned(N)))
#define _YDATA(N)   __attribute__((space(ymemory),far,aligned(N)))

/* The following macros do not require an argument. They can  */
/* be used to locate a variable in persistent data memory or  */
/* in near data memory. For example, to declare two variables */
/* that retain their values across a device reset:            */
/*                                                            */
/* int _PERSISTENT var1,var2;                                 */
/*                                                            */
#define _PERSISTENT __attribute__((persistent))
#define _NEAR       __attribute__((near))

/* ---------------------------------------------------------- */
/* Some useful macros for declaring functions                 */
/* ---------------------------------------------------------- */

/* The following macros can be used to declare interrupt      */
/* service routines (ISRs). For example, to declare an ISR    */
/* for the timer1 interrupt:                                  */
/*                                                            */
/* void _ISR _T1Interrupt(void);                              */
/*                                                            */
/* To declare an ISR for the SPI1 interrupt with fast         */
/* context save:                                              */
/*                                                            */
/* void _ISRFAST _SPI1Interrupt(void);                        */
/*                                                            */
/* Note: ISRs will be installed into the interrupt vector     */
/* tables automatically if the reserved names listed in the   */
/* MPLAB C30 Compiler User's Guide (DS51284) are used.        */
/*                                                            */
#define _ISR __attribute__((interrupt))
#define _ISRFAST __attribute__((interrupt, shadow))

/* ---------------------------------------------------------- */
/* Some useful macros for changing the CPU IPL                */
/* ---------------------------------------------------------- */

/* The following macros can be used to modify the current CPU */
/* IPL. The definition of the macro may vary from device to   */
/* device.                                                    */
/*                                                            */
/* To safely set the CPU IPL, use SET_CPU_IPL(ipl); the       */
/* valid range of ipl is 0-7, it may be any expression.       */
/*                                                            */
/* SET_CPU_IPL(7);                                            */
/*                                                            */
/* To preserve the current IPL and save it use                */
/* SET_AND_SAVE_CPU_IPL(save_to, ipl); the valid range of ipl */
/* is 0-7 and may be any expression, save_to should denote    */
/* some temporary storage.                                    */
/*                                                            */
/* int old_ipl;                                               */
/*                                                            */
/* SET_AND_SAVE_CPU_IPL(old_ipl, 7);                          */
/*                                                            */
/* The IPL can be restored with RESTORE_CPU_IPL(saved_to)     */
/*                                                            */
/* RESTORE_CPU_IPL(old_ipl);                                  */

#define SET_CPU_IPL(ipl) {       \
  int DISI_save;                 \
                                 \
  DISI_save = DISICNT;           \
  asm volatile ("disi #0x3FFF"); \
  SRbits.IPL = ipl;              \
  DISICNT = DISI_save; } (void) 0;

#define SET_AND_SAVE_CPU_IPL(save_to, ipl) { \
  save_to = SRbits.IPL; \
  SET_CPU_IPL(ipl); } (void) 0;

#define RESTORE_CPU_IPL(saved_to) SET_CPU_IPL(saved_to)


/* -------------------------------------------------------- */
/* External declaration for DMA memory base address         */
/*                                                          */
/* For example:                                             */
/*                                                          */
/*   unsigned int addr = (unsigned int) &_DMA_BASE;         */
/*                                                          */
/* -------------------------------------------------------- */

extern void *_DMA_BASE;


/* -------------------------------------------------------- */
/* Macros for setting device configuration registers        */
/* -------------------------------------------------------- */

/* Register FBS (0xf80000)                               */

#define _FBS(x) __attribute__((section("__FBS.sec,code"))) int _FBS = (x);

/*
** Only one invocation of FBS should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FBS.
** Multiple options may be combined, as shown:
**
** _FBS( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Boot Segment Data Ram:
**     RBS_LARGE_RAM        Large Sized Boot Ram
**     RBS_MEDIUM_RAM       Medium Sized Boot Ram
**     RBS_SMALL_RAM        Small Sized Boot Ram
**     RBS_NO_RAM           No Boot Ram
**
**   Boot Segment Program Memory:
**     BSS_LARGE_FLASH_HIGH  High Security Lar Boot Flash
**     BSS_MEDIUM_FLASH_HIGH High Security Med Boot Flash
**     BSS_SMALL_FLASH_HIGH  High Security Small Boot Flash
**     BSS_LARGE_FLASH_STD   Standard Security Lar Boot Flash
**     BSS_MEDIUM_FLASH_STD  Standard Security Med Boot Flash
**     BSS_SMALL_FLASH_STD  Standard Security Small Boot Flash
**     BSS_NO_FLASH         No Boot Segment Program Memory
**
**    Write Protect :
**     BWRP_WRPROTECT_ON     Enabled
**     BWRP_WRPROTECT_OFF    Disabled
**
*/

#define RBS_LARGE_RAM        0xFF3F
#define RBS_MEDIUM_RAM       0xFF7F
#define RBS_SMALL_RAM        0xFFBF
#define RBS_NO_RAM           0xFFFF

#define BSS_LARGE_FLASH_HIGH 0xFFF1
#define BSS_MEDIUM_FLASH_HIGH 0xFFF3
#define BSS_SMALL_FLASH_HIGH 0xFFF5
#define BSS_LARGE_FLASH_STD  0xFFF9
#define BSS_MEDIUM_FLASH_STD 0xFFFB
#define BSS_SMALL_FLASH_STD  0xFFFD
#define BSS_NO_FLASH         0xFFFF

#define BWRP_WRPROTECT_ON    0xFFFE
#define BWRP_WRPROTECT_OFF   0xFFFF

/* Register FSS (0xf80002)                               */

#define _FSS(x) __attribute__((section("__FSS.sec,code"))) int _FSS = (x);

/*
** Only one invocation of FSS should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FSS.
** Multiple options may be combined, as shown:
**
** _FSS( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Secure Segment Data Ram:
**     RSS_LARGE_RAM         Large Sized Secure Ram
**     RSS_MEDIUM_RAM        Medium Sized Secure Ram
**     RSS_SMALL_RAM         Small Sized Secure Ram
**     RSS_NO_RAM           No Secure Ram
**
**   Secure Segment Program Memory:
**     SSS_LARGE_FLASH_HIGH  High Security Lar Secure Flash
**     SSS_MEDIUM_FLASH_HIGH High Security Med Secure Flash
**     SSS_SMALL_FLASH_HIGH  High Security Small Secure Flash
**     SSS_LARGE_FLASH_STD   Standard Security Large Secure Flash
**     SSS_MEDIUM_FLASH_STD  Standard Security Med Secure Flash
**     SSS_SMALL_FLASH_STD  Standard Security Small Secure Flash
**     SSS_NO_FLASH         No Secure Segment
**
**    Write Protect :
**     SWRP_WRPROTECT_ON     Enabled
**     SWRP_WRPROTECT_OFF    Disabled
**
*/

#define RSS_LARGE_RAM        0xFF3F
#define RSS_MEDIUM_RAM       0xFF7F
#define RSS_SMALL_RAM        0xFFBF
#define RSS_NO_RAM           0xFFFF

#define SSS_LARGE_FLASH_HIGH 0xFFF1
#define SSS_MEDIUM_FLASH_HIGH 0xFFF3
#define SSS_SMALL_FLASH_HIGH 0xFFF5
#define SSS_LARGE_FLASH_STD  0xFFF9
#define SSS_MEDIUM_FLASH_STD 0xFFFB
#define SSS_SMALL_FLASH_STD  0xFFFD
#define SSS_NO_FLASH         0xFFFF

#define SWRP_WRPROTECT_ON    0xFFFE
#define SWRP_WRPROTECT_OFF   0xFFFF

/* Register FGS (0xf80004)                               */

#define _FGS(x) __attribute__((section("__FGS.sec,code"))) int _FGS = (x);

/*
** Only one invocation of FGS should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FGS.
** Multiple options may be combined, as shown:
**
** _FGS( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Code Protect:
**     GSS_HIGH              high security protect on
**     GSS_STD               standard security code protect on
**     GSS_OFF              code protect off
**
**   Code Protect:
**     GCP_ON               Enabled
**     GCP_OFF              Disabled
**
**   Write Protect:
**     GWRP_ON              Enabled
**     GWRP_OFF             Disabled
**
*/

#define GSS_HIGH             0xFFFB
#define GSS_STD              0xFFFD
#define GSS_OFF              0xFFFF

#define GCP_ON               0xFFFD
#define GCP_OFF              0xFFFF

#define GWRP_ON              0xFFFE
#define GWRP_OFF             0xFFFF

/* Register FOSCSEL (0xf80006)                               */

#define _FOSCSEL(x) __attribute__((section("__FOSCSEL.sec,code"))) int _FOSCSEL = (x);

/*
** Only one invocation of FOSCSEL should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FOSCSEL.
** Multiple options may be combined, as shown:
**
** _FOSCSEL( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Oscillator Source Selection:
**     FNOSC_FRC            Fast RC oscillator
**     FNOSC_FRCPLL         Fast RC oscillator w/ divide and PLL
**     FNOSC_PRI            Primary oscillator (XT, HS, EC)
**     FNOSC_PRIPLL         Primary oscillator (XT, HS, EC) w/ PLL
**     FNOSC_SOSC           Secondary oscillator
**     FNOSC_LPRC           Low power RC oscillator
**     FNOSC_FRCDIV16       Fast RC oscillator w/ divide by 16
**     FNOSC_LPRCDIVN        Low power Fast RC oscillator w/divide by N
**
**   Two-speed Oscillator Startup :
**     IESO_OFF             Disabled
**     IESO_ON              Enabled
**
*/

#define FNOSC_FRC            0xFFF8
#define FNOSC_FRCPLL         0xFFF9
#define FNOSC_PRI            0xFFFA
#define FNOSC_PRIPLL         0xFFFB
#define FNOSC_SOSC           0xFFFC
#define FNOSC_LPRC           0xFFFD
#define FNOSC_FRCDIV16       0xFFFE
#define FNOSC_LPRCDIVN       0xFFFF

#define IESO_OFF             0xFF7F
#define IESO_ON              0xFFFF

/* Register FOSC (0xf80008)                               */

#define _FOSC(x) __attribute__((section("__FOSC.sec,code"))) int _FOSC = (x);

/*
** Only one invocation of FOSC should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FOSC.
** Multiple options may be combined, as shown:
**
** _FOSC( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Clock switching and clock monitor:
**     FCKSM_CSECME         Both enabled
**     FCKSM_CSECMD         Only clock switching enabled
**     FCKSM_CSDCMD         Both disabled
**
**   OSC2 Pin function:
**     OSCIOFNC_ON          Digital I/O
**     OSCIOFNC_OFF         OSC2 is clock O/P
**
**   Oscillator Selection:
**     POSCMD_EC            External clock
**     POSCMD_XT            XT oscillator
**     POSCMD_HS            HS oscillator
**     POSCMD_NONE          Primary disabled
**
*/

#define FCKSM_CSECME         0xFF3F
#define FCKSM_CSECMD         0xFF7F
#define FCKSM_CSDCMD         0xFFBF

#define OSCIOFNC_ON          0xFFFB
#define OSCIOFNC_OFF         0xFFFF

#define POSCMD_EC            0xFFFC
#define POSCMD_XT            0xFFFD
#define POSCMD_HS            0xFFFE
#define POSCMD_NONE          0xFFFF

/* Register FWDT (0xf8000a)                               */

#define _FWDT(x) __attribute__((section("__FWDT.sec,code"))) int _FWDT = (x);

/*
** Only one invocation of FWDT should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FWDT.
** Multiple options may be combined, as shown:
**
** _FWDT( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Watchdog Timer:
**     FWDTEN_OFF           Disabled
**     FWDTEN_ON            Enabled
**
**   Windowed WDT:
**     WINDIS_ON            Enabled
**     WINDIS_OFF           Disabled
**
**   Watchdog prescaler:
**     WDTPRE_PR32          1:32
**     WDTPRE_PR128         1:128
**
**   Watchdog postscaler:
**     WDTPOST_PS1          1:1
**     WDTPOST_PS2          1:2
**     WDTPOST_PS4          1:4
**     WDTPOST_PS8          1:8
**     WDTPOST_PS16         1:16
**     WDTPOST_PS32         1:32
**     WDTPOST_PS64         1:64
**     WDTPOST_PS128        1:128
**     WDTPOST_PS256        1:256
**     WDTPOST_PS512        1:512
**     WDTPOST_PS1024       1:1,024
**     WDTPOST_PS2048       1:2,048
**     WDTPOST_PS4096       1:4,096
**     WDTPOST_PS8192       1:8,192
**     WDTPOST_PS16384      1:16,384
**     WDTPOST_PS32768      1:32,768
**
*/

#define FWDTEN_OFF           0xFF7F
#define FWDTEN_ON            0xFFFF

#define WINDIS_ON            0xFFBF
#define WINDIS_OFF           0xFFFF

#define WDTPRE_PR32          0xFFEF
#define WDTPRE_PR128         0xFFFF

#define WDTPOST_PS1          0xFFF0
#define WDTPOST_PS2          0xFFF1
#define WDTPOST_PS4          0xFFF2
#define WDTPOST_PS8          0xFFF3
#define WDTPOST_PS16         0xFFF4
#define WDTPOST_PS32         0xFFF5
#define WDTPOST_PS64         0xFFF6
#define WDTPOST_PS128        0xFFF7
#define WDTPOST_PS256        0xFFF8
#define WDTPOST_PS512        0xFFF9
#define WDTPOST_PS1024       0xFFFA
#define WDTPOST_PS2048       0xFFFB
#define WDTPOST_PS4096       0xFFFC
#define WDTPOST_PS8192       0xFFFD
#define WDTPOST_PS16384      0xFFFE
#define WDTPOST_PS32768      0xFFFF

/* Register FPOR (0xf8000c)                               */

#define _FPOR(x) __attribute__((section("__FPOR.sec,code"))) int _FPOR = (x);

/*
** Only one invocation of FPOR should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FPOR.
** Multiple options may be combined, as shown:
**
** _FPOR( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Power-on Reset Value:
**     FPWRT_PWR1           Disabled
**     FPWRT_PWR2           2ms
**     FPWRT_PWR4           4ms
**     FPWRT_PWR8           8ms
**     FPWRT_PWR16          16ms
**     FPWRT_PWR32          32ms
**     FPWRT_PWR64          64ms
**     FPWRT_PWR128         128ms
**
*/

#define FPWRT_PWR1           0xFFF8
#define FPWRT_PWR2           0xFFF9
#define FPWRT_PWR4           0xFFFA
#define FPWRT_PWR8           0xFFFB
#define FPWRT_PWR16          0xFFFC
#define FPWRT_PWR32          0xFFFD
#define FPWRT_PWR64          0xFFFE
#define FPWRT_PWR128         0xFFFF

/* Register FUID0 (0xf80010)                               */

#define _FUID0(x) __attribute__((section("__FUID0.sec,code"))) int _FUID0 = (x);

/*
** Only one invocation of FUID0 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FUID0.
** Multiple options may be combined, as shown:
**
** _FUID0( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
*/

/* Register FUID1 (0xf80012)                               */

#define _FUID1(x) __attribute__((section("__FUID1.sec,code"))) int _FUID1 = (x);

/*
** Only one invocation of FUID1 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FUID1.
** Multiple options may be combined, as shown:
**
** _FUID1( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
*/

/* Register FUID2 (0xf80014)                               */

#define _FUID2(x) __attribute__((section("__FUID2.sec,code"))) int _FUID2 = (x);

/*
** Only one invocation of FUID2 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FUID2.
** Multiple options may be combined, as shown:
**
** _FUID2( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
*/

/* Register FUID3 (0xf80016)                               */

#define _FUID3(x) __attribute__((section("__FUID3.sec,code"))) int _FUID3 = (x);

/*
** Only one invocation of FUID3 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FUID3.
** Multiple options may be combined, as shown:
**
** _FUID3( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
*/


#endif

