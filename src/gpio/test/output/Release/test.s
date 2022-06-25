
output/Release/test.elf:     file format elf32-littlearm

SYMBOL TABLE:
08000000 l    d  .isr_vector	00000000 .isr_vector
080001a8 l    d  .text	00000000 .text
080006ec l    d  .rodata	00000000 .rodata
080006fc l    d  .ARM.extab	00000000 .ARM.extab
080006fc l    d  .ARM	00000000 .ARM
080006fc l    d  .preinit_array	00000000 .preinit_array
080006fc l    d  .init_array	00000000 .init_array
0800070c l    d  .fini_array	00000000 .fini_array
20000000 l    d  .data	00000000 .data
20000004 l    d  .bss	00000000 .bss
20000028 l    d  ._user_heap_stack	00000000 ._user_heap_stack
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
08000380 l       .text	00000000 LoopCopyDataInit
0800037a l       .text	00000000 CopyDataInit
08000392 l       .text	00000000 LoopFillZerobss
0800038e l       .text	00000000 FillZerobss
080003a6 l       .text	00000000 LoopCopyCCMDataInit
080003a0 l       .text	00000000 CopyCCMDataInit
080003b8 l       .text	00000000 LoopFillZeroCCMbss
080003b4 l       .text	00000000 FillZeroCCMbss
080003c4 l       .text	00000000 LoopForever
080003f4 l       .text	00000000 Infinite_Loop
00000000 l    df *ABS*	00000000 crtstuff.c
080006d4 l     O .text	00000000 __EH_FRAME_BEGIN__
080001a8 l     F .text	00000000 __do_global_dtors_aux
20000004 l       .bss	00000001 completed.1
0800070c l     O .fini_array	00000000 __do_global_dtors_aux_fini_array_entry
080001cc l     F .text	00000000 frame_dummy
20000008 l       .bss	00000018 object.0
080006fc l     O .init_array	00000000 __frame_dummy_init_array_entry
00000000 l    df *ABS*	00000000 system_stm32f4xx.c
00000000 l    df *ABS*	00000000 main.c
0800026c l     F .text	0000000e sys_clk_update
00000000 l    df *ABS*	00000000 gpio.c
0800044c l     F .text	0000000e sys_clk_update
00000000 l    df *ABS*	00000000 delay.c
08000628 l     F .text	0000000e sys_clk_update
20000020 l     O .bss	00000004 DELAY_CYCLES_MS
00000000 l    df *ABS*	00000000 init.c
00000000 l    df *ABS*	00000000 crti.o
00000000 l    df *ABS*	00000000 crtn.o
00000000 l    df *ABS*	00000000 
0800070c l       .init_array	00000000 __init_array_end
080006fc l       .preinit_array	00000000 __preinit_array_end
080006fc l       .init_array	00000000 __init_array_start
080006fc l       .preinit_array	00000000 __preinit_array_start
080003f4  w    F .text	00000002 RTC_Alarm_IRQHandler
080003f4  w    F .text	00000002 HASH_RNG_IRQHandler
080003f4  w    F .text	00000002 EXTI2_IRQHandler
080003f4  w    F .text	00000002 TIM8_CC_IRQHandler
080003f4  w    F .text	00000002 DebugMon_Handler
10000000 g       .ccmbss	00000000 _eccmbss
0800045c g     F .text	000000c4 gpio_config_all
080003f4  w    F .text	00000002 TIM1_CC_IRQHandler
080003f4  w    F .text	00000002 DMA2_Stream5_IRQHandler
080003f4  w    F .text	00000002 HardFault_Handler
080003f4  w    F .text	00000002 DMA1_Stream5_IRQHandler
00000400 g       *ABS*	00000000 _Min_Stack_Size
080003f4  w    F .text	00000002 SysTick_Handler
080003f4  w    F .text	00000002 PVD_IRQHandler
080003f4  w    F .text	00000002 SDIO_IRQHandler
080003f4  w    F .text	00000002 TAMP_STAMP_IRQHandler
08000710 g       *ABS*	00000000 _sidata
080003f4  w    F .text	00000002 PendSV_Handler
080003f4  w    F .text	00000002 NMI_Handler
080006fc g       .ARM	00000000 __exidx_end
080003f4  w    F .text	00000002 CAN2_RX1_IRQHandler
080003f4  w    F .text	00000002 EXTI3_IRQHandler
080003f4  w    F .text	00000002 TIM8_TRG_COM_TIM14_IRQHandler
080003f4  w    F .text	00000002 TIM1_UP_TIM10_IRQHandler
080006ec g       .text	00000000 _etext
20000004 g       .bss	00000000 _sbss
080003f4  w    F .text	00000002 TIM8_UP_TIM13_IRQHandler
080003f4  w    F .text	00000002 I2C3_ER_IRQHandler
080003f4  w    F .text	00000002 LCD_TFT_IRQHandler
080003f4  w    F .text	00000002 EXTI0_IRQHandler
080003f4  w    F .text	00000002 I2C2_EV_IRQHandler
080003f4  w    F .text	00000002 DMA1_Stream2_IRQHandler
080003f4  w    F .text	00000002 CAN1_RX0_IRQHandler
080003f4  w    F .text	00000002 FPU_IRQHandler
20000000 g     O .data	00000004 SystemCoreClock
080003f4  w    F .text	00000002 OTG_HS_WKUP_IRQHandler
080003f4  w    F .text	00000002 UsageFault_Handler
080003f4  w    F .text	00000002 CAN2_SCE_IRQHandler
080003f4  w    F .text	00000002 DMA2_Stream2_IRQHandler
20000004 g       .bss	00000000 __bss_start__
08000520 g     F .text	00000030 gpio_config_mode
20000000 g       .data	00000000 _sdata
080003f4  w    F .text	00000002 SPI1_IRQHandler
080003f4  w    F .text	00000002 TIM6_DAC_IRQHandler
080003f4  w    F .text	00000002 TIM1_BRK_TIM9_IRQHandler
080003f4  w    F .text	00000002 DCMI_IRQHandler
080003f4  w    F .text	00000002 CAN2_RX0_IRQHandler
10000000 g       .ccmdata	00000000 _sccmdata
080006fc g       .ARM	00000000 __exidx_start
080003f4  w    F .text	00000002 DMA2_Stream3_IRQHandler
0800068c g     F .text	00000048 __libc_init_array
40024000 g       .bram	00000000 _sbram
10000000 g       .ccmbss	00000000 _sccmbss
080005b0 g     F .text	00000078 gpio_config_af
080003f8 g     F .text	00000052 gpio_config_lock
080003f4  w    F .text	00000002 USART6_IRQHandler
080006d4 g     F .text	00000000 _init
080003f4  w    F .text	00000002 USART3_IRQHandler
080003f4  w    F .text	00000002 CRYP_IRQHandler
20000028 g       .bss	00000000 _ebss
08000368  w    F .text	0000005e Reset_Handler
080003f4  w    F .text	00000002 CAN1_RX1_IRQHandler
080003f4  w    F .text	00000002 UART5_IRQHandler
080003f4  w    F .text	00000002 DMA2_Stream0_IRQHandler
080003f4  w    F .text	00000002 TIM4_IRQHandler
080003f4  w    F .text	00000002 I2C1_EV_IRQHandler
080003f4  w    F .text	00000002 DMA1_Stream6_IRQHandler
080003f4  w    F .text	00000002 DMA1_Stream1_IRQHandler
080003f4  w    F .text	00000002 UART4_IRQHandler
20000028 g       .bss	00000000 __bss_end__
080003f4  w    F .text	00000002 LCD_TFT_1_IRQHandler
080003f4  w    F .text	00000002 TIM3_IRQHandler
08000714 g       *ABS*	00000000 _siccmdata
080003f4  w    F .text	00000002 RCC_IRQHandler
080003f4  w    F .text	00000002 TIM8_BRK_TIM12_IRQHandler
08000550 g     F .text	00000030 gpio_config_speed
00000000 g       *ABS*	00000000 _Min_Heap_Size
080003f4 g       .text	00000002 Default_Handler
08000638 g     F .text	0000003c delay_init
080006ec g     O .rodata	00000010 AHBPrescTable
08000580 g     F .text	00000030 gpio_config_input_pull_mode
080003f4  w    F .text	00000002 EXTI15_10_IRQHandler
080003f4  w    F .text	00000002 ADC_IRQHandler
080003f4  w    F .text	00000002 DMA1_Stream7_IRQHandler
080003f4  w    F .text	00000002 TIM7_IRQHandler
080003f4  w    F .text	00000002 CAN2_TX_IRQHandler
080003f4  w    F .text	00000002 TIM5_IRQHandler
080003f4  w    F .text	00000002 DMA2_Stream7_IRQHandler
080003f4  w    F .text	00000002 I2C3_EV_IRQHandler
20000024 g     O .bss	00000004 DELAY_CYCLES_US
080003f4  w    F .text	00000002 EXTI9_5_IRQHandler
080003f4  w    F .text	00000002 RTC_WKUP_IRQHandler
080003f4  w    F .text	00000002 ETH_WKUP_IRQHandler
080003f4  w    F .text	00000002 SPI2_IRQHandler
080003f4  w    F .text	00000002 OTG_HS_EP1_IN_IRQHandler
080003f4  w    F .text	00000002 MemManage_Handler
0800027c g     F .text	000000ec main
08000674 g     F .text	00000018 delay_ms
080003f4  w    F .text	00000002 DMA1_Stream0_IRQHandler
080003f4  w    F .text	00000002 CAN1_TX_IRQHandler
080003f4  w    F .text	00000002 SVC_Handler
080003f4  w    F .text	00000002 EXTI4_IRQHandler
080001e8 g     F .text	00000014 SystemInit
080006e0 g     F .text	00000000 _fini
080003f4  w    F .text	00000002 FSMC_IRQHandler
080003f4  w    F .text	00000002 ETH_IRQHandler
080003f4  w    F .text	00000002 OTG_HS_EP1_OUT_IRQHandler
080003f4  w    F .text	00000002 WWDG_IRQHandler
080003f4  w    F .text	00000002 TIM2_IRQHandler
080003f4  w    F .text	00000002 OTG_FS_WKUP_IRQHandler
080003f4  w    F .text	00000002 TIM1_TRG_COM_TIM11_IRQHandler
080003f4  w    F .text	00000002 OTG_HS_IRQHandler
20020000 g       .isr_vector	00000000 _estack
080003f4  w    F .text	00000002 EXTI1_IRQHandler
20000004 g       .data	00000000 _edata
080003f4  w    F .text	00000002 USART2_IRQHandler
08000000 g     O .isr_vector	00000000 g_pfnVectors
080001fc g     F .text	00000070 SystemCoreClockUpdate
080003f4  w    F .text	00000002 I2C2_ER_IRQHandler
080003f4  w    F .text	00000002 DMA2_Stream1_IRQHandler
080003f4  w    F .text	00000002 CAN1_SCE_IRQHandler
080003f4  w    F .text	00000002 DMA2_Stream4_IRQHandler
40024000 g       .bram	00000000 _ebram
080003f4  w    F .text	00000002 BusFault_Handler
080003f4  w    F .text	00000002 USART1_IRQHandler
080003f4  w    F .text	00000002 OTG_FS_IRQHandler
080003f4  w    F .text	00000002 SPI3_IRQHandler
080003f4  w    F .text	00000002 DMA1_Stream4_IRQHandler
080003f4  w    F .text	00000002 I2C1_ER_IRQHandler
10000000 g       .ccmdata	00000000 _eccmdata
080003f4  w    F .text	00000002 DMA2_Stream6_IRQHandler
080003f4  w    F .text	00000002 DMA1_Stream3_IRQHandler



Disassembly of section .isr_vector:

08000000 <g_pfnVectors>:
 8000000:	0000      	movs	r0, r0
 8000002:	2002      	movs	r0, #2
 8000004:	0369      	lsls	r1, r5, #13
 8000006:	0800      	lsrs	r0, r0, #32
 8000008:	03f5      	lsls	r5, r6, #15
 800000a:	0800      	lsrs	r0, r0, #32
 800000c:	03f5      	lsls	r5, r6, #15
 800000e:	0800      	lsrs	r0, r0, #32
 8000010:	03f5      	lsls	r5, r6, #15
 8000012:	0800      	lsrs	r0, r0, #32
 8000014:	03f5      	lsls	r5, r6, #15
 8000016:	0800      	lsrs	r0, r0, #32
 8000018:	03f5      	lsls	r5, r6, #15
 800001a:	0800      	lsrs	r0, r0, #32
	...
 800002c:	03f5      	lsls	r5, r6, #15
 800002e:	0800      	lsrs	r0, r0, #32
 8000030:	03f5      	lsls	r5, r6, #15
 8000032:	0800      	lsrs	r0, r0, #32
 8000034:	0000      	movs	r0, r0
 8000036:	0000      	movs	r0, r0
 8000038:	03f5      	lsls	r5, r6, #15
 800003a:	0800      	lsrs	r0, r0, #32
 800003c:	03f5      	lsls	r5, r6, #15
 800003e:	0800      	lsrs	r0, r0, #32
 8000040:	03f5      	lsls	r5, r6, #15
 8000042:	0800      	lsrs	r0, r0, #32
 8000044:	03f5      	lsls	r5, r6, #15
 8000046:	0800      	lsrs	r0, r0, #32
 8000048:	03f5      	lsls	r5, r6, #15
 800004a:	0800      	lsrs	r0, r0, #32
 800004c:	03f5      	lsls	r5, r6, #15
 800004e:	0800      	lsrs	r0, r0, #32
 8000050:	0000      	movs	r0, r0
 8000052:	0000      	movs	r0, r0
 8000054:	03f5      	lsls	r5, r6, #15
 8000056:	0800      	lsrs	r0, r0, #32
 8000058:	03f5      	lsls	r5, r6, #15
 800005a:	0800      	lsrs	r0, r0, #32
 800005c:	03f5      	lsls	r5, r6, #15
 800005e:	0800      	lsrs	r0, r0, #32
 8000060:	03f5      	lsls	r5, r6, #15
 8000062:	0800      	lsrs	r0, r0, #32
 8000064:	03f5      	lsls	r5, r6, #15
 8000066:	0800      	lsrs	r0, r0, #32
 8000068:	03f5      	lsls	r5, r6, #15
 800006a:	0800      	lsrs	r0, r0, #32
 800006c:	03f5      	lsls	r5, r6, #15
 800006e:	0800      	lsrs	r0, r0, #32
 8000070:	03f5      	lsls	r5, r6, #15
 8000072:	0800      	lsrs	r0, r0, #32
 8000074:	03f5      	lsls	r5, r6, #15
 8000076:	0800      	lsrs	r0, r0, #32
 8000078:	03f5      	lsls	r5, r6, #15
 800007a:	0800      	lsrs	r0, r0, #32
 800007c:	03f5      	lsls	r5, r6, #15
 800007e:	0800      	lsrs	r0, r0, #32
 8000080:	03f5      	lsls	r5, r6, #15
 8000082:	0800      	lsrs	r0, r0, #32
 8000084:	03f5      	lsls	r5, r6, #15
 8000086:	0800      	lsrs	r0, r0, #32
 8000088:	03f5      	lsls	r5, r6, #15
 800008a:	0800      	lsrs	r0, r0, #32
 800008c:	03f5      	lsls	r5, r6, #15
 800008e:	0800      	lsrs	r0, r0, #32
 8000090:	03f5      	lsls	r5, r6, #15
 8000092:	0800      	lsrs	r0, r0, #32
 8000094:	03f5      	lsls	r5, r6, #15
 8000096:	0800      	lsrs	r0, r0, #32
 8000098:	03f5      	lsls	r5, r6, #15
 800009a:	0800      	lsrs	r0, r0, #32
 800009c:	03f5      	lsls	r5, r6, #15
 800009e:	0800      	lsrs	r0, r0, #32
 80000a0:	03f5      	lsls	r5, r6, #15
 80000a2:	0800      	lsrs	r0, r0, #32
 80000a4:	03f5      	lsls	r5, r6, #15
 80000a6:	0800      	lsrs	r0, r0, #32
 80000a8:	03f5      	lsls	r5, r6, #15
 80000aa:	0800      	lsrs	r0, r0, #32
 80000ac:	03f5      	lsls	r5, r6, #15
 80000ae:	0800      	lsrs	r0, r0, #32
 80000b0:	03f5      	lsls	r5, r6, #15
 80000b2:	0800      	lsrs	r0, r0, #32
 80000b4:	03f5      	lsls	r5, r6, #15
 80000b6:	0800      	lsrs	r0, r0, #32
 80000b8:	03f5      	lsls	r5, r6, #15
 80000ba:	0800      	lsrs	r0, r0, #32
 80000bc:	03f5      	lsls	r5, r6, #15
 80000be:	0800      	lsrs	r0, r0, #32
 80000c0:	03f5      	lsls	r5, r6, #15
 80000c2:	0800      	lsrs	r0, r0, #32
 80000c4:	03f5      	lsls	r5, r6, #15
 80000c6:	0800      	lsrs	r0, r0, #32
 80000c8:	03f5      	lsls	r5, r6, #15
 80000ca:	0800      	lsrs	r0, r0, #32
 80000cc:	03f5      	lsls	r5, r6, #15
 80000ce:	0800      	lsrs	r0, r0, #32
 80000d0:	03f5      	lsls	r5, r6, #15
 80000d2:	0800      	lsrs	r0, r0, #32
 80000d4:	03f5      	lsls	r5, r6, #15
 80000d6:	0800      	lsrs	r0, r0, #32
 80000d8:	03f5      	lsls	r5, r6, #15
 80000da:	0800      	lsrs	r0, r0, #32
 80000dc:	03f5      	lsls	r5, r6, #15
 80000de:	0800      	lsrs	r0, r0, #32
 80000e0:	03f5      	lsls	r5, r6, #15
 80000e2:	0800      	lsrs	r0, r0, #32
 80000e4:	03f5      	lsls	r5, r6, #15
 80000e6:	0800      	lsrs	r0, r0, #32
 80000e8:	03f5      	lsls	r5, r6, #15
 80000ea:	0800      	lsrs	r0, r0, #32
 80000ec:	03f5      	lsls	r5, r6, #15
 80000ee:	0800      	lsrs	r0, r0, #32
 80000f0:	03f5      	lsls	r5, r6, #15
 80000f2:	0800      	lsrs	r0, r0, #32
 80000f4:	03f5      	lsls	r5, r6, #15
 80000f6:	0800      	lsrs	r0, r0, #32
 80000f8:	03f5      	lsls	r5, r6, #15
 80000fa:	0800      	lsrs	r0, r0, #32
 80000fc:	03f5      	lsls	r5, r6, #15
 80000fe:	0800      	lsrs	r0, r0, #32
 8000100:	03f5      	lsls	r5, r6, #15
 8000102:	0800      	lsrs	r0, r0, #32
 8000104:	03f5      	lsls	r5, r6, #15
 8000106:	0800      	lsrs	r0, r0, #32
 8000108:	03f5      	lsls	r5, r6, #15
 800010a:	0800      	lsrs	r0, r0, #32
 800010c:	03f5      	lsls	r5, r6, #15
 800010e:	0800      	lsrs	r0, r0, #32
 8000110:	03f5      	lsls	r5, r6, #15
 8000112:	0800      	lsrs	r0, r0, #32
 8000114:	03f5      	lsls	r5, r6, #15
 8000116:	0800      	lsrs	r0, r0, #32
 8000118:	03f5      	lsls	r5, r6, #15
 800011a:	0800      	lsrs	r0, r0, #32
 800011c:	03f5      	lsls	r5, r6, #15
 800011e:	0800      	lsrs	r0, r0, #32
 8000120:	03f5      	lsls	r5, r6, #15
 8000122:	0800      	lsrs	r0, r0, #32
 8000124:	03f5      	lsls	r5, r6, #15
 8000126:	0800      	lsrs	r0, r0, #32
 8000128:	03f5      	lsls	r5, r6, #15
 800012a:	0800      	lsrs	r0, r0, #32
 800012c:	03f5      	lsls	r5, r6, #15
 800012e:	0800      	lsrs	r0, r0, #32
 8000130:	03f5      	lsls	r5, r6, #15
 8000132:	0800      	lsrs	r0, r0, #32
 8000134:	03f5      	lsls	r5, r6, #15
 8000136:	0800      	lsrs	r0, r0, #32
 8000138:	03f5      	lsls	r5, r6, #15
 800013a:	0800      	lsrs	r0, r0, #32
 800013c:	03f5      	lsls	r5, r6, #15
 800013e:	0800      	lsrs	r0, r0, #32
 8000140:	03f5      	lsls	r5, r6, #15
 8000142:	0800      	lsrs	r0, r0, #32
 8000144:	03f5      	lsls	r5, r6, #15
 8000146:	0800      	lsrs	r0, r0, #32
 8000148:	03f5      	lsls	r5, r6, #15
 800014a:	0800      	lsrs	r0, r0, #32
 800014c:	03f5      	lsls	r5, r6, #15
 800014e:	0800      	lsrs	r0, r0, #32
 8000150:	03f5      	lsls	r5, r6, #15
 8000152:	0800      	lsrs	r0, r0, #32
 8000154:	03f5      	lsls	r5, r6, #15
 8000156:	0800      	lsrs	r0, r0, #32
 8000158:	03f5      	lsls	r5, r6, #15
 800015a:	0800      	lsrs	r0, r0, #32
 800015c:	03f5      	lsls	r5, r6, #15
 800015e:	0800      	lsrs	r0, r0, #32
 8000160:	03f5      	lsls	r5, r6, #15
 8000162:	0800      	lsrs	r0, r0, #32
 8000164:	03f5      	lsls	r5, r6, #15
 8000166:	0800      	lsrs	r0, r0, #32
 8000168:	03f5      	lsls	r5, r6, #15
 800016a:	0800      	lsrs	r0, r0, #32
 800016c:	03f5      	lsls	r5, r6, #15
 800016e:	0800      	lsrs	r0, r0, #32
 8000170:	03f5      	lsls	r5, r6, #15
 8000172:	0800      	lsrs	r0, r0, #32
 8000174:	03f5      	lsls	r5, r6, #15
 8000176:	0800      	lsrs	r0, r0, #32
 8000178:	03f5      	lsls	r5, r6, #15
 800017a:	0800      	lsrs	r0, r0, #32
 800017c:	03f5      	lsls	r5, r6, #15
 800017e:	0800      	lsrs	r0, r0, #32
 8000180:	03f5      	lsls	r5, r6, #15
 8000182:	0800      	lsrs	r0, r0, #32
 8000184:	03f5      	lsls	r5, r6, #15
 8000186:	0800      	lsrs	r0, r0, #32
	...
 80001a0:	03f5      	lsls	r5, r6, #15
 80001a2:	0800      	lsrs	r0, r0, #32
 80001a4:	03f5      	lsls	r5, r6, #15
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
 80001c8:	       06d4      	lsls	r4, r2, #27
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
 80001e4:	    06d4      	lsls	r4, r2, #27
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
 8000260:	          06ec      	lsls	r4, r5, #27
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
 8000276:	f000 b9df 	b.w	8000638 <delay_init>
 800027a:	bf00      	nop

0800027c <main>:
    GPIO_IO3, /*!< Button K1 on board */ 
    GPIO_IO4  /*!< Button K0 on board */ 
};

int main (void)
{
 800027c:	       b508      	push	{r3, lr}
    SystemCoreClockUpdate();
 800027e:	       f7ff ffbd 	bl	80001fc <SystemCoreClockUpdate>
    delay_init();
 8000282:	       f000 f9d9 	bl	8000638 <delay_init>
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_en_ahb1(rcc_ahb1_t mask)
{
    RCC->AHB1ENR |= mask;
 8000286:	       4b35      	ldr	r3, [pc, #212]	; (800035c <main+0xe0>)

    /* GPIOB RCC clock should be disabled ---------------------------------|*/
    gpio_clk_dis(GPIOB_RCC);                                         /*<-|*/  /*[ok]*/

    /* GPIOA leds[1:0] should be configured as output pins ----------------|*/
    gpio_config_mode(GPIOA, GPIO_MODE_OUTPUT, leds[0] | leds[1]);      /*<-|*/  /*[ok]*/
 8000288:	       4c35      	ldr	r4, [pc, #212]	; (8000360 <main+0xe4>)
 800028a:	       6b19      	ldr	r1, [r3, #48]	; 0x30
 800028c:	       f041 0113 	orr.w	r1, r1, #19
 8000290:	       6319      	str	r1, [r3, #48]	; 0x30
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_dis_ahb1(rcc_ahb1_t mask)
{
    RCC->AHB1ENR &= ~mask;
 8000292:	       6b18      	ldr	r0, [r3, #48]	; 0x30
 8000294:	       f020 0002 	bic.w	r0, r0, #2
 8000298:	       6318      	str	r0, [r3, #48]	; 0x30
 800029a:	       22c0      	movs	r2, #192	; 0xc0
 800029c:	       2101      	movs	r1, #1
 800029e:	       4620      	mov	r0, r4
 80002a0:	       f000 f93e 	bl	8000520 <gpio_config_mode>
 * ...
 * @endcode
 */
__FORCE_INLINE void gpio_port_set (GPIO_TypeDef *gpio, gpio_io_t mask)
{
    gpio->BSRR |= mask;
 80002a4:	       69a3      	ldr	r3, [r4, #24]

    /* GPIOA_OTYPER[6] should be 0 [Push-Pull] ----------------------------|*/
    gpio_config_output_mode(GPIOA, GPIO_OUTPUT_PP, GPIO_IO6);          /*<-|*/  /*[]*/

    /* GPIOE buttons[1:0] should be configured as input pull-up pins ------|*/
    gpio_config_all(                                                     /*|*/
 80002a6:	       482f      	ldr	r0, [pc, #188]	; (8000364 <main+0xe8>)
 80002a8:	       f043 03c0 	orr.w	r3, r3, #192	; 0xc0
 80002ac:	       61a3      	str	r3, [r4, #24]
 * ...
 * @endcode
 */
__FORCE_INLINE void gpio_port_clr (GPIO_TypeDef *gpio, gpio_io_t mask)
{
    gpio->BSRR |= mask << 16;
 80002ae:	       69a3      	ldr	r3, [r4, #24]
 80002b0:	       f443 0380 	orr.w	r3, r3, #4194304	; 0x400000
 80002b4:	       61a3      	str	r3, [r4, #24]
    gpio->OTYPER &= ~mask;
 80002b6:	       6863      	ldr	r3, [r4, #4]
 80002b8:	       f023 0340 	bic.w	r3, r3, #64	; 0x40
 80002bc:	       6063      	str	r3, [r4, #4]
        gpio->OTYPER |= mask;
 80002be:	       6863      	ldr	r3, [r4, #4]
 80002c0:	       f043 0340 	orr.w	r3, r3, #64	; 0x40
 80002c4:	       6063      	str	r3, [r4, #4]
    gpio->OTYPER &= ~mask;
 80002c6:	       6863      	ldr	r3, [r4, #4]
 80002c8:	       f023 0340 	bic.w	r3, r3, #64	; 0x40
 80002cc:	       2218      	movs	r2, #24
 80002ce:	       f44f 61a1 	mov.w	r1, #1288	; 0x508
 80002d2:	       6063      	str	r3, [r4, #4]
 80002d4:	       f000 f8c2 	bl	800045c <gpio_config_all>
 * ...
 * @endcode
 */
__FORCE_INLINE uint16_t gpio_port_read_input (GPIO_TypeDef *gpio)
{
    return gpio->IDR;
 80002d8:	       4a22      	ldr	r2, [pc, #136]	; (8000364 <main+0xe8>)
 80002da:	   /-> 6913      	ldr	r3, [r2, #16]
        GPIO_CONFIG_MODE_INPUT | GPIO_CONFIG_PULL_UP,                    /*|*/
        buttons[0] | buttons[1]                                          /*|*/
    );                                                                 /*<-|*/  /*[ok]*/

    /* GPIOE input should be 1 up to press button -------------------------|*/
    while((gpio_port_read_input(GPIOE) & buttons[0]) != 0);            /*<-|*/  /*[ok]*/
 80002dc:	   |   071b      	lsls	r3, r3, #28
 80002de:	   \-- d4fc      	bmi.n	80002da <main+0x5e>
 80002e0:	       6913      	ldr	r3, [r2, #16]

    /* It should stay on 'while' while the buttons K0 & K1 don´t be pressed at
       same time ----------------------------------------------------------|*/
    while(gpio_port_read_input_mask(GPIOE, buttons[0] | buttons[1])!=0)  /*|*/
 80002e2:	       f013 0f18 	tst.w	r3, #24
 80002e6:	/----- d00d      	beq.n	8000304 <main+0x88>
    gpio->ODR ^= mask;
 80002e8:	|      4c1d      	ldr	r4, [pc, #116]	; (8000360 <main+0xe4>)
    return gpio->IDR;
 80002ea:	|      4d1e      	ldr	r5, [pc, #120]	; (8000364 <main+0xe8>)
    gpio->ODR ^= mask;
 80002ec:	|  /-> 6963      	ldr	r3, [r4, #20]
 80002ee:	|  |   f083 0340 	eor.w	r3, r3, #64	; 0x40
 80002f2:	|  |   6163      	str	r3, [r4, #20]
    {                                                                    /*|*/
        /* LED D2 should toggle every second --|                           |*/
        gpio_port_tgl(GPIOA, leds[0]);       /*|                           |*/  
        delay_ms(1000);                    /*<-|                           |*/  /*[ok]*/
 80002f4:	|  |   f44f 707a 	mov.w	r0, #1000	; 0x3e8
 80002f8:	|  |   f000 f9bc 	bl	8000674 <delay_ms>
    return gpio->IDR;
 80002fc:	|  |   692b      	ldr	r3, [r5, #16]
    while(gpio_port_read_input_mask(GPIOE, buttons[0] | buttons[1])!=0)  /*|*/
 80002fe:	|  |   f013 0f18 	tst.w	r3, #24
 8000302:	|  \-- d1f3      	bne.n	80002ec <main+0x70>
    }                                                                  /*<-|*/  /*[ok]*/

    delay_ms(1999);
 8000304:	\----> f240 70cf 	movw	r0, #1999	; 0x7cf
 8000308:	       f000 f9b4 	bl	8000674 <delay_ms>

    /* It should lock the button[0] config [If lock sequence fail bucles the
       program] -----------------------------------------------------------|*/
    while(gpio_config_lock(GPIOE, buttons[0]) == 1);                   /*<-|*/  /*[ok?]*/ /*?: Apparently sometimes fails*/
 800030c:	       4c15      	ldr	r4, [pc, #84]	; (8000364 <main+0xe8>)
 800030e:	   /-> 2108      	movs	r1, #8
 8000310:	   |   4620      	mov	r0, r4
 8000312:	   |   f000 f871 	bl	80003f8 <gpio_config_lock>
 8000316:	   |   2801      	cmp	r0, #1
 8000318:	   \-- d0f9      	beq.n	800030e <main+0x92>

    /* Config should be applied only on the button[1] ---------------------|*/
    gpio_config_input_pull_mode(                                         /*|*/
 800031a:	       4812      	ldr	r0, [pc, #72]	; (8000364 <main+0xe8>)
    gpio->BSRR |= mask;
 800031c:	       4c10      	ldr	r4, [pc, #64]	; (8000360 <main+0xe4>)
 800031e:	       2218      	movs	r2, #24
 8000320:	       2100      	movs	r1, #0
 8000322:	       f000 f92d 	bl	8000580 <gpio_config_input_pull_mode>
        GPIO_PULL_NONE,                                                  /*|*/
        buttons[0] | buttons[1]                                          /*|*/
    );                                                                 /*<-|*/  /*[ok]*/

    /* LED D2 [GPIOA6] should have low speed mode output ------------------|*/
    gpio_config_speed(GPIOA, GPIO_SPEED_MEDIUM, leds[0]);              /*<-|*/  /*[ok]*/
 8000326:	       480e      	ldr	r0, [pc, #56]	; (8000360 <main+0xe4>)
 8000328:	       2240      	movs	r2, #64	; 0x40
 800032a:	       2101      	movs	r1, #1
 800032c:	       f000 f910 	bl	8000550 <gpio_config_speed>

    /* GPIOA[15,0] should have been configured as AF1 Alternate function --|*/
    gpio_config_af(GPIOA, GPIO_ALT_AF1, GPIO_IO15 | GPIO_IO0);         /*<-|*/  /*[ok]*/
 8000330:	       480b      	ldr	r0, [pc, #44]	; (8000360 <main+0xe4>)
 8000332:	       f248 0201 	movw	r2, #32769	; 0x8001
 8000336:	       2101      	movs	r1, #1
 8000338:	       f000 f93a 	bl	80005b0 <gpio_config_af>
 800033c:	   /-> 69a3      	ldr	r3, [r4, #24]
 800033e:	   |   f043 03c0 	orr.w	r3, r3, #192	; 0xc0
 8000342:	   |   61a3      	str	r3, [r4, #24]

    while (1)
    {
        /* LEDS should blink every second if everyting is fine ------------|*/
        gpio_port_set(GPIOA, leds[0] | leds[1]);                         /*|*/
        delay_ms(20);                                                    /*|*/
 8000344:	   |   2014      	movs	r0, #20
 8000346:	   |   f000 f995 	bl	8000674 <delay_ms>
    gpio->BSRR |= mask << 16;
 800034a:	   |   69a3      	ldr	r3, [r4, #24]
 800034c:	   |   f443 0340 	orr.w	r3, r3, #12582912	; 0xc00000
        gpio_port_clr(GPIOA, leds[0] | leds[1]);                         /*|*/
        delay_ms(979);                                                 /*<-|*/  /*[ok]*/
 8000350:	   |   f240 30d3 	movw	r0, #979	; 0x3d3
 8000354:	   |   61a3      	str	r3, [r4, #24]
 8000356:	   |   f000 f98d 	bl	8000674 <delay_ms>
    while (1)
 800035a:	   \-- e7ef      	b.n	800033c <main+0xc0>
 800035c:	       3800      	subs	r0, #0
 800035e:	       4002      	ands	r2, r0
 8000360:	       0000      	movs	r0, r0
 8000362:	       4002      	ands	r2, r0
 8000364:	       1000      	asrs	r0, r0, #32
 8000366:	       4002      	ands	r2, r0

08000368 <Reset_Handler>:
 8000368:	4817      	ldr	r0, [pc, #92]	; (80003c8 <LoopForever+0x4>)
 800036a:	4685      	mov	sp, r0
 800036c:	f7ff ff3c 	bl	80001e8 <SystemInit>
 8000370:	4816      	ldr	r0, [pc, #88]	; (80003cc <LoopForever+0x8>)
 8000372:	4917      	ldr	r1, [pc, #92]	; (80003d0 <LoopForever+0xc>)
 8000374:	4a17      	ldr	r2, [pc, #92]	; (80003d4 <LoopForever+0x10>)
 8000376:	2300      	movs	r3, #0
 8000378:	e002      	b.n	8000380 <LoopCopyDataInit>

0800037a <CopyDataInit>:
 800037a:	58d4      	ldr	r4, [r2, r3]
 800037c:	50c4      	str	r4, [r0, r3]
 800037e:	3304      	adds	r3, #4

08000380 <LoopCopyDataInit>:
 8000380:	18c4      	adds	r4, r0, r3
 8000382:	428c      	cmp	r4, r1
 8000384:	d3f9      	bcc.n	800037a <CopyDataInit>
 8000386:	4a14      	ldr	r2, [pc, #80]	; (80003d8 <LoopForever+0x14>)
 8000388:	4c14      	ldr	r4, [pc, #80]	; (80003dc <LoopForever+0x18>)
 800038a:	2300      	movs	r3, #0
 800038c:	e001      	b.n	8000392 <LoopFillZerobss>

0800038e <FillZerobss>:
 800038e:	6013      	str	r3, [r2, #0]
 8000390:	3204      	adds	r2, #4

08000392 <LoopFillZerobss>:
 8000392:	42a2      	cmp	r2, r4
 8000394:	d3fb      	bcc.n	800038e <FillZerobss>
 8000396:	4812      	ldr	r0, [pc, #72]	; (80003e0 <LoopForever+0x1c>)
 8000398:	4912      	ldr	r1, [pc, #72]	; (80003e4 <LoopForever+0x20>)
 800039a:	4a13      	ldr	r2, [pc, #76]	; (80003e8 <LoopForever+0x24>)
 800039c:	2300      	movs	r3, #0
 800039e:	e002      	b.n	80003a6 <LoopCopyCCMDataInit>

080003a0 <CopyCCMDataInit>:
 80003a0:	58d4      	ldr	r4, [r2, r3]
 80003a2:	50c4      	str	r4, [r0, r3]
 80003a4:	3304      	adds	r3, #4

080003a6 <LoopCopyCCMDataInit>:
 80003a6:	18c4      	adds	r4, r0, r3
 80003a8:	428c      	cmp	r4, r1
 80003aa:	d3f9      	bcc.n	80003a0 <CopyCCMDataInit>
 80003ac:	4a0f      	ldr	r2, [pc, #60]	; (80003ec <LoopForever+0x28>)
 80003ae:	4c10      	ldr	r4, [pc, #64]	; (80003f0 <LoopForever+0x2c>)
 80003b0:	2300      	movs	r3, #0
 80003b2:	e001      	b.n	80003b8 <LoopFillZeroCCMbss>

080003b4 <FillZeroCCMbss>:
 80003b4:	6013      	str	r3, [r2, #0]
 80003b6:	3204      	adds	r2, #4

080003b8 <LoopFillZeroCCMbss>:
 80003b8:	42a2      	cmp	r2, r4
 80003ba:	d3fb      	bcc.n	80003b4 <FillZeroCCMbss>
 80003bc:	f000 f966 	bl	800068c <__libc_init_array>
 80003c0:	f7ff ff5c 	bl	800027c <main>

080003c4 <LoopForever>:
 80003c4:	/-- e7fe      	b.n	80003c4 <LoopForever>
 80003c6:	    0000      	movs	r0, r0
 80003c8:	    0000      	movs	r0, r0
 80003ca:	    2002      	movs	r0, #2
 80003cc:	    0000      	movs	r0, r0
 80003ce:	    2000      	movs	r0, #0
 80003d0:	    0004      	movs	r4, r0
 80003d2:	    2000      	movs	r0, #0
 80003d4:	    0710      	lsls	r0, r2, #28
 80003d6:	    0800      	lsrs	r0, r0, #32
 80003d8:	    0004      	movs	r4, r0
 80003da:	    2000      	movs	r0, #0
 80003dc:	    0028      	movs	r0, r5
 80003de:	    2000      	movs	r0, #0
 80003e0:	    0000      	movs	r0, r0
 80003e2:	    1000      	asrs	r0, r0, #32
 80003e4:	    0000      	movs	r0, r0
 80003e6:	    1000      	asrs	r0, r0, #32
 80003e8:	    0714      	lsls	r4, r2, #28
 80003ea:	    0800      	lsrs	r0, r0, #32
 80003ec:	    0000      	movs	r0, r0
 80003ee:	    1000      	asrs	r0, r0, #32
 80003f0:	    0000      	movs	r0, r0
 80003f2:	    1000      	asrs	r0, r0, #32

080003f4 <ADC_IRQHandler>:
 80003f4:	/-- e7fe      	b.n	80003f4 <ADC_IRQHandler>
	...

080003f8 <gpio_config_lock>:
}

/* Override the optimization level */
__attribute__((optimize("-O0")))
uint8_t gpio_config_lock(GPIO_TypeDef *gpio, gpio_io_t mask)
{
 80003f8:	b480      	push	{r7}
 80003fa:	b085      	sub	sp, #20
 80003fc:	af00      	add	r7, sp, #0
 80003fe:	6078      	str	r0, [r7, #4]
 8000400:	460b      	mov	r3, r1
 8000402:	807b      	strh	r3, [r7, #2]
    /* Execute lock sequence ref. "GPIO port configuration lock register"
     * pag. 285 - Reference Manual
     */
    uint32_t tmp;
    gpio->LCKR = 0x10000 | mask;
 8000404:	887b      	ldrh	r3, [r7, #2]
 8000406:	f443 3380 	orr.w	r3, r3, #65536	; 0x10000
 800040a:	461a      	mov	r2, r3
 800040c:	687b      	ldr	r3, [r7, #4]
 800040e:	61da      	str	r2, [r3, #28]
    gpio->LCKR = 0x00000 | mask;
 8000410:	887a      	ldrh	r2, [r7, #2]
 8000412:	687b      	ldr	r3, [r7, #4]
 8000414:	61da      	str	r2, [r3, #28]
    gpio->LCKR = 0x10000 | mask;
 8000416:	887b      	ldrh	r3, [r7, #2]
 8000418:	f443 3380 	orr.w	r3, r3, #65536	; 0x10000
 800041c:	461a      	mov	r2, r3
 800041e:	687b      	ldr	r3, [r7, #4]
 8000420:	61da      	str	r2, [r3, #28]
    tmp = gpio->LCKR;
 8000422:	687b      	ldr	r3, [r7, #4]
 8000424:	69db      	ldr	r3, [r3, #28]
 8000426:	60fb      	str	r3, [r7, #12]
    tmp++;
 8000428:	68fb      	ldr	r3, [r7, #12]
 800042a:	3301      	adds	r3, #1
 800042c:	60fb      	str	r3, [r7, #12]
    return !((gpio->LCKR) >> 16);
 800042e:	687b      	ldr	r3, [r7, #4]
 8000430:	69db      	ldr	r3, [r3, #28]
 8000432:	0c1b      	lsrs	r3, r3, #16
 8000434:	2b00      	cmp	r3, #0
 8000436:	bf0c      	ite	eq
 8000438:	2301      	moveq	r3, #1
 800043a:	2300      	movne	r3, #0
 800043c:	b2db      	uxtb	r3, r3
}
 800043e:	4618      	mov	r0, r3
 8000440:	3714      	adds	r7, #20
 8000442:	46bd      	mov	sp, r7
 8000444:	f85d 7b04 	ldr.w	r7, [sp], #4
 8000448:	4770      	bx	lr
 800044a:	bf00      	nop

0800044c <sys_clk_update>:
#define HSI_VALUE    ((uint32_t)16000000) /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */

__CONSTRUCTOR
__FORCE_INLINE void sys_clk_update()
{
 800044c:	b508      	push	{r3, lr}
    SystemCoreClockUpdate();
 800044e:	f7ff fed5 	bl	80001fc <SystemCoreClockUpdate>
    delay_init();
}
 8000452:	e8bd 4008 	ldmia.w	sp!, {r3, lr}
    delay_init();
 8000456:	f000 b8ef 	b.w	8000638 <delay_init>
 800045a:	bf00      	nop

0800045c <gpio_config_all>:
{
 800045c:	          e92d 4370 	stmdb	sp!, {r4, r5, r6, r8, r9, lr}
    if (configurator_enable & 0x1) {
 8000460:	          05cd      	lsls	r5, r1, #23
    uint8_t configurator_enable = (config & 0xF00) >> 8;
 8000462:	          ea4f 2e11 	mov.w	lr, r1, lsr #8
    if (configurator_enable & 0x1) {
 8000466:	/-------- d517      	bpl.n	8000498 <gpio_config_all+0x3c>
        uint8_t gpio_mode = (config & 0x3);
 8000468:	|         f001 0803 	and.w	r8, r1, #3
        uint32_t _mask = (uint32_t) mask;
 800046c:	|         4694      	mov	r12, r2
 800046e:	|         2300      	movs	r3, #0
                gpio->MODER &= ~(0x3 << bit);
 8000470:	|         2603      	movs	r6, #3
            if (_mask & 0x1) {
 8000472:	|  /----> f01c 0f01 	tst.w	r12, #1
                gpio->MODER &= ~(0x3 << bit);
 8000476:	|  |      fa06 f903 	lsl.w	r9, r6, r3
            _mask >>= 1;
 800047a:	|  |      ea4f 0c5c 	mov.w	r12, r12, lsr #1
            if (_mask & 0x1) {
 800047e:	|  |  /-- d008      	beq.n	8000492 <gpio_config_all+0x36>
                gpio->MODER &= ~(0x3 << bit);
 8000480:	|  |  |   6805      	ldr	r5, [r0, #0]
 8000482:	|  |  |   ea25 0509 	bic.w	r5, r5, r9
 8000486:	|  |  |   6005      	str	r5, [r0, #0]
                gpio->MODER |= (gpio_mode << bit);
 8000488:	|  |  |   6805      	ldr	r5, [r0, #0]
 800048a:	|  |  |   fa08 f403 	lsl.w	r4, r8, r3
 800048e:	|  |  |   432c      	orrs	r4, r5
 8000490:	|  |  |   6004      	str	r4, [r0, #0]
        for (uint8_t bit = 0; bit < 32; bit += 2) {
 8000492:	|  |  \-> 3302      	adds	r3, #2
 8000494:	|  |      2b20      	cmp	r3, #32
 8000496:	|  \----- d1ec      	bne.n	8000472 <gpio_config_all+0x16>
    if (configurator_enable & 0x2) {
 8000498:	\-------> f01e 0f02 	tst.w	lr, #2
 800049c:	      /-- d008      	beq.n	80004b0 <gpio_config_all+0x54>
        gpio->OTYPER &= ~mask;
 800049e:	      |   6843      	ldr	r3, [r0, #4]
 80004a0:	      |   ea23 0302 	bic.w	r3, r3, r2
 80004a4:	      |   6043      	str	r3, [r0, #4]
        gpio->OTYPER |= output_mode ? mask : 0;
 80004a6:	      |   6843      	ldr	r3, [r0, #4]
 80004a8:	      |   074c      	lsls	r4, r1, #29
 80004aa:	      |   bf48      	it	mi
 80004ac:	      |   4313      	orrmi	r3, r2
 80004ae:	      |   6043      	str	r3, [r0, #4]
    if (configurator_enable & 0x4) {
 80004b0:	      \-> f01e 0f04 	tst.w	lr, #4
 80004b4:	/-------- d017      	beq.n	80004e6 <gpio_config_all+0x8a>
        uint8_t pull_mode = (config & 0x18) >> 3;
 80004b6:	|         f3c1 08c1 	ubfx	r8, r1, #3, #2
        uint32_t _mask = (uint32_t) mask;
 80004ba:	|         4694      	mov	r12, r2
 80004bc:	|         2300      	movs	r3, #0
                gpio->PUPDR &= ~(0x3 << bit);
 80004be:	|         2603      	movs	r6, #3
            if (_mask & 0x1) {
 80004c0:	|  /----> f01c 0f01 	tst.w	r12, #1
                gpio->PUPDR &= ~(0x3 << bit);
 80004c4:	|  |      fa06 f903 	lsl.w	r9, r6, r3
            _mask >>= 1;
 80004c8:	|  |      ea4f 0c5c 	mov.w	r12, r12, lsr #1
            if (_mask & 0x1) {
 80004cc:	|  |  /-- d008      	beq.n	80004e0 <gpio_config_all+0x84>
                gpio->PUPDR &= ~(0x3 << bit);
 80004ce:	|  |  |   68c5      	ldr	r5, [r0, #12]
 80004d0:	|  |  |   ea25 0509 	bic.w	r5, r5, r9
 80004d4:	|  |  |   60c5      	str	r5, [r0, #12]
                gpio->PUPDR |= pull_mode << bit;
 80004d6:	|  |  |   68c5      	ldr	r5, [r0, #12]
 80004d8:	|  |  |   fa08 f403 	lsl.w	r4, r8, r3
 80004dc:	|  |  |   432c      	orrs	r4, r5
 80004de:	|  |  |   60c4      	str	r4, [r0, #12]
        for (uint8_t bit = 0; bit < 32; bit += 2) {
 80004e0:	|  |  \-> 3302      	adds	r3, #2
 80004e2:	|  |      2b20      	cmp	r3, #32
 80004e4:	|  \----- d1ec      	bne.n	80004c0 <gpio_config_all+0x64>
    if (configurator_enable & 0x8) {
 80004e6:	\-------> f01e 0f08 	tst.w	lr, #8
 80004ea:	/-------- d017      	beq.n	800051c <gpio_config_all+0xc0>
        uint8_t speed = (config & 0x60) >> 5;
 80004ec:	|         f3c1 1641 	ubfx	r6, r1, #5, #2
        uint32_t _mask = (uint32_t) mask;
 80004f0:	|         2300      	movs	r3, #0
                gpio->OSPEEDR &= ~(0x3 << bit);
 80004f2:	|         f04f 0c03 	mov.w	r12, #3
            if (_mask & 0x1) {
 80004f6:	|  /----> f012 0f01 	tst.w	r2, #1
                gpio->OSPEEDR &= ~(0x3 << bit);
 80004fa:	|  |      fa0c f503 	lsl.w	r5, r12, r3
            _mask >>= 1;
 80004fe:	|  |      ea4f 0252 	mov.w	r2, r2, lsr #1
            if (_mask & 0x1) {
 8000502:	|  |  /-- d008      	beq.n	8000516 <gpio_config_all+0xba>
                gpio->OSPEEDR &= ~(0x3 << bit);
 8000504:	|  |  |   6884      	ldr	r4, [r0, #8]
 8000506:	|  |  |   ea24 0405 	bic.w	r4, r4, r5
 800050a:	|  |  |   6084      	str	r4, [r0, #8]
                gpio->OSPEEDR |= speed << bit;
 800050c:	|  |  |   6884      	ldr	r4, [r0, #8]
 800050e:	|  |  |   fa06 f103 	lsl.w	r1, r6, r3
 8000512:	|  |  |   4321      	orrs	r1, r4
 8000514:	|  |  |   6081      	str	r1, [r0, #8]
        for (uint8_t bit = 0; bit < 32; bit += 2) {
 8000516:	|  |  \-> 3302      	adds	r3, #2
 8000518:	|  |      2b20      	cmp	r3, #32
 800051a:	|  \----- d1ec      	bne.n	80004f6 <gpio_config_all+0x9a>
}
 800051c:	\-------> e8bd 8370 	ldmia.w	sp!, {r4, r5, r6, r8, r9, pc}

08000520 <gpio_config_mode>:
{
 8000520:	       b530      	push	{r4, r5, lr}
 8000522:	       2300      	movs	r3, #0
            gpio->MODER &= ~(0x3 << bit);
 8000524:	       f04f 0e03 	mov.w	lr, #3
        if (mask & 0x1) {
 8000528:	/----> f012 0f01 	tst.w	r2, #1
            gpio->MODER &= ~(0x3 << bit);
 800052c:	|      fa0e fc03 	lsl.w	r12, lr, r3
        mask >>= 1;
 8000530:	|      ea4f 0252 	mov.w	r2, r2, lsr #1
        if (mask & 0x1) {
 8000534:	|  /-- d008      	beq.n	8000548 <gpio_config_mode+0x28>
            gpio->MODER &= ~(0x3 << bit);
 8000536:	|  |   6805      	ldr	r5, [r0, #0]
 8000538:	|  |   ea25 050c 	bic.w	r5, r5, r12
 800053c:	|  |   6005      	str	r5, [r0, #0]
            gpio->MODER |= mode << bit;
 800053e:	|  |   6805      	ldr	r5, [r0, #0]
 8000540:	|  |   fa01 f403 	lsl.w	r4, r1, r3
 8000544:	|  |   432c      	orrs	r4, r5
 8000546:	|  |   6004      	str	r4, [r0, #0]
    for (uint8_t bit = 0; bit < 32; bit += 2) {
 8000548:	|  \-> 3302      	adds	r3, #2
 800054a:	|      2b20      	cmp	r3, #32
 800054c:	\----- d1ec      	bne.n	8000528 <gpio_config_mode+0x8>
}
 800054e:	       bd30      	pop	{r4, r5, pc}

08000550 <gpio_config_speed>:
{
 8000550:	       b530      	push	{r4, r5, lr}
 8000552:	       2300      	movs	r3, #0
            gpio->OSPEEDR &= ~(0x3 << bit);
 8000554:	       f04f 0e03 	mov.w	lr, #3
        if (mask & 0x1) {
 8000558:	/----> f012 0f01 	tst.w	r2, #1
            gpio->OSPEEDR &= ~(0x3 << bit);
 800055c:	|      fa0e fc03 	lsl.w	r12, lr, r3
        mask >>= 1;
 8000560:	|      ea4f 0252 	mov.w	r2, r2, lsr #1
        if (mask & 0x1) {
 8000564:	|  /-- d008      	beq.n	8000578 <gpio_config_speed+0x28>
            gpio->OSPEEDR &= ~(0x3 << bit);
 8000566:	|  |   6885      	ldr	r5, [r0, #8]
 8000568:	|  |   ea25 050c 	bic.w	r5, r5, r12
 800056c:	|  |   6085      	str	r5, [r0, #8]
            gpio->OSPEEDR |= speed << bit;
 800056e:	|  |   6885      	ldr	r5, [r0, #8]
 8000570:	|  |   fa01 f403 	lsl.w	r4, r1, r3
 8000574:	|  |   432c      	orrs	r4, r5
 8000576:	|  |   6084      	str	r4, [r0, #8]
    for (uint8_t bit = 0; bit < 32; bit += 2) {
 8000578:	|  \-> 3302      	adds	r3, #2
 800057a:	|      2b20      	cmp	r3, #32
 800057c:	\----- d1ec      	bne.n	8000558 <gpio_config_speed+0x8>
}
 800057e:	       bd30      	pop	{r4, r5, pc}

08000580 <gpio_config_input_pull_mode>:
{
 8000580:	       b530      	push	{r4, r5, lr}
 8000582:	       2300      	movs	r3, #0
            gpio->PUPDR &= ~(0x3 << bit);
 8000584:	       f04f 0e03 	mov.w	lr, #3
        if (mask & 0x1) {
 8000588:	/----> f012 0f01 	tst.w	r2, #1
            gpio->PUPDR &= ~(0x3 << bit);
 800058c:	|      fa0e fc03 	lsl.w	r12, lr, r3
        mask >>= 1;
 8000590:	|      ea4f 0252 	mov.w	r2, r2, lsr #1
        if (mask & 0x1) {
 8000594:	|  /-- d008      	beq.n	80005a8 <gpio_config_input_pull_mode+0x28>
            gpio->PUPDR &= ~(0x3 << bit);
 8000596:	|  |   68c5      	ldr	r5, [r0, #12]
 8000598:	|  |   ea25 050c 	bic.w	r5, r5, r12
 800059c:	|  |   60c5      	str	r5, [r0, #12]
            gpio->PUPDR |= pull_mode << bit;
 800059e:	|  |   68c5      	ldr	r5, [r0, #12]
 80005a0:	|  |   fa01 f403 	lsl.w	r4, r1, r3
 80005a4:	|  |   432c      	orrs	r4, r5
 80005a6:	|  |   60c4      	str	r4, [r0, #12]
    for (uint8_t bit = 0; bit < 32; bit += 2) {
 80005a8:	|  \-> 3302      	adds	r3, #2
 80005aa:	|      2b20      	cmp	r3, #32
 80005ac:	\----- d1ec      	bne.n	8000588 <gpio_config_input_pull_mode+0x8>
}
 80005ae:	       bd30      	pop	{r4, r5, pc}

080005b0 <gpio_config_af>:

void gpio_config_af(GPIO_TypeDef *gpio, gpio_alt_t af, gpio_io_t mask)
{
 80005b0:	             e92d 4170 	stmdb	sp!, {r4, r5, r6, r8, lr}
 80005b4:	             f04f 0c04 	mov.w	r12, #4
 80005b8:	             f04f 0e00 	mov.w	lr, #0
                gpio->AFR[0] |= af << bit;
            }
            else {
                /* For last 8 IO/s |> AFRH */
                uint8_t tmp = bit - 32;
                gpio->AFR[1] &= ~(0xF << tmp);
 80005bc:	             250f      	movs	r5, #15
 80005be:	         /-- e018      	b.n	80005f2 <gpio_config_af+0x42>
 80005c0:	   /-----|-> 3b20      	subs	r3, #32
 80005c2:	   |     |   b2db      	uxtb	r3, r3
            if (bit < 32) {
 80005c4:	   |     |   f1be 0f1f 	cmp.w	lr, #31
                gpio->AFR[0] &= ~(0xF << bit);
 80005c8:	   |     |   fa05 f80e 	lsl.w	r8, r5, lr
                gpio->AFR[1] &= ~(0xF << tmp);
 80005cc:	   |     |   fa05 f603 	lsl.w	r6, r5, r3
                gpio->AFR[0] |= af << bit;
 80005d0:	   |     |   fa01 f40e 	lsl.w	r4, r1, lr
            if (bit < 32) {
 80005d4:	   |  /--|-- d819      	bhi.n	800060a <gpio_config_af+0x5a>
                gpio->AFR[0] &= ~(0xF << bit);
 80005d6:	   |  |  |   6a03      	ldr	r3, [r0, #32]
 80005d8:	   |  |  |   ea23 0308 	bic.w	r3, r3, r8
 80005dc:	   |  |  |   6203      	str	r3, [r0, #32]
                gpio->AFR[0] |= af << bit;
 80005de:	   |  |  |   6a03      	ldr	r3, [r0, #32]
 80005e0:	   |  |  |   431c      	orrs	r4, r3
                gpio->AFR[1] |= af << tmp;
            }
        }
        mask >>= 1;
 80005e2:	   |  |  |   0852      	lsrs	r2, r2, #1
                gpio->AFR[0] |= af << bit;
 80005e4:	   |  |  |   6204      	str	r4, [r0, #32]
    for (uint8_t bit = 0; bit < 64; bit += 4) {
 80005e6:	/--|--|--|-> f10c 0c04 	add.w	r12, r12, #4
 80005ea:	|  |  |  |   fa5f fc8c 	uxtb.w	r12, r12
 80005ee:	|  |  |  |   f10e 0e04 	add.w	lr, lr, #4
        if (mask & 0x1) {
 80005f2:	|  |  |  \-> f012 0f01 	tst.w	r2, #1
 80005f6:	|  |  |      fa5f f38e 	uxtb.w	r3, lr
 80005fa:	|  \--|----- d1e1      	bne.n	80005c0 <gpio_config_af+0x10>
    for (uint8_t bit = 0; bit < 64; bit += 4) {
 80005fc:	|     |      f1bc 0f40 	cmp.w	r12, #64	; 0x40
        mask >>= 1;
 8000600:	|     |      ea4f 0252 	mov.w	r2, r2, lsr #1
    for (uint8_t bit = 0; bit < 64; bit += 4) {
 8000604:	+-----|----- d1ef      	bne.n	80005e6 <gpio_config_af+0x36>
    }
 8000606:	|     |  /-> e8bd 8170 	ldmia.w	sp!, {r4, r5, r6, r8, pc}
                gpio->AFR[1] &= ~(0xF << tmp);
 800060a:	|     \--|-> 6a44      	ldr	r4, [r0, #36]	; 0x24
 800060c:	|        |   ea24 0406 	bic.w	r4, r4, r6
 8000610:	|        |   6244      	str	r4, [r0, #36]	; 0x24
                gpio->AFR[1] |= af << tmp;
 8000612:	|        |   6a44      	ldr	r4, [r0, #36]	; 0x24
 8000614:	|        |   fa01 f303 	lsl.w	r3, r1, r3
 8000618:	|        |   4323      	orrs	r3, r4
    for (uint8_t bit = 0; bit < 64; bit += 4) {
 800061a:	|        |   f1bc 0f40 	cmp.w	r12, #64	; 0x40
                gpio->AFR[1] |= af << tmp;
 800061e:	|        |   6243      	str	r3, [r0, #36]	; 0x24
        mask >>= 1;
 8000620:	|        |   ea4f 0252 	mov.w	r2, r2, lsr #1
    for (uint8_t bit = 0; bit < 64; bit += 4) {
 8000624:	\--------|-- d1df      	bne.n	80005e6 <gpio_config_af+0x36>
 8000626:	         \-- e7ee      	b.n	8000606 <gpio_config_af+0x56>

08000628 <sys_clk_update>:
{
 8000628:	b508      	push	{r3, lr}
    SystemCoreClockUpdate();
 800062a:	f7ff fde7 	bl	80001fc <SystemCoreClockUpdate>
}
 800062e:	e8bd 4008 	ldmia.w	sp!, {r3, lr}
    delay_init();
 8000632:	f000 b801 	b.w	8000638 <delay_init>
 8000636:	bf00      	nop

08000638 <delay_init>:
uint32_t DELAY_CYCLES_US;              


void delay_init (void)
{
    DELAY_CYCLES_MS = (SystemCoreClock / 1000);
 8000638:	4a09      	ldr	r2, [pc, #36]	; (8000660 <delay_init+0x28>)
 800063a:	4b0a      	ldr	r3, [pc, #40]	; (8000664 <delay_init+0x2c>)
 800063c:	6812      	ldr	r2, [r2, #0]
    DELAY_CYCLES_US = (DELAY_CYCLES_MS / 1000);
    DELAY_CYCLES_MS += EXTRACYCLES_PER_MS;
 800063e:	480a      	ldr	r0, [pc, #40]	; (8000668 <delay_init+0x30>)
{
 8000640:	b410      	push	{r4}
    DELAY_CYCLES_US = (DELAY_CYCLES_MS / 1000);
 8000642:	4c0a      	ldr	r4, [pc, #40]	; (800066c <delay_init+0x34>)
    DELAY_CYCLES_MS = (SystemCoreClock / 1000);
 8000644:	fba3 1302 	umull	r1, r3, r3, r2
 8000648:	099b      	lsrs	r3, r3, #6
    DELAY_CYCLES_US = (DELAY_CYCLES_MS / 1000);
 800064a:	fba4 4202 	umull	r4, r2, r4, r2
 800064e:	4908      	ldr	r1, [pc, #32]	; (8000670 <delay_init+0x38>)
}
 8000650:	f85d 4b04 	ldr.w	r4, [sp], #4
    DELAY_CYCLES_US = (DELAY_CYCLES_MS / 1000);
 8000654:	0c92      	lsrs	r2, r2, #18
    DELAY_CYCLES_MS += EXTRACYCLES_PER_MS;
 8000656:	3309      	adds	r3, #9
 8000658:	6003      	str	r3, [r0, #0]
    DELAY_CYCLES_US = (DELAY_CYCLES_MS / 1000);
 800065a:	600a      	str	r2, [r1, #0]
}
 800065c:	4770      	bx	lr
 800065e:	bf00      	nop
 8000660:	0000      	movs	r0, r0
 8000662:	2000      	movs	r0, #0
 8000664:	4dd3      	ldr	r5, [pc, #844]	; (80009b4 <_siccmdata+0x2a0>)
 8000666:	1062      	asrs	r2, r4, #1
 8000668:	0020      	movs	r0, r4
 800066a:	2000      	movs	r0, #0
 800066c:	de83      	udf	#131	; 0x83
 800066e:	431b      	orrs	r3, r3
 8000670:	0024      	movs	r4, r4
 8000672:	2000      	movs	r0, #0

08000674 <delay_ms>:

__attribute__((optimize("-Os")))
void delay_ms (uint32_t ms)
{
    do {
        register int32_t cycles_to_ms = DELAY_CYCLES_MS;
 8000674:	       4a04      	ldr	r2, [pc, #16]	; (8000688 <delay_ms+0x14>)
 8000676:	/----> 6813      	ldr	r3, [r2, #0]
        do {
            __asm("NOP");
 8000678:	|  /-> bf00      	nop
            cycles_to_ms -= CYCLES_PER_MS;
 800067a:	|  |   3b05      	subs	r3, #5
        } while (cycles_to_ms > 0);
 800067c:	|  |   2b00      	cmp	r3, #0
 800067e:	|  \-- dcfb      	bgt.n	8000678 <delay_ms+0x4>
    } while (--ms);
 8000680:	|      3801      	subs	r0, #1
 8000682:	\----- d1f8      	bne.n	8000676 <delay_ms+0x2>
}
 8000684:	       4770      	bx	lr
 8000686:	       bf00      	nop
 8000688:	       0020      	movs	r0, r4
 800068a:	       2000      	movs	r0, #0

0800068c <__libc_init_array>:
 800068c:	             b570      	push	{r4, r5, r6, lr}
 800068e:	             4d0d      	ldr	r5, [pc, #52]	; (80006c4 <__libc_init_array+0x38>)
 8000690:	             4c0d      	ldr	r4, [pc, #52]	; (80006c8 <__libc_init_array+0x3c>)
 8000692:	             1b64      	subs	r4, r4, r5
 8000694:	             10a4      	asrs	r4, r4, #2
 8000696:	             2600      	movs	r6, #0
 8000698:	/----------> 42a6      	cmp	r6, r4
 800069a:	|     /----- d109      	bne.n	80006b0 <__libc_init_array+0x24>
 800069c:	|     |      4d0b      	ldr	r5, [pc, #44]	; (80006cc <__libc_init_array+0x40>)
 800069e:	|     |      4c0c      	ldr	r4, [pc, #48]	; (80006d0 <__libc_init_array+0x44>)
 80006a0:	|     |      f000 f818 	bl	80006d4 <_init>
 80006a4:	|     |      1b64      	subs	r4, r4, r5
 80006a6:	|     |      10a4      	asrs	r4, r4, #2
 80006a8:	|     |      2600      	movs	r6, #0
 80006aa:	|  /--|----> 42a6      	cmp	r6, r4
 80006ac:	|  |  |  /-- d105      	bne.n	80006ba <__libc_init_array+0x2e>
 80006ae:	|  |  |  |   bd70      	pop	{r4, r5, r6, pc}
 80006b0:	|  |  \--|-> f855 3b04 	ldr.w	r3, [r5], #4
 80006b4:	|  |     |   4798      	blx	r3
 80006b6:	|  |     |   3601      	adds	r6, #1
 80006b8:	\--|-----|-- e7ee      	b.n	8000698 <__libc_init_array+0xc>
 80006ba:	   |     \-> f855 3b04 	ldr.w	r3, [r5], #4
 80006be:	   |         4798      	blx	r3
 80006c0:	   |         3601      	adds	r6, #1
 80006c2:	   \-------- e7f2      	b.n	80006aa <__libc_init_array+0x1e>
 80006c4:	             06fc      	lsls	r4, r7, #27
 80006c6:	             0800      	lsrs	r0, r0, #32
 80006c8:	             06fc      	lsls	r4, r7, #27
 80006ca:	             0800      	lsrs	r0, r0, #32
 80006cc:	             06fc      	lsls	r4, r7, #27
 80006ce:	             0800      	lsrs	r0, r0, #32
 80006d0:	             070c      	lsls	r4, r1, #28
 80006d2:	             0800      	lsrs	r0, r0, #32

080006d4 <_init>:
 80006d4:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 80006d6:	bf00      	nop
 80006d8:	bcf8      	pop	{r3, r4, r5, r6, r7}
 80006da:	bc08      	pop	{r3}
 80006dc:	469e      	mov	lr, r3
 80006de:	4770      	bx	lr

080006e0 <_fini>:
 80006e0:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 80006e2:	bf00      	nop
 80006e4:	bcf8      	pop	{r3, r4, r5, r6, r7}
 80006e6:	bc08      	pop	{r3}
 80006e8:	469e      	mov	lr, r3
 80006ea:	4770      	bx	lr

Disassembly of section .rodata:

080006ec <AHBPrescTable>:
	...
 80006f4:	0201      	lsls	r1, r0, #8
 80006f6:	0403      	lsls	r3, r0, #16
 80006f8:	0706      	lsls	r6, r0, #28
 80006fa:	0908      	lsrs	r0, r1, #4

Disassembly of section .init_array:

080006fc <__frame_dummy_init_array_entry>:
 80006fc:	01cd      	lsls	r5, r1, #7
 80006fe:	0800      	lsrs	r0, r0, #32
 8000700:	026d      	lsls	r5, r5, #9
 8000702:	0800      	lsrs	r0, r0, #32
 8000704:	044d      	lsls	r5, r1, #17
 8000706:	0800      	lsrs	r0, r0, #32
 8000708:	0629      	lsls	r1, r5, #24
 800070a:	0800      	lsrs	r0, r0, #32

Disassembly of section .fini_array:

0800070c <__do_global_dtors_aux_fini_array_entry>:
 800070c:	01a9      	lsls	r1, r5, #6
 800070e:	0800      	lsrs	r0, r0, #32

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

20000020 <DELAY_CYCLES_MS>:
static uint32_t DELAY_CYCLES_MS;
20000020:	0000      	movs	r0, r0
	...

20000024 <DELAY_CYCLES_US>:
uint32_t DELAY_CYCLES_US;              
20000024:	0000      	movs	r0, r0
	...

Disassembly of section ._user_heap_stack:

20000028 <._user_heap_stack>:
	...
