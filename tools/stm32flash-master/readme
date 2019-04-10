sudo stm32flash -R -i ',,:rts&dtr,,-dtr,' /dev/ttyUSB0
sudo stm32flash  -i '-dtr&rts,,dtr,:rts&dtr,,-dtr,' /dev/ttyUSB0


首先，mcuisp控制DTR输出低电平，则DTR#输出高，然后RTS置高，则RTS#输出低，这样Q3导通了，BOOT0被拉高，即实现设置BOOT0为1，同时Q2也会导通，STM32的复位脚被拉低，实现复位。然后，延时100ms后，mcuisp控制DTR为高电平，则DTR#输出低电平，RTS维持高电平，则RTS#继续为低电平，此时STM32的复位引脚，由于Q2不再导通，变为高电平，STM32结束复位，但是BOOT0还是维持为1，从而进入ISP模式，接着mcuisp就可以开始连接STM32，下载代码了，从而实现一键下载。

程序下载完毕后，如果设置了编程后执行，STM32会再次被复位，此时DTR#为高，RTS#为低，STM32复位后，DTR#设置为低，RTS#设置为高，那么Q2和Q3都不导通，此时，STM32重新开始启动后，检测到BOOT0为0，程序开始正常运行，一键下载至此就完成了。
