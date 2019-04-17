#ifndef __UART_LOG_H
#define __UART_LOG_H
#include "stm32f4xx_hal.h"
#include  <sys/unistd.h>
#include "stdio.h"

void uartLogInit(USART_TypeDef *uartx);
int  getchar(void);

#endif