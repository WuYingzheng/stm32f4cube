# FatFS Makefile
FatFS_INC = -I$(STM32_SDK_DIR)/Middlewares/Third_Party/FatFs/src
FatFS_INC+= -I$(STM32_SDK_DIR)/Middlewares/Third_Party/FatFs/src/drivers

FatFS_SRC=  $(STM32_SDK_DIR)/Middlewares/Third_Party/FatFs/src/diskio.c\
			$(STM32_SDK_DIR)/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c\
			$(STM32_SDK_DIR)/Middlewares/Third_Party/FatFs/src/ff.c

