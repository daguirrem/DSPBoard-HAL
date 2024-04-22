mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))

EXAMPLES := \
/home/david/MEGA/embedded/stm/hal_sdk/sdk/lib/hal/examples/basic/gpio/button_read/ \
/home/david/MEGA/embedded/stm/hal_sdk/sdk/lib/hal/examples/basic/gpio/led_blink/ \
/home/david/MEGA/embedded/stm/hal_sdk/sdk/lib/hal/examples/basic/i2s/adc_to_uda1334a/ \
/home/david/MEGA/embedded/stm/hal_sdk/sdk/lib/hal/examples/basic/spi/external_flash/ \
/home/david/MEGA/embedded/stm/hal_sdk/sdk/lib/hal/examples/board/default/ \
/home/david/MEGA/embedded/stm/hal_sdk/sdk/lib/hal/examples/dsp/effects/delay/ \
/home/david/MEGA/embedded/stm/hal_sdk/sdk/lib/hal/examples/dsp/effects/eco/ \
/home/david/MEGA/embedded/stm/hal_sdk/sdk/lib/hal/examples/dsp/filters/fir/ 

SDK = $(abspath $(mkfile_dir)../../../)
CMSIS_PATH=$(SDK)/packs/STM32CubeF4/Drivers/CMSIS
TOOLCHAIN=$(SDK)/gcc
OPTIMIZATION=-O2
EXT_LIB_PATH=$(SDK)/lib/hal/src
EXT_LIB_INCLUDE=$(SDK)/lib/hal/include
TARGET=Release
HSE_VALUE=8000000UL
FPU_HARDWARE=yes

.PHONY: build sdk

examples:
	@$(foreach example, \
		$(EXAMPLES), \
		echo $(example); \
	)

build: 
	@$(foreach example, \
		$(EXAMPLES), \
		echo $(example) && \
		make -s -C $(example) \
		build \
		"SDK=$(SDK)" \
		"PRJ_NAME"=$(shell basename $(example)) \
		"CMSIS_PATH=$(CMSIS_PATH)" \
		"TOOLCHAIN=$(TOOLCHAIN)" \
		"OPTIMIZATION=$(OPTIMIZATION)" \
		"EXT_LIB_PATH=$(EXT_LIB_PATH)" \
		"EXT_LIB_INCLUDE=$(EXT_LIB_INCLUDE)" \
		"TARGET=$(TARGET)" \
		"HSE_VALUE=$(HSE_VALUE)" \
		"FPU_HARDWARE=$(FPU_HARDWARE)" >> /dev/null;\
		)

clean: 
	@$(foreach example, \
		$(EXAMPLES), \
		make -s -C $(example) \
		clean \
		"SDK=$(SDK)" \
		"PRJ_NAME"=$(shell basename $(example)) \
		"CMSIS_PATH=$(CMSIS_PATH)" \
		"TOOLCHAIN=$(TOOLCHAIN)" \
		"OPTIMIZATION=$(OPTIMIZATION)" \
		"EXT_LIB_PATH=$(EXT_LIB_PATH)" \
		"EXT_LIB_INCLUDE=$(EXT_LIB_INCLUDE)" \
		"TARGET=$(TARGET)" \
		"HSE_VALUE=$(HSE_VALUE)" \
		"FPU_HARDWARE=$(FPU_HARDWARE)";\
		)