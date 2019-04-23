# 开发环境
    开发板     stm32f429discovery
    编译器安装：https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm
    openocd
    stlink

# UART同通信例程
    连接器２号引脚　GND
    连接器６号引脚　tx
    连接器８号引脚　rx
    波特率：　     115200
    配置:         8N1

   * 开发板连线方式:
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


# 编译程序：
    cd gcc
    发行版　　　　　　ｍake release
    如果需要调试程序　make debug

# 烧录程序：
    make flash
    >> 烧录完成后，led2会闪烁;
    >> 超级终端会显示答应信息；
    >> 成功接收到串口信息后led3会被点亮；    

@par Directory contents 

  - UART/UART_Printf/Inc/stm32f4xx_hal_conf.h    HAL configuration file
  - UART/UART_Printf/Inc/stm32f4xx_it.h          IT interrupt handlers header file
  - UART/UART_Printf/Inc/main.h                  Header for main.c module  
  - UART/UART_Printf/Src/stm32f4xx_it.c          Interrupt handlers
  - UART/UART_Printf/Src/main.c                  Main program
  - UART/UART_Printf/Src/stm32f4xx_hal_msp.c     HAL MSP module
  - UART/UART_Printf/Src/system_stm32f4xx.c      STM32F4xx system source file

# 如何实现printf():
* 在makefile中包含如下文件:
    INCLUDES+=-I$(STM32_SDK_DIR)/utilities/Log
    CSOURCES+=$(STM32_SDK_DIR)/utilities/Log/uart_log.c
* 调用如下函数初始化串口:
    uartLogInit(USARTx);

* 最终printf会调用_write()向串口写数据

# 调试程序：
    在一个终端中登录　openocd -f board/stm32f429discovery.cfg
    打开一个新的终端调试：　arm-none-eabi-gdb -x gdbinit bin/outp.elf
    成功进入调试后，RGB灯会跳动．．．

    常用的一些调试命令:
    r 运行程序，遇到断点会暂停，直到结束
    c 继续运行程序
    设置断点
    (gdb) b 8　　　　　　　　　　在行号中设置断点
    (gdb) b main　　　　　　　　在函数名处设置断点
    (gdb) b *main　　　　　　　和汇编有关．．．　　　　　　　　
    (gdb) b *0x804835c       在指定地址设置断点
    (gdb) d [num]　　　　　　　删除指定编号的断点
    s 　　　　　　　　　执行一行代码，如果代码中有函数调用，则进入子函数
    n 　　　　　　　　　执行一行代码，不会陷入子函数，在下一行停止
    si,ni            与上面两个类似，针对汇编指令
    ｐ <变量名称>      显示某个变量的值　

    ｑ                退出调试