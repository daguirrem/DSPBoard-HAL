/**
 * @file main.c
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief 
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

#include "system.h"

#include <stdbool.h>

#include "utils.h"

float array_to_write[] = {0,1,9,2,8,3,7,4,6,5};
float array_to_read[10] = {0};

static bool check_array(float* arr_1, float *arr_2, size_t lenght)
{
    for(size_t i = 0; i < lenght; i++)
        if(arr_1[i] != arr_2[i])
            return false;
    return true;
}

int main (void)
{
    circular_buffer_t *buff;
    buff = circular_buffer_init(10, sizeof(float));

    for(size_t i = 0; i < 10; i++)
        circular_buffer_write_float(buff, array_to_write[i], NULL);
    
    for(size_t i = 0; i < 10; i++)
        array_to_read[i] = circular_buffer_read_float(buff, NULL);

    volatile bool result = check_array(
        (float*)&array_to_write, (float*)&array_to_read, 10);

    circular_buffer_deinit(buff);

    while(1)
    {
    }
}
