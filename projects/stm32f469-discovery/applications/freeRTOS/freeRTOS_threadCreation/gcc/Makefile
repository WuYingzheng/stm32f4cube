# STM32_SDK_DIR?=""
STM32_SDK_DIR?=../../../../../..
#　这个变量用来指定单片机的型号，编译时传递给底层的hal文件
DEVICE=STM32F469xx

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

######################## 1.注意不要将子目录添加到变量中 
######################## 2.不要将第三方库目录添加在这里
BINDIR=bin
INCDIR=inc 
SRCDIR=boot ../src

# Find source files
ASOURCES=$(shell find -L $(SRCDIR) -name '*.s')      #这个命令会递归的向下查找所有 .s .c .cpp文件，因此SRCDIR不要包含子目录
CSOURCES=$(shell find -L $(SRCDIR) -name '*.c')
CXXSOURCES=$(shell find -L $(SRCDIR) -name '*.cpp')
# Find header directories
INC=$(shell find -L $(INCDIR) -name '*.h' -exec dirname {} \; | uniq)    # 这个命令非常智能，只要添加根目录，可以找出所有包含.h的目录
INCLUDES=$(INC:%=-I%)

INCLUDES+= -I../Inc/
INCLUDES+= -I$(STM32_SDK_DIR)/Drivers/CMSIS/Core/Include/                 # 内核以及内核外设相关的头文件
INCLUDES+= -I$(STM32_SDK_DIR)/Drivers/CMSIS/Device/ST/STM32F4xx/Include/  # 设备底层寄存器访问接口 
INCLUDES+= -I$(STM32_SDK_DIR)/Middlewares/ST/STM32_Audio/Addons/PDM/Inc   # 和MP3音频有关

# 包含 bsp 头文件和源文件支持
include $(STM32_SDK_DIR)/Drivers/BSP/stm32f469-discovery/bsp.mk
# 由于shell运行顺序的问题，下面这条语句可能回到最后才复制，可能造成后续的flag错位
#CSOURCES+=$(shell find -L $(BSP_COMPONENTS_DIR) -name '*.c')

# 如果编译时显示Hal库中的变量未定义，请在stm32fxx_hal_conf.h中进行配置
include $(STM32_SDK_DIR)/Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal.mk


################################## ADD YOUR CONPONENTS HERE ###############################
include $(STM32_SDK_DIR)/Middlewares/Third_Party/FreeRTOS/FreeRTOS.mk
INCLUDES+=$(FreeRTOS_INC)
CSOURCES+=$(FreeRTOS_SRC)

########################### Find libraries ##################################
INCLUDES_LIBS=-L$(STM32_SDK_DIR)/Middlewares/ST/STM32_Audio/Addons/PDM/Lib
LINK_LIBS=-lPDMFilter_CM4_GCC_wc32
# Create object list
OBJECTS=$(ASOURCES:%.s=%.o)
OBJECTS+=$(CSOURCES:%.c=%.o)
OBJECTS+=$(CXXSOURCES:%.cpp=%.o)
# Define output files ELF & IHEX
BINELF=outp.elf
BINHEX=outp.hex

# MCU FLAGS
MCUFLAGS=-mcpu=cortex-m4 -mthumb -mlittle-endian \
-mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb-interwork

# 定义宏参数
DEFS=-DUSE_STDPERIPH_DRIVER=" "
# ！！！选项的顺序有很大的关系，不能随便改改
CFLAGS=-c $(MCUFLAGS)  $(INCLUDES) -D$(DEVICE)=" " $(DEFS)
CXXFLAGS=-c $(MCUFLAGS) $(DEFS) $(INCLUDES) -std=c++11
# LINKER FLAGS
LDSCRIPT=STM32F469NIHx_FLASH.ld
LDFLAGS =-T $(LDSCRIPT) $(MCUFLAGS) --specs=nosys.specs $(INCLUDES_LIBS) $(LINK_LIBS)

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

release: $(BINDIR)/$(BINHEX)

$(BINDIR)/$(BINHEX): $(BINDIR)/$(BINELF)
	$(CP) -O ihex $< $@
	@echo "Objcopy from ELF to IHEX complete!\n"

##
# C++ linking is used.
#
# Change
#   $(CXX) $(OBJECTS) $(LDFLAGS) -o $@ to 
#   $(CC) $(OBJECTS) $(LDFLAGS) -o $@ if
#   C linker is required.
$(BINDIR)/$(BINELF): $(OBJECTS)
	@mkdir -p $(BINDIR)
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

check:
ifeq ($(STM32_SDK_DIR),"")#　注意echo后面留一个空格
	@echo "NOTE:: STM32_SDK_DIR was not set, please source the environment first!"
else 
	@echo " Building FreeRTOS library..."
endif

clean:
	rm -f $(OBJECTS) $(BINDIR)/$(BINELF) $(BINDIR)/$(BINHEX) $(BINDIR)/output.map

flash:
	openocd -f  board/stm32f429discovery.cfg\
    -c "init" \
    -c "reset init" \
    -c "flash probe 0"\
    -c "flash info 0"\
    -c "program bin/"$(BINELF)" verify reset" \
    -c "reset run"\
    -c "shutdown"

