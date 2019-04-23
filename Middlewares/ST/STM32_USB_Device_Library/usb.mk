USB_INC = -I$(STM32_SDK_DIR)/Middlewares/ST/STM32_USB_Device_Library/Core/Inc\
			-I$(STM32_SDK_DIR)/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc

USBCORE_SRC = $(STM32_SDK_DIR)/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c\
			  $(STM32_SDK_DIR)/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c\
			  $(STM32_SDK_DIR)/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c

USBMSC_SRC = $(STM32_SDK_DIR)/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Src/usbd_msc_bot.c\
			 $(STM32_SDK_DIR)/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Src/usbd_msc_data.c\
			 $(STM32_SDK_DIR)/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Src/usbd_msc_scsi.c\
			 $(STM32_SDK_DIR)/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Src/usbd_msc.c

USB_SRC = $(USBCORE_SRC) $(USBMSC_SRC)