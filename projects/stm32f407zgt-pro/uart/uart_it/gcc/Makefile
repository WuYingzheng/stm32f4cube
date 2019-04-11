STM32_SDK_DIR=../../../../..
#　这个变量用来指定单片机芯片的型号，编译时传递给底层的hal文件
DEVICE=STM32F407xx
#　开发板的名称
BOARD=stm32f407zgt-pro
# BOARD=STM32469I-Discovery

BINDIR=bin
INCDIR=inc 
SRCDIR=boot ../src   # 注意不要将子目录添加到变量中

CC=arm-none-eabi-gcc
CXX=arm-none-eabi-g++
LD=arm-none-eabi-ld
AR=arm-none-eabi-ar
AS=arm-none-eabi-as
CP=arm-none-eabi-objcopy
OD=arm-none-eabi-objdump
NM=arm-none-eabi-nm
SIZE=arm-none-eabi-size
A2L=arm-none-eabi-addr2line

# Find source files
ASOURCES=$(shell find -L $(SRCDIR) -name '*.s')      #这个命令会递归的向下查找所有 .s .c .cpp文件，因此SRCDIR不要包含子目录
CSOURCES=$(shell find -L $(SRCDIR) -name '*.c')
CXXSOURCES=$(shell find -L $(SRCDIR) -name '*.cpp')
# Find header directories
INC=$(shell find -L $(INCDIR) -name '*.h' -exec dirname {} \; | uniq)    # 这个命令非常智能，只要添加根目录，可以找出所有包含.h的目录
INCLUDES=$(INC:%=-I%)

INCLUDES+= -I../inc/
INCLUDES+= -I$(STM32_SDK_DIR)/Drivers/CMSIS/Core/Include/                 # 内核以及内核外设相关的头文件
INCLUDES+= -I$(STM32_SDK_DIR)/Drivers/CMSIS/Device/ST/STM32F4xx/Include/  # 设备底层寄存器访问接口
INCLUDES+= -I$(STM32_SDK_DIR)/Middlewares/ST/STM32_Audio/Addons/PDM/Inc   # 和MP3音频有关

#------------------------------- BSP -------------------------------
include $(STM32_SDK_DIR)/Drivers/BSP/$(BOARD)/bsp.mk
INCLUDES+=$(BSP_INC) $(BSP_COMPONENTS_INC)
CSOURCES+=$(BSP_SOURCES) $(BSP_COMPONENTS_SRC)

#------------------------------- HAL -------------------------------
include $(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal.mk
INCLUDES+=$(HAL_INC)
CSOURCES+=$(HAL_SOURCES)

################################## ADD YOUR CONPONENTS HERE ###########################
#FreeRTOS_PATH=$(STM32_SDK_DIR)/Middlewares/Third_Party/FreeRTOS/Source
#include $(FreeRTOS_PATH)/Makefile
#INCLUDES+=$(FreeRTOS_INC)
#CSOURCES+=$(FreeRTOS_SRC)

#include $(STM32_SDK_DIR)/Middlewares/Third_Party/FatFs/FatFS.mk
#INCLUDES+=$(FatFS_INC)
#CSOURCES+=$(FatFS_SRC)

#######################################################################################
# Find libraries
INCLUDES_LIBS=-L$(STM32_SDK_DIR)/Middlewares/ST/STM32_Audio/Addons/PDM/Lib
LINK_LIBS=-lPDMFilter_CM4_GCC_wc32
# Create object list
OBJECTS=$(ASOURCES:%.s=%.o)
OBJECTS+=$(CSOURCES:%.c=%.o)
OBJECTS+=$(CXXSOURCES:%.cpp=%.o)
# Define output files ELF & IHEX
BINELF=outp.elf
BINHEX=outp.hex
BINARY=outp.bin

# MCU FLAGS
MCUFLAGS=-mcpu=cortex-m4 -mthumb -mlittle-endian \
-mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb-interwork

DEFS=-DUSE_STDPERIPH_DRIVER=" " -D$(DEVICE)=" "
CFLAGS=-c $(MCUFLAGS) $(INCLUDES) $(DEFS)  --specs=nano.specs
CXXFLAGS=-c $(MCUFLAGS) $(DEFS) $(INCLUDES) -std=c++11
# LINKER FLAGS
LDSCRIPT=$(BOARD).ld
LDFLAGS =-T $(LDSCRIPT) $(MCUFLAGS) --specs=nosys.specs --specs=nano.specs $(INCLUDES_LIBS) $(LINK_LIBS)

###
# Build Rules
.PHONY: all release release-memopt debug clean

debug: CFLAGS+=-g
debug: CXXFLAGS+=-g
debug: LDFLAGS+=-g
debug: release

all: release-memopt

release-memopt-blame: CFLAGS+=-g
release-memopt-blame: CXXFLAGS+=-g
release-memopt-blame: LDFLAGS+=-g -Wl,-Map=$(BINDIR)/output.map
release-memopt-blame: release-memopt
release-memopt-blame:
	@echo "Top 10 space consuming symbols from the object code ...\n"
	$(NM) -A -l -C -td --reverse-sort --size-sort $(BINDIR)/$(BINELF) | head -n10 | cat -n # Output legend: man nm
	@echo "\n... and corresponging source files to blame.\n"
	$(NM) --reverse-sort --size-sort -S -tx $(BINDIR)/$(BINELF) | head -10 | cut -d':' -f2 | cut -d' ' -f1 | $(A2L) -e $(BINDIR)/$(BINELF) | cat -n # Output legend: man addr2line

release-memopt: DEFS+=-DCUSTOM_NEW -DNO_EXCEPTIONS
release-memopt: CFLAGS+=-Os -ffunction-sections -fdata-sections -fno-builtin # -flto
release-memopt: CXXFLAGS+=-Os -fno-exceptions -ffunction-sections -fdata-sections -fno-builtin -fno-rtti # -flto
#fno-buildin 不使用内联函数
release-memopt: LDFLAGS+=-Os -Wl,-gc-sections --specs=nano.specs # -flto
release-memopt: release

release: $(BINDIR)/$(BINHEX) $(BINDIR)/$(BINARY)

$(BINDIR)/$(BINHEX): $(BINDIR)/$(BINELF)
	$(CP) -O ihex $< $@
	@echo "Objcopy from ELF to IHEX complete!\n"

$(BINDIR)/$(BINARY):$(BINDIR)/$(BINELF)
	$(CP) -S -O binary $< $@
	@echo "Objcopy from ELF to BIN complete!\n"
##
# C++ linking is used.
#
# Change
#   $(CXX) $(OBJECTS) $(LDFLAGS) -o $@ to 
#   $(CC) $(OBJECTS) $(LDFLAGS) -o $@ if
#   C linker is required.
$(BINDIR)/$(BINELF): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@
	@echo "Linking complete!\n"
	$(SIZE) $(BINDIR)/$(BINELF)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
	@echo "Compiled "$<"!\n"

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@
	@echo "Compiled "$<"!\n"

%.o: %.s
	$(CC) $(CFLAGS) $< -o $@
	@echo "Assambled "$<"!\n"

clean:
	rm -f $(OBJECTS) $(BINDIR)/$(BINELF) $(BINDIR)/$(BINHEX) $(BINDIR)/output.map

j-flash:debug
	openocd  -f $(STM32_SDK_DIR)/scripts/openocd/$(BOARD).cfg\
	 -c init \
	 -c targets \
	 -c "halt" \
	 -c "flash write_image erase bin/$(BINELF)" \
	 -c "verify_image bin/outp.elf" \
	 -c "reset run" \
	 -c shutdown

st-flash: release
	openocd -f  board/stm32f429discovery.cfg\
    -c "init" \
    -c "reset init" \
    -c "flash probe 0"\
    -c "flash info 0"\
    -c "program bin/"$(BINELF)" verify reset" \
    -c "reset run"\
    -c "shutdown"