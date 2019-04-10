#include "stm32f4xx_hal.h"
#include "stm32469i_discovery.h"

UART_HandleTypeDef UartHandle;

void uartInit(void){
    UartHandle.Instance        = USART6;
    UartHandle.Init.BaudRate   = 9600;
    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
    UartHandle.Init.StopBits   = UART_STOPBITS_1;
    UartHandle.Init.Parity     = UART_PARITY_NONE;
    UartHandle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
    UartHandle.Init.Mode       = UART_MODE_TX_RX;
    if(HAL_UART_DeInit(&UartHandle) != HAL_OK){
        BSP_LED_On(LED4);
    } 
    if(HAL_UART_Init(&UartHandle) != HAL_OK){
        BSP_LED_On(LED4);
    } 
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *UartHandle){
  /* Turn LED1 on: Transfer in transmission process is correct */
  BSP_LED_On(LED1); 
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle){
  /* Turn LED3 on: Transfer in reception process is correct */
  BSP_LED_On(LED3);
}