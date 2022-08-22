/**
 * @file main.c
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief Ejemplo de lectura de entradas GPIO.
 * @version d0.1
 * @date 2022-08-21
 * 
 * @copyright MIT License, Copyright (c) 2022 David A. Aguirre M. @n @n
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
#include "gpio.h"

int main (void)
{
    /* Habilita el clock del GPIOA y GPIOE */
    gpio_clk_en(
        GPIOA_RCC | GPIOE_RCC
    );

    /* Configura los LEDs de la board */
    gpio_config_mode(
        GPIOA, GPIO_MODE_OUTPUT, GPIO_IO7 | GPIO_IO6
    );

    /* Configuración de los botones de la placa */
    /* Entrada PULL-UP */
    gpio_config_all(
        GPIOE,
        GPIO_CONFIG_MODE_INPUT | GPIO_CONFIG_PULL_UP,
        GPIO_IO4 | GPIO_IO3
    );

    /* Escribe en todo el puerto 0b10000000 [Prende LED en 6 y apaga en 7] */
    gpio_port_write(
        GPIOA, GPIO_IO7
    );

    /* Espera hasta que se presionen los 2 botones */
    while(
        gpio_port_read_input_mask(GPIOE, GPIO_IO4 | GPIO_IO3) != 0
    );

    /* Apaga LEDs */
    gpio_port_set(
        GPIOA, GPIO_IO7 | GPIO_IO6
    );

    while(1)
    {
        /* Lectura del estado de los botones */
        uint16_t port = gpio_port_read_input_mask(GPIOE, GPIO_IO4 | GPIO_IO3);
        /* Escritura del estado en los LEDs */
        port <<= 3;
        /* GPIO[4:3] -> GPIO[7:6] */
        gpio_port_write(GPIOA, port);
        /* Espere 100 ms */
        delay_ms(100);
    }
}
