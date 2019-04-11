# FreeRTOS Makefile
FreeRTOS_INC= -I$(STM32_SDK_DIR)/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS            # RTOS
FreeRTOS_INC+= -I$(STM32_SDK_DIR)/Middlewares/Third_Party/FreeRTOS/Source/include
FreeRTOS_INC+= -I$(STM32_SDK_DIR)/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F

FreeRTOS_SRC=   $(STM32_SDK_DIR)/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c\
			$(STM32_SDK_DIR)/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c\
			$(STM32_SDK_DIR)/Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c\
			$(STM32_SDK_DIR)/Middlewares/Third_Party/FreeRTOS/Source/croutine.c\
			$(STM32_SDK_DIR)/Middlewares/Third_Party/FreeRTOS/Source/event_groups.c\
			$(STM32_SDK_DIR)/Middlewares/Third_Party/FreeRTOS/Source/list.c\
			$(STM32_SDK_DIR)/Middlewares/Third_Party/FreeRTOS/Source/queue.c\
			$(STM32_SDK_DIR)/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c\
			$(STM32_SDK_DIR)/Middlewares/Third_Party/FreeRTOS/Source/tasks.c\
			$(STM32_SDK_DIR)/Middlewares/Third_Party/FreeRTOS/Source/timers.c
			#$(STM32_SDK_DIR)/Middlewares/Third_Party/FreeRTOS/Source/portable/Common/mpu_wrappers.c\

