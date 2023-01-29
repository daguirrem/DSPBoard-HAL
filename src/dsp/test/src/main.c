/**
 * @file main.c
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief Test for DSP Library
 * @version d0.1
 * @date 2023-01-27
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
#include "dsp.h"

float a[10] = 
{
    9,8,7,5,4,3,2,1,0
};

__CCM_VAR_I float b[10] = 
{
    0,1,2,3,4,5,6,7,8,9
};

int main (void)
{
    /* FIR TEST ------------------------------------------------------------- */
    /* Static testing */
    /* Normal */
    /* This should create a variable named 'fir_static' with order 10 ------| */
    dsp_filter_fir_declarate(fir_static, 10);                          /* <-| */ /*[ok]*/
    
    /* This should assign B coiefficients to Filter B Coefficient at LowPass| */
    fir_static.b.low = &b[0];                                          /* <-| */ /*[ok]*/

    /* CCM */
    /* This should create a variable named 'fir_ccm' with order 10 ---------| */
    /* at .ccmdata memory section                                           | */
    dsp_filter_fir_declarate(fir_ccm, 10, __CCM_VAR_I);                /* <-| */ /*[ok]*/

    /* This should assign B coiefficients to Filter B Coefficient at LowPass| */
    fir_ccm.b.low = &b[0];                                             /* <-| */ /*[ok]*/

    /* Dynamic allocation testing */
    fir_t *fir_dynamic = dsp_filter_fir_init(10);
    dsp_filter_fir_coeff_init(fir_dynamic, FILTER_TYPE_LOWPASS, (float *) &b);

    /* IIR TEST ------------------------------------------------------------- */
    /* Static testing */
    /* Normal */
    /* This should create a variable named 'fir_static' with order 10 ------| */
    dsp_filter_iir_declarate(iir_static, 10);                          /* <-| */ /*[ok]*/
    
    /* This should assign A coiefficients to Filter A Coefficient at LowPass| */
    iir_static.a.low = &a[0];                                          /* <-| */ /*[ok]*/
    /* This should assign B coiefficients to Filter B Coefficient at LowPass| */
    iir_static.b.low = &b[0];                                          /* <-| */ /*[ok]*/

    /* CCM */
    /* This should create a variable named 'fir_ccm' with order 10 ---------| */
    /* at .ccmdata memory section                                           | */
    dsp_filter_iir_declarate(iir_ccm, 10, __CCM_VAR_I);                /* <-| */ /*[ok]*/

    /* This should assign A coiefficients to Filter A Coefficient at LowPass| */
    iir_ccm.a.low = &a[0];                                             /* <-| */ /*[ok]*/
    /* This should assign B coiefficients to Filter B Coefficient at LowPass| */
    iir_ccm.b.low = &b[0];                                             /* <-| */ /*[ok]*/

    iir_t *iir_dynamic = dsp_filter_iir_init(10);
    dsp_filter_iir_coeff_init(iir_dynamic, FILTER_TYPE_LOWPASS, &a[0], &b[0]);

    dsp_filter_fir(&fir_static, FILTER_TYPE_LOWPASS, 1);
    dsp_filter_fir(&fir_ccm, FILTER_TYPE_LOWPASS, 1);
    dsp_filter_fir(fir_dynamic, FILTER_TYPE_LOWPASS, 1);

    dsp_filter_iir(&iir_static, FILTER_TYPE_LOWPASS, 1);
    dsp_filter_iir(&iir_ccm, FILTER_TYPE_LOWPASS, 1);
    dsp_filter_iir(iir_dynamic, FILTER_TYPE_LOWPASS, 1);

    dsp_filter_fir_deinit(fir_dynamic);
    dsp_filter_iir_deinit(iir_dynamic);
    
    while(1)
    {
    }
}
