/**
 * @file gpio.c
 * @author David A. Aguirre M. (daguirre.m@outlook.com)
 * @brief GPIO - Custom HAL for DSP Board SDK.
 * @version d0.1
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

#include "gpio.h"

/*
 * Update each configuration register of masked IOs of GPIO in accordance of 
 * custom configuration mask.
 */
void gpio_config_all (GPIO_TypeDef *gpio, gpio_config_t config, gpio_io_t mask)
{
    /* Discriminate the CCCC bits of config mask [\config]*/
    uint8_t configurator_enable = (config & 0xF00) >> 8;
    /* MODER CONFIG = CCC1 */
    if (configurator_enable & 0x1) {
        /* Discriminate the MM bits of config mask */
        uint8_t gpio_mode = (config & 0x3);
        uint32_t _mask = (uint32_t) mask;
        /* Enable desired gpio mode to each IO Modder configurator if IO is
           masked */
        for (uint8_t bit = 0; bit < 32; bit += 2) {
            if (_mask & 0x1) {
                gpio->MODER &= ~(0x3 << bit);
                gpio->MODER |= (gpio_mode << bit);
            }
            _mask >>= 1;
        }
    }
    /* OUTPUT MODE CONFIG = CC1C */
    if (configurator_enable & 0x2) {
        /* Pass through the O bits mask to Output Mode Register configurator */
        uint16_t output_mode = (config & 0x4) >> 2;
        gpio->OTYPER &= ~mask;
        gpio->OTYPER |= output_mode ? mask : 0;
    }
    /* PULL MODE CONFIG = C1CC */
    if (configurator_enable & 0x4) {
        /* Discriminate the PP bits of config mask */
        uint8_t pull_mode = (config & 0x18) >> 3;
        uint32_t _mask = (uint32_t) mask;
        /* Enable desired pull input mode to each IO Pull configurator if IO 
           is masked */
        for (uint8_t bit = 0; bit < 32; bit += 2) {
            if (_mask & 0x1) {
                gpio->PUPDR &= ~(0x3 << bit);
                gpio->PUPDR |= pull_mode << bit;
            }
            _mask >>= 1;
        }
    }
    /* SPEED CONFIG = 1CCC */
    if (configurator_enable & 0x8) {
        /* Discriminate the SS bits of mask */
        uint8_t speed = (config & 0x60) >> 5;
        uint32_t _mask = (uint32_t) mask;
        /* Enable desired speed mode to each IO Speed configurator if IO 
           is masked */
        for (uint8_t bit = 0; bit < 32; bit += 2) {
            if (_mask & 0x1) {
                gpio->OSPEEDR &= ~(0x3 << bit);
                gpio->OSPEEDR |= speed << bit;
            }
            _mask >>= 1;
        }
    }
}

/* Individual Modder configurator */
void gpio_config_mode (GPIO_TypeDef *gpio, gpio_mode_t mode, gpio_io_t mask)
{
    /* Enable desired gpio mode [\mode] to each IO moder configurator
       masked [\mask] of GPIO [\gpio] */
    for (uint8_t bit = 0; bit < 32; bit += 2) {
        if (mask & 0x1) {
            gpio->MODER &= ~(0x3 << bit);
            gpio->MODER |= mode << bit;
        }
        mask >>= 1;
    }
}

/* Individual Modder configurator */
void gpio_config_speed (GPIO_TypeDef *gpio, gpio_speed_t speed, gpio_io_t mask)
{
    /* Enable desired gpio speed [\speed] to each masked [\mask] IO moder 
       configurator on target GPIO_OSPEEDR register [\gpio] */
    for (uint8_t bit = 0; bit < 32; bit += 2) {
        if (mask & 0x1) {
            gpio->OSPEEDR &= ~(0x3 << bit);
            gpio->OSPEEDR |= speed << bit;
        }
        mask >>= 1;
    }
}

/* Individual Pull input mode configurator */
void gpio_config_input_pull_mode (
    GPIO_TypeDef *gpio, gpio_pull_t pull_mode, gpio_io_t mask
)
{
    /* Enable desired pull input mode [\pullmode] to each masked [\mask] IO pull 
       configurator on target GPIO_PUPDR register [\gpio] */
    for (uint8_t bit = 0; bit < 32; bit += 2) {
        if (mask & 0x1) {
            gpio->PUPDR &= ~(0x3 << bit);
            gpio->PUPDR |= pull_mode << bit;
        }
        mask >>= 1;
    }
}

/* Override the optimization level */
__attribute__((optimize("-O0")))
uint8_t gpio_config_lock(GPIO_TypeDef *gpio, gpio_io_t mask)
{
    /* Execute lock sequence ref. "GPIO port configuration lock register"
     * pag. 285 - Reference Manual
     */
    uint32_t tmp;
    gpio->LCKR = 0x10000 | mask;
    gpio->LCKR = 0x00000 | mask;
    gpio->LCKR = 0x10000 | mask;
    tmp = gpio->LCKR;
    tmp++;
    return !((gpio->LCKR) >> 16);
}

void gpio_config_af(GPIO_TypeDef *gpio, gpio_alt_t af, gpio_io_t mask)
{
    /* Enable desired alternate function mode [\af] to each masked[\mask] IO af 
       configurator on target GPIO correspondig AFR register [\gpio] */
    for (uint8_t bit = 0; bit < 64; bit += 4) {
        if (mask & 0x1) {
            if (bit < 32) {
                /* For first 8 IO/s |> AFRL */
                gpio->AFR[0] &= ~(0xF << bit);
                gpio->AFR[0] |= af << bit;
            }
            else {
                /* For last 8 IO/s |> AFRH */
                uint8_t tmp = bit - 32;
                gpio->AFR[1] &= ~(0xF << tmp);
                gpio->AFR[1] |= af << tmp;
            }
        }
        mask >>= 1;
    }
}