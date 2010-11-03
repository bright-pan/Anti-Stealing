 /*
*********************************************************************************************************
*                                               uC/OS-II
*                                         The Real-Time Kernel
*
*                               (c) Copyright 2006, Micrium, Weston, FL
*                                          All Rights Reserved
*
*
*                                          dsPIC33 MPLab Port
*                                                 
*
* File         : os_cpu.h
* By           : Eric Shufro
* Port Version : V2.81 (and higher)
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                           INCLUDES
*********************************************************************************************************
*/

#include <p33FJ256GP506.h>

/*
*********************************************************************************************************
*                                          PROTOTYPES
*********************************************************************************************************
*/

void  OSCtxSw(void);                                             /* See os_cpu_a.s                                 */
void  OSIntCtxSw(void);
void  OSStartHighRdy(void);

/*
*********************************************************************************************************
*                                   APPLICATION INDEPENDENT DATA TYPES
*
* Notes : These data types are chosen based upon the C30 compiler datatype specifications
*********************************************************************************************************
*/

typedef unsigned char     BOOLEAN;
typedef unsigned char     INT8U;
typedef signed char       INT8S;
typedef unsigned int      INT16U;
typedef signed int        INT16S;
typedef unsigned long     INT32U;
typedef signed long       INT32S;
typedef float             FP32;
typedef long double       FP64;

/*
*********************************************************************************************************
*                                         OTHER DATA TYPES
*********************************************************************************************************
*/

typedef INT16U            OS_STK;                                /* Define the size of each stack entry            */
typedef INT16U            OS_CPU_SR;                             /* Define the size of CPU status register         */

/*
*********************************************************************************************************
*                                         PROCESSOR SPECIFICS
*********************************************************************************************************
*/

#define OS_CRITICAL_METHOD  3                                    /* Use type 3 critical sections                   */
#define OS_STK_GROWTH       0                                    /* Stack grows from low to high memory            */

#define OS_TASK_SW()        OSCtxSw()                            /* Macro for defining a high level context switch */
                                                                 /* This function call adds 4 bytes to the stack   */

#if OS_CRITICAL_METHOD == 1                                      /* Support critical method type 1                 */
#define OS_ENTER_CRITICAL() SRbits.IPL = 7                       /* Disable all interrupts                         */
#define OS_EXIT_CRITICAL()  SRbits.IPL = 0                       /* Eenable interrupts                             */
#endif

#if OS_CRITICAL_METHOD == 3                                      /* Support critical method type 3                 */
#define OS_ENTER_CRITICAL() {cpu_sr = SR; SRbits.IPL = 7;}       /* Disable all interrupts                         */
#define OS_EXIT_CRITICAL()  {SR = cpu_sr;}                       /* Enable  interrupts                             */
#endif

 

