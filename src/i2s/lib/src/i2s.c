/**
 * @file i2s.c
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief I2S - Custom HAL for DSP Board SDK.
 * @version d0.1
 * @date 2023-04-03
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


#include "i2s.h"

#include "rcc.h"
#include "gpio.h"

/**
 * @defgroup private_i2s Private
 * @ingroup i2s
 */

typedef struct i2s_config_lockup_s {
    float pll_freq;
    uint8_t i2s_div;
    uint8_t i2s_odd;
} i2s_config_lockup_t;

i2s_config_lockup_t i2s_config [] =
{
    /* 16 bits */
     [0] = {.pll_freq =  96000000.0f, .i2s_div = 187, .i2s_odd = 1},
     [1] = {.pll_freq =  64000000.0f, .i2s_div =  62, .i2s_odd = 1},
     [2] = {.pll_freq = 128000000.0f, .i2s_div =  62, .i2s_odd = 1},
     [3] = {.pll_freq =  38400000.0f, .i2s_div =  12, .i2s_odd = 1},
     [4] = {.pll_freq =  76800000.0f, .i2s_div =  12, .i2s_odd = 1},
     [5] = {.pll_freq =  96666667.0f, .i2s_div =  68, .i2s_odd = 1},
     [6] = {.pll_freq = 151000000.0f, .i2s_div =  53, .i2s_odd = 1},
     [7] = {.pll_freq = 141333333.0f, .i2s_div =  11, .i2s_odd = 1},
    
    /* 32 bits */
     [8] = {.pll_freq =  64000000.0f, .i2s_div = 62, .i2s_odd = 1},
     [9] = {.pll_freq = 128000000.0f, .i2s_div = 62, .i2s_odd = 1},
    [10] = {.pll_freq = 512000000.0f, .i2s_div = 12, .i2s_odd = 1},
    [11] = {.pll_freq =  76800000.0f, .i2s_div = 12, .i2s_odd = 1},
    [12] = {.pll_freq = 141333333.0f, .i2s_div = 11, .i2s_odd = 1},
    [13] = {.pll_freq = 151000000.0f, .i2s_div = 53, .i2s_odd = 1},
    [14] = {.pll_freq = 107250000.0f, .i2s_div = 19, .i2s_odd = 0},
    [15] = {.pll_freq =  86000000.0f, .i2s_div =  3, .i2s_odd = 1},
};

i2s_irq_handler_t i2s_tx_handler[3] = {NULL};

void i2s_rst(i2s_rcc_t mask)
{
    if ((mask & I2S1_RCC) == I2S1_RCC)
    {
        rcc_rst_apb2(I2S1_RCC);
        mask &= ~I2S1_RCC;
        
        if(mask == 0)
            return;
    }
    rcc_rst_apb1((rcc_apb1_t) mask);
}

void i2s_clk_en(i2s_rcc_t mask)
{
    if ((mask & I2S1_RCC) == I2S1_RCC)
    {
        rcc_rst_apb2(I2S1_RCC);
        rcc_clk_en_apb2(I2S1_RCC);
        mask &= ~I2S1_RCC;
        
        if(mask == 0)
            return;
    }
    rcc_rst_apb1((rcc_apb1_t) mask);
    rcc_clk_en_apb1((rcc_apb1_t) mask);
}

void i2s_clk_dis(i2s_rcc_t mask)
{
    if ((mask & I2S1_RCC) == I2S1_RCC)
    {
        rcc_clk_dis_apb2(I2S1_RCC);
        mask &= ~I2S1_RCC;
        
        if(mask == 0)
            return;
    }
    rcc_clk_dis_apb1((rcc_apb1_t) mask);
}

/** ### i2s:gpio:configure
  * @ingroup private_spi
  * @brief Configure GPIO from /i2s configurator.
  * 
  * Enable GPIO's to work with SPI peripheral. This will configure
  * .gpio_spi with pinnes masked at .sck_pin, .miso_pin & .mosi_pin as
  * correspondig alternate function. Also configure .gpio_ss with pinnes masked
  * at .ss_pin array of .ss_size to work as sotfware or hardware SS controllers.
  * 
  * @param[in] i2s Address to target i2s configurator.
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
  *     i2s_t *i2s = {
  *         .gpio_spi = GPIOB, .gpio_ss = GPIOC, 
  *         .sck_pin = GPIO_IO15, .miso_pin = GPIO_IO14, .mosi_IO13, 
  *         .ss_pin = {GPIO_IO9, GPIO_IO10} .ss_size = 2
  *     }
  *     spi_gpio_config(&i2s);
  * }
  * ...
  * @endcode
  */
void i2s_gpio_config(i2s_t *i2s)
{
    gpio_alt_t gpio_target_af;

    if(i2s->i2s_p == I2S1)
        gpio_target_af = GPIO_ALT_AF6;
    else
        gpio_target_af = GPIO_ALT_AF5;

    /* Enable I2S alternate function at GPIO */
    gpio_config_af(
        i2s->gpio_i2s, gpio_target_af, 
        i2s->sd_pin | i2s->ck_pin | i2s->extSD_pin
    );

    /* Output configuration (SD, CK, extSD) */
    gpio_config_all(
        i2s->gpio_i2s, 
        GPIO_CONFIG_MODE_ALTERNATE | GPIO_CONFIG_OUTPUT_PP | GPIO_CONFIG_SPEED_HIGH,
        i2s->sd_pin | i2s->ck_pin | i2s->extSD_pin
    );

    /* Check if Master clock pin is configured */
    if (i2s->mck_pin != 0)
    {
        gpio_config_af(
            i2s->gpio_mck, gpio_target_af, 
            i2s->mck_pin
        );
        gpio_config_all(
            i2s->gpio_mck, 
            GPIO_CONFIG_MODE_ALTERNATE | GPIO_CONFIG_OUTPUT_PP | GPIO_CONFIG_SPEED_VHIGH,
            i2s->mck_pin
        );
    }

    if (i2s->software_ws)
    {
        gpio_config_all(
            i2s->gpio_i2s, 
            GPIO_CONFIG_MODE_OUTPUT | GPIO_CONFIG_SPEED_MEDIUM,
            i2s->ws_pin
        );
        gpio_port_set(i2s->gpio_i2s, i2s->ws_pin);
    }
    else
    {
        gpio_config_af(
            i2s->gpio_i2s, gpio_target_af, 
            i2s->ws_pin
        );
        gpio_config_all(
            i2s->gpio_i2s, 
            GPIO_CONFIG_MODE_ALTERNATE | GPIO_CONFIG_OUTPUT_PP | GPIO_CONFIG_SPEED_MEDIUM,
            i2s->ws_pin
        );
    }
}

void i2s_master_init(i2s_t *i2s)
{
    i2s_gpio_config(i2s);
    uint8_t indexer = (uint8_t) i2s->fs;

    if((i2s->channel_length == I2S_CH_LEN_32bits) 
        || (i2s->data_length > I2S_DATA_LEN_16bits))
    {
        /* Indexer to 32 bits */
        indexer += 8;
    }

    /* Get target clock configurations */
    float pll_target_freq = i2s_config[indexer].pll_freq;
    uint8_t i2s_target_div = i2s_config[indexer].i2s_div;
    uint8_t i2s_target_odd = i2s_config[indexer].i2s_odd;

    /* Compute, set and power on the I2S PLL Clock */
    rcc_pll_i2s_param_cpte_set(pll_target_freq, i2s->pll_clk_src);
    rcc_pll_i2s_power_on();

    if (i2s->mck_pin != 0)
        i2s->i2s_p->I2SPR = SPI_I2SPR_MCKOE;

    i2s->i2s_p->I2SPR = i2s_target_odd | i2s_target_div;
    i2s->i2s_p->I2SCFGR = SPI_I2SCFGR_I2SMOD | i2s->data_length | i2s->channel_length 
        | i2s->ck_pol | i2s->pcm_sync | i2s->protocol | i2s->mode;

    i2s->i2s_p->I2SCFGR |= SPI_I2SCFGR_I2SE;
}

void i2s_write_raw(i2s_t *i2s, uint16_t data)
{
    /* Set data to transfer at DR register */
    i2s->i2s_p->DR = data;
    /* Wait until DR is empty & SPI transaction is done*/
    while(!(i2s->i2s_p->SR & SPI_SR_TXE) || (i2s->i2s_p->SR & SPI_SR_BSY));
}

uint16_t i2s_master_write_and_read_raw(i2s_t *i2s, uint16_t data)
{
    /* Set data to transfer at DR register */
    i2s->i2s_p->DR = data;
    
    /* Wait until:
     *  TX DR is empty
     *  RX DR is full
     *  SPI transaction is done.
     */
    while( !(i2s->i2s_p->SR & SPI_SR_TXE) 
        || !(i2s->i2s_p->SR & SPI_SR_RXNE) || (i2s->i2s_p->SR & SPI_SR_BSY));
    
    /* Retrun readed data */
    return (uint16_t) i2s->i2s_p->DR;
}

void spi_master_write(i2s_t *i2s, uint16_t data, uint8_t ss)
{
    // if(i2s->software_ss)
    // {
    //     /* Start comunication */
    //     gpio_port_clr(i2s->gpio_ss, i2s->ss_pin[ss]);
    //     /* Write data to i2s */
    //     i2s_write_raw(i2s, data);
    //     /* Stop comunication */
    //     gpio_port_set(i2s->gpio_ss, i2s->ss_pin[ss]);
    // }
    // else
    // {
    //     /* TODO: Hardware implementation */
    // }
}

uint16_t spi_master_write_and_read(i2s_t *i2s, uint16_t data, uint8_t ss)
{
    uint16_t in = 0;
    // if(i2s->software_ss)
    // {
    //     /* Start comunication */
    //     gpio_port_clr(i2s->gpio_ss, i2s->ss_pin[ss]);
    //     /* write and read data on i2s */
    //     in = i2s_master_write_and_read_raw(i2s, data);
    //     /* Stop comunication */
    //     gpio_port_set(i2s->gpio_ss, i2s->ss_pin[ss]);
    // }
    // else
    // {
    //     /* TODO: Hardware implementation */
    //     in = 0;
    // }
    return in;
}

bool is_greater_16bits[3] = {false};

void i2s_irq_setup(i2s_t *i2s)
{
    IRQn_Type irq_index;
    uint8_t i2s_index;
    switch((uint32_t) i2s->i2s_p)
    {
        case (uint32_t) I2S1:
            irq_index = SPI1_IRQn;
            i2s_index = 0;
            break;
        case (uint32_t) I2S2:
            irq_index = SPI2_IRQn;
            i2s_index = 1;
            break;
        case (uint32_t) I2S3:
            irq_index = SPI3_IRQn;
            i2s_index = 2;
            break;
        default:
            return;
    }

    i2s_tx_handler[i2s_index] = i2s->tx_handler;
    if((i2s->channel_length == I2S_CH_LEN_32bits) 
        || (i2s->data_length > I2S_DATA_LEN_16bits))
    {
        is_greater_16bits[i2s_index] = true;
    }

    i2s->i2s_p->CR2 |= SPI_CR2_TXEIE;
    NVIC_EnableIRQ(irq_index);
    NVIC_SetPendingIRQ(irq_index);
}

void SPI2_IRQHandler(void)
{
    uint8_t ch = (SPI2->SR & SPI_SR_CHSIDE) >> SPI_SR_CHSIDE_Pos;
    static bool half = false;

    if(i2s_tx_handler[1] != NULL)
    {
        uint32_t dr;
        i2s_tx_handler[1](&dr, ch);

        if(is_greater_16bits[1])
        {
            dr = half ? (dr >> 8) : (dr << 8);
            half ^= true;
        }
        SPI2->DR = (uint16_t) dr;
    }
}