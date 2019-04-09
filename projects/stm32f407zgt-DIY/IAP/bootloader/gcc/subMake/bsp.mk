BSP_INC= -I$(STM32_SDK_DIR)/Drivers/BSP/stm32f407zgt-DIY           # bsp

BSP_SOURCES=$(STM32_SDK_DIR)/Drivers/BSP/stm32f407zgt-DIY/stm32f4_discovery_accelerometer.c\
			$(STM32_SDK_DIR)/Drivers/BSP/stm32f407zgt-DIY/stm32f4_discovery_audio.c\
			$(STM32_SDK_DIR)/Drivers/BSP/stm32f407zgt-DIY/stm32f407_DIY.c\


BSP_COMPONENTS_INC= -I$(STM32_SDK_DIR)/Drivers/BSP/Components/cs43l22\
					-I$(STM32_SDK_DIR)/Drivers/BSP/Components/lis302dl\
					-I$(STM32_SDK_DIR)Drivers/BSP/Components/lis3dsh

BSP_COMPONENTS_SRC= $(STM32_SDK_DIR)/Drivers/BSP/Components/cs43l22/cs43l22.c\
					$(STM32_SDK_DIR)/Drivers/BSP/Components/lis302dl/lis302dl.c\
					$(STM32_SDK_DIR)/Drivers/BSP/Components/lis3dsh/lis3dsh.c