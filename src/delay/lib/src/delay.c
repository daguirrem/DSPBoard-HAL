/**
 * @file delay.c
 * @author David A. Aguirre M. (daguirre.m@outlook.com)
 * @brief DELAY - Custom HAL for DSP Board SDK.
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

#include "system.h"

/**
 * @addtogroup delay
 */

/**
 * @defgroup delay_private Private
 * @ingroup delay
 */

#define CYCLES_PER_MS 5         /*!< Internal cycles per ms at delay_ms */
#define EXTRACYCLES_PER_MS 9    /*!< Internal extra cycles per ms at delay_ms */


extern uint32_t SystemCoreClock;

/*! @ingroup delay_private */
//! Cycles per MS
static uint32_t DELAY_CYCLES_MS;

/*! @ingroup delay_public */
//! Cycles per US */
uint32_t DELAY_CYCLES_US;              


void delay_init (void)
{
    DELAY_CYCLES_MS = (SystemCoreClock / 1000);
    DELAY_CYCLES_US = (DELAY_CYCLES_MS / 1000);
    DELAY_CYCLES_MS += EXTRACYCLES_PER_MS;
}

__attribute__((optimize("-Os")))
void delay_ms (uint32_t ms)
{
    do {
        register int32_t cycles_to_ms = DELAY_CYCLES_MS;
        do {
            __asm("NOP");
            cycles_to_ms -= CYCLES_PER_MS;
        } while (cycles_to_ms > 0);
    } while (--ms);
}
