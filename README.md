# STM32CubeF4 MCU Firmware Package
**STM32Cube** is an STMicroelectronics original initiative to ease the developers life by reducing efforts, time and cost.
**STM32Cube** covers the overall STM32 products portfolio. It includes a comprehensive embedded software platform (this repo), delivered for each series (such as the STM32CubeF4 for the STM32F4 series).
   * The CMSIS modules (core and device) corresponding to the ARM-tm core implemented in this STM32 product
   * The STM32 HAL-LL drivers : an abstraction drivers layer, the API ensuring maximized portability across the STM32 portfolio 
   * The BSP Drivers of each evaluation or demonstration board provided by this STM32 series 
   * A consistent set of middlewares components such as RTOS, USB, FatFS, LwIP, Graphics ...
   * A full set of software projects (basic examples, applications or demonstrations) for each board provided by this STM32 series
   
The **STM32CubeF4 MCU Package** projects are directly running on the STM32F4 series boards. You can find in each Projects/*Board name* directories a set of software projects (Applications/Demonstration/Examples) 

# 1. File Organization
- [Documentation](https://github.com/WuYingzheng/stm32f4cube/tree/master/Documentation) 
- [Drivers](https://github.com/WuYingzheng/stm32f4cube/tree/master/Drivers) stm32 hal driver, cmsis-core
- [Middlerwares](https://github.com/WuYingzheng/stm32f4cube/tree/master/Middlewares) Middleware library, including freeRTOS, Lwip, FatFS, etc...
- [projects](https://github.com/WuYingzheng/stm32f4cube/tree/master/projects) demo project for supported board, have the following status: [![Build Status](https://travis-ci.org/istarc/stm32.svg?branch=master)](https://travis-ci.org/istarc/stm32)
- [scripts](https://github.com/WuYingzheng/stm32f4cube/tree/master/scripts) script for openocd
- [utilities](https://github.com/WuYingzheng/stm32f4cube/tree/master/utilities) inlcuding stm32 seiral flash tools, micro_lib, uart_Log/lcd_log, etc.. 

# 2. How to Setup the Environment
## 2.1 Ubuntu LTS Users
Ubuntu users install the environment directly on host OS. :-)

 1. install [arm-none-eabi-gcc](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm)
 2. Download [Jlink_driver](https://www.segger.com/downloads/jlink/), [stlink_driver](https://github.com/texane/stlink)
 3. install openocd
 4. sudo apt-get install git
 5. git clone git@github.com:WuYingzheng/stm32f4cube.git
    
optional: you can add **STM32_SDK_DIR** to you env variable :-)
   
    export STM32_SDK_DIR="/floder/to/stm32f4Cube"

## 2.2 Other Platforms

    TODO

# 3. Usage
## 3.1 Build Existing Projects

    cd stm32f4Cube/project/**your_prefer_project_dir**/gcc
    make
    make j-flash (you need a jlink..., other flash the stm32 by interal bootloader)

## 3.2 Deploy an Existing Project

    TODO
    

# 4. Boards supported
  * [stm32f407zgt-pro](https://item.taobao.com/item.htm?spm=a230r.1.14.239.15b63b01Nxgf0Q&id=565644828969&ns=1&abbucket=6#detail)
  ![stm32f407zgt-pro](https://github.com/WuYingzheng/stm32f4cube/blob/master/Documentation/pictures/stmf407zgt-pro1.jpg)
  * [STM32469I-Discovery](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-discovery-kits/32f469idiscovery.html)
  ![STM32469I-Discovery](https://github.com/WuYingzheng/stm32f4cube/blob/master/Documentation/pictures/stm32f469-discovery1.jpg)
	
# 5. Troubleshooting
## 5.1 Reflash stlink to jlink
 * Download [Jlink_Fireware](https://www.segger.com/downloads/jlink/).
 * If you have successfully reflashed **stlink** to **jlink**, remember to use **JLinkLicenseManager** to add license, so that you have full access to jlink advanced features. [Segger_J-Link_keygen](https://raw.githubusercontent.com/WuYingzheng/stm32f4cube/master/utilities/PC_Software/Segger_J-Link_keygen.exe) may help you generate jlink license with a jlink serial key(tested on windows, OK).
 
## 5.2 fail to flash stm32 micro-controler
 * openocd烧录失败和stlink固件的版本有关系，如果失败请把stlink固件更新到最新版本
 * stm32f407zgt-pro芯片复位时，不能使用uart1! 解决方案，移除任何可能占用uart1的设备:
   板载ch340 uart使能后，芯片无法复位，必须关闭uart串口

# 6. More Info
 - [http://istarc.wordpress.com/][1]
 - [https://github.com/istarc/stm32][2]
 - [https://registry.hub.docker.com/u/istarc/stm32/][3]
 - [https://vagrantcloud.com/istarc/stm32][4]
  [1]: http://istarc.wordpress.com/
  [2]: https://github.com/istarc/stm32
  [3]: https://registry.hub.docker.com/u/istarc/stm32/
  [4]: https://vagrantcloud.com/istarc/stm32

  [openocd 教程](https://www.bilibili.com/video/av86932597?from=search&seid=384530457015525304)
