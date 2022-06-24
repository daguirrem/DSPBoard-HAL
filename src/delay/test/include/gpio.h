/**
 * @file gpio.h
 * @author David A. Aguirre M. (daguirre.m@outlook.com)
 * @brief GPIO - Custom HAL for DSP Board SDK.
 * @version d0.2
 * @date 2022-04-30
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
 * @todo Clock
 *  * Reset ¿?
 * @todo Aleternate function implementation.
 */

#ifndef _GPIO_H_
#define _GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup gpio GPIO
 */

/**
 * @defgroup public_gpio Public
 * @ingroup gpio
 */

#include "system.h"
#include "rcc.h"

/*----------------------------------------------------------------------------*/
/* Enums */
/*----------------------------------------------------------------------------*/

/**
 * @ingroup public_gpio
 * @brief AHB1 GPIO clock mask.
 * 
 * GPIO mask on RCC->AHB1
 */
typedef enum {
    GPIOA_RCC = RCC_AHB1_GPIOA, /*!< GPIOA enable clock mask */
    GPIOB_RCC = RCC_AHB1_GPIOB, /*!< GPIOB enable clock mask */
    GPIOC_RCC = RCC_AHB1_GPIOC, /*!< GPIOC enable clock mask */
    GPIOD_RCC = RCC_AHB1_GPIOD, /*!< GPIOD enable clock mask */
    GPIOE_RCC = RCC_AHB1_GPIOE, /*!< GPIOE enable clock mask */
    GPIOF_RCC = RCC_AHB1_GPIOF, /*!< GPIOF enable clock mask */
    GPIOG_RCC = RCC_AHB1_GPIOG, /*!< GPIOG enable clock mask */
    GPIOH_RCC = RCC_AHB1_GPIOH, /*!< GPIOH enable clock mask */
    GPIOI_RCC = RCC_AHB1_GPIOI  /*!< GPIOI enable clock mask */
} gpio_rcc_t;

/**
 * @ingroup public_gpio
 * @brief GPIO pin mask.
 * 
 * Represents each GPIO pin (input/output).
 */
typedef enum {
    GPIO_IO0   = 0x0001, /*!< IO0 mask */
    GPIO_IO1   = 0x0002, /*!< IO1 mask */
    GPIO_IO2   = 0x0004, /*!< IO2 mask */
    GPIO_IO3   = 0x0008, /*!< IO3 mask */
    GPIO_IO4   = 0x0010, /*!< IO3 mask */
    GPIO_IO5   = 0x0020, /*!< IO4 mask */
    GPIO_IO6   = 0x0040, /*!< IO5 mask */
    GPIO_IO7   = 0x0080, /*!< IO6 mask */
    GPIO_IO8   = 0x0100, /*!< IO7 mask */
    GPIO_IO9   = 0x0200, /*!< IO8 mask */
    GPIO_IO10  = 0x0400, /*!< IO9 mask */
    GPIO_IO11  = 0x0800, /*!< IO10 mask */
    GPIO_IO12  = 0x1000, /*!< IO11 mask */
    GPIO_IO13  = 0x2000, /*!< IO12 mask */
    GPIO_IO14  = 0x4000, /*!< IO13 mask */
    GPIO_IO15  = 0x8000  /*!< IO14 mask */
} gpio_io_t;

/**
 * @ingroup public_gpio
 * @brief GPIO configuration mask.
 * 
 * User defined mask to GPIO custom easy configuration.
 * 
 * @note 12 bit mask where: @n
 *  0b CCCC x SS PP O MM
 *  * C: Configurator mask bits
 *  * S: Speed mask bits
 *  * P: Pull mode mask bits
 *  * O: Output mode mask bits
 *  * M: GPIO mode mask bits
 *  * x: none 
 * 
 * @note Refer product datasheet for max frequency on speed levels
 *       pag. 117 - datasheet [Input/output AC characteristics].
 */
typedef enum {
    GPIO_CONFIG_MODE_INPUT      = 0x100, /*!< GPIO input mode */
    GPIO_CONFIG_MODE_OUTPUT     = 0x101, /*!< GPIO output mode */
    GPIO_CONFIG_MODE_ALTERNATE  = 0x102, /*!< GPIO alternate mode */
    GPIO_CONFIG_MODE_ANALOG     = 0x103, /*!< GPIO analog mode */
    GPIO_CONFIG_OUTPUT_OD       = 0x200, /*!< GPIO output open drain mode */
    GPIO_CONFIG_OUTPUT_PP       = 0x204, /*!< GPIO output push-pull mode */
    GPIO_CONFIG_PULL_NONE       = 0x400, /*!< GPIO input none pull mode */
    GPIO_CONFIG_PULL_UP         = 0x408, /*!< GPIO input pull-up mode */
    GPIO_CONFIG_PULL_DOWN       = 0x410, /*!< GPIO input pull-down mode */
    GPIO_CONFIG_SPEED_LOW       = 0x800, /*!< GPIO low speed mode */
    GPIO_CONFIG_SPEED_MEDIUM    = 0x820, /*!< GPIO medium speed mode*/
    GPIO_CONFIG_SPEED_HIGH      = 0x840, /*!< GPIO high speed mode */
    GPIO_CONFIG_SPEED_VHIGH     = 0x860, /*!< GPIO very high speed mode */
} gpio_config_t;

/**
 * @ingroup public_gpio
 * @brief GPIO general mode specific mask.
 * 
 * GPIO general configuration mode mask.
 */
typedef enum {
    GPIO_MODE_INPUT     = 0x0, /*!< GPIO input mode */
    GPIO_MODE_OUTPUT    = 0x1, /*!< GPIO output mode */
    GPIO_MODE_ALTERNATE = 0x2, /*!< GPIO alternate mode */
    GPIO_MODE_ANALOG    = 0x3, /*!< GPIO analog mode */
} gpio_mode_t;


/**
 * @ingroup public_gpio
 * @brief GPIO output mode specific mask.
 * 
 * GPIO output configuration mode mask.
 */
typedef enum {
    GPIO_OUTPUT_PP  = 0x0, /*!< GPIO output push-pull mode */
    GPIO_OUTPUT_OD  = 0x1  /*!< GPIO output open drain mode */
} gpio_output_t;

/**
 * @ingroup public_gpio
 * @brief GPIO input pull mode specific mask.
 * 
 * GPIO input pull configuration mode mask.
 */
typedef enum {
    GPIO_PULL_NONE  = 0x0, /*!< GPIO input none pull mode */
    GPIO_PULL_UP    = 0x1, /*!< GPIO input pull-up mode */
    GPIO_PULL_DOWN  = 0x2, /*!< GPIO input pull-down mode */
} gpio_pull_t;

/**
 * @ingroup public_gpio
 * @brief GPIO speed mode specific mask.
 * 
 * GPIO speed configuration mode mask.
 */
typedef enum {
    GPIO_SPEED_LOW      = 0x0, /*!< GPIO Low Speed Mode */
    GPIO_SPEED_MEDIUM   = 0x1, /*!< GPIO Medium Speed Mode */
    GPIO_SPEED_HIGH     = 0x2, /*!< GPIO High Speed Mode */
    GPIO_SPEED_VHIGH    = 0x3, /*!< GPIO Very High Speed Mode */
} gpio_speed_t;

/**
 * @ingroup public_gpio
 * @brief GPIO alternate function.
 * 
 * AFRL Register alternate function mask.
 */
typedef enum {
    GPIO_ALT_AF0    = 0x00, /*!< GPIO Alternate Function 0 */
    GPIO_ALT_AF1    = 0x01, /*!< GPIO Alternate Function 1 */
    GPIO_ALT_AF2    = 0x02, /*!< GPIO Alternate Function 2 */
    GPIO_ALT_AF3    = 0x03, /*!< GPIO Alternate Function 3 */
    GPIO_ALT_AF4    = 0x04, /*!< GPIO Alternate Function 4 */
    GPIO_ALT_AF5    = 0x05, /*!< GPIO Alternate Function 5 */
    GPIO_ALT_AF6    = 0x06, /*!< GPIO Alternate Function 6 */
    GPIO_ALT_AF7    = 0x07, /*!< GPIO Alternate Function 7 */
    GPIO_ALT_AF8    = 0x08, /*!< GPIO Alternate Function 8 */
    GPIO_ALT_AF9    = 0x09, /*!< GPIO Alternate Function 9 */
    GPIO_ALT_AF10   = 0x0A, /*!< GPIO Alternate Function 10 */
    GPIO_ALT_AF11   = 0x0B, /*!< GPIO Alternate Function 11 */
    GPIO_ALT_AF12   = 0x0C, /*!< GPIO Alternate Function 12 */
    GPIO_ALT_AF13   = 0x0D, /*!< GPIO Alternate Function 13 */
    GPIO_ALT_AF14   = 0x0E, /*!< GPIO Alternate Function 14 */
    GPIO_ALT_AF15   = 0x0F, /*!< GPIO Alternate Function 15 */
} gpio_alt_t;

/*----------------------------------------------------------------------------*/
/* Functions */
/*----------------------------------------------------------------------------*/


/** ### gpio:reset
 * @ingroup public_gpio
 * @brief Reset single or multiple GPIO peripheral/s.
 * 
 * Reset masked peripheral/s in RCC_AHB1RSTR, This will reset ALL registers
 * associated with the target peripheral/s.
 * 
 * @param[in] mask GPIO mask to be reset.
 * 
 * @return None
 * 
 * @note It is a forded inline function.
 * 
 * @see gpio_rcc_t Mask type.
 * @see rcc_ahb1_peripheral_clk_rst Internal rcc function.
 * 
 * E.g. @n
 * * For single GPIO reset:
 * @code
 * ...
 * // This reset a GPIOC peripheral.
 * gpio_rst(GPIOC_RCC);
 * ...
 * @endcode
 * * For Multiple GPIOs reset:
 * @code
 * ...
 * // This reset a GPIOC & GPIOI peripherals.
 * gpio_rst(GPIOC_RCC | GPIOI_RCC);
 * ...
 * @endcode
 */
__FORCE_INLINE void gpio_rst(gpio_rcc_t mask)
{
    rcc_rst_ahb1((rcc_ahb1_t) mask);
}

/** ### gpio:clock:enable:
 * @ingroup public_gpio
 * @brief Enable single or multiple GPIO peripheral/s clock.
 * 
 * Enable clock in RCC_AHB1 to masked GPIO/s.
 * 
 * @param[in] mask GPIO mask to be enabled.
 * 
 * @return None
 * 
 * @note It is a forded inline function.
 * 
 * @see gpio_rcc_t Mask type.
 * @see rcc_ahb1_peripheral_clk_en Internal rcc function.
 * 
 * E.g. @n
 * * For single GPIO clock enable:
 * @code
 * ...
 * // This enable a GPIOC clock.
 * gpio_clock_en(GPIOC_RCC);
 * ...
 * @endcode
 * * For Multiple GPIOs clock enable:
 * @code
 * ...
 * // This enable a GPIOC & GPIOI clock.
 * gpio_clock_en(GPIOC_RCC | GPIOI_RCC);
 * ...
 * @endcode
 */
__FORCE_INLINE void gpio_clock_en(gpio_rcc_t mask)
{
    rcc_clk_en_ahb1((rcc_ahb1_t) mask);
}

/** ### gpio:clock:disable:
 * @ingroup public_gpio
 * @brief Disable single or multiple GPIO peripheral/s clock.
 * 
 * Disable clock in RCC_AHB1 to masked GPIO/s.
 * 
 * @param[in] mask GPIO mask to be disabled.
 * 
 * @return None
 * 
 * @note It is a forded inline function.
 * 
 * @see gpio_rcc_t Mask type.
 * @see rcc_ahb1_peripheral_clk_dis Internal rcc function.
 * 
 * E.g. @n
 * * For single GPIO clock disable:
 * @code
 * ...
 * // This disable a GPIOC clock.
 * gpio_clock_dis(GPIOC_RCC);
 * ...
 * @endcode
 * * For Multiple GPIOs clock disable:
 * @code
 * ...
 * // This disable a GPIOC & GPIOI clock.
 * gpio_clock_dis(GPIOC_RCC | GPIOI_RCC);
 * ...
 * @endcode
 */
__FORCE_INLINE void gpio_clock_dis(gpio_rcc_t mask)
{
    rcc_clk_dis_ahb1((rcc_ahb1_t) mask);
}

/** ### gpio:configure:all [all modes]:
 * @ingroup public_gpio
 * @brief Set single or multiple configuration modes for specific IO/s on 
 * target GPIO port.
 * 
 * Configure full operation mode of single or multiple IO/s on a target GPIO at 
 * same time.
 * 
 * @param[in] gpio Target GPIO port.
 * @param[in] config Desired configuration mask.
 * @param[in] mask Target IO/s mask.
 * 
 * @return None
 * 
 * @note You can set single or multiple configurations on a single or multiple
 *       IOs at same time specifying an OR operator between IOs and/or configs.
 * 
 * @see gpio_config_t Config type
 * @see gpio_io_t Mask type
 * 
 * E.g. @n
 * * Single config on single pin:
 * @code
 * ...
 * // This enable GPIOA[0] as input pin.
 * gpio_config_all(GPIOA, GPIO_CONFIG_MODE_INPUT, GPIO_IO0);
 * ...
 * @endcode
 * * Single config on multiple pins:
 * @code
 * ...
 * // This enable GPIOA[1:0] as input pins.
 * gpio_config_all(GPIOA, GPIO_CONFIG_MODE_INPUT, GPIO_IO0 | GPIO_IO1);
 * ...
 * @endcode
 * * Multiple configs on single pin:
 * @code
 * ...
 * // This enable GPIOA[0] as input pin with an pull-down mode specification.
 * gpio_config_all(
 *     GPIOA, 
 *     GPIO_CONFIG_MODE_INPUT | GPIO_CONFIG_PULL_DOWN,
 *     GPIO_IO0
 * );
 * ...
 * @endcode
 * * Multiple configs on multiple pins:
 * @code
 * ...
 * // This enable GPIOA[2:0] as output pins with open-drain and low speed mode 
 * // specifications.
 * gpio_config_all(
 *     GPIOA, 
 *     GPIO_CONFIG_MODE_OUTPUT | GPIO_CONFIG_OUTPUT_OD | GPIO_CONFIG_SPEED_LOW,
 *     GPIO_IO0 | GPIO_IO1 | GPIO_IO2
 * );
 * ...
 * @endcode
 */
void gpio_config_all (GPIO_TypeDef *gpio, gpio_config_t config, gpio_io_t mask);

/** ### gpio:config:mode [general io mode]:
 * @ingroup public_gpio
 * @brief Set single or multiple IO/s operation mode of target GPIO.
 * 
 * Configure only the IO operation mode of single or multiple IO/s on target
 * GPIO port at same time.
 * 
 * @param[in] gpio Target GPIO port.
 * @param[in] mode Desired operation mode to configure.
 * @param[in] mask Target IO/s mask.
 * 
 * @note To set multiple IOs you must specify an OR operator between IOs.
 * 
 * @return None
 * 
 * E.g. @n
 * * Single pin:
 * @code
 * ...
 * // This enable GPIOA[0] as input pin.
 * gpio_config_mode(GPIOA, GPIO_MODE_INPUT, GPIO_IO0);
 * ...
 * @endcode
 * * Multiple pins:
 * @code
 * ...
 * // This enable GPIOA[9,4,0] as input pins.
 * gpio_config_mode(GPIOA, GPIO_MODE_INPUT, GPIO_IO0 | GPIO_IO4 | GPIO_IO9);
 * ...
 * @endcode
 */
void gpio_config_mode (GPIO_TypeDef *gpio, gpio_mode_t mode, gpio_io_t mask);

/** ### gpio:configure:output:mode:
 * @ingroup public_gpio
 * @brief Set single or multiple IO/s output mode operation of target GPIO.
 * 
 * Configure only the output operation mode of single or multiple IO/s on target
 * GPIO port at same time.
 * 
 * @param[in] gpio Target GPIO port.
 * @param[in] mode Desired output mode to configure.
 * @param[in] mask Target IO/s mask.
 * 
 * @return None
 * 
 * @note 1. To set multiple IOs you must specify an OR operator between IOs.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * * Single pin:
 * @code
 * ...
 * // This enable GPIOA[0] as output push-pull mode specification.
 * gpio_config_output_mode(GPIOA, GPIO_OUTPUT_PP, GPIO_IO0);
 * ...
 * @endcode
 * * Multiple pins:
 * @code
 * ...
 * // This enable GPIOA[4,0] as output open-drain mode specification.
 * gpio_config_output_mode(GPIOA, GPIO_MODE_INPUT, GPIO_IO0 | GPIO_IO4);
 * ...
 * @endcode
 */
__FORCE_INLINE void gpio_config_output_mode (
    GPIO_TypeDef *gpio, gpio_output_t mode, gpio_io_t mask
)
{
    gpio->OTYPER &= ~mask;
    gpio->OTYPER |= mask;
}

/** ### gpio:configure:speed:
 * @ingroup public_gpio
 * @brief Set single or multiple IO/s speed mode of target GPIO.
 * 
 * Configure only the output speed mode of single or multiple IO/s on target
 * GPIO port at same time.
 * 
 * @param[in] gpio Target GPIO port.
 * @param[in] mode Desired speed mode to configure.
 * @param[in] mask Target IO/s mask.
 * 
 * @return None
 * 
 * @note To set multiple IOs you must specify an OR operator between IOs.
 * 
 * E.g. @n
 * * Single pin:
 * @code
 * ...
 * // This enable low speed output on GPIOA[0].
 * gpio_config_speed(GPIOA, GPIO_SPEED_LOW, GPIO_IO0);
 * ...
 * @endcode
 * * Multiple pins:
 * @code
 * ...
 * // This enable medium output on GPIOA[0,4].
 * gpio_config_speed(GPIOA, GPIO_SPEED_MEDIUM, GPIO_IO4 | GPIO_IO0);
 * ...
 * @endcode
 */
void gpio_config_speed (GPIO_TypeDef *gpio, gpio_speed_t speed, gpio_io_t mask);


/** ### gpio:configure:input:pull:mode:
 * @ingroup public_gpio
 * @brief Set single or multiple IO/s input pull operation mode of target GPIO.
 * 
 * Configure only the input operation mode of single or multiple IO/s on target
 * GPIO port at same time.
 * 
 * @param[in] gpio Target GPIO port.
 * @param[in] mode Desired input pull mode to configure.
 * @param[in] mask Target IO/s mask.
 * 
 * @return None
 * 
 * @note To set multiple IOs you must specify an OR operator between IOs.
 * 
 * E.g. @n
 * * Single pin:
 * @code
 * ...
 * // This enable GPIOA[0] as pull-down input.
 * gpio_config_input_pull_mode(GPIOA, GPIO_PULL_DOWN, GPIO_IO0);
 * ...
 * @endcode
 * * Multiple pins:
 * @code
 * ...
 * // This enable GPIOA[0,4] as pull-up input.
 * gpio_config_input_pull_mode(GPIOA, GPIO_PULL_UP, GPIO_IO0 | GPIO_IO4);
 * ...
 * @endcode
 */
void gpio_config_input_pull_mode (
    GPIO_TypeDef *gpio, gpio_pull_t pull_mode, gpio_io_t mask
);

/** ### gpio:config:lock
 * @ingroup public_gpio
 * @brief Lock the configuration IO/s on target GPIO.
 * 
 * Execute a lock sequence for lock the configuration of IO/s on target GPIO.
 * 
 * @param[in] gpio Target GPIO to be locked.
 * @param[in] mask Target IOs to be locked.
 * 
 * @return '0' if lock is succesfull, '1' if does not.
 * 
 * @note After lock the configuration of GPIO, the GPIO can't be unclocked until
 *       MCU is reset or GPIO peripheral is reset.
 * 
 * E.g @n
 * @code
 * ...
 * // This will lock the config of GPIOE[15,13,7:5]
 * gpio_config_lock(
 *     GPIOE, GPIO_IO15 | GPIO_IO13 | GPIO_IO7 | GPIO_IO6 | GPIO_IO5
 * );
 * ...
 * @endcode
 */
uint8_t gpio_config_lock(GPIO_TypeDef *gpio, gpio_io_t mask);

/** ### gpio:port:set:
 * @ingroup public_gpio
 * @brief Set to high level single or multiple outputs on target GPIO.
 * 
 * Write logical one to single or multiple masked IOs on GPIO_BSRR[15:0] target 
 * register.
 * 
 * @param[in] gpio Target GPIO port.
 * @param[in] mask Target output IO/s mask.
 * 
 * @return None 
 * 
 * @note 1. To set multiple IOs you must specify an OR operator between IOs.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * * For single output:
 * @code
 * ...
 * // This set high the GPIOA[0] output.
 * gpio_port_set(GPIOA, GPIO_IO0);
 * ...
 * @endcode
 * * For multiple output:
 * @code
 * ...
 * // This set high the GPIOA[0,2] output.
 * gpio_port_set(GPIOA, GPIO_IO0 | GPIO_IO2);
 * ...
 * @endcode
 */
__FORCE_INLINE void gpio_port_set (GPIO_TypeDef *gpio, gpio_io_t mask)
{
    gpio->BSRR |= mask;
}

/** ### gpio:port:clear:
 * @ingroup public_gpio
 * @brief Set to low level single or multiple outputs on target GPIO.
 * 
 * Write logical one to single or multiple masked IOs on GPIO_BSRR[31:16] target 
 * register.
 * 
 * @param[in] gpio Target GPIO port.
 * @param[in] mask Target output IO/s mask.
 * 
 * @return None 
 * 
 * @note 1. To set multiple IOs you must specify an OR operator between IOs.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * * For single output:
 * @code
 * ...
 * // This set low the GPIOA[0] output.
 * gpio_port_clr(GPIOA, GPIO_IO0);
 * ...
 * @endcode
 * * For multiple output:
 * @code
 * ...
 * // This set low the GPIOA[0,2] output.
 * gpio_port_clr(GPIOA, GPIO_IO0 | GPIO_IO2);
 * ...
 * @endcode
 */
__FORCE_INLINE void gpio_port_clr (GPIO_TypeDef *gpio, gpio_io_t mask)
{
    gpio->BSRR |= mask << 16;
}

/** ### gpio:port:toggle:
 * @ingroup public_gpio
 * @brief Toggle the output mask from GPIO.
 * 
 * Toggle the IO/s status of single or multiple masked IO/s on GPIO_ODR
 * target register.
 * 
 * @param[in] gpio Target GPIO port.
 * @param[in] mask Target output IO/s mask to toggle.
 * 
 * @return None 
 * 
 * @note 1. To toggle multiple IOs you must specify an OR operator between IOs.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * * For single toggle:
 * @code
 * ...
 * // This toggle the GPIOA[0] output.
 * gpio_port_tgl(GPIOA, GPIO_IO0);
 * ...
 * @endcode
 * * For multiple toggle:
 * @code
 * ...
 * // This toggle the GPIOA[0,2] output.
 * gpio_port_tgl(GPIOA, GPIO_IO0 | GPIO_IO2);
 * ...
 * @endcode
 */
__FORCE_INLINE void gpio_port_tgl (GPIO_TypeDef *gpio, gpio_io_t mask)
{
    gpio->ODR ^= mask;
}


/** ### gpio:port:write:
 * @ingroup public_gpio
 * @brief Write RAW data to ouput register on target GPIO.
 * 
 * Write RAW data on target GPIO_ODR Register.
 * 
 * @param[in] gpio Target GPIO port.
 * @param[in] data Data to write.
 * 
 * @return None
 * 
 * @note It is a forced inline function.
 * 
 * E.g. @n
 * @code
 * ...
 * // This writes data '0xAF28' on output GPIOB register.
 * gpio_port_write(GPIOB, 0xAF28);
 * ...
 * @endcode
 */
__FORCE_INLINE void gpio_port_write (GPIO_TypeDef *gpio, uint16_t data)
{
    gpio->ODR = data;
}

/** ### gpio:port:read:input
 * @ingroup public_gpio
 * @brief Read the input status of target GPIO.
 * 
 * Read target GPIO_IDR register.
 * 
 * @param[in] gpio Target GPIO port.
 * 
 * @return [uint16_t] Data value at input port.
 * 
 * @note It is a forced inline function.
 * 
 * E.g. @n
 * @code
 * ...
 * // It returns a value at GPIOA input.
 * uint16_t data = gpio_port_read_input(GPIOA);
 * ...
 * @endcode
 */
__FORCE_INLINE uint16_t gpio_port_read_input (GPIO_TypeDef *gpio)
{
    return gpio->IDR;
}

/** ### gpio:port:read:input_masked
 * @ingroup public_gpio
 * @brief Read the input masked status of target GPIO.
 * 
 * Read masked GPIO_IDR target register.
 * 
 * @param[in] gpio Target GPIO port.
 * @param[in] mask GPIO mask to read.
 * 
 * @return [uint16_t] Masked value at input port.
 * 
 * @note 1. To read multiple IOs you must specify an OR operator between IOs.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * For single IO read:
 * @code
 * ...
 * // It returns a value at GPIOA[0] input.
 * uint16_t data = gpio_port_read_input_mask(GPIOA, GPIO_IO0);
 * ...
 * @endcode
 * For multiple IOs read:
 * @code
 * ...
 * // It returns a value at GPIOA[1:0] input.
 * uint16_t data = gpio_port_read_input_mask(GPIOA, GPIO_IO0 | GPIO_IO1);
 * ...
 * @endcode
 */
__FORCE_INLINE uint16_t gpio_port_read_input_mask (GPIO_TypeDef *gpio, gpio_io_t mask)
{
    return gpio_port_read_input (gpio) & mask;
}

/** ### gpio:port:read:output
 * @ingroup public_gpio
 * @brief Read the output status of target GPIO.
 * 
 * Read target GPIO_ODR register.
 * 
 * @param[in] gpio Target GPIO port.
 * 
 * @return [uint16_t] Data value at output port.
 * 
 * @note It is a forced inline function.
 * 
 * E.g. @n
 * @code
 * ...
 * // It returns a value at GPIOA output.
 * uint16_t data = gpio_port_read_output(GPIOA);
 * ...
 * @endcode
 */
__FORCE_INLINE uint16_t gpio_port_read_output (GPIO_TypeDef *gpio)
{
    return gpio->ODR;
}

/** ### gpio:port:read:output_masked
 * @ingroup public_gpio
 * @brief Read the output masked status of target GPIO.
 * 
 * Read masked GPIO_ODR target register.
 * 
 * @param[in] gpio Target GPIO port.
 * @param[in] mask GPIO mask to read.
 * 
 * @return [uint16_t] Masked value at output port.
 * 
 * @note 1. To read multiple IOs you must specify an OR operator between IOs.
 * @note 2. It is a forced inline function.
 * 
 * E.g. @n
 * For single IO read:
 * @code
 * ...
 * // It returns a value at GPIOA[0] output.
 * uint16_t data = gpio_port_read_output_mask(GPIOA, GPIO_IO0);
 * ...
 * @endcode
 * For multiple IOs read:
 * @code
 * ...
 * // It returns a value at GPIOA[1:0] output.
 * uint16_t data = gpio_port_read_output_mask(GPIOA, GPIO_IO0 | GPIO_IO1);
 * ...
 * @endcode
 */
__FORCE_INLINE uint16_t gpio_port_read_output_mask (GPIO_TypeDef *gpio, gpio_io_t mask)
{
    return gpio_port_read_output(gpio) & mask;
}

/** ### gpio:configure:alternate_function
 * @ingroup gpio_public
 * @brief Switch the alternate IO/s function on target GPIO.
 * 
 * Configure the alternate function register GPIO_AFR of masked IO/s on target
 * GPIO.
 * 
 * @param gpio Target GPIO port.
 * @param af Alternate function to switch.
 * @param mask GPIO Mask to configure.
 * 
 * @return None
 * 
 * @note To alternate multiple IOs you must specify an OR operator between IOs.
 * 
 * E.g @n
 * For Single IO:
 * @code
 * ...
 * // This switch the alternate function of GPIOA[0] to AF2
 * gpio_config_af(GPIOA, GPIO_ALT_AF0, GPIO_IO0);
 * ...
 * @endcode
 * For Multiple IO:
 * @code
 * ...
 * // This switch the alternate function of GPIOA[15,0] to AF2
 * gpio_config_af(GPIOA, GPIO_ALT_AF0, GPIO_IO15 | GPIO_IO0);
 * ...
 * @endcode
 */
void gpio_config_af(GPIO_TypeDef *gpio, gpio_alt_t af, gpio_io_t mask);

#ifdef __cplusplus
}
#endif

#endif /* _GPIO_H_ */
