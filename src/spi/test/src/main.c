/**
 * @file main.c
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief SPI Tester.
 * @version d0.1
 * @date 2023-03-11
 * 
 * @copyright MIT License, Copyright (c) 2023 David A. Aguirre M. @n @n
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
#include "spi.h"
#include "gpio.h"

int main (void)
{
    rcc_sysclk_select(RCC_SYSCLK_HSE);

    gpio_clk_en(GPIOH_RCC);
    gpio_config_mode(GPIOH, GPIO_MODE_OUTPUT, GPIO_IO11);

    /* SPI configuration */
    spi_clk_en(SPI2_RCC);
    gpio_clk_en(GPIOB_RCC | GPIOC_RCC);
    
    spi_t spi =
    {
        .spi_p = SPI2,
        .gpio_spi = GPIOB, .gpio_ss = GPIOC,
        .sck_pin = GPIO_IO15, .miso_pin = GPIO_IO14, .mosi_pin = GPIO_IO13, 
        .ss_pin = {GPIO_IO9}, .ss_size = 1,
        .software_ss = true,
        .clk_pol = SPI_CLK_POL_HIGH,
        .clk_prescaler = SPI_PRESCALER_256,
        .data_format = SPI_DF_8BITS,
        .transfer_format = SPI_TF_MSB,
        .clk_pha = SPI_CLK_PHA_FIRST
    };
    spi_master_init(&spi);

    while(1)
    {
        spi_master_write_and_read(&spi, 0xA5, 0);

        gpio_port_tgl(GPIOH, GPIO_IO11);
        delay_ms(1000);
    }
}

