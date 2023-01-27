/**
 * @file main.c
 * @author David A. Aguirre M. (daguirre.m@outlook.com)
 * @brief Test for RCC HAL LIB
 * @version d0.1
 * @date 2022-04-18
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
#include "rcc.h"
#include "delay.h"

int main (void)
{
    /* SystemCoreClock should be HSE value ----------------|*/
    /* 8 MHz                                               |*/
    rcc_sysclk_select(RCC_SYSCLK_HSE);                 /*<-|*/                  /*[ok]*/

    /* SystemCoreClock should be PLL value ----------------|*/
    /* 168 MHz                                             |*/
    rcc_pll_param_cpte(168, RCC_PLLCLK_HSE);             /*|*/
    rcc_pll_param_clr();                                 /*|*/
    rcc_pll_param_set();                                 /*|*/
    rcc_sysclk_select(RCC_SYSCLK_PLL | RCC_SYSCLK_HSE);/*<-|*/                  /*[ok]*/

    /* SystemCoreClock should be HSI value ----------------|*/
    /* 16 MHz                                              |*/
    rcc_sysclk_select(RCC_SYSCLK_HSI);                 /*<-|*/                  /*[ok]*/

    /* SystemCoreClock should be PLL value ----------------|*/
    /* 100 MHz                                             |*/
    rcc_pll_param_cpte_set(100, RCC_PLLCLK_HSE);         /*|*/
    rcc_sysclk_select(RCC_SYSCLK_PLL | RCC_SYSCLK_HSE);/*<-|*/                  /*[ok]*/

    /* SystemCoreClock should be HSE value ----------------|*/
    /* 8 MHz                                               |*/
    rcc_sysclk_select(RCC_SYSCLK_HSE);                 /*<-|*/                  /*[ok]*/

    /* GPIOA clock should be enabled ----------------------|*/
    rcc_clk_en_ahb1(RCC_AHB1_GPIOA);                   /*<-|*/                  /*[ok]*/

    /* GPIOA clock should be disabled ---------------------|*/
    rcc_clk_dis_ahb1(RCC_AHB1_GPIOA);                  /*<-|*/                  /*[ok]*/

    /* GPIOB clock should be enabled  ---------------------|*/
    rcc_clk_en_ahb1(RCC_AHB1_GPIOB);                   /*<-|*/                  /*[ok]*/

    /* GPIOB clock should be reset ------------------------|*/
    rcc_rst_ahb1(RCC_AHB1_GPIOB);                      /*<-|*/                  /*[ok?]*/ //TODO: Qué hace el rst?

    /* GPIOB clock should be disabled ---------------------|*/
    rcc_clk_dis_ahb1(RCC_AHB1_GPIOB);                  /*<-|*/                  /*[ok]*/

    /* GPIOA & GPIOB clock should be enabled ------------------------|*/
    rcc_clk_en_ahb1(RCC_AHB1_GPIOA | RCC_AHB1_GPIOB);            /*<-|*/        /*[ok]*/

    /* GPIOA & GPIOB clock should be disabled -----------------------|*/
    rcc_clk_dis_ahb1(RCC_AHB1_GPIOA | RCC_AHB1_GPIOB);           /*<-|*/        /*[ok]*/

    /* APB1 Clock should be 42 MHz */
    volatile uint32_t apb1_clk = rcc_clk_get_apb1();

    /* APB2 Clock should be 84 MHz */
    volatile uint32_t apb2_clk = rcc_clk_get_apb2();

    while(1)
    {
        delay_ms(1);
    }
}
