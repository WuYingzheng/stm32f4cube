1. 设置程序的偏移地址:
0x08008000
* 对应的修改链接文件,　参见.ld file

2. 设置中断向量表的偏移地址
0x08008000
* 对应的修改中断控制寄存器，参见main()

# 注意事项
* jlink烧录过程要注意，防止意外擦除bootloader, [openocd document](http://openocd.org/doc/html/Flash-Commands.html#program)
