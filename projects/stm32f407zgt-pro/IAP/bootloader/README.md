# 基于UART ymodem 的bootloader


# flash 布局
 * chip: stm32f469zgt:
start at 0x08000000, size 0x00100000, buswidth 0, chipwidth 0   ??? 256k ?  不是很明白
   *  0: 0x00000000 (0x4000 16kB)   not protected
   *  1: 0x00004000 (0x4000 16kB)   not protected
   *  2: 0x00008000 (0x4000 16kB)   not protected
   *  3: 0x0000c000 (0x4000 16kB)   not protected
   *  4: 0x00010000 (0x10000 64kB)  not protected
   *  5: 0x00020000 (0x20000 128kB) not protected
   *  6: 0x00040000 (0x20000 128kB) not protected
   *  7: 0x00060000 (0x20000 128kB) not protected
   *  8: 0x00080000 (0x20000 128kB) not protected
   *  9: 0x000a0000 (0x20000 128kB) not protected
   * 10: 0x000c0000 (0x20000 128kB) not protected
   * 11: 0x000e0000 (0x20000 128kB) not protected

Following picture illustrates the situation in program memory:
Figure 2. Flash memory usage

 Top Flash Memory address 
   /-------------------------------------------\  0x080FFFFF
   |                                           |
   |                                           |
   |                                           |
   |                                           |
   |                                           |
   |          Sector 2 - Sector 11             |
   |                                           |
   |                                           |
   |                                           |
   |                                           |
   |                                           |
   |                                           |
   |                                           |
   |          User code                        |
   |                                           |
   |- - - - - - - - - - - - - - - - - - - - - -|
   |          Vector table                     |
   |-------------------------------------------|  0x08008000
   |          IAP code                         |
   |- - - - - - - - - - - - - - - - - - - - - -|
   |          Vector table                     |
   \-------------------------------------------/	 0x08000000		

# Attention
  * the size of bootloarder must not biger than 32k, because the start address of the application begin from 0x08008000

# 拓展阅读
## hex 文件解析
 * 格式如下:
  :本行数据长度 | 本行数据起始地址 | 数据类型 | 数据      | 校验码
    1 byte	      2 bytes        1 byte   n byte	 1 byte
 * 数据类型：
    '00' Data Rrecord：用来记录数据，HEX文件的大部分记录都是数据记录
    '01' End of File Record:用来标识文件结束，放在文件的最后，标识HEX文件的结尾
    '02' Extended Segment Address Record:用来标识扩展段地址的记录
    '03' Start Segment Address Record:开始段地址记录
    '04' Extended Linear Address Record:用来标识扩展线性地址的记录
    '05' Start Linear Address Record:开始线性地址记录

 * 校验和的算法为：计算校验和前所有16进制码的累加和(不计进位)，检验和 = 0x100 - 累加和

## 04,05两种类型和地址有关
   如 :02 0000 04 0800 F2 表示基地址为：(0x0800 << 16) = 0x0800 0000 