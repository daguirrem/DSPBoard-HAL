
output/Debug/test.elf:     file format elf32-littlearm

SYMBOL TABLE:
08000000 l    d  .isr_vector	00000000 .isr_vector
080001a8 l    d  .text	00000000 .text
08000860 l    d  .rodata	00000000 .rodata
08000884 l    d  .ARM.extab	00000000 .ARM.extab
08000884 l    d  .ARM	00000000 .ARM
08000884 l    d  .preinit_array	00000000 .preinit_array
08000884 l    d  .init_array	00000000 .init_array
0800089c l    d  .fini_array	00000000 .fini_array
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
00000000 l    d  .debug_macro	00000000 .debug_macro
00000000 l    d  .debug_line	00000000 .debug_line
00000000 l    d  .debug_str	00000000 .debug_str
00000000 l    d  .comment	00000000 .comment
00000000 l    d  .debug_frame	00000000 .debug_frame
00000000 l    df *ABS*	00000000 startup_stm32f407xx.o
0800031c l       .text	00000000 LoopCopyDataInit
08000316 l       .text	00000000 CopyDataInit
0800032e l       .text	00000000 LoopFillZerobss
0800032a l       .text	00000000 FillZerobss
08000342 l       .text	00000000 LoopCopyCCMDataInit
0800033c l       .text	00000000 CopyCCMDataInit
08000354 l       .text	00000000 LoopFillZeroCCMbss
08000350 l       .text	00000000 FillZeroCCMbss
08000360 l       .text	00000000 LoopForever
08000390 l       .text	00000000 Infinite_Loop
00000000 l    df *ABS*	00000000 crtstuff.c
08000848 l     O .text	00000000 __EH_FRAME_BEGIN__
080001a8 l     F .text	00000000 __do_global_dtors_aux
20000008 l       .bss	00000001 completed.1
0800089c l     O .fini_array	00000000 __do_global_dtors_aux_fini_array_entry
080001cc l     F .text	00000000 frame_dummy
2000000c l       .bss	00000018 object.0
08000884 l     O .init_array	00000000 __frame_dummy_init_array_entry
00000000 l    df *ABS*	00000000 system_stm32f4xx.c
00000000 l    df *ABS*	00000000 main.c
0800029c l     F .text	0000000c sys_clk_update
00000000 l    df *ABS*	00000000 gpio.c
08000392 l     F .text	0000000c sys_clk_update
00000000 l    df *ABS*	00000000 rcc.c
08000436 l     F .text	0000000c sys_clk_update
20000024 l     O .bss	0000000c pll_parameters
00000000 l    df *ABS*	00000000 flash.c
080006c8 l     F .text	0000000c sys_clk_update
00000000 l    df *ABS*	00000000 delay.c
080007ac l     F .text	0000000c sys_clk_update
20000030 l     O .bss	00000004 DELAY_CYCLES_MS
00000000 l    df *ABS*	00000000 init.c
00000000 l    df *ABS*	00000000 crti.o
00000000 l    df *ABS*	00000000 crtn.o
00000000 l    df *ABS*	00000000 
0800089c l       .init_array	00000000 __init_array_end
08000884 l       .preinit_array	00000000 __preinit_array_end
08000884 l       .init_array	00000000 __init_array_start
08000884 l       .preinit_array	00000000 __preinit_array_start
08000390  w    F .text	00000002 RTC_Alarm_IRQHandler
08000390  w    F .text	00000002 HASH_RNG_IRQHandler
08000390  w    F .text	00000002 EXTI2_IRQHandler
08000390  w    F .text	00000002 TIM8_CC_IRQHandler
08000390  w    F .text	00000002 DebugMon_Handler
10000000 g       .ccmbss	00000000 _eccmbss
08000570 g     F .text	000000f8 rcc_pll_param_cpte
08000390  w    F .text	00000002 TIM1_CC_IRQHandler
08000390  w    F .text	00000002 DMA2_Stream5_IRQHandler
08000390  w    F .text	00000002 HardFault_Handler
08000390  w    F .text	00000002 DMA1_Stream5_IRQHandler
00000400 g       *ABS*	00000000 _Min_Stack_Size
08000390  w    F .text	00000002 SysTick_Handler
08000390  w    F .text	00000002 PVD_IRQHandler
08000390  w    F .text	00000002 SDIO_IRQHandler
08000390  w    F .text	00000002 TAMP_STAMP_IRQHandler
080008a0 g       *ABS*	00000000 _sidata
08000390  w    F .text	00000002 PendSV_Handler
08000390  w    F .text	00000002 NMI_Handler
08000884 g       .ARM	00000000 __exidx_end
08000390  w    F .text	00000002 CAN2_RX1_IRQHandler
08000390  w    F .text	00000002 EXTI3_IRQHandler
08000390  w    F .text	00000002 TIM8_TRG_COM_TIM14_IRQHandler
08000390  w    F .text	00000002 TIM1_UP_TIM10_IRQHandler
08000860 g       .text	00000000 _etext
20000008 g       .bss	00000000 _sbss
08000390  w    F .text	00000002 TIM8_UP_TIM13_IRQHandler
08000390  w    F .text	00000002 I2C3_ER_IRQHandler
08000390  w    F .text	00000002 LCD_TFT_IRQHandler
08000390  w    F .text	00000002 EXTI0_IRQHandler
08000390  w    F .text	00000002 I2C2_EV_IRQHandler
08000390  w    F .text	00000002 DMA1_Stream2_IRQHandler
08000390  w    F .text	00000002 CAN1_RX0_IRQHandler
08000390  w    F .text	00000002 FPU_IRQHandler
20000000 g     O .data	00000004 SystemCoreClock
08000390  w    F .text	00000002 OTG_HS_WKUP_IRQHandler
08000390  w    F .text	00000002 UsageFault_Handler
08000390  w    F .text	00000002 CAN2_SCE_IRQHandler
08000390  w    F .text	00000002 DMA2_Stream2_IRQHandler
20000008 g       .bss	00000000 __bss_start__
0800039e g     F .text	0000004c gpio_config_mode
20000000 g       .data	00000000 _sdata
08000390  w    F .text	00000002 SPI1_IRQHandler
08000390  w    F .text	00000002 TIM6_DAC_IRQHandler
08000390  w    F .text	00000002 TIM1_BRK_TIM9_IRQHandler
08000390  w    F .text	00000002 DCMI_IRQHandler
08000390  w    F .text	00000002 CAN2_RX0_IRQHandler
10000000 g       .ccmdata	00000000 _sccmdata
08000884 g       .ARM	00000000 __exidx_start
08000390  w    F .text	00000002 DMA2_Stream3_IRQHandler
08000800 g     F .text	00000048 __libc_init_array
08000444 g     F .text	0000012c rcc_sysclk_select
40024000 g       .bram	00000000 _sbram
10000000 g       .ccmbss	00000000 _sccmbss
08000390  w    F .text	00000002 USART6_IRQHandler
08000848 g     F .text	00000000 _init
08000390  w    F .text	00000002 USART3_IRQHandler
08000390  w    F .text	00000002 CRYP_IRQHandler
20000038 g       .bss	00000000 _ebss
08000304  w    F .text	0000005e Reset_Handler
08000390  w    F .text	00000002 CAN1_RX1_IRQHandler
08000390  w    F .text	00000002 UART5_IRQHandler
08000390  w    F .text	00000002 DMA2_Stream0_IRQHandler
080006d4 g     F .text	000000d8 flash_acr_config_auto
08000390  w    F .text	00000002 TIM4_IRQHandler
08000390  w    F .text	00000002 I2C1_EV_IRQHandler
08000390  w    F .text	00000002 DMA1_Stream6_IRQHandler
08000390  w    F .text	00000002 DMA1_Stream1_IRQHandler
08000390  w    F .text	00000002 UART4_IRQHandler
20000038 g       .bss	00000000 __bss_end__
08000390  w    F .text	00000002 LCD_TFT_1_IRQHandler
08000390  w    F .text	00000002 TIM3_IRQHandler
080008a8 g       *ABS*	00000000 _siccmdata
08000390  w    F .text	00000002 RCC_IRQHandler
08000390  w    F .text	00000002 TIM8_BRK_TIM12_IRQHandler
080003ea g     F .text	0000004c gpio_config_speed
00000000 g       *ABS*	00000000 _Min_Heap_Size
08000390 g       .text	00000002 Default_Handler
080007b8 g     F .text	00000030 delay_init
08000874 g     O .rodata	00000010 AHBPrescTable
08000390  w    F .text	00000002 EXTI15_10_IRQHandler
08000390  w    F .text	00000002 ADC_IRQHandler
08000390  w    F .text	00000002 DMA1_Stream7_IRQHandler
08000390  w    F .text	00000002 TIM7_IRQHandler
08000390  w    F .text	00000002 CAN2_TX_IRQHandler
08000390  w    F .text	00000002 TIM5_IRQHandler
08000390  w    F .text	00000002 DMA2_Stream7_IRQHandler
08000390  w    F .text	00000002 I2C3_EV_IRQHandler
20000034 g     O .bss	00000004 DELAY_CYCLES_US
08000390  w    F .text	00000002 EXTI9_5_IRQHandler
08000390  w    F .text	00000002 RTC_WKUP_IRQHandler
08000390  w    F .text	00000002 ETH_WKUP_IRQHandler
080006ac g     F .text	0000001c rcc_pll_param_clr
08000668 g     F .text	00000044 rcc_pll_param_set
08000390  w    F .text	00000002 SPI2_IRQHandler
08000390  w    F .text	00000002 OTG_HS_EP1_IN_IRQHandler
08000390  w    F .text	00000002 MemManage_Handler
080002a8 g     F .text	0000005c main
080007e8 g     F .text	00000018 delay_ms
08000390  w    F .text	00000002 DMA1_Stream0_IRQHandler
08000390  w    F .text	00000002 CAN1_TX_IRQHandler
08000390  w    F .text	00000002 SVC_Handler
08000390  w    F .text	00000002 EXTI4_IRQHandler
080001e8 g     F .text	00000014 SystemInit
08000854 g     F .text	00000000 _fini
08000390  w    F .text	00000002 FSMC_IRQHandler
20000004 g     O .data	00000004 system_clk
08000390  w    F .text	00000002 ETH_IRQHandler
08000390  w    F .text	00000002 OTG_HS_EP1_OUT_IRQHandler
08000390  w    F .text	00000002 WWDG_IRQHandler
08000390  w    F .text	00000002 TIM2_IRQHandler
08000390  w    F .text	00000002 OTG_FS_WKUP_IRQHandler
08000390  w    F .text	00000002 TIM1_TRG_COM_TIM11_IRQHandler
08000390  w    F .text	00000002 OTG_HS_IRQHandler
20020000 g       .isr_vector	00000000 _estack
08000390  w    F .text	00000002 EXTI1_IRQHandler
20000008 g       .data	00000000 _edata
08000390  w    F .text	00000002 USART2_IRQHandler
08000000 g     O .isr_vector	00000000 g_pfnVectors
080001fc g     F .text	000000a0 SystemCoreClockUpdate
08000390  w    F .text	00000002 I2C2_ER_IRQHandler
08000390  w    F .text	00000002 DMA2_Stream1_IRQHandler
08000390  w    F .text	00000002 CAN1_SCE_IRQHandler
08000390  w    F .text	00000002 DMA2_Stream4_IRQHandler
40024000 g       .bram	00000000 _ebram
08000390  w    F .text	00000002 BusFault_Handler
08000390  w    F .text	00000002 USART1_IRQHandler
08000390  w    F .text	00000002 OTG_FS_IRQHandler
08000390  w    F .text	00000002 SPI3_IRQHandler
08000390  w    F .text	00000002 DMA1_Stream4_IRQHandler
08000390  w    F .text	00000002 I2C1_ER_IRQHandler
10000000 g       .ccmdata	00000000 _eccmdata
08000390  w    F .text	00000002 DMA2_Stream6_IRQHandler
08000390  w    F .text	00000002 DMA1_Stream3_IRQHandler



Disassembly of section .isr_vector:

08000000 <g_pfnVectors>:
 8000000:	0000      	movs	r0, r0
 8000002:	2002      	movs	r0, #2
 8000004:	0305      	lsls	r5, r0, #12
 8000006:	0800      	lsrs	r0, r0, #32
 8000008:	0391      	lsls	r1, r2, #14
 800000a:	0800      	lsrs	r0, r0, #32
 800000c:	0391      	lsls	r1, r2, #14
 800000e:	0800      	lsrs	r0, r0, #32
 8000010:	0391      	lsls	r1, r2, #14
 8000012:	0800      	lsrs	r0, r0, #32
 8000014:	0391      	lsls	r1, r2, #14
 8000016:	0800      	lsrs	r0, r0, #32
 8000018:	0391      	lsls	r1, r2, #14
 800001a:	0800      	lsrs	r0, r0, #32
	...
 800002c:	0391      	lsls	r1, r2, #14
 800002e:	0800      	lsrs	r0, r0, #32
 8000030:	0391      	lsls	r1, r2, #14
 8000032:	0800      	lsrs	r0, r0, #32
 8000034:	0000      	movs	r0, r0
 8000036:	0000      	movs	r0, r0
 8000038:	0391      	lsls	r1, r2, #14
 800003a:	0800      	lsrs	r0, r0, #32
 800003c:	0391      	lsls	r1, r2, #14
 800003e:	0800      	lsrs	r0, r0, #32
 8000040:	0391      	lsls	r1, r2, #14
 8000042:	0800      	lsrs	r0, r0, #32
 8000044:	0391      	lsls	r1, r2, #14
 8000046:	0800      	lsrs	r0, r0, #32
 8000048:	0391      	lsls	r1, r2, #14
 800004a:	0800      	lsrs	r0, r0, #32
 800004c:	0391      	lsls	r1, r2, #14
 800004e:	0800      	lsrs	r0, r0, #32
 8000050:	0000      	movs	r0, r0
 8000052:	0000      	movs	r0, r0
 8000054:	0391      	lsls	r1, r2, #14
 8000056:	0800      	lsrs	r0, r0, #32
 8000058:	0391      	lsls	r1, r2, #14
 800005a:	0800      	lsrs	r0, r0, #32
 800005c:	0391      	lsls	r1, r2, #14
 800005e:	0800      	lsrs	r0, r0, #32
 8000060:	0391      	lsls	r1, r2, #14
 8000062:	0800      	lsrs	r0, r0, #32
 8000064:	0391      	lsls	r1, r2, #14
 8000066:	0800      	lsrs	r0, r0, #32
 8000068:	0391      	lsls	r1, r2, #14
 800006a:	0800      	lsrs	r0, r0, #32
 800006c:	0391      	lsls	r1, r2, #14
 800006e:	0800      	lsrs	r0, r0, #32
 8000070:	0391      	lsls	r1, r2, #14
 8000072:	0800      	lsrs	r0, r0, #32
 8000074:	0391      	lsls	r1, r2, #14
 8000076:	0800      	lsrs	r0, r0, #32
 8000078:	0391      	lsls	r1, r2, #14
 800007a:	0800      	lsrs	r0, r0, #32
 800007c:	0391      	lsls	r1, r2, #14
 800007e:	0800      	lsrs	r0, r0, #32
 8000080:	0391      	lsls	r1, r2, #14
 8000082:	0800      	lsrs	r0, r0, #32
 8000084:	0391      	lsls	r1, r2, #14
 8000086:	0800      	lsrs	r0, r0, #32
 8000088:	0391      	lsls	r1, r2, #14
 800008a:	0800      	lsrs	r0, r0, #32
 800008c:	0391      	lsls	r1, r2, #14
 800008e:	0800      	lsrs	r0, r0, #32
 8000090:	0391      	lsls	r1, r2, #14
 8000092:	0800      	lsrs	r0, r0, #32
 8000094:	0391      	lsls	r1, r2, #14
 8000096:	0800      	lsrs	r0, r0, #32
 8000098:	0391      	lsls	r1, r2, #14
 800009a:	0800      	lsrs	r0, r0, #32
 800009c:	0391      	lsls	r1, r2, #14
 800009e:	0800      	lsrs	r0, r0, #32
 80000a0:	0391      	lsls	r1, r2, #14
 80000a2:	0800      	lsrs	r0, r0, #32
 80000a4:	0391      	lsls	r1, r2, #14
 80000a6:	0800      	lsrs	r0, r0, #32
 80000a8:	0391      	lsls	r1, r2, #14
 80000aa:	0800      	lsrs	r0, r0, #32
 80000ac:	0391      	lsls	r1, r2, #14
 80000ae:	0800      	lsrs	r0, r0, #32
 80000b0:	0391      	lsls	r1, r2, #14
 80000b2:	0800      	lsrs	r0, r0, #32
 80000b4:	0391      	lsls	r1, r2, #14
 80000b6:	0800      	lsrs	r0, r0, #32
 80000b8:	0391      	lsls	r1, r2, #14
 80000ba:	0800      	lsrs	r0, r0, #32
 80000bc:	0391      	lsls	r1, r2, #14
 80000be:	0800      	lsrs	r0, r0, #32
 80000c0:	0391      	lsls	r1, r2, #14
 80000c2:	0800      	lsrs	r0, r0, #32
 80000c4:	0391      	lsls	r1, r2, #14
 80000c6:	0800      	lsrs	r0, r0, #32
 80000c8:	0391      	lsls	r1, r2, #14
 80000ca:	0800      	lsrs	r0, r0, #32
 80000cc:	0391      	lsls	r1, r2, #14
 80000ce:	0800      	lsrs	r0, r0, #32
 80000d0:	0391      	lsls	r1, r2, #14
 80000d2:	0800      	lsrs	r0, r0, #32
 80000d4:	0391      	lsls	r1, r2, #14
 80000d6:	0800      	lsrs	r0, r0, #32
 80000d8:	0391      	lsls	r1, r2, #14
 80000da:	0800      	lsrs	r0, r0, #32
 80000dc:	0391      	lsls	r1, r2, #14
 80000de:	0800      	lsrs	r0, r0, #32
 80000e0:	0391      	lsls	r1, r2, #14
 80000e2:	0800      	lsrs	r0, r0, #32
 80000e4:	0391      	lsls	r1, r2, #14
 80000e6:	0800      	lsrs	r0, r0, #32
 80000e8:	0391      	lsls	r1, r2, #14
 80000ea:	0800      	lsrs	r0, r0, #32
 80000ec:	0391      	lsls	r1, r2, #14
 80000ee:	0800      	lsrs	r0, r0, #32
 80000f0:	0391      	lsls	r1, r2, #14
 80000f2:	0800      	lsrs	r0, r0, #32
 80000f4:	0391      	lsls	r1, r2, #14
 80000f6:	0800      	lsrs	r0, r0, #32
 80000f8:	0391      	lsls	r1, r2, #14
 80000fa:	0800      	lsrs	r0, r0, #32
 80000fc:	0391      	lsls	r1, r2, #14
 80000fe:	0800      	lsrs	r0, r0, #32
 8000100:	0391      	lsls	r1, r2, #14
 8000102:	0800      	lsrs	r0, r0, #32
 8000104:	0391      	lsls	r1, r2, #14
 8000106:	0800      	lsrs	r0, r0, #32
 8000108:	0391      	lsls	r1, r2, #14
 800010a:	0800      	lsrs	r0, r0, #32
 800010c:	0391      	lsls	r1, r2, #14
 800010e:	0800      	lsrs	r0, r0, #32
 8000110:	0391      	lsls	r1, r2, #14
 8000112:	0800      	lsrs	r0, r0, #32
 8000114:	0391      	lsls	r1, r2, #14
 8000116:	0800      	lsrs	r0, r0, #32
 8000118:	0391      	lsls	r1, r2, #14
 800011a:	0800      	lsrs	r0, r0, #32
 800011c:	0391      	lsls	r1, r2, #14
 800011e:	0800      	lsrs	r0, r0, #32
 8000120:	0391      	lsls	r1, r2, #14
 8000122:	0800      	lsrs	r0, r0, #32
 8000124:	0391      	lsls	r1, r2, #14
 8000126:	0800      	lsrs	r0, r0, #32
 8000128:	0391      	lsls	r1, r2, #14
 800012a:	0800      	lsrs	r0, r0, #32
 800012c:	0391      	lsls	r1, r2, #14
 800012e:	0800      	lsrs	r0, r0, #32
 8000130:	0391      	lsls	r1, r2, #14
 8000132:	0800      	lsrs	r0, r0, #32
 8000134:	0391      	lsls	r1, r2, #14
 8000136:	0800      	lsrs	r0, r0, #32
 8000138:	0391      	lsls	r1, r2, #14
 800013a:	0800      	lsrs	r0, r0, #32
 800013c:	0391      	lsls	r1, r2, #14
 800013e:	0800      	lsrs	r0, r0, #32
 8000140:	0391      	lsls	r1, r2, #14
 8000142:	0800      	lsrs	r0, r0, #32
 8000144:	0391      	lsls	r1, r2, #14
 8000146:	0800      	lsrs	r0, r0, #32
 8000148:	0391      	lsls	r1, r2, #14
 800014a:	0800      	lsrs	r0, r0, #32
 800014c:	0391      	lsls	r1, r2, #14
 800014e:	0800      	lsrs	r0, r0, #32
 8000150:	0391      	lsls	r1, r2, #14
 8000152:	0800      	lsrs	r0, r0, #32
 8000154:	0391      	lsls	r1, r2, #14
 8000156:	0800      	lsrs	r0, r0, #32
 8000158:	0391      	lsls	r1, r2, #14
 800015a:	0800      	lsrs	r0, r0, #32
 800015c:	0391      	lsls	r1, r2, #14
 800015e:	0800      	lsrs	r0, r0, #32
 8000160:	0391      	lsls	r1, r2, #14
 8000162:	0800      	lsrs	r0, r0, #32
 8000164:	0391      	lsls	r1, r2, #14
 8000166:	0800      	lsrs	r0, r0, #32
 8000168:	0391      	lsls	r1, r2, #14
 800016a:	0800      	lsrs	r0, r0, #32
 800016c:	0391      	lsls	r1, r2, #14
 800016e:	0800      	lsrs	r0, r0, #32
 8000170:	0391      	lsls	r1, r2, #14
 8000172:	0800      	lsrs	r0, r0, #32
 8000174:	0391      	lsls	r1, r2, #14
 8000176:	0800      	lsrs	r0, r0, #32
 8000178:	0391      	lsls	r1, r2, #14
 800017a:	0800      	lsrs	r0, r0, #32
 800017c:	0391      	lsls	r1, r2, #14
 800017e:	0800      	lsrs	r0, r0, #32
 8000180:	0391      	lsls	r1, r2, #14
 8000182:	0800      	lsrs	r0, r0, #32
 8000184:	0391      	lsls	r1, r2, #14
 8000186:	0800      	lsrs	r0, r0, #32
	...
 80001a0:	0391      	lsls	r1, r2, #14
 80001a2:	0800      	lsrs	r0, r0, #32
 80001a4:	0391      	lsls	r1, r2, #14
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
 80001c8:	       0848      	lsrs	r0, r1, #1
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
 80001e4:	    0848      	lsrs	r0, r1, #1
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
 80001fc:	             4b22      	ldr	r3, [pc, #136]	; (8000288 <SystemCoreClockUpdate+0x8c>)
 80001fe:	             689b      	ldr	r3, [r3, #8]
 8000200:	             f003 030c 	and.w	r3, r3, #12

  switch (tmp)
 8000204:	             2b04      	cmp	r3, #4
 8000206:	      /----- d014      	beq.n	8000232 <SystemCoreClockUpdate+0x36>
 8000208:	      |      2b08      	cmp	r3, #8
 800020a:	   /--|----- d016      	beq.n	800023a <SystemCoreClockUpdate+0x3e>
 800020c:	   |  |  /-- b11b      	cbz	r3, 8000216 <SystemCoreClockUpdate+0x1a>

      pllp = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >>16) + 1 ) *2;
      SystemCoreClock = pllvco/pllp;
      break;
    default:
      SystemCoreClock = HSI_VALUE;
 800020e:	   |  |  |   4b1f      	ldr	r3, [pc, #124]	; (800028c <SystemCoreClockUpdate+0x90>)
 8000210:	   |  |  |   4a1f      	ldr	r2, [pc, #124]	; (8000290 <SystemCoreClockUpdate+0x94>)
 8000212:	   |  |  |   601a      	str	r2, [r3, #0]
      break;
 8000214:	/--|--|--|-- e002      	b.n	800021c <SystemCoreClockUpdate+0x20>
      SystemCoreClock = HSI_VALUE;
 8000216:	|  |  |  \-> 4b1d      	ldr	r3, [pc, #116]	; (800028c <SystemCoreClockUpdate+0x90>)
 8000218:	|  |  |      4a1d      	ldr	r2, [pc, #116]	; (8000290 <SystemCoreClockUpdate+0x94>)
 800021a:	|  |  |      601a      	str	r2, [r3, #0]
  }
  /* Compute HCLK frequency --------------------------------------------------*/
  /* Get HCLK prescaler */
  tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4)];
 800021c:	>--|--|----> 4b1a      	ldr	r3, [pc, #104]	; (8000288 <SystemCoreClockUpdate+0x8c>)
 800021e:	|  |  |      689b      	ldr	r3, [r3, #8]
 8000220:	|  |  |      f3c3 1303 	ubfx	r3, r3, #4, #4
 8000224:	|  |  |      4a1b      	ldr	r2, [pc, #108]	; (8000294 <SystemCoreClockUpdate+0x98>)
 8000226:	|  |  |      5cd1      	ldrb	r1, [r2, r3]
  /* HCLK frequency */
  SystemCoreClock >>= tmp;
 8000228:	|  |  |      4a18      	ldr	r2, [pc, #96]	; (800028c <SystemCoreClockUpdate+0x90>)
 800022a:	|  |  |      6813      	ldr	r3, [r2, #0]
 800022c:	|  |  |      40cb      	lsrs	r3, r1
 800022e:	|  |  |      6013      	str	r3, [r2, #0]
}
 8000230:	|  |  |      4770      	bx	lr
      SystemCoreClock = HSE_VALUE;
 8000232:	|  |  \----> 4b16      	ldr	r3, [pc, #88]	; (800028c <SystemCoreClockUpdate+0x90>)
 8000234:	|  |         4a18      	ldr	r2, [pc, #96]	; (8000298 <SystemCoreClockUpdate+0x9c>)
 8000236:	|  |         601a      	str	r2, [r3, #0]
      break;
 8000238:	+--|-------- e7f0      	b.n	800021c <SystemCoreClockUpdate+0x20>
      pllsource = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC) >> 22;
 800023a:	|  \-------> 4b13      	ldr	r3, [pc, #76]	; (8000288 <SystemCoreClockUpdate+0x8c>)
 800023c:	|            6859      	ldr	r1, [r3, #4]
      pllm = RCC->PLLCFGR & RCC_PLLCFGR_PLLM;
 800023e:	|            685a      	ldr	r2, [r3, #4]
 8000240:	|            f002 023f 	and.w	r2, r2, #63	; 0x3f
      if (pllsource != 0)
 8000244:	|            f411 0f80 	tst.w	r1, #4194304	; 0x400000
 8000248:	|     /----- d013      	beq.n	8000272 <SystemCoreClockUpdate+0x76>
        pllvco = (HSE_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
 800024a:	|     |      4b13      	ldr	r3, [pc, #76]	; (8000298 <SystemCoreClockUpdate+0x9c>)
 800024c:	|     |      fbb3 f3f2 	udiv	r3, r3, r2
 8000250:	|     |      4a0d      	ldr	r2, [pc, #52]	; (8000288 <SystemCoreClockUpdate+0x8c>)
 8000252:	|     |      6852      	ldr	r2, [r2, #4]
 8000254:	|     |      f3c2 1288 	ubfx	r2, r2, #6, #9
 8000258:	|     |      fb02 f303 	mul.w	r3, r2, r3
      pllp = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >>16) + 1 ) *2;
 800025c:	|     |  /-> 4a0a      	ldr	r2, [pc, #40]	; (8000288 <SystemCoreClockUpdate+0x8c>)
 800025e:	|     |  |   6852      	ldr	r2, [r2, #4]
 8000260:	|     |  |   f3c2 4201 	ubfx	r2, r2, #16, #2
 8000264:	|     |  |   3201      	adds	r2, #1
 8000266:	|     |  |   0052      	lsls	r2, r2, #1
      SystemCoreClock = pllvco/pllp;
 8000268:	|     |  |   fbb3 f3f2 	udiv	r3, r3, r2
 800026c:	|     |  |   4a07      	ldr	r2, [pc, #28]	; (800028c <SystemCoreClockUpdate+0x90>)
 800026e:	|     |  |   6013      	str	r3, [r2, #0]
      break;
 8000270:	\-----|--|-- e7d4      	b.n	800021c <SystemCoreClockUpdate+0x20>
        pllvco = (HSI_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
 8000272:	      \--|-> 4b07      	ldr	r3, [pc, #28]	; (8000290 <SystemCoreClockUpdate+0x94>)
 8000274:	         |   fbb3 f3f2 	udiv	r3, r3, r2
 8000278:	         |   4a03      	ldr	r2, [pc, #12]	; (8000288 <SystemCoreClockUpdate+0x8c>)
 800027a:	         |   6852      	ldr	r2, [r2, #4]
 800027c:	         |   f3c2 1288 	ubfx	r2, r2, #6, #9
 8000280:	         |   fb02 f303 	mul.w	r3, r2, r3
 8000284:	         \-- e7ea      	b.n	800025c <SystemCoreClockUpdate+0x60>
 8000286:	             bf00      	nop
 8000288:	             3800      	subs	r0, #0
 800028a:	             4002      	ands	r2, r0
 800028c:	             0000      	movs	r0, r0
 800028e:	             2000      	movs	r0, #0
 8000290:	             2400      	movs	r4, #0
 8000292:	             00f4      	lsls	r4, r6, #3
 8000294:	             0874      	lsrs	r4, r6, #1
 8000296:	             0800      	lsrs	r0, r0, #32
 8000298:	             1200      	asrs	r0, r0, #8
 800029a:	             007a      	lsls	r2, r7, #1

0800029c <sys_clk_update>:


__CONSTRUCTOR
__FORCE_INLINE
void sys_clk_update(void)
{
 800029c:	b508      	push	{r3, lr}
    SystemCoreClockUpdate();
 800029e:	f7ff ffad 	bl	80001fc <SystemCoreClockUpdate>
    delay_init();
 80002a2:	f000 fa89 	bl	80007b8 <delay_init>
}
 80002a6:	bd08      	pop	{r3, pc}

080002a8 <main>:
#include "delay.h"
#include "gpio.h"
#include "rcc.h"

int main(void)
{
 80002a8:	    b508      	push	{r3, lr}
 */
__FORCE_INLINE void rcc_pll_param_cpte_set(uint8_t pll_clk_out, 
    rcc_pllclk_t pll_clk_in
)
{
    rcc_pll_param_cpte(pll_clk_out, pll_clk_in);
 80002aa:	    f44f 0180 	mov.w	r1, #4194304	; 0x400000
 80002ae:	    2064      	movs	r0, #100	; 0x64
 80002b0:	    f000 f95e 	bl	8000570 <rcc_pll_param_cpte>
    rcc_pll_param_clr();
 80002b4:	    f000 f9fa 	bl	80006ac <rcc_pll_param_clr>
    rcc_pll_param_set();
 80002b8:	    f000 f9d6 	bl	8000668 <rcc_pll_param_set>
    rcc_pll_param_cpte_set(100, RCC_PLLCLK_HSE);
    rcc_sysclk_select(RCC_SYSCLK_PLL | RCC_SYSCLK_HSE);
 80002bc:	    480e      	ldr	r0, [pc, #56]	; (80002f8 <main+0x50>)
 80002be:	    f000 f8c1 	bl	8000444 <rcc_sysclk_select>
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_en_ahb1(rcc_ahb1_t mask)
{
    RCC->AHB1ENR |= mask;
 80002c2:	    4a0e      	ldr	r2, [pc, #56]	; (80002fc <main+0x54>)
 80002c4:	    6b13      	ldr	r3, [r2, #48]	; 0x30
 80002c6:	    f043 0301 	orr.w	r3, r3, #1
 80002ca:	    6313      	str	r3, [r2, #48]	; 0x30
    gpio_clock_en(GPIOA_RCC);
    gpio_config_mode(GPIOA, GPIO_MODE_OUTPUT, GPIO_IO6);
 80002cc:	    4c0c      	ldr	r4, [pc, #48]	; (8000300 <main+0x58>)
 80002ce:	    2240      	movs	r2, #64	; 0x40
 80002d0:	    2101      	movs	r1, #1
 80002d2:	    4620      	mov	r0, r4
 80002d4:	    f000 f863 	bl	800039e <gpio_config_mode>
    gpio_config_speed(GPIOA, GPIO_SPEED_VHIGH, GPIO_IO6);
 80002d8:	    2240      	movs	r2, #64	; 0x40
 80002da:	    2103      	movs	r1, #3
 80002dc:	    4620      	mov	r0, r4
 80002de:	    f000 f884 	bl	80003ea <gpio_config_speed>
 * ...
 * @endcode
 */
__FORCE_INLINE void gpio_port_tgl (GPIO_TypeDef *gpio, gpio_io_t mask)
{
    gpio->ODR ^= mask;
 80002e2:	/-> 4a07      	ldr	r2, [pc, #28]	; (8000300 <main+0x58>)
 80002e4:	|   6953      	ldr	r3, [r2, #20]
 80002e6:	|   f083 0340 	eor.w	r3, r3, #64	; 0x40
 80002ea:	|   6153      	str	r3, [r2, #20]
    
    while (1)
    {
        gpio_port_tgl(GPIOA, GPIO_IO6);
        delay_ms(273);
 80002ec:	|   f240 1011 	movw	r0, #273	; 0x111
 80002f0:	|   f000 fa7a 	bl	80007e8 <delay_ms>
    while (1)
 80002f4:	\-- e7f5      	b.n	80002e2 <main+0x3a>
 80002f6:	    bf00      	nop
 80002f8:	    0000      	movs	r0, r0
 80002fa:	    0101      	lsls	r1, r0, #4
 80002fc:	    3800      	subs	r0, #0
 80002fe:	    4002      	ands	r2, r0
 8000300:	    0000      	movs	r0, r0
 8000302:	    4002      	ands	r2, r0

08000304 <Reset_Handler>:
 8000304:	4817      	ldr	r0, [pc, #92]	; (8000364 <LoopForever+0x4>)
 8000306:	4685      	mov	sp, r0
 8000308:	f7ff ff6e 	bl	80001e8 <SystemInit>
 800030c:	4816      	ldr	r0, [pc, #88]	; (8000368 <LoopForever+0x8>)
 800030e:	4917      	ldr	r1, [pc, #92]	; (800036c <LoopForever+0xc>)
 8000310:	4a17      	ldr	r2, [pc, #92]	; (8000370 <LoopForever+0x10>)
 8000312:	2300      	movs	r3, #0
 8000314:	e002      	b.n	800031c <LoopCopyDataInit>

08000316 <CopyDataInit>:
 8000316:	58d4      	ldr	r4, [r2, r3]
 8000318:	50c4      	str	r4, [r0, r3]
 800031a:	3304      	adds	r3, #4

0800031c <LoopCopyDataInit>:
 800031c:	18c4      	adds	r4, r0, r3
 800031e:	428c      	cmp	r4, r1
 8000320:	d3f9      	bcc.n	8000316 <CopyDataInit>
 8000322:	4a14      	ldr	r2, [pc, #80]	; (8000374 <LoopForever+0x14>)
 8000324:	4c14      	ldr	r4, [pc, #80]	; (8000378 <LoopForever+0x18>)
 8000326:	2300      	movs	r3, #0
 8000328:	e001      	b.n	800032e <LoopFillZerobss>

0800032a <FillZerobss>:
 800032a:	6013      	str	r3, [r2, #0]
 800032c:	3204      	adds	r2, #4

0800032e <LoopFillZerobss>:
 800032e:	42a2      	cmp	r2, r4
 8000330:	d3fb      	bcc.n	800032a <FillZerobss>
 8000332:	4812      	ldr	r0, [pc, #72]	; (800037c <LoopForever+0x1c>)
 8000334:	4912      	ldr	r1, [pc, #72]	; (8000380 <LoopForever+0x20>)
 8000336:	4a13      	ldr	r2, [pc, #76]	; (8000384 <LoopForever+0x24>)
 8000338:	2300      	movs	r3, #0
 800033a:	e002      	b.n	8000342 <LoopCopyCCMDataInit>

0800033c <CopyCCMDataInit>:
 800033c:	58d4      	ldr	r4, [r2, r3]
 800033e:	50c4      	str	r4, [r0, r3]
 8000340:	3304      	adds	r3, #4

08000342 <LoopCopyCCMDataInit>:
 8000342:	18c4      	adds	r4, r0, r3
 8000344:	428c      	cmp	r4, r1
 8000346:	d3f9      	bcc.n	800033c <CopyCCMDataInit>
 8000348:	4a0f      	ldr	r2, [pc, #60]	; (8000388 <LoopForever+0x28>)
 800034a:	4c10      	ldr	r4, [pc, #64]	; (800038c <LoopForever+0x2c>)
 800034c:	2300      	movs	r3, #0
 800034e:	e001      	b.n	8000354 <LoopFillZeroCCMbss>

08000350 <FillZeroCCMbss>:
 8000350:	6013      	str	r3, [r2, #0]
 8000352:	3204      	adds	r2, #4

08000354 <LoopFillZeroCCMbss>:
 8000354:	42a2      	cmp	r2, r4
 8000356:	d3fb      	bcc.n	8000350 <FillZeroCCMbss>
 8000358:	f000 fa52 	bl	8000800 <__libc_init_array>
 800035c:	f7ff ffa4 	bl	80002a8 <main>

08000360 <LoopForever>:
 8000360:	/-- e7fe      	b.n	8000360 <LoopForever>
 8000362:	    0000      	movs	r0, r0
 8000364:	    0000      	movs	r0, r0
 8000366:	    2002      	movs	r0, #2
 8000368:	    0000      	movs	r0, r0
 800036a:	    2000      	movs	r0, #0
 800036c:	    0008      	movs	r0, r1
 800036e:	    2000      	movs	r0, #0
 8000370:	    08a0      	lsrs	r0, r4, #2
 8000372:	    0800      	lsrs	r0, r0, #32
 8000374:	    0008      	movs	r0, r1
 8000376:	    2000      	movs	r0, #0
 8000378:	    0038      	movs	r0, r7
 800037a:	    2000      	movs	r0, #0
 800037c:	    0000      	movs	r0, r0
 800037e:	    1000      	asrs	r0, r0, #32
 8000380:	    0000      	movs	r0, r0
 8000382:	    1000      	asrs	r0, r0, #32
 8000384:	    08a8      	lsrs	r0, r5, #2
 8000386:	    0800      	lsrs	r0, r0, #32
 8000388:	    0000      	movs	r0, r0
 800038a:	    1000      	asrs	r0, r0, #32
 800038c:	    0000      	movs	r0, r0
 800038e:	    1000      	asrs	r0, r0, #32

08000390 <ADC_IRQHandler>:
 8000390:	/-- e7fe      	b.n	8000390 <ADC_IRQHandler>

08000392 <sys_clk_update>:


__CONSTRUCTOR
__FORCE_INLINE
void sys_clk_update(void)
{
 8000392:	b508      	push	{r3, lr}
    SystemCoreClockUpdate();
 8000394:	f7ff ff32 	bl	80001fc <SystemCoreClockUpdate>
    delay_init();
 8000398:	f000 fa0e 	bl	80007b8 <delay_init>
}
 800039c:	bd08      	pop	{r3, pc}

0800039e <gpio_config_mode>:
/* Individual Modder configurator */
void gpio_config_mode (GPIO_TypeDef *gpio, gpio_mode_t mode, gpio_io_t mask)
{
    /* Enable desired gpio mode [\mode] to each IO moder configurator
       masked [\mask] of GPIO [\gpio] */
    for (uint8_t bit = 0; bit < 32; bit += 2) {
 800039e:	             2300      	movs	r3, #0
 80003a0:	         /-- e005      	b.n	80003ae <gpio_config_mode+0x10>
            gpio->MODER &= ~(0x3 << bit);
            gpio->MODER |= mode << bit;
        }
        mask >>= 1;
    }
}
 80003a2:	/--------|-> f85d 4b04 	ldr.w	r4, [sp], #4
 80003a6:	|        |   4770      	bx	lr
        mask >>= 1;
 80003a8:	|     /--|-> 0852      	lsrs	r2, r2, #1
    for (uint8_t bit = 0; bit < 32; bit += 2) {
 80003aa:	|     |  |   3302      	adds	r3, #2
 80003ac:	|     |  |   b2db      	uxtb	r3, r3
 80003ae:	|     |  \-> 2b1f      	cmp	r3, #31
 80003b0:	|  /--|----- d81a      	bhi.n	80003e8 <gpio_config_mode+0x4a>
        if (mask & 0x1) {
 80003b2:	|  |  |      f012 0f01 	tst.w	r2, #1
 80003b6:	|  |  \----- d0f7      	beq.n	80003a8 <gpio_config_mode+0xa>
{
 80003b8:	|  |         b410      	push	{r4}
            gpio->MODER &= ~(0x3 << bit);
 80003ba:	|  |  /----> 6804      	ldr	r4, [r0, #0]
 80003bc:	|  |  |      f04f 0c03 	mov.w	r12, #3
 80003c0:	|  |  |      fa0c fc03 	lsl.w	r12, r12, r3
 80003c4:	|  |  |      ea24 040c 	bic.w	r4, r4, r12
 80003c8:	|  |  |      6004      	str	r4, [r0, #0]
            gpio->MODER |= mode << bit;
 80003ca:	|  |  |      6804      	ldr	r4, [r0, #0]
 80003cc:	|  |  |      fa01 fc03 	lsl.w	r12, r1, r3
 80003d0:	|  |  |      ea44 040c 	orr.w	r4, r4, r12
 80003d4:	|  |  |      6004      	str	r4, [r0, #0]
        mask >>= 1;
 80003d6:	|  |  |  /-> 0852      	lsrs	r2, r2, #1
    for (uint8_t bit = 0; bit < 32; bit += 2) {
 80003d8:	|  |  |  |   3302      	adds	r3, #2
 80003da:	|  |  |  |   b2db      	uxtb	r3, r3
 80003dc:	|  |  |  |   2b1f      	cmp	r3, #31
 80003de:	\--|--|--|-- d8e0      	bhi.n	80003a2 <gpio_config_mode+0x4>
        if (mask & 0x1) {
 80003e0:	   |  |  |   f012 0f01 	tst.w	r2, #1
 80003e4:	   |  |  \-- d0f7      	beq.n	80003d6 <gpio_config_mode+0x38>
 80003e6:	   |  \----- e7e8      	b.n	80003ba <gpio_config_mode+0x1c>
 80003e8:	   \-------> 4770      	bx	lr

080003ea <gpio_config_speed>:
/* Individual Modder configurator */
void gpio_config_speed (GPIO_TypeDef *gpio, gpio_speed_t speed, gpio_io_t mask)
{
    /* Enable desired gpio speed [\speed] to each masked [\mask] IO moder 
       configurator on target GPIO_OSPEEDR register [\gpio] */
    for (uint8_t bit = 0; bit < 32; bit += 2) {
 80003ea:	             2300      	movs	r3, #0
 80003ec:	         /-- e005      	b.n	80003fa <gpio_config_speed+0x10>
            gpio->OSPEEDR &= ~(0x3 << bit);
            gpio->OSPEEDR |= speed << bit;
        }
        mask >>= 1;
    }
}
 80003ee:	/--------|-> f85d 4b04 	ldr.w	r4, [sp], #4
 80003f2:	|        |   4770      	bx	lr
        mask >>= 1;
 80003f4:	|     /--|-> 0852      	lsrs	r2, r2, #1
    for (uint8_t bit = 0; bit < 32; bit += 2) {
 80003f6:	|     |  |   3302      	adds	r3, #2
 80003f8:	|     |  |   b2db      	uxtb	r3, r3
 80003fa:	|     |  \-> 2b1f      	cmp	r3, #31
 80003fc:	|  /--|----- d81a      	bhi.n	8000434 <gpio_config_speed+0x4a>
        if (mask & 0x1) {
 80003fe:	|  |  |      f012 0f01 	tst.w	r2, #1
 8000402:	|  |  \----- d0f7      	beq.n	80003f4 <gpio_config_speed+0xa>
{
 8000404:	|  |         b410      	push	{r4}
            gpio->OSPEEDR &= ~(0x3 << bit);
 8000406:	|  |  /----> 6884      	ldr	r4, [r0, #8]
 8000408:	|  |  |      f04f 0c03 	mov.w	r12, #3
 800040c:	|  |  |      fa0c fc03 	lsl.w	r12, r12, r3
 8000410:	|  |  |      ea24 040c 	bic.w	r4, r4, r12
 8000414:	|  |  |      6084      	str	r4, [r0, #8]
            gpio->OSPEEDR |= speed << bit;
 8000416:	|  |  |      6884      	ldr	r4, [r0, #8]
 8000418:	|  |  |      fa01 fc03 	lsl.w	r12, r1, r3
 800041c:	|  |  |      ea44 040c 	orr.w	r4, r4, r12
 8000420:	|  |  |      6084      	str	r4, [r0, #8]
        mask >>= 1;
 8000422:	|  |  |  /-> 0852      	lsrs	r2, r2, #1
    for (uint8_t bit = 0; bit < 32; bit += 2) {
 8000424:	|  |  |  |   3302      	adds	r3, #2
 8000426:	|  |  |  |   b2db      	uxtb	r3, r3
 8000428:	|  |  |  |   2b1f      	cmp	r3, #31
 800042a:	\--|--|--|-- d8e0      	bhi.n	80003ee <gpio_config_speed+0x4>
        if (mask & 0x1) {
 800042c:	   |  |  |   f012 0f01 	tst.w	r2, #1
 8000430:	   |  |  \-- d0f7      	beq.n	8000422 <gpio_config_speed+0x38>
 8000432:	   |  \----- e7e8      	b.n	8000406 <gpio_config_speed+0x1c>
 8000434:	   \-------> 4770      	bx	lr

08000436 <sys_clk_update>:
{
 8000436:	b508      	push	{r3, lr}
    SystemCoreClockUpdate();
 8000438:	f7ff fee0 	bl	80001fc <SystemCoreClockUpdate>
    delay_init();
 800043c:	f000 f9bc 	bl	80007b8 <delay_init>
}
 8000440:	bd08      	pop	{r3, pc}
	...

08000444 <rcc_sysclk_select>:
static struct pll_s pll_parameters;

uint32_t system_clk = HSI_VALUE;

void rcc_sysclk_select(rcc_sysclk_t source)
{
 8000444:	                            b570      	push	{r4, r5, r6, lr}
 8000446:	                            b086      	sub	sp, #24
 8000448:	                            4604      	mov	r4, r0
    uint32_t RCC_CR_BIT_RD = 0; /* Target ready bit on RCC_CR register */
    uint32_t pll_request;
    uint32_t cfgr_switch;
    uint32_t cfgr_ready;

    const uint32_t APB_PRESCALER[] = {
 800044a:	                            f10d 0c04 	add.w	r12, sp, #4
 800044e:	                            4d41      	ldr	r5, [pc, #260]	; (8000554 <rcc_sysclk_select+0x110>)
 8000450:	                            cd0f      	ldmia	r5!, {r0, r1, r2, r3}
 8000452:	                            e8ac 000f 	stmia.w	r12!, {r0, r1, r2, r3}
 8000456:	                            682b      	ldr	r3, [r5, #0]
 8000458:	                            f8cc 3000 	str.w	r3, [r12]
        0x110,
        0x111
    };

    /* Separe PLL request on */
    pll_request = source & RCC_CR_PLLON;
 800045c:	                            f004 7680 	and.w	r6, r4, #16777216	; 0x1000000
    source &= ~RCC_CR_PLLON;
 8000460:	                            f024 7080 	bic.w	r0, r4, #16777216	; 0x1000000
    
    switch (source)
 8000464:	                            f5b0 3f80 	cmp.w	r0, #65536	; 0x10000
 8000468:	   /----------------------- d05d      	beq.n	8000526 <rcc_sysclk_select+0xe2>
        cfgr_switch = 1;
        break;
    case RCC_SYSCLK_HSI:
    default:
        RCC_CR_BIT_RD = RCC_CR_HSIRDY;
        cfgr_switch = 0;
 800046a:	   |                        2500      	movs	r5, #0
        RCC_CR_BIT_RD = RCC_CR_HSIRDY;
 800046c:	   |                        2202      	movs	r2, #2
        break;
    }
    /* Power on the target clock (HSI or HSE) */
    RCC->CR |= source;
 800046e:	/--|----------------------> 493a      	ldr	r1, [pc, #232]	; (8000558 <rcc_sysclk_select+0x114>)
 8000470:	|  |                        680b      	ldr	r3, [r1, #0]
 8000472:	|  |                        4303      	orrs	r3, r0
 8000474:	|  |                        600b      	str	r3, [r1, #0]
    /* Wait for stable target clock (rdy flag == 1) */
    while ((RCC->CR & RCC_CR_BIT_RD) == 0);
 8000476:	|  |                    /-> 4b38      	ldr	r3, [pc, #224]	; (8000558 <rcc_sysclk_select+0x114>)
 8000478:	|  |                    |   681b      	ldr	r3, [r3, #0]
 800047a:	|  |                    |   4213      	tst	r3, r2
 800047c:	|  |                    \-- d0fb      	beq.n	8000476 <rcc_sysclk_select+0x32>
    /* Verify PLL target and power on it if required */
    if(pll_request)
 800047e:	|  |                        2e00      	cmp	r6, #0
 8000480:	|  |  /-------------------- d055      	beq.n	800052e <rcc_sysclk_select+0xea>
    {
        cfgr_switch = 2;
        RCC->CR |= pll_request;
 8000482:	|  |  |                     4a35      	ldr	r2, [pc, #212]	; (8000558 <rcc_sysclk_select+0x114>)
 8000484:	|  |  |                     6813      	ldr	r3, [r2, #0]
 8000486:	|  |  |                     431e      	orrs	r6, r3
 8000488:	|  |  |                     6016      	str	r6, [r2, #0]
        /* Wait for stable pll clock (rdy flag == 1) */
        while ((RCC->CR & RCC_CR_PLLRDY) == 0);
 800048a:	|  |  |                 /-> 4b33      	ldr	r3, [pc, #204]	; (8000558 <rcc_sysclk_select+0x114>)
 800048c:	|  |  |                 |   681b      	ldr	r3, [r3, #0]
 800048e:	|  |  |                 |   f013 7f00 	tst.w	r3, #33554432	; 0x2000000
 8000492:	|  |  |                 \-- d0fa      	beq.n	800048a <rcc_sysclk_select+0x46>
        /* Set maximus AHB/APB bus clocks */
        RCC->CFGR &= ~((0x7 << RCC_CFGR_PPRE2_Pos) | (0x7 << RCC_CFGR_PPRE1_Pos) 
 8000494:	|  |  |                     4930      	ldr	r1, [pc, #192]	; (8000558 <rcc_sysclk_select+0x114>)
 8000496:	|  |  |                     688b      	ldr	r3, [r1, #8]
 8000498:	|  |  |                     f423 437c 	bic.w	r3, r3, #64512	; 0xfc00
 800049c:	|  |  |                     f023 03f0 	bic.w	r3, r3, #240	; 0xf0
 80004a0:	|  |  |                     608b      	str	r3, [r1, #8]
            | (0xF << RCC_CFGR_HPRE_Pos));
        RCC->CFGR |= (APB_PRESCALER[pll_parameters.ppre2] << RCC_CFGR_PPRE2_Pos)
 80004a2:	|  |  |                     688d      	ldr	r5, [r1, #8]
 80004a4:	|  |  |                     482d      	ldr	r0, [pc, #180]	; (800055c <rcc_sysclk_select+0x118>)
 80004a6:	|  |  |                     78c3      	ldrb	r3, [r0, #3]
 80004a8:	|  |  |                     f003 0307 	and.w	r3, r3, #7
 80004ac:	|  |  |                     aa06      	add	r2, sp, #24
 80004ae:	|  |  |                     eb02 0383 	add.w	r3, r2, r3, lsl #2
 80004b2:	|  |  |                     f853 6c14 	ldr.w	r6, [r3, #-20]
            | (APB_PRESCALER[pll_parameters.ppre1] << RCC_CFGR_PPRE1_Pos);
 80004b6:	|  |  |                     7882      	ldrb	r2, [r0, #2]
 80004b8:	|  |  |                     0952      	lsrs	r2, r2, #5
 80004ba:	|  |  |                     ab06      	add	r3, sp, #24
 80004bc:	|  |  |                     eb03 0282 	add.w	r2, r3, r2, lsl #2
 80004c0:	|  |  |                     f852 3c14 	ldr.w	r3, [r2, #-20]
 80004c4:	|  |  |                     029b      	lsls	r3, r3, #10
 80004c6:	|  |  |                     ea43 3346 	orr.w	r3, r3, r6, lsl #13
        RCC->CFGR |= (APB_PRESCALER[pll_parameters.ppre2] << RCC_CFGR_PPRE2_Pos)
 80004ca:	|  |  |                     432b      	orrs	r3, r5
 80004cc:	|  |  |                     608b      	str	r3, [r1, #8]
        break;
    case 1:
        system_clk = HSE_VALUE;
        break;
    case 2:
        system_clk = pll_parameters.freq_o;
 80004ce:	|  |  |                     6842      	ldr	r2, [r0, #4]
 80004d0:	|  |  |                     4b23      	ldr	r3, [pc, #140]	; (8000560 <rcc_sysclk_select+0x11c>)
 80004d2:	|  |  |                     601a      	str	r2, [r3, #0]
        break;
 80004d4:	|  |  |                     2502      	movs	r5, #2
        break;
    }

    /* Referer to Relation between CPU clock frequency and Flash memory read 
       time [increasing/decreasing the CPU Freq.] pag. 81 - Refrence Manual*/
    if (system_clk > SystemCoreClock)
 80004d6:	|  |  |  /----------------> 4b22      	ldr	r3, [pc, #136]	; (8000560 <rcc_sysclk_select+0x11c>)
 80004d8:	|  |  |  |                  6818      	ldr	r0, [r3, #0]
 80004da:	|  |  |  |                  4b22      	ldr	r3, [pc, #136]	; (8000564 <rcc_sysclk_select+0x120>)
 80004dc:	|  |  |  |                  681b      	ldr	r3, [r3, #0]
 80004de:	|  |  |  |                  4298      	cmp	r0, r3
 80004e0:	|  |  |  |     /----------- d831      	bhi.n	8000546 <rcc_sysclk_select+0x102>
    {
        flash_acr_config_auto(system_clk);
    }

    cfgr_ready = (cfgr_switch<<RCC_CFGR_SWS_Pos);
 80004e2:	|  |  |  |  /--|----------> 00aa      	lsls	r2, r5, #2
    /* Switch clock from system */
    RCC->CFGR &= ~0x3; RCC->CFGR |= cfgr_switch;
 80004e4:	|  |  |  |  |  |            4b1c      	ldr	r3, [pc, #112]	; (8000558 <rcc_sysclk_select+0x114>)
 80004e6:	|  |  |  |  |  |            6899      	ldr	r1, [r3, #8]
 80004e8:	|  |  |  |  |  |            f021 0103 	bic.w	r1, r1, #3
 80004ec:	|  |  |  |  |  |            6099      	str	r1, [r3, #8]
 80004ee:	|  |  |  |  |  |            6899      	ldr	r1, [r3, #8]
 80004f0:	|  |  |  |  |  |            430d      	orrs	r5, r1
 80004f2:	|  |  |  |  |  |            609d      	str	r5, [r3, #8]
    /* Wait for the system complete the switch */
    while ((RCC->CFGR & cfgr_ready) != cfgr_ready);
 80004f4:	|  |  |  |  |  |        /-> 4b18      	ldr	r3, [pc, #96]	; (8000558 <rcc_sysclk_select+0x114>)
 80004f6:	|  |  |  |  |  |        |   689b      	ldr	r3, [r3, #8]
 80004f8:	|  |  |  |  |  |        |   ea32 0303 	bics.w	r3, r2, r3
 80004fc:	|  |  |  |  |  |        \-- d1fa      	bne.n	80004f4 <rcc_sysclk_select+0xb0>

    if (system_clk < SystemCoreClock)
 80004fe:	|  |  |  |  |  |            4b18      	ldr	r3, [pc, #96]	; (8000560 <rcc_sysclk_select+0x11c>)
 8000500:	|  |  |  |  |  |            6818      	ldr	r0, [r3, #0]
 8000502:	|  |  |  |  |  |            4b18      	ldr	r3, [pc, #96]	; (8000564 <rcc_sysclk_select+0x120>)
 8000504:	|  |  |  |  |  |            681b      	ldr	r3, [r3, #0]
 8000506:	|  |  |  |  |  |            4298      	cmp	r0, r3
 8000508:	|  |  |  |  |  |     /----- d320      	bcc.n	800054c <rcc_sysclk_select+0x108>
    SystemCoreClockUpdate();
 800050a:	|  |  |  |  |  |  /--|----> f7ff fe77 	bl	80001fc <SystemCoreClockUpdate>
    delay_init();
 800050e:	|  |  |  |  |  |  |  |      f000 f953 	bl	80007b8 <delay_init>
    }

    /* Update the internal monitor clock variable */
    sys_clk_update();
    /* Shutdown the other source clocks */
    RCC->CR &= ((RCC_CR_PLLON | RCC_CR_HSEON| RCC_CR_HSION) & (source | pll_request));
 8000512:	|  |  |  |  |  |  |  |      4b11      	ldr	r3, [pc, #68]	; (8000558 <rcc_sysclk_select+0x114>)
 8000514:	|  |  |  |  |  |  |  |      6818      	ldr	r0, [r3, #0]
 8000516:	|  |  |  |  |  |  |  |      4004      	ands	r4, r0
 8000518:	|  |  |  |  |  |  |  |      f004 3401 	and.w	r4, r4, #16843009	; 0x1010101
 800051c:	|  |  |  |  |  |  |  |      f424 7480 	bic.w	r4, r4, #256	; 0x100
 8000520:	|  |  |  |  |  |  |  |      601c      	str	r4, [r3, #0]
}
 8000522:	|  |  |  |  |  |  |  |      b006      	add	sp, #24
 8000524:	|  |  |  |  |  |  |  |      bd70      	pop	{r4, r5, r6, pc}
        cfgr_switch = 1;
 8000526:	|  \--|--|--|--|--|--|----> 2501      	movs	r5, #1
        RCC_CR_BIT_RD = RCC_CR_HSERDY;
 8000528:	|     |  |  |  |  |  |      f44f 3200 	mov.w	r2, #131072	; 0x20000
 800052c:	\-----|--|--|--|--|--|----- e79f      	b.n	800046e <rcc_sysclk_select+0x2a>
    switch (cfgr_switch)
 800052e:	      \--|--|--|--|--|----> 2d01      	cmp	r5, #1
 8000530:	         |  |  |  |  |  /-- d005      	beq.n	800053e <rcc_sysclk_select+0xfa>
 8000532:	         |  |  |  |  |  |   2d00      	cmp	r5, #0
 8000534:	         +--|--|--|--|--|-- d1cf      	bne.n	80004d6 <rcc_sysclk_select+0x92>
        system_clk = HSI_VALUE;
 8000536:	         |  |  |  |  |  |   4b0a      	ldr	r3, [pc, #40]	; (8000560 <rcc_sysclk_select+0x11c>)
 8000538:	         |  |  |  |  |  |   4a0b      	ldr	r2, [pc, #44]	; (8000568 <rcc_sysclk_select+0x124>)
 800053a:	         |  |  |  |  |  |   601a      	str	r2, [r3, #0]
        break;
 800053c:	         +--|--|--|--|--|-- e7cb      	b.n	80004d6 <rcc_sysclk_select+0x92>
        system_clk = HSE_VALUE;
 800053e:	         |  |  |  |  |  \-> 4b08      	ldr	r3, [pc, #32]	; (8000560 <rcc_sysclk_select+0x11c>)
 8000540:	         |  |  |  |  |      4a0a      	ldr	r2, [pc, #40]	; (800056c <rcc_sysclk_select+0x128>)
 8000542:	         |  |  |  |  |      601a      	str	r2, [r3, #0]
        break;
 8000544:	         \--|--|--|--|----- e7c7      	b.n	80004d6 <rcc_sysclk_select+0x92>
        flash_acr_config_auto(system_clk);
 8000546:	            |  \--|--|----> f000 f8c5 	bl	80006d4 <flash_acr_config_auto>
 800054a:	            \-----|--|----- e7ca      	b.n	80004e2 <rcc_sysclk_select+0x9e>
        flash_acr_config_auto(system_clk);
 800054c:	                  |  \----> f000 f8c2 	bl	80006d4 <flash_acr_config_auto>
 8000550:	                  \-------- e7db      	b.n	800050a <rcc_sysclk_select+0xc6>
 8000552:	                            bf00      	nop
 8000554:	                            0860      	lsrs	r0, r4, #1
 8000556:	                            0800      	lsrs	r0, r0, #32
 8000558:	                            3800      	subs	r0, #0
 800055a:	                            4002      	ands	r2, r0
 800055c:	                            0024      	movs	r4, r4
 800055e:	                            2000      	movs	r0, #0
 8000560:	                            0004      	movs	r4, r0
 8000562:	                            2000      	movs	r0, #0
 8000564:	                            0000      	movs	r0, r0
 8000566:	                            2000      	movs	r0, #0
 8000568:	                            2400      	movs	r4, #0
 800056a:	                            00f4      	lsls	r4, r6, #3
 800056c:	                            1200      	asrs	r0, r0, #8
 800056e:	                            007a      	lsls	r2, r7, #1

08000570 <rcc_pll_param_cpte>:

void rcc_pll_param_cpte(uint8_t pll_clk_out, rcc_pllclk_t pll_clk_in)
{
 8000570:	             b410      	push	{r4}
 8000572:	             b083      	sub	sp, #12
    pll_parameters.source = pll_clk_in;
 8000574:	             4a34      	ldr	r2, [pc, #208]	; (8000648 <rcc_pll_param_cpte+0xd8>)
 8000576:	             6091      	str	r1, [r2, #8]
    pll_parameters.freq_o = pll_clk_out * 1000000;
 8000578:	             4b34      	ldr	r3, [pc, #208]	; (800064c <rcc_pll_param_cpte+0xdc>)
 800057a:	             fb00 f303 	mul.w	r3, r0, r3
 800057e:	             6053      	str	r3, [r2, #4]

    const uint8_t pll_p[] = /* Decode table for PLL_P values */
 8000580:	             4b33      	ldr	r3, [pc, #204]	; (8000650 <rcc_pll_param_cpte+0xe0>)
 8000582:	             9301      	str	r3, [sp, #4]
    /* output vco frequency [MHz] */
    const uint32_t fvco_in = 2; 
    uint32_t fvco_out; 

    /* Determinate PLL clock */
    uint32_t __pll_clk_in = (pll_clk_in == RCC_PLLCLK_HSE) ? HSE_VALUE : HSI_VALUE;
 8000584:	             f5b1 0f80 	cmp.w	r1, #4194304	; 0x400000
 8000588:	/----------- d055      	beq.n	8000636 <rcc_pll_param_cpte+0xc6>
 800058a:	|            4c32      	ldr	r4, [pc, #200]	; (8000654 <rcc_pll_param_cpte+0xe4>)
    __pll_clk_in /= 1000000UL;

    /* Configure de max value to pll_p parameter */
    pll_parameters.p = 3; /* Bit value for request pll_p */
 800058c:	|  /-------> 4a2e      	ldr	r2, [pc, #184]	; (8000648 <rcc_pll_param_cpte+0xd8>)
 800058e:	|  |         6813      	ldr	r3, [r2, #0]
 8000590:	|  |         f443 33c0 	orr.w	r3, r3, #98304	; 0x18000
 8000594:	|  |         6013      	str	r3, [r2, #0]

    /* Determinate the minimun pll_p for request clock */
    do {
        uint8_t idx = pll_parameters.p;
 8000596:	|  |  /----> 4b2c      	ldr	r3, [pc, #176]	; (8000648 <rcc_pll_param_cpte+0xd8>)
 8000598:	|  |  |      681b      	ldr	r3, [r3, #0]
 800059a:	|  |  |      f3c3 33c1 	ubfx	r3, r3, #15, #2
        /* fvco_out = pll_out * pll_p (pag. 226 - reference manual) */
        fvco_out = pll_clk_out * pll_p[idx]; 
 800059e:	|  |  |      f103 0208 	add.w	r2, r3, #8
 80005a2:	|  |  |      446a      	add	r2, sp
 80005a4:	|  |  |      f812 2c04 	ldrb.w	r2, [r2, #-4]
 80005a8:	|  |  |      fb00 f202 	mul.w	r2, r0, r2
        if (fvco_out > RCC_PLLN_MAX_VALUE) { 
 80005ac:	|  |  |      f5b2 7fd8 	cmp.w	r2, #432	; 0x1b0
 80005b0:	|  |  |  /-- d908      	bls.n	80005c4 <rcc_pll_param_cpte+0x54>
            /* If fvco_out is major than FVCO_MAX decrease pll_p
               to get a valid value for fvco_out freq */
            pll_parameters.p -= 1;
 80005b2:	|  |  |  |   4925      	ldr	r1, [pc, #148]	; (8000648 <rcc_pll_param_cpte+0xd8>)
 80005b4:	|  |  |  |   3b01      	subs	r3, #1
 80005b6:	|  |  |  |   680a      	ldr	r2, [r1, #0]
 80005b8:	|  |  |  |   f363 32d0 	bfi	r2, r3, #15, #2
 80005bc:	|  |  |  |   600a      	str	r2, [r1, #0]
        } else {
            /* Otherwise break the while routine */
            break;
        }
    } while(pll_parameters.p > 0);
 80005be:	|  |  |  |   f412 3fc0 	tst.w	r2, #98304	; 0x18000
 80005c2:	|  |  \--|-- d1e8      	bne.n	8000596 <rcc_pll_param_cpte+0x26>
    /* Recalculate fvco with the last pll_p value */
    fvco_out = pll_clk_out * pll_p[pll_parameters.p];
 80005c4:	|  |     \-> 4a20      	ldr	r2, [pc, #128]	; (8000648 <rcc_pll_param_cpte+0xd8>)
 80005c6:	|  |         6813      	ldr	r3, [r2, #0]
 80005c8:	|  |         f3c3 33c1 	ubfx	r3, r3, #15, #2
 80005cc:	|  |         3308      	adds	r3, #8
 80005ce:	|  |         446b      	add	r3, sp
 80005d0:	|  |         f813 3c04 	ldrb.w	r3, [r3, #-4]
 80005d4:	|  |         fb00 f303 	mul.w	r3, r0, r3
    /* Compute other parameters */
    pll_parameters.m = __pll_clk_in / fvco_in;
 80005d8:	|  |         491f      	ldr	r1, [pc, #124]	; (8000658 <rcc_pll_param_cpte+0xe8>)
 80005da:	|  |         fba1 1404 	umull	r1, r4, r1, r4
 80005de:	|  |         0ce4      	lsrs	r4, r4, #19
 80005e0:	|  |         7811      	ldrb	r1, [r2, #0]
 80005e2:	|  |         f364 0105 	bfi	r1, r4, #0, #6
 80005e6:	|  |         7011      	strb	r1, [r2, #0]
    pll_parameters.n = fvco_out / fvco_in;
 80005e8:	|  |         f3c3 0448 	ubfx	r4, r3, #1, #9
 80005ec:	|  |         8811      	ldrh	r1, [r2, #0]
 80005ee:	|  |         f364 118e 	bfi	r1, r4, #6, #9
 80005f2:	|  |         8011      	strh	r1, [r2, #0]
    pll_parameters.q = fvco_out / 48;
 80005f4:	|  |         4919      	ldr	r1, [pc, #100]	; (800065c <rcc_pll_param_cpte+0xec>)
 80005f6:	|  |         fba1 1303 	umull	r1, r3, r1, r3
 80005fa:	|  |         f3c3 1343 	ubfx	r3, r3, #5, #4
 80005fe:	|  |         7891      	ldrb	r1, [r2, #2]
 8000600:	|  |         f363 0144 	bfi	r1, r3, #1, #4
 8000604:	|  |         7091      	strb	r1, [r2, #2]
    /* PLL_Q Must not be less than 2 */
    if (pll_parameters.q < 2)
 8000606:	|  |         2b01      	cmp	r3, #1
 8000608:	|  |     /-- d917      	bls.n	800063a <rcc_pll_param_cpte+0xca>
    {
        pll_parameters.q = 2;
    }
    /* Compute APB preescalers to get max bus speeds */
    pll_parameters.ppre1 = pll_clk_out / 42; /* 42MHz in APB1 case */
 800060a:	|  |  /--|-> 0843      	lsrs	r3, r0, #1
 800060c:	|  |  |  |   4914      	ldr	r1, [pc, #80]	; (8000660 <rcc_pll_param_cpte+0xf0>)
 800060e:	|  |  |  |   fba1 2303 	umull	r2, r3, r1, r3
 8000612:	|  |  |  |   089b      	lsrs	r3, r3, #2
 8000614:	|  |  |  |   4a0c      	ldr	r2, [pc, #48]	; (8000648 <rcc_pll_param_cpte+0xd8>)
 8000616:	|  |  |  |   7894      	ldrb	r4, [r2, #2]
 8000618:	|  |  |  |   f363 1447 	bfi	r4, r3, #5, #3
 800061c:	|  |  |  |   7094      	strb	r4, [r2, #2]
    pll_parameters.ppre2 = pll_clk_out / 84; /* 84MHz in APB2 case */
 800061e:	|  |  |  |   0880      	lsrs	r0, r0, #2
 8000620:	|  |  |  |   fba1 3000 	umull	r3, r0, r1, r0
 8000624:	|  |  |  |   0880      	lsrs	r0, r0, #2
 8000626:	|  |  |  |   78d3      	ldrb	r3, [r2, #3]
 8000628:	|  |  |  |   f360 0302 	bfi	r3, r0, #0, #3
 800062c:	|  |  |  |   70d3      	strb	r3, [r2, #3]
}
 800062e:	|  |  |  |   b003      	add	sp, #12
 8000630:	|  |  |  |   f85d 4b04 	ldr.w	r4, [sp], #4
 8000634:	|  |  |  |   4770      	bx	lr
    uint32_t __pll_clk_in = (pll_clk_in == RCC_PLLCLK_HSE) ? HSE_VALUE : HSI_VALUE;
 8000636:	\--|--|--|-> 4c0b      	ldr	r4, [pc, #44]	; (8000664 <rcc_pll_param_cpte+0xf4>)
 8000638:	   \--|--|-- e7a8      	b.n	800058c <rcc_pll_param_cpte+0x1c>
        pll_parameters.q = 2;
 800063a:	      |  \-> 4613      	mov	r3, r2
 800063c:	      |      b2ca      	uxtb	r2, r1
 800063e:	      |      2102      	movs	r1, #2
 8000640:	      |      f361 0244 	bfi	r2, r1, #1, #4
 8000644:	      |      709a      	strb	r2, [r3, #2]
 8000646:	      \----- e7e0      	b.n	800060a <rcc_pll_param_cpte+0x9a>
 8000648:	             0024      	movs	r4, r4
 800064a:	             2000      	movs	r0, #0
 800064c:	             4240      	negs	r0, r0
 800064e:	             000f      	movs	r7, r1
 8000650:	             0402      	lsls	r2, r0, #16
 8000652:	             0806      	lsrs	r6, r0, #32
 8000654:	             2400      	movs	r4, #0
 8000656:	             00f4      	lsls	r4, r6, #3
 8000658:	             de83      	udf	#131	; 0x83
 800065a:	             431b      	orrs	r3, r3
 800065c:	             aaab      	add	r2, sp, #684	; 0x2ac
 800065e:	             aaaa      	add	r2, sp, #680	; 0x2a8
 8000660:	             0c31      	lsrs	r1, r6, #16
 8000662:	             30c3      	adds	r0, #195	; 0xc3
 8000664:	             1200      	asrs	r0, r0, #8
 8000666:	             007a      	lsls	r2, r7, #1

08000668 <rcc_pll_param_set>:

void rcc_pll_param_set(void)
{
 8000668:	b410      	push	{r4}
    RCC->PLLCFGR |= (pll_parameters.q << RCC_PLLCFGR_PLLQ_Pos) 
 800066a:	4c0e      	ldr	r4, [pc, #56]	; (80006a4 <rcc_pll_param_set+0x3c>)
 800066c:	6861      	ldr	r1, [r4, #4]
 800066e:	4a0e      	ldr	r2, [pc, #56]	; (80006a8 <rcc_pll_param_set+0x40>)
 8000670:	7893      	ldrb	r3, [r2, #2]
 8000672:	f3c3 0043 	ubfx	r0, r3, #1, #4
        | (pll_parameters.p << RCC_PLLCFGR_PLLP_Pos)
 8000676:	6813      	ldr	r3, [r2, #0]
 8000678:	f3c3 33c1 	ubfx	r3, r3, #15, #2
 800067c:	041b      	lsls	r3, r3, #16
 800067e:	ea43 6300 	orr.w	r3, r3, r0, lsl #24
        | (pll_parameters.n << RCC_PLLCFGR_PLLN_Pos) 
 8000682:	8810      	ldrh	r0, [r2, #0]
 8000684:	f3c0 1088 	ubfx	r0, r0, #6, #9
 8000688:	ea43 1380 	orr.w	r3, r3, r0, lsl #6
        | (pll_parameters.m << RCC_PLLCFGR_PLLM_Pos) 
 800068c:	7810      	ldrb	r0, [r2, #0]
 800068e:	f000 003f 	and.w	r0, r0, #63	; 0x3f
 8000692:	4303      	orrs	r3, r0
        | (pll_parameters.source);
 8000694:	6892      	ldr	r2, [r2, #8]
 8000696:	4313      	orrs	r3, r2
    RCC->PLLCFGR |= (pll_parameters.q << RCC_PLLCFGR_PLLQ_Pos) 
 8000698:	430b      	orrs	r3, r1
 800069a:	6063      	str	r3, [r4, #4]
}
 800069c:	f85d 4b04 	ldr.w	r4, [sp], #4
 80006a0:	4770      	bx	lr
 80006a2:	bf00      	nop
 80006a4:	3800      	subs	r0, #0
 80006a6:	4002      	ands	r2, r0
 80006a8:	0024      	movs	r4, r4
 80006aa:	2000      	movs	r0, #0

080006ac <rcc_pll_param_clr>:

void rcc_pll_param_clr(void)
{
    RCC->PLLCFGR &= ~((0xF << RCC_PLLCFGR_PLLQ_Pos) 
 80006ac:	4a05      	ldr	r2, [pc, #20]	; (80006c4 <rcc_pll_param_clr+0x18>)
 80006ae:	6853      	ldr	r3, [r2, #4]
 80006b0:	f023 6374 	bic.w	r3, r3, #255852544	; 0xf400000
 80006b4:	f423 335f 	bic.w	r3, r3, #228352	; 0x37c00
 80006b8:	f423 737f 	bic.w	r3, r3, #1020	; 0x3fc
 80006bc:	f023 0303 	bic.w	r3, r3, #3
 80006c0:	6053      	str	r3, [r2, #4]
        | (0x3 << RCC_PLLCFGR_PLLP_Pos)
        | (0x1FF << RCC_PLLCFGR_PLLN_Pos) 
        | (0x3F << RCC_PLLCFGR_PLLM_Pos)
        | RCC_PLLCFGR_PLLSRC);
 80006c2:	4770      	bx	lr
 80006c4:	3800      	subs	r0, #0
 80006c6:	4002      	ands	r2, r0

080006c8 <sys_clk_update>:
{
 80006c8:	b508      	push	{r3, lr}
    SystemCoreClockUpdate();
 80006ca:	f7ff fd97 	bl	80001fc <SystemCoreClockUpdate>
    delay_init();
 80006ce:	f000 f873 	bl	80007b8 <delay_init>
}
 80006d2:	bd08      	pop	{r3, pc}

080006d4 <flash_acr_config_auto>:

#include "flash.h"

void flash_acr_config_auto(uint32_t clk)
{
    if (clk <= 30000000) {
 80006d4:	    4b2f      	ldr	r3, [pc, #188]	; (8000794 <flash_acr_config_auto+0xc0>)
 80006d6:	    4298      	cmp	r0, r3
 80006d8:	/-- d809      	bhi.n	80006ee <flash_acr_config_auto+0x1a>
 * ...
 * @endcode
 */
__FORCE_INLINE void flash_acr_config_set(flash_config_t config)
{
    FLASH->ACR &= ~config;
 80006da:	|   4b2f      	ldr	r3, [pc, #188]	; (8000798 <flash_acr_config_auto+0xc4>)
 80006dc:	|   681a      	ldr	r2, [r3, #0]
 80006de:	|   f422 62e0 	bic.w	r2, r2, #1792	; 0x700
 80006e2:	|   601a      	str	r2, [r3, #0]
    FLASH->ACR |= config;
 80006e4:	|   681a      	ldr	r2, [r3, #0]
 80006e6:	|   f442 62e0 	orr.w	r2, r2, #1792	; 0x700
 80006ea:	|   601a      	str	r2, [r3, #0]
}
 80006ec:	|   4770      	bx	lr
        flash_acr_config_set(
            FLASH_CONFIG_DCACHE | FLASH_CONFIG_ICACHE |
            FLASH_CONFIG_PREFETCH | FLASH_CONFIG_LATENCY_0WS
        );
    } 
    else if (clk <= 60000000) {
 80006ee:	\-> 4b2b      	ldr	r3, [pc, #172]	; (800079c <flash_acr_config_auto+0xc8>)
 80006f0:	    4298      	cmp	r0, r3
 80006f2:	/-- d80d      	bhi.n	8000710 <flash_acr_config_auto+0x3c>
    FLASH->ACR &= ~config;
 80006f4:	|   4a28      	ldr	r2, [pc, #160]	; (8000798 <flash_acr_config_auto+0xc4>)
 80006f6:	|   6813      	ldr	r3, [r2, #0]
 80006f8:	|   f423 63e0 	bic.w	r3, r3, #1792	; 0x700
 80006fc:	|   f023 0301 	bic.w	r3, r3, #1
 8000700:	|   6013      	str	r3, [r2, #0]
    FLASH->ACR |= config;
 8000702:	|   6813      	ldr	r3, [r2, #0]
 8000704:	|   f443 63e0 	orr.w	r3, r3, #1792	; 0x700
 8000708:	|   f043 0301 	orr.w	r3, r3, #1
 800070c:	|   6013      	str	r3, [r2, #0]
}
 800070e:	|   4770      	bx	lr
        flash_acr_config_set(
            FLASH_CONFIG_DCACHE | FLASH_CONFIG_ICACHE |
            FLASH_CONFIG_PREFETCH | FLASH_CONFIG_LATENCY_1WS
        );
    }
    else if (clk <= 90000000) {
 8000710:	\-> 4b23      	ldr	r3, [pc, #140]	; (80007a0 <flash_acr_config_auto+0xcc>)
 8000712:	    4298      	cmp	r0, r3
 8000714:	/-- d80d      	bhi.n	8000732 <flash_acr_config_auto+0x5e>
    FLASH->ACR &= ~config;
 8000716:	|   4a20      	ldr	r2, [pc, #128]	; (8000798 <flash_acr_config_auto+0xc4>)
 8000718:	|   6813      	ldr	r3, [r2, #0]
 800071a:	|   f423 63e0 	bic.w	r3, r3, #1792	; 0x700
 800071e:	|   f023 0302 	bic.w	r3, r3, #2
 8000722:	|   6013      	str	r3, [r2, #0]
    FLASH->ACR |= config;
 8000724:	|   6813      	ldr	r3, [r2, #0]
 8000726:	|   f443 63e0 	orr.w	r3, r3, #1792	; 0x700
 800072a:	|   f043 0302 	orr.w	r3, r3, #2
 800072e:	|   6013      	str	r3, [r2, #0]
}
 8000730:	|   4770      	bx	lr
        flash_acr_config_set(
            FLASH_CONFIG_DCACHE | FLASH_CONFIG_ICACHE |
            FLASH_CONFIG_PREFETCH | FLASH_CONFIG_LATENCY_2WS
        );
    }
    else if (clk <= 120000000) {
 8000732:	\-> 4b1c      	ldr	r3, [pc, #112]	; (80007a4 <flash_acr_config_auto+0xd0>)
 8000734:	    4298      	cmp	r0, r3
 8000736:	/-- d80d      	bhi.n	8000754 <flash_acr_config_auto+0x80>
    FLASH->ACR &= ~config;
 8000738:	|   4a17      	ldr	r2, [pc, #92]	; (8000798 <flash_acr_config_auto+0xc4>)
 800073a:	|   6813      	ldr	r3, [r2, #0]
 800073c:	|   f423 63e0 	bic.w	r3, r3, #1792	; 0x700
 8000740:	|   f023 0303 	bic.w	r3, r3, #3
 8000744:	|   6013      	str	r3, [r2, #0]
    FLASH->ACR |= config;
 8000746:	|   6813      	ldr	r3, [r2, #0]
 8000748:	|   f443 63e0 	orr.w	r3, r3, #1792	; 0x700
 800074c:	|   f043 0303 	orr.w	r3, r3, #3
 8000750:	|   6013      	str	r3, [r2, #0]
}
 8000752:	|   4770      	bx	lr
        flash_acr_config_set(
            FLASH_CONFIG_DCACHE | FLASH_CONFIG_ICACHE |
            FLASH_CONFIG_PREFETCH | FLASH_CONFIG_LATENCY_3WS
        );
    }
    else if (clk <= 150000000) {
 8000754:	\-> 4b14      	ldr	r3, [pc, #80]	; (80007a8 <flash_acr_config_auto+0xd4>)
 8000756:	    4298      	cmp	r0, r3
 8000758:	/-- d80d      	bhi.n	8000776 <flash_acr_config_auto+0xa2>
    FLASH->ACR &= ~config;
 800075a:	|   4a0f      	ldr	r2, [pc, #60]	; (8000798 <flash_acr_config_auto+0xc4>)
 800075c:	|   6813      	ldr	r3, [r2, #0]
 800075e:	|   f423 63e0 	bic.w	r3, r3, #1792	; 0x700
 8000762:	|   f023 0304 	bic.w	r3, r3, #4
 8000766:	|   6013      	str	r3, [r2, #0]
    FLASH->ACR |= config;
 8000768:	|   6813      	ldr	r3, [r2, #0]
 800076a:	|   f443 63e0 	orr.w	r3, r3, #1792	; 0x700
 800076e:	|   f043 0304 	orr.w	r3, r3, #4
 8000772:	|   6013      	str	r3, [r2, #0]
}
 8000774:	|   4770      	bx	lr
    FLASH->ACR &= ~config;
 8000776:	\-> 4a08      	ldr	r2, [pc, #32]	; (8000798 <flash_acr_config_auto+0xc4>)
 8000778:	    6813      	ldr	r3, [r2, #0]
 800077a:	    f423 63e0 	bic.w	r3, r3, #1792	; 0x700
 800077e:	    f023 0305 	bic.w	r3, r3, #5
 8000782:	    6013      	str	r3, [r2, #0]
    FLASH->ACR |= config;
 8000784:	    6813      	ldr	r3, [r2, #0]
 8000786:	    f443 63e0 	orr.w	r3, r3, #1792	; 0x700
 800078a:	    f043 0305 	orr.w	r3, r3, #5
 800078e:	    6013      	str	r3, [r2, #0]
        flash_acr_config_set(
            FLASH_CONFIG_DCACHE | FLASH_CONFIG_ICACHE |
            FLASH_CONFIG_PREFETCH | FLASH_CONFIG_LATENCY_5WS
        );
    }
}
 8000790:	    4770      	bx	lr
 8000792:	    bf00      	nop
 8000794:	    c380      	stmia	r3!, {r7}
 8000796:	    01c9      	lsls	r1, r1, #7
 8000798:	    3c00      	subs	r4, #0
 800079a:	    4002      	ands	r2, r0
 800079c:	    8700      	strh	r0, [r0, #56]	; 0x38
 800079e:	    0393      	lsls	r3, r2, #14
 80007a0:	    4a80      	ldr	r2, [pc, #512]	; (80009a4 <_siccmdata+0xfc>)
 80007a2:	    055d      	lsls	r5, r3, #21
 80007a4:	    0e00      	lsrs	r0, r0, #24
 80007a6:	    0727      	lsls	r7, r4, #28
 80007a8:	    d180      	bne.n	80006ac <rcc_pll_param_clr>
 80007aa:	    08f0      	lsrs	r0, r6, #3

080007ac <sys_clk_update>:
{
 80007ac:	b508      	push	{r3, lr}
    SystemCoreClockUpdate();
 80007ae:	f7ff fd25 	bl	80001fc <SystemCoreClockUpdate>
    delay_init();
 80007b2:	f000 f801 	bl	80007b8 <delay_init>
}
 80007b6:	bd08      	pop	{r3, pc}

080007b8 <delay_init>:
uint32_t DELAY_CYCLES_US;              


void delay_init (void)
{
    DELAY_CYCLES_MS = (SystemCoreClock / 1000);
 80007b8:	4b07      	ldr	r3, [pc, #28]	; (80007d8 <delay_init+0x20>)
 80007ba:	681b      	ldr	r3, [r3, #0]
 80007bc:	4a07      	ldr	r2, [pc, #28]	; (80007dc <delay_init+0x24>)
 80007be:	fba2 1303 	umull	r1, r3, r2, r3
 80007c2:	099b      	lsrs	r3, r3, #6
 80007c4:	4906      	ldr	r1, [pc, #24]	; (80007e0 <delay_init+0x28>)
 80007c6:	600b      	str	r3, [r1, #0]
    DELAY_CYCLES_US = (DELAY_CYCLES_MS / 1000);
 80007c8:	fba2 0203 	umull	r0, r2, r2, r3
 80007cc:	0992      	lsrs	r2, r2, #6
 80007ce:	4805      	ldr	r0, [pc, #20]	; (80007e4 <delay_init+0x2c>)
 80007d0:	6002      	str	r2, [r0, #0]
    DELAY_CYCLES_MS += EXTRACYCLES_PER_MS;
 80007d2:	3309      	adds	r3, #9
 80007d4:	600b      	str	r3, [r1, #0]
}
 80007d6:	4770      	bx	lr
 80007d8:	0000      	movs	r0, r0
 80007da:	2000      	movs	r0, #0
 80007dc:	4dd3      	ldr	r5, [pc, #844]	; (8000b2c <_siccmdata+0x284>)
 80007de:	1062      	asrs	r2, r4, #1
 80007e0:	0030      	movs	r0, r6
 80007e2:	2000      	movs	r0, #0
 80007e4:	0034      	movs	r4, r6
 80007e6:	2000      	movs	r0, #0

080007e8 <delay_ms>:

__attribute__((optimize("-Os")))
void delay_ms (uint32_t ms)
{
    do {
        register int32_t cycles_to_ms = DELAY_CYCLES_MS;
 80007e8:	       4a04      	ldr	r2, [pc, #16]	; (80007fc <delay_ms+0x14>)
 80007ea:	/----> 6813      	ldr	r3, [r2, #0]
        do {
            __asm("NOP");
 80007ec:	|  /-> bf00      	nop
            cycles_to_ms -= CYCLES_PER_MS;
 80007ee:	|  |   3b05      	subs	r3, #5
        } while (cycles_to_ms > 0);
 80007f0:	|  |   2b00      	cmp	r3, #0
 80007f2:	|  \-- dcfb      	bgt.n	80007ec <delay_ms+0x4>
    } while (--ms);
 80007f4:	|      3801      	subs	r0, #1
 80007f6:	\----- d1f8      	bne.n	80007ea <delay_ms+0x2>
}
 80007f8:	       4770      	bx	lr
 80007fa:	       bf00      	nop
 80007fc:	       0030      	movs	r0, r6
 80007fe:	       2000      	movs	r0, #0

08000800 <__libc_init_array>:
 8000800:	             b570      	push	{r4, r5, r6, lr}
 8000802:	             4d0d      	ldr	r5, [pc, #52]	; (8000838 <__libc_init_array+0x38>)
 8000804:	             4c0d      	ldr	r4, [pc, #52]	; (800083c <__libc_init_array+0x3c>)
 8000806:	             1b64      	subs	r4, r4, r5
 8000808:	             10a4      	asrs	r4, r4, #2
 800080a:	             2600      	movs	r6, #0
 800080c:	/----------> 42a6      	cmp	r6, r4
 800080e:	|     /----- d109      	bne.n	8000824 <__libc_init_array+0x24>
 8000810:	|     |      4d0b      	ldr	r5, [pc, #44]	; (8000840 <__libc_init_array+0x40>)
 8000812:	|     |      4c0c      	ldr	r4, [pc, #48]	; (8000844 <__libc_init_array+0x44>)
 8000814:	|     |      f000 f818 	bl	8000848 <_init>
 8000818:	|     |      1b64      	subs	r4, r4, r5
 800081a:	|     |      10a4      	asrs	r4, r4, #2
 800081c:	|     |      2600      	movs	r6, #0
 800081e:	|  /--|----> 42a6      	cmp	r6, r4
 8000820:	|  |  |  /-- d105      	bne.n	800082e <__libc_init_array+0x2e>
 8000822:	|  |  |  |   bd70      	pop	{r4, r5, r6, pc}
 8000824:	|  |  \--|-> f855 3b04 	ldr.w	r3, [r5], #4
 8000828:	|  |     |   4798      	blx	r3
 800082a:	|  |     |   3601      	adds	r6, #1
 800082c:	\--|-----|-- e7ee      	b.n	800080c <__libc_init_array+0xc>
 800082e:	   |     \-> f855 3b04 	ldr.w	r3, [r5], #4
 8000832:	   |         4798      	blx	r3
 8000834:	   |         3601      	adds	r6, #1
 8000836:	   \-------- e7f2      	b.n	800081e <__libc_init_array+0x1e>
 8000838:	             0884      	lsrs	r4, r0, #2
 800083a:	             0800      	lsrs	r0, r0, #32
 800083c:	             0884      	lsrs	r4, r0, #2
 800083e:	             0800      	lsrs	r0, r0, #32
 8000840:	             0884      	lsrs	r4, r0, #2
 8000842:	             0800      	lsrs	r0, r0, #32
 8000844:	             089c      	lsrs	r4, r3, #2
 8000846:	             0800      	lsrs	r0, r0, #32

08000848 <_init>:
 8000848:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 800084a:	bf00      	nop
 800084c:	bcf8      	pop	{r3, r4, r5, r6, r7}
 800084e:	bc08      	pop	{r3}
 8000850:	469e      	mov	lr, r3
 8000852:	4770      	bx	lr

08000854 <_fini>:
 8000854:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 8000856:	bf00      	nop
 8000858:	bcf8      	pop	{r3, r4, r5, r6, r7}
 800085a:	bc08      	pop	{r3}
 800085c:	469e      	mov	lr, r3
 800085e:	4770      	bx	lr

Disassembly of section .rodata:

08000860 <AHBPrescTable-0x14>:
 8000860:	0000      	movs	r0, r0
 8000862:	0000      	movs	r0, r0
 8000864:	0100      	lsls	r0, r0, #4
 8000866:	0000      	movs	r0, r0
 8000868:	0101      	lsls	r1, r0, #4
 800086a:	0000      	movs	r0, r0
 800086c:	0110      	lsls	r0, r2, #4
 800086e:	0000      	movs	r0, r0
 8000870:	0111      	lsls	r1, r2, #4
	...

08000874 <AHBPrescTable>:
	...
 800087c:	0201      	lsls	r1, r0, #8
 800087e:	0403      	lsls	r3, r0, #16
 8000880:	0706      	lsls	r6, r0, #28
 8000882:	0908      	lsrs	r0, r1, #4

Disassembly of section .init_array:

08000884 <__frame_dummy_init_array_entry>:
 8000884:	01cd      	lsls	r5, r1, #7
 8000886:	0800      	lsrs	r0, r0, #32
 8000888:	029d      	lsls	r5, r3, #10
 800088a:	0800      	lsrs	r0, r0, #32
 800088c:	0393      	lsls	r3, r2, #14
 800088e:	0800      	lsrs	r0, r0, #32
 8000890:	0437      	lsls	r7, r6, #16
 8000892:	0800      	lsrs	r0, r0, #32
 8000894:	06c9      	lsls	r1, r1, #27
 8000896:	0800      	lsrs	r0, r0, #32
 8000898:	07ad      	lsls	r5, r5, #30
 800089a:	0800      	lsrs	r0, r0, #32

Disassembly of section .fini_array:

0800089c <__do_global_dtors_aux_fini_array_entry>:
 800089c:	01a9      	lsls	r1, r5, #6
 800089e:	0800      	lsrs	r0, r0, #32

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
