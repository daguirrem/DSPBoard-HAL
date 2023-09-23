/**
 * @file menu.h
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief 
 * @version d0.1
 * @date 2023-06-25
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

#ifndef _MENU_H_
#define _MENU_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdint.h>

/*----------------------------------------------------------------------------*/
/* Enums */
/*----------------------------------------------------------------------------*/
struct {
    uint8_t depht;
    uint8_t mode;
    uint8_t volume;
    uint8_t gain;
    float wet;
    float feedback;
    float dry;
    uint16_t delay;
} menu = {
    .depht = 0, .mode = 0,
    .volume = 50,
    .gain = 0,
    .wet = 0.5f, .feedback = 0.5, .dry = 0.3,
    .delay = 100
};

/*----------------------------------------------------------------------------*/
/* Structs */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Variables */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Functions */
/*----------------------------------------------------------------------------*/



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MENU_H_ */