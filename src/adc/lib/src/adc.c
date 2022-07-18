/**
 * @file adc.c
 * @author David A. Aguirre M. (daguirre.m@outlook.com)
 * @brief ADC - Custom HAL for DSP Board SDK.
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

#include <stdlib.h>

#include "adc.h"


/** 
 * @addtogroup private_adc Private
 * @ingroup adc
 */

// adc_seqr_rgl_t adc_sequencer_rgl;
// adc_seqr_ijt_t adc_sequencer_ijt;

const uint16_t resbits_decode[] = {
    4095, /* 12 Bits */
    1023, /* 10 Bits */
    255,  /*  8 Bits */
    63    /*  6 Bits */
};

void adc_ind_config(
    ADC_TypeDef *adc, adc_res_t resolution, adc_align_t alignment
)
{
    ADC->CCR &= ~ADC_CCR_MULTI;
    adc->CR1 = 0;
    adc->CR1 |= (resolution << ADC_CR1_RES_Pos); // | ADC_CR1_SCAN;

    adc->CR2 = 0;
    adc->CR2 |= (alignment << ADC_CR2_ALIGN_Pos) | ADC_CR2_EOCS;
}

int8_t adc_config_seq_rgl(ADC_TypeDef *adc, adc_seqr_rgl_t *sequencer)
{
    if (sequencer->lenght > 16) return -1; // Sequencer lenght not allowed

    adc->SQR1 = 0;
    adc->SQR2 = 0;
    adc->SQR3 = 0;
    adc->SQR1 |= ((sequencer->lenght - 1) << ADC_SQR1_L_Pos);
    
    for (uint8_t i = 0; i < sequencer->lenght; i++)
    {
        if (i <= 6)
        {
            adc->SQR3 |= sequencer->sequece[i] << (i*5);
        }
        else if (i <= 12)
        {
            adc->SQR2 |= sequencer->sequece[i] << (i*5);
        }
        else
        {
            adc->SQR1 |= sequencer->sequece[i] << (i*5);
        }
    }

    adc->SR = 0;
    return 0;
}

int8_t adc_config_seq_ijt(ADC_TypeDef *adc, adc_seqr_ijt_t *sequencer)
{
    if(sequencer->lenght > 4) return -1; // Sequencer lenght not allowed

    adc->JSQR = 0;
    adc->JSQR |= ((sequencer->lenght - 1) << ADC_JSQR_JL_Pos);

    for (uint8_t i = 0; i < sequencer->lenght; i++)
    {
        adc->JSQR |= sequencer->sequece[i] << (i*5);
    }

    adc->SR = 0;
    return 0;
}

void adc_ind_read_scan_rgl(ADC_TypeDef *adc, adc_seqr_rgl_t *sequencer)
{
    adc_sw_start(adc);
    for(uint8_t i = 0; i < sequencer->lenght; i++)
    {
        while((adc->SR & ADC_SR_EOC) == 0);
        sequencer->raw[i] = adc->DR;
    }
    adc->SR &= ~ADC_SR_STRT;
}

void adc_ind_read_scan_ijt(ADC_TypeDef *adc, adc_seqr_ijt_t *sequencer)
{
    adc_sw_start(adc);
    for(uint8_t i = 0; i < sequencer->lenght; i++)
    {
        while((adc->SR & ADC_SR_EOC) == 0);
        sequencer->raw[i] = adc->DR;
    }
    adc->SR &= ~ADC_SR_STRT;
}
