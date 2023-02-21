/**
 * @file dsp.h
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

#ifndef _DSP_H_
#define _DSP_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "system.h"
#include <stdint.h>

/**
 * @addtogroup dsp DSP
 */

/**
 * @defgroup public_dsp Public
 * @ingroup dsp
 */


/*----------------------------------------------------------------------------*/
/* Macros */
/*----------------------------------------------------------------------------*/


#define dsp_filter_fir_init_static_0(n, o) \
    float n##_x[o] = {}; \
    fir_t n##_var = \
    { \
        .x = &n##_x[0], .order = o \
    }; \
    fir_t *n = &(n##_var)

#define dsp_filter_fir_init_static_1(n, o, s) \
    static s float n##_x[o] = {}; \
    static s fir_t n##_var = \
    { \
        .x = &n##_x[0], .order = o \
    }; \
    static s fir_t *n = &(n##_var)

#define dsp_filter_fir_declarate_chooser(x,n,o,s,f, ...) f 

/**
 * @ingroup public_dsp
 * @brief Inicializate static fir_t filter
 * 
 * This macro create a fir_t variable with /n name of /o order on /s section of
 * memory (optional). Also create an array for x of size /o and assign it to 
 * fir_t variable created. The order of the filter is saved on variable created. 
 * 
 * @param[in] n Name of filter to create & inicializate.
 * @param[in] o Order of filter to inicializate.
 * @param[in] s (Optional) Section where variables are created, it can be
 *              __CCM_VAR_I for CCM data or none for .data section.
 * 
 * @return None.
 * 
 * @note 1. After call this macro you can access to a new variable of name /n.
 * @note 2. If you declarate in specific memory section, it must be called outside
 *          of main function (As global variable).
 * 
 * @see fir_t
 * 
 * E.g. @n
 * This inicializate a static fir variable and then use them.
 * @code
 * ...
 * // B Coefficients array
 * float b[10] = {1,2,3,4,5,6,7,8,9};
 * ...
 * int main(void){
 *     ...
 *     // After that call of macro, you have declarated a fir_t variable 
 *     // with name 'filter'.
 *     dsp_filter_fir_declarate(filter, 10);
 *     // Now you can assign a B coefficient filter (For example High Pass)
 *     filter.b.high = &b[0];
 *     ...
 * }
 * @endcode
 * E.g. @n
 * This inicializate a static fir variable on ccm data section.
 * @code
 * ...
 * // B Coefficients array
 * float b[10] = {1,2,3,4,5,6,7,8,9};
 * ...
 * int main(void){
 *     ...
 *     // Declare 'filter' on CCM data section.
 *     dsp_filter_fir_declarate(filter, 10, __CCM_VAR_I);
 *     // Now you can assign a B coefficient filter (For example High Pass)
 *     filter.b.high = &b[0];
 *     ...
 * }
 * @endcode
 */
#define dsp_filter_fir_declarate(...) \
    dsp_filter_fir_declarate_chooser(,##__VA_ARGS__,\
        dsp_filter_fir_init_static_1(__VA_ARGS__),\
        dsp_filter_fir_init_static_0(__VA_ARGS__)\
    ) 

#define dsp_filter_iir_init_static_0(n, o) \
    float n##_x[o] = {}; \
    iir_t n##_var = \
    { \
        .x = &n##_x[0], .order = o \
    }; \
    iir_t* n = &(n##_var)

#define dsp_filter_iir_init_static_1(n, o, s) \
    static s float n##_x[o] = {}; \
    static s iir_t n##_var = \
    { \
        .x = &n##_x[0], .order = o \
    }; \
    static s iir_t* n = &(n##_var)

#define dsp_filter_iir_declarate_chooser(x,n,o,s,f, ...) f 

/**
 * @ingroup public_dsp
 * @brief Inicializate static iir_t filter.
 * 
 * This macro create a iir_t variable with /n name of /o order on /s section of
 * memory (optional). Also create an array for x & y of size /o and assign them to 
 * iir_t variable created. The order of the filter is saved on variable created. 
 * 
 * @param[in] n Name of filter to create & inicializate.
 * @param[in] o Order of filter to inicializate.
 * @param[in] s (Optional) Section where variables are created, it can be
 *              __CCM_VAR_I for CCM data or none for .data section.
 * 
 * @return None.
 * 
 * @note 1. After call this macro you can access to a new variable of name /n.
 * @note 2. If you declarate in specific memory section, it must be called outside
 *          of main function (As global variable).
 * 
 * @see iir_t
 * 
 * E.g. @n
 * This inicializate a static iir variable and then use them.
 * @code
 * ...
 * // A & B Coefficients array
 * float a[10] = {0,1,2,3,4,5,6,7,8,9};
 * float b[10] = {1,2,3,4,5,6,7,8,9,0};
 * ...
 * int main(void){
 *     ...
 *     // After that call of macro, you have declarated a iir_t variable 
 *     // with name 'filter'.
 *     dsp_filter_iir_declarate(filter, 10);
 *     // Now you can assign A & B coefficient filter (For example High Pass)
 *     filter.a.high = &a[0];
 *     filter.b.high = &b[0];
 *     ...
 * }
 * @endcode
 * E.g. @n
 * This inicializate a static fir variable on ccm data section.
 * @code
 * ...
 * // A & B Coefficients array
 * float a[10] = {0,1,2,3,4,5,6,7,8,9};
 * float b[10] = {1,2,3,4,5,6,7,8,9,0};
 * ...
 * int main(void){
 *     ...
 *     // After that call of macro, you have declarated a iir_t variable 
 *     // with name 'filter'.
 *     dsp_filter_iir_declarate(filter, 10, __CCM_VAR_I);
 *     // Now you can assign A & B coefficient filter (For example High Pass)
 *     filter.a.high = &a[0];
 *     filter.b.high = &b[0];
 *     ...
 * }
 * @endcode
 */
#define dsp_filter_iir_declarate(...) \
    dsp_filter_iir_declarate_chooser(,##__VA_ARGS__,\
        dsp_filter_iir_init_static_1(__VA_ARGS__),\
        dsp_filter_iir_init_static_0(__VA_ARGS__)\
    ) 

/*----------------------------------------------------------------------------*/
/* Enums */
/*----------------------------------------------------------------------------*/

/**
 * @ingroup public_dsp
 * @brief Filters types.
 * 
 */
typedef enum filter_type_e
{
    FILTER_TYPE_LOWPASS,  /*!< 'LowPass' type filter */
    FILTER_TYPE_HIGHPASS, /*!< 'HighPass' type filter */
    FILTER_TYPE_BANDPASS, /*!< 'BandPass' type filter */
    FILTER_TYPE_BANDSTOP, /*!< 'BandStop' type filter */
    FILTER_TYPE_END
} filter_type_t;

/*----------------------------------------------------------------------------*/
/* Structs */
/*----------------------------------------------------------------------------*/

/**
 * @ingroup public_dsp
 * @brief FIR struct.
 * 
 * Struct to handle FIR data type.
 * 
 */
typedef struct fir_s
{
    float *x; /*!< Input array where x[0] is last input value */
    float y; /*!< Output computed value */
    uint16_t order; /*!< Filter order */
    struct
    {
        const float *low; /*!< For LowPass filter */
        const float *high; /*!< For HighPass filter */
        const float *pass; /*!< For BandPass filter */
        const float *stop; /*!< For BandStop filter */
    } b; /*!< B Coefficients */
} fir_t;

/**
 * @ingroup public_dsp
 * @brief FIR struct.
 * 
 * Struct to handle IIR data type.
 * 
 */
typedef struct iir_s
{
    float *x; /*!< Input array where x[0] is last input value */
    float *y; /*!< Output array where y[0] is last output computed value */
    uint16_t order; /*!< Filter order */
    struct
    {
        const float *low; /*!< For LowPass filter */
        const float *high; /*!< For HighPass filter */
        const float *pass; /*!< For BandPass filter */
        const float *stop; /*!< For BandStop filter */
    } a; /*!< A Coefficients (Numerator) */
    struct
    {
        const float *low; /*!< For LowPass filter */
        const float *high; /*!< For HighPass filter */
        const float *pass; /*!< For BandPass filter */
        const float *stop; /*!< For BandStop filter */
    } b; /*!< B Coefficients (Denominator) */
} iir_t;

/*----------------------------------------------------------------------------*/
/* Variables */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Functions */
/*----------------------------------------------------------------------------*/

/** ### dsp:fir:init
  * @ingroup public_dsp
  * @brief Inicializate a fir_t variable.
  * 
  * Allocate memory to fir_t variable type on heap memory depending on the 
  * FIR /order.
  * 
  * The size of memory allocated is:
  *     fir_t type:             28 [bytes] +
  *     float x[order + 1]:     (order + 1) * 4 [bytes]
  * 
  * The order filter is saved on /filter->order.
  * 
  * @param[in] order Order to inicializate filter.
  * 
  * @return fir_t allocated.
  * @retval NULL if allocation failed.
  * @retval Otherwise the address of fit_t allocated.
  * 
  * 
  * @note 1. The coefficients B are set to NULL pointer, you must to inicializate
  *          them by calling dsp_filter_fir_coeff_init() function.
  * @note 2. Y output is set to 0.
  * @note 3. This is used only for dynamic allocation.
  * 
  * @see fir_t FIR variable type.
  * @see dsp_filter_fir_coeff_init() 
  * 
  * E.g. @n
  * 
  * @code
  * ...
  * ...
  * @endcode
  */
fir_t *dsp_filter_fir_init(const uint16_t order);

/** ### dsp:fir:init
  * @ingroup public_dsp
  * @brief Deinicializate a fir_t variable.
  * 
  * Deallocate /filter & every allocated array of /filter variable.
  * 
  * @param[in] filter fir_t variable to deinicializate.
  * 
  * @return None.
  * 
  * @note This is used only for dynamic allocation.
  * 
  * @see fir_t FIR variable type.
  * 
  * E.g. @n
  * 
  * @code
  * ...
  * ...
  * @endcode
  */
void dsp_filter_fir_deinit(fir_t *filter);

/** ### dsp:fir:b:init
  * @ingroup public_dsp
  * @brief Inicializate B coefficients  of a filter.
  * 
  * Allocate B coefficients of filter /type, and copy /b to /filter->b./type.
  * 
  * @param[in] filter Filter to inicializate B coefficients.
  * @param[in] type Type of B filter coefficients to inicializate.
  * @param[in] b B coefficients to copy.
  * 
  * @return Status of inicialization.
  * @retval 0 if succesfull inicialization.
  * @retval -1 if B coefficient array not allocated.
  * 
  * @note This is used only for dynamic allocation.
  * 
  * @see
  * 
  * E.g. @n
  * 
  * @code
  * ...
  * ...
  * @endcode
  */
int8_t dsp_filter_fir_coeff_init(fir_t *filter, filter_type_t type, const float *b);


/** ### dsp:filter:fir
  * @ingroup public_dsp
  * @brief Executes a FIR on filter accordding the type.
  * 
  * Executes a convolution to compute a Y output of /filter and returns it,
  * the execution depends of filter /type and it expect a last input of x.
  * 
  * y = x[0]*b./type[0] + x[1]*b./type[1] + ... x[order]*b./type[order].
  * 
  * Where:
  *   y is stored on /filter->y
  *   x is stored on /filter->x
  *   b is stored on /filter->b
  *   x[0] is the last input.
  * 
  * @param[in] filter Filter to execute a FIR.
  * @param[in] type Filter type to execute.
  * @param[in] float Last input of x array of convolution.
  * 
  * @return Y computed output.
  * 
  * @see fir_t /filter type
  * @see filter_type_t /type type
  * 
  * E.g. @n
  * 
  * @code
  * ...
  * ...
  * @endcode
  */
float dsp_filter_fir(fir_t *filter, filter_type_t type, float x_in);

/** ### dsp:iir:init
  * @ingroup public_dsp
  * @brief Inicializate a iir_t variable.
  * 
  * Allocate memory to iir_t variable type on heap memory depending on the 
  * IIR /order.
  * 
  * The size of memory allocated is:
  *     iir_t type:             44 [bytes] +
  *     float x[order + 1]:     (order + 1) * 4 [bytes] +
  *     float y[order + 1]:     (order + 1) * 4 [bytes]
  * 
  * @param[in] order Order to inicializate filter.
  * 
  * @return iir_t allocated.
  * @retval NULL if allocation failed.
  * @retval Otherwise the address of iir_t allocated.
  * 
  * 
  * @note 1. The coefficients A & B are set to NULL pointer, you must to 
  *          inicializate them by calling dsp_filter_iir_coeff_init() function.
  * @note 2. This is used only for dynamic allocation.
  * 
  * @see iir_t IIR variable type.
  * @see dsp_filter_iir_coeff_init() 
  * 
  * E.g. @n
  * 
  * @code
  * ...
  * ...
  * @endcode
  */
iir_t *dsp_filter_iir_init(const uint16_t order);

/** ### dsp:iir:init
  * @ingroup public_dsp
  * @brief Deinicializate a fir_t variable.
  * 
  * Deallocate /filter & every allocated array of /filter variable.
  * 
  * @param[in] filter fir_t variable to deinicializate.
  * 
  * @return None.
  * 
  * @note This is used only for dynamic allocation.
  * 
  * @see fir_t FIR variable type.
  * 
  * E.g. @n
  * 
  * @code
  * ...
  * ...
  * @endcode
  */
void dsp_filter_iir_deinit(iir_t *filter);

/** ### dsp:fir:b:init
  * @ingroup public_dsp
  * @brief Inicializate B coefficients  of a filter.
  * 
  * Allocate B coefficients of filter /type, and copy /b to /filter->b./type.
  * 
  * @param[in] filter Filter to inicializate B coefficients.
  * @param[in] type Type of B filter coefficients to inicializate.
  * @param[in] b B coefficients to copy.
  * 
  * @return Status of inicialization.
  * @retval 0 if succesfull inicialization.
  * @retval -1 if B coefficient array not allocated.
  * 
  * @note This is used only for dynamic allocation.
  * 
  * @see
  * 
  * E.g. @n
  * 
  * @code
  * ...
  * ...
  * @endcode
  */
int8_t dsp_filter_iir_coeff_init(
    iir_t *filter, filter_type_t type, float *a, const float *b
);

/** ### dsp:filter:fir
  * @ingroup public_dsp
  * @brief Executes a FIR on filter accordding the type.
  * 
  * Executes a convolution to compute a Y output of /filter and returns it,
  * the execution depends of filter /type and it expect a last input of x.
  * 
  * y = x[0]*b./type[0] + x[1]*b./type[1] + ... x[order]*b./type[order].
  * 
  * Where:
  *   y is stored on /filter->y
  *   x is stored on /filter->x
  *   b is stored on /filter->b
  *   x[0] is the last input.
  * 
  * @param[in] filter Filter to execute a FIR.
  * @param[in] type Filter type to execute.
  * @param[in] float Last input of x array of convolution.
  * 
  * @return Y computed output.
  * 
  * @see fir_t /filter type
  * @see filter_type_t /type type
  * 
  * E.g. @n
  * 
  * @code
  * ...
  * ...
  * @endcode
  */
float dsp_filter_iir(iir_t *filter, filter_type_t type, float x_in);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DSP_H_ */