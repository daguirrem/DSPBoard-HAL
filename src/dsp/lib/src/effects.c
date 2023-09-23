/**
 * @file effects.c
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief DSP effects lib.
 * @version d0.1
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

#include "dsp.h"

#ifdef DSP_EFFECT_DELAY_WARN
#warning DSP_EFFECT_DELAY \
         is not defined. By default DSP_EFFECT_DELAY is defined as 1
#endif

dsp_delay_t *dsp_effect_delay_init(
    float delay[DSP_EFFECT_DELAY_SIZE], float gain[DSP_EFFECT_DELAY_SIZE], uint32_t sample_rate)
{
    dsp_delay_t *delay_ptr = (dsp_delay_t *) calloc(1, sizeof(dsp_delay_t));
    
    /* If allocation fails returns NULL */
    if(delay_ptr == NULL)
    {
        return NULL;
    }

    for(size_t i = 0; i < DSP_EFFECT_DELAY_SIZE; i++)
    {
        size_t size = delay[i] * sample_rate;
        delay_ptr->buffer[i] = circular_buffer_init(size, sizeof(float));

        /* If some buffer allocation fails, deallocate buffers allocated & dsp_delay_t 
         * and returns NULL */
        if (delay_ptr->buffer[i] == NULL)
        {
            while(i)
            {
                circular_buffer_deinit(delay_ptr->buffer[--i]);
            }

            free(delay_ptr);
            return NULL;
        }
        /* Else copy parameters to allocated dsp_delay_t variable */
        delay_ptr->delay[i] = delay_ptr->mdelay[i] = delay[i];
        delay_ptr->gain[i] = gain[i];
    }
    delay_ptr->sample_rate = sample_rate;
    return delay_ptr;
}

void dsp_effect_delay_deinit(dsp_delay_t *delay)
{
    /* Deallocate all buffers & dsp_delay_t variable */
    for(size_t i = 0; i < DSP_EFFECT_DELAY_SIZE; i++)
    {
        circular_buffer_deinit(delay->buffer[i]);
    }
    free(delay);
}

float dsp_effect_delay(dsp_delay_t *delay, float x)
{
    float y = 0;
    for(size_t i = 0; i < DSP_EFFECT_DELAY_SIZE; i++)
    {
        /* For every depth delay level check if x is desired time delayed 
         * Only if time is desired (Buffer is FULL-1) start to read the circular
         * buffer.
         */
        if(delay->_c[i] >= (delay->buffer[i]->length - 1))
        {
            /* Compute y with delayed x and depth level gain */
            y += delay->gain[i] * circular_buffer_read_float(delay->buffer[i], &delay->err);
        } 
        else
        {
            /* Wait up to time delay (Up to buffer is full)*/
            delay->_c[i]++;
        }
        /* Write to circular buffer the x */
        circular_buffer_write_float(delay->buffer[i], x, &delay->err);
    }
    return y;
}

void dsp_effect_delay_update(dsp_delay_t *delay, float *delays)
{
    for(size_t i = 0; i < DSP_EFFECT_DELAY_SIZE; i++)
    {
        /* Recompute the buffer "lenght" based on target delay and sample rate */
        /* Note: Real buffer lenght and allocation cant be modify */
        delay->buffer[i]->length = (delays[i] * delay->sample_rate) + 1;
        delay->_c[i] = 0;
    }
}

dsp_eco_t *dsp_effect_eco_init(float delay, uint32_t sample_rate)
{
    dsp_eco_t *eco_ptr;
    eco_ptr = (dsp_eco_t *) calloc(1, sizeof(dsp_eco_t));

    /* If allocation fails returns NULL */
    if(eco_ptr == NULL)
    {
        return NULL;
    }

    size_t size = delay * sample_rate;

    eco_ptr->buffer = circular_buffer_init(size + 1, sizeof(float));

    /* If buffer allocation fails, deallocate dsp_eco_t and returns NULL */
    if(eco_ptr->buffer == NULL)
    {
        free(eco_ptr);
        return NULL;
    }

    /* Copy the default config to allocated dsp_eco_t */
    eco_ptr->delay = delay;
    eco_ptr->wet = 0.5;
    eco_ptr->dry = 0.5f;
    eco_ptr->feedback = 0.4;
    eco_ptr->sample_rate = sample_rate;
    return eco_ptr;
}

void dsp_effect_eco_deinit(dsp_eco_t *eco)
{
    /* Deallocate buffer */
    circular_buffer_deinit(eco->buffer);
    /* Deallocate dsp_eco_t */
    free(eco);
}

float dsp_effect_eco(dsp_eco_t *eco, float x)
{
    float y = 0;
    /* Check if x is desired time delayed.
     * Only if time is desired (Buffer is FULL-1) start to read the circular
     * buffer.
     */
    if(eco->_c >= (eco->buffer->length - 1))
    {
        /* Compute the ECO effect with wet, dry parameters */
        float x_delayed = circular_buffer_read_float(eco->buffer, NULL);
        y += eco->dry * x;
        y +=  x_delayed * eco->wet;

        /* Mix the input with feedback delayed x*/
        x += (x_delayed * eco->feedback);
    }
    else
    {
        /* Wait up to time delay (Up to buffer is full)*/
        eco->_c++;
    }
    circular_buffer_write_float(eco->buffer, x, NULL);
    return y;
}

void dsp_effect_eco_update(dsp_eco_t *eco, float delay)
{
    /* Recompute the buffer "lenght" based on target delay and sample rate */
    /* Note: Real buffer lenght and allocation can't be modify */
    eco->buffer->length = (delay * eco->sample_rate) + 1;
    eco->_c = 0;
}