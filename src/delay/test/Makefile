# David A. Aguirre M. - daguirre.m@outlook.com
# BASED on Cortex-Builder MAKEFILE (https://github.com/7bnx/Cortex-Builder)
# NOTE:
# Tested on Windows 10/11

#MIT License
#Copyright (c) 2020 Semyon Ivanov - 2022 David A. Aguirre M.

#Permission is hereby granted, free of charge, to any person obtaining a copy
#of this software and associated documentation files (the "Software"), to deal
#in the Software without restriction, including without limitation the rights
#to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#copies of the Software, and to permit persons to whom the Software is
#furnished to do so, subject to the following conditions:

#The above copyright notice and this permission notice shall be included in all
#copies or substantial portions of the Software.

#THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#SOFTWARE.
#Make

ifneq ($(XPACK),)
	ECHO = "${XPACK}/echo.exe"
	MKDIR = "${XPACK}/mkdir.exe"
	COPY = "${XPACK}/cp.exe"
	POSTFIX = .exe
else
	ECHO = echo
	MKDIR = mkdir
	COPY = cp
	POSTFIX =
endif

ifeq ($(PROGRAMMER),bmp)
	PROGRAMMER_COMMAND = $(BMP_COMMAND)
	PROGRAMMER_ARGS = -wV $(OUTPUT_PATH)/$(PRJ_NAME).bin -a $(FLASHSTART)
else
	PROGRAMMER_COMMAND = $(ST_COMMAND)
	PROGRAMMER_ARGS = -f interface/stlink.cfg -f target/stm32f4x.cfg \
		-c 'program $(OUTPUT_PATH)/$(PRJ_NAME).elf verify reset exit'
endif

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))

# Necesary options
PRJ_NAME = $(TARGET)
FPU_HARDWARE = yes
HSE_VALUE = 8000000UL
FLASHSTART = 0x08000000
TOOLCHAIN =
TOOLCHAIN_VERSION =
CMSIS_PATH = 
LIB_PATH = build/lib/$(TARGET)

# MCU Defines
CORE = cortex-m4
INCLUDEDEFINE = \
	STM32F407xx \
	STM32F4xx \
	HSE_VALUE=$(HSE_VALUE)

# Folders
BUILD_PATH = build/$(TARGET)
OUTPUT_PATH = output/$(TARGET)
INCLUDE_PATH = \
	./include \
	$(CMSIS_PATH)/Include \
	$(CMSIS_PATH)/Device/ST/STM32F4xx/Include 

SOURCE_PATH = \
	src

OBJECT_PATH = build/$(TARGET)/src

# Libraries
LIBS_INCLUDE = \
	gpio \
	rcc \
	flash \
	delay

LIBS = $(foreach lib, $(LIBS_INCLUDE),-l$(lib))
LIBS_BUILDED = $(foreach lib, $(LIBS_INCLUDE),$(LIB_PATH)/lib$(lib).a)
LIBS_INC_DIR = $(foreach lib, $(LIBS_INCLUDE),include/$(lib).h)

# Settings
CPPSTANDARD = gnu++17
CSTANDARD = gnu11

ifeq ($(TARGET),Debug)
	INCLUDEDEFINE += DEBUG
	DEBUG          = -ggdb3
	OPT_FLAG       = -Og
else
	INCLUDEDEFINE += _NDEBUG
	DEBUG          = -ggdb2
	OPT_FLAG       = $(OPTIMIZATION)
endif

# Compiler
PREFIX = $(TOOLCHAIN)/bin/arm-none-eabi-
CC = "$(PREFIX)gcc$(POSTFIX)"
CXX = "$(PREFIX)g++$(POSTFIX)"
AS = "$(PREFIX)gcc$(POSTFIX)" -x assembler-with-cpp
CP = "$(PREFIX)objcopy$(POSTFIX)"
SZ = "$(PREFIX)size$(POSTFIX)"
OBJDUMP = "$(PREFIX)objdump$(POSTFIX)"
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

# Defines
ASM_DEFINES = 
CANDCPP_DEFINES = $(foreach definition, $(INCLUDEDEFINE),-D$(definition))

# MCU Flags
CPU = -mcpu=$(CORE)
FPU = -mfpu=fpv4-sp-d16
ifeq ($(FPU_HARDWARE),yes)
	FLOATABI = -mfloat-abi=hard
	CANDCPP_DEFINES += -D__VFP_FP__=1 -U__SOFTFP__
else
	FLOATABI = -mfloat-abi=soft
	CANDCPP_DEFINES += -D__SOFTFP__=1 -U__VFP_FP__
endif
MCU = $(CPU) -mthumb $(FPU) $(FLOATABI)

ASM_INCLUDES =
CANDCPP_INCLUDES += -I./system
CANDCPP_INCLUDES += $(foreach include, $(INCLUDE_PATH),-I"$(include)")

ASM_SOURCE = $(wildcard ./system/startup_*.s)
C_SOURCE = $(wildcard ./system/system_*.c)
C_SOURCE += $(wildcard $(SOURCE_PATH)/*.c)
CPP_SOURCE = $(wildcard $(SOURCE_PATH)/*.cpp)

# Linker
LDSCRIPT = ld/linker.ld
LIBS += -lc -lm -lnosys
LIBDIR = -L"$(LIB_PATH)"
LDFLAGS = $(MCU) -specs=nano.specs -specs=nosys.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS)\
-Wl,-Map=$(BUILD_PATH)/$(PRJ_NAME).map,--cref -Wl,--gc-sections

# Source flags
ASMFLAGS = $(MCU) $(ASM_DEFINES) $(ASM_INCLUDES) $(OPT_FLAG)\
\
-Wall -fdata-sections -ffunction-sections
CFLAGS = $(MCU) $(CANDCPP_DEFINES) $(CANDCPP_INCLUDES) $(OPT_FLAG) -std=$(CSTANDARD)\
\
-Wall -fdata-sections -ffunction-sections $(DEBUG)
CPPFLAGS = $(MCU) $(CANDCPP_DEFINES) $(CANDCPP_INCLUDES) $(OPT_FLAG) -std=$(CPPSTANDARD)\
\
-Wall -fdata-sections -ffunction-sections -fno-exceptions $(DEBUG)

# Obeject list
OBJECTS = $(addprefix $(BUILD_PATH)/,$(notdir $(C_SOURCE:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCE)))
OBJECTS += $(addprefix $(BUILD_PATH)/,$(notdir $(CPP_SOURCE:.cpp=.o)))
vpath %.cpp $(sort $(dir $(CPP_SOURCE)))
OBJECTS += $(addprefix $(BUILD_PATH)/,$(notdir $(ASM_SOURCE:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCE)))
DEPS := $(OBJECTS:.o=.d)
-include $(DEPS)

ASMOUTPUTFILE = $(OBJDUMP) -DSG -t -marm -w --start-address=$(FLASHSTART) --show-raw-insn \
--visualize-jumps --inlines $(OUTPUT_PATH)/$(PRJ_NAME).elf \
-Mforce-thumb -Mreg-names-std > $(OUTPUT_PATH)/$(PRJ_NAME).s

# Build
$(BUILD_PATH)/%.o: %.c Makefile | $(BUILD_PATH)
	@${ECHO} -e "\033[1;34m["$<"] Compiling\033[0m"
	@$(CC) $(CFLAGS) -MMD -MP -Wa,-a,-ad,-alms=$(BUILD_PATH)/$(notdir $(<:.c=.lst)) -c "$<" -o "$@"

$(BUILD_PATH)/%.o: %.cpp Makefile | $(BUILD_PATH)
	@${ECHO} -e "\033[1;34m["$<"] Compiling\033[0m"
	@$(CXX) $(CPPFLAGS) -MMD -MP -Wa,-a,-ad,-alms=$(BUILD_PATH)/$(notdir $(<:.cpp=.lst)) -c "$<" -o "$@"

$(BUILD_PATH)/%.o: %.s Makefile | $(BUILD_PATH)
	@${ECHO} -e "\033[1;34m["$<"] Compiling\033[0m\r\n"
	@$(AS) -c $(ASMFLAGS) "$<" -o "$@"

$(OUTPUT_PATH)/$(PRJ_NAME).elf: $(OBJECTS) Makefile | $(OUTPUT_PATH)
	@${ECHO} -e "\033[1;34mGenerating .elf file \033[0m"
	@$(CC) $(OBJECTS) $(LDFLAGS) -o "$@"
	@${ECHO} -e "\033[1;34mGenerating .lst file \033[0m"
	@$(OBJDUMP) -h -S "$(OUTPUT_PATH)/$(PRJ_NAME).elf" > "$(OUTPUT_PATH)/$(PRJ_NAME).lst"
	@${ECHO} -e "\033[1;32mELF generation done \033[0m\r\n"

$(OUTPUT_PATH)/%.hex: $(OUTPUT_PATH)/%.elf | $(OUTPUT_PATH)
	@${ECHO} -e "\033[1;34mGenerating .hex file\033[0m"
	@$(HEX) "$<" "$@"

$(OUTPUT_PATH)/%.bin: $(OUTPUT_PATH)/%.elf | $(OUTPUT_PATH)
	@${ECHO} -e "\033[1;34mGenerating .bin file\033[0m"
	@$(BIN) "$<" "$@"
	@$(ASMOUTPUTFILE)

$(BUILD_PATH):
	@${MKDIR} -p "$@"

$(OUTPUT_PATH):
	@${MKDIR} -p "$@"

$(LIB_PATH)/%.a: $(LIBS_INC_DIR) Makefile | $(BUILD_PATH)
	@${MAKE} -C '$(EXT_LIB_PATH)/$(patsubst $(LIB_PATH)/lib%.a,'%',$@)/lib' \
	export \
	"EXPORT_PATH=$(mkfile_dir)" \
	"FPU_HARDWARE=$(FPU_HARDWARE)" \
	"OPT_FLAG=$(OPT_FLAG)" \
	"CORE=$(CORE)" \
	"INCLUDEDEFINE=$(INCLUDEDEFINE)" \
	"CPPSTANDARD=$(CPPSTANDARD)" \
	"CSTANDARD=$(CSTANDARD)" \
	"CPU=$(CPU)" \
	"FPU=$(FPU)" \
	"MCU=$(MCU)" \
	"FLOATABI=$(FLOATABI)"

include/%.h:
	@${MAKE} -C '$(EXT_LIB_PATH)/$(patsubst include/%.h,'%',$@)/lib' \
	incl_exp \
	"EXPORT_PATH=$(mkfile_dir)"

# Actions
.PHONY: build clean program incl_imp

build: $(LIBS_BUILDED) $(OUTPUT_PATH)/$(PRJ_NAME).bin $(OUTPUT_PATH)/$(PRJ_NAME).hex
	@${ECHO} -e "\033[1;32mBuild done\r\n\033[1;33m"

clean:
	@${ECHO} -e "\r\nCleaning current project"
	@rm -rf ./output/
	@rm -rf ./build/
	@${ECHO} -e "\033[1;31mProject cleaned\033[0m\r\n"

program: build
	@$(PROGRAMMER_COMMAND) $(PROGRAMMER_ARGS)

incl_imp: $(LIBS_INC_DIR)