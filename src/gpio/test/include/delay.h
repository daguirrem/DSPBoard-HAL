/**
 * @file delay.h
 * @author David A. Aguirre M. (daguirre.m@outlook.com)
 * @brief Delay - Custom HAL for DSP Board SDK.
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

#ifndef _DELAY_H_
#define _DELAY_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup delay DELAY
 */

/**
 * @defgroup public_delay Public
 * @ingroup delay
 */

#include <stdint.h>

// extern uint32_t DELAY_CYCLES_US;

/** ### delay:initialization
 * @ingroup public_delay
 * @brief Init internal variables to delay.
 * 
 * Init a DELAY_CYCLES_MS & DELAY_CYCLES_US variables to delay functions.
 * 
 * @return None.
 * 
 * @note 1. If a SystemCoreClock is updated, its required reinit the delay.
 * @note 2. sys_clk_update executes a SystemCoreClock & Delay vars update.
 * 
 * E.g. @n
 * @code
 * ...
 * // This will update the SystemCoreClock variable & update delay vars
 * SystemCoreClockUpdate();
 * delay_init();
 * ...
 * @endcode
 */
void delay_init (void);

/** ### delay:miliseconds
 * @ingroup public_delay
 * @brief Create a delay by x miliseconds.
 * 
 * Stop the program flow by aprox. required ms.
 * 
 * @param[in] ms ~ms to delay.
 * 
 * @note Depends by DELAY_CYCLES_MS variable.
 * 
 * @return None.
 * E.g. @n
 * @code
 * // This will stops the program flow by ~100 ms
 * delay_ms(100);
 * @endcode
 */
void delay_ms (uint32_t ms);

// /** ### delay:microseconds
//  * @ingroup public_delay
//  * @brief Create a delay by x microseconds.
//  * 
//  * Stop the program flow by aprox. required us.
//  * 
//  * @param[in] us ~us to delay.
//  * 
//  * @note 1. Depends by DELAY_CYCLES_US variable.
//  * @note 2. PRESICION IS POOR (Recomend USE OTHER WAYS to delay US).
//  * @note 3. It is a forced inline function.
//  * 
//  * @return None.
//  * E.g. @n
//  * @code
//  * // This will stops the program flow by ~100 us
//  * delay_us(100);
//  * @endcode
//  */
// __FORCE_INLINE void delay_us(uint32_t us)
// {
//     do {
//         uint32_t l = DELAY_CYCLES_US/6;
//         __asm volatile( 
//             "0:"
//             "SUBS %[count], 1;"
//             "BNE 0b;" :[count]"+r"(l) 
//         );
//     } while (--us);
// }

#ifdef __cplusplus
}
#endif

#endif /* _DELAY_H_ */