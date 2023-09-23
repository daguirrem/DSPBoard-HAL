/**
 * @file ks0108.h
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief 
 * @version d0.1
 * @date 2023-06-24
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

#ifndef _KS0108_H_
#define _KS0108_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>

#define KS0108_PIN_D0_Pos  8

#define KS0108_PIN_RS  GPIO_IO7
#define KS0108_PIN_RW  GPIO_IO6
#define KS0108_PIN_EN  GPIO_IO5
#define KS0108_PIN_CS1 GPIO_IO4
#define KS0108_PIN_CS2 GPIO_IO3
#define KS0108_PIN_RST GPIO_IO2

/*----------------------------------------------------------------------------*/
/* Enums */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structs */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Variables */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Functions */
/*----------------------------------------------------------------------------*/

void ks0108_init(void);

void ks0108_send_cmd(uint8_t cmd, uint16_t cs);

void ks0108_write(uint8_t data, uint16_t cs);

void ks0108_set_x(uint8_t x);

void ks0108_set_y(uint8_t y);

void ks0108_set_z(uint8_t z);

void ks0108_screen_clear(void);

void ks0108_vram_clear(void);

void ks0108_vram_write(const uint8_t buff[8][128]);

void ks0108_vram_add_layer(const uint8_t buff[8][128]);

void ks0108_screen_render(void);

void ks0108_vram_puts(char c);

void ks0108_vram_print(char *s);

size_t ks0108_vram_printf(const char *format, ...);

void ks0108_vram_set_xy(uint8_t _x, uint8_t _y);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _KS0108_H_ */