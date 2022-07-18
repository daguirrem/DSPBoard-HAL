/**
 * @file system.h
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief System global includes and global macros / definitions / configs.
 * @version d0.3
 * @date 2022-05-02
 * 
 * @copyright MIT License, Copyright (c) 2022 David A. Aguirre M. @n @n
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions: @n @n
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software. @n @n

 * THE SOFTWARE IS PROVIDED  "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */

#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "delay.h"

#if defined(STM32F4xx)
#include "stm32f4xx.h"
#endif

#define __FORCE_INLINE  __attribute__((always_inline)) static inline

#define __CCM_VAR_I __attribute__((section(".ccmdata")))
#define __CCM_VAR_U __attribute__((section(".ccmbss")))
#define __RAM_FUNC  __attribute__((section(".ramFunc")))

#define __CONSTRUCTOR __attribute__((constructor))

#if !defined  (HSE_VALUE) 
#define HSE_VALUE    ((uint32_t)8000000) /*!< Default value of the External oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined  (HSI_VALUE)
#define HSI_VALUE    ((uint32_t)16000000) /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */

__CONSTRUCTOR
__FORCE_INLINE void sys_clk_update()
{
    SystemCoreClockUpdate();
    delay_init();
}

#endif /* _SYSTEM_H_ */
