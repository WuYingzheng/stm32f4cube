# STM32CubeF4 MCU Firmware Package

# env set up
   * 激活jlink ==> JLinkLicenseManager add license.
   * cd $(STM32_SDK_DIR)
   * source SOURCEME

# git push
   * git push -u origin master

**STM32Cube** is an STMicroelectronics original initiative to ease the developers life by reducing efforts, time and cost.

**STM32Cube** covers the overall STM32 products portfolio. It includes a comprehensive embedded software platform (this repo), delivered for each series (such as the STM32CubeF4 for the STM32F4 series).
   * The CMSIS modules (core and device) corresponding to the ARM-tm core implemented in this STM32 product
   * The STM32 HAL-LL drivers : an abstraction drivers layer, the API ensuring maximized portability across the STM32 portfolio 
   * The BSP Drivers of each evaluation or demonstration board provided by this STM32 series 
   * A consistent set of middlewares components such as RTOS, USB, FatFS, LwIP, Graphics ...
   * A full set of software projects (basic examples, applications or demonstrations) for each board provided by this STM32 series
   
The **STM32CubeF4 MCU Package** projects are directly running on the STM32F4 series boards. You can find in each Projects/*Board name* directories a set of software projects (Applications/Demonstration/Examples) 

## Boards available
  * STM32F4 
    * [STM32F4-Discovery](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/
    * [STM32F411E-Discovery](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-discovery-kits/32f411ediscovery.html)
    * [STM32F412G-Discovery](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-discovery-kits/32f412gdiscovery.html)
    * [STM32F412ZG-Nucleo](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-nucleo/nucleo-f412zg.html)
    * [STM32F429I-Discovery](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-discovery-kits/32f429idiscovery.html)
    * [STM32429I_EVAL](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-eval-boards/stm32429i-eval.html)
    * [STM3240G_EVAL](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-eval-boards/stm3240g-eval.html)
    * [STM32446E_EVAL](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-eval-boards/stm32446e-eval.html)
    * [STM32446E-Nucleo](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-nucleo/nucleo-f446re.html)
    * [STM32469I_EVAL](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-eval-boards/stm32479i-eval.html)
    * [STM32469I-Discovery](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-discovery-kits/32f469idiscovery.html)
	
## Troubleshooting
 * openocd烧录失败和stlink固件的版本有关系，如果失败请把stlink固件更新到最新版本
 * stm32f407zgt-pro芯片复位时，不能使用uart1! 解决方案，移除任何可能占用uart1的设备:
   板载ch340 uart使能后，芯片无法复位，必须关闭uart串口
