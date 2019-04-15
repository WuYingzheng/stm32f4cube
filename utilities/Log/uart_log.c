#include  <sys/unistd.h>
#include  <errno.h> 
#include "stm32f4xx_hal.h"

// if you want use printf() function, you must re-define UART_LOG_Handle
// in your source code, the initialize the uart consele with prope routings.
__attribute__((weak)) UART_HandleTypeDef UART_LOG_Handle;
  
#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */

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
// int _read(int file, char *data, int len)

#endif /* __GNUC__ */