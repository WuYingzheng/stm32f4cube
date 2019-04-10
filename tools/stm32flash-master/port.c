/*
  这个文件用来探测端口，目前支持usart和i2c
  port_open函数会依次调用各种端口的OPEN函数，如果成功，就返回该端口的控制接口

  stm32flash - Open Source ST STM32 flash program for *nix
  Copyright (C) 2014 Antonio Borneo <borneo.antonio@gmail.com>

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <stdint.h>
#include <stdio.h>

#include "serial.h"
#include "port.h"

//声明串口对象和I2C接口对象
extern struct port_interface port_serial;
extern struct port_interface port_i2c;

//定义并初始化端口集合，现在支持usart和I2C
static struct port_interface *ports[] = {
	&port_serial,
	&port_i2c,
	NULL,
};


port_err_t port_open(struct port_options *ops, struct port_interface **outport)
{
	int ret;
	static struct port_interface **port;

	for (port = ports; *port; port++) {
		ret = (*port)->open(*port, ops);
		if (ret == PORT_ERR_NODEV)//如果设备不存在就跳过
			continue;
		if (ret == PORT_ERR_OK)//成功打开就返回
			break;
		fprintf(stderr, "Error probing interface \"%s\"\n",
			(*port)->name);
	}
	if (*port == NULL) {
		fprintf(stderr, "Cannot handle device \"%s\"\n",
			ops->device);
		return PORT_ERR_UNKNOWN;
	}

	*outport = *port;
	return PORT_ERR_OK;
}
