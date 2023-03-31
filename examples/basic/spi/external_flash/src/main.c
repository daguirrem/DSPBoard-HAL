/**
 * @file main.c
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief Ejemplo de implementación del SPI, para controlar una memoria flash
 *        W25Qxx mediante una librería externa (https://github.com/iammingge/Driver_W25Qxx).
 * @version d0.1
 * @date 2023-03-23
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

#include <string.h>

#include "system.h"

#include "rcc.h"
#include "spi.h"
#include "gpio.h"

#include "W25Qxx.h"

/* Variable de configuración del SPI */
static spi_t spi =
{
    /* Uso de SPI 2 */
    .spi_p = SPI2,

    /* GPIOB (SCK:13, MISO:14, MOSI:15) GPIOC (SS:9) */
    .gpio_spi = GPIOB, .gpio_ss = GPIOC,
    .sck_pin = GPIO_IO13, .miso_pin = GPIO_IO14, .mosi_pin = GPIO_IO15,
    .ss_pin = {GPIO_IO9}, .ss_size = 1,
    /* Selección de esclavo por software */
    .software_ss = true,

    /* Reloj de SPI más lento (Prescaler máximo) */
    .clk_prescaler = SPI_PRESCALER_256,

    /* Trasmisión de 8 bits */
    .data_format = SPI_DF_8BITS,
    /* Envío de tipo MSB (Primer bit es el más significativo) */
    .transfer_format = SPI_TF_MSB,

    /* SPI Modo 3 (La memoria W25Qxx es compatible con el modo 0 y 3) */
    .mode = SPI_MODE_3
    /* También puede ser seleccionado el modo 3 de la siguiente manera: */
    // .clk_pol = SPI_CLK_POL_HIGH,
    // .clk_pha = SPI_CLK_PHA_SECOND,
};

/* Implementación de función que pone en LOW el pin SS (Slave Select) 
 * requerida por la librería Driver_W25Qxx.
 * 
 * La función tiene que ser de tipo void(void).
 */
static void W25Qxx_ss_low(void)
{
    gpio_port_clr(GPIOC, GPIO_IO9);
}

/* Implementación de función que pone en HIGH el pin SS (Slave Select) 
 * requerida por la librería Driver_W25Qxx.
 * 
 * La función tiene que ser de tipo void(void).
 */
static void W25Qxx_ss_high(void)
{
    gpio_port_set(GPIOC, GPIO_IO9);
}

/* Implementación de función que escribe y lee el periférico SPI
 * requerido por la librería Driver_W25Qxx.
 * 
 * La función tiene que ser de tipo uint8_t(uint8_t).
 * 
 * Se implementa spi_master_write_and_read_raw debido a que esta función no hace
 * uso del pin SS para controlar la comunicación SPI.
 */
static uint8_t W25Qxx_spi(uint8_t data)
{
    return (uint8_t) spi_master_write_and_read_raw(&spi, data);
}

static void board_error_handler(void)
{
    do {
        gpio_port_tgl(GPIOH, GPIO_IO11);
        delay_ms(100);
    } while (1);
}

static void board_ok_handler(void)
{
    do {
        gpio_port_tgl(GPIOH, GPIO_IO11);
        delay_ms(1000);
    } while (1);
}

int main (void)
{
    /* Fuente de reloj del MCU = Cristal externo @8 MHz */
    rcc_sysclk_select(RCC_SYSCLK_HSE);

    /* Se habilita el reloj para los periféricos que se van a usar con el SPI */
    spi_clk_en(SPI2_RCC);
    gpio_clk_en(GPIOB_RCC | GPIOC_RCC | GPIOH_RCC);

    /* Depuración (LED de la placa) */
    gpio_config_mode(GPIOH, GPIO_MODE_OUTPUT, GPIO_IO11);

    /* Inicialización del periférico SPI como maestro */
    spi_master_init(&spi);

    /* Inicialización del driver W25Qxx según el ejemplo de implementación 
     *  Se declara una variable tipo W25Qxx_ERR (Bandera de errores de comuniación)
     *  Se asigna las funciones que internamente usa el driver para la comunicación
     *   - spi_delayms de tipo void(uint32_t): Crea un retardo en milisegundos.
     *   - spi_rw de tipo uint8_t(uint8_t): Comunicación SPI (Lectura y escritura).
     *   - spi_cs_H de tipo void(void): Pone en alto el pin SS o CS.
     *   - spi_cs_L de tipo void(void): Pone en bajo el pin SS o CS.
     *  Se llama la función de inicialización W25Qxx_config.
     */
    W25Qxx_ERR err;
    W25Qxx.port.spi_delayms = delay_ms;
    W25Qxx.port.spi_rw = W25Qxx_spi;
    W25Qxx.port.spi_cs_H = W25Qxx_ss_high;
    W25Qxx.port.spi_cs_L = W25Qxx_ss_low;
    W25Qxx_config(&err);

    /* En caso de que exista un error en la inicialización, notificar mediante
     * el LED de la placa, parpadeante de manera constate y rápida (100 ms).
     */
    if (err != W25Qxx_ERR_NONE)
    {
        board_error_handler();
    }

    /* Buffers para escritura (_to_write) y lectura (_to_read) para la flash */
    uint8_t b_to_write[10] = "DSP Board";
    uint8_t b_to_read[10] = "";

    while(1)
    {
        /* Leer 10 posiciones a partir de la dirección 0 de la flash
         * y guardarlo en el buffer b_to_read.
         */
        W25Qxx_Read(b_to_read, 0x00000000, 10, &err);

        /* Comprobar si en el buffer de lectura se encuentra almacenado la 
         * cadena "DSP Board"
         */
        if (strncmp((const char *)b_to_read, (const char *)b_to_write, 10) != 0)
        {
            /* En caso de que no se encuentre almacenado, verificar si existe 
             * un error en la comunicación con la memoria flash, y reportarlo
             * en el LED de la placa mediante un parpadeo rápido (100 ms) 
             * (Y detener el flujo de programa).
             */
            if (err != W25Qxx_ERR_NONE)
            {
                board_error_handler();
            }

            /* En caso de que no exista error, se deduce que es la primera vez 
             * va a programar la flash, por tanto desde la dirección 0 de la flash
             * se escribe la cadena "DSP Board".
             */
            W25Qxx_Program(b_to_write, 0x00000000, 10, &err);

            /* Se espera que en el próximo ciclo del while se lea de nuevo la 
             * flash con la cadena ya programada, y no entre a este punto de nuevo.
             */
        }
        else
        {
            /* En caso de que si se encuentre almacenada la cadena "DSP Board" 
             * notificar mediante el LED de la placa con un parpadeo lento (1 s)
             * (Y detener el flujo de programa).
             */
            board_ok_handler();
        }
    }
}
