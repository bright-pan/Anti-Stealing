;
;********************************************************************************************************
;                                               uC/OS-II
;                                         The Real-Time Kernel
;
;                         (c) Copyright 2002, Jean J. Labrosse, Weston, FL
;                                          All Rights Reserved
;
;
;                                  dsPIC33FJ Board Support Package
;
;
; File         : bsp_a.s
; By           : Eric Shufro
;********************************************************************************************************
;

;
;********************************************************************************************************
;                                                CONSTANTS
;********************************************************************************************************
;
    .equ     __33FJ256GP506, 1                    ; Inform the p33FG256GP710 header file that we are using a dsPIC33FJ256GP710

;
;********************************************************************************************************
;                                                INCLUDES
;********************************************************************************************************
;

    .include "p33FJ256GP506.inc"                  ; Include assembly equates for various CPU registers and bit masks
    .include "os_cpu_util_a.s"                    ; Include an assembly utility files with macros for saving and restoring the CPU registers

;
;********************************************************************************************************
;                                             LINKER SPECIFICS
;********************************************************************************************************
;

    .text                                                               ; Locate this file in the text region of the build

;
;********************************************************************************************************
;                                                 GLOBALS
;********************************************************************************************************
;

    .global __T3Interrupt
    .global __T4Interrupt
    .global __U1RXInterrupt
    .global __U1TXInterrupt
    .global __U2RXInterrupt
    .global __U2TXInterrupt

;
;********************************************************************************************************
;                                            OS Time Tick ISR Handler
;
; Description : This function services the OS Time Tick Interrupt when configured using Timer #2
;
; Notes       : All user interrupts should be defined as follows.
;********************************************************************************************************
;

__T3Interrupt:
    OS_REGS_SAVE                                                        ; 1) Save processor registers

    mov   #_OSIntNesting, w1
    inc.b [w1], [w1]                                                    ; 2) Call OSIntEnter() or increment OSIntNesting

    ;dec.b _OSIntNesting, wreg                                           ; 3) Check OSIntNesting. if OSIntNesting == 1, then save the stack pointer, otherwise jump to T2_Cont
	dec.b [w1], w0
    bra nz, T3_Cont
    mov _OSTCBCur, w0
    mov w15, [w0]

T3_Cont:
    call _OS_Tick_ISR_Handler                                           ; 4) Call YOUR ISR Handler (May be a C function). In this case, the OS Tick ISR Handler
    call _OSIntExit                                                     ; 5) Call OSIntExit() or decrement 1 from OSIntNesting

    OS_REGS_RESTORE                                                     ; 6) Restore registers

    retfie                                                              ; 7) Return from interrupt


;
;********************************************************************************************************
;                                            OS Time Tick ISR Handler
;
; Description : This function services the OS Time Tick Interrupt when configured using Timer #4
;
; Notes       : All user interrupts should be defined as follows.
;********************************************************************************************************
;

__T4Interrupt:
    OS_REGS_SAVE                                                        ; 1) Save processor registers

    mov   #_OSIntNesting, w1
    inc.b [w1], [w1]                                                    ; 2) Call OSIntEnter() or increment OSIntNesting

    ;dec.b _OSIntNesting, wreg                                           ; 3) Check OSIntNesting. if OSIntNesting == 1, then save the stack pointer, otherwise jump to T2_Cont
	dec.b [w1], w0
    bra nz, T4_Cont
    mov _OSTCBCur, w0
    mov w15, [w0]

T4_Cont:
    call _OS_Tick_ISR_Handler                                           ; 4) Call YOUR ISR Handler (May be a C function). In this case, the OS Tick ISR Handler
    call _OSIntExit                                                     ; 5) Call OSIntExit() or decrement 1 from OSIntNesting

    OS_REGS_RESTORE                                                     ; 6) Restore registers

    retfie                                                              ; 7) Return from interrupt
;
;********************************************************************************************************
; 
; 			GR47 通讯接收中断
; 
;********************************************************************************************************
;
__U1RXInterrupt:
    OS_REGS_SAVE                                                        ; 1) Save processor registers

    mov   #_OSIntNesting, w1
    inc.b [w1], [w1]                                                    ; 2) Call OSIntEnter() or increment OSIntNesting

    ;dec.b _OSIntNesting, wreg                                           ; 3) Check OSIntNesting. if OSIntNesting == 1, then save the stack pointer, otherwise jump to T2_Cont
	dec.b [w1], w0
    bra nz, U1RX_Cont
    mov _OSTCBCur, w0
    mov w15, [w0]

U1RX_Cont:
    call _Uart1_RxISRHandler                                           ; 4) Call YOUR ISR Handler (May be a C function). In this case, the OS Tick ISR Handler
    call _OSIntExit                                                     ; 5) Call OSIntExit() or decrement 1 from OSIntNesting

    OS_REGS_RESTORE                                                     ; 6) Restore registers

    retfie                                                              ; 7) Return from interrupt
;
;********************************************************************************************************
; 
; 			GR47 通讯发送中断
; 
;********************************************************************************************************
;
__U1TXInterrupt:
    OS_REGS_SAVE                                                        ; 1) Save processor registers

    mov   #_OSIntNesting, w1
    inc.b [w1], [w1]                                                    ; 2) Call OSIntEnter() or increment OSIntNesting

    ;dec.b _OSIntNesting, wreg                                           ; 3) Check OSIntNesting. if OSIntNesting == 1, then save the stack pointer, otherwise jump to T2_Cont
	dec.b [w1], w0
    bra nz, U1TX_Cont
    mov _OSTCBCur, w0
    mov w15, [w0]

U1TX_Cont:
    call _Uart1_TxISRHandler                                           ; 4) Call YOUR ISR Handler (May be a C function). In this case, the OS Tick ISR Handler
    call _OSIntExit                                                     ; 5) Call OSIntExit() or decrement 1 from OSIntNesting

    OS_REGS_RESTORE                                                     ; 6) Restore registers

    retfie                                                              ; 7) Return from interrupt
    
;
;********************************************************************************************************
; 
; 			RS485 通讯接收中断
; 
;********************************************************************************************************
;

__U2RXInterrupt:
    OS_REGS_SAVE                                                        ; 1) Save processor registers

    mov   #_OSIntNesting, w1
    inc.b [w1], [w1]                                                    ; 2) Call OSIntEnter() or increment OSIntNesting

    ;dec.b _OSIntNesting, wreg                                           ; 3) Check OSIntNesting. if OSIntNesting == 1, then save the stack pointer, otherwise jump to T2_Cont
	dec.b [w1], w0
    bra nz, U2RX_Cont
    mov _OSTCBCur, w0
    mov w15, [w0]

U2RX_Cont:
    call _Uart2_RxISRHandler                                           ; 4) Call YOUR ISR Handler (May be a C function). In this case, the OS Tick ISR Handler
    call _OSIntExit                                                     ; 5) Call OSIntExit() or decrement 1 from OSIntNesting

    OS_REGS_RESTORE                                                     ; 6) Restore registers

    retfie                                                              ; 7) Return from interrupt

;
;********************************************************************************************************
; 
; 			RS485 通讯发送中断
; 
;********************************************************************************************************
;
__U2TXInterrupt:
    OS_REGS_SAVE                                                        ; 1) Save processor registers

    mov   #_OSIntNesting, w1
    inc.b [w1], [w1]                                                    ; 2) Call OSIntEnter() or increment OSIntNesting

    ;dec.b _OSIntNesting, wreg                                           ; 3) Check OSIntNesting. if OSIntNesting == 1, then save the stack pointer, otherwise jump to T2_Cont
	dec.b [w1], w0
    bra nz, U2TX_Cont
    mov _OSTCBCur, w0
    mov w15, [w0]

U2TX_Cont:
    call _Uart2_TxISRHandler                                           ; 4) Call YOUR ISR Handler (May be a C function). In this case, the OS Tick ISR Handler
    call _OSIntExit                                                     ; 5) Call OSIntExit() or decrement 1 from OSIntNesting

    OS_REGS_RESTORE                                                     ; 6) Restore registers

    retfie                                                              ; 7) Return from interrupt
        
