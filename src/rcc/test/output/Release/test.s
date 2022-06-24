
output/Release/test.elf:     file format elf32-littlearm

SYMBOL TABLE:
08000000 l    d  .isr_vector	00000000 .isr_vector
080001a8 l    d  .text	00000000 .text
08000784 l    d  .rodata	00000000 .rodata
080007a8 l    d  .ARM.extab	00000000 .ARM.extab
080007a8 l    d  .ARM	00000000 .ARM
080007a8 l    d  .preinit_array	00000000 .preinit_array
080007a8 l    d  .init_array	00000000 .init_array
080007ac l    d  .fini_array	00000000 .fini_array
20000000 l    d  .data	00000000 .data
20000008 l    d  .bss	00000000 .bss
20000038 l    d  ._user_heap_stack	00000000 ._user_heap_stack
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
08000320 l       .text	00000000 LoopCopyDataInit
0800031a l       .text	00000000 CopyDataInit
08000332 l       .text	00000000 LoopFillZerobss
0800032e l       .text	00000000 FillZerobss
08000346 l       .text	00000000 LoopCopyCCMDataInit
08000340 l       .text	00000000 CopyCCMDataInit
08000358 l       .text	00000000 LoopFillZeroCCMbss
08000354 l       .text	00000000 FillZeroCCMbss
08000364 l       .text	00000000 LoopForever
08000394 l       .text	00000000 Infinite_Loop
00000000 l    df *ABS*	00000000 crtstuff.c
0800076c l     O .text	00000000 __EH_FRAME_BEGIN__
080001a8 l     F .text	00000000 __do_global_dtors_aux
20000008 l       .bss	00000001 completed.1
080007ac l     O .fini_array	00000000 __do_global_dtors_aux_fini_array_entry
080001cc l     F .text	00000000 frame_dummy
2000000c l       .bss	00000018 object.0
080007a8 l     O .init_array	00000000 __frame_dummy_init_array_entry
00000000 l    df *ABS*	00000000 system_stm32f4xx.c
00000000 l    df *ABS*	00000000 main.c
00000000 l    df *ABS*	00000000 rcc.c
20000024 l     O .bss	0000000c pll_parameters
00000000 l    df *ABS*	00000000 flash.c
00000000 l    df *ABS*	00000000 delay.c
20000030 l     O .bss	00000004 DELAY_CYCLES_MS
00000000 l    df *ABS*	00000000 init.c
00000000 l    df *ABS*	00000000 crti.o
00000000 l    df *ABS*	00000000 crtn.o
00000000 l    df *ABS*	00000000 
080007ac l       .init_array	00000000 __init_array_end
080007a8 l       .preinit_array	00000000 __preinit_array_end
080007a8 l       .init_array	00000000 __init_array_start
080007a8 l       .preinit_array	00000000 __preinit_array_start
08000394  w    F .text	00000002 RTC_Alarm_IRQHandler
08000394  w    F .text	00000002 HASH_RNG_IRQHandler
08000394  w    F .text	00000002 EXTI2_IRQHandler
08000394  w    F .text	00000002 TIM8_CC_IRQHandler
08000394  w    F .text	00000002 DebugMon_Handler
10000000 g       .ccmbss	00000000 _eccmbss
080004d0 g     F .text	000000d8 rcc_pll_param_cpte
08000394  w    F .text	00000002 TIM1_CC_IRQHandler
08000394  w    F .text	00000002 DMA2_Stream5_IRQHandler
08000394  w    F .text	00000002 HardFault_Handler
08000394  w    F .text	00000002 DMA1_Stream5_IRQHandler
00000400 g       *ABS*	00000000 _Min_Stack_Size
08000394  w    F .text	00000002 SysTick_Handler
08000394  w    F .text	00000002 PVD_IRQHandler
08000394  w    F .text	00000002 SDIO_IRQHandler
08000394  w    F .text	00000002 TAMP_STAMP_IRQHandler
080007b0 g       *ABS*	00000000 _sidata
08000394  w    F .text	00000002 PendSV_Handler
08000394  w    F .text	00000002 NMI_Handler
080007a8 g       .ARM	00000000 __exidx_end
08000394  w    F .text	00000002 CAN2_RX1_IRQHandler
08000394  w    F .text	00000002 EXTI3_IRQHandler
08000394  w    F .text	00000002 TIM8_TRG_COM_TIM14_IRQHandler
08000394  w    F .text	00000002 TIM1_UP_TIM10_IRQHandler
08000784 g       .text	00000000 _etext
20000008 g       .bss	00000000 _sbss
08000394  w    F .text	00000002 TIM8_UP_TIM13_IRQHandler
08000394  w    F .text	00000002 I2C3_ER_IRQHandler
08000394  w    F .text	00000002 LCD_TFT_IRQHandler
08000394  w    F .text	00000002 EXTI0_IRQHandler
08000394  w    F .text	00000002 I2C2_EV_IRQHandler
08000394  w    F .text	00000002 DMA1_Stream2_IRQHandler
08000394  w    F .text	00000002 CAN1_RX0_IRQHandler
08000394  w    F .text	00000002 FPU_IRQHandler
20000000 g     O .data	00000004 SystemCoreClock
08000394  w    F .text	00000002 OTG_HS_WKUP_IRQHandler
08000394  w    F .text	00000002 UsageFault_Handler
08000394  w    F .text	00000002 CAN2_SCE_IRQHandler
08000394  w    F .text	00000002 DMA2_Stream2_IRQHandler
20000008 g       .bss	00000000 __bss_start__
20000000 g       .data	00000000 _sdata
08000394  w    F .text	00000002 SPI1_IRQHandler
08000394  w    F .text	00000002 TIM6_DAC_IRQHandler
08000394  w    F .text	00000002 TIM1_BRK_TIM9_IRQHandler
08000394  w    F .text	00000002 DCMI_IRQHandler
08000394  w    F .text	00000002 CAN2_RX0_IRQHandler
10000000 g       .ccmdata	00000000 _sccmdata
080007a8 g       .ARM	00000000 __exidx_start
08000394  w    F .text	00000002 DMA2_Stream3_IRQHandler
08000724 g     F .text	00000048 __libc_init_array
08000398 g     F .text	00000138 rcc_sysclk_select
40024000 g       .bram	00000000 _sbram
10000000 g       .ccmbss	00000000 _sccmbss
08000394  w    F .text	00000002 USART6_IRQHandler
0800076c g     F .text	00000000 _init
08000394  w    F .text	00000002 USART3_IRQHandler
08000394  w    F .text	00000002 CRYP_IRQHandler
20000038 g       .bss	00000000 _ebss
08000308  w    F .text	0000005e Reset_Handler
08000394  w    F .text	00000002 CAN1_RX1_IRQHandler
08000394  w    F .text	00000002 UART5_IRQHandler
08000394  w    F .text	00000002 DMA2_Stream0_IRQHandler
08000600 g     F .text	000000d0 flash_acr_config_auto
08000394  w    F .text	00000002 TIM4_IRQHandler
08000394  w    F .text	00000002 I2C1_EV_IRQHandler
08000394  w    F .text	00000002 DMA1_Stream6_IRQHandler
08000394  w    F .text	00000002 DMA1_Stream1_IRQHandler
08000394  w    F .text	00000002 UART4_IRQHandler
20000038 g       .bss	00000000 __bss_end__
08000394  w    F .text	00000002 LCD_TFT_1_IRQHandler
08000394  w    F .text	00000002 TIM3_IRQHandler
080007b8 g       *ABS*	00000000 _siccmdata
08000394  w    F .text	00000002 RCC_IRQHandler
08000394  w    F .text	00000002 TIM8_BRK_TIM12_IRQHandler
00000000 g       *ABS*	00000000 _Min_Heap_Size
08000394 g       .text	00000002 Default_Handler
080006d0 g     F .text	0000003c delay_init
08000798 g     O .rodata	00000010 AHBPrescTable
08000394  w    F .text	00000002 EXTI15_10_IRQHandler
08000394  w    F .text	00000002 ADC_IRQHandler
08000394  w    F .text	00000002 DMA1_Stream7_IRQHandler
08000394  w    F .text	00000002 TIM7_IRQHandler
08000394  w    F .text	00000002 CAN2_TX_IRQHandler
08000394  w    F .text	00000002 TIM5_IRQHandler
08000394  w    F .text	00000002 DMA2_Stream7_IRQHandler
08000394  w    F .text	00000002 I2C3_EV_IRQHandler
20000034 g     O .bss	00000004 DELAY_CYCLES_US
08000394  w    F .text	00000002 EXTI9_5_IRQHandler
08000394  w    F .text	00000002 RTC_WKUP_IRQHandler
08000394  w    F .text	00000002 ETH_WKUP_IRQHandler
080005ec g     F .text	00000014 rcc_pll_param_clr
080005a8 g     F .text	00000044 rcc_pll_param_set
08000394  w    F .text	00000002 SPI2_IRQHandler
08000394  w    F .text	00000002 OTG_HS_EP1_IN_IRQHandler
08000394  w    F .text	00000002 MemManage_Handler
0800026c g     F .text	0000009c main
0800070c g     F .text	00000018 delay_ms
08000394  w    F .text	00000002 DMA1_Stream0_IRQHandler
08000394  w    F .text	00000002 CAN1_TX_IRQHandler
08000394  w    F .text	00000002 SVC_Handler
08000394  w    F .text	00000002 EXTI4_IRQHandler
080001e8 g     F .text	00000014 SystemInit
08000778 g     F .text	00000000 _fini
08000394  w    F .text	00000002 FSMC_IRQHandler
20000004 g     O .data	00000004 system_clk
08000394  w    F .text	00000002 ETH_IRQHandler
08000394  w    F .text	00000002 OTG_HS_EP1_OUT_IRQHandler
08000394  w    F .text	00000002 WWDG_IRQHandler
08000394  w    F .text	00000002 TIM2_IRQHandler
08000394  w    F .text	00000002 OTG_FS_WKUP_IRQHandler
08000394  w    F .text	00000002 TIM1_TRG_COM_TIM11_IRQHandler
08000394  w    F .text	00000002 OTG_HS_IRQHandler
20020000 g       .isr_vector	00000000 _estack
08000394  w    F .text	00000002 EXTI1_IRQHandler
20000008 g       .data	00000000 _edata
08000394  w    F .text	00000002 USART2_IRQHandler
08000000 g     O .isr_vector	00000000 g_pfnVectors
080001fc g     F .text	00000070 SystemCoreClockUpdate
08000394  w    F .text	00000002 I2C2_ER_IRQHandler
08000394  w    F .text	00000002 DMA2_Stream1_IRQHandler
08000394  w    F .text	00000002 CAN1_SCE_IRQHandler
08000394  w    F .text	00000002 DMA2_Stream4_IRQHandler
40024000 g       .bram	00000000 _ebram
08000394  w    F .text	00000002 BusFault_Handler
08000394  w    F .text	00000002 USART1_IRQHandler
08000394  w    F .text	00000002 OTG_FS_IRQHandler
08000394  w    F .text	00000002 SPI3_IRQHandler
08000394  w    F .text	00000002 DMA1_Stream4_IRQHandler
08000394  w    F .text	00000002 I2C1_ER_IRQHandler
10000000 g       .ccmdata	00000000 _eccmdata
08000394  w    F .text	00000002 DMA2_Stream6_IRQHandler
08000394  w    F .text	00000002 DMA1_Stream3_IRQHandler



Disassembly of section .isr_vector:

08000000 <g_pfnVectors>:
 8000000:	0000      	movs	r0, r0
 8000002:	2002      	movs	r0, #2
 8000004:	0309      	lsls	r1, r1, #12
 8000006:	0800      	lsrs	r0, r0, #32
 8000008:	0395      	lsls	r5, r2, #14
 800000a:	0800      	lsrs	r0, r0, #32
 800000c:	0395      	lsls	r5, r2, #14
 800000e:	0800      	lsrs	r0, r0, #32
 8000010:	0395      	lsls	r5, r2, #14
 8000012:	0800      	lsrs	r0, r0, #32
 8000014:	0395      	lsls	r5, r2, #14
 8000016:	0800      	lsrs	r0, r0, #32
 8000018:	0395      	lsls	r5, r2, #14
 800001a:	0800      	lsrs	r0, r0, #32
	...
 800002c:	0395      	lsls	r5, r2, #14
 800002e:	0800      	lsrs	r0, r0, #32
 8000030:	0395      	lsls	r5, r2, #14
 8000032:	0800      	lsrs	r0, r0, #32
 8000034:	0000      	movs	r0, r0
 8000036:	0000      	movs	r0, r0
 8000038:	0395      	lsls	r5, r2, #14
 800003a:	0800      	lsrs	r0, r0, #32
 800003c:	0395      	lsls	r5, r2, #14
 800003e:	0800      	lsrs	r0, r0, #32
 8000040:	0395      	lsls	r5, r2, #14
 8000042:	0800      	lsrs	r0, r0, #32
 8000044:	0395      	lsls	r5, r2, #14
 8000046:	0800      	lsrs	r0, r0, #32
 8000048:	0395      	lsls	r5, r2, #14
 800004a:	0800      	lsrs	r0, r0, #32
 800004c:	0395      	lsls	r5, r2, #14
 800004e:	0800      	lsrs	r0, r0, #32
 8000050:	0000      	movs	r0, r0
 8000052:	0000      	movs	r0, r0
 8000054:	0395      	lsls	r5, r2, #14
 8000056:	0800      	lsrs	r0, r0, #32
 8000058:	0395      	lsls	r5, r2, #14
 800005a:	0800      	lsrs	r0, r0, #32
 800005c:	0395      	lsls	r5, r2, #14
 800005e:	0800      	lsrs	r0, r0, #32
 8000060:	0395      	lsls	r5, r2, #14
 8000062:	0800      	lsrs	r0, r0, #32
 8000064:	0395      	lsls	r5, r2, #14
 8000066:	0800      	lsrs	r0, r0, #32
 8000068:	0395      	lsls	r5, r2, #14
 800006a:	0800      	lsrs	r0, r0, #32
 800006c:	0395      	lsls	r5, r2, #14
 800006e:	0800      	lsrs	r0, r0, #32
 8000070:	0395      	lsls	r5, r2, #14
 8000072:	0800      	lsrs	r0, r0, #32
 8000074:	0395      	lsls	r5, r2, #14
 8000076:	0800      	lsrs	r0, r0, #32
 8000078:	0395      	lsls	r5, r2, #14
 800007a:	0800      	lsrs	r0, r0, #32
 800007c:	0395      	lsls	r5, r2, #14
 800007e:	0800      	lsrs	r0, r0, #32
 8000080:	0395      	lsls	r5, r2, #14
 8000082:	0800      	lsrs	r0, r0, #32
 8000084:	0395      	lsls	r5, r2, #14
 8000086:	0800      	lsrs	r0, r0, #32
 8000088:	0395      	lsls	r5, r2, #14
 800008a:	0800      	lsrs	r0, r0, #32
 800008c:	0395      	lsls	r5, r2, #14
 800008e:	0800      	lsrs	r0, r0, #32
 8000090:	0395      	lsls	r5, r2, #14
 8000092:	0800      	lsrs	r0, r0, #32
 8000094:	0395      	lsls	r5, r2, #14
 8000096:	0800      	lsrs	r0, r0, #32
 8000098:	0395      	lsls	r5, r2, #14
 800009a:	0800      	lsrs	r0, r0, #32
 800009c:	0395      	lsls	r5, r2, #14
 800009e:	0800      	lsrs	r0, r0, #32
 80000a0:	0395      	lsls	r5, r2, #14
 80000a2:	0800      	lsrs	r0, r0, #32
 80000a4:	0395      	lsls	r5, r2, #14
 80000a6:	0800      	lsrs	r0, r0, #32
 80000a8:	0395      	lsls	r5, r2, #14
 80000aa:	0800      	lsrs	r0, r0, #32
 80000ac:	0395      	lsls	r5, r2, #14
 80000ae:	0800      	lsrs	r0, r0, #32
 80000b0:	0395      	lsls	r5, r2, #14
 80000b2:	0800      	lsrs	r0, r0, #32
 80000b4:	0395      	lsls	r5, r2, #14
 80000b6:	0800      	lsrs	r0, r0, #32
 80000b8:	0395      	lsls	r5, r2, #14
 80000ba:	0800      	lsrs	r0, r0, #32
 80000bc:	0395      	lsls	r5, r2, #14
 80000be:	0800      	lsrs	r0, r0, #32
 80000c0:	0395      	lsls	r5, r2, #14
 80000c2:	0800      	lsrs	r0, r0, #32
 80000c4:	0395      	lsls	r5, r2, #14
 80000c6:	0800      	lsrs	r0, r0, #32
 80000c8:	0395      	lsls	r5, r2, #14
 80000ca:	0800      	lsrs	r0, r0, #32
 80000cc:	0395      	lsls	r5, r2, #14
 80000ce:	0800      	lsrs	r0, r0, #32
 80000d0:	0395      	lsls	r5, r2, #14
 80000d2:	0800      	lsrs	r0, r0, #32
 80000d4:	0395      	lsls	r5, r2, #14
 80000d6:	0800      	lsrs	r0, r0, #32
 80000d8:	0395      	lsls	r5, r2, #14
 80000da:	0800      	lsrs	r0, r0, #32
 80000dc:	0395      	lsls	r5, r2, #14
 80000de:	0800      	lsrs	r0, r0, #32
 80000e0:	0395      	lsls	r5, r2, #14
 80000e2:	0800      	lsrs	r0, r0, #32
 80000e4:	0395      	lsls	r5, r2, #14
 80000e6:	0800      	lsrs	r0, r0, #32
 80000e8:	0395      	lsls	r5, r2, #14
 80000ea:	0800      	lsrs	r0, r0, #32
 80000ec:	0395      	lsls	r5, r2, #14
 80000ee:	0800      	lsrs	r0, r0, #32
 80000f0:	0395      	lsls	r5, r2, #14
 80000f2:	0800      	lsrs	r0, r0, #32
 80000f4:	0395      	lsls	r5, r2, #14
 80000f6:	0800      	lsrs	r0, r0, #32
 80000f8:	0395      	lsls	r5, r2, #14
 80000fa:	0800      	lsrs	r0, r0, #32
 80000fc:	0395      	lsls	r5, r2, #14
 80000fe:	0800      	lsrs	r0, r0, #32
 8000100:	0395      	lsls	r5, r2, #14
 8000102:	0800      	lsrs	r0, r0, #32
 8000104:	0395      	lsls	r5, r2, #14
 8000106:	0800      	lsrs	r0, r0, #32
 8000108:	0395      	lsls	r5, r2, #14
 800010a:	0800      	lsrs	r0, r0, #32
 800010c:	0395      	lsls	r5, r2, #14
 800010e:	0800      	lsrs	r0, r0, #32
 8000110:	0395      	lsls	r5, r2, #14
 8000112:	0800      	lsrs	r0, r0, #32
 8000114:	0395      	lsls	r5, r2, #14
 8000116:	0800      	lsrs	r0, r0, #32
 8000118:	0395      	lsls	r5, r2, #14
 800011a:	0800      	lsrs	r0, r0, #32
 800011c:	0395      	lsls	r5, r2, #14
 800011e:	0800      	lsrs	r0, r0, #32
 8000120:	0395      	lsls	r5, r2, #14
 8000122:	0800      	lsrs	r0, r0, #32
 8000124:	0395      	lsls	r5, r2, #14
 8000126:	0800      	lsrs	r0, r0, #32
 8000128:	0395      	lsls	r5, r2, #14
 800012a:	0800      	lsrs	r0, r0, #32
 800012c:	0395      	lsls	r5, r2, #14
 800012e:	0800      	lsrs	r0, r0, #32
 8000130:	0395      	lsls	r5, r2, #14
 8000132:	0800      	lsrs	r0, r0, #32
 8000134:	0395      	lsls	r5, r2, #14
 8000136:	0800      	lsrs	r0, r0, #32
 8000138:	0395      	lsls	r5, r2, #14
 800013a:	0800      	lsrs	r0, r0, #32
 800013c:	0395      	lsls	r5, r2, #14
 800013e:	0800      	lsrs	r0, r0, #32
 8000140:	0395      	lsls	r5, r2, #14
 8000142:	0800      	lsrs	r0, r0, #32
 8000144:	0395      	lsls	r5, r2, #14
 8000146:	0800      	lsrs	r0, r0, #32
 8000148:	0395      	lsls	r5, r2, #14
 800014a:	0800      	lsrs	r0, r0, #32
 800014c:	0395      	lsls	r5, r2, #14
 800014e:	0800      	lsrs	r0, r0, #32
 8000150:	0395      	lsls	r5, r2, #14
 8000152:	0800      	lsrs	r0, r0, #32
 8000154:	0395      	lsls	r5, r2, #14
 8000156:	0800      	lsrs	r0, r0, #32
 8000158:	0395      	lsls	r5, r2, #14
 800015a:	0800      	lsrs	r0, r0, #32
 800015c:	0395      	lsls	r5, r2, #14
 800015e:	0800      	lsrs	r0, r0, #32
 8000160:	0395      	lsls	r5, r2, #14
 8000162:	0800      	lsrs	r0, r0, #32
 8000164:	0395      	lsls	r5, r2, #14
 8000166:	0800      	lsrs	r0, r0, #32
 8000168:	0395      	lsls	r5, r2, #14
 800016a:	0800      	lsrs	r0, r0, #32
 800016c:	0395      	lsls	r5, r2, #14
 800016e:	0800      	lsrs	r0, r0, #32
 8000170:	0395      	lsls	r5, r2, #14
 8000172:	0800      	lsrs	r0, r0, #32
 8000174:	0395      	lsls	r5, r2, #14
 8000176:	0800      	lsrs	r0, r0, #32
 8000178:	0395      	lsls	r5, r2, #14
 800017a:	0800      	lsrs	r0, r0, #32
 800017c:	0395      	lsls	r5, r2, #14
 800017e:	0800      	lsrs	r0, r0, #32
 8000180:	0395      	lsls	r5, r2, #14
 8000182:	0800      	lsrs	r0, r0, #32
 8000184:	0395      	lsls	r5, r2, #14
 8000186:	0800      	lsrs	r0, r0, #32
	...
 80001a0:	0395      	lsls	r5, r2, #14
 80001a2:	0800      	lsrs	r0, r0, #32
 80001a4:	0395      	lsls	r5, r2, #14
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
 80001c0:	       0008      	movs	r0, r1
 80001c2:	       2000      	movs	r0, #0
 80001c4:	       0000      	movs	r0, r0
 80001c6:	       0000      	movs	r0, r0
 80001c8:	       076c      	lsls	r4, r5, #29
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
 80001e0:	    000c      	movs	r4, r1
 80001e2:	    2000      	movs	r0, #0
 80001e4:	    076c      	lsls	r4, r5, #29
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
 8000260:	          0798      	lsls	r0, r3, #30
 8000262:	          0800      	lsrs	r0, r0, #32
 8000264:	          0000      	movs	r0, r0
 8000266:	          2000      	movs	r0, #0
 8000268:	          1200      	asrs	r0, r0, #8
 800026a:	          007a      	lsls	r2, r7, #1

0800026c <main>:
#include "system.h"
#include "rcc.h"
#include "delay.h"

int main (void)
{
 800026c:	    b508      	push	{r3, lr}
    /* SystemCoreClock should be HSE value ----------------|*/
    /* 8 MHz                                               |*/
    rcc_sysclk_select(RCC_SYSCLK_HSE);                 /*<-|*/                  /*[ok]*/
 800026e:	    f44f 3080 	mov.w	r0, #65536	; 0x10000
 8000272:	    f000 f891 	bl	8000398 <rcc_sysclk_select>

    /* SystemCoreClock should be PLL value ----------------|*/
    /* 168 MHz                                             |*/
    rcc_pll_param_cpte(168, RCC_PLLCLK_HSE);             /*|*/
 8000276:	    f44f 0180 	mov.w	r1, #4194304	; 0x400000
 800027a:	    20a8      	movs	r0, #168	; 0xa8
 800027c:	    f000 f928 	bl	80004d0 <rcc_pll_param_cpte>
    rcc_pll_param_clr();                                 /*|*/
 8000280:	    f000 f9b4 	bl	80005ec <rcc_pll_param_clr>
    rcc_pll_param_set();                                 /*|*/
 8000284:	    f000 f990 	bl	80005a8 <rcc_pll_param_set>
    rcc_sysclk_select(RCC_SYSCLK_PLL | RCC_SYSCLK_HSE);/*<-|*/                  /*[ok]*/
 8000288:	    481d      	ldr	r0, [pc, #116]	; (8000300 <main+0x94>)
 800028a:	    f000 f885 	bl	8000398 <rcc_sysclk_select>

    /* SystemCoreClock should be HSI value ----------------|*/
    /* 16 MHz                                              |*/
    rcc_sysclk_select(RCC_SYSCLK_HSI);                 /*<-|*/                  /*[ok]*/
 800028e:	    2001      	movs	r0, #1
 8000290:	    f000 f882 	bl	8000398 <rcc_sysclk_select>
 */
__FORCE_INLINE void rcc_pll_param_cpte_set(uint8_t pll_clk_out, 
    rcc_pllclk_t pll_clk_in
)
{
    rcc_pll_param_cpte(pll_clk_out, pll_clk_in);
 8000294:	    f44f 0180 	mov.w	r1, #4194304	; 0x400000
 8000298:	    2064      	movs	r0, #100	; 0x64
 800029a:	    f000 f919 	bl	80004d0 <rcc_pll_param_cpte>
    rcc_pll_param_clr();
 800029e:	    f000 f9a5 	bl	80005ec <rcc_pll_param_clr>
    rcc_pll_param_set();
 80002a2:	    f000 f981 	bl	80005a8 <rcc_pll_param_set>

    /* SystemCoreClock should be PLL value ----------------|*/
    /* 100 MHz                                             |*/
    rcc_pll_param_cpte_set(100, RCC_PLLCLK_HSE);         /*|*/
    rcc_sysclk_select(RCC_SYSCLK_PLL | RCC_SYSCLK_HSE);/*<-|*/                  /*[ok]*/
 80002a6:	    4816      	ldr	r0, [pc, #88]	; (8000300 <main+0x94>)
 80002a8:	    f000 f876 	bl	8000398 <rcc_sysclk_select>

    /* SystemCoreClock should be HSE value ----------------|*/
    /* 8 MHz                                               |*/
    rcc_sysclk_select(RCC_SYSCLK_HSE);                 /*<-|*/                  /*[ok]*/
 80002ac:	    f44f 3080 	mov.w	r0, #65536	; 0x10000
 80002b0:	    f000 f872 	bl	8000398 <rcc_sysclk_select>
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_en_ahb1(rcc_ahb1_t mask)
{
    RCC->AHB1ENR |= mask;
 80002b4:	    4b13      	ldr	r3, [pc, #76]	; (8000304 <main+0x98>)
 80002b6:	    6b1a      	ldr	r2, [r3, #48]	; 0x30
 80002b8:	    f042 0201 	orr.w	r2, r2, #1
 80002bc:	    631a      	str	r2, [r3, #48]	; 0x30
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_dis_ahb1(rcc_ahb1_t mask)
{
    RCC->AHB1ENR &= ~mask;
 80002be:	    6b1a      	ldr	r2, [r3, #48]	; 0x30
 80002c0:	    f022 0201 	bic.w	r2, r2, #1
 80002c4:	    631a      	str	r2, [r3, #48]	; 0x30
    RCC->AHB1ENR |= mask;
 80002c6:	    6b1a      	ldr	r2, [r3, #48]	; 0x30
 80002c8:	    f042 0202 	orr.w	r2, r2, #2
 80002cc:	    631a      	str	r2, [r3, #48]	; 0x30
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_rst_ahb1(rcc_ahb1_t mask)
{
    RCC->AHB1RSTR |= mask;
 80002ce:	    691a      	ldr	r2, [r3, #16]
 80002d0:	    f042 0202 	orr.w	r2, r2, #2
 80002d4:	    611a      	str	r2, [r3, #16]
    RCC->AHB1RSTR &= ~mask;
 80002d6:	    691a      	ldr	r2, [r3, #16]
 80002d8:	    f022 0202 	bic.w	r2, r2, #2
 80002dc:	    611a      	str	r2, [r3, #16]
    RCC->AHB1ENR &= ~mask;
 80002de:	    6b1a      	ldr	r2, [r3, #48]	; 0x30
 80002e0:	    f022 0202 	bic.w	r2, r2, #2
 80002e4:	    631a      	str	r2, [r3, #48]	; 0x30
    RCC->AHB1ENR |= mask;
 80002e6:	    6b1a      	ldr	r2, [r3, #48]	; 0x30
 80002e8:	    f042 0203 	orr.w	r2, r2, #3
 80002ec:	    631a      	str	r2, [r3, #48]	; 0x30
    RCC->AHB1ENR &= ~mask;
 80002ee:	    6b1a      	ldr	r2, [r3, #48]	; 0x30
 80002f0:	    f022 0203 	bic.w	r2, r2, #3
 80002f4:	    631a      	str	r2, [r3, #48]	; 0x30
    /* GPIOA & GPIOB clock should be disabled -----------------------|*/
    rcc_clk_dis_ahb1(RCC_AHB1_GPIOA | RCC_AHB1_GPIOB);           /*<-|*/        /*[ok]*/

    while(1)
    {
        delay_ms(1);
 80002f6:	/-> 2001      	movs	r0, #1
 80002f8:	|   f000 fa08 	bl	800070c <delay_ms>
    while(1)
 80002fc:	\-- e7fb      	b.n	80002f6 <main+0x8a>
 80002fe:	    bf00      	nop
 8000300:	    0000      	movs	r0, r0
 8000302:	    0101      	lsls	r1, r0, #4
 8000304:	    3800      	subs	r0, #0
 8000306:	    4002      	ands	r2, r0

08000308 <Reset_Handler>:
 8000308:	4817      	ldr	r0, [pc, #92]	; (8000368 <LoopForever+0x4>)
 800030a:	4685      	mov	sp, r0
 800030c:	f7ff ff6c 	bl	80001e8 <SystemInit>
 8000310:	4816      	ldr	r0, [pc, #88]	; (800036c <LoopForever+0x8>)
 8000312:	4917      	ldr	r1, [pc, #92]	; (8000370 <LoopForever+0xc>)
 8000314:	4a17      	ldr	r2, [pc, #92]	; (8000374 <LoopForever+0x10>)
 8000316:	2300      	movs	r3, #0
 8000318:	e002      	b.n	8000320 <LoopCopyDataInit>

0800031a <CopyDataInit>:
 800031a:	58d4      	ldr	r4, [r2, r3]
 800031c:	50c4      	str	r4, [r0, r3]
 800031e:	3304      	adds	r3, #4

08000320 <LoopCopyDataInit>:
 8000320:	18c4      	adds	r4, r0, r3
 8000322:	428c      	cmp	r4, r1
 8000324:	d3f9      	bcc.n	800031a <CopyDataInit>
 8000326:	4a14      	ldr	r2, [pc, #80]	; (8000378 <LoopForever+0x14>)
 8000328:	4c14      	ldr	r4, [pc, #80]	; (800037c <LoopForever+0x18>)
 800032a:	2300      	movs	r3, #0
 800032c:	e001      	b.n	8000332 <LoopFillZerobss>

0800032e <FillZerobss>:
 800032e:	6013      	str	r3, [r2, #0]
 8000330:	3204      	adds	r2, #4

08000332 <LoopFillZerobss>:
 8000332:	42a2      	cmp	r2, r4
 8000334:	d3fb      	bcc.n	800032e <FillZerobss>
 8000336:	4812      	ldr	r0, [pc, #72]	; (8000380 <LoopForever+0x1c>)
 8000338:	4912      	ldr	r1, [pc, #72]	; (8000384 <LoopForever+0x20>)
 800033a:	4a13      	ldr	r2, [pc, #76]	; (8000388 <LoopForever+0x24>)
 800033c:	2300      	movs	r3, #0
 800033e:	e002      	b.n	8000346 <LoopCopyCCMDataInit>

08000340 <CopyCCMDataInit>:
 8000340:	58d4      	ldr	r4, [r2, r3]
 8000342:	50c4      	str	r4, [r0, r3]
 8000344:	3304      	adds	r3, #4

08000346 <LoopCopyCCMDataInit>:
 8000346:	18c4      	adds	r4, r0, r3
 8000348:	428c      	cmp	r4, r1
 800034a:	d3f9      	bcc.n	8000340 <CopyCCMDataInit>
 800034c:	4a0f      	ldr	r2, [pc, #60]	; (800038c <LoopForever+0x28>)
 800034e:	4c10      	ldr	r4, [pc, #64]	; (8000390 <LoopForever+0x2c>)
 8000350:	2300      	movs	r3, #0
 8000352:	e001      	b.n	8000358 <LoopFillZeroCCMbss>

08000354 <FillZeroCCMbss>:
 8000354:	6013      	str	r3, [r2, #0]
 8000356:	3204      	adds	r2, #4

08000358 <LoopFillZeroCCMbss>:
 8000358:	42a2      	cmp	r2, r4
 800035a:	d3fb      	bcc.n	8000354 <FillZeroCCMbss>
 800035c:	f000 f9e2 	bl	8000724 <__libc_init_array>
 8000360:	f7ff ff84 	bl	800026c <main>

08000364 <LoopForever>:
 8000364:	/-- e7fe      	b.n	8000364 <LoopForever>
 8000366:	    0000      	movs	r0, r0
 8000368:	    0000      	movs	r0, r0
 800036a:	    2002      	movs	r0, #2
 800036c:	    0000      	movs	r0, r0
 800036e:	    2000      	movs	r0, #0
 8000370:	    0008      	movs	r0, r1
 8000372:	    2000      	movs	r0, #0
 8000374:	    07b0      	lsls	r0, r6, #30
 8000376:	    0800      	lsrs	r0, r0, #32
 8000378:	    0008      	movs	r0, r1
 800037a:	    2000      	movs	r0, #0
 800037c:	    0038      	movs	r0, r7
 800037e:	    2000      	movs	r0, #0
 8000380:	    0000      	movs	r0, r0
 8000382:	    1000      	asrs	r0, r0, #32
 8000384:	    0000      	movs	r0, r0
 8000386:	    1000      	asrs	r0, r0, #32
 8000388:	    07b8      	lsls	r0, r7, #30
 800038a:	    0800      	lsrs	r0, r0, #32
 800038c:	    0000      	movs	r0, r0
 800038e:	    1000      	asrs	r0, r0, #32
 8000390:	    0000      	movs	r0, r0
 8000392:	    1000      	asrs	r0, r0, #32

08000394 <ADC_IRQHandler>:
 8000394:	/-- e7fe      	b.n	8000394 <ADC_IRQHandler>
	...

08000398 <rcc_sysclk_select>:
static struct pll_s pll_parameters;

uint32_t system_clk = HSI_VALUE;

void rcc_sysclk_select(rcc_sysclk_t source)
{
 8000398:	                      e92d 43f0 	stmdb	sp!, {r4, r5, r6, r7, r8, r9, lr}
    uint32_t RCC_CR_BIT_RD = 0; /* Target ready bit on RCC_CR register */
    uint32_t pll_request;
    uint32_t cfgr_switch;
    uint32_t cfgr_ready;

    const uint32_t APB_PRESCALER[] = {
 800039c:	                      4f45      	ldr	r7, [pc, #276]	; (80004b4 <rcc_sysclk_select+0x11c>)
        RCC_CR_BIT_RD = RCC_CR_HSIRDY;
        cfgr_switch = 0;
        break;
    }
    /* Power on the target clock (HSI or HSE) */
    RCC->CR |= source;
 800039e:	                      4c46      	ldr	r4, [pc, #280]	; (80004b8 <rcc_sysclk_select+0x120>)
    source &= ~RCC_CR_PLLON;
 80003a0:	                      f020 7980 	bic.w	r9, r0, #16777216	; 0x1000000
{
 80003a4:	                      4605      	mov	r5, r0
    pll_request = source & RCC_CR_PLLON;
 80003a6:	                      f000 7880 	and.w	r8, r0, #16777216	; 0x1000000
    const uint32_t APB_PRESCALER[] = {
 80003aa:	                      cf0f      	ldmia	r7!, {r0, r1, r2, r3}
{
 80003ac:	                      b087      	sub	sp, #28
    const uint32_t APB_PRESCALER[] = {
 80003ae:	                      f10d 0e04 	add.w	lr, sp, #4
 80003b2:	                      e8ae 000f 	stmia.w	lr!, {r0, r1, r2, r3}
 80003b6:	                      683b      	ldr	r3, [r7, #0]
 80003b8:	                      f8ce 3000 	str.w	r3, [lr]
    RCC->CR |= source;
 80003bc:	                      6823      	ldr	r3, [r4, #0]
        cfgr_switch = 0;
 80003be:	                      f5b9 3f80 	cmp.w	r9, #65536	; 0x10000
    RCC->CR |= source;
 80003c2:	                      ea43 0309 	orr.w	r3, r3, r9
        cfgr_switch = 0;
 80003c6:	                      bf0b      	itete	eq
 80003c8:	                      2601      	moveq	r6, #1
 80003ca:	                      2600      	movne	r6, #0
 80003cc:	                      f44f 3c00 	moveq.w	r12, #131072	; 0x20000
 80003d0:	                      f04f 0c02 	movne.w	r12, #2
    RCC->CR |= source;
 80003d4:	                      6023      	str	r3, [r4, #0]
    /* Wait for stable target clock (rdy flag == 1) */
    while ((RCC->CR & RCC_CR_BIT_RD) == 0);
 80003d6:	                  /-> 6823      	ldr	r3, [r4, #0]
 80003d8:	                  |   ea13 0f0c 	tst.w	r3, r12
 80003dc:	                  \-- d0fb      	beq.n	80003d6 <rcc_sysclk_select+0x3e>
    /* Verify PLL target and power on it if required */
    if(pll_request)
 80003de:	                      f1b8 0f00 	cmp.w	r8, #0
 80003e2:	/-------------------- d04a      	beq.n	800047a <rcc_sysclk_select+0xe2>
    {
        cfgr_switch = 2;
        RCC->CR |= pll_request;
 80003e4:	|                     6823      	ldr	r3, [r4, #0]
        /* Wait for stable pll clock (rdy flag == 1) */
        while ((RCC->CR & RCC_CR_PLLRDY) == 0);
 80003e6:	|                     4a34      	ldr	r2, [pc, #208]	; (80004b8 <rcc_sysclk_select+0x120>)
        RCC->CR |= pll_request;
 80003e8:	|                     ea43 0308 	orr.w	r3, r3, r8
 80003ec:	|                     6023      	str	r3, [r4, #0]
        while ((RCC->CR & RCC_CR_PLLRDY) == 0);
 80003ee:	|                 /-> 6813      	ldr	r3, [r2, #0]
 80003f0:	|                 |   019b      	lsls	r3, r3, #6
 80003f2:	|                 \-- d5fc      	bpl.n	80003ee <rcc_sysclk_select+0x56>
        /* Set maximus AHB/APB bus clocks */
        RCC->CFGR &= ~((0x7 << RCC_CFGR_PPRE2_Pos) | (0x7 << RCC_CFGR_PPRE1_Pos) 
 80003f4:	|                     6893      	ldr	r3, [r2, #8]
            | (0xF << RCC_CFGR_HPRE_Pos));
        RCC->CFGR |= (APB_PRESCALER[pll_parameters.ppre2] << RCC_CFGR_PPRE2_Pos)
 80003f6:	|                     4831      	ldr	r0, [pc, #196]	; (80004bc <rcc_sysclk_select+0x124>)
        break;
    case 1:
        system_clk = HSE_VALUE;
        break;
    case 2:
        system_clk = pll_parameters.freq_o;
 80003f8:	|                     f8df 80d0 	ldr.w	r8, [pc, #208]	; 80004cc <rcc_sysclk_select+0x134>
        RCC->CFGR &= ~((0x7 << RCC_CFGR_PPRE2_Pos) | (0x7 << RCC_CFGR_PPRE1_Pos) 
 80003fc:	|                     f423 437c 	bic.w	r3, r3, #64512	; 0xfc00
 8000400:	|                     f023 03f0 	bic.w	r3, r3, #240	; 0xf0
 8000404:	|                     6093      	str	r3, [r2, #8]
            | (APB_PRESCALER[pll_parameters.ppre1] << RCC_CFGR_PPRE1_Pos);
 8000406:	|                     7883      	ldrb	r3, [r0, #2]
        RCC->CFGR |= (APB_PRESCALER[pll_parameters.ppre2] << RCC_CFGR_PPRE2_Pos)
 8000408:	|                     78c1      	ldrb	r1, [r0, #3]
        system_clk = pll_parameters.freq_o;
 800040a:	|                     6840      	ldr	r0, [r0, #4]
            | (APB_PRESCALER[pll_parameters.ppre1] << RCC_CFGR_PPRE1_Pos);
 800040c:	|                     ac06      	add	r4, sp, #24
 800040e:	|                     095b      	lsrs	r3, r3, #5
 8000410:	|                     eb04 0383 	add.w	r3, r4, r3, lsl #2
        RCC->CFGR |= (APB_PRESCALER[pll_parameters.ppre2] << RCC_CFGR_PPRE2_Pos)
 8000414:	|                     f001 0107 	and.w	r1, r1, #7
 8000418:	|                     eb04 0181 	add.w	r1, r4, r1, lsl #2
            | (APB_PRESCALER[pll_parameters.ppre1] << RCC_CFGR_PPRE1_Pos);
 800041c:	|                     f853 3c14 	ldr.w	r3, [r3, #-20]
        RCC->CFGR |= (APB_PRESCALER[pll_parameters.ppre2] << RCC_CFGR_PPRE2_Pos)
 8000420:	|                     f851 4c14 	ldr.w	r4, [r1, #-20]
 8000424:	|                     6891      	ldr	r1, [r2, #8]
            | (APB_PRESCALER[pll_parameters.ppre1] << RCC_CFGR_PPRE1_Pos);
 8000426:	|                     029b      	lsls	r3, r3, #10
 8000428:	|                     ea43 3344 	orr.w	r3, r3, r4, lsl #13
        RCC->CFGR |= (APB_PRESCALER[pll_parameters.ppre2] << RCC_CFGR_PPRE2_Pos)
 800042c:	|                     430b      	orrs	r3, r1
 800042e:	|                     6093      	str	r3, [r2, #8]
        break;
 8000430:	|                     2408      	movs	r4, #8
        system_clk = pll_parameters.freq_o;
 8000432:	|                     f8c8 0000 	str.w	r0, [r8]
        break;
 8000436:	|                     2602      	movs	r6, #2
        break;
    }

    /* Referer to Relation between CPU clock frequency and Flash memory read 
       time [increasing/decreasing the CPU Freq.] pag. 81 - Refrence Manual*/
    if (system_clk > SystemCoreClock)
 8000438:	|  /----------------> 4f21      	ldr	r7, [pc, #132]	; (80004c0 <rcc_sysclk_select+0x128>)
 800043a:	|  |                  6839      	ldr	r1, [r7, #0]
 800043c:	|  |                  4281      	cmp	r1, r0
 800043e:	|  |     /----------- d328      	bcc.n	8000492 <rcc_sysclk_select+0xfa>
        flash_acr_config_auto(system_clk);
    }

    cfgr_ready = (cfgr_switch<<RCC_CFGR_SWS_Pos);
    /* Switch clock from system */
    RCC->CFGR &= ~0x3; RCC->CFGR |= cfgr_switch;
 8000440:	|  |  /--|----------> 4a1d      	ldr	r2, [pc, #116]	; (80004b8 <rcc_sysclk_select+0x120>)
 8000442:	|  |  |  |            6893      	ldr	r3, [r2, #8]
 8000444:	|  |  |  |            f023 0303 	bic.w	r3, r3, #3
 8000448:	|  |  |  |            6093      	str	r3, [r2, #8]
 800044a:	|  |  |  |            6893      	ldr	r3, [r2, #8]
 800044c:	|  |  |  |            431e      	orrs	r6, r3
 800044e:	|  |  |  |            6096      	str	r6, [r2, #8]
    /* Wait for the system complete the switch */
    while ((RCC->CFGR & cfgr_ready) != cfgr_ready);
 8000450:	|  |  |  |        /-> 6893      	ldr	r3, [r2, #8]
 8000452:	|  |  |  |        |   ea34 0303 	bics.w	r3, r4, r3
 8000456:	|  |  |  |        \-- d1fb      	bne.n	8000450 <rcc_sysclk_select+0xb8>

    if (system_clk < SystemCoreClock)
 8000458:	|  |  |  |            4288      	cmp	r0, r1
 800045a:	|  |  |  |     /----- d320      	bcc.n	800049e <rcc_sysclk_select+0x106>
#endif /* HSI_VALUE */


__FORCE_INLINE void sys_clk_update()
{
    SystemCoreClockUpdate();
 800045c:	|  |  |  |  /--|----> f7ff fece 	bl	80001fc <SystemCoreClockUpdate>
    delay_init();
 8000460:	|  |  |  |  |  |      f000 f936 	bl	80006d0 <delay_init>
    }

    /* Update the internal monitor clock variable */
    sys_clk_update();
    /* Shutdown the other source clocks */
    RCC->CR &= ((RCC_CR_PLLON | RCC_CR_HSEON| RCC_CR_HSION) & (source | pll_request));
 8000464:	|  |  |  |  |  |      4a14      	ldr	r2, [pc, #80]	; (80004b8 <rcc_sysclk_select+0x120>)
 8000466:	|  |  |  |  |  |      6813      	ldr	r3, [r2, #0]
 8000468:	|  |  |  |  |  |      402b      	ands	r3, r5
 800046a:	|  |  |  |  |  |      f003 3301 	and.w	r3, r3, #16843009	; 0x1010101
 800046e:	|  |  |  |  |  |      f423 7380 	bic.w	r3, r3, #256	; 0x100
 8000472:	|  |  |  |  |  |      6013      	str	r3, [r2, #0]
}
 8000474:	|  |  |  |  |  |      b007      	add	sp, #28
 8000476:	|  |  |  |  |  |      e8bd 83f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, r9, pc}
    switch (cfgr_switch)
 800047a:	\--|--|--|--|--|----> 2e01      	cmp	r6, #1
 800047c:	   |  |  |  |  |  /-- d012      	beq.n	80004a4 <rcc_sysclk_select+0x10c>
    if (system_clk > SystemCoreClock)
 800047e:	   |  |  |  |  |  |   4f10      	ldr	r7, [pc, #64]	; (80004c0 <rcc_sysclk_select+0x128>)
        system_clk = HSI_VALUE;
 8000480:	   |  |  |  |  |  |   4810      	ldr	r0, [pc, #64]	; (80004c4 <rcc_sysclk_select+0x12c>)
    if (system_clk > SystemCoreClock)
 8000482:	   |  |  |  |  |  |   6839      	ldr	r1, [r7, #0]
        system_clk = HSI_VALUE;
 8000484:	   |  |  |  |  |  |   f8df 8044 	ldr.w	r8, [pc, #68]	; 80004cc <rcc_sysclk_select+0x134>
    if (system_clk > SystemCoreClock)
 8000488:	   |  |  |  |  |  |   4281      	cmp	r1, r0
        break;
 800048a:	   |  |  |  |  |  |   4634      	mov	r4, r6
        system_clk = HSI_VALUE;
 800048c:	   |  |  |  |  |  |   f8c8 0000 	str.w	r0, [r8]
    if (system_clk > SystemCoreClock)
 8000490:	   |  +--|--|--|--|-- d2d6      	bcs.n	8000440 <rcc_sysclk_select+0xa8>
        flash_acr_config_auto(system_clk);
 8000492:	   |  |  \--|--|--|-> f000 f8b5 	bl	8000600 <flash_acr_config_auto>
    if (system_clk < SystemCoreClock)
 8000496:	   |  |     |  |  |   f8d8 0000 	ldr.w	r0, [r8]
 800049a:	   |  |     |  |  |   6839      	ldr	r1, [r7, #0]
 800049c:	   |  \-----|--|--|-- e7d0      	b.n	8000440 <rcc_sysclk_select+0xa8>
        flash_acr_config_auto(system_clk);
 800049e:	   |        |  \--|-> f000 f8af 	bl	8000600 <flash_acr_config_auto>
 80004a2:	   |        \-----|-- e7db      	b.n	800045c <rcc_sysclk_select+0xc4>
        system_clk = HSE_VALUE;
 80004a4:	   |              \-> f8df 8024 	ldr.w	r8, [pc, #36]	; 80004cc <rcc_sysclk_select+0x134>
 80004a8:	   |                  4807      	ldr	r0, [pc, #28]	; (80004c8 <rcc_sysclk_select+0x130>)
 80004aa:	   |                  f8c8 0000 	str.w	r0, [r8]
        break;
 80004ae:	   |                  2404      	movs	r4, #4
 80004b0:	   \----------------- e7c2      	b.n	8000438 <rcc_sysclk_select+0xa0>
 80004b2:	                      bf00      	nop
 80004b4:	                      0784      	lsls	r4, r0, #30
 80004b6:	                      0800      	lsrs	r0, r0, #32
 80004b8:	                      3800      	subs	r0, #0
 80004ba:	                      4002      	ands	r2, r0
 80004bc:	                      0024      	movs	r4, r4
 80004be:	                      2000      	movs	r0, #0
 80004c0:	                      0000      	movs	r0, r0
 80004c2:	                      2000      	movs	r0, #0
 80004c4:	                      2400      	movs	r4, #0
 80004c6:	                      00f4      	lsls	r4, r6, #3
 80004c8:	                      1200      	asrs	r0, r0, #8
 80004ca:	                      007a      	lsls	r2, r7, #1
 80004cc:	                      0004      	movs	r4, r0
 80004ce:	                      2000      	movs	r0, #0

080004d0 <rcc_pll_param_cpte>:

void rcc_pll_param_cpte(uint8_t pll_clk_out, rcc_pllclk_t pll_clk_in)
{
 80004d0:	          b530      	push	{r4, r5, lr}
    pll_parameters.source = pll_clk_in;
 80004d2:	          4c30      	ldr	r4, [pc, #192]	; (8000594 <rcc_pll_param_cpte+0xc4>)
    pll_parameters.freq_o = pll_clk_out * 1000000;
 80004d4:	          4a30      	ldr	r2, [pc, #192]	; (8000598 <rcc_pll_param_cpte+0xc8>)
    /* Determinate PLL clock */
    uint32_t __pll_clk_in = (pll_clk_in == RCC_PLLCLK_HSE) ? HSE_VALUE : HSI_VALUE;
    __pll_clk_in /= 1000000UL;

    /* Configure de max value to pll_p parameter */
    pll_parameters.p = 3; /* Bit value for request pll_p */
 80004d6:	          6825      	ldr	r5, [r4, #0]
    const uint8_t pll_p[] = /* Decode table for PLL_P values */
 80004d8:	          4b30      	ldr	r3, [pc, #192]	; (800059c <rcc_pll_param_cpte+0xcc>)
{
 80004da:	          b083      	sub	sp, #12
    uint32_t __pll_clk_in = (pll_clk_in == RCC_PLLCLK_HSE) ? HSE_VALUE : HSI_VALUE;
 80004dc:	          f5b1 0f80 	cmp.w	r1, #4194304	; 0x400000
    pll_parameters.freq_o = pll_clk_out * 1000000;
 80004e0:	          fb00 f202 	mul.w	r2, r0, r2
    pll_parameters.p = 3; /* Bit value for request pll_p */
 80004e4:	          f445 35c0 	orr.w	r5, r5, #98304	; 0x18000
    pll_parameters.freq_o = pll_clk_out * 1000000;
 80004e8:	          e9c4 2101 	strd	r2, r1, [r4, #4]
    const uint8_t pll_p[] = /* Decode table for PLL_P values */
 80004ec:	          9301      	str	r3, [sp, #4]
    pll_parameters.p = 3; /* Bit value for request pll_p */
 80004ee:	          6025      	str	r5, [r4, #0]
    uint32_t __pll_clk_in = (pll_clk_in == RCC_PLLCLK_HSE) ? HSE_VALUE : HSI_VALUE;
 80004f0:	          bf0c      	ite	eq
 80004f2:	          f04f 0e04 	moveq.w	lr, #4
 80004f6:	          f04f 0e08 	movne.w	lr, #8
    pll_parameters.p = 3; /* Bit value for request pll_p */
 80004fa:	          2100      	movs	r1, #0
 80004fc:	          2208      	movs	r2, #8
 80004fe:	      /-- e008      	b.n	8000512 <rcc_pll_param_cpte+0x42>
        /* fvco_out = pll_out * pll_p (pag. 226 - reference manual) */
        fvco_out = pll_clk_out * pll_p[idx]; 
        if (fvco_out > RCC_PLLN_MAX_VALUE) { 
            /* If fvco_out is major than FVCO_MAX decrease pll_p
               to get a valid value for fvco_out freq */
            pll_parameters.p -= 1;
 8000500:	   /--|-> 6822      	ldr	r2, [r4, #0]
 8000502:	   |  |   f363 32d0 	bfi	r2, r3, #15, #2
        } else {
            /* Otherwise break the while routine */
            break;
        }
    } while(pll_parameters.p > 0);
 8000506:	   |  |   f412 3fc0 	tst.w	r2, #98304	; 0x18000
            pll_parameters.p -= 1;
 800050a:	   |  |   6022      	str	r2, [r4, #0]
    } while(pll_parameters.p > 0);
 800050c:	/--|--|-- d03d      	beq.n	800058a <rcc_pll_param_cpte+0xba>
        fvco_out = pll_clk_out * pll_p[idx]; 
 800050e:	|  |  |   f81c 2c04 	ldrb.w	r2, [r12, #-4]
        uint8_t idx = pll_parameters.p;
 8000512:	|  |  \-> f001 0303 	and.w	r3, r1, #3
 8000516:	|  |      f083 0303 	eor.w	r3, r3, #3
            pll_parameters.p -= 1;
 800051a:	|  |      3b01      	subs	r3, #1
        fvco_out = pll_clk_out * pll_p[idx]; 
 800051c:	|  |      fb10 f202 	smulbb	r2, r0, r2
            pll_parameters.p -= 1;
 8000520:	|  |      f003 0303 	and.w	r3, r3, #3
        fvco_out = pll_clk_out * pll_p[idx]; 
 8000524:	|  |      f103 0508 	add.w	r5, r3, #8
        if (fvco_out > RCC_PLLN_MAX_VALUE) { 
 8000528:	|  |      f5b2 7fd8 	cmp.w	r2, #432	; 0x1b0
        fvco_out = pll_clk_out * pll_p[idx]; 
 800052c:	|  |      eb0d 0c05 	add.w	r12, sp, r5
    } while(pll_parameters.p > 0);
 8000530:	|  |      f101 0101 	add.w	r1, r1, #1
        if (fvco_out > RCC_PLLN_MAX_VALUE) { 
 8000534:	|  \----- dce4      	bgt.n	8000500 <rcc_pll_param_cpte+0x30>
    /* Recalculate fvco with the last pll_p value */
    fvco_out = pll_clk_out * pll_p[pll_parameters.p];
    /* Compute other parameters */
    pll_parameters.m = __pll_clk_in / fvco_in;
 8000536:	|     /-> 8821      	ldrh	r1, [r4, #0]
    {
        pll_parameters.q = 2;
    }
    /* Compute APB preescalers to get max bus speeds */
    pll_parameters.ppre1 = pll_clk_out / 42; /* 42MHz in APB1 case */
    pll_parameters.ppre2 = pll_clk_out / 84; /* 84MHz in APB2 case */
 8000538:	|     |   4d19      	ldr	r5, [pc, #100]	; (80005a0 <rcc_pll_param_cpte+0xd0>)
    pll_parameters.m = __pll_clk_in / fvco_in;
 800053a:	|     |   f3c2 0348 	ubfx	r3, r2, #1, #9
 800053e:	|     |   f421 41ff 	bic.w	r1, r1, #32640	; 0x7f80
 8000542:	|     |   ea4e 1383 	orr.w	r3, lr, r3, lsl #6
 8000546:	|     |   f021 017f 	bic.w	r1, r1, #127	; 0x7f
 800054a:	|     |   430b      	orrs	r3, r1
    pll_parameters.q = fvco_out / 48;
 800054c:	|     |   4915      	ldr	r1, [pc, #84]	; (80005a4 <rcc_pll_param_cpte+0xd4>)
    pll_parameters.m = __pll_clk_in / fvco_in;
 800054e:	|     |   8023      	strh	r3, [r4, #0]
    pll_parameters.q = fvco_out / 48;
 8000550:	|     |   fba1 3202 	umull	r3, r2, r1, r2
 8000554:	|     |   f3c2 1243 	ubfx	r2, r2, #5, #4
        pll_parameters.q = 2;
 8000558:	|     |   78a3      	ldrb	r3, [r4, #2]
    if (pll_parameters.q < 2)
 800055a:	|     |   2a01      	cmp	r2, #1
        pll_parameters.q = 2;
 800055c:	|     |   bf98      	it	ls
 800055e:	|     |   2202      	movls	r2, #2
 8000560:	|     |   f362 0344 	bfi	r3, r2, #1, #4
    pll_parameters.ppre1 = pll_clk_out / 42; /* 42MHz in APB1 case */
 8000564:	|     |   0842      	lsrs	r2, r0, #1
        pll_parameters.q = 2;
 8000566:	|     |   70a3      	strb	r3, [r4, #2]
    pll_parameters.ppre1 = pll_clk_out / 42; /* 42MHz in APB1 case */
 8000568:	|     |   fba5 1202 	umull	r1, r2, r5, r2
    pll_parameters.ppre2 = pll_clk_out / 84; /* 84MHz in APB2 case */
 800056c:	|     |   0883      	lsrs	r3, r0, #2
    pll_parameters.ppre1 = pll_clk_out / 42; /* 42MHz in APB1 case */
 800056e:	|     |   8861      	ldrh	r1, [r4, #2]
    pll_parameters.ppre2 = pll_clk_out / 84; /* 84MHz in APB2 case */
 8000570:	|     |   fba5 0303 	umull	r0, r3, r5, r3
    pll_parameters.ppre1 = pll_clk_out / 42; /* 42MHz in APB1 case */
 8000574:	|     |   0892      	lsrs	r2, r2, #2
 8000576:	|     |   0152      	lsls	r2, r2, #5
 8000578:	|     |   089b      	lsrs	r3, r3, #2
 800057a:	|     |   ea42 2303 	orr.w	r3, r2, r3, lsl #8
 800057e:	|     |   f421 62fc 	bic.w	r2, r1, #2016	; 0x7e0
 8000582:	|     |   4313      	orrs	r3, r2
 8000584:	|     |   8063      	strh	r3, [r4, #2]
}
 8000586:	|     |   b003      	add	sp, #12
 8000588:	|     |   bd30      	pop	{r4, r5, pc}
    fvco_out = pll_clk_out * pll_p[pll_parameters.p];
 800058a:	\-----|-> f81c 2c04 	ldrb.w	r2, [r12, #-4]
 800058e:	      |   fb12 f200 	smulbb	r2, r2, r0
 8000592:	      \-- e7d0      	b.n	8000536 <rcc_pll_param_cpte+0x66>
 8000594:	          0024      	movs	r4, r4
 8000596:	          2000      	movs	r0, #0
 8000598:	          4240      	negs	r0, r0
 800059a:	          000f      	movs	r7, r1
 800059c:	          0402      	lsls	r2, r0, #16
 800059e:	          0806      	lsrs	r6, r0, #32
 80005a0:	          0c31      	lsrs	r1, r6, #16
 80005a2:	          30c3      	adds	r0, #195	; 0xc3
 80005a4:	          aaab      	add	r2, sp, #684	; 0x2ac
 80005a6:	          aaaa      	add	r2, sp, #680	; 0x2a8

080005a8 <rcc_pll_param_set>:

void rcc_pll_param_set(void)
{
    RCC->PLLCFGR |= (pll_parameters.q << RCC_PLLCFGR_PLLQ_Pos) 
 80005a8:	4a0e      	ldr	r2, [pc, #56]	; (80005e4 <rcc_pll_param_set+0x3c>)
        | (pll_parameters.p << RCC_PLLCFGR_PLLP_Pos)
 80005aa:	6813      	ldr	r3, [r2, #0]
    RCC->PLLCFGR |= (pll_parameters.q << RCC_PLLCFGR_PLLQ_Pos) 
 80005ac:	f892 c002 	ldrb.w	r12, [r2, #2]
        | (pll_parameters.n << RCC_PLLCFGR_PLLN_Pos) 
        | (pll_parameters.m << RCC_PLLCFGR_PLLM_Pos) 
 80005b0:	7810      	ldrb	r0, [r2, #0]
        | (pll_parameters.p << RCC_PLLCFGR_PLLP_Pos)
 80005b2:	f3c3 33c1 	ubfx	r3, r3, #15, #2
    RCC->PLLCFGR |= (pll_parameters.q << RCC_PLLCFGR_PLLQ_Pos) 
 80005b6:	f3cc 0c43 	ubfx	r12, r12, #1, #4
        | (pll_parameters.p << RCC_PLLCFGR_PLLP_Pos)
 80005ba:	041b      	lsls	r3, r3, #16
{
 80005bc:	b410      	push	{r4}
        | (pll_parameters.m << RCC_PLLCFGR_PLLM_Pos) 
 80005be:	f000 003f 	and.w	r0, r0, #63	; 0x3f
    RCC->PLLCFGR |= (pll_parameters.q << RCC_PLLCFGR_PLLQ_Pos) 
 80005c2:	4c09      	ldr	r4, [pc, #36]	; (80005e8 <rcc_pll_param_set+0x40>)
        | (pll_parameters.p << RCC_PLLCFGR_PLLP_Pos)
 80005c4:	ea43 630c 	orr.w	r3, r3, r12, lsl #24
        | (pll_parameters.m << RCC_PLLCFGR_PLLM_Pos) 
 80005c8:	4303      	orrs	r3, r0
        | (pll_parameters.n << RCC_PLLCFGR_PLLN_Pos) 
 80005ca:	8810      	ldrh	r0, [r2, #0]
    RCC->PLLCFGR |= (pll_parameters.q << RCC_PLLCFGR_PLLQ_Pos) 
 80005cc:	6861      	ldr	r1, [r4, #4]
 80005ce:	6892      	ldr	r2, [r2, #8]
        | (pll_parameters.n << RCC_PLLCFGR_PLLN_Pos) 
 80005d0:	f3c0 1088 	ubfx	r0, r0, #6, #9
        | (pll_parameters.m << RCC_PLLCFGR_PLLM_Pos) 
 80005d4:	ea43 1380 	orr.w	r3, r3, r0, lsl #6
    RCC->PLLCFGR |= (pll_parameters.q << RCC_PLLCFGR_PLLQ_Pos) 
 80005d8:	430a      	orrs	r2, r1
 80005da:	4313      	orrs	r3, r2
 80005dc:	6063      	str	r3, [r4, #4]
        | (pll_parameters.source);
}
 80005de:	f85d 4b04 	ldr.w	r4, [sp], #4
 80005e2:	4770      	bx	lr
 80005e4:	0024      	movs	r4, r4
 80005e6:	2000      	movs	r0, #0
 80005e8:	3800      	subs	r0, #0
 80005ea:	4002      	ands	r2, r0

080005ec <rcc_pll_param_clr>:

void rcc_pll_param_clr(void)
{
    RCC->PLLCFGR &= ~((0xF << RCC_PLLCFGR_PLLQ_Pos) 
 80005ec:	4a02      	ldr	r2, [pc, #8]	; (80005f8 <rcc_pll_param_clr+0xc>)
 80005ee:	4903      	ldr	r1, [pc, #12]	; (80005fc <rcc_pll_param_clr+0x10>)
 80005f0:	6853      	ldr	r3, [r2, #4]
 80005f2:	400b      	ands	r3, r1
 80005f4:	6053      	str	r3, [r2, #4]
        | (0x3 << RCC_PLLCFGR_PLLP_Pos)
        | (0x1FF << RCC_PLLCFGR_PLLN_Pos) 
        | (0x3F << RCC_PLLCFGR_PLLM_Pos)
        | RCC_PLLCFGR_PLLSRC);
 80005f6:	4770      	bx	lr
 80005f8:	3800      	subs	r0, #0
 80005fa:	4002      	ands	r2, r0
 80005fc:	8000      	strh	r0, [r0, #0]
 80005fe:	f0bc  			; <UNDEFINED> instruction: 0xf0bc4b2d

08000600 <flash_acr_config_auto>:

#include "flash.h"

void flash_acr_config_auto(uint32_t clk)
{
    if (clk <= 30000000) {
 8000600:	       4b2d      	ldr	r3, [pc, #180]	; (80006b8 <flash_acr_config_auto+0xb8>)
 8000602:	       4298      	cmp	r0, r3
 8000604:	   /-- d809      	bhi.n	800061a <flash_acr_config_auto+0x1a>
 * ...
 * @endcode
 */
__FORCE_INLINE void flash_acr_config_set(flash_config_t config)
{
    FLASH->ACR &= ~config;
 8000606:	   |   4b2d      	ldr	r3, [pc, #180]	; (80006bc <flash_acr_config_auto+0xbc>)
 8000608:	   |   681a      	ldr	r2, [r3, #0]
 800060a:	   |   f422 62e0 	bic.w	r2, r2, #1792	; 0x700
 800060e:	   |   601a      	str	r2, [r3, #0]
    FLASH->ACR |= config;
 8000610:	   |   681a      	ldr	r2, [r3, #0]
 8000612:	   |   f442 62e0 	orr.w	r2, r2, #1792	; 0x700
 8000616:	   |   601a      	str	r2, [r3, #0]
}
 8000618:	   |   4770      	bx	lr
        flash_acr_config_set(
            FLASH_CONFIG_DCACHE | FLASH_CONFIG_ICACHE |
            FLASH_CONFIG_PREFETCH | FLASH_CONFIG_LATENCY_0WS
        );
    } 
    else if (clk <= 60000000) {
 800061a:	   \-> 4b29      	ldr	r3, [pc, #164]	; (80006c0 <flash_acr_config_auto+0xc0>)
 800061c:	       4298      	cmp	r0, r3
 800061e:	   /-- d80d      	bhi.n	800063c <flash_acr_config_auto+0x3c>
    FLASH->ACR &= ~config;
 8000620:	   |   4a26      	ldr	r2, [pc, #152]	; (80006bc <flash_acr_config_auto+0xbc>)
 8000622:	   |   6813      	ldr	r3, [r2, #0]
 8000624:	   |   f423 63e0 	bic.w	r3, r3, #1792	; 0x700
 8000628:	   |   f023 0301 	bic.w	r3, r3, #1
 800062c:	   |   6013      	str	r3, [r2, #0]
    FLASH->ACR |= config;
 800062e:	   |   6813      	ldr	r3, [r2, #0]
 8000630:	   |   f443 63e0 	orr.w	r3, r3, #1792	; 0x700
 8000634:	   |   f043 0301 	orr.w	r3, r3, #1
 8000638:	   |   6013      	str	r3, [r2, #0]
}
 800063a:	   |   4770      	bx	lr
        flash_acr_config_set(
            FLASH_CONFIG_DCACHE | FLASH_CONFIG_ICACHE |
            FLASH_CONFIG_PREFETCH | FLASH_CONFIG_LATENCY_1WS
        );
    }
    else if (clk <= 90000000) {
 800063c:	   \-> 4b21      	ldr	r3, [pc, #132]	; (80006c4 <flash_acr_config_auto+0xc4>)
 800063e:	       4298      	cmp	r0, r3
 8000640:	   /-- d910      	bls.n	8000664 <flash_acr_config_auto+0x64>
        flash_acr_config_set(
            FLASH_CONFIG_DCACHE | FLASH_CONFIG_ICACHE |
            FLASH_CONFIG_PREFETCH | FLASH_CONFIG_LATENCY_2WS
        );
    }
    else if (clk <= 120000000) {
 8000642:	   |   4b21      	ldr	r3, [pc, #132]	; (80006c8 <flash_acr_config_auto+0xc8>)
 8000644:	   |   4298      	cmp	r0, r3
 8000646:	/--|-- d81b      	bhi.n	8000680 <flash_acr_config_auto+0x80>
    FLASH->ACR &= ~config;
 8000648:	|  |   4a1c      	ldr	r2, [pc, #112]	; (80006bc <flash_acr_config_auto+0xbc>)
 800064a:	|  |   6813      	ldr	r3, [r2, #0]
 800064c:	|  |   f423 63e0 	bic.w	r3, r3, #1792	; 0x700
 8000650:	|  |   f023 0303 	bic.w	r3, r3, #3
 8000654:	|  |   6013      	str	r3, [r2, #0]
    FLASH->ACR |= config;
 8000656:	|  |   6813      	ldr	r3, [r2, #0]
 8000658:	|  |   f443 63e0 	orr.w	r3, r3, #1792	; 0x700
 800065c:	|  |   f043 0303 	orr.w	r3, r3, #3
 8000660:	|  |   6013      	str	r3, [r2, #0]
}
 8000662:	|  |   4770      	bx	lr
    FLASH->ACR &= ~config;
 8000664:	|  \-> 4a15      	ldr	r2, [pc, #84]	; (80006bc <flash_acr_config_auto+0xbc>)
 8000666:	|      6813      	ldr	r3, [r2, #0]
 8000668:	|      f423 63e0 	bic.w	r3, r3, #1792	; 0x700
 800066c:	|      f023 0302 	bic.w	r3, r3, #2
 8000670:	|      6013      	str	r3, [r2, #0]
    FLASH->ACR |= config;
 8000672:	|      6813      	ldr	r3, [r2, #0]
 8000674:	|      f443 63e0 	orr.w	r3, r3, #1792	; 0x700
 8000678:	|      f043 0302 	orr.w	r3, r3, #2
 800067c:	|      6013      	str	r3, [r2, #0]
}
 800067e:	|      4770      	bx	lr
        flash_acr_config_set(
            FLASH_CONFIG_DCACHE | FLASH_CONFIG_ICACHE |
            FLASH_CONFIG_PREFETCH | FLASH_CONFIG_LATENCY_3WS
        );
    }
    else if (clk <= 150000000) {
 8000680:	\----> 4b12      	ldr	r3, [pc, #72]	; (80006cc <flash_acr_config_auto+0xcc>)
    FLASH->ACR &= ~config;
 8000682:	       4a0e      	ldr	r2, [pc, #56]	; (80006bc <flash_acr_config_auto+0xbc>)
 8000684:	       4298      	cmp	r0, r3
 8000686:	       6813      	ldr	r3, [r2, #0]
 8000688:	       f423 63e0 	bic.w	r3, r3, #1792	; 0x700
 800068c:	   /-- d809      	bhi.n	80006a2 <flash_acr_config_auto+0xa2>
 800068e:	   |   f023 0304 	bic.w	r3, r3, #4
 8000692:	   |   6013      	str	r3, [r2, #0]
    FLASH->ACR |= config;
 8000694:	   |   6813      	ldr	r3, [r2, #0]
 8000696:	   |   f443 63e0 	orr.w	r3, r3, #1792	; 0x700
 800069a:	   |   f043 0304 	orr.w	r3, r3, #4
 800069e:	   |   6013      	str	r3, [r2, #0]
}
 80006a0:	   |   4770      	bx	lr
    FLASH->ACR &= ~config;
 80006a2:	   \-> f023 0305 	bic.w	r3, r3, #5
 80006a6:	       6013      	str	r3, [r2, #0]
    FLASH->ACR |= config;
 80006a8:	       6813      	ldr	r3, [r2, #0]
 80006aa:	       f443 63e0 	orr.w	r3, r3, #1792	; 0x700
 80006ae:	       f043 0305 	orr.w	r3, r3, #5
 80006b2:	       6013      	str	r3, [r2, #0]
        flash_acr_config_set(
            FLASH_CONFIG_DCACHE | FLASH_CONFIG_ICACHE |
            FLASH_CONFIG_PREFETCH | FLASH_CONFIG_LATENCY_5WS
        );
    }
}
 80006b4:	       4770      	bx	lr
 80006b6:	       bf00      	nop
 80006b8:	       c380      	stmia	r3!, {r7}
 80006ba:	       01c9      	lsls	r1, r1, #7
 80006bc:	       3c00      	subs	r4, #0
 80006be:	       4002      	ands	r2, r0
 80006c0:	       8700      	strh	r0, [r0, #56]	; 0x38
 80006c2:	       0393      	lsls	r3, r2, #14
 80006c4:	       4a80      	ldr	r2, [pc, #512]	; (80008c8 <_siccmdata+0x110>)
 80006c6:	       055d      	lsls	r5, r3, #21
 80006c8:	       0e00      	lsrs	r0, r0, #24
 80006ca:	       0727      	lsls	r7, r4, #28
 80006cc:	       d180      	bne.n	80005d0 <rcc_pll_param_set+0x28>
 80006ce:	       08f0      	lsrs	r0, r6, #3

080006d0 <delay_init>:
uint32_t DELAY_CYCLES_US;              


void delay_init (void)
{
    DELAY_CYCLES_MS = (SystemCoreClock / 1000);
 80006d0:	4a09      	ldr	r2, [pc, #36]	; (80006f8 <delay_init+0x28>)
 80006d2:	4b0a      	ldr	r3, [pc, #40]	; (80006fc <delay_init+0x2c>)
 80006d4:	6812      	ldr	r2, [r2, #0]
    DELAY_CYCLES_US = (DELAY_CYCLES_MS / 1000);
    DELAY_CYCLES_MS += EXTRACYCLES_PER_MS;
 80006d6:	480a      	ldr	r0, [pc, #40]	; (8000700 <delay_init+0x30>)
{
 80006d8:	b410      	push	{r4}
    DELAY_CYCLES_US = (DELAY_CYCLES_MS / 1000);
 80006da:	4c0a      	ldr	r4, [pc, #40]	; (8000704 <delay_init+0x34>)
    DELAY_CYCLES_MS = (SystemCoreClock / 1000);
 80006dc:	fba3 1302 	umull	r1, r3, r3, r2
 80006e0:	099b      	lsrs	r3, r3, #6
    DELAY_CYCLES_US = (DELAY_CYCLES_MS / 1000);
 80006e2:	fba4 4202 	umull	r4, r2, r4, r2
 80006e6:	4908      	ldr	r1, [pc, #32]	; (8000708 <delay_init+0x38>)
}
 80006e8:	f85d 4b04 	ldr.w	r4, [sp], #4
    DELAY_CYCLES_US = (DELAY_CYCLES_MS / 1000);
 80006ec:	0c92      	lsrs	r2, r2, #18
    DELAY_CYCLES_MS += EXTRACYCLES_PER_MS;
 80006ee:	3309      	adds	r3, #9
 80006f0:	6003      	str	r3, [r0, #0]
    DELAY_CYCLES_US = (DELAY_CYCLES_MS / 1000);
 80006f2:	600a      	str	r2, [r1, #0]
}
 80006f4:	4770      	bx	lr
 80006f6:	bf00      	nop
 80006f8:	0000      	movs	r0, r0
 80006fa:	2000      	movs	r0, #0
 80006fc:	4dd3      	ldr	r5, [pc, #844]	; (8000a4c <_siccmdata+0x294>)
 80006fe:	1062      	asrs	r2, r4, #1
 8000700:	0030      	movs	r0, r6
 8000702:	2000      	movs	r0, #0
 8000704:	de83      	udf	#131	; 0x83
 8000706:	431b      	orrs	r3, r3
 8000708:	0034      	movs	r4, r6
 800070a:	2000      	movs	r0, #0

0800070c <delay_ms>:

__attribute__((optimize("-Os")))
void delay_ms (uint32_t ms)
{
    do {
        register int32_t cycles_to_ms = DELAY_CYCLES_MS;
 800070c:	       4a04      	ldr	r2, [pc, #16]	; (8000720 <delay_ms+0x14>)
 800070e:	/----> 6813      	ldr	r3, [r2, #0]
        do {
            __asm("NOP");
 8000710:	|  /-> bf00      	nop
            cycles_to_ms -= CYCLES_PER_MS;
 8000712:	|  |   3b05      	subs	r3, #5
        } while (cycles_to_ms > 0);
 8000714:	|  |   2b00      	cmp	r3, #0
 8000716:	|  \-- dcfb      	bgt.n	8000710 <delay_ms+0x4>
    } while (--ms);
 8000718:	|      3801      	subs	r0, #1
 800071a:	\----- d1f8      	bne.n	800070e <delay_ms+0x2>
}
 800071c:	       4770      	bx	lr
 800071e:	       bf00      	nop
 8000720:	       0030      	movs	r0, r6
 8000722:	       2000      	movs	r0, #0

08000724 <__libc_init_array>:
 8000724:	             b570      	push	{r4, r5, r6, lr}
 8000726:	             4d0d      	ldr	r5, [pc, #52]	; (800075c <__libc_init_array+0x38>)
 8000728:	             4c0d      	ldr	r4, [pc, #52]	; (8000760 <__libc_init_array+0x3c>)
 800072a:	             1b64      	subs	r4, r4, r5
 800072c:	             10a4      	asrs	r4, r4, #2
 800072e:	             2600      	movs	r6, #0
 8000730:	/----------> 42a6      	cmp	r6, r4
 8000732:	|     /----- d109      	bne.n	8000748 <__libc_init_array+0x24>
 8000734:	|     |      4d0b      	ldr	r5, [pc, #44]	; (8000764 <__libc_init_array+0x40>)
 8000736:	|     |      4c0c      	ldr	r4, [pc, #48]	; (8000768 <__libc_init_array+0x44>)
 8000738:	|     |      f000 f818 	bl	800076c <_init>
 800073c:	|     |      1b64      	subs	r4, r4, r5
 800073e:	|     |      10a4      	asrs	r4, r4, #2
 8000740:	|     |      2600      	movs	r6, #0
 8000742:	|  /--|----> 42a6      	cmp	r6, r4
 8000744:	|  |  |  /-- d105      	bne.n	8000752 <__libc_init_array+0x2e>
 8000746:	|  |  |  |   bd70      	pop	{r4, r5, r6, pc}
 8000748:	|  |  \--|-> f855 3b04 	ldr.w	r3, [r5], #4
 800074c:	|  |     |   4798      	blx	r3
 800074e:	|  |     |   3601      	adds	r6, #1
 8000750:	\--|-----|-- e7ee      	b.n	8000730 <__libc_init_array+0xc>
 8000752:	   |     \-> f855 3b04 	ldr.w	r3, [r5], #4
 8000756:	   |         4798      	blx	r3
 8000758:	   |         3601      	adds	r6, #1
 800075a:	   \-------- e7f2      	b.n	8000742 <__libc_init_array+0x1e>
 800075c:	             07a8      	lsls	r0, r5, #30
 800075e:	             0800      	lsrs	r0, r0, #32
 8000760:	             07a8      	lsls	r0, r5, #30
 8000762:	             0800      	lsrs	r0, r0, #32
 8000764:	             07a8      	lsls	r0, r5, #30
 8000766:	             0800      	lsrs	r0, r0, #32
 8000768:	             07ac      	lsls	r4, r5, #30
 800076a:	             0800      	lsrs	r0, r0, #32

0800076c <_init>:
 800076c:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 800076e:	bf00      	nop
 8000770:	bcf8      	pop	{r3, r4, r5, r6, r7}
 8000772:	bc08      	pop	{r3}
 8000774:	469e      	mov	lr, r3
 8000776:	4770      	bx	lr

08000778 <_fini>:
 8000778:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 800077a:	bf00      	nop
 800077c:	bcf8      	pop	{r3, r4, r5, r6, r7}
 800077e:	bc08      	pop	{r3}
 8000780:	469e      	mov	lr, r3
 8000782:	4770      	bx	lr

Disassembly of section .rodata:

08000784 <AHBPrescTable-0x14>:
 8000784:	0000      	movs	r0, r0
 8000786:	0000      	movs	r0, r0
 8000788:	0100      	lsls	r0, r0, #4
 800078a:	0000      	movs	r0, r0
 800078c:	0101      	lsls	r1, r0, #4
 800078e:	0000      	movs	r0, r0
 8000790:	0110      	lsls	r0, r2, #4
 8000792:	0000      	movs	r0, r0
 8000794:	0111      	lsls	r1, r2, #4
	...

08000798 <AHBPrescTable>:
	...
 80007a0:	0201      	lsls	r1, r0, #8
 80007a2:	0403      	lsls	r3, r0, #16
 80007a4:	0706      	lsls	r6, r0, #28
 80007a6:	0908      	lsrs	r0, r1, #4

Disassembly of section .init_array:

080007a8 <__frame_dummy_init_array_entry>:
 80007a8:	01cd      	lsls	r5, r1, #7
 80007aa:	0800      	lsrs	r0, r0, #32

Disassembly of section .fini_array:

080007ac <__do_global_dtors_aux_fini_array_entry>:
 80007ac:	01a9      	lsls	r1, r5, #6
 80007ae:	0800      	lsrs	r0, r0, #32

Disassembly of section .data:

20000000 <SystemCoreClock>:
uint32_t SystemCoreClock = 16000000;
20000000:	2400      	movs	r4, #0
20000002:	00f4      	lsls	r4, r6, #3

20000004 <system_clk>:
uint32_t system_clk = HSI_VALUE;
20000004:	2400      	movs	r4, #0
20000006:	00f4      	lsls	r4, r6, #3

Disassembly of section .bss:

20000008 <__bss_start__>:
20000008:	0000      	movs	r0, r0
	...

2000000c <object.0>:
	...

20000024 <pll_parameters>:
	...

20000030 <DELAY_CYCLES_MS>:
static uint32_t DELAY_CYCLES_MS;
20000030:	0000      	movs	r0, r0
	...

20000034 <DELAY_CYCLES_US>:
uint32_t DELAY_CYCLES_US;              
20000034:	0000      	movs	r0, r0
	...

Disassembly of section ._user_heap_stack:

20000038 <._user_heap_stack>:
	...
