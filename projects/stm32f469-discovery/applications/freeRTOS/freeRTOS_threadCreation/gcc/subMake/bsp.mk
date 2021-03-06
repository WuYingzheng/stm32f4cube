BSP_INC_DIR= -I$(STM32_SDK_DIR)/Drivers/BSP/STM32469I-Discovery/            # bsp

BSP_SOURCES=$(STM32_SDK_DIR)/Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_ts.c\
		$(STM32_SDK_DIR)/Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_sdram.c\
		$(STM32_SDK_DIR)/Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_sd.c\
		$(STM32_SDK_DIR)/Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_qspi.c\
		$(STM32_SDK_DIR)/Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_lcd.c\
		$(STM32_SDK_DIR)/Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_eeprom.c\
		$(STM32_SDK_DIR)/Drivers/BSP/STM32469I-Discovery/stm32469i_discovery.c\
		$(STM32_SDK_DIR)/Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_audio.c

BSP_COMPONENTS_INC= -I$(STM32_SDK_DIR)/Drivers/BSP/Components/cs43l22\
					-I$(STM32_SDK_DIR)/Drivers/BSP/Components/ft6x06\
					-I$(STM32_SDK_DIR)/Drivers/BSP/Components/otm8009a

BSP_COMPONENTS_SRC= $(STM32_SDK_DIR)/Drivers/BSP/Components/cs43l22/cs43l22.c\
					$(STM32_SDK_DIR)/Drivers/BSP/Components/ft6x06/ft6x06.c\
					$(STM32_SDK_DIR)/Drivers/BSP/Components/otm8009a/otm8009a.c