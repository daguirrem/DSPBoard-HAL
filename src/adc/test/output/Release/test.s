
output/Release/test.elf:     file format elf32-littlearm

SYMBOL TABLE:
08000000 l    d  .isr_vector	00000000 .isr_vector
080001a8 l    d  .text	00000000 .text
080005a8 l    d  .rodata	00000000 .rodata
080005c0 l    d  .ARM.extab	00000000 .ARM.extab
080005c0 l    d  .ARM	00000000 .ARM
080005c0 l    d  .preinit_array	00000000 .preinit_array
080005c0 l    d  .init_array	00000000 .init_array
080005d4 l    d  .fini_array	00000000 .fini_array
20000000 l    d  .data	00000000 .data
20000004 l    d  .bss	00000000 .bss
2000009c l    d  ._user_heap_stack	00000000 ._user_heap_stack
10000000 l    d  .ccmdata	00000000 .ccmdata
10000000 l    d  .ccmbss	00000000 .ccmbss
40024000 l    d  .bram	00000000 .bram
00000000 l    d  .ARM.attributes	00000000 .ARM.attributes
00000000 l    d  .debug_info	00000000 .debug_info
00000000 l    d  .debug_abbrev	00000000 .debug_abbrev
00000000 l    d  .debug_loc	00000000 .debug_loc
00000000 l    d  .debug_aranges	00000000 .debug_aranges
00000000 l    d  .debug_ranges	00000000 .debug_ranges
00000000 l    d  .debug_line	00000000 .debug_line
00000000 l    d  .debug_str	00000000 .debug_str
00000000 l    d  .comment	00000000 .comment
00000000 l    d  .debug_frame	00000000 .debug_frame
00000000 l    df *ABS*	00000000 startup_stm32f407xx.o
08000348 l       .text	00000000 LoopCopyDataInit
08000342 l       .text	00000000 CopyDataInit
0800035a l       .text	00000000 LoopFillZerobss
08000356 l       .text	00000000 FillZerobss
0800036e l       .text	00000000 LoopCopyCCMDataInit
08000368 l       .text	00000000 CopyCCMDataInit
08000380 l       .text	00000000 LoopFillZeroCCMbss
0800037c l       .text	00000000 FillZeroCCMbss
0800038c l       .text	00000000 LoopForever
080003bc l       .text	00000000 Infinite_Loop
00000000 l    df *ABS*	00000000 crtstuff.c
08000590 l     O .text	00000000 __EH_FRAME_BEGIN__
080001a8 l     F .text	00000000 __do_global_dtors_aux
20000004 l       .bss	00000001 completed.1
080005d4 l     O .fini_array	00000000 __do_global_dtors_aux_fini_array_entry
080001cc l     F .text	00000000 frame_dummy
20000008 l       .bss	00000018 object.0
080005c0 l     O .init_array	00000000 __frame_dummy_init_array_entry
00000000 l    df *ABS*	00000000 system_stm32f4xx.c
00000000 l    df *ABS*	00000000 main.c
0800026c l     F .text	0000000e sys_clk_update
00000000 l    df *ABS*	00000000 gpio.c
080003c0 l     F .text	0000000e sys_clk_update
00000000 l    df *ABS*	00000000 adc.c
08000400 l     F .text	0000000e sys_clk_update
00000000 l    df *ABS*	00000000 delay.c
080004e4 l     F .text	0000000e sys_clk_update
20000094 l     O .bss	00000004 DELAY_CYCLES_MS
00000000 l    df *ABS*	00000000 init.c
00000000 l    df *ABS*	00000000 crti.o
00000000 l    df *ABS*	00000000 crtn.o
00000000 l    df *ABS*	00000000 
080005d4 l       .init_array	00000000 __init_array_end
080005c0 l       .preinit_array	00000000 __preinit_array_end
080005c0 l       .init_array	00000000 __init_array_start
080005c0 l       .preinit_array	00000000 __preinit_array_start
080003bc  w    F .text	00000002 RTC_Alarm_IRQHandler
080003bc  w    F .text	00000002 HASH_RNG_IRQHandler
080003bc  w    F .text	00000002 EXTI2_IRQHandler
080003bc  w    F .text	00000002 TIM8_CC_IRQHandler
080003bc  w    F .text	00000002 DebugMon_Handler
10000000 g       .ccmbss	00000000 _eccmbss
080003bc  w    F .text	00000002 TIM1_CC_IRQHandler
080005b8 g     O .rodata	00000008 resbits_decode
080003bc  w    F .text	00000002 DMA2_Stream5_IRQHandler
080003bc  w    F .text	00000002 HardFault_Handler
080003bc  w    F .text	00000002 DMA1_Stream5_IRQHandler
00000400 g       *ABS*	00000000 _Min_Stack_Size
080003bc  w    F .text	00000002 SysTick_Handler
080003bc  w    F .text	00000002 PVD_IRQHandler
080003bc  w    F .text	00000002 SDIO_IRQHandler
080003bc  w    F .text	00000002 TAMP_STAMP_IRQHandler
080005d8 g       *ABS*	00000000 _sidata
080003bc  w    F .text	00000002 PendSV_Handler
080003bc  w    F .text	00000002 NMI_Handler
080005c0 g       .ARM	00000000 __exidx_end
080003bc  w    F .text	00000002 CAN2_RX1_IRQHandler
080003bc  w    F .text	00000002 EXTI3_IRQHandler
080003bc  w    F .text	00000002 TIM8_TRG_COM_TIM14_IRQHandler
080003bc  w    F .text	00000002 TIM1_UP_TIM10_IRQHandler
080005a8 g       .text	00000000 _etext
20000004 g       .bss	00000000 _sbss
080003bc  w    F .text	00000002 TIM8_UP_TIM13_IRQHandler
080003bc  w    F .text	00000002 I2C3_ER_IRQHandler
080003bc  w    F .text	00000002 LCD_TFT_IRQHandler
080003bc  w    F .text	00000002 EXTI0_IRQHandler
080003bc  w    F .text	00000002 I2C2_EV_IRQHandler
080003bc  w    F .text	00000002 DMA1_Stream2_IRQHandler
080003bc  w    F .text	00000002 CAN1_RX0_IRQHandler
080003bc  w    F .text	00000002 FPU_IRQHandler
20000000 g     O .data	00000004 SystemCoreClock
080003bc  w    F .text	00000002 OTG_HS_WKUP_IRQHandler
080003bc  w    F .text	00000002 UsageFault_Handler
080003bc  w    F .text	00000002 CAN2_SCE_IRQHandler
080003bc  w    F .text	00000002 DMA2_Stream2_IRQHandler
20000004 g       .bss	00000000 __bss_start__
080003d0 g     F .text	00000030 gpio_config_mode
20000000 g       .data	00000000 _sdata
080003bc  w    F .text	00000002 SPI1_IRQHandler
080003bc  w    F .text	00000002 TIM6_DAC_IRQHandler
080003bc  w    F .text	00000002 TIM1_BRK_TIM9_IRQHandler
080003bc  w    F .text	00000002 DCMI_IRQHandler
080003bc  w    F .text	00000002 CAN2_RX0_IRQHandler
10000000 g       .ccmdata	00000000 _sccmdata
080005c0 g       .ARM	00000000 __exidx_start
080003bc  w    F .text	00000002 DMA2_Stream3_IRQHandler
08000548 g     F .text	00000048 __libc_init_array
40024000 g       .bram	00000000 _sbram
10000000 g       .ccmbss	00000000 _sccmbss
080003bc  w    F .text	00000002 USART6_IRQHandler
08000590 g     F .text	00000000 _init
080003bc  w    F .text	00000002 USART3_IRQHandler
080003bc  w    F .text	00000002 CRYP_IRQHandler
2000009c g       .bss	00000000 _ebss
08000330  w    F .text	0000005e Reset_Handler
080003bc  w    F .text	00000002 CAN1_RX1_IRQHandler
080003bc  w    F .text	00000002 UART5_IRQHandler
080003bc  w    F .text	00000002 DMA2_Stream0_IRQHandler
080003bc  w    F .text	00000002 TIM4_IRQHandler
080003bc  w    F .text	00000002 I2C1_EV_IRQHandler
080003bc  w    F .text	00000002 DMA1_Stream6_IRQHandler
08000410 g     F .text	00000030 adc_config_ind_scan
080003bc  w    F .text	00000002 DMA1_Stream1_IRQHandler
080003bc  w    F .text	00000002 UART4_IRQHandler
2000009c g       .bss	00000000 __bss_end__
080003bc  w    F .text	00000002 LCD_TFT_1_IRQHandler
080003bc  w    F .text	00000002 TIM3_IRQHandler
080005dc g       *ABS*	00000000 _siccmdata
080003bc  w    F .text	00000002 RCC_IRQHandler
080003bc  w    F .text	00000002 TIM8_BRK_TIM12_IRQHandler
00000000 g       *ABS*	00000000 _Min_Heap_Size
080003bc g       .text	00000002 Default_Handler
080004f4 g     F .text	0000003c delay_init
080005a8 g     O .rodata	00000010 AHBPrescTable
080003bc  w    F .text	00000002 EXTI15_10_IRQHandler
080003bc  w    F .text	00000002 ADC_IRQHandler
080003bc  w    F .text	00000002 DMA1_Stream7_IRQHandler
080003bc  w    F .text	00000002 TIM7_IRQHandler
080003bc  w    F .text	00000002 CAN2_TX_IRQHandler
080003bc  w    F .text	00000002 TIM5_IRQHandler
08000440 g     F .text	00000068 adc_config_seq_rgl
080003bc  w    F .text	00000002 DMA2_Stream7_IRQHandler
080003bc  w    F .text	00000002 I2C3_EV_IRQHandler
20000098 g     O .bss	00000004 DELAY_CYCLES_US
080003bc  w    F .text	00000002 EXTI9_5_IRQHandler
080003bc  w    F .text	00000002 RTC_WKUP_IRQHandler
080003bc  w    F .text	00000002 ETH_WKUP_IRQHandler
080003bc  w    F .text	00000002 SPI2_IRQHandler
080004a8 g     F .text	0000003c adc_read_ind_scan
080003bc  w    F .text	00000002 OTG_HS_EP1_IN_IRQHandler
080003bc  w    F .text	00000002 MemManage_Handler
0800027c g     F .text	000000b4 main
08000530 g     F .text	00000018 delay_ms
080003bc  w    F .text	00000002 DMA1_Stream0_IRQHandler
080003bc  w    F .text	00000002 CAN1_TX_IRQHandler
080003bc  w    F .text	00000002 SVC_Handler
080003bc  w    F .text	00000002 EXTI4_IRQHandler
080001e8 g     F .text	00000014 SystemInit
0800059c g     F .text	00000000 _fini
080003bc  w    F .text	00000002 FSMC_IRQHandler
080003bc  w    F .text	00000002 ETH_IRQHandler
080003bc  w    F .text	00000002 OTG_HS_EP1_OUT_IRQHandler
080003bc  w    F .text	00000002 WWDG_IRQHandler
080003bc  w    F .text	00000002 TIM2_IRQHandler
080003bc  w    F .text	00000002 OTG_FS_WKUP_IRQHandler
080003bc  w    F .text	00000002 TIM1_TRG_COM_TIM11_IRQHandler
080003bc  w    F .text	00000002 OTG_HS_IRQHandler
20020000 g       .isr_vector	00000000 _estack
080003bc  w    F .text	00000002 EXTI1_IRQHandler
20000004 g       .data	00000000 _edata
080003bc  w    F .text	00000002 USART2_IRQHandler
08000000 g     O .isr_vector	00000000 g_pfnVectors
080001fc g     F .text	00000070 SystemCoreClockUpdate
080003bc  w    F .text	00000002 I2C2_ER_IRQHandler
080003bc  w    F .text	00000002 DMA2_Stream1_IRQHandler
080003bc  w    F .text	00000002 CAN1_SCE_IRQHandler
080003bc  w    F .text	00000002 DMA2_Stream4_IRQHandler
40024000 g       .bram	00000000 _ebram
080003bc  w    F .text	00000002 BusFault_Handler
080003bc  w    F .text	00000002 USART1_IRQHandler
080003bc  w    F .text	00000002 OTG_FS_IRQHandler
080003bc  w    F .text	00000002 SPI3_IRQHandler
080003bc  w    F .text	00000002 DMA1_Stream4_IRQHandler
080003bc  w    F .text	00000002 I2C1_ER_IRQHandler
20000020 g     O .bss	00000074 adc_sequencer_rgl
10000000 g       .ccmdata	00000000 _eccmdata
080003bc  w    F .text	00000002 DMA2_Stream6_IRQHandler
080003bc  w    F .text	00000002 DMA1_Stream3_IRQHandler



Disassembly of section .isr_vector:

08000000 <g_pfnVectors>:
 8000000:	0000      	movs	r0, r0
 8000002:	2002      	movs	r0, #2
 8000004:	0331      	lsls	r1, r6, #12
 8000006:	0800      	lsrs	r0, r0, #32
 8000008:	03bd      	lsls	r5, r7, #14
 800000a:	0800      	lsrs	r0, r0, #32
 800000c:	03bd      	lsls	r5, r7, #14
 800000e:	0800      	lsrs	r0, r0, #32
 8000010:	03bd      	lsls	r5, r7, #14
 8000012:	0800      	lsrs	r0, r0, #32
 8000014:	03bd      	lsls	r5, r7, #14
 8000016:	0800      	lsrs	r0, r0, #32
 8000018:	03bd      	lsls	r5, r7, #14
 800001a:	0800      	lsrs	r0, r0, #32
	...
 800002c:	03bd      	lsls	r5, r7, #14
 800002e:	0800      	lsrs	r0, r0, #32
 8000030:	03bd      	lsls	r5, r7, #14
 8000032:	0800      	lsrs	r0, r0, #32
 8000034:	0000      	movs	r0, r0
 8000036:	0000      	movs	r0, r0
 8000038:	03bd      	lsls	r5, r7, #14
 800003a:	0800      	lsrs	r0, r0, #32
 800003c:	03bd      	lsls	r5, r7, #14
 800003e:	0800      	lsrs	r0, r0, #32
 8000040:	03bd      	lsls	r5, r7, #14
 8000042:	0800      	lsrs	r0, r0, #32
 8000044:	03bd      	lsls	r5, r7, #14
 8000046:	0800      	lsrs	r0, r0, #32
 8000048:	03bd      	lsls	r5, r7, #14
 800004a:	0800      	lsrs	r0, r0, #32
 800004c:	03bd      	lsls	r5, r7, #14
 800004e:	0800      	lsrs	r0, r0, #32
 8000050:	0000      	movs	r0, r0
 8000052:	0000      	movs	r0, r0
 8000054:	03bd      	lsls	r5, r7, #14
 8000056:	0800      	lsrs	r0, r0, #32
 8000058:	03bd      	lsls	r5, r7, #14
 800005a:	0800      	lsrs	r0, r0, #32
 800005c:	03bd      	lsls	r5, r7, #14
 800005e:	0800      	lsrs	r0, r0, #32
 8000060:	03bd      	lsls	r5, r7, #14
 8000062:	0800      	lsrs	r0, r0, #32
 8000064:	03bd      	lsls	r5, r7, #14
 8000066:	0800      	lsrs	r0, r0, #32
 8000068:	03bd      	lsls	r5, r7, #14
 800006a:	0800      	lsrs	r0, r0, #32
 800006c:	03bd      	lsls	r5, r7, #14
 800006e:	0800      	lsrs	r0, r0, #32
 8000070:	03bd      	lsls	r5, r7, #14
 8000072:	0800      	lsrs	r0, r0, #32
 8000074:	03bd      	lsls	r5, r7, #14
 8000076:	0800      	lsrs	r0, r0, #32
 8000078:	03bd      	lsls	r5, r7, #14
 800007a:	0800      	lsrs	r0, r0, #32
 800007c:	03bd      	lsls	r5, r7, #14
 800007e:	0800      	lsrs	r0, r0, #32
 8000080:	03bd      	lsls	r5, r7, #14
 8000082:	0800      	lsrs	r0, r0, #32
 8000084:	03bd      	lsls	r5, r7, #14
 8000086:	0800      	lsrs	r0, r0, #32
 8000088:	03bd      	lsls	r5, r7, #14
 800008a:	0800      	lsrs	r0, r0, #32
 800008c:	03bd      	lsls	r5, r7, #14
 800008e:	0800      	lsrs	r0, r0, #32
 8000090:	03bd      	lsls	r5, r7, #14
 8000092:	0800      	lsrs	r0, r0, #32
 8000094:	03bd      	lsls	r5, r7, #14
 8000096:	0800      	lsrs	r0, r0, #32
 8000098:	03bd      	lsls	r5, r7, #14
 800009a:	0800      	lsrs	r0, r0, #32
 800009c:	03bd      	lsls	r5, r7, #14
 800009e:	0800      	lsrs	r0, r0, #32
 80000a0:	03bd      	lsls	r5, r7, #14
 80000a2:	0800      	lsrs	r0, r0, #32
 80000a4:	03bd      	lsls	r5, r7, #14
 80000a6:	0800      	lsrs	r0, r0, #32
 80000a8:	03bd      	lsls	r5, r7, #14
 80000aa:	0800      	lsrs	r0, r0, #32
 80000ac:	03bd      	lsls	r5, r7, #14
 80000ae:	0800      	lsrs	r0, r0, #32
 80000b0:	03bd      	lsls	r5, r7, #14
 80000b2:	0800      	lsrs	r0, r0, #32
 80000b4:	03bd      	lsls	r5, r7, #14
 80000b6:	0800      	lsrs	r0, r0, #32
 80000b8:	03bd      	lsls	r5, r7, #14
 80000ba:	0800      	lsrs	r0, r0, #32
 80000bc:	03bd      	lsls	r5, r7, #14
 80000be:	0800      	lsrs	r0, r0, #32
 80000c0:	03bd      	lsls	r5, r7, #14
 80000c2:	0800      	lsrs	r0, r0, #32
 80000c4:	03bd      	lsls	r5, r7, #14
 80000c6:	0800      	lsrs	r0, r0, #32
 80000c8:	03bd      	lsls	r5, r7, #14
 80000ca:	0800      	lsrs	r0, r0, #32
 80000cc:	03bd      	lsls	r5, r7, #14
 80000ce:	0800      	lsrs	r0, r0, #32
 80000d0:	03bd      	lsls	r5, r7, #14
 80000d2:	0800      	lsrs	r0, r0, #32
 80000d4:	03bd      	lsls	r5, r7, #14
 80000d6:	0800      	lsrs	r0, r0, #32
 80000d8:	03bd      	lsls	r5, r7, #14
 80000da:	0800      	lsrs	r0, r0, #32
 80000dc:	03bd      	lsls	r5, r7, #14
 80000de:	0800      	lsrs	r0, r0, #32
 80000e0:	03bd      	lsls	r5, r7, #14
 80000e2:	0800      	lsrs	r0, r0, #32
 80000e4:	03bd      	lsls	r5, r7, #14
 80000e6:	0800      	lsrs	r0, r0, #32
 80000e8:	03bd      	lsls	r5, r7, #14
 80000ea:	0800      	lsrs	r0, r0, #32
 80000ec:	03bd      	lsls	r5, r7, #14
 80000ee:	0800      	lsrs	r0, r0, #32
 80000f0:	03bd      	lsls	r5, r7, #14
 80000f2:	0800      	lsrs	r0, r0, #32
 80000f4:	03bd      	lsls	r5, r7, #14
 80000f6:	0800      	lsrs	r0, r0, #32
 80000f8:	03bd      	lsls	r5, r7, #14
 80000fa:	0800      	lsrs	r0, r0, #32
 80000fc:	03bd      	lsls	r5, r7, #14
 80000fe:	0800      	lsrs	r0, r0, #32
 8000100:	03bd      	lsls	r5, r7, #14
 8000102:	0800      	lsrs	r0, r0, #32
 8000104:	03bd      	lsls	r5, r7, #14
 8000106:	0800      	lsrs	r0, r0, #32
 8000108:	03bd      	lsls	r5, r7, #14
 800010a:	0800      	lsrs	r0, r0, #32
 800010c:	03bd      	lsls	r5, r7, #14
 800010e:	0800      	lsrs	r0, r0, #32
 8000110:	03bd      	lsls	r5, r7, #14
 8000112:	0800      	lsrs	r0, r0, #32
 8000114:	03bd      	lsls	r5, r7, #14
 8000116:	0800      	lsrs	r0, r0, #32
 8000118:	03bd      	lsls	r5, r7, #14
 800011a:	0800      	lsrs	r0, r0, #32
 800011c:	03bd      	lsls	r5, r7, #14
 800011e:	0800      	lsrs	r0, r0, #32
 8000120:	03bd      	lsls	r5, r7, #14
 8000122:	0800      	lsrs	r0, r0, #32
 8000124:	03bd      	lsls	r5, r7, #14
 8000126:	0800      	lsrs	r0, r0, #32
 8000128:	03bd      	lsls	r5, r7, #14
 800012a:	0800      	lsrs	r0, r0, #32
 800012c:	03bd      	lsls	r5, r7, #14
 800012e:	0800      	lsrs	r0, r0, #32
 8000130:	03bd      	lsls	r5, r7, #14
 8000132:	0800      	lsrs	r0, r0, #32
 8000134:	03bd      	lsls	r5, r7, #14
 8000136:	0800      	lsrs	r0, r0, #32
 8000138:	03bd      	lsls	r5, r7, #14
 800013a:	0800      	lsrs	r0, r0, #32
 800013c:	03bd      	lsls	r5, r7, #14
 800013e:	0800      	lsrs	r0, r0, #32
 8000140:	03bd      	lsls	r5, r7, #14
 8000142:	0800      	lsrs	r0, r0, #32
 8000144:	03bd      	lsls	r5, r7, #14
 8000146:	0800      	lsrs	r0, r0, #32
 8000148:	03bd      	lsls	r5, r7, #14
 800014a:	0800      	lsrs	r0, r0, #32
 800014c:	03bd      	lsls	r5, r7, #14
 800014e:	0800      	lsrs	r0, r0, #32
 8000150:	03bd      	lsls	r5, r7, #14
 8000152:	0800      	lsrs	r0, r0, #32
 8000154:	03bd      	lsls	r5, r7, #14
 8000156:	0800      	lsrs	r0, r0, #32
 8000158:	03bd      	lsls	r5, r7, #14
 800015a:	0800      	lsrs	r0, r0, #32
 800015c:	03bd      	lsls	r5, r7, #14
 800015e:	0800      	lsrs	r0, r0, #32
 8000160:	03bd      	lsls	r5, r7, #14
 8000162:	0800      	lsrs	r0, r0, #32
 8000164:	03bd      	lsls	r5, r7, #14
 8000166:	0800      	lsrs	r0, r0, #32
 8000168:	03bd      	lsls	r5, r7, #14
 800016a:	0800      	lsrs	r0, r0, #32
 800016c:	03bd      	lsls	r5, r7, #14
 800016e:	0800      	lsrs	r0, r0, #32
 8000170:	03bd      	lsls	r5, r7, #14
 8000172:	0800      	lsrs	r0, r0, #32
 8000174:	03bd      	lsls	r5, r7, #14
 8000176:	0800      	lsrs	r0, r0, #32
 8000178:	03bd      	lsls	r5, r7, #14
 800017a:	0800      	lsrs	r0, r0, #32
 800017c:	03bd      	lsls	r5, r7, #14
 800017e:	0800      	lsrs	r0, r0, #32
 8000180:	03bd      	lsls	r5, r7, #14
 8000182:	0800      	lsrs	r0, r0, #32
 8000184:	03bd      	lsls	r5, r7, #14
 8000186:	0800      	lsrs	r0, r0, #32
	...
 80001a0:	03bd      	lsls	r5, r7, #14
 80001a2:	0800      	lsrs	r0, r0, #32
 80001a4:	03bd      	lsls	r5, r7, #14
 80001a6:	0800      	lsrs	r0, r0, #32

Disassembly of section .text:

080001a8 <__do_global_dtors_aux>:
 80001a8:	       b510      	push	{r4, lr}
 80001aa:	       4c05      	ldr	r4, [pc, #20]	; (80001c0 <__do_global_dtors_aux+0x18>)
 80001ac:	       7823      	ldrb	r3, [r4, #0]
 80001ae:	/----- b933      	cbnz	r3, 80001be <__do_global_dtors_aux+0x16>
 80001b0:	|      4b04      	ldr	r3, [pc, #16]	; (80001c4 <__do_global_dtors_aux+0x1c>)
 80001b2:	|  /-- b113      	cbz	r3, 80001ba <__do_global_dtors_aux+0x12>
 80001b4:	|  |   4804      	ldr	r0, [pc, #16]	; (80001c8 <__do_global_dtors_aux+0x20>)
 80001b6:	|  |   f3af 8000 	nop.w
 80001ba:	|  \-> 2301      	movs	r3, #1
 80001bc:	|      7023      	strb	r3, [r4, #0]
 80001be:	\----> bd10      	pop	{r4, pc}
 80001c0:	       0004      	movs	r4, r0
 80001c2:	       2000      	movs	r0, #0
 80001c4:	       0000      	movs	r0, r0
 80001c6:	       0000      	movs	r0, r0
 80001c8:	       0590      	lsls	r0, r2, #22
 80001ca:	       0800      	lsrs	r0, r0, #32

080001cc <frame_dummy>:
 80001cc:	    b508      	push	{r3, lr}
 80001ce:	    4b03      	ldr	r3, [pc, #12]	; (80001dc <frame_dummy+0x10>)
 80001d0:	/-- b11b      	cbz	r3, 80001da <frame_dummy+0xe>
 80001d2:	|   4903      	ldr	r1, [pc, #12]	; (80001e0 <frame_dummy+0x14>)
 80001d4:	|   4803      	ldr	r0, [pc, #12]	; (80001e4 <frame_dummy+0x18>)
 80001d6:	|   f3af 8000 	nop.w
 80001da:	\-> bd08      	pop	{r3, pc}
 80001dc:	    0000      	movs	r0, r0
 80001de:	    0000      	movs	r0, r0
 80001e0:	    0008      	movs	r0, r1
 80001e2:	    2000      	movs	r0, #0
 80001e4:	    0590      	lsls	r0, r2, #22
 80001e6:	    0800      	lsrs	r0, r0, #32

080001e8 <SystemInit>:
  */
void SystemInit(void)
{
  /* FPU settings ------------------------------------------------------------*/
  #if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 Full Access */
 80001e8:	4a03      	ldr	r2, [pc, #12]	; (80001f8 <SystemInit+0x10>)
 80001ea:	f8d2 3088 	ldr.w	r3, [r2, #136]	; 0x88
 80001ee:	f443 0370 	orr.w	r3, r3, #15728640	; 0xf00000
 80001f2:	f8c2 3088 	str.w	r3, [r2, #136]	; 0x88

  /* Configure the Vector Table location -------------------------------------*/
#if defined(USER_VECT_TAB_ADDRESS)
  SCB->VTOR = VECT_TAB_BASE_ADDRESS | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM */
#endif /* USER_VECT_TAB_ADDRESS */
}
 80001f6:	4770      	bx	lr
 80001f8:	ed00 e000 	stc	0, cr14, [r0, #-0]

080001fc <SystemCoreClockUpdate>:
void SystemCoreClockUpdate(void)
{
  uint32_t tmp = 0, pllvco = 0, pllp = 2, pllsource = 0, pllm = 2;
  
  /* Get SYSCLK source -------------------------------------------------------*/
  tmp = RCC->CFGR & RCC_CFGR_SWS;
 80001fc:	          4a16      	ldr	r2, [pc, #88]	; (8000258 <SystemCoreClockUpdate+0x5c>)
 80001fe:	          6893      	ldr	r3, [r2, #8]
 8000200:	          f003 030c 	and.w	r3, r3, #12

  switch (tmp)
 8000204:	          2b04      	cmp	r3, #4
 8000206:	      /-- d00c      	beq.n	8000222 <SystemCoreClockUpdate+0x26>
 8000208:	      |   2b08      	cmp	r3, #8
 800020a:	   /--|-- d00c      	beq.n	8000226 <SystemCoreClockUpdate+0x2a>
 800020c:	   |  |   4b13      	ldr	r3, [pc, #76]	; (800025c <SystemCoreClockUpdate+0x60>)
      SystemCoreClock = HSI_VALUE;
      break;
  }
  /* Compute HCLK frequency --------------------------------------------------*/
  /* Get HCLK prescaler */
  tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4)];
 800020e:	/--|--|-> 4a12      	ldr	r2, [pc, #72]	; (8000258 <SystemCoreClockUpdate+0x5c>)
 8000210:	|  |  |   4813      	ldr	r0, [pc, #76]	; (8000260 <SystemCoreClockUpdate+0x64>)
 8000212:	|  |  |   6892      	ldr	r2, [r2, #8]
  /* HCLK frequency */
  SystemCoreClock >>= tmp;
 8000214:	|  |  |   4913      	ldr	r1, [pc, #76]	; (8000264 <SystemCoreClockUpdate+0x68>)
  tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4)];
 8000216:	|  |  |   f3c2 1203 	ubfx	r2, r2, #4, #4
 800021a:	|  |  |   5c82      	ldrb	r2, [r0, r2]
  SystemCoreClock >>= tmp;
 800021c:	|  |  |   40d3      	lsrs	r3, r2
 800021e:	|  |  |   600b      	str	r3, [r1, #0]
}
 8000220:	|  |  |   4770      	bx	lr
  switch (tmp)
 8000222:	|  |  \-> 4b11      	ldr	r3, [pc, #68]	; (8000268 <SystemCoreClockUpdate+0x6c>)
 8000224:	+--|----- e7f3      	b.n	800020e <SystemCoreClockUpdate+0x12>
      pllsource = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC) >> 22;
 8000226:	|  \----> 6853      	ldr	r3, [r2, #4]
      pllm = RCC->PLLCFGR & RCC_PLLCFGR_PLLM;
 8000228:	|         6851      	ldr	r1, [r2, #4]
      if (pllsource != 0)
 800022a:	|         f413 0f80 	tst.w	r3, #4194304	; 0x400000
      pllm = RCC->PLLCFGR & RCC_PLLCFGR_PLLM;
 800022e:	|         f001 013f 	and.w	r1, r1, #63	; 0x3f
        pllvco = (HSE_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
 8000232:	|         6853      	ldr	r3, [r2, #4]
 8000234:	|         bf14      	ite	ne
 8000236:	|         4a0c      	ldrne	r2, [pc, #48]	; (8000268 <SystemCoreClockUpdate+0x6c>)
        pllvco = (HSI_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
 8000238:	|         4a08      	ldreq	r2, [pc, #32]	; (800025c <SystemCoreClockUpdate+0x60>)
 800023a:	|         fbb2 f1f1 	udiv	r1, r2, r1
      pllp = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >>16) + 1 ) *2;
 800023e:	|         4a06      	ldr	r2, [pc, #24]	; (8000258 <SystemCoreClockUpdate+0x5c>)
 8000240:	|         6852      	ldr	r2, [r2, #4]
 8000242:	|         f3c2 4201 	ubfx	r2, r2, #16, #2
        pllvco = (HSI_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
 8000246:	|         f3c3 1388 	ubfx	r3, r3, #6, #9
      pllp = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >>16) + 1 ) *2;
 800024a:	|         3201      	adds	r2, #1
        pllvco = (HSI_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
 800024c:	|         fb01 f303 	mul.w	r3, r1, r3
      pllp = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >>16) + 1 ) *2;
 8000250:	|         0052      	lsls	r2, r2, #1
      SystemCoreClock = pllvco/pllp;
 8000252:	|         fbb3 f3f2 	udiv	r3, r3, r2
      break;
 8000256:	\-------- e7da      	b.n	800020e <SystemCoreClockUpdate+0x12>
 8000258:	          3800      	subs	r0, #0
 800025a:	          4002      	ands	r2, r0
 800025c:	          2400      	movs	r4, #0
 800025e:	          00f4      	lsls	r4, r6, #3
 8000260:	          05a8      	lsls	r0, r5, #22
 8000262:	          0800      	lsrs	r0, r0, #32
 8000264:	          0000      	movs	r0, r0
 8000266:	          2000      	movs	r0, #0
 8000268:	          1200      	asrs	r0, r0, #8
 800026a:	          007a      	lsls	r2, r7, #1

0800026c <sys_clk_update>:
#define HSI_VALUE    ((uint32_t)16000000) /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */

__CONSTRUCTOR
__FORCE_INLINE void sys_clk_update()
{
 800026c:	b508      	push	{r3, lr}
    SystemCoreClockUpdate();
 800026e:	f7ff ffc5 	bl	80001fc <SystemCoreClockUpdate>
    delay_init();
}
 8000272:	e8bd 4008 	ldmia.w	sp!, {r3, lr}
    delay_init();
 8000276:	f000 b93d 	b.w	80004f4 <delay_init>
 800027a:	bf00      	nop

0800027c <main>:
#include "adc.h"
#include "gpio.h"
#include "delay.h"

int main (void)
{
 800027c:	          b580      	push	{r7, lr}
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_en_ahb1(rcc_ahb1_t mask)
{
    RCC->AHB1ENR |= mask;
 800027e:	          4f24      	ldr	r7, [pc, #144]	; (8000310 <main+0x94>)
    gpio_clk_en(GPIOA_RCC);
    gpio_config_mode(GPIOA, GPIO_MODE_ANALOG, GPIO_IO0);
 8000280:	          4824      	ldr	r0, [pc, #144]	; (8000314 <main+0x98>)
 8000282:	          6b3b      	ldr	r3, [r7, #48]	; 0x30
    /* ADC clock 2 & 3 should be disabled ----------------------------------|*/
    adc_clk_dis(ADC2_RCC | ADC3_RCC);                                   /*<-|*/ /*[]*/
    adc_sequencer_rgl.sequece[0] = 0;
    adc_sequencer_rgl.sequece[1] = 17;
    adc_sequencer_rgl.sequece[2] = 16;
    adc_sequencer_rgl.lenght = 3;
 8000284:	          4d24      	ldr	r5, [pc, #144]	; (8000318 <main+0x9c>)
    adc_config_seq_rgl(ADC1);
 8000286:	          4c25      	ldr	r4, [pc, #148]	; (800031c <main+0xa0>)
    gpio_config_mode(GPIOA, GPIO_MODE_ANALOG, GPIO_IO0);
 8000288:	          2201      	movs	r2, #1
 800028a:	          4313      	orrs	r3, r2
 800028c:	          2103      	movs	r1, #3
 800028e:	          633b      	str	r3, [r7, #48]	; 0x30
 8000290:	          f000 f89e 	bl	80003d0 <gpio_config_mode>
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_en_apb2(rcc_apb2_t mask)
{
    RCC->APB2ENR |= mask;
 8000294:	          6c7b      	ldr	r3, [r7, #68]	; 0x44
 8000296:	          f443 63e0 	orr.w	r3, r3, #1792	; 0x700
 800029a:	          647b      	str	r3, [r7, #68]	; 0x44
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_dis_apb2(rcc_apb2_t mask)
{
    RCC->APB2ENR &= ~mask;
 800029c:	          6c7b      	ldr	r3, [r7, #68]	; 0x44
    adc_sequencer_rgl.lenght = 3;
 800029e:	          462e      	mov	r6, r5
 80002a0:	          f423 63c0 	bic.w	r3, r3, #1536	; 0x600
 80002a4:	          647b      	str	r3, [r7, #68]	; 0x44
 80002a6:	          4b1e      	ldr	r3, [pc, #120]	; (8000320 <main+0xa4>)
 80002a8:	          f846 3b12 	str.w	r3, [r6], #18
    adc_config_seq_rgl(ADC1);
 80002ac:	          4620      	mov	r0, r4
 80002ae:	          f000 f8c7 	bl	8000440 <adc_config_seq_rgl>

    adc_config_ind_scan(
 80002b2:	          2200      	movs	r2, #0
 80002b4:	          2303      	movs	r3, #3
 80002b6:	          4611      	mov	r1, r2
 80002b8:	          4620      	mov	r0, r4
 80002ba:	          f000 f8a9 	bl	8000410 <adc_config_ind_scan>

void adc_read_ind_scan(ADC_TypeDef *adc);

__FORCE_INLINE void adc_internalch_en(adc_ich_t mask)
{
    ADC->CCR |= mask;
 80002be:	          4a19      	ldr	r2, [pc, #100]	; (8000324 <main+0xa8>)
 80002c0:	          6853      	ldr	r3, [r2, #4]
 80002c2:	          f443 0300 	orr.w	r3, r3, #8388608	; 0x800000
 80002c6:	          6053      	str	r3, [r2, #4]
    adc->CR2 |= ADC_CR2_ADON;
 80002c8:	          68a3      	ldr	r3, [r4, #8]
    return (raw * ADC_VREF) / resbits_decode[resolution];
 80002ca:	          4a17      	ldr	r2, [pc, #92]	; (8000328 <main+0xac>)
    adc->CR2 |= ADC_CR2_ADON;
 80002cc:	          f043 0301 	orr.w	r3, r3, #1
    return (raw * ADC_VREF) / resbits_decode[resolution];
 80002d0:	          f8b2 9000 	ldrh.w	r9, [r2]
    adc->CR2 |= ADC_CR2_ADON;
 80002d4:	          60a3      	str	r3, [r4, #8]
 80002d6:	          2702      	movs	r7, #2
    return (raw * ADC_VREF) / resbits_decode[resolution];
 80002d8:	          f640 48e4 	movw	r8, #3300	; 0xce4
    
    adc_internalch_en(ADC_INCH_TVREF);
    adc_power_on(ADC1);

    while(1) {
        adc_read_ind_scan(ADC1);
 80002dc:	/-------> 4620      	mov	r0, r4
 80002de:	|         f000 f8e3 	bl	80004a8 <adc_read_ind_scan>
    ADC->CCR &= ~mask;
}

__FORCE_INLINE void adc_seq_get_voltages(adc_res_t resolution)
{
    for (uint8_t i = 0; i < adc_sequencer_rgl.lenght; i++)
 80002e2:	|         7828      	ldrb	r0, [r5, #0]
 80002e4:	|  /----- b180      	cbz	r0, 8000308 <main+0x8c>
 80002e6:	|  |      4a11      	ldr	r2, [pc, #68]	; (800032c <main+0xb0>)
 80002e8:	|  |      3801      	subs	r0, #1
 80002ea:	|  |      b2c0      	uxtb	r0, r0
 80002ec:	|  |      f102 0120 	add.w	r1, r2, #32
 80002f0:	|  |      fb17 6000 	smlabb	r0, r7, r0, r6
    return (raw * ADC_VREF) / resbits_decode[resolution];
 80002f4:	|  |  /-> f832 3f02 	ldrh.w	r3, [r2, #2]!
    for (uint8_t i = 0; i < adc_sequencer_rgl.lenght; i++)
 80002f8:	|  |  |   4282      	cmp	r2, r0
    return (raw * ADC_VREF) / resbits_decode[resolution];
 80002fa:	|  |  |   fb08 f303 	mul.w	r3, r8, r3
 80002fe:	|  |  |   fbb3 f3f9 	udiv	r3, r3, r9
        adc_sequencer_rgl.voltage[i] = 
 8000302:	|  |  |   f841 3f04 	str.w	r3, [r1, #4]!
    for (uint8_t i = 0; i < adc_sequencer_rgl.lenght; i++)
 8000306:	|  |  \-- d1f5      	bne.n	80002f4 <main+0x78>
        adc_seq_get_voltages(ADC_RES_12BITS);
        delay_ms(100);
 8000308:	|  \----> 2064      	movs	r0, #100	; 0x64
 800030a:	|         f000 f911 	bl	8000530 <delay_ms>
        adc_read_ind_scan(ADC1);
 800030e:	\-------- e7e5      	b.n	80002dc <main+0x60>
 8000310:	          3800      	subs	r0, #0
 8000312:	          4002      	ands	r2, r0
 8000314:	          0000      	movs	r0, r0
 8000316:	          4002      	ands	r2, r0
 8000318:	          0020      	movs	r0, r4
 800031a:	          2000      	movs	r0, #0
 800031c:	          2000      	movs	r0, #0
 800031e:	          4001      	ands	r1, r0
 8000320:	          0003      	movs	r3, r0
 8000322:	          1011      	asrs	r1, r2, #32
 8000324:	          2300      	movs	r3, #0
 8000326:	          4001      	ands	r1, r0
 8000328:	          05b8      	lsls	r0, r7, #22
 800032a:	          0800      	lsrs	r0, r0, #32
 800032c:	          0030      	movs	r0, r6
 800032e:	          2000      	movs	r0, #0

08000330 <Reset_Handler>:
 8000330:	4817      	ldr	r0, [pc, #92]	; (8000390 <LoopForever+0x4>)
 8000332:	4685      	mov	sp, r0
 8000334:	f7ff ff58 	bl	80001e8 <SystemInit>
 8000338:	4816      	ldr	r0, [pc, #88]	; (8000394 <LoopForever+0x8>)
 800033a:	4917      	ldr	r1, [pc, #92]	; (8000398 <LoopForever+0xc>)
 800033c:	4a17      	ldr	r2, [pc, #92]	; (800039c <LoopForever+0x10>)
 800033e:	2300      	movs	r3, #0
 8000340:	e002      	b.n	8000348 <LoopCopyDataInit>

08000342 <CopyDataInit>:
 8000342:	58d4      	ldr	r4, [r2, r3]
 8000344:	50c4      	str	r4, [r0, r3]
 8000346:	3304      	adds	r3, #4

08000348 <LoopCopyDataInit>:
 8000348:	18c4      	adds	r4, r0, r3
 800034a:	428c      	cmp	r4, r1
 800034c:	d3f9      	bcc.n	8000342 <CopyDataInit>
 800034e:	4a14      	ldr	r2, [pc, #80]	; (80003a0 <LoopForever+0x14>)
 8000350:	4c14      	ldr	r4, [pc, #80]	; (80003a4 <LoopForever+0x18>)
 8000352:	2300      	movs	r3, #0
 8000354:	e001      	b.n	800035a <LoopFillZerobss>

08000356 <FillZerobss>:
 8000356:	6013      	str	r3, [r2, #0]
 8000358:	3204      	adds	r2, #4

0800035a <LoopFillZerobss>:
 800035a:	42a2      	cmp	r2, r4
 800035c:	d3fb      	bcc.n	8000356 <FillZerobss>
 800035e:	4812      	ldr	r0, [pc, #72]	; (80003a8 <LoopForever+0x1c>)
 8000360:	4912      	ldr	r1, [pc, #72]	; (80003ac <LoopForever+0x20>)
 8000362:	4a13      	ldr	r2, [pc, #76]	; (80003b0 <LoopForever+0x24>)
 8000364:	2300      	movs	r3, #0
 8000366:	e002      	b.n	800036e <LoopCopyCCMDataInit>

08000368 <CopyCCMDataInit>:
 8000368:	58d4      	ldr	r4, [r2, r3]
 800036a:	50c4      	str	r4, [r0, r3]
 800036c:	3304      	adds	r3, #4

0800036e <LoopCopyCCMDataInit>:
 800036e:	18c4      	adds	r4, r0, r3
 8000370:	428c      	cmp	r4, r1
 8000372:	d3f9      	bcc.n	8000368 <CopyCCMDataInit>
 8000374:	4a0f      	ldr	r2, [pc, #60]	; (80003b4 <LoopForever+0x28>)
 8000376:	4c10      	ldr	r4, [pc, #64]	; (80003b8 <LoopForever+0x2c>)
 8000378:	2300      	movs	r3, #0
 800037a:	e001      	b.n	8000380 <LoopFillZeroCCMbss>

0800037c <FillZeroCCMbss>:
 800037c:	6013      	str	r3, [r2, #0]
 800037e:	3204      	adds	r2, #4

08000380 <LoopFillZeroCCMbss>:
 8000380:	42a2      	cmp	r2, r4
 8000382:	d3fb      	bcc.n	800037c <FillZeroCCMbss>
 8000384:	f000 f8e0 	bl	8000548 <__libc_init_array>
 8000388:	f7ff ff78 	bl	800027c <main>

0800038c <LoopForever>:
 800038c:	/-- e7fe      	b.n	800038c <LoopForever>
 800038e:	    0000      	movs	r0, r0
 8000390:	    0000      	movs	r0, r0
 8000392:	    2002      	movs	r0, #2
 8000394:	    0000      	movs	r0, r0
 8000396:	    2000      	movs	r0, #0
 8000398:	    0004      	movs	r4, r0
 800039a:	    2000      	movs	r0, #0
 800039c:	    05d8      	lsls	r0, r3, #23
 800039e:	    0800      	lsrs	r0, r0, #32
 80003a0:	    0004      	movs	r4, r0
 80003a2:	    2000      	movs	r0, #0
 80003a4:	    009c      	lsls	r4, r3, #2
 80003a6:	    2000      	movs	r0, #0
 80003a8:	    0000      	movs	r0, r0
 80003aa:	    1000      	asrs	r0, r0, #32
 80003ac:	    0000      	movs	r0, r0
 80003ae:	    1000      	asrs	r0, r0, #32
 80003b0:	    05dc      	lsls	r4, r3, #23
 80003b2:	    0800      	lsrs	r0, r0, #32
 80003b4:	    0000      	movs	r0, r0
 80003b6:	    1000      	asrs	r0, r0, #32
 80003b8:	    0000      	movs	r0, r0
 80003ba:	    1000      	asrs	r0, r0, #32

080003bc <ADC_IRQHandler>:
 80003bc:	/-- e7fe      	b.n	80003bc <ADC_IRQHandler>
	...

080003c0 <sys_clk_update>:
#define HSI_VALUE    ((uint32_t)16000000) /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */

__CONSTRUCTOR
__FORCE_INLINE void sys_clk_update()
{
 80003c0:	b508      	push	{r3, lr}
    SystemCoreClockUpdate();
 80003c2:	f7ff ff1b 	bl	80001fc <SystemCoreClockUpdate>
    delay_init();
}
 80003c6:	e8bd 4008 	ldmia.w	sp!, {r3, lr}
    delay_init();
 80003ca:	f000 b893 	b.w	80004f4 <delay_init>
 80003ce:	bf00      	nop

080003d0 <gpio_config_mode>:
    }
}

/* Individual Modder configurator */
void gpio_config_mode (GPIO_TypeDef *gpio, gpio_mode_t mode, gpio_io_t mask)
{
 80003d0:	       b530      	push	{r4, r5, lr}
 80003d2:	       2300      	movs	r3, #0
    /* Enable desired gpio mode [\mode] to each IO moder configurator
       masked [\mask] of GPIO [\gpio] */
    for (uint8_t bit = 0; bit < 32; bit += 2) {
        if (mask & 0x1) {
            gpio->MODER &= ~(0x3 << bit);
 80003d4:	       f04f 0e03 	mov.w	lr, #3
        if (mask & 0x1) {
 80003d8:	/----> f012 0f01 	tst.w	r2, #1
            gpio->MODER &= ~(0x3 << bit);
 80003dc:	|      fa0e fc03 	lsl.w	r12, lr, r3
            gpio->MODER |= mode << bit;
        }
        mask >>= 1;
 80003e0:	|      ea4f 0252 	mov.w	r2, r2, lsr #1
        if (mask & 0x1) {
 80003e4:	|  /-- d008      	beq.n	80003f8 <gpio_config_mode+0x28>
            gpio->MODER &= ~(0x3 << bit);
 80003e6:	|  |   6805      	ldr	r5, [r0, #0]
 80003e8:	|  |   ea25 050c 	bic.w	r5, r5, r12
 80003ec:	|  |   6005      	str	r5, [r0, #0]
            gpio->MODER |= mode << bit;
 80003ee:	|  |   6805      	ldr	r5, [r0, #0]
 80003f0:	|  |   fa01 f403 	lsl.w	r4, r1, r3
 80003f4:	|  |   432c      	orrs	r4, r5
 80003f6:	|  |   6004      	str	r4, [r0, #0]
    for (uint8_t bit = 0; bit < 32; bit += 2) {
 80003f8:	|  \-> 3302      	adds	r3, #2
 80003fa:	|      2b20      	cmp	r3, #32
 80003fc:	\----- d1ec      	bne.n	80003d8 <gpio_config_mode+0x8>
    }
}
 80003fe:	       bd30      	pop	{r4, r5, pc}

08000400 <sys_clk_update>:
{
 8000400:	b508      	push	{r3, lr}
    SystemCoreClockUpdate();
 8000402:	f7ff fefb 	bl	80001fc <SystemCoreClockUpdate>
}
 8000406:	e8bd 4008 	ldmia.w	sp!, {r3, lr}
    delay_init();
 800040a:	f000 b873 	b.w	80004f4 <delay_init>
 800040e:	bf00      	nop

08000410 <adc_config_ind_scan>:

void adc_config_ind_scan(
    ADC_TypeDef *adc, adc_res_t resolution, adc_align_t alignment, 
    adc_pre_t prescaler
)
{
 8000410:	b4f0      	push	{r4, r5, r6, r7}
    ADC->CCR = 0;
 8000412:	4e0a      	ldr	r6, [pc, #40]	; (800043c <adc_config_ind_scan+0x2c>)
 8000414:	2400      	movs	r4, #0
 8000416:	6074      	str	r4, [r6, #4]
    ADC->CCR |= prescaler << ADC_CCR_ADCPRE_Pos;
 8000418:	6877      	ldr	r7, [r6, #4]
 800041a:	ea47 4703 	orr.w	r7, r7, r3, lsl #16
 800041e:	6077      	str	r7, [r6, #4]

    adc->CR1 = 0;
 8000420:	6044      	str	r4, [r0, #4]
    adc->CR1 |= (resolution << ADC_CR1_RES_Pos); // | ADC_CR1_SCAN;
 8000422:	6845      	ldr	r5, [r0, #4]
 8000424:	ea45 6101 	orr.w	r1, r5, r1, lsl #24
 8000428:	6041      	str	r1, [r0, #4]

    adc->CR2 = 0;
 800042a:	6084      	str	r4, [r0, #8]
    adc->CR2 |= (alignment << ADC_CR2_ALIGN_Pos) | ADC_CR2_EOCS;
 800042c:	6883      	ldr	r3, [r0, #8]
 800042e:	ea43 22c2 	orr.w	r2, r3, r2, lsl #11
 8000432:	f442 6280 	orr.w	r2, r2, #1024	; 0x400
}
 8000436:	bcf0      	pop	{r4, r5, r6, r7}
    adc->CR2 |= (alignment << ADC_CR2_ALIGN_Pos) | ADC_CR2_EOCS;
 8000438:	6082      	str	r2, [r0, #8]
}
 800043a:	4770      	bx	lr
 800043c:	2300      	movs	r3, #0
 800043e:	4001      	ands	r1, r0

08000440 <adc_config_seq_rgl>:

void adc_config_seq_rgl(ADC_TypeDef *adc)
{
 8000440:	                b470      	push	{r4, r5, r6}
    adc->SQR1 = 0;
    adc->SQR2 = 0;
    adc->SQR3 = 0;
    adc->SQR1 |= ((adc_sequencer_rgl.lenght - 1) << ADC_SQR1_L_Pos);
 8000442:	                4918      	ldr	r1, [pc, #96]	; (80004a4 <adc_config_seq_rgl+0x64>)
    adc->SQR1 = 0;
 8000444:	                2200      	movs	r2, #0
 8000446:	                62c2      	str	r2, [r0, #44]	; 0x2c
    adc->SQR1 |= ((adc_sequencer_rgl.lenght - 1) << ADC_SQR1_L_Pos);
 8000448:	                780d      	ldrb	r5, [r1, #0]
    adc->SQR2 = 0;
 800044a:	                6302      	str	r2, [r0, #48]	; 0x30
    adc->SQR3 = 0;
 800044c:	                6342      	str	r2, [r0, #52]	; 0x34
    adc->SQR1 |= ((adc_sequencer_rgl.lenght - 1) << ADC_SQR1_L_Pos);
 800044e:	                6ac3      	ldr	r3, [r0, #44]	; 0x2c
 8000450:	                1e6c      	subs	r4, r5, #1
 8000452:	                ea43 5304 	orr.w	r3, r3, r4, lsl #20
 8000456:	                62c3      	str	r3, [r0, #44]	; 0x2c
    
    for (uint8_t i = 0; i < adc_sequencer_rgl.lenght; i++)
 8000458:	/-------------- b1fd      	cbz	r5, 800049a <adc_config_seq_rgl+0x5a>
 800045a:	|               4613      	mov	r3, r2
 800045c:	|               4694      	mov	r12, r2
 800045e:	|           /-- e00f      	b.n	8000480 <adc_config_seq_rgl+0x40>
    {
        if (i <= 6) {
            adc->SQR3 |= adc_sequencer_rgl.sequece[i] << (i*5);
        } else if (i <= 12) {
 8000460:	|        /--|-> f1bc 0f0c 	cmp.w	r12, #12
 8000464:	|  /-----|--|-- d914      	bls.n	8000490 <adc_config_seq_rgl+0x50>
            adc->SQR2 |= adc_sequencer_rgl.sequece[i] << (i*5);
        } else {
            adc->SQR1 |= adc_sequencer_rgl.sequece[i] << (i*5);
 8000466:	|  |     |  |   6ac6      	ldr	r6, [r0, #44]	; 0x2c
 8000468:	|  |     |  |   4094      	lsls	r4, r2
 800046a:	|  |     |  |   4334      	orrs	r4, r6
 800046c:	|  |     |  |   62c4      	str	r4, [r0, #44]	; 0x2c
    for (uint8_t i = 0; i < adc_sequencer_rgl.lenght; i++)
 800046e:	|  |  /--|--|-> 3301      	adds	r3, #1
 8000470:	|  |  |  |  |   fa5f fc83 	uxtb.w	r12, r3
 8000474:	|  |  |  |  |   4565      	cmp	r5, r12
 8000476:	|  |  |  |  |   f101 0101 	add.w	r1, r1, #1
 800047a:	|  |  |  |  |   f102 0205 	add.w	r2, r2, #5
 800047e:	+--|--|--|--|-- d90c      	bls.n	800049a <adc_config_seq_rgl+0x5a>
        if (i <= 6) {
 8000480:	|  |  |  |  \-> 2b06      	cmp	r3, #6
            adc->SQR3 |= adc_sequencer_rgl.sequece[i] << (i*5);
 8000482:	|  |  |  |      784c      	ldrb	r4, [r1, #1]
        if (i <= 6) {
 8000484:	|  |  |  \----- d8ec      	bhi.n	8000460 <adc_config_seq_rgl+0x20>
            adc->SQR3 |= adc_sequencer_rgl.sequece[i] << (i*5);
 8000486:	|  |  |         6b46      	ldr	r6, [r0, #52]	; 0x34
 8000488:	|  |  |         4094      	lsls	r4, r2
 800048a:	|  |  |         4334      	orrs	r4, r6
 800048c:	|  |  |         6344      	str	r4, [r0, #52]	; 0x34
 800048e:	|  |  +-------- e7ee      	b.n	800046e <adc_config_seq_rgl+0x2e>
            adc->SQR2 |= adc_sequencer_rgl.sequece[i] << (i*5);
 8000490:	|  \--|-------> 6b06      	ldr	r6, [r0, #48]	; 0x30
 8000492:	|     |         4094      	lsls	r4, r2
 8000494:	|     |         4334      	orrs	r4, r6
 8000496:	|     |         6304      	str	r4, [r0, #48]	; 0x30
 8000498:	|     \-------- e7e9      	b.n	800046e <adc_config_seq_rgl+0x2e>
        }
    }

    adc->SR = 0;
 800049a:	\-------------> 2300      	movs	r3, #0
}
 800049c:	                bc70      	pop	{r4, r5, r6}
    adc->SR = 0;
 800049e:	                6003      	str	r3, [r0, #0]
}
 80004a0:	                4770      	bx	lr
 80004a2:	                bf00      	nop
 80004a4:	                0020      	movs	r0, r4
 80004a6:	                2000      	movs	r0, #0

080004a8 <adc_read_ind_scan>:
}

void adc_read_ind_scan(ADC_TypeDef *adc)
{
    adc->CR2 |= ADC_CR2_SWSTART;
    for(uint8_t i = 0; i < adc_sequencer_rgl.lenght; i++)
 80004a8:	       4a0d      	ldr	r2, [pc, #52]	; (80004e0 <adc_read_ind_scan+0x38>)
    adc->CR2 |= ADC_CR2_SWSTART;
 80004aa:	       6881      	ldr	r1, [r0, #8]
    for(uint8_t i = 0; i < adc_sequencer_rgl.lenght; i++)
 80004ac:	       7813      	ldrb	r3, [r2, #0]
    adc->CR2 |= ADC_CR2_SWSTART;
 80004ae:	       f041 4180 	orr.w	r1, r1, #1073741824	; 0x40000000
 80004b2:	       6081      	str	r1, [r0, #8]
    for(uint8_t i = 0; i < adc_sequencer_rgl.lenght; i++)
 80004b4:	/----- b173      	cbz	r3, 80004d4 <adc_read_ind_scan+0x2c>
 80004b6:	|      3b01      	subs	r3, #1
 80004b8:	|      f102 0112 	add.w	r1, r2, #18
 80004bc:	|      b2db      	uxtb	r3, r3
 80004be:	|      3210      	adds	r2, #16
 80004c0:	|      eb01 0143 	add.w	r1, r1, r3, lsl #1
    {
        while((adc->SR & ADC_SR_EOC) == 0);
 80004c4:	|  /-> 6803      	ldr	r3, [r0, #0]
 80004c6:	|  |   079b      	lsls	r3, r3, #30
 80004c8:	|  +-- d5fc      	bpl.n	80004c4 <adc_read_ind_scan+0x1c>
        adc_sequencer_rgl.raw[i] = adc->DR;
 80004ca:	|  |   6cc3      	ldr	r3, [r0, #76]	; 0x4c
 80004cc:	|  |   f822 3f02 	strh.w	r3, [r2, #2]!
    for(uint8_t i = 0; i < adc_sequencer_rgl.lenght; i++)
 80004d0:	|  |   428a      	cmp	r2, r1
 80004d2:	|  \-- d1f7      	bne.n	80004c4 <adc_read_ind_scan+0x1c>
    }
    adc->SR &= ~ADC_SR_STRT;
 80004d4:	\----> 6803      	ldr	r3, [r0, #0]
 80004d6:	       f023 0310 	bic.w	r3, r3, #16
 80004da:	       6003      	str	r3, [r0, #0]
}
 80004dc:	       4770      	bx	lr
 80004de:	       bf00      	nop
 80004e0:	       0020      	movs	r0, r4
 80004e2:	       2000      	movs	r0, #0

080004e4 <sys_clk_update>:
{
 80004e4:	b508      	push	{r3, lr}
    SystemCoreClockUpdate();
 80004e6:	f7ff fe89 	bl	80001fc <SystemCoreClockUpdate>
}
 80004ea:	e8bd 4008 	ldmia.w	sp!, {r3, lr}
    delay_init();
 80004ee:	f000 b801 	b.w	80004f4 <delay_init>
 80004f2:	bf00      	nop

080004f4 <delay_init>:
uint32_t DELAY_CYCLES_US;              


void delay_init (void)
{
    DELAY_CYCLES_MS = (SystemCoreClock / 1000);
 80004f4:	4a09      	ldr	r2, [pc, #36]	; (800051c <delay_init+0x28>)
 80004f6:	4b0a      	ldr	r3, [pc, #40]	; (8000520 <delay_init+0x2c>)
 80004f8:	6812      	ldr	r2, [r2, #0]
    DELAY_CYCLES_US = (DELAY_CYCLES_MS / 1000);
    DELAY_CYCLES_MS += EXTRACYCLES_PER_MS;
 80004fa:	480a      	ldr	r0, [pc, #40]	; (8000524 <delay_init+0x30>)
{
 80004fc:	b410      	push	{r4}
    DELAY_CYCLES_US = (DELAY_CYCLES_MS / 1000);
 80004fe:	4c0a      	ldr	r4, [pc, #40]	; (8000528 <delay_init+0x34>)
    DELAY_CYCLES_MS = (SystemCoreClock / 1000);
 8000500:	fba3 1302 	umull	r1, r3, r3, r2
 8000504:	099b      	lsrs	r3, r3, #6
    DELAY_CYCLES_US = (DELAY_CYCLES_MS / 1000);
 8000506:	fba4 4202 	umull	r4, r2, r4, r2
 800050a:	4908      	ldr	r1, [pc, #32]	; (800052c <delay_init+0x38>)
}
 800050c:	f85d 4b04 	ldr.w	r4, [sp], #4
    DELAY_CYCLES_US = (DELAY_CYCLES_MS / 1000);
 8000510:	0c92      	lsrs	r2, r2, #18
    DELAY_CYCLES_MS += EXTRACYCLES_PER_MS;
 8000512:	3309      	adds	r3, #9
 8000514:	6003      	str	r3, [r0, #0]
    DELAY_CYCLES_US = (DELAY_CYCLES_MS / 1000);
 8000516:	600a      	str	r2, [r1, #0]
}
 8000518:	4770      	bx	lr
 800051a:	bf00      	nop
 800051c:	0000      	movs	r0, r0
 800051e:	2000      	movs	r0, #0
 8000520:	4dd3      	ldr	r5, [pc, #844]	; (8000870 <_siccmdata+0x294>)
 8000522:	1062      	asrs	r2, r4, #1
 8000524:	0094      	lsls	r4, r2, #2
 8000526:	2000      	movs	r0, #0
 8000528:	de83      	udf	#131	; 0x83
 800052a:	431b      	orrs	r3, r3
 800052c:	0098      	lsls	r0, r3, #2
 800052e:	2000      	movs	r0, #0

08000530 <delay_ms>:

__attribute__((optimize("-Os")))
void delay_ms (uint32_t ms)
{
    do {
        register int32_t cycles_to_ms = DELAY_CYCLES_MS;
 8000530:	       4a04      	ldr	r2, [pc, #16]	; (8000544 <delay_ms+0x14>)
 8000532:	/----> 6813      	ldr	r3, [r2, #0]
        do {
            __asm("NOP");
 8000534:	|  /-> bf00      	nop
            cycles_to_ms -= CYCLES_PER_MS;
 8000536:	|  |   3b05      	subs	r3, #5
        } while (cycles_to_ms > 0);
 8000538:	|  |   2b00      	cmp	r3, #0
 800053a:	|  \-- dcfb      	bgt.n	8000534 <delay_ms+0x4>
    } while (--ms);
 800053c:	|      3801      	subs	r0, #1
 800053e:	\----- d1f8      	bne.n	8000532 <delay_ms+0x2>
}
 8000540:	       4770      	bx	lr
 8000542:	       bf00      	nop
 8000544:	       0094      	lsls	r4, r2, #2
 8000546:	       2000      	movs	r0, #0

08000548 <__libc_init_array>:
 8000548:	             b570      	push	{r4, r5, r6, lr}
 800054a:	             4d0d      	ldr	r5, [pc, #52]	; (8000580 <__libc_init_array+0x38>)
 800054c:	             4c0d      	ldr	r4, [pc, #52]	; (8000584 <__libc_init_array+0x3c>)
 800054e:	             1b64      	subs	r4, r4, r5
 8000550:	             10a4      	asrs	r4, r4, #2
 8000552:	             2600      	movs	r6, #0
 8000554:	/----------> 42a6      	cmp	r6, r4
 8000556:	|     /----- d109      	bne.n	800056c <__libc_init_array+0x24>
 8000558:	|     |      4d0b      	ldr	r5, [pc, #44]	; (8000588 <__libc_init_array+0x40>)
 800055a:	|     |      4c0c      	ldr	r4, [pc, #48]	; (800058c <__libc_init_array+0x44>)
 800055c:	|     |      f000 f818 	bl	8000590 <_init>
 8000560:	|     |      1b64      	subs	r4, r4, r5
 8000562:	|     |      10a4      	asrs	r4, r4, #2
 8000564:	|     |      2600      	movs	r6, #0
 8000566:	|  /--|----> 42a6      	cmp	r6, r4
 8000568:	|  |  |  /-- d105      	bne.n	8000576 <__libc_init_array+0x2e>
 800056a:	|  |  |  |   bd70      	pop	{r4, r5, r6, pc}
 800056c:	|  |  \--|-> f855 3b04 	ldr.w	r3, [r5], #4
 8000570:	|  |     |   4798      	blx	r3
 8000572:	|  |     |   3601      	adds	r6, #1
 8000574:	\--|-----|-- e7ee      	b.n	8000554 <__libc_init_array+0xc>
 8000576:	   |     \-> f855 3b04 	ldr.w	r3, [r5], #4
 800057a:	   |         4798      	blx	r3
 800057c:	   |         3601      	adds	r6, #1
 800057e:	   \-------- e7f2      	b.n	8000566 <__libc_init_array+0x1e>
 8000580:	             05c0      	lsls	r0, r0, #23
 8000582:	             0800      	lsrs	r0, r0, #32
 8000584:	             05c0      	lsls	r0, r0, #23
 8000586:	             0800      	lsrs	r0, r0, #32
 8000588:	             05c0      	lsls	r0, r0, #23
 800058a:	             0800      	lsrs	r0, r0, #32
 800058c:	             05d4      	lsls	r4, r2, #23
 800058e:	             0800      	lsrs	r0, r0, #32

08000590 <_init>:
 8000590:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 8000592:	bf00      	nop
 8000594:	bcf8      	pop	{r3, r4, r5, r6, r7}
 8000596:	bc08      	pop	{r3}
 8000598:	469e      	mov	lr, r3
 800059a:	4770      	bx	lr

0800059c <_fini>:
 800059c:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 800059e:	bf00      	nop
 80005a0:	bcf8      	pop	{r3, r4, r5, r6, r7}
 80005a2:	bc08      	pop	{r3}
 80005a4:	469e      	mov	lr, r3
 80005a6:	4770      	bx	lr

Disassembly of section .rodata:

080005a8 <AHBPrescTable>:
	...
 80005b0:	0201      	lsls	r1, r0, #8
 80005b2:	0403      	lsls	r3, r0, #16
 80005b4:	0706      	lsls	r6, r0, #28
 80005b6:	0908      	lsrs	r0, r1, #4

080005b8 <resbits_decode>:
const uint16_t resbits_decode[] = {
 80005b8:	0fff      	lsrs	r7, r7, #31
 80005ba:	03ff      	lsls	r7, r7, #15
 80005bc:	00ff      	lsls	r7, r7, #3
 80005be:	003f      	movs	r7, r7

Disassembly of section .init_array:

080005c0 <__frame_dummy_init_array_entry>:
 80005c0:	01cd      	lsls	r5, r1, #7
 80005c2:	0800      	lsrs	r0, r0, #32
 80005c4:	026d      	lsls	r5, r5, #9
 80005c6:	0800      	lsrs	r0, r0, #32
 80005c8:	03c1      	lsls	r1, r0, #15
 80005ca:	0800      	lsrs	r0, r0, #32
 80005cc:	0401      	lsls	r1, r0, #16
 80005ce:	0800      	lsrs	r0, r0, #32
 80005d0:	04e5      	lsls	r5, r4, #19
 80005d2:	0800      	lsrs	r0, r0, #32

Disassembly of section .fini_array:

080005d4 <__do_global_dtors_aux_fini_array_entry>:
 80005d4:	01a9      	lsls	r1, r5, #6
 80005d6:	0800      	lsrs	r0, r0, #32

Disassembly of section .data:

20000000 <SystemCoreClock>:
uint32_t SystemCoreClock = 16000000;
20000000:	2400      	movs	r4, #0
20000002:	00f4      	lsls	r4, r6, #3

Disassembly of section .bss:

20000004 <__bss_start__>:
20000004:	0000      	movs	r0, r0
	...

20000008 <object.0>:
	...

20000020 <adc_sequencer_rgl>:
	...

20000094 <DELAY_CYCLES_MS>:
static uint32_t DELAY_CYCLES_MS;
20000094:	0000      	movs	r0, r0
	...

20000098 <DELAY_CYCLES_US>:
uint32_t DELAY_CYCLES_US;              
20000098:	0000      	movs	r0, r0
	...

Disassembly of section ._user_heap_stack:

2000009c <._user_heap_stack>:
	...
