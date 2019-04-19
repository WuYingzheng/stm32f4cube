# Bootloader Demo
 * uart1与用户交互，uart2用于传输.bin文件

# 快速验证
  1. 进入bootloader目录，编译工程并使用jlink烧录:
    make
    make j-flash
  2. 进入app目录，编译并烧录app:
    make
    make j-flash
  3. reset 开发板，开发板上两个led灯会闪烁, 证明bootloader可以boot上层app.

# flash扇区布局
 * chip: stm32f469zgt:
start at 0x08000000, size 0x00100000, buswidth 0, chipwidth 0   ??? 256k ?  不是很明白
   *  0: 0x00000000 (0x4000 16kB)   
   *  1: 0x00004000 (0x4000 16kB)   
   *  2: 0x00008000 (0x4000 16kB)   
   *  3: 0x0000c000 (0x4000 16kB)   
   *  4: 0x00010000 (0x10000 64kB)  
   *  5: 0x00020000 (0x20000 128kB) 
   *  6: 0x00040000 (0x20000 128kB) 
   *  7: 0x00060000 (0x20000 128kB) 
   *  8: 0x00080000 (0x20000 128kB) 
   *  9: 0x000a0000 (0x20000 128kB) 
   * 10: 0x000c0000 (0x20000 128kB) 
   * 11: 0x000e0000 (0x20000 128kB) 

# 串口boot
   实现uart串口IAP,以下操作的核心代码:
   projects/stm32f407zgt-pro/IAP/bootloader/src/menu.c
1. 首先通过jlink将bootloader烧录到flash中,目前bootloader使用flash的前两个扇区:
    0x08000000 ~ 0x08007FFF
2. bootloader通过串口1与用户交互，通过串口２传输数据，协议为ymodern; 目前只支持下载和跳转到APP．实验前请先接好两个串口，波特率 115200！
    * 开发板reset前按下key1, 开发板进入bootloader模式，led0被点亮；否则进入app模式,如果led1常亮，表示引导出错;
    * bootloader模式中，在交互界面中按下１，接着开发板等待传输数据
    * 在minicom中启用ymodern文件传输，传输成功交互界面会显示接收到的字节数
    * 传输成功后在交互界面中按３会跳转到app

# 开发注意事项
* 查看app与bootloader目录下的readme

# TODO
  * upload image from flash 
  * read data of specified flash address 
