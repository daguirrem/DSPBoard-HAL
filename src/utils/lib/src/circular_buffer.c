/**
 * @file circular_buffer.c
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief Generic implementation of cirular buffer.
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

#include "utils.h"

circular_buffer_t *circular_buffer_init(size_t length, int8_t size_of)
{
    circular_buffer_t *_p;
    _p = (circular_buffer_t *) calloc(1, sizeof(circular_buffer_t));
    _p->b = calloc(length + 1, size_of);
    if(_p->b == NULL) { free(_p); return NULL;}
    _p->length = length + 1;
    _p->head = 0;
    _p->tail = 0;
    return _p;
}

void circular_buffer_deinit(circular_buffer_t *buffer)
{
    free(buffer->b);
    free(buffer);
}

void circular_buffer_write_float(
    circular_buffer_t *buffer, float in, circular_buffer_err_t *err
)
{
    if((buffer->head + 1) == buffer->tail)
    {
        if(err != NULL)
            *err = CIRC_BUFF_FULL;
        return;
    }
    
    buffer->head = (buffer->head + 1) % buffer->length;
    ((float *)buffer->b)[buffer->head] = in;
    
    if(err != NULL)
        *err = CIRC_BUFF_OK;
}

float circular_buffer_read_float(
    circular_buffer_t *buffer, circular_buffer_err_t *err
)
{
    if(buffer->head == buffer->tail)
    {
        if(err != NULL)
            *err = CIRC_BUFF_EMPTY;
        return 0;
    }
    if(err != NULL)
        *err = CIRC_BUFF_OK;

    buffer->tail = (buffer->tail + 1) % buffer->length;
    return ((float *)buffer->b)[buffer->tail];
}