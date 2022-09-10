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

adc_seqr_rgl_t adc_rgl; // ADC Regular Structure for Tests

int main (void)
{
    /* Enable GPIO on Analog mode ------------------------------------------|*/
    gpio_clk_en(GPIOA_RCC);                                               /*|*/
    gpio_config_mode(GPIOA, GPIO_MODE_ANALOG, GPIO_IO0);                /*<-|*/ /*[ok]*/

    /* ADC clock 1, 2, 3 should be enabled ---------------------------------|*/
    adc_clk_en(ADC1_RCC | ADC2_RCC | ADC3_RCC);                         /*<-|*/ /*[ok]*/
    
    /* ADC clock 2 & 3 should be disabled ----------------------------------|*/
    adc_clk_dis(ADC2_RCC | ADC3_RCC);                                   /*<-|*/ /*[ok]*/
    
    /* ADC prescaler should be 8 -------------------------------------------|*/
    adc_common_config_pre(ADC_PRE_8);                                   /*<-|*/ /*[ok]*/

    /* ADC configure individual mode ---------------------------------------|*/
    adc_ind_config(ADC1, ADC_RES_12BITS, ADC_ALIGN_RIGHT);              /*<-|*/ /*[ok]*/

    /* ADC individual configure sequencer for single channel ---------------|*/
    adc_ind_config_seq_sgl(ADC1, 0);                                    /*<-|*/ /*[ok]*/

    /* ADC power on --------------------------------------------------------|*/
    adc_power_on(ADC1);                                                 /*<-|*/ /*[ok]*/

    /* Read single preconfigured channel on sequencer 0 --------------------|*/
    volatile uint32_t adc_read = adc_ind_read_sgl(ADC1);                /*<-|*/ /*[ok]*/
    
    /* Enable internal VREF channel ----------------------------------------|*/
    adc_ich_en(ADC_INCH_TVREF);                                         /*<-|*/ /*[ok]*/
    
    /* Configure a sequencer to read 3 channels ----------------------------|*/
    adc_rgl.lenght = 3;                             /* Channels to read ----|*/
    adc_rgl.sequece[0] = 0;                         /* Channel 0 [GPIOA0] --|*/
    adc_rgl.sequece[1] = 17;                        /* Voltaje reference ---|*/
    adc_rgl.sequece[2] = 16;                        /* Voltaje temperature -|*/
    adc_config_seq_rgl(ADC1, &adc_rgl);                                  /*-|*/
    adc_ind_config_mode_scan(ADC1);                                     /*<-|*/ /*[ok]*/

    while(1)
    {
        /* Excecute a read sequencered channels ----------------------------|*/
        adc_ind_read_scan_rgl(ADC1, &adc_rgl);                          /*<-|*/ /*[ok]*/
        /* Compute a readed channels to voltages values --------------------|*/
        adc_seq_get_voltages_rgl(&adc_rgl, ADC_RES_12BITS);             /*<-|*/ /*[ok]*/
        
        delay_ms(100);
    }
}
