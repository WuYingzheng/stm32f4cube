#include  <errno.h> 
#include "uart_log.h"

// if you want use printf() function, you must re-define UART_LOG_Handle
// in your source code, the initialize the uart consele with prope routings.
UART_HandleTypeDef UART_LOG_Handle;

void uartLogInit(USART_TypeDef *uartx){
   UART_LOG_Handle.Instance      = uartx;
   UART_LOG_Handle.Init.BaudRate = 115200;
   UART_LOG_Handle.Init.WordLength = UART_WORDLENGTH_8B;
   UART_LOG_Handle.Init.StopBits = UART_STOPBITS_1;
   UART_LOG_Handle.Init.Parity = UART_PARITY_NONE;
   UART_LOG_Handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
   UART_LOG_Handle.Init.Mode = UART_MODE_RX | UART_MODE_TX;
   UART_LOG_Handle.Init.OverSampling = UART_OVERSAMPLING_16;

  if(HAL_UART_Init(&UART_LOG_Handle) != HAL_OK){
    //Error_Handler();
  }
}

int getchar(void){
   char c=0;

   if ( UART_LOG_Handle.gState == HAL_UART_STATE_TIMEOUT ){
      UART_LOG_Handle.gState = HAL_UART_STATE_READY;
   }
   HAL_StatusTypeDef status =\
         HAL_UART_Receive(&UART_LOG_Handle, (uint8_t*)&c, 1, 0xffffffff);
         putchar(c);
   return (status == HAL_OK ? c : -1);
}
  
#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */

// putchar('a') is ok;
int _write(int file, char *data, int len)
{
   if ((file != STDOUT_FILENO) && (file != STDERR_FILENO))
   {
      // errno = EBADF;
      return -1;
   }

   // arbitrary timeout 1000
   HAL_StatusTypeDef status =\
         HAL_UART_Transmit(&UART_LOG_Handle, (uint8_t*)data, len, 1000);

   // return # of bytes written - as best we can tell
   return (status == HAL_OK ? len : 0);
}

// 用来实现getc();
// getchar() doesn't work properly
int _read (int fd, char *ptr, int len){
   if (fd != STDIN_FILENO){
      // errno = EBADF;
      return -1;
   }

   int tmp=len;
   if ( UART_LOG_Handle.gState == HAL_UART_STATE_TIMEOUT ){
      UART_LOG_Handle.gState = HAL_UART_STATE_READY;
   }
   HAL_StatusTypeDef status =\
         HAL_UART_Receive(&UART_LOG_Handle, (uint8_t*)ptr, len, 0xffffffff);
   return (status == HAL_OK ? len : 0);
}

#endif /* __GNUC__ */