/**
 * @file dsp.h
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief DSP header lib for custom DSP Board SDK.
 * @version d0.2
 * @date 2023-07-04
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
#include <stdbool.h>

#include "utils.h"

/**
 * @addtogroup dsp DSP
 */

/**
 * @defgroup public_dsp Public
 * @ingroup dsp
 */

#ifndef DSP_EFFECT_DELAY_SIZE
#define DSP_EFFECT_DELAY_SIZE 1 /*<! Default dsp delay effect depth */
#define DSP_EFFECT_DELAY_WARN 1 /*<! Flag to display warning on compile time */
#endif


/*----------------------------------------------------------------------------*/
/* Macros */
/*----------------------------------------------------------------------------*/


#define dsp_filter_fir_init_static_0(n, o) \
    float n##_x[o + 1] = {}; \
    fir_t n##_var = \
    { \
        .x = &n##_x[0], .order = o \
    }; \
    fir_t *n = &(n##_var)

#define dsp_filter_fir_init_static_1(n, o, s) \
    static s float n##_x[o + 1] = {}; \
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
    float n##_x[o + 1] = {}; \
    float n##_y[o + 1] = {}; \
    iir_t n##_var = \
    { \
        .x = &n##_x[0], .y = &n##_y[0], .order = o \
    }; \
    iir_t* n = &(n##_var)

#define dsp_filter_iir_init_static_1(n, o, s) \
    static s float n##_x[o + 1] = {}; \
    static s float n##_y[o + 1] = {}; \
    static s iir_t n##_var = \
    { \
        .x = &n##_x[0], .y = &n##_y[0], .order = o \
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
 * @brief IIR struct.
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

/**
 * @ingroup public_dsp
 * @brief ECO struct.
 * 
 * Struct to handle ECO data type.
 * 
 */
typedef struct eco_s
{
    circular_buffer_t *buffer; /*!< Internal circular buffer */
    circular_buffer_err_t err; /*!< Error status to cirular buffer opeartions */
    uint32_t sample_rate; /*!< Sample rate to compute eco buffer length */
    size_t _c; /*!< Internal counter */

    float wet; /*!< Wet gain (from 0 to 1) */
    float dry; /*!< Dry gain (from 0 to 1) */
    float feedback; /*!< Feedback gain (from 0 to 1) */
    float delay; /*!< Current eco delay (s) [> 0 && <= mdelay] */
    float mdelay; /*!< Max delay (s) (configured on dsp_effect_eco_init) */
    float x; /* Computed x to eco */
} dsp_eco_t;

/**
 * @ingroup public_dsp
 * @brief DSP_DELAY struct.
 * 
 * Struct to handle DSP delay data type.
 * 
 */
typedef struct dsp_delay_s
{
    circular_buffer_t *buffer[DSP_EFFECT_DELAY_SIZE] /*!< Internal circular buffer/s */;
    circular_buffer_err_t err; /*!< Error status to cirular buffer opeartions */
    uint32_t sample_rate; /*!< Sample rate to compute delay buffer/s length/s */
    size_t _c[DSP_EFFECT_DELAY_SIZE]; /*!< Internal counter */

    float delay[DSP_EFFECT_DELAY_SIZE]; /*!< Current delay/s (s) [> 0 && <= mdelay] */
    float mdelay[DSP_EFFECT_DELAY_SIZE]; /*!< Max delay/s (s) (configured on dsp_effect_eco_init) */
    float gain[DSP_EFFECT_DELAY_SIZE]; /* Gain of delay/s*/
} dsp_delay_t;

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

/*----------------------------------------------------------------------------*/
/** ### dsp:effect:delay:init
  * @ingroup public_dsp
  * @brief Inicializate dsp_delay_t variable type to apply dsp delay effect.
  * 
  * Allocates a single buffer or array of buffers from /delay with length
  * computed from /delay array and /sample_rate.
  * 
  * The size of memory allocated is:
  *     dsp_delay_t type:       37 [bytes] +
  *     circular_buffer_t:      16 [bytes] +
  *     buffer[/delay * /sample_rate]: (/delay * /sample_rate) * 4 [bytes]
  * 
  * @param[in] delay array of max delays to inicializate.
  * @param[in] gain array of max delays to inicializate.
  * @param[in] sample_rate sample rate of delay effect.
  * 
  * @return dsp_delay_t allocated.
  * @retval NULL if allocation failed.
  * @retval Otherwise the address of dsp_delay_t allocated.
  * 
  * @note You must allocate enough heap memory at linker file (linker.ld)
  * 
  * @see dsp_delay_t delay datatype.
  * 
  * E.g. @n
  * This init dsp_delay_t of 3 depth levels. 
  * (DSP_EFFECT_DELAY_SIZE=3 defined on user.mk)
  * @code
  * ...
  * #include "dsp.h"
  * 
  * // dsp_delay_t to be allocated
  * dsp_delay_t *dsp_delay;
  * 
  * void main(void)
  * {
  *     ...
  *     // Declare gains of each delay
  *     float gains[DSP_EFFECT_DELAY_SIZE] = {0.8f, 0.65f, 0.1f};
  *     
  *     // Declare max delays of each level (on seconds)
  *     float delays[DSP_EFFECT_DELAY_SIZE] = {0.05f, 0.085f, 0.1f};
  *     
  *     // Init the delay effect variable with sample rate at 44100 Hz
  *     dsp_delay = dsp_effect_delay_init(delays, gains, 44100);
  *     
  *     // Test if delay is succesfull allocated
  *     if (dsp_delay == NULL)
  *         while(1) {//DO SOMETHING TO NOTIFY AN ERROR OR LOOP THE PROGRAM}
  *     
  *     // Everithing is ok.
  *     ...
  *     while(1)
  *     {
  *         ...
  *     }
  * }
  * ...
  * @endcode
  */
dsp_delay_t *dsp_effect_delay_init(
    float delay[DSP_EFFECT_DELAY_SIZE], float gain[DSP_EFFECT_DELAY_SIZE], uint32_t sample_rate);

/** ### dsp:effect:delay:deinit
  * @ingroup public_dsp
  * @brief Deallocates dsp_delay_t variable.
  * 
  * Deallocate all resource from dsp_delay_t variable.
  * 
  * @param[in] delay Pointer to dsp_delay_t to deallocate.
  * 
  * @return None
  * 
  * @see dsp_delay_t delay_ptr datatype.
  * 
  * E.g. @n
  * This deallocates dsp_delay variable.
  * @code
  * ...
  * int main(void)
  * {
  *     dsp_delay_t *dsp_delay;
  *     ...
  *     // Code to init dsp_delay
  *     ...
  *     dsp_effect_delay_deinit(dsp_delay);
  *     while(1)
  *     {
  *     }
  * }
  * ...
  * @endcode
  */
void dsp_effect_delay_deinit(dsp_delay_t *delay);

/** ### dsp:effect:delay
  * @ingroup public_dsp
  * @brief Execute a delay effect with current /delay preallocated variable.
  * 
  * Compute and return a delayed /x from /x input with /delay preallocated
  * configs.
  * 
  * Eq.
  *   y = 0;
  *   for (i = 0; i < DSP_EFFECT_DELAY_SIZE; i++)
  *     y += x_delayed[i] * gain[i];
  *
  *   where:
  *     x_delayed is a x readed from circular_buffers array [/x delayed /eco->delay seconds].
  *     /x is saved on circular_buffer.
  * 
  * 
  * @param[in] delay dsp_delay_t configs to apply delay effect.
  * @param[in] x Input to compute delay effect.
  * 
  * @return Computed delayed /x.
  * 
  * @note Based on "Implementation of sound effects in DSP". Alfredo Ricci Vásquez - Juan Carlos Bucheli García
  * 
  * @see dsp_delay_t delay datatype.
  * 
  * E.g. @n
  * 
  * @code
  * ...
  * #include "dsp.h"
  * 
  * int main(void)
  * {
  *     dsp_delay_t *dsp_delay;
  *     float gains[DSP_EFFECT_DELAY_SIZE] = {...}, delays[DSP_EFFECT_DELAY_SIZE] = {...};
  *     
  *     dsp_delay = dsp_effect_delay_init(delays, gains, 44100);
  *     
  *     if (dsp_delay == NULL)
  *         while(1) {}
  *     
  *     while(1)
  *     {
  *         ...
  *         // bucle run at 44.1 kHz.
  *         float x = adc; // Some discrete value.
  *         dsp_effect_delay(dsp_delay, x);
  *         ...
  *     }
  * }
  * ...
  * @endcode
  */
float dsp_effect_delay(dsp_delay_t *delay, float x);

/** ### dsp:effect:eco:update
  * @ingroup public_dsp
  * @brief Update current delay/s from delay effect.
  * 
  * Update /delay->delay value (> 0 && <= /delay->mdelay)
  * 
  * @param[in] delay dsp_delay_t to update.
  * @param[in] delays target array of delays to update.
  * 
  * @return None
  * 
  * @see dsp_delay_t
  * 
  * E.g. @n
  * This modify current delay to 50 ms from 85 ms at i = 10,
  * and finally to 75 from 85 ms at i = 20 only on second delay depth level.
  * @code
  * ...
  * #include "dsp.h"
  * 
  * int main(void)
  * {
  *     float gains[DSP_EFFECT_DELAY_SIZE] = {0.8f, 0.65f, 0.1f};
  *     float delays[DSP_EFFECT_DELAY_SIZE] = {0.03f, 0.085f, 0.1f};
  *     
  *     dsp_delay = dsp_effect_delay_init(delays, gains, 44100);
  *     
  *     // Test if delay is succesfull allocated
  *     if (dsp_delay == NULL)
  *         while(1) {}
  *     
  *     uint8_t i = 0;
  *     while(1)
  *     {
  *         ..
  *         // bucle run at 44.1 kHz.
  *         float x = adc; // Some discrete value.
  *         dsp_effect_delay(dsp_delay, x);
  *         
  *         i += 1;
  *         if(i == 10)
  *         {
  *             delays[1] = 0.05f;
  *             dsp_effect_delay_update(dsp_delay, &delays);
  *         }
  *         else if (i == 20)
  *         {
  *             delays[1] = 0.075f;
  *             dsp_effect_delay_update(dsp_delay, &delays);
  *         }
  *         ...
  *     }
  * }
  * ...
  * @endcode
  */
void dsp_effect_delay_update(dsp_delay_t *delay, float *delays);

/** ### dsp:effect:eco:init
  * @ingroup public_dsp
  * @brief Inicializate dsp_eco_t variable type to apply dsp eco effect.
  * 
  * Allocates a single buffer with length computed from /delay and 
  * /sample_rate, also inicializate wet, dry and feedback parameters from
  * /eco with 0.5, 0.5 and 0.4 values respectively.
  * 
  * @param[in] delay dsp_delay_t to inicializate.
  * @param[in] max_delay array of max delays to inicializate.
  * @param[in] sample_rate sample rate of delay effect.
  * 
  * @return None
  * 
  * @note 1. /eco->[wet,dry,feedback,delay] can be modify externally.
  * @note 2. You must allocate enough heap memory at linker file (linker.ld)
  * 
  * @see dsp_eco_t eco datatype.
  * 
  * E.g. @n
  * This allocates dsp_eco_t variable with max delay of 250 ms and wet of 0.4,
  * dry = 0.4 and feedback = 0.6.
  * @code
  * ...
  * #include "dsp.h"
  * 
  * dsp_eco_t *dsp_eco;
  * int main(void)
  * {
  *     ...
  *     dsp_eco = dsp_effect_eco_init(0.25, 44100);
  *     
  *     // Test if eco is succesfull allocated
  *     if (dsp_eco == NULL)
  *         while(1) {//DO SOMETHING TO NOTIFY AN ERROR OR LOOP THE PROGRAM}
  * 
  *     // Modify default eco parameters.
  *     dsp_eco->wet = 0.4f;
  *     dsp_eco->dry = 0.4f;
  *     dsp_eco->feedback = 0.6;
  *     ...
  *     while(1)
  *     {
  *     }
  * }
  * ...
  * @endcode
  */
dsp_eco_t *dsp_effect_eco_init(float max_delay, uint32_t sample_rate);

/** ### dsp:effect:eco:deinit
  * @ingroup public_dsp
  * @brief Deallocates dsp_eco_t variable.
  * 
  * Deallocate all resource from dsp_eco_t variable.
  * 
  * @param[in] eco Pointer to dsp_eco_t to deallocate.
  * 
  * @return None
  * 
  * @see dsp_eco_t eco_ptr datatype.
  * 
  * E.g. @n
  * This deallocates dsp_eco variable.
  * @code
  * ...
  * int main(void)
  * {
  *     dsp_eco_t *dsp_eco;
  *     ...
  *     // Code to init dsp_eco
  *     ...
  *     dsp_effect_eco_deinit(dsp_eco);
  *     while(1)
  *     {
  *     }
  * }
  * ...
  * @endcode
  */
void dsp_effect_eco_deinit(dsp_eco_t *eco);

/** ### dsp:effect:eco
  * @ingroup public_eco
  * @brief Execute an eco effect from /eco preinicializated variable.
  * 
  * Compute a /x eco from /x with /eco configs.
  * 
  * Eq.
  *   y = (/x * /eco->dry) + (x_delayed * /eco->wet);
  *   where:
  *     x_delayed is a x readed from ciruclar buffer [x delayed /eco->delay seconds].
  *     x to save on circular_buffer is:
  *     x = /x + (x_delayed * /eco->feedback).
  * 
  * @param[in] eco dsp_eco_t configs to apply eco effect.
  * @param[in] x Input to compute eco effect.
  * 
  * @return Computed eco /x.
  * 
  * @note Based on ECO basics diagram at https://wiki.analog.com/resources/tools-software/sharc-audio-module/baremetal/delay-effect-tutorial
  * 
  * @see dsp_eco_t eco datatype
  * 
  * E.g. @n
  * This apply eco effect with default wet, dry & feedback, delay = 250 ms
  * fs = 44100;
  * @code
  * ...
  * #include "dsp.h"
  * 
  * int main(void)
  * {
  *     dsp_eco_t *dsp_eco;
  *     
  *     dsp_eco = dsp_effect_eco_init(0.25f, 44100);
  *     
  *     if (dsp_eco == NULL)
  *         while(1) {}
  *     
  *     while(1)
  *     {
  *         ...
  *         // bucle run at 44.1 kHz.
  *         float x = adc; // Some discrete value.
  *         dsp_effect_eco(dsp_eco, x);
  *         ...
  *     }
  * }
  * ...
  * @endcode
  */
float dsp_effect_eco(dsp_eco_t *eco, float x);

/** ### dsp:effect:eco:update
  * @ingroup public_dsp
  * @brief Update current delay from eco effect.
  * 
  * Update /eco->delay value (> 0 && <= /eco->mdelay)
  * 
  * @param[in] eco dsp_eco_t to update delay
  * @param[in] delay target delay.
  * 
  * @return None
  * 
  * @see dsp_eco_t
  * 
  * E.g. @n
  * This modify current eco delay to 50 ms from 250 ms at i = 10,
  * amd finally to 75 from 50 ms at i = 20.
  * @code
  * ...
  * #include "dsp.h"
  * 
  * int main(void)
  * {
  *     dsp_eco_t *dsp_eco;
  *     
  *     dsp_eco = dsp_effect_eco_init(0.25f, 44100);
  *     
  *     if (dsp_eco == NULL)
  *         while(1) {}
  *     
  *     uint8_t i = 0;
  *     while(1)
  *     {
  *         ..
  *         // bucle run at 44.1 kHz.
  *         float x = adc; // Some discrete value.
  *         dsp_effect_eco(dsp_eco, x);
  *         
  *         i += 1;
  *         if(i == 10)
  *         {
  *             dsp_effect_eco_update(dsp_eco, 0.05f);
  *         }
  *         else if (i == 20)
  *         {
  *             dsp_effect_eco_update(dsp_eco, 0.075f);
  *         }
  *         ...
  *     }
  * }
  * ...
  * @endcode
  */
void dsp_effect_eco_update(dsp_eco_t *eco, float delay);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _DSP_H_ */
