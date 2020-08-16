# UART同通信例程
    连接器２号引脚　GND
    连接器６号引脚　tx
    连接器８号引脚　rx

    开发板连线方式具体参考上一级目录README.md

# 开发环境
    开发板     stm32f429discovery
    编译器安装：https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm
    openocd
    stlink

# 编译程序：
    发行版　　　　　　ｍake release
    如果需要调试程序　make debug

# 烧录程序：
    make flash
    >> 烧录完成后，led2会闪烁;
    >> 按开发板上的user按键，开始发送信息，发送成功后led1被点亮；
    >> 成功接收到串口信息后led3会被点亮；    

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