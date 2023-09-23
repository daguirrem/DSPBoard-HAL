/**
 * @file ks0108.c
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

#include "ks0108.h"

#include "system.h"
#include "gpio.h"
#include "rcc.h"

#include "font.h"

void ks1080_delay(void)
{
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
}

void ks0108_init(void)
{
    gpio_clk_en(GPIOG_RCC);
    gpio_config_mode(
        GPIOG, GPIO_MODE_OUTPUT,
        0xFFFF
    );

    gpio_config_speed(GPIOG, GPIO_SPEED_VHIGH, 0xFFFF);

    gpio_config_mode(
        GPIOH, GPIO_MODE_OUTPUT,
        GPIO_IO11
    );

    gpio_port_clr(GPIOG, 0xFFFF);
    delay_ms(5);
    gpio_port_set(GPIOG, KS0108_PIN_RST);
    delay_ms(50);

    ks0108_send_cmd(0x3F, KS0108_PIN_CS1 | KS0108_PIN_CS2);
    ks0108_screen_clear();

    ks0108_set_x(0);
    ks0108_set_y(0);
    ks0108_set_z(0);
}

void ks0108_busy_wait(void)
{
    gpio_config_mode(GPIOG, GPIO_MODE_INPUT, 0xFF << KS0108_PIN_D0_Pos);
    
    gpio_port_set(GPIOG, KS0108_PIN_CS1 | KS0108_PIN_CS2);

    gpio_port_clr(
        GPIOG, KS0108_PIN_RS
    );

    gpio_port_set(
        GPIOG, KS0108_PIN_RW
    );

    do {
        gpio_port_set(GPIOG, KS0108_PIN_EN);
        ks1080_delay();
        gpio_port_clr(GPIOG, KS0108_PIN_EN);
        ks1080_delay();
    }
    while(
        gpio_port_read_input_mask(GPIOG, 0x4 << KS0108_PIN_D0_Pos) != 0
    );

    gpio_port_clr(GPIOG, KS0108_PIN_CS1 | KS0108_PIN_CS2);

    gpio_config_mode(GPIOG, GPIO_MODE_OUTPUT, 0xFF << KS0108_PIN_D0_Pos);
}

void ks0108_send_cmd(uint8_t cmd, uint16_t cs)
{
    uint8_t EXTI_Back = EXTI->IMR;
    EXTI->IMR = 0;
    ks0108_busy_wait();

    gpio_port_clr(
        GPIOG, KS0108_PIN_RS | KS0108_PIN_RW | (0xFF << KS0108_PIN_D0_Pos)
    );
    
    gpio_port_set(GPIOG, cs);

    gpio_port_set(
        GPIOG, (cmd << KS0108_PIN_D0_Pos)
    );

    gpio_port_set(GPIOG, KS0108_PIN_EN);
    ks1080_delay();
    gpio_port_clr(GPIOG, KS0108_PIN_EN);
    ks1080_delay();

    gpio_port_clr(GPIOG, cs);
    EXTI->IMR = EXTI_Back;
}

void ks0108_write(uint8_t data, uint16_t cs)
{
    uint8_t EXTI_Back = EXTI->IMR;
    EXTI->IMR = 0;
    ks0108_busy_wait();
    
    gpio_port_clr(
        GPIOG, KS0108_PIN_RW | (0xFF << KS0108_PIN_D0_Pos)
    );

    gpio_port_set(
        GPIOG, KS0108_PIN_RS | cs | data << KS0108_PIN_D0_Pos
    );

    gpio_port_set(GPIOG, KS0108_PIN_EN);
    ks1080_delay();
    gpio_port_clr(GPIOG, KS0108_PIN_EN);
    ks1080_delay();

    gpio_port_clr(GPIOG, cs);
    EXTI->IMR = EXTI_Back;
}

void ks0108_set_x(uint8_t x)
{
    ks0108_send_cmd(0xB8 | x, KS0108_PIN_CS2 | KS0108_PIN_CS1);
}

void ks0108_set_y(uint8_t y)
{
    ks0108_send_cmd(0x40 | y, KS0108_PIN_CS2 | KS0108_PIN_CS1);
}

void ks0108_set_z(uint8_t z)
{
    ks0108_send_cmd(0xC0 | z, KS0108_PIN_CS2 | KS0108_PIN_CS1);
}

void ks0108_screen_clear(void)
{
    ks0108_set_y(0);
    for(uint8_t x = 0; x < 8; x++)
    {
        ks0108_set_x(x);
        for(uint8_t y = 0; y < 64; y++)
            ks0108_write(0, KS0108_PIN_CS2 | KS0108_PIN_CS1);
    }
}

uint8_t vram[8][128] = {};

void ks0108_vram_clear(void)
{
    for(uint8_t x = 0; x < 8; x++)
        for(uint8_t y = 0; y < 128; y++)
            vram[x][y] = 0;
}

void ks0108_vram_write(const uint8_t buff[8][128])
{
    for(uint8_t x = 0; x < 8; x++)
        for(uint8_t y = 0; y < 128; y++)
            vram[x][y] = buff[x][y];
}

void ks0108_vram_add_layer(const uint8_t buff[8][128])
{
    for(uint8_t x = 0; x < 8; x++)
        for(uint8_t y = 0; y < 128; y++)
            vram[x][y] |= buff[x][y];
}

void ks0108_screen_render(void)
{
    ks0108_set_y(0);
    for(uint8_t x = 0; x < 8; x++)
    {
        ks0108_set_x(x);
        for(uint8_t y = 0; y < 64; y++)
            ks0108_write(vram[x][y], KS0108_PIN_CS1);
    }

    
    for(uint8_t x = 0; x < 8; x++)
    {
        ks0108_set_y(0);
        ks0108_set_x(x);
        for(uint8_t y = 64; y < 127; y++){
            ks0108_write(vram[x][y], KS0108_PIN_CS2);
        }
    }
}

uint8_t x = 0, y = 0;

void ks0108_vram_puts(char c)
{
    c -= 32;
    for(uint8_t i = 0; i < 5; i++)
        vram[x][i + y] = font[(5 * c) + i];
    
    vram[x][6 + y] = 0;
    y += 6;
    
    if(y >= 128)
    {
        y = 0;
        x ++;
        if (x >= 8)
            x = 0;
    }
}

void ks0108_vram_print(char *s)
{
    do {
        if(*s == '\n')
        {
            y = 0;
            x++;
            if (x >= 8)
                x = 0;
        }
        else
        {
            ks0108_vram_puts(*s);
        }
        s++;
    } while(*s != 0);
}

size_t ks0108_vram_printf(const char *format, ...)
{
    char buffer[20];
    size_t rm = 0;
    va_list args;
    va_start(args, format);
    rm = vsnprintf(buffer, 20 - 1, format, args);
    va_end(args);
    ks0108_vram_print(buffer);
    return rm;
}



void ks0108_vram_set_xy(uint8_t _x, uint8_t _y)
{
    x = _x, y = _y;
}