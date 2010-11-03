/*
*********************************************************************************************************
*                                               MODULE
*********************************************************************************************************
*/

#ifndef  LIB_BUF_MODULE_PRESENT
#define  LIB_BUF_MODULE_PRESENT


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
//#include  <app_cfg.h>
//#include <bsp.h>
//#include <includes.h>

/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/
#define	SEND_ALL 		0 //发送一个字符串直到'\0'
#define	RECEIVE_ALL	0 //接受缓冲去中所有数据

#define 	BUF_SIZE 		256 //缓冲区大小为512




/*
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*/
typedef struct {
	unsigned int head;
	unsigned int tail;
	unsigned char buf[BUF_SIZE];
}BUFFER;

typedef struct {
	BUFFER r_buf;
	BUFFER w_buf;
}RW_BUFFER;

/*$PAGE*/
/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/



/*$PAGE*/
/*
*********************************************************************************************************
*                                               MACRO'S
*********************************************************************************************************
*/
#define INC(a) ((a) = ((a)+1) & (BUF_SIZE-1))
#define DEC(a) ((a) = ((a)-1) & (BUF_SIZE-1))
#define EMPTY(a) ((a).head == (a).tail)
#define FLUSH(a)	((a).head = (a).tail = 0)
#define LEFT(a) (((a).tail-(a).head-1)&(BUF_SIZE-1))
#define LAST(a) ((a).buf[(BUF_SIZE-1)&((a).head-1)])
#define FULL(a) (!LEFT(a))
#define CHARS(a) (((a).head-(a).tail)&(BUF_SIZE-1))
#define GETCH(queue,c) \
(void)({c=(queue).buf[(queue).tail];INC((queue).tail);})
#define PUTCH(c,queue) \
(void)({(queue).buf[(queue).head]=(c);INC((queue).head);})



/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

unsigned char *Receive_From_GR64(unsigned char *str, unsigned int str_len);
unsigned char *Receive_From_RS485(unsigned char *str, unsigned int str_len);

void Send_To_GR64(unsigned char *str, unsigned int str_len);
void Send_To_RS485(unsigned char *str, unsigned int str_len);

void Flush_RS485_Buffer(void);
void Flush_GR64_Buffer(void);

/*$PAGE*/
/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif                                                          /* End of lib mem module include.                       */

