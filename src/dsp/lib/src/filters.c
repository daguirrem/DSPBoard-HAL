/**
 * @file filters.c
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief 
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

#include <stdlib.h>
#include <string.h>

#include "dsp.h"

#ifndef FIR_OPTIMICED
#warning FIR_OPTIMICED \
         is not defined by default, the funtion 'dsp_filter_fir' \
         will compile with optimization enabled.
#define FIR_OPTIMICED 1
#endif

/**
 * @addtogroup dsp
 */

/**
 * @defgroup dsp_private Private
 * @ingroup dsp
 */

/*----------------------------------------------------------------------------*/
/* FIR */
/*----------------------------------------------------------------------------*/

fir_t *dsp_filter_fir_init(const uint16_t order)
{
    fir_t *filter;
    filter = (fir_t *) calloc(1, sizeof(fir_t));

    /* If filter is not allocated, return */
    if(filter == NULL)
        return NULL;
    
    filter->x = (float *) calloc(order + 1, sizeof(float));

    /* If X array is not allocated, Deallocate filter variable & return */
    if(filter->x == NULL)
    {
        free((void *) filter);
        return NULL;
    }

    /* Save order on filter variable */
    filter->order = order;

    return filter; 
}

void dsp_filter_fir_deinit(fir_t *filter)
{
    /* Deallocate every B array coefficients */
    if (filter->b.low != NULL)
    {
        free((void*) filter->b.low);
        filter->b.low = NULL;
    }
    if (filter->b.high != NULL)
    {
        free((void*) filter->b.high);
        filter->b.high = NULL;
    }
    if (filter->b.pass != NULL)
    {
        free((void*) filter->b.pass);
        filter->b.pass = NULL;
    }
    if (filter->b.stop != NULL)
    {
        free((void*) filter->b.stop);
        filter->b.stop = NULL;
    }
    /* Deallocate X array */
    free((void*) filter->x);
    filter->x = NULL;

    /* Deallocate filter variable */
    free((void*) filter);
    filter = NULL;
}

int8_t dsp_filter_fir_coeff_init(
    fir_t *filter, filter_type_t type, const float *b
)
{
    float **to_allocate;

    /* Get B coefficient address to be allocated */
    switch (type)
    {
        case FILTER_TYPE_LOWPASS:
            to_allocate = (float **) &filter->b.low;
            break;
        case FILTER_TYPE_HIGHPASS:
            to_allocate = (float **) &filter->b.high;
            break;
        case FILTER_TYPE_BANDPASS:
            to_allocate = (float **) &filter->b.pass;
            break;
        case FILTER_TYPE_BANDSTOP:
            to_allocate = (float **) &filter->b.stop;
            break;
        default:
            return -1; /* Misstaken filter type */
            break;
    }

    *to_allocate = (float *) calloc(filter->order + 1, sizeof(float));

    /* Test if array was allocated */
    if(*to_allocate == NULL)
        return -1; /* B coefficient array not allocated */

    /* Copy B to target filter->B */
    for(uint16_t i = 0; i < filter->order; i++)
        (*to_allocate)[i] = b[i];

    /* Everithing succesfull */
    return 0;
}

float dsp_filter_fir(fir_t *filter, filter_type_t type, float x_in)
{
    /* Function optimization */
    #if defined(FIR_OPTIMICED) && (FIR_OPTIMICED==1)

    /* Optimiced version use a do-while for x array shift & convolution 
     * (y = b*x).
     * This version is apriximated 10us @168MHz faster than no optimiced version.
     */

    /* La versión optimizada hace un do-while para el corrimiento del arreglo
     * de entrada (x) y la convolución (y=b*x).
     * Esta versión es aproximadamente 10us más rápida que la versión no optimizada.
     */

    uint16_t s = filter->order; /* Array size */
    float *x = filter->x; /* Initial address of x array (x[0]) */
    float *_x = x + s; /* Final address of x array (x[s])*/
    const float *b; /* Initial B coefficients array address (b[0]) */
    const float *_b; /* Final address of B coefficientes array address (b[s]) */

    switch (type)
    {
    case FILTER_TYPE_LOWPASS:
        b = (filter->b.low);
        break;
    case FILTER_TYPE_HIGHPASS:
        b = (filter->b.high);
        break;
    case FILTER_TYPE_BANDPASS:
        b = (filter->b.pass);
        break;
    case FILTER_TYPE_BANDSTOP:
    default:
        b = (filter->b.stop);
        break;
    }

    _b = b + s;

    /* FIR: */
    float y = 0;
    
    do {
        /* x array shift */
        /* Where:
         *  x[1] = x[0], x[2] = x[1],...x[FIR_ORDER-1] = x[FIR_ORDER-2]
         */
        *_x = *(_x - 1);

        /* Convolution */
        /* Where: 
         *  x[0] = x[n]; x[1] = x[n-1] ...
         *  y[n] = b[0]*x[n] + b[1]*x[n-1] + ... b[FIR_ORDER-1] * x[n - (FIR_ORDER-1)]
         */
        y += *(_x) * *(_b);
        _x -=1; _b -= 1;
    } while(--s);

    /* x[0] = Input (Last entry) */
    filter->x[0] = x_in;
    y += b[0] * x[0];

    #else /* Not optimiced version */

    /* The no optimiced version use 2 independient for to shift and convolution.
     * This version is aproximated 10us @168MHz slower than optimiced version.
     */

    /* La versión no optimizada hace uso de 2 "fors" independientes para el 
     * corrimiento y la convolución del filtro.
     * Esta versión es aproximadamente 10us más lenta que la versión optimizada.
     */

    for (size_t k = filter->order; k > 0; k--)
    {
        /* x array shift */
        /* Where:
         *  x[1] = x[0], x[2] = x[1],...x[FIR_ORDER-1] = x[FIR_ORDER-2]
         */
        filter->x[k] = filter->x[k-1];
    }
    /* x[0] = Input (Last entry) */
    filter->x[0] = x_in;

    /* Get a filter type to execute */
    float *b;
    switch (type)
    {
    case FILTER_TYPE_LOWPASS:
        b = (filter->b.low);
        break;
    case FILTER_TYPE_HIGHPASS:
        b = (filter->b.high);
        break;
    case FILTER_TYPE_BANDPASS:
        b = (filter->b.pass);
        break;
    case FILTER_TYPE_BANDSTOP:
    default:
        b = (filter->b.stop);
        break;
    }

    /* FIR */
    /* Where: 
    *  x[0] = x[n]; x[1] = x[n-1] ...
    *  y[n] = b[0]*x[n] + b[1]*x[n-1] + ... b[FIR_ORDER-1] * x[n - (FIR_ORDER-1)]
    */
    float y = 0; /* Acumulator */
    
    for (size_t k = 0; k <= filter->order; k++)
    {
        /* Where x[0] = x[n]; x[1] = x[n-1] ... */
        y += b[k] * filter->x[k];
    }

#endif /* !defined(FIR_OPTIMICED) || (FIR_OPTMICED==0)*/

    /* Save y output on filter variable & return it */
    filter->y = y;
    return y;
}

/*----------------------------------------------------------------------------*/
/* IIR */
/*----------------------------------------------------------------------------*/

iir_t *dsp_filter_iir_init(const uint16_t order)
{
    iir_t *filter;
    filter = (iir_t *) calloc(1, sizeof(iir_t));

    /* If filter is not allocated, return */
    if(filter == NULL)
        return NULL;
    
    filter->x = (float *) calloc(order + 1, sizeof(float));

    /* If X array is not allocated, Deallocate filter variable & return */
    if(filter->x == NULL)
    {
        free((void *) filter);
        return NULL;
    }

    filter->y = (float *) calloc(order + 1, sizeof(float));

    /* If Y array is not allocated, Deallocate filter variable & return */
    if(filter->y == NULL)
    {
        free((void *) filter->x);
        free((void *) filter);

        filter->x = NULL;
        return NULL;
    }

    /* Save order on filter variable */
    filter->order = order;

    return filter; 
}

void dsp_filter_iir_deinit(iir_t *filter)
{
    /* Deallocate every A array coefficients */
    if (filter->a.low != NULL)
    {
        free((void*) filter->a.low);
        filter->a.low = NULL;
    }
    if (filter->a.high != NULL)
    {
        free((void*) filter->a.high);
        filter->a.high = NULL;
    }
    if (filter->a.pass != NULL)
    {
        free((void*) filter->a.pass);
        filter->a.pass = NULL;
    }
    if (filter->a.stop != NULL)
    {
        free((void*) filter->a.stop);
        filter->a.stop = NULL;
    }

    /* Deallocate every B array coefficients */
    if (filter->b.low != NULL)
    {
        free((void*) filter->b.low);
        filter->b.low = NULL;
    }
    if (filter->b.high != NULL)
    {
        free((void*) filter->b.high);
        filter->b.high = NULL;
    }
    if (filter->b.pass != NULL)
    {
        free((void*) filter->b.pass);
        filter->b.pass = NULL;
    }
    if (filter->b.stop != NULL)
    {
        free((void*) filter->b.stop);
        filter->b.stop = NULL;
    }
    /* Deallocate X array */
    free((void*) filter->x);
    filter->x = NULL;

    /* Deallocate Y array */
    free((void*) filter->y);
    filter->y = NULL;

    /* Deallocate filter variable */
    free((void*) filter);
    filter = NULL;
}

int8_t dsp_filter_iir_coeff_init(
    iir_t *filter, filter_type_t type, float *a, const float *b
)
{
    float **to_allocate_a;
    float **to_allocate_b;

    /* Get B coefficient address to be allocated */
    switch (type)
    {
        case FILTER_TYPE_LOWPASS:
            to_allocate_a = (float **) &filter->a.low;
            to_allocate_b = (float **) &filter->b.low;
            break;
        case FILTER_TYPE_HIGHPASS:
            to_allocate_a = (float **) &filter->a.high;
            to_allocate_b = (float **) &filter->b.high;
            break;
        case FILTER_TYPE_BANDPASS:
            to_allocate_a = (float **) &filter->a.pass;
            to_allocate_b = (float **) &filter->b.pass;
            break;
        case FILTER_TYPE_BANDSTOP:
            to_allocate_a = (float **) &filter->a.stop;
            to_allocate_b = (float **) &filter->b.stop;
            break;
        default:
            return -1; /* Misstaken filter type */
            break;
    }

    *to_allocate_a = (float *) calloc(filter->order + 1, sizeof(float));
    *to_allocate_b = (float *) calloc(filter->order + 1, sizeof(float));

    /* Test if array was allocated */
    if(*to_allocate_a == NULL)
        return -1; /* A coefficient array not allocated */
    if(*to_allocate_b == NULL)
        return -2; /* B coefficient array not allocated */

    /* Copy A & B to target filter->A & filter->B */
    for(uint16_t i = 0; i < filter->order; i++)
    {
        (*to_allocate_a)[i] = a[i];
        (*to_allocate_b)[i] = b[i];
    }
    /* Everithing succesfull */
    return 0;
}

float dsp_filter_iir(iir_t *filter, filter_type_t type, float x_in)
{
    for (size_t k = filter->order; k > 0; k--)
    {
        /* 'x' & 'y' arrays shift */
        /* x[1] = x[0], x[2] = x[1],...x[IIR_ORDER] = x[IIR_ORDER-1] */
        /* y[1] = y[0], y[2] = y[1],...y[IIR_ORDER] = y[IIR_ORDER-1] */
        filter->x[k] = filter->x[k-1];
        filter->y[k] = filter->y[k-1];
    }
    /* x[0] = Last input */
    filter->x[0] = x_in;

    const float *a;
    const float *b;
    switch (type)
    {
    case FILTER_TYPE_LOWPASS:
        a = (filter->a.low);
        b = (filter->b.low);
        break;
    case FILTER_TYPE_HIGHPASS:
        a = (filter->a.high);
        b = (filter->b.high);
        break;
    case FILTER_TYPE_BANDPASS:
        a = (filter->a.pass);
        b = (filter->b.pass);
        break;
    case FILTER_TYPE_BANDSTOP:
    default:
        a = (filter->a.stop);
        b = (filter->b.stop);
        break;
    }
    /* IIR: */
    /* y[n] = b[0]*x[n] + b[1]*x[n-1] + ... b[IIR_ORDER] * x[n - (IIR_ORDER)] 
     *      - a[1]*y[n-1] - a[2]*x[n-2] + ... a[IIR_ORDER] * y[n - (IIR_ORDER)] 
     */
    float y = 0; /* Acumulator */
    for (size_t k = 0; k <= filter->order; k++)
    {
        /* Donde x[0] = x[n]; x[1] = x[n-1] ... */
        y += b[k] * filter->x[k];
    }
    for (size_t k = 1; k <= filter->order; k++)
    {
        /* Donde y[1] = y[n-1]; y[2] = y[n-2] ... */
        y -= a[k] * filter->y[k];
    }

    /* Save y output on filter variable & return it */
    filter->y[0] = y;
    return y;
}