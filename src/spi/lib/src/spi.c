/**
 * @file spi.c
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief SPI - Custom HAL for DSP Board SDK.
 * @version d0.1
 * @date 2023-03-29
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


#include "spi.h"

#include "rcc.h"
#include "gpio.h"

/**
 * @defgroup private_spi Private
 * @ingroup spi
 */

#if SPI_ENABLE_WARNING == 1
#warning "The SPI_SS_MAX_SIZE is not defined \
by default it will be defined as 4, if you have larger size of SS pines please \
define SPI_SS_MAX_SIZE at extra defines section on user.mk file"
#endif

void spi_rst(spi_rcc_t mask)
{
    if ((mask & SPI1_RCC) == SPI1_RCC)
    {
        rcc_rst_apb2(SPI1_RCC);
        mask &= ~SPI1_RCC;
        
        if(mask == 0)
            return;
    }
    rcc_rst_apb1((rcc_apb1_t) mask);
}

void spi_clk_en(spi_rcc_t mask)
{
    if ((mask & SPI1_RCC) == SPI1_RCC)
    {
        rcc_rst_apb2(SPI1_RCC);
        rcc_clk_en_apb2(SPI1_RCC);
        mask &= ~SPI1_RCC;
        
        if(mask == 0)
            return;
    }
    rcc_rst_apb1((rcc_apb1_t) mask);
    rcc_clk_en_apb1((rcc_apb1_t) mask);
}

void spi_clk_dis(spi_rcc_t mask)
{
    if ((mask & SPI1_RCC) == SPI1_RCC)
    {
        rcc_clk_dis_apb2(SPI1_RCC);
        mask &= ~SPI1_RCC;
        
        if(mask == 0)
            return;
    }
    rcc_clk_dis_apb1((rcc_apb1_t) mask);
}

/** ### spi:gpio:configure
  * @ingroup private_spi
  * @brief Configure GPIO from /spi configurator.
  * 
  * Enable GPIO's to work with SPI peripheral. This will configure
  * .gpio_spi with pinnes masked at .sck_pin, .miso_pin & .mosi_pin as
  * correspondig alternate function. Also configure .gpio_ss with pinnes masked
  * at .ss_pin array of .ss_size to work as sotfware or hardware SS controllers.
  * 
  * @param[in] spi Address to target spi configurator.
  * 
  * @return None.
  * 
  * @note SS Hardware configurator is not implemented yet.
  * @todo SS Hardware configurator.
  * 
  * E.g. @n
  * @code
  * ...
  * // This will be configure:
  * //   - SCK, MISO & MOSI = 15, 14, 13 GPIO pinnes from GPIOB
  * //   - SS = 10 & 9 GPIO pinnes from GPIOC (2 Slaves) controlled by software.
  * int main(void)
  * {
  *     spi_t *spi = {
  *         .gpio_spi = GPIOB, .gpio_ss = GPIOC, 
  *         .sck_pin = GPIO_IO15, .miso_pin = GPIO_IO14, .mosi_IO13, 
  *         .ss_pin = {GPIO_IO9, GPIO_IO10} .ss_size = 2
  *     }
  *     spi_gpio_config(&spi);
  * }
  * ...
  * @endcode
  */
void spi_gpio_config(spi_t *spi)
{
    /* Output configuration (MOSI & SCK) */
    gpio_config_all(
        spi->gpio_spi, 
        GPIO_CONFIG_MODE_ALTERNATE | GPIO_CONFIG_OUTPUT_PP | GPIO_CONFIG_SPEED_VHIGH,
        spi->mosi_pin | spi->sck_pin
    );

    /* Input configuration (MISO) */
    gpio_config_all(
        spi->gpio_spi, 
        GPIO_CONFIG_MODE_ALTERNATE | GPIO_CONFIG_PULL_UP,
        spi->miso_pin
    );

    /* Enable SPI alternate function at GPIO */
    gpio_config_af(
        spi->gpio_spi, GPIO_ALT_AF5, 
        spi->sck_pin | spi->miso_pin | spi->mosi_pin
    );

    /* Configure NSS */
    gpio_io_t ss_pines = 0;
    for (uint8_t i = 0; i < spi->ss_size; i++)
    {
        ss_pines |= spi->ss_pin[i];
    }
    if (spi->software_ss)
    {
        gpio_config_all(
            spi->gpio_ss, 
            GPIO_CONFIG_MODE_OUTPUT | GPIO_CONFIG_SPEED_HIGH,
            ss_pines
        );
        gpio_port_set(spi->gpio_ss, ss_pines);
    }
    else
    {
        // TODO: Hardware implementation
    }
}

void spi_master_init(spi_t *spi)
{
    spi_gpio_config(spi);
    spi->spi_p->CR1 = 
        spi->transfer_format | spi->data_format | spi->clk_pha | spi->clk_pol
      | spi->mode |spi->clk_prescaler;

    if(spi->software_ss)
    {
        /* If required enable software SS control */
        spi->spi_p->CR1 |= SPI_CR1_SSM | SPI_CR1_SSI;
    }
    else
    {
        /* TODO: SS hardware configuration */
    }
    spi->spi_p->CR1 |= SPI_CR1_MSTR;

    spi->spi_p->CR2 = 0;
    spi->spi_p->CR1 |= SPI_CR1_SPE;

    /* Compute spi clk */
    const uint16_t lockup_prescaler[] = {2, 4, 8, 16, 32, 64, 128, 256};
    const uint8_t i = spi->clk_prescaler >> SPI_CR1_BR_Pos;

    float *clk = (float *) &(spi->clk);
    *clk = rcc_clk_get_apb1() / lockup_prescaler[i];
}

void spi_master_write_raw(spi_t *spi, uint16_t data)
{
    /* Set data to transfer at DR register */
    spi->spi_p->DR = data;
    /* Wait until DR is empty & SPI transaction is done*/
    while(!(spi->spi_p->SR & SPI_SR_TXE) || (spi->spi_p->SR & SPI_SR_BSY));
}

uint16_t spi_master_write_and_read_raw(spi_t *spi, uint16_t data)
{
    /* Set data to transfer at DR register */
    spi->spi_p->DR = data;
    
    /* Wait until:
     *  TX DR is empty
     *  RX DR is full
     *  SPI transaction is done.
     */
    while( !(spi->spi_p->SR & SPI_SR_TXE) 
        || !(spi->spi_p->SR & SPI_SR_RXNE) || (spi->spi_p->SR & SPI_SR_BSY));
    
    /* Retrun readed data */
    return (uint16_t) spi->spi_p->DR;
}

void spi_master_write(spi_t *spi, uint16_t data, uint8_t ss)
{
    if(spi->software_ss)
    {
        /* Start comunication */
        gpio_port_clr(spi->gpio_ss, spi->ss_pin[ss]);
        /* Write data to spi */
        spi_master_write_raw(spi, data);
        /* Stop comunication */
        gpio_port_set(spi->gpio_ss, spi->ss_pin[ss]);
    }
    else
    {
        /* TODO: Hardware implementation */
    }
}

uint16_t spi_master_write_and_read(spi_t *spi, uint16_t data, uint8_t ss)
{
    uint16_t in;
    if(spi->software_ss)
    {
        /* Start comunication */
        gpio_port_clr(spi->gpio_ss, spi->ss_pin[ss]);
        /* write and read data on spi */
        in = spi_master_write_and_read_raw(spi, data);
        /* Stop comunication */
        gpio_port_set(spi->gpio_ss, spi->ss_pin[ss]);
    }
    else
    {
        /* TODO: Hardware implementation */
        in = 0;
    }
    return in;
}