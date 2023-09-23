/**
 * @file i2s.h
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

#ifndef _I2S_H_
#define _I2S_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdbool.h>

#include "system.h"
#include "gpio.h"

/**
 * @addtogroup i2s I2S
 */

/**
 * @defgroup public_i2s Public
 * @ingroup i2s
 */

#define I2S1 SPI1
#define I2S2 SPI2
#define I2S3 SPI3

/*----------------------------------------------------------------------------*/
/* Enums */
/*----------------------------------------------------------------------------*/

/**
 * @ingroup public_i2s
 * @brief I2S clock mask.
 * 
 * I2S mask on RCC->APB1 & RCC->APB2
 */
typedef enum {
    I2S1_RCC = RCC_APB2ENR_SPI1EN, /*!< I2S1 enable clock mask */
    I2S2_RCC = RCC_APB1ENR_SPI2EN, /*!< I2S2 enable clock mask */
    I2S3_RCC = RCC_APB1ENR_SPI3EN  /*!< I2S3 enable clock mask */
} i2s_rcc_t;

/**
 * @ingroup public_i2s
 * @brief I2S Sampling Frequency Indexer.
 */
typedef enum {
    I2S_FREQ_8000Hz = 0,
    I2S_FREQ_16000Hz = 1,
    I2S_FREQ_32000Hz = 2,
    I2S_FREQ_48000Hz = 3,
    I2S_FREQ_96000Hz = 4,
    I2S_FREQ_22050Hz = 5,
    I2S_FREQ_44100Hz = 6,
    I2S_FREQ_192000Hz = 7
} i2s_fs_t;

/**
 * @ingroup public_i2s
 * @brief I2S clock polaraty mask.
 * 
 * I2S clock polaraty.
 * 
 * @note Clock polarity with Clock phase determinate the I2S mode
 */
typedef enum {
    I2S_MODE_SLAVE_TRASMIT = 0 << SPI_I2SCFGR_I2SCFG_Pos, /*!< I2S as Slave Trasmiter */
    I2S_MODE_SLAVE_RECEIVE = 1 << SPI_I2SCFGR_I2SCFG_Pos, /*!< I2S as Slave Receiver */
    I2S_MODE_MASTER_TRASMIT = 2 << SPI_I2SCFGR_I2SCFG_Pos, /*!< I2S as Master Trasmiter */
    I2S_MODE_MASTER_RECEIVE = 3 << SPI_I2SCFGR_I2SCFG_Pos, /*!< I2S as Master Receiver */
} i2s_mode_t;

/**
 * @ingroup public_i2s
 * @brief I2S clock polaraty mask.
 * 
 * I2S clock polaraty.
 * 
 * @note Clock polarity with Clock phase determinate the I2S mode
 */
typedef enum {
    I2S_PCM_SYNC_SHORT = 0 << SPI_I2SCFGR_PCMSYNC_Pos, /*!< PCM Short syncronization */
    I2S_PCM_SYNC_LONG = 1 << SPI_I2SCFGR_PCMSYNC_Pos /*!< PCM Long syncronization */
} i2s_pcm_sync_t;

/**
 * @ingroup public_i2s
 * @brief I2S clock polaraty mask.
 * 
 * I2S clock polaraty.
 * 
 * @note Clock polarity with Clock phase determinate the I2S mode
 */
typedef enum {
    I2S_STANDAR_I2S_PHILIPS = 0 << SPI_I2SCFGR_I2SSTD_Pos, /*!< I2S Philips standar */
    I2S_STANDAR_MSB = 1 << SPI_I2SCFGR_I2SSTD_Pos, /*!< MSB left justified standar */
    I2S_STANDAR_LSB = 2 << SPI_I2SCFGR_I2SSTD_Pos, /*!< LSB right justified standar */
    I2S_STANDAR_PCM = 3 << SPI_I2SCFGR_I2SSTD_Pos /*!< PCM standar */
} i2s_standar_t;

/**
 * @ingroup public_i2s
 * @brief I2S clock polaraty mask.
 * 
 * I2S clock polaraty.
 * 
 * @note Clock polarity with Clock phase determinate the I2S mode
 */
typedef enum {
    SPI_CK_POL_LOW = 0 << SPI_I2SCFGR_CKPOL_Pos, /*!< CK low at IDLE */
    SPI_CK_POL_HIGH = 1 << SPI_I2SCFGR_CKPOL_Pos /*!< CK high at IDLE*/
} i2s_ck_pol_t;

/**
 * @ingroup public_i2s
 * @brief I2S clock polaraty mask.
 * 
 * I2S clock polaraty.
 * 
 * @note Clock polarity with Clock phase determinate the I2S mode
 */
typedef enum {
    I2S_DATA_LEN_16bits = 0 << SPI_I2SCFGR_DATLEN_Pos, /*!< I2S 16 bits Data Length */
    I2S_DATA_LEN_24bits = 1 << SPI_I2SCFGR_DATLEN_Pos, /*!< I2S 24 bits Data Length */
    I2S_DATA_LEN_32bits = 2 << SPI_I2SCFGR_DATLEN_Pos  /*!< I2S 32 bits Data Length */
} i2s_data_len_t;

/**
 * @ingroup public_i2s
 * @brief I2S clock polaraty mask.
 * 
 * I2S clock polaraty.
 * 
 * @note Clock polarity with Clock phase determinate the I2S mode
 */
typedef enum {
    I2S_CH_LEN_16bits = 0 << SPI_I2SCFGR_CHLEN_Pos, /*!< 16 bits wide */
    I2S_CH_LEN_32bits = 1 << SPI_I2SCFGR_CHLEN_Pos  /*!< 32 bits wide*/
} i2s_ch_len_t;

/*----------------------------------------------------------------------------*/
/* Typedef */
/*----------------------------------------------------------------------------*/

typedef void (*i2s_irq_handler_t)(uint32_t*, uint8_t);

/*----------------------------------------------------------------------------*/
/* Structs */
/*----------------------------------------------------------------------------*/

/**
 * @ingroup public_i2s
 * @brief I2S Configurator.
 * 
 * General I2S configurator variable.
 * 
 */
typedef struct {
    /* Peripheral hardware configuration */
    SPI_TypeDef *i2s_p; /*!< I2S Peripheral */
    GPIO_TypeDef *gpio_i2s; /*!< GPIO of I2S */
    GPIO_TypeDef *gpio_mck; /*!< GPIO of MCK */
    gpio_io_t ws_pin; /*!< Word Select IO pin */
    gpio_io_t ck_pin; /*!< Clock IO pin */
    gpio_io_t sd_pin; /*!< Serial Data IO pin */
    gpio_io_t extSD_pin; /*!< extSD IO pin array */
    gpio_io_t mck_pin; /*!< Master Clock output IO pin array */
    bool software_ws; /*!< Software WS enable (Disabled = Hardware) */
    
    /* I2S Configuration */
    i2s_mode_t mode; /* I2S Mode */
    i2s_pcm_sync_t pcm_sync; /* PCM Sync mode */
    i2s_standar_t protocol; /* I2S Standar Protocol */
    i2s_ck_pol_t ck_pol; /* I2S CK Polarization */
    i2s_data_len_t data_length; /* I2S Data length to be transfered */
    i2s_ch_len_t channel_length; /* I2S Channel length */
    i2s_fs_t fs; /* Audio Frequency Sampling */

    /* IRQ */
    i2s_irq_handler_t tx_handler;

    /* Others */
    rcc_pllclk_t pll_clk_src;
    const float clk; /*!< Current I2S clock speed (computed at i2s_master_init) */
} i2s_t;

/*----------------------------------------------------------------------------*/
/* Functions */
/*----------------------------------------------------------------------------*/

/** ### i2s:reset
 * @ingroup public_i2s
 * @brief Reset single or multiple I2S peripheral/s.
 * 
 * Reset masked peripheral/s in RCC_APB2RSTR or RCC_APB1RSTR, 
 * This will reset ALL registers associated with the target peripheral/s.
 * 
 * @param[in] mask I2S mask to be reset.
 * 
 * @return None.
 * 
 * @note You can reset multiple I2S's at same time passing each of them with 
 *       an OR operator.
 * 
 * @see i2s_rcc_t Mask type.
 * @see rcc_rst_apb1 Internal RCC function.
 * @see rcc_rst_apb2 Internal RCC function.
 * 
 * E.g. @n
 * For one I2S peripheral reset:
 * @code
 * ...
 * // This reset I2S 1 peripheral
 * i2s_rst(SPI1_RCC);
 * ...
 * @endcode
 * For multiple I2S peripheral reset:
 * @code
 * ...
 * // This reset I2S 2 and I2S 1 peripherals
 * i2s_rst(SPI2_RCC | SPI1_RCC);
 * ...
 * @endcode
 */
void i2s_rst(i2s_rcc_t mask);

/** ### i2s:clock:enable
 * @ingroup public_i2s
 * @brief Enable single or multiple I2S peripheral/s clock.
 * 
 * Enable clock in RCC_APB2 or RCC_APB21 to masked I2S/s.
 * 
 * @param[in] mask I2S mask to be enabled.
 * 
 * @return None.
 * 
 * @note You can enable multiple I2S's at same time passing each of them with
 *       an OR operator.
 * 
 * @see i2s_rcc_t Mask type.
 * @see rcc_clk_en_apb1 Internal RCC function
 * @see rcc_clk_en_apb2 Internal RCC function
 * 
 * E.g. @n
 * For one I2S clock enable:
 * @code
 * ...
 * // This enable I2S 1 clock
 * i2s_clk_en(SPI1_RCC);
 * ...
 * @endcode
 * For multiple I2S clock enable:
 * @code
 * ...
 * // This enable I2S 2 and I2S 1 clocks
 * i2s_clk_en(SPI2_RCC | SPI1_RCC);
 * ...
 * @endcode
 */
void i2s_clk_en(i2s_rcc_t mask);

/** ### i2s:clock:enable
 * @ingroup public_i2s
 * @brief Enable single or multiple I2S peripheral/s clock.
 * 
 * Enable clock in RCC_APB2 or RCC_APB21 to masked I2S/s.
 * 
 * @param[in] mask I2S mask to be enabled.
 * 
 * @return None.
 * 
 * @note You can enable multiple I2S's at same time passing each of them with
 *       an OR operator.
 * 
 * @see i2s_rcc_t Mask type.
 * @see rcc_clk_en_apb1 Internal RCC function
 * @see rcc_clk_en_apb2 Internal RCC function
 * 
 * E.g. @n
 * For one I2S clock enable:
 * @code
 * ...
 * // This disable I2S 1 clock
 * i2s_clk_dis(SPI1_RCC);
 * ...
 * @endcode
 * For multiple I2S clock enable:
 * @code
 * ...
 * // This disable I2S 2 and I2S 1 clocks
 * i2s_clk_dis(SPI2_RCC | SPI1_RCC);
 * ...
 * @endcode
 */
void i2s_clk_dis(i2s_rcc_t mask);

/** ### i2s:master:initialization
  * @ingroup public_i2s
  * @brief Init I2S as master.
  * 
  * Configure a target .spi_p from /i2s as master with /i2s configurations.
  * Also configure a respective GPIO to work with the peripheral.
  * 
  * @param[in] i2s Address to i2s variable configurator.
  * 
  * @return None.
  * 
  * @note 1. .sck_pin, .miso_pin & .mosi_pin from /i2s must be from same GPIO 
  *          configured at .gpio_spi.
  * @note 2. .ss_pin is an array of gpio_io_t, and .ss_size must have a .ss_pin 
  *          array size
  * 
  * @see
  * 
  * E.g. @n
  * @code
  * ...
  * // This will be inicializate SPI2 as master with:
  * //   - SCK, MISO & MOSI = 15, 14, 13 GPIO pinnes from GPIOB
  * //   - SS = 10 & 9 GPIO pinnes from GPIOC (2 Slaves) controlled by software.
  * //   - Clock prescaler = 256
  * //   - 8 Bits MSB first.
  * //   - I2S standar mode = 3.
  * int main(void)
  * {
  *     i2s_clk_en(SPI2_RCC);
  * 
  *     spi_t *i2s = {
  *         .spi_p = SPI2, .gpio_spi = GPIOB, .gpio_ss = GPIOC, 
  *         .sck_pin = GPIO_IO15, .miso_pin = GPIO_IO14, .mosi_IO13, 
  *         .ss_pin = {GPIO_IO9, GPIO_IO10}, .ss_size = 2,
  *         .software_ss = true,
  *         .clk_prescaler = SPI_PRESCALER_256,
  *         .data_format = SPI_DF_8BITS,
  *         .transfer_format = SPI_TF_MSB,
  *         .mode = SPI_MODE_3
  *     }
  * 
  *     i2s_master_init(&i2s);
  * }
  * ...
  * @endcode
  */
void i2s_master_init(i2s_t *i2s);

/** ### i2s:master:write:raw
  * @ingroup public_i2s
  * @brief Execute a RAW write comand to target i2s.
  * 
  * Writes /data to DR register on .spi_p from /i2s. The data format transaction
  * will be 8 or 16 bits depending .data_format on /i2s.
  * 
  * @param[in] i2s Target I2S configuration to write.
  * @param[in] data Target data to write.
  * 
  * @return None.
  * 
  * E.g. @n
  * @code
  * ...
  * // This will RAW writes 0xA5 (8 bits) on SPI2 without SS signal.
  * // Note: By default i2s mode = 0, clk_prescaler = SPI_PRESCALER_2,
  * // .transfer_format = SPI_TF_MSB
  * int main(void)
  * {
  *     i2s_clk_en(SPI2_RCC);
  * 
  *     spi_t *i2s = {
  *         .spi_p = SPI2, .gpio_spi = GPIOB,
  *         .sck_pin = GPIO_IO15, .miso_pin = GPIO_IO14, .mosi = GPIO_IO13,
  *         .data_format = SPI_DF_8BITS
  *     }
  * 
  *     i2s_master_init(&i2s);
  *     i2s_write_raw(&i2s, 0xA5);
  *     while(1);
  * }
  * ...
  * @endcode
  */
void i2s_write_raw(i2s_t *i2s, uint16_t data);

/** ### i2s:master:write:and:read:raw
  * @ingroup public_i2s
  * @brief Execute a RAW write and read comand to target i2s.
  * 
  * Writes /data to TX DR register and returns the RX DR register on .spi_p from /i2s
  * The data format transaction will be 8 or 16 bits depending .data_format on /i2s.
  * 
  * @param[in] i2s Target I2S configuration to write and read.
  * @param[in] data Target data to write.
  * 
  * @return (uint16_t) Target I2S data readed.
  * 
  * E.g. @n
  * @code
  * ...
  * // This will RAW writes 0xA5 (8 bits) on SPI2 without SS signal and espect 
  * // an answer.
  * // Note: By default i2s mode = 0, clk_prescaler = SPI_PRESCALER_2,
  * // .transfer_format = SPI_TF_MSB
  * int main(void)
  * {
  *     // I2S data in.
  *     uint8_t spi_in;
  * 
  *     i2s_clk_en(SPI2_RCC);
  * 
  *     spi_t *i2s = {
  *         .spi_p = SPI2, .gpio_spi = GPIOB,
  *         .sck_pin = GPIO_IO15, .miso_pin = GPIO_IO14, .mosi = GPIO_IO13,
  *         .data_format = SPI_DF_8BITS
  *     }
  * 
  *     i2s_master_init(&i2s);
  * 
  *     spi_in = (uint8_t) spi_master_write_read_raw(&i2s, 0xA5);
  *     while(1);
  * }
  * ...
  * @endcode
  */
uint16_t i2s_master_write_and_read_raw(i2s_t *i2s, uint16_t data);

/** ### i2s:master:write
  * @ingroup public_i2s
  * @brief Execute a write comand to target i2s on target slave.
  * 
  * Writes /data to DR register on .spi_p from /i2s with control of target SS 
  * signal selected by /ss (indexing .ss_pin array from /i2s) by software or 
  * hardware depending of .software_ss enabler on /i2s. The data format transaction
  * will be 8 or 16 bits depending .data_format on /i2s.
  * 
  * @param[in] i2s Target I2S configuration to write.
  * @param[in] data Target data to write.
  * 
  * @return None.
  * 
  * @note Hardware SS control not implemented yet.
  * @todo Hardware SS control.
  * 
  * E.g. @n
  * @code
  * ...
  * // Note: By default i2s mode = 0, clk_prescaler = SPI_PRESCALER_2,
  * // .transfer_format = SPI_TF_MSB
  * int main(void)
  * {
  *     i2s_clk_en(SPI2_RCC);
  * 
  *     spi_t *i2s = {
  *         .spi_p = SPI2, .gpio_spi = GPIOB, .gpio_ss = GPIOC, 
  *         .sck_pin = GPIO_IO15, .miso_pin = GPIO_IO14, .mosi_IO13, 
  *         .ss_pin = {GPIO_IO9, GPIO_IO10}, .ss_size = 2
  *         .data_format = SPI_DF_8BITS
  *     }
  *     i2s_master_init(&i2s);
  * 
  *     // Write 0xA5 to SS @ GPIO_IO9
  *     spi_master_write(&i2s, 0xA5, 0);
  *     // Write 0xA6 to SS @ GPIO_IO10
  *     spi_master_write(&i2s, 0xA6, 1);
  * 
  *     while(1);
  * }
  * ...
  * @endcode
  */
void spi_master_write(i2s_t *i2s, uint16_t data, uint8_t ss);

/** ### i2s:master:write:and:read
  * @ingroup public_i2s
  * @brief Execute a write and read comand to target i2s on target slave.
  * 
  * Writes /data to TX DR register on .spi_p from /i2s with control of target SS 
  * signal selected by /ss (indexing .ss_pin array from /i2s) by software or 
  * hardware depending of .software_ss enabler on /i2s. And returns RX DR register
  * from target i2s. 
  * The data format transaction will be 8 or 16 bits depending .data_format on /i2s.
  * 
  * @param[in] i2s Target I2S configuration to write and read.
  * @param[in] data Target data to write.
  * 
  * @return (uint16_t) Target I2S data readed.
  * 
  * @note Hardware SS control not implemented yet.
  * @todo Hardware SS control.
  * 
  * E.g. @n
  * @code
  * ...
  * // Note: By default i2s mode = 0, clk_prescaler = SPI_PRESCALER_2,
  * // .transfer_format = SPI_TF_MSB
  * int main(void)
  * {
  *     // I2S data inputs.
  *     uint8_t spi_in_0, spi_in_1;
  * 
  *     i2s_clk_en(SPI2_RCC);
  * 
  *     spi_t *i2s = {
  *         .spi_p = SPI2, .gpio_spi = GPIOB, .gpio_ss = GPIOC, 
  *         .sck_pin = GPIO_IO15, .miso_pin = GPIO_IO14, .mosi_IO13, 
  *         .ss_pin = {GPIO_IO9, GPIO_IO10}, .ss_size = 2
  *         .data_format = SPI_DF_8BITS
  *     }
  * 
  *     i2s_master_init(&i2s);
  * 
  *     // Write 0xA5 to SS @ GPIO_IO9 (Expect an answer)
  *     spi_in_0 = (uint8_t) spi_master_write(&i2s, 0xA5, 0);
  *     // Write 0xA6 to SS @ GPIO_IO10 (Expect an answer)
  *     spi_in_1 = (uint8_t) spi_master_write(&i2s, 0xA6, 1);
  * 
  *     while(1);
  * }
  * ...
  * @endcode
  */
uint16_t spi_master_write_and_read(i2s_t *i2s, uint16_t data, uint8_t ss);


void i2s_irq_setup(i2s_t *i2s);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _I2S_H_ */