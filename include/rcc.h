/**
 * @file rcc.h
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

/**
 * @todo Backupdomain control implementation
 * @todo Clock ctrl & status implementation
 * @todo Spread Spectrum Clock Generator implementation
 * @todo I²S implementation
 * @todo PLL Q Individual Compute & Set
 * @todo APB[1,2] Individual Preescaleers Set
 * @todo MCU Clock Output Implementation
 * @todo RTC Preescalers implementation
 * @todo RCC Interrupts
 * 
 */

#ifndef _RCC_H_
#define _RCC_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup rcc RCC
 */

/**
 * @defgroup public_rcc Public
 * @ingroup rcc
 */

#include "system.h"

/*----------------------------------------------------------------------------*/
/* Enums*/
/*----------------------------------------------------------------------------*/

/**
 * @ingroup public_rcc
 * @brief System core clocks.
 *
 * Source clocks than can be configured as Systen core clock.
 */
typedef enum
{
    RCC_SYSCLK_HSI  = RCC_CR_HSION, /*!< System core clock from hsi source*/
    RCC_SYSCLK_HSE  = RCC_CR_HSEON, /*!< System core clock from hse source*/
    RCC_SYSCLK_PLL  = RCC_CR_PLLON, /*!< System core clock from pll source*/
    RCC_SYSCLK_END /*!< End of rcc_sysclk enum */
} rcc_sysclk_t;

/**
 * @ingroup public_rcc
 * @brief PLL surce clocks.
 *
 * Source clocks than can be configured as PLL Input clock source.
 */
typedef enum
{
    RCC_PLLCLK_HSI  = RCC_PLLCFGR_PLLSRC_HSI, /*!< PLL input clock from hsi source*/
    RCC_PLLCLK_HSE  = RCC_PLLCFGR_PLLSRC_HSE, /*!< PLL input clock from hse source*/
    RCC_PLLCLK_NONE = 0xFFFFFFFE, /*!< PLL disable input */
    RCC_PLLCLK_END /*!< End of rcc_pllclk enum */
} rcc_pllclk_t;

/**
 * @ingroup public_rcc
 * @brief AHB1 peripherals masks.
 *
 * Peripherals mask at AHB1 BUS.
 */
typedef enum
{
    RCC_AHB1_GPIOA      = RCC_AHB1ENR_GPIOAEN,      /*!< GPIOA Enable mask */
    RCC_AHB1_GPIOB      = RCC_AHB1ENR_GPIOBEN,      /*!< GPIOB Enable mask */
    RCC_AHB1_GPIOC      = RCC_AHB1ENR_GPIOCEN,      /*!< GPIOC Enable mask */
    RCC_AHB1_GPIOD      = RCC_AHB1ENR_GPIODEN,      /*!< GPIOD Enable mask */
    RCC_AHB1_GPIOE      = RCC_AHB1ENR_GPIOEEN,      /*!< GPIOE Enable mask */
    RCC_AHB1_GPIOF      = RCC_AHB1ENR_GPIOFEN,      /*!< GPIOF Enable mask */
    RCC_AHB1_GPIOG      = RCC_AHB1ENR_GPIOGEN,      /*!< GPIOG Enable mask */
    RCC_AHB1_GPIOH      = RCC_AHB1ENR_GPIOHEN,      /*!< GPIOH Enable mask */
    RCC_AHB1_GPIOI      = RCC_AHB1ENR_GPIOIEN,      /*!< GPIOI Enable mask */
    RCC_AHB1_CRC        = RCC_AHB1ENR_CRCEN,        /*!< CRC Enable mask */
    RCC_AHB1_BKPSRAM    = RCC_AHB1ENR_BKPSRAMEN,    /*!< BKPSRAM Enable mask */
    RCC_AHB1_CCMDATA    = RCC_AHB1ENR_CCMDATARAMEN, /*!< CCMDATA Enable mask */
    RCC_AHB1_DMA1       = RCC_AHB1ENR_DMA1EN,       /*!< DMA1 Enable mask */
    RCC_AHB1_DMA2       = RCC_AHB1ENR_DMA2EN,       /*!< DMA2 Enable mask */
    RCC_AHB1_ETHMAC     = RCC_AHB1ENR_ETHMACEN,     /*!< ETHMAC Enable mask */
    RCC_AHB1_ETHMACTX   = RCC_AHB1ENR_ETHMACTXEN,   /*!< ETHMACTX Enable mask */
    RCC_AHB1_ETHMACRX   = RCC_AHB1ENR_ETHMACRXEN,   /*!< ETHMACRX Enable mask */
    RCC_AHB1_ETHMACPTP  = RCC_AHB1ENR_ETHMACPTPEN,  /*!< ETHMACPTP Enable mask */
    RCC_AHB1_OTGHS      = RCC_AHB1ENR_OTGHSEN,      /*!< OTGHS Enable mask */
    RCC_AHB1_OTGHSULPI  = RCC_AHB1ENR_OTGHSULPIEN,  /*!< OTGHS ULPI Enable mask */
    RCC_AHB1_END /*!< End of rcc_ahb1 enum */
} rcc_ahb1_t;

/**
 * @ingroup public_rcc
 * @brief AHB2 peripherals masks.
 *
 * Peripherals mask at AHB2 BUS.
 */
typedef enum
{
    RCC_AHB2_DCMI   = RCC_AHB2ENR_DCMIEN,   /*!< DCMI Enable mask */
#if defined(RCC_AHB2ENR_CRYPEN)
    RCC_AHB2_CRYP   = RCC_AHB2ENR_CRYPEN,   /*!< CRYP Enable mask */
#endif /* defined(RCC_AHB2ENR_CRYPEN) */
#if defined(RCC_AHB2ENR_HASHEN)
    RCC_AHB2_HASH   = RCC_AHB2ENR_HASHEN,   /*!< HASH Enable mask */ 
#endif /* defined(RCC_AHB2ENR_HASHEN) */
    RCC_AHB2_RNG    = RCC_AHB2ENR_RNGEN,    /*!< RNG Enable mask */
    RCC_AHB2_OTGFS  = RCC_AHB2ENR_OTGFSEN,  /*!< OTGFS Enable mask */
    RCC_AHB2_END /*!< End of rcc_ahb2 enum */
} rcc_ahb2_t;

/**
 * @ingroup public_rcc
 * @brief AHB3 peripherals masks.
 *
 * Peripherals mask at AHB3 BUS.
 */
typedef enum
{
    RCC_AHB3_FSMC   = RCC_AHB3ENR_FSMCEN,   /*!< FSMC Enable mask */
    RCC_AHB3_END /*!< End of rcc_ahb3 enum */
} rcc_ahb3_t;

/**
 * @ingroup public_rcc
 * @brief APB1 peripherals masks.
 *
 * Peripherals mask at APB1 BUS.
 */
typedef enum
{
    RCC_APB1_TIM2   = RCC_APB1ENR_TIM2EN,   /*!< TIM2 Enable mask */
    RCC_APB1_TIM3   = RCC_APB1ENR_TIM3EN,   /*!< TIM3 Enable mask */
    RCC_APB1_TIM4   = RCC_APB1ENR_TIM4EN,   /*!< TIM4 Enable mask */
    RCC_APB1_TIM5   = RCC_APB1ENR_TIM5EN,   /*!< TIM5 Enable mask */
    RCC_APB1_TIM6   = RCC_APB1ENR_TIM6EN,   /*!< TIM6 Enable mask */
    RCC_APB1_TIM7   = RCC_APB1ENR_TIM7EN,   /*!< TIM7 Enable mask */
    RCC_APB1_TIM12  = RCC_APB1ENR_TIM12EN,  /*!< TIM12 Enable mask */
    RCC_APB1_TIM13  = RCC_APB1ENR_TIM13EN,  /*!< TIM13 Enable mask */
    RCC_APB1_TIM14  = RCC_APB1ENR_TIM14EN,  /*!< TIM14 Enable mask */
    RCC_APB1_WWDG   = RCC_APB1ENR_WWDGEN,   /*!< WWDG Enable mask */
    RCC_APB1_SPI2   = RCC_APB1ENR_SPI2EN,   /*!< SPI2 Enable mask */
    RCC_APB1_SPI3   = RCC_APB1ENR_SPI3EN,   /*!< SPI3 Enable mask */
    RCC_APB1_USART2 = RCC_APB1ENR_USART2EN, /*!< USART2 Enable mask */
    RCC_APB1_USART3 = RCC_APB1ENR_USART3EN, /*!< USART3 Enable mask */
    RCC_APB1_UART4  = RCC_APB1ENR_UART4EN,  /*!< UART4 Enable mask */
    RCC_APB1_UART5  = RCC_APB1ENR_UART5EN,  /*!< UART5 Enable mask */
    RCC_APB1_I2C1   = RCC_APB1ENR_I2C1EN,   /*!< I2C1 Enable mask */
    RCC_APB1_I2C2   = RCC_APB1ENR_I2C2EN,   /*!< I2C2 Enable mask */
    RCC_APB1_I2C3   = RCC_APB1ENR_I2C3EN,   /*!< I2C3 Enable mask */
    RCC_APB1_CAN1   = RCC_APB1ENR_CAN1EN,   /*!< CAN1 Enable mask */
    RCC_APB1_CAN2   = RCC_APB1ENR_CAN2EN,   /*!< CAN2 Enable mask */
    RCC_APB1_PWR    = RCC_APB1ENR_PWREN,    /*!< PWR Enable mask */
    RCC_APB1_DAC    = RCC_APB1ENR_DACEN,    /*!< DAC Enable mask */
    RCC_APB1_END /*!< End of rcc_apb1 enum */
} rcc_apb1_t;

/**
 * @ingroup public_rcc
 * @brief APB2 peripherals masks.
 *
 * Peripherals mask at APB2 BUS.
 */
typedef enum
{
    RCC_APB2_TIM1   = RCC_APB2ENR_TIM1EN,   /*!< TIM1 Enable mask */
    RCC_APB2_TIM8   = RCC_APB2ENR_TIM8EN,   /*!< TIM8 Enable mask */
    RCC_APB2_USART1 = RCC_APB2ENR_USART1EN, /*!< USART1 Enable mask */
    RCC_APB2_USART6 = RCC_APB2ENR_USART6EN, /*!< USART6 Enable mask */
    RCC_APB2_ADC1   = RCC_APB2ENR_ADC1EN,   /*!< ADC1 Enable mask */
    RCC_APB2_ADC2   = RCC_APB2ENR_ADC2EN,   /*!< ADC2 Enable mask */
    RCC_APB2_ADC3   = RCC_APB2ENR_ADC3EN,   /*!< ADC3 Enable mask */
    RCC_APB2_SDIO   = RCC_APB2ENR_SDIOEN,   /*!< SDIO Enable mask */
    RCC_APB2_SPI1   = RCC_APB2ENR_SPI1EN,   /*!< SPI1 Enable mask */
    RCC_APB2_SYSCFG = RCC_APB2ENR_SYSCFGEN, /*!< SYSCFG Enable mask */
    RCC_APB2_TIM9   = RCC_APB2ENR_TIM9EN,   /*!< TIM9 Enable mask */
    RCC_APB2_TIM10  = RCC_APB2ENR_TIM10EN,  /*!< TIM10 Enable mask */
    RCC_APB2_TIM11  = RCC_APB2ENR_TIM11EN,  /*!< TIM11 Enable mask */
    RCC_APB2_END /*!< End of rcc_apb2 enum */
} rcc_apb2_t;

/*----------------------------------------------------------------------------*/
/* Functions */
/*----------------------------------------------------------------------------*/

/** ### rcc:system_core_clock:select
 * @ingroup public_rcc
 * @brief Select and inicializate the system core clock.
 *
 * Switch the system core clock source to a target 'source'.
 *
 * @param[in] source System target source clock.
 *
 * @return None.
 * 
 * @note 1. If a PLL is the target clock you must define the PLL source clock with
 *       an OR operator.
 * 
 * @note 2. If a PLL is the target clock you must fisrt compute the PLL parameters
 *       and set it before switch the system core clock.
 * 
 * @note 3. Others clocks will be deactivated after call this function.
 *
 * E.g.
 * * For HSE or HSI:
 * @code
 * ...
 * // This enable and switch the system core clock to HSE target
 * rcc_sysclk_select(RCC_SYSCLK_HSE);
 * ...
 * @endcode
 * * For PLL:
 * @code
 * ...
 * // This enable and switch the system core clock to PLL target with
 * // HSE as input PLL clock
 * rcc_sysclk_select(RCC_SYSCLK_PLL | RCC_SYSCLK_HSE);
 * ...
 * @endcode
 */
void rcc_sysclk_select(rcc_sysclk_t source);

/** ### rcc:pll:parameter:compute
 * @ingroup public_rcc
 * @brief Compute PLL configuration parameters.
 *
 * Compute M,N,P and Q PLL parameters from the desired clock for the PLL and save
 * them on static internal variable [pll_parameters].
 *
 * @param[in] pll_clk_out Desired PLL clock [MHz].
 * @param[in] pll_clk_in PLL source input clock.
 *
 * @return None.
 *
 * @note Always Q parameter will compute to get a 48 MHz PLL48CK clock, if you
 *       need less you must call rcc_pll_param_q_set function.
 *
 * E.g.
 * @code
 * ...
 * // It will calculate the parameters to get 168 MHz at PLL output with HSE
 * // as input clock source to PLL
 * rcc_pll_param_cpte(168, PLL_SRC_HSE);
 * ...
 * @endcode
 */
void rcc_pll_param_cpte(uint8_t pll_clk_out, rcc_pllclk_t pll_clk_in);

/** ### rcc:pll:parameter:set
 * @ingroup public_rcc
 * @brief Set PLL parameters stored on static internal variable [pll_parameters].
 * 
 * Set P, M, N, Q, PREAHB1 & PREAHB2 parameters on RCC_PLLCFGR Register.
 * 
 * @return None.
 * E.g.
 * @code
 * ...
 * // It will set the parameters stored on internal pll_paramenters variable
 * // to PLL
 * rcc_pll_param_set();
 * ...
 * @endcode
 */
void rcc_pll_param_set(void);

/** ### rcc:pll:parameter:clear
 * @ingroup public_rcc
 * @brief Clear the PLL parameters.
 * 
 * Clear P, M, N, Q, PREAHB1 & PREAHB2 parameters on RCC_PLLCFGR Register.
 *
 * @return None.
 * 
 * E.g.
 * @code
 * ...
 * // It will clear the parameters on PLL
 * rcc_pll_param_clr();
 * ...
 * @endcode
 */
void rcc_pll_param_clr(void);

/** ### rcc:pll:parameter:compute_and_set
 * @ingroup public_rcc
 * @brief Compute & set the PLL Parameters.
 * 
 * Call rcc_pll_param_cpte, rcc_pll_param_clr & rcc_pll_param_set functions.
 * 
 * @param[in] pll_clk_out Desired PLL clock [MHz].
 * @param[in] pll_clk_in PLL source input clock.
 * 
 * @return None.
 * 
 * E.g.
 * @code
 * ...
 * // It will calculate the parameters to get 168 MHz at PLL output with HSE
 * // as input clock source to PLL and then sets to PLL registers
 * rcc_pll_param_cpte_set(168, PLL_SRC_HSE);
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_pll_param_cpte_set(uint8_t pll_clk_out, 
    rcc_pllclk_t pll_clk_in
)
{
    rcc_pll_param_cpte(pll_clk_out, pll_clk_in);
    rcc_pll_param_clr();
    rcc_pll_param_set();
}

/** ### rcc:clock:enable:AHB1
 * @ingroup public_rcc
 * @brief Enable clock to AHB1 peripherial/s.
 * 
 * Allow enable following clock to peripherials on RCC_APB1ENR register:
 *  * GPIO[A,B,C...I].
 *  * CRC.
 *  * Backup SRAM interface.
 *  * CCM Data RAM interface.
 *  * DMA[1:2].
 *  * Ethernet [MAC, TX, RX, PTP].
 *  * USB [HS, HS_ULPI].
 *
 * @param[in] mask AHB1 Peripheral/s mask to be enabled.
 * 
 * @return None.
 * 
 * @note 1. You can enable multiple peripherals at time passing each of them 
 *          with an OR operator.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * For one peripheral enable:
 * @code
 * ...
 * // This enable clock to GPIOA peripheral
 * rcc_clk_en_ahb1(RCC_AHB1_GPIOA);
 * ...
 * @endcode
 * For multiple peripherals enable:
 * @code
 * ...
 * // This enable clock to GPIOA & GPIOB peripheral
 * rcc_clk_en_ahb1(RCC_AHB1_GPIOA | RCC_AHB1_GPIOB);
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_en_ahb1(rcc_ahb1_t mask)
{
    RCC->AHB1ENR |= mask;
}

/** ### rcc:clock:disable:AHB1
 * @ingroup public_rcc
 * @brief Disable clock to AHB1 peripherial/s.
 * 
 * Allow disable following clock to peripherials on RCC_APB1ENR register:
 *  * GPIO[A,B,C,...I].
 *  * CRC.
 *  * Backup SRAM interface.
 *  * CCM Data RAM interface.
 *  * DMA[1,2].
 *  * Ethernet [MAC, TX, RX, PTP].
 *  * USB [HS, HS_ULPI].
 *
 * @param[in] mask AHB1 Peripheral/s mask to be disabled.
 * 
 * @return None.
 * 
 * @note 1. You can disable multiple peripherals at time passing each of them 
 *          with an OR operator.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * For one peripheral disable:
 * @code
 * ...
 * // This disable clock to GPIOA peripheral
 * rcc_clk_dis_ahb1(RCC_AHB1_GPIOA);
 * ...
 * @endcode
 * For multiple peripheral disable:
 * @code
 * ...
 * // This disable clock to GPIOA & GPIOB peripheral
 * rcc_clk_dis_ahb1(RCC_AHB1_GPIOA | RCC_AHB1_GPIOB);
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_dis_ahb1(rcc_ahb1_t mask)
{
    RCC->AHB1ENR &= ~mask;
}

/** ### rcc:reset:AHB1
 * @ingroup public_rcc
 * @brief Reset AHB1 peripherial/s.
 * 
 * Allow reset following peripherials setting and clear RCC_AHB1RSTR register:
 *  * GPIO[A,B,C,...I].
 *  * CRC.
 *  * Backup SRAM interface.
 *  * CCM Data RAM interface.
 *  * DMA[1:2].
 *  * Ethernet [MAC, TX, RX, PTP].
 *  * USB [HS, HS_ULPI].
 *
 * @param[in] mask AHB1 Peripheral/s mask to be reset.
 * 
 * @return None.
 * 
 * @note 1. You can reset multiple peripherals at time passing each of them 
 *          with an OR operator.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * For one peripheral reset:
 * @code
 * ...
 * // This reset GPIOA peripheral
 * rcc_rst_ahb1(RCC_AHB1_GPIOA);
 * ...
 * @endcode
 * For multiple peripheral reset:
 * @code
 * ...
 * // This reset GPIOA & GPIOB peripherals
 * rcc_rst_ahb1(RCC_AHB1_GPIOA | RCC_AHB1_GPIOB);
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_rst_ahb1(rcc_ahb1_t mask)
{
    RCC->AHB1RSTR |= mask;
    RCC->AHB1RSTR &= ~mask;
}

/** ### rcc:clock:enable:AHB2
 * @ingroup public_rcc
 * @brief Enable clock to AHB2 peripherial/s.
 * 
 * Allow enable following clock to peripherials on RCC_AHB2ENR register:
 *  * Camera Interface.
 *  * Cryptographic Modules [If it is available].
 *  * Hash Modules [If it is available].
 *  * USB OTG FS.
 *
 * @param[in] mask AHB2 Peripheral/s mask to be enabled.
 * 
 * @return None.
 * 
 * @note 1. You can enable multiple peripherals at time passing each of them 
 *          with an OR operator.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * For one peripheral enable:
 * @code
 * ...
 * // This enable clock to Camera Interface peripheral
 * rcc_clk_en_ahb2(RCC_AHB2_DCMI);
 * ...
 * @endcode
 * For multiple peripherals enable:
 * @code
 * ...
 * // This enable clock to Camera Interface & Random Number Generator peripherals
 * rcc_clk_en_ahb2(RCC_AHB2_RNG | RCC_AHB2_DCMI);
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_en_ahb2(rcc_ahb2_t mask)
{
    RCC->AHB2ENR |= mask;
}

/** ### rcc:clock:disable:AHB2
 * @ingroup public_rcc
 * @brief Disable clock to AHB2 peripherial/s.
 * 
 * Allow disable following clock to peripherials on RCC_AHB2ENR register:
 *  * Camera Interface.
 *  * Cryptographic Modules [If it is available].
 *  * Hash Modules [If it is available].
 *  * USB OTG FS.
 *
 * @param[in] mask AHB2 Peripheral/s mask to be disabled.
 * 
 * @return None.
 * 
 * @note 1. You can disable multiple peripherals at time passing each of them 
 *          with an OR operator.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * For one peripheral disable:
 * @code
 * ...
 * // This disable clock to Camera Interface peripheral
 * rcc_clk_dis_ahb2(RCC_AHB2_DCMI);
 * ...
 * @endcode
 * For multiple peripherals enable:
 * @code
 * ...
 * // This disable clock to Camera Interface & Random Number Generator peripherals
 * rcc_clk_dis_ahb2(RCC_AHB2_RNG | RCC_AHB2_DCMI);
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_dis_ahb2(rcc_ahb2_t mask)
{
    RCC->AHB2ENR &= ~mask;
}

/** ### rcc:reset:AHB2
 * @ingroup public_rcc
 * @brief Reset AHB2 peripherial/s.
 * 
 * Allow reset following peripherials setting and clear RCC_AHB2RSTR register:
 *  * Camera Interface.
 *  * Cryptographic Modules [If it is available].
 *  * Hash Modules [If it is available].
 *  * USB OTG FS.
 *
 * @param[in] mask AHB2 Peripheral/s mask to be reset.
 * 
 * @return None.
 * 
 * @note 1. You can reset multiple peripherals at time passing each of them
 *          with an OR operator.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * For one peripheral reset:
 * @code
 * ...
 * // This resets Camera Interface peripheral
 * rcc_rst_ahb2(RCC_AHB2_DCMI);
 * ...
 * @endcode
 * For multiple peripherals enable:
 * @code
 * ...
 * // This resets Camera Interface & Random Number Generator peripherals
 * rcc_rst_ahb2(RCC_AHB2_RNG | RCC_AHB2_DCMI);
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_rst_ahb2(rcc_ahb2_t mask)
{
    RCC->AHB2RSTR |= mask;
    RCC->AHB2RSTR &= ~mask;
}

/** ### rcc:clock:enable:AHB3
 * @ingroup public_rcc
 * @brief Enable clock to AHB3 peripherial/s.
 * 
 * Allow enable following clock to peripherials on RCC_AHB3ENR register:
 *  * Flexible static memory controller.
 *
 * @param[in] mask AHB3 Peripheral/s mask to be enabled.
 * 
 * @return None.
 * 
 * @note It is a forced inline function.
 * 
 * E.g. @n
 * @code
 * ...
 * // This enable clock to FSMC peripheral
 * rcc_clk_en_ahb3(RCC_AHB3_FSMC);
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_en_ahb3(rcc_ahb3_t mask)
{
    RCC->AHB3ENR |= mask;
}

/** ### rcc:clock:disable:AHB3
 * @ingroup public_rcc
 * @brief Disable clock to AHB3 peripherial/s.
 * 
 * Allow disable following clock to peripherials on RCC_AHB3ENR register:
 *  * Flexible static memory controller
 *
 * @param[in] mask AHB3 Peripheral/s mask to be disabled.
 * 
 * @return None.
 * 
 * @note It is a forced inline function.
 * 
 * E.g. @n
 * @code
 * ...
 * // This disable clock to GPIOA peripheral
 * rcc_clk_dis_ahb3(RCC_AHB3_FSMC);
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_dis_ahb3(rcc_ahb3_t mask)
{
    RCC->AHB3ENR &= ~mask;
}

/** ### rcc:reset:AHB3
 * @ingroup public_rcc
 * @brief Reset AHB3 peripherial/s.
 * 
 * Allow reset following peripherials setting and clear RCC_AHB3RSTR register:
 *  * Flexible static memory controller.
 *
 * @param[in] mask AHB3 Peripheral/s mask to be reset.
 * 
 * @return None.
 * 
 * @note It is a forced inline function.
 * 
 * E.g. @n
 * @code
 * ...
 * // This reset GPIOA peripheral
 * rcc_rst_ahb3(RCC_AHB3_FSMC);
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_rst_ahb3(rcc_ahb3_t mask)
{
    RCC->AHB3RSTR |= mask;
    RCC->AHB3RSTR &= ~mask;
}

/** ### rcc:clock:enable:APB1
 * @ingroup public_rcc
 * @brief Enable clock to APB1 peripherial/s.
 * 
 * Allow enable following clock to peripherials on RCC_APB1ENR register:
 *  * Timmers TIM[2,3,4...7,12,13,14].
 *  * Window Watch Dog WWD.
 *  * SPI[2,3].
 *  * USART[2,3,4*,5*] * UART ONLY.
 *  * I²C[1,2,3].
 *  * CAN[1,2].
 *  * Power Interface.
 *  * DAC.
 *
 * @param[in] mask APB1 Peripheral/s mask to be enabled.
 * 
 * @return None.
 * 
 * @note 1. You can enable multiple peripherals at time passing each of them 
 *          with an OR operator.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * For one peripheral enable:
 * @code
 * ...
 * // This enable clock to DAC peripheral
 * rcc_clk_en_apb1(RCC_APB1_DAC);
 * ...
 * @endcode
 * For multiple peripherals enable:
 * @code
 * ...
 * // This enable clock to DAC & TIM2 peripheral
 * rcc_clk_en_apb1(RCC_APB1_DAC | RCC_APB1_TIM2);
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_en_apb1(rcc_apb1_t mask)
{
    RCC->APB1ENR |= mask;
}

/** ### rcc:clock:disable:APB1
 * @ingroup public_rcc
 * @brief Disable clock to APB1 peripherial/s.
 * 
 * Allow disable following clock to peripherials on RCC_APB1ENR register:
 *  * Timmers TIM[2,3,4...7,12,13,14].
 *  * Window Watch Dog.
 *  * SPI[2,3].
 *  * USART[2,3,4*,5*] * UART ONLY.
 *  * I²C[1,2,3].
 *  * CAN[1,2].
 *  * Power Interface.
 *  * DAC.
 *
 * @param[in] mask APB1 Peripheral/s mask to be disabled.
 * 
 * @return None.
 * 
 * @note 1. You can disable multiple peripherals at time passing each of them 
 *          with an OR operator.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * For one peripheral disable:
 * @code
 * ...
 * // This disable clock to DAC peripheral
 * rcc_clk_dis_apb1(RCC_APB1_DAC);
 * ...
 * @endcode
 * For multiple peripherals enable:
 * @code
 * ...
 * // This disable clock to DAC & TIM2 peripherals
 * rcc_clk_dis_apb1(RCC_APB1_DAC | RCC_APB1_TIM2);
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_dis_apb1(rcc_apb1_t mask)
{
    RCC->APB1ENR &= ~mask;
}

/** ### rcc:reset:APB1
 * @ingroup public_rcc
 * @brief Reset APB1 peripherial/s.
 * 
 * Allow reset following peripherials setting and clear RCC_APB1RSTR register:
 *  * Timmers TIM[2,3,4...7,12,13,14].
 *  * Window Watch Dog.
 *  * SPI[2,3].
 *  * USART[2,3,4*,5*] * UART ONLY.
 *  * I²C[1,2,3].
 *  * CAN[1,2].
 *  * Power Interface.
 *  * DAC.
 *
 * @param[in] mask APB1 Peripheral/s mask to be reset.
 * 
 * @return None.
 * 
 * @note 1. You can reset multiple peripherals at time passing each of them with 
 *          an OR operator.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * For one peripheral reset:
 * @code
 * ...
 * // This reset DAC peripheral
 * rcc_rst_apb1(RCC_APB1_DAC);
 * ...
 * @endcode
 * For multiple peripherals reset:
 * @code
 * ...
 * // This reset DAC & TIM2 peripherals
 * rcc_rst_apb1(RCC_APB1_DAC | RCC_APB1_TIM2);
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_rst_apb1(rcc_apb1_t mask)
{
    RCC->APB1RSTR |= mask;
    RCC->APB1RSTR &= ~mask;
}

/** ### rcc:clock:enable:APB2
 * @ingroup public_rcc
 * @brief Enable clock to APB2 peripherial/s.
 * 
 * Allow enable following clock to peripherials on RCC_APB2ENR register:
 *  * Timmers TIM[1,8,9,10,11].
 *  * USART[1,6].
 *  * ADC[1,2,3].
 *  * SDIO (SD Interface).
 *  * SPI[1].
 *  * System Configuration Controller SYSCF.
 *
 * @param[in] mask APB2 Peripheral/s mask to be enabled.
 * 
 * @return None.
 * 
 * @note 1. You can enable multiple peripherals at time passing each of them 
 *          with an OR operator.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * For one peripheral enable:
 * @code
 * ...
 * // This enable clock to USART1 peripheral
 * rcc_clk_en_apb2(RCC_APB2_USART1);
 * ...
 * @endcode
 * For multiple peripherals enable:
 * @code
 * ...
 * // This enable clock to ADC1 & USART1 peripherals
 * rcc_clk_en_apb2(RCC_APB2_ADC1 | RCC_APB2_USART1);
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_en_apb2(rcc_apb2_t mask)
{
    RCC->APB2ENR |= mask;
}

/** ### rcc:clock:disable:APB2
 * @ingroup public_rcc
 * @brief Disable clock to APB2 peripherial/s.
 * 
 * Allow disable following clock to peripherials on RCC_APB2ENR register:
 *  * Timmers TIM[1,8,9,10,11].
 *  * USART[1,6].
 *  * ADC[1,2,3].
 *  * SDIO (SD Interface).
 *  * SPI[1].
 *  * System Configuration Controller SYSCF.
 *
 * @param[in] mask APB2 Peripheral/s mask to be disabled.
 * 
 * @return None.
 * 
 * @note 1. You can disable multiple peripherals at time passing each of them 
 *          with an OR operator.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * For one peripheral disable:
 * @code
 * ...
 * // This disable clock to USART1 peripheral
 * rcc_clk_en_apb2(RCC_APB2_USART1);
 * ...
 * @endcode
 * For multiple peripherals disable:
 * @code
 * ...
 * // This disable clock to ADC1 & USART1 peripherals
 * rcc_clk_en_apb2(RCC_APB2_ADC1 | RCC_APB2_USART1);
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_clk_dis_apb2(rcc_apb2_t mask)
{
    RCC->APB2ENR &= ~mask;
}

/** ### rcc:reset:APB2
 * @ingroup public_rcc
 * @brief Reset APB2 peripherial/s.
 * 
 * Allow reset following peripherials setting and clear RCC_APB2RSTR register:
 *  * Timmers TIM[1,8,9,10,11].
 *  * USART[1,6].
 *  * ADC[1,2,3].
 *  * SDIO (SD Interface).
 *  * SPI[1].
 *  * System Configuration Controller SYSCF.
 *
 * @param[in] mask APB2 Peripheral/s mask to be reset.
 * 
 * @return None.
 * 
 * @note 1. You can reset multiple peripherals at time passing each of them with 
 *          an OR operator.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * For one peripheral reset:
 * @code
 * ...
 * // This reset USART1 peripheral
 * rcc_clk_en_apb2(RCC_APB2_USART1);
 * ...
 * @endcode
 * For multiple peripherals enable:
 * @code
 * ...
 * // This reset ADC1 & USART1 peripherals
 * rcc_clk_en_apb2(RCC_APB2_ADC1 | RCC_APB2_USART1);
 * ...
 * @endcode
 */
__FORCE_INLINE void rcc_rst_apb2(rcc_apb2_t mask)
{
    RCC->APB2RSTR |= mask;
    RCC->APB2RSTR &= ~mask;
}

#ifdef __cplusplus
}
#endif

#endif /* _RCC_H_ */
