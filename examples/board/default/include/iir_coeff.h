/**
 * @file iir_coeff.h
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief Coeficientes generados por coeff_generator.m
 * @version r1.0
 * @date 
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

#ifndef _IIR_COEFF_H_
#define _IIR_COEFF_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "system.h"

/* Orden del filtro */
#define IIR_ORDER 4

/*----------------------------------------------------------------------------*/
/* Variables */
/*----------------------------------------------------------------------------*/

/* 500 - 1000 */
__CCM_VAR_I float b_band_pass[] = {
    +1.20741e-03,     +0.00000e+00,     -2.41481e-03,     +0.00000e+00,     +1.20741e-03
};

__CCM_VAR_I float a_band_pass[] = {
    +1.00000e+00,     -3.87955e+00,     +5.66434e+00,     -3.68885e+00,     +9.04163e-01   
};

/* 200 1000 */
__CCM_VAR_I float b_band_stop[] = {
    +9.22561e-01,     -3.68275e+00,     +5.52039e+00,     -3.68275e+00,     +9.22561e-01
};

__CCM_VAR_I float a_band_stop[] = {
    +1.00000e+00,     -3.83132e+00,     +5.51438e+00,     -3.53418e+00,     +8.51128e-01
};

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _IIR_COEFF_H_ */