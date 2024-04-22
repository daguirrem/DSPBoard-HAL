#User extra custom definitions / include_paths / Libs to include

INCLUDEDEFINE += \
	FIR_OPTIMICED=1 \
	DSP_EFFECT_DELAY_SIZE=1 \

INCLUDE_PATH +=

LIB_SDK += \
	rcc \
	gpio \
	adc \
	flash \
	delay \
	dsp \
	utils

LIBS +=

LIBDIR +=