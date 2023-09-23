/**
 * @file utils.h
 * @author David A. Aguirre M. <daguirre.m@outlook.com
 * @brief Extra libs to DSP Board SDK.
 * @version d0.1
 * @date 2023-06-19
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

#ifndef _UTILS_H_
#define _UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdlib.h>
#include <stdint.h>

/**
 * @addtogroup utils UTILS
 */

/**
 * @defgroup public_utils Public
 * @ingroup utils
 */

/*----------------------------------------------------------------------------*/
/* Enums */
/*----------------------------------------------------------------------------*/
typedef enum circular_buffer_err_e
{
    CIRC_BUFF_OK = 0,
    CIRC_BUFF_FULL = 1,
    CIRC_BUFF_EMPTY = 2
} circular_buffer_err_t;

/*----------------------------------------------------------------------------*/
/* Structs */
/*----------------------------------------------------------------------------*/
typedef struct circular_buffer_s 
{
    void *b; /*<! Pointer to buffer */
    size_t head; /*<! Circular buffer head */
    size_t tail; /*<! Circular buffer tail */
    size_t length; /*<! Circular buffer length */
} circular_buffer_t;

/*----------------------------------------------------------------------------*/
/* Variables */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Functions */
/*----------------------------------------------------------------------------*/

/* Circular buffer -----------------------------------------------------------*/

/** ### circular_buffer:init
  * @ingroup public_dsp
  * @brief Inicializate a circular_buffer_t variable.
  * 
  * Allocate memory to circular_buffer_t variable type.
  * 
  * The size of memory allocated is:
  *     circular_buffer_t type:   16 [bytes] +
  *     float b[length + 1]:       (length + 1) * size_of [bytes]
  * 
  * @param[in] length Buffer size to init.
  * @param[in] size_of sizeof data type to init the /buffer.
  * 
  * @return circular_buffer_t allocated.
  * @retval NULL if allocation failed.
  * @retval Otherwise the address of circular_buffer_t allocated.
  * 
  * @see circular_buffer_t.
  * 
  * E.g. @n
  * 
  * @code
  * ...
  * ...
  * @endcode
  */
circular_buffer_t *circular_buffer_init(size_t length, int8_t size_of);

void circular_buffer_deinit(circular_buffer_t *buffer);

/** ### circular_buffer:write:float
  * @ingroup public_utils
  * @brief Write a float on a circular buffer.
  * 
  * Writes /in float type variable to /buffer and returns on /err the result of
  * write operation. If all is succesfull /err returns CIRC_BUFF_OK.
  * 
  * @param[in] buffer Pointer to circular buffer.
  * @param[in] in Float to wirte on buffer.
  * @param[out] err Pointer to error flag variable.
  * 
  * @return None.
  * 
  * @note You can pass to /err NULL pointer if you don't need it.
  * 
  * @see circular_buffer_t Buffer data type.
  * @see circular_buffer_err_t Error data type.
  * 
  * E.g. @n
  * 
  * @code
  * ...
  * ...
  * @endcode
  */
void circular_buffer_write_float(
    circular_buffer_t *buffer, float in, circular_buffer_err_t *err
);

/** ### circular_buffer:read:float
  * @ingroup public_utils
  * @brief Read a float from circular buffer.
  * 
  * Reads float type variable from /buffer and returns on /err the result of
  * read operation. If all is succesfull /err returns CIRC_BUFF_OK.
  * 
  * @param[in] buffer Pointer to circular buffer.
  * @param[out] err Pointer to error flag variable.
  * 
  * @return Float data from buffer readed.
  * 
  * @note You can pass to /err NULL pointer if you don't need it.
  * 
  * @see circular_buffer_t Buffer data type.
  * @see circular_buffer_err_t Error data type.
  * 
  * E.g. @n
  * 
  * @code
  * ...
  * ...
  * @endcode
  */
float circular_buffer_read_float(
    circular_buffer_t *buffer, circular_buffer_err_t *err
);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _UTILS_H_ */