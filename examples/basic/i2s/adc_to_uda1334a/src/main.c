/**
 * @file main.c
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief 
 * @version d0.1
 * @date 2023-04-09
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

#include "adc.h"
#include "rcc.h"
#include "i2s.h"
#include "gpio.h"

uint32_t adc_in = 0;

void i2s_handler(uint32_t *dr, uint8_t ch)
{
    if(ch == 0)
    {
        *dr = adc_in;
    }
    else
    {
        *dr = adc_in;

        float tmp = 0;
        /* Get ADC sample */
        for (uint8_t i = 0; i < 4; i++)
        {
            tmp += (float) adc_ind_read_sgl(ADC1);
        }
        tmp *= 16777215.0f / 4095.0f; /* 12 to 24 bits */
        adc_in = ((uint32_t) (tmp / 4.0f));
    }
}

int main (void)
{
    rcc_pll_param_cpte_set(80, RCC_PLLCLK_HSE);
    rcc_sysclk_select(RCC_SYSCLK_PLL | RCC_SYSCLK_HSE);

    gpio_clk_en(GPIOA_RCC |GPIOH_RCC | GPIOI_RCC);
    gpio_config_mode(GPIOH, GPIO_MODE_OUTPUT, GPIO_IO11);

    i2s_clk_en(I2S2_RCC);

    i2s_t i2s =
    {
        .i2s_p = I2S2, .gpio_i2s = GPIOI,
        .ws_pin = GPIO_IO0, .ck_pin = GPIO_IO1, .sd_pin = GPIO_IO3,
        
        .mode = I2S_MODE_MASTER_TRASMIT,
        .protocol = I2S_STANDAR_I2S_PHILIPS,
        .data_length = I2S_DATA_LEN_24bits,
        .channel_length = I2S_CH_LEN_32bits,
        .fs = I2S_FREQ_22050Hz,
        .pll_clk_src = RCC_PLLCLK_HSE,

        .tx_handler = i2s_handler
    };

    i2s_master_init(&i2s);

    /* Clock ADC */
    adc_clk_en(ADC1_RCC);
    /* Configuración GPIO Anáogo */
    gpio_config_mode(
          GPIOA, GPIO_MODE_ANALOG,
          GPIO_IO7    /*ADC R*/
    );
    /* Prescaler en 8 */
    adc_common_config_pre(ADC_PRE_4);
    
    /* Alineación hacia la derecha y configuración a 12 bits */
    adc_ind_config(ADC1, ADC_RES_12BITS, ADC_ALIGN_RIGHT);

    /* Configuración de lectura de únicamente el canal 7 */
    adc_ind_config_seq_sgl(ADC1, 7);
    adc_power_on(ADC1);

    i2s_irq_setup(&i2s);
    __enable_irq();

    while(1)
    {
    }
}
