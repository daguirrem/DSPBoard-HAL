/**
 * @file flash.h
 * @author David A. Aguirre M. (daguirre.m@outlook.com)
 * @brief FLASH - Custom HAL for DSP Board SDK.
 * @version d0.1
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

/**
 * @note Only ACR Configuration is implemented by now.
 */

#ifndef _FLASH_H_
#define _FLASH_H_

/**
 * @addtogroup flash FLASH
 */

/**
 * @defgroup public_flash Public
 * @ingroup flash
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "system.h"

/*----------------------------------------------------------------------------*/
/* Enums */
/*----------------------------------------------------------------------------*/

/**
 * @brief Internal FLASH_ACR available configurations
 * 
 */
typedef enum {
    FLASH_CONFIG_LATENCY_0WS = FLASH_ACR_LATENCY_0WS, //!< Wait States 0
    FLASH_CONFIG_LATENCY_1WS = FLASH_ACR_LATENCY_1WS, //!< Wait States 1
    FLASH_CONFIG_LATENCY_2WS = FLASH_ACR_LATENCY_2WS, //!< Wait States 2
    FLASH_CONFIG_LATENCY_3WS = FLASH_ACR_LATENCY_3WS, //!< Wait States 3
    FLASH_CONFIG_LATENCY_4WS = FLASH_ACR_LATENCY_4WS, //!< Wait States 4
    FLASH_CONFIG_LATENCY_5WS = FLASH_ACR_LATENCY_5WS, //!< Wait States 5
    FLASH_CONFIG_LATENCY_6WS = FLASH_ACR_LATENCY_6WS, //!< Wait States 6
    FLASH_CONFIG_LATENCY_7WS = FLASH_ACR_LATENCY_7WS, //!< Wait States 7
    FLASH_CONFIG_PREFETCH    = FLASH_ACR_PRFTEN,      //!< Prefecth
    FLASH_CONFIG_ICACHE      = FLASH_ACR_ICEN,        //!< Instruction cache
    FLASH_CONFIG_DCACHE      = FLASH_ACR_DCEN,        //!< Data cache
    FLASH_CONFIG_ICACHE_RST  = FLASH_ACR_ICRST,       //!< Instruction cache reset
    FLASH_CONFIG_DCACHE_RST  = FLASH_ACR_DCRST        //!< Data cache reset
} flash_config_t;

/*----------------------------------------------------------------------------*/
/* Functions */
/*----------------------------------------------------------------------------*/

/** ### flash:acr:configuration:set
 * @ingroup public_flash
 * @brief Configure the Flash ACR.
 * 
 * Set the FLASH_ACR register with target configuration.
 * 
 * @param[in] config Target configuration to set.
 * 
 * @return None. 
 * 
 * @note 1. You can set multiple configurations at time passing each of them 
 *          with an OR operator.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * @code
 * ...
 * // This will configure the ACR_: ICACHE, DCACHE, PREFETCH & 3WS
 * flash_acr_config_set(
 *     FLASH_CONFIG_ICACHE | FLASH_CONFIG_DCACHE | FLASH_CONFIG_PREFETCH |
 *     FLASH_CONFIG_LATENCY_3WS
 * );
 * ...
 * @endcode
 */
__FORCE_INLINE void flash_acr_config_set(flash_config_t config)
{
    FLASH->ACR &= ~config;
    FLASH->ACR |= config;
}

/** ### flash:acr:configuration:reset
 * @ingroup public_flash
 * @brief Reset configs at Flash ACR.
 * 
 * Reset the target configuration on FLASH_ACR register.
 * 
 * @param[in] config Target configuration to reset.
 * 
 * @return None. 
 * 
 * @note 1. You can reset multiple configurations at time passing each of them 
 *          with an OR operator.
 * @note 2. It is a forced inline function.
 * 
 * E.g @n
 * @code
 * ...
 * // This reset the ACR_: ICACHE, DCACHE, PREFETCH
 * flash_acr_config_rst(
 *     FLASH_CONFIG_ICACHE | FLASH_CONFIG_DCACHE | FLASH_CONFIG_PREFETCH
 * );
 * ...
 * @endcode
 */
__FORCE_INLINE void flash_acr_config_rst(flash_config_t config)
{
    FLASH->ACR &= ~config;
}

/** ### flash:acr:configuration:automatically
 * @ingroup public_flash
 * @brief Automatically configure the ACR according system clock.
 * 
 * Configure the flash latency according with the target clock to configure.
 * 
 * @param[in] clk Target clock to configure ACR.
 * 
 * @return None.
 * 
 * @note This function enables ICACHE, DCACHE & PREFETCH always. if it does not
 *       necesary, you can disable calling flash_acr_config_rst.
 * 
 * E.g. @n
 * @code
 * ...
 * // This will configure the latency & enable ICACHE, DCACHE & PREFETCH of flash
 * // with target clock of 168000000 [WS will be 5]
 * flash_acr_config_auto(168000000);
 * ...
 * @endcode
 */
void flash_acr_config_auto(uint32_t clk);

#ifdef __cplusplus
}
#endif

#endif /* _FLASH_H_ */
