/**
 * @file rcc.c
 * @author David A. Aguirre M. (daguirre.m@outlook.com)
 * @brief RCC - Custom HAL for DSP Board SDK.
 * @version d0.2
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
 *
 * THE SOFTWARE IS PROVIDED  "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */



#include "rcc.h"
#include "system.h"

#include "flash.h"

/**
 * @addtogroup rcc
 */

/**
 * @defgroup rcc_private Private
 * @ingroup rcc
 */

/**
 * @ingroup rcc_private
 * @brief Static struct than have PLL configuration parameters.
 * 
 */
struct pll_s
{
    uint32_t m:6; //!< Divisor factor for FVCO input
    uint32_t n:9; //!< Multiply factor for FVCO output
    uint32_t p:2; //!< Divisor factor PLL output
    uint32_t q:4; //!< Multiply factor for 48CK clock
    uint32_t ppre1:3; //!< Prescaler to AHB1 Bus
    uint32_t ppre2:3; //!< Prescaler to AHB2 Bus
    uint32_t freq_o;  //!< Output Frequency PLL
    rcc_pllclk_t source; //!< Source input clock to PLL
};

/*! @ingroup rcc_private */
//! PLL parameters configurations
/*! Internal variable that contains PLL parameters */
static struct pll_s pll_parameters;

/**
 * @ingroup rcc_private
 * @brief Static struct than contains clock speeds.
 * 
 */
struct clk_s
{
    uint32_t system; //!< System clock speed
    uint32_t ahb; //!< AHB Bus clock speed
    uint32_t apb1; //!< APB1 Bus clock speed
    uint32_t apb2; //!< APB2 Bus clock speed
};

/*! 
 * @ingroup rcc_private
 * @brief MCU current clock speeds.
 * Internal variable that contains current mcu clock speeds
 * @note By default (at boot) all clocks are HSI_VALUE
 * @see clk_s
 */
static struct clk_s rcc_clocks_current =
{
    .system = HSI_VALUE,
    .ahb = HSI_VALUE,
    .apb1 = HSI_VALUE,
    .apb2 = HSI_VALUE
};

/*! 
 * @ingroup rcc_private
 * @brief MCU previous clock speeds.
 * Internal variable that contains previus (at current) mcu clock speeds
 * @note By default (at boot) all clocks are HSI_VALUE
 * @see clk_s
 */
static struct clk_s rcc_clocks_previous =
{
    .system = HSI_VALUE,
    .ahb = HSI_VALUE,
    .apb1 = HSI_VALUE,
    .apb2 = HSI_VALUE
};

void rcc_sysclk_select(rcc_sysclk_t source)
{
    uint32_t RCC_CR_BIT_RD = 0; /* Target ready bit on RCC_CR register */
    uint32_t pll_request;
    uint32_t cfgr_switch;
    uint32_t cfgr_ready;

    const uint32_t APB_PRESCALER[] = {
        0x000,
        0x100,
        0x101,
        0x110,
        0x111
    };

    /* Store clocks before change */
    rcc_clocks_previous.system = rcc_clocks_current.system;
    rcc_clocks_previous.ahb = rcc_clocks_current.ahb;

    /* Separe PLL request on */
    pll_request = source & RCC_CR_PLLON;
    source &= ~RCC_CR_PLLON;
    
    switch (source)
    {
    case RCC_SYSCLK_HSE:
        RCC_CR_BIT_RD = RCC_CR_HSERDY;
        cfgr_switch = 1;
        break;
    case RCC_SYSCLK_HSI:
    default:
        RCC_CR_BIT_RD = RCC_CR_HSIRDY;
        cfgr_switch = 0;
        break;
    }
    /* Power on the target clock (HSI or HSE) */
    RCC->CR |= source;
    /* Wait for stable target clock (rdy flag == 1) */
    while ((RCC->CR & RCC_CR_BIT_RD) == 0);
    /* Verify PLL target and power on it if required */
    if(pll_request)
    {
        cfgr_switch = 2;
        RCC->CR |= pll_request;
        /* Wait for stable pll clock (rdy flag == 1) */
        while ((RCC->CR & RCC_CR_PLLRDY) == 0);
        /* Set maximus AHB/APB bus clocks */
        RCC->CFGR &= ~((0x7 << RCC_CFGR_PPRE2_Pos) | (0x7 << RCC_CFGR_PPRE1_Pos) 
            | (0xF << RCC_CFGR_HPRE_Pos));
        RCC->CFGR |= (APB_PRESCALER[pll_parameters.ppre2] << RCC_CFGR_PPRE2_Pos)
            | (APB_PRESCALER[pll_parameters.ppre1] << RCC_CFGR_PPRE1_Pos);
    }

    /* Determinate the target system core clock to FLASH config */
    uint32_t system_clk;
    switch (cfgr_switch)
    {
    case 1:
        system_clk = HSE_VALUE;
        break;
    case 2:
        system_clk = pll_parameters.freq_o;
        break;
    case 0:
    default:
        system_clk = HSI_VALUE;
        break;
    }

    /* Referer to Relation between CPU clock frequency and Flash memory read 
       time [increasing/decreasing the CPU Freq.] pag. 81 - Refrence Manual*/
    if (system_clk > SystemCoreClock)
    {
        flash_acr_config_auto(system_clk);
    }

    cfgr_ready = (cfgr_switch<<RCC_CFGR_SWS_Pos);
    /* Switch clock from system */
    RCC->CFGR &= ~0x3; RCC->CFGR |= cfgr_switch;
    /* Wait for the system complete the switch */
    uint32_t tmp;
    do {
        tmp = (RCC->CFGR & 0xC);
    }
    while (tmp != cfgr_ready);

    if (system_clk < SystemCoreClock)
    {
        flash_acr_config_auto(system_clk);
    }

    /* Update the internal monitor clock variable */
    sys_clk_update();
    /* Shutdown the other source clocks */
    RCC->CR &= ((RCC_CR_PLLON | RCC_CR_HSEON| RCC_CR_HSION) & (source | pll_request));

    /* Update current clocks */
    rcc_clocks_current.system = system_clk;
    rcc_clocks_current.ahb = system_clk;
}

void rcc_pll_param_cpte(uint8_t pll_clk_out, rcc_pllclk_t pll_clk_in)
{
    pll_parameters.source = pll_clk_in;
    pll_parameters.freq_o = pll_clk_out * 1000000;

    /* Save previous bus speeds */
    rcc_clocks_previous.apb1 = rcc_clocks_current.apb1;
    rcc_clocks_previous.apb2 = rcc_clocks_current.apb2;

    const uint8_t pll_p[] = /* Decode table for PLL_P values */
    {
        2,4,6,8
    };

    /* 2 MHz target fvco_in (suggested by reference manual) (pag. 227) */
    /* input vco frequency [MHz] */
    const uint32_t fvco_in = 2; 
    /* output vco frequency [MHz] */
    uint32_t fvco_out; 

    /* Determinate PLL clock */
    uint32_t __pll_clk_in = (pll_clk_in == RCC_PLLCLK_HSE) ? HSE_VALUE : HSI_VALUE;
    __pll_clk_in /= 1000000UL;

    /* Configure de max value to pll_p parameter */
    pll_parameters.p = 3; /* Bit value for request pll_p */

    /* Determinate the minimun pll_p for request clock */
    do {
        uint8_t idx = pll_parameters.p;
        /* fvco_out = pll_out * pll_p (pag. 226 - reference manual) */
        fvco_out = pll_clk_out * pll_p[idx]; 
        if (fvco_out > RCC_PLLN_MAX_VALUE) { 
            /* If fvco_out is major than FVCO_MAX decrease pll_p
               to get a valid value for fvco_out freq */
            pll_parameters.p -= 1;
        } else {
            /* Otherwise break the while routine */
            break;
        }
    } while(pll_parameters.p > 0);
    /* Recalculate fvco with the last pll_p value */
    fvco_out = pll_clk_out * pll_p[pll_parameters.p];
    /* Compute other parameters */
    pll_parameters.m = __pll_clk_in / fvco_in;
    pll_parameters.n = fvco_out / fvco_in;
    pll_parameters.q = fvco_out / 48;
    /* PLL_Q Must not be less than 2 */
    if (pll_parameters.q < 2)
    {
        pll_parameters.q = 2;
    }
    /* Compute APB preescalers to get max bus speeds */
    pll_parameters.ppre1 = pll_clk_out / 42; /* 42MHz in APB1 case */
    pll_parameters.ppre2 = pll_clk_out / 84; /* 84MHz in APB2 case */
    
    /* Update current bus speeds */
    rcc_clocks_current.apb1 = (uint32_t) 42000000;
    rcc_clocks_current.apb2 = (uint32_t) 84000000;
}

void rcc_pll_param_set(void)
{
    RCC->PLLCFGR |= (pll_parameters.q << RCC_PLLCFGR_PLLQ_Pos) 
        | (pll_parameters.p << RCC_PLLCFGR_PLLP_Pos)
        | (pll_parameters.n << RCC_PLLCFGR_PLLN_Pos) 
        | (pll_parameters.m << RCC_PLLCFGR_PLLM_Pos) 
        | (pll_parameters.source);
}

void rcc_pll_param_clr(void)
{
    RCC->PLLCFGR &= ~((0xF << RCC_PLLCFGR_PLLQ_Pos) 
        | (0x3 << RCC_PLLCFGR_PLLP_Pos)
        | (0x1FF << RCC_PLLCFGR_PLLN_Pos) 
        | (0x3F << RCC_PLLCFGR_PLLM_Pos)
        | RCC_PLLCFGR_PLLSRC);
}

uint32_t rcc_clk_get_apb1(void)
{
    return rcc_clocks_current.apb1;
}

uint32_t rcc_clk_get_apb2(void)
{
    return rcc_clocks_current.apb2;
}