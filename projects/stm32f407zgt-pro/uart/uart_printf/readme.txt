/**
  @page UART_Printf UART Printf example
  
  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    UART/UART_Printf/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the UART Printf example.
  ******************************************************************************
  @endverbatim

@par Example Description 

This example shows how to re-route the C library printf function to the UART.
The UART outputs a message on the HyperTerminal.

Board: stm32f407zgt-pro
Tx Pin: PA.02
Rx Pin: PA.03
   _________________________ 
  |           ______________|                       _______________
  |          |USART         |                      | HyperTerminal |
  |          |              |                      |               |
  |          |           TX |______________________|RX             |
  |          |              |                      |               |
  |          |              |     ttl Cable        |               |             
  |          |              |                      |               |
  |          |           RX |______________________|TX             |          
  |          |              |                      |               |           
  |          |______________|                      |_______________|          
  |                         |                       
  |                         |                    
  |                         |                      
  |                         |                      
  |_STM32_Board_____________|                      

想要uart正常工作，首先需要申请单片机资源，如GPIO,时钟，中断等，这部分工作在钩子函数中完成．
  HAL_UART_MspInit();
  HAL_UART_MspDeInit();
随后设置参数，The USART is configured as follows:
    - BaudRate = 9600 baud  
    - Word Length = 8 Bits (7 data bit + 1 parity bit)
    - One Stop Bit
    - no parity
    - Hardware flow control disabled (RTS and CTS signals)
    - Reception and transmission are enabled in the time
  调用HAL_UART_Init(),实现参数配置;
  
一旦uart配置完成，需要考虑将printf()重定向到串口;本例程实现了gcc编译器下的移植；
  移植的关键代码如下：
  #ifdef __GNUC__
  
  int _write(int file, char *data, int len){
   if ((file != STDOUT_FILENO) && (file != STDERR_FILENO))
   {
      errno = EBADF;
      return -1;
   }

   // arbitrary timeout 1000
   HAL_StatusTypeDef status =
      HAL_UART_Transmit(&UartHandle, (uint8_t*)data, len, 1000);

   // return # of bytes written - as best we can tell
   return (status == HAL_OK ? len : 0);
  }

  #endif /* __GNUC__ */

  重定义标准库中的_write()函数，将写入标准输出与标准错误的函数重定向到串口；


@note USARTx/UARTx instance used and associated resources can be updated in "main.h"
file depending hardware configuration used.

@note When the parity is enabled, the computed parity is inserted at the MSB
position of the transmitted data.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@note The connection of the LCD reset pin to a dedicated GPIO PK7 instead of the STM32F469 NRST pin may cause residual display on LCD with applications/examples that do not require display.
	  The LCD clear can be ensured by hardware through the board's power off/power on or by software calling the BSP_LCD_Reset() function.

@par Directory contents 

  - UART/UART_Printf/Inc/stm32f4xx_hal_conf.h    HAL configuration file
  - UART/UART_Printf/Inc/stm32f4xx_it.h          IT interrupt handlers header file
  - UART/UART_Printf/Inc/main.h                  Header for main.c module  
  - UART/UART_Printf/Src/stm32f4xx_it.c          Interrupt handlers
  - UART/UART_Printf/Src/main.c                  Main program
  - UART/UART_Printf/Src/stm32f4xx_hal_msp.c     HAL MSP module
  - UART/UART_Printf/Src/system_stm32f4xx.c      STM32F4xx system source file


@par Hardware and Software environment

  - This example runs on stm32f407zgt-pro devices.

  - 本历程已经在stm32f407zgt-pro开发板上测试通过，实验前先按照前面的连线方式连线;   

  - 编译：make
    烧录：make j-flash
    调试：Ozone uart.jdebug 

  - Hyperterminal configuration:
    - Data Length = 8 Bits
    - One Stop Bit
    - no parity
    - BaudRate = 9600 baud
    - Flow control: None 

@par 实验现象 ? 
  上电后开发板的led1会闪烁；
  按下开发板上的key1，led1会熄灭，开始执行printf()
  如果串口的连线正确，超级中断中出现"hello"字样；

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
