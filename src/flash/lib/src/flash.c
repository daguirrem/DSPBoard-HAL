/**
 * @file flash.c
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

#include "flash.h"

void flash_acr_config_auto(uint32_t clk)
{
    if (clk <= 30000000) {
        flash_acr_config_set(
            FLASH_CONFIG_DCACHE | FLASH_CONFIG_ICACHE |
            FLASH_CONFIG_PREFETCH | FLASH_CONFIG_LATENCY_0WS
        );
    } 
    else if (clk <= 60000000) {
        flash_acr_config_set(
            FLASH_CONFIG_DCACHE | FLASH_CONFIG_ICACHE |
            FLASH_CONFIG_PREFETCH | FLASH_CONFIG_LATENCY_1WS
        );
    }
    else if (clk <= 90000000) {
        flash_acr_config_set(
            FLASH_CONFIG_DCACHE | FLASH_CONFIG_ICACHE |
            FLASH_CONFIG_PREFETCH | FLASH_CONFIG_LATENCY_2WS
        );
    }
    else if (clk <= 120000000) {
        flash_acr_config_set(
            FLASH_CONFIG_DCACHE | FLASH_CONFIG_ICACHE |
            FLASH_CONFIG_PREFETCH | FLASH_CONFIG_LATENCY_3WS
        );
    }
    else if (clk <= 150000000) {
        flash_acr_config_set(
            FLASH_CONFIG_DCACHE | FLASH_CONFIG_ICACHE |
            FLASH_CONFIG_PREFETCH | FLASH_CONFIG_LATENCY_4WS
        );
    }
    else  {
        flash_acr_config_set(
            FLASH_CONFIG_DCACHE | FLASH_CONFIG_ICACHE |
            FLASH_CONFIG_PREFETCH | FLASH_CONFIG_LATENCY_5WS
        );
    }
}
