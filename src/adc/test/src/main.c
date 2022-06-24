/**
 * @file main.c
 * @author David A. Aguirre M. (daguirre.m@outlook.com)
 * @brief 
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

#include "system.h"
#include "adc.h"
#include "gpio.h"
#include "delay.h"

int main (void)
{
    gpio_clk_en(GPIOA_RCC);
    gpio_config_mode(GPIOA, GPIO_MODE_ANALOG, GPIO_IO0);

    /* ADC clock 1, 2, 3 should be enabled ---------------------------------|*/
    adc_clk_en(ADC1_RCC | ADC2_RCC | ADC3_RCC);                         /*<-|*/ /*[]*/
    
    /* ADC clock 2 & 3 should be disabled ----------------------------------|*/
    adc_clk_dis(ADC2_RCC | ADC3_RCC);                                   /*<-|*/ /*[]*/
    adc_sequencer_rgl.sequece[0] = 0;
    adc_sequencer_rgl.sequece[1] = 17;
    adc_sequencer_rgl.sequece[2] = 16;
    adc_sequencer_rgl.lenght = 3;
    adc_config_seq_rgl(ADC1);

    adc_config_ind_scan(
        ADC1, ADC_RES_12BITS, ADC_ALIGN_RIGHT, ADC_PRE_8
    );
    
    adc_internalch_en(ADC_INCH_TVREF);
    adc_power_on(ADC1);

    while(1) {
        adc_read_ind_scan(ADC1);
        adc_seq_get_voltages(ADC_RES_12BITS);
        delay_ms(100);
    }
}
