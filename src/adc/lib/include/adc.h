/**
 * @file adc.h
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
#ifndef _ADC_H_
#define _ADC_H_

/**
 * @addtogroup adc ADC
 * 
 */

/** 
 * @addtogroup public_adc Public
 * @ingroup adc
 * 
 */

#include "system.h"
#include "rcc.h"

#define ADC_VREF_P 3300
#define ADC_VREF_N 0
#define ADC_VREF ADC_VREF_P - ADC_VREF_N

/*----------------------------------------------------------------------------*/
/* Enums */
/*----------------------------------------------------------------------------*/

typedef enum {
    ADC1_RCC = RCC_APB2_ADC1, //!< ADC0 RCC mask
    ADC2_RCC = RCC_APB2_ADC2, //!< ADC1 RCC mask
    ADC3_RCC = RCC_APB2_ADC3  //!< ADC2 RCC mask
} adc_rcc_t;

typedef enum {
    ADC_RES_12BITS = 0,
    ADC_RES_10BITS = 1,
    ADC_RES_8BITS  = 2,
    ADC_RES_6BITS  = 3
} adc_res_t;

typedef enum {
    ADC_ALIGN_RIGHT = 0,
    ADC_ALIGN_LEFT = 1
} adc_align_t;

typedef enum {
    ADC_PRE_2 = 0,
    ADC_PRE_4 = 1,
    ADC_PRE_6 = 2,
    ADC_PRE_8 = 3
} adc_pre_t;

typedef enum {
    ADC_INCH_VBAT = ADC_CCR_VBATE,
    ADC_INCH_TVREF = ADC_CCR_TSVREFE
} adc_ich_t;

/*----------------------------------------------------------------------------*/
/* Structs */
/*----------------------------------------------------------------------------*/

typedef struct {
    uint8_t lenght;
    uint8_t sequece[16];
    uint16_t raw[16];
    uint32_t voltage[16];
} adc_seqr_rgl_t;

typedef struct {
    uint8_t lenght;
    uint8_t sequece[4];
    uint16_t raw[4];
    uint32_t voltage[4];
} adc_seqr_ijt_t;

extern adc_seqr_rgl_t adc_sequencer_rgl;
extern adc_seqr_ijt_t adc_sequencer_ijt;
extern const uint16_t resbits_decode[];

/*----------------------------------------------------------------------------*/
/* Functions */
/*----------------------------------------------------------------------------*/

__FORCE_INLINE void adc_rst(adc_rcc_t mask)
{
    rcc_clk_en_apb2((rcc_apb2_t) mask);
}

__FORCE_INLINE void adc_clk_en(adc_rcc_t mask)
{
    rcc_clk_en_apb2((rcc_apb2_t) mask);
}

__FORCE_INLINE void adc_clk_dis(adc_rcc_t mask)
{
    rcc_clk_dis_apb2((rcc_apb2_t) mask);
}

__FORCE_INLINE void adc_power_on(ADC_TypeDef *adc)
{
    adc->CR2 |= ADC_CR2_ADON;
}

__FORCE_INLINE void adc_power_down(ADC_TypeDef *adc)
{
    adc->CR2 &= ~ADC_CR2_ADON;
}

__FORCE_INLINE void adc_config_seq_sgl_ch(ADC_TypeDef *adc, uint8_t channel)
{
    adc->SQR1 &= ~(0x0F << ADC_SQR1_L_Pos); /* Clear lenght */
    adc->SQR3 &= ~(0x1F);    /* Clear first sequence */
    adc->SQR3 |= channel;   /* Assign desired channel to read */
}

__FORCE_INLINE uint16_t adc_read_ind_sgl(ADC_TypeDef *adc)
{
    adc->CR2 |= ADC_CR2_SWSTART;
    while((adc->SR & ADC_SR_EOC) == 0);
    uint16_t raw = adc->DR;
    adc->SR &= ~ADC_SR_STRT;
    return raw;
}

__FORCE_INLINE uint32_t adc_get_voltage(uint16_t raw, adc_res_t resolution)
{
    return (raw * ADC_VREF) / resbits_decode[resolution];
}

void adc_config_ind_scan(
    ADC_TypeDef *adc, adc_res_t resolution, adc_align_t alignment, 
    adc_pre_t prescaler
);

void adc_config_seq_rgl(ADC_TypeDef *adc);

void adc_read_ind_scan(ADC_TypeDef *adc);

__FORCE_INLINE void adc_internalch_en(adc_ich_t mask)
{
    ADC->CCR |= mask;
}

__FORCE_INLINE void adc_internalch_dis(adc_ich_t mask)
{
    ADC->CCR &= ~mask;
}

__FORCE_INLINE void adc_seq_get_voltages(adc_res_t resolution)
{
    for (uint8_t i = 0; i < adc_sequencer_rgl.lenght; i++)
        adc_sequencer_rgl.voltage[i] = 
            adc_get_voltage(adc_sequencer_rgl.raw[i], ADC_RES_12BITS);
}

#endif /* _ADC_H_ */
