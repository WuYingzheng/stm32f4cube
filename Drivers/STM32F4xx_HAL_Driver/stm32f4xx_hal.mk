# 外设驱动接口
HAL_INC= -I$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Inc

HAL_SOURCES=$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma2d.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dsi.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s_ex.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc_ex.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_qspi.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rtc.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rtc_ex.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sd.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sdram.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmc.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_sdmmc.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sai.c\
	$(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sai_ex.c