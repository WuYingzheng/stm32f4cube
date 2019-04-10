#include "stm32f4xx.h"

extern UART_HandleTypeDef UartHandle;
extern __IO ITStatus UartReady = RESET;




void uartInit(void);