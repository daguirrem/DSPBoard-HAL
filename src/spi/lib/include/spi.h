/**
 * @file spi.h
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief ADC - Custom HAL for DSP Board SDK.
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

#ifndef _SPI_H_
#define _SPI_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdbool.h>

#include "system.h"
#include "gpio.h"

/**
 * @addtogroup spi SPI
 */

/**
 * @defgroup public_spi Public
 * @ingroup spi
 */

#ifndef SPI_SS_MAX_SIZE
#define SPI_SS_MAX_SIZE 4 /*!< SPI slave select max pinnes (size) */
#define SPI_ENABLE_WARNING 1 /*!< Enable warning of undefined SPI_SS_MAX_SIZE at 
                                  compile time */
#endif

/*----------------------------------------------------------------------------*/
/* Enums */
/*----------------------------------------------------------------------------*/

/**
 * @ingroup public_spi
 * @brief SPI clock mask.
 * 
 * SPI mask on RCC->APB1 & RCC->APB2
 */
typedef enum {
    SPI1_RCC = RCC_APB2ENR_SPI1EN, /*!< GPIOA enable clock mask */
    SPI2_RCC = RCC_APB1ENR_SPI2EN, /*!< GPIOB enable clock mask */
    SPI3_RCC = RCC_APB1ENR_SPI3EN, /*!< GPIOC enable clock mask */
} spi_rcc_t;

/**
 * @ingroup public_spi
 * @brief SPI Baud control mask.
 * 
 * SPI Baud control prescalers (From 2 to 256).
 */
typedef enum {
    SPI_PRESCALER_2 = 0 << SPI_CR1_BR_Pos, /*!< SPI Clock = f_{PCLK}/2 */
    SPI_PRESCALER_4 = 1 << SPI_CR1_BR_Pos, /*!< SPI Clock = f_{PCLK}/4 */
    SPI_PRESCALER_8 = 2 << SPI_CR1_BR_Pos, /*!< SPI Clock = f_{PCLK}/8 */
    SPI_PRESCALER_16 = 3 << SPI_CR1_BR_Pos, /*!< SPI Clock = f_{PCLK}/16 */
    SPI_PRESCALER_32 = 4 << SPI_CR1_BR_Pos, /*!< SPI Clock = f_{PCLK}/32 */
    SPI_PRESCALER_64 = 5 << SPI_CR1_BR_Pos, /*!< SPI Clock = f_{PCLK}/64 */
    SPI_PRESCALER_128 = 6 << SPI_CR1_BR_Pos, /*!< SPI Clock = f_{PCLK}/128 */
    SPI_PRESCALER_256 = 7 << SPI_CR1_BR_Pos /*!< SPI Clock = f_{PCLK}/256 */
} spi_prescaler_t;

/**
 * @ingroup public_spi
 * @brief SPI Data Format mask.
 * 
 * SPI data formats (8 or 16 bit).
 */
typedef enum {
    SPI_DF_8BITS = 0 << SPI_CR1_DFF_Pos, /*!< SPI 8 Bits data format */
    SPI_DF_16BITS = 1 << SPI_CR1_DFF_Pos /*!< SPI 16 bits data format */
} spi_df_t;

/**
 * @ingroup public_spi
 * @brief SPI Trasnfer Format mask.
 * 
 * SPI trasfer formats (MSB or LSB first).
 */
typedef enum {
    SPI_TF_MSB = 0 << SPI_CR1_DFF_Pos, /*!< MSB Trasmited first */
    SPI_TF_LSB = 1 << SPI_CR1_DFF_Pos /*!< LSB Trasmited first */
} spi_tf_t;

/**
 * @ingroup public_spi
 * @brief SPI clock polaraty mask.
 * 
 * SPI clock polaraty.
 * 
 * @note Clock polarity with Clock phase determinate the SPI mode
 */
typedef enum {
    SPI_CLK_POL_LOW = 0 << SPI_CR1_CPOL_Pos, /*!< CLK low at IDLE */
    SPI_CLK_POL_HIGH = 1 << SPI_CR1_CPOL_Pos /*!< CLK high at IDLE*/
} spi_clk_pol_t;

/**
 * @ingroup public_spi
 * @brief SPI clock phase mask.
 * 
 * SPI clock phase.
 * 
 * @note Clock polarity with Clock phase determinate the SPI MODE
 */
typedef enum {
    SPI_CLK_PHA_FIRST = 0 << SPI_CR1_CPHA_Pos, /*!< Data at first clk transition */
    SPI_CLK_PHA_SECOND = 1 << SPI_CR1_CPHA_Pos /*!< Data at second clk transition */
} spi_clk_pha_t;

/**
 * @ingroup public_spi
 * @brief SPI modes.
 * 
 * Standar SPI modes.
 */
typedef enum {
    SPI_MODE_0 = SPI_CLK_POL_LOW | SPI_CLK_PHA_FIRST, /*!< SPI Mode 0 */
    SPI_MODE_1 = SPI_CLK_POL_LOW | SPI_CLK_PHA_SECOND, /*!< SPI Mode 1 */
    SPI_MODE_2 = SPI_CLK_POL_HIGH | SPI_CLK_PHA_FIRST, /*!< SPI Mode 2 */
    SPI_MODE_3 = SPI_CLK_POL_HIGH | SPI_CLK_PHA_SECOND, /*!< SPI Mode 3 */
} spi_mode_t;

/*----------------------------------------------------------------------------*/
/* Structs */
/*----------------------------------------------------------------------------*/

/**
 * @ingroup public_spi
 * @brief SPI Configurator.
 * 
 * General SPI configurator variable.
 * 
 * @note Static size of ss_size is defined by SPI_SS_MAX_SIZE, by default de max
 *       size is 4. (Define this macro to get different value).
 */
typedef struct {
    /* Peripheral hardware configuration */
    SPI_TypeDef *spi_p; /*!< SPI Peripheral */
    GPIO_TypeDef *gpio_spi; /*!< GPIO of SPI */
    GPIO_TypeDef *gpio_ss; /*!< GPIO of Slave Select Pin */
    gpio_io_t sck_pin; /*!< Clock IO pin */
    gpio_io_t miso_pin; /*!< MISO IO pin */
    gpio_io_t mosi_pin; /*!< MOSI IO pin */
    gpio_io_t ss_pin[SPI_SS_MAX_SIZE]; /*!< Slave Select IO pin array */
    uint8_t ss_size; /*!< Size pinnes configured on .ss_pin */
    bool software_ss; /*!< Software SS enable (Disabled = Hardware) */

    /* SPI Configuration */
    spi_df_t data_format; /*!< SPI Data format */
    spi_tf_t transfer_format; /*!< SPI Trans format */
    spi_clk_pol_t clk_pol; /*!< SPI clock polarization */
    spi_clk_pha_t clk_pha; /*!< SPI clock phase */
    spi_mode_t mode; /*!< SPI modes */
    spi_prescaler_t clk_prescaler; /*!< SPI Clock prescaler */

    /* Others */
    const float clk; /*!< Current SPI clock speed (computed at spi_master_init) */
} spi_t;

/*----------------------------------------------------------------------------*/
/* Functions */
/*----------------------------------------------------------------------------*/

/** ### spi:reset
 * @ingroup public_spi
 * @brief Reset single or multiple SPI peripheral/s.
 * 
 * Reset masked peripheral/s in RCC_APB2RSTR or RCC_APB1RSTR, 
 * This will reset ALL registers associated with the target peripheral/s.
 * 
 * @param[in] mask SPI mask to be reset.
 * 
 * @return None.
 * 
 * @note You can reset multiple SPI's at same time passing each of them with 
 *       an OR operator.
 * 
 * @see spi_rcc_t Mask type.
 * @see rcc_rst_apb1 Internal RCC function.
 * @see rcc_rst_apb2 Internal RCC function.
 * 
 * E.g. @n
 * For one SPI peripheral reset:
 * @code
 * ...
 * // This reset SPI 1 peripheral
 * spi_rst(SPI1_RCC);
 * ...
 * @endcode
 * For multiple SPI peripheral reset:
 * @code
 * ...
 * // This reset SPI 2 and SPI 1 peripherals
 * spi_rst(SPI2_RCC | SPI1_RCC);
 * ...
 * @endcode
 */
void spi_rst(spi_rcc_t mask);

/** ### spi:clock:enable
 * @ingroup public_spi
 * @brief Enable single or multiple SPI peripheral/s clock.
 * 
 * Enable clock in RCC_APB2 or RCC_APB21 to masked SPI/s.
 * 
 * @param[in] mask SPI mask to be enabled.
 * 
 * @return None.
 * 
 * @note You can enable multiple SPI's at same time passing each of them with
 *       an OR operator.
 * 
 * @see spi_rcc_t Mask type.
 * @see rcc_clk_en_apb1 Internal RCC function
 * @see rcc_clk_en_apb2 Internal RCC function
 * 
 * E.g. @n
 * For one SPI clock enable:
 * @code
 * ...
 * // This enable SPI 1 clock
 * spi_clk_en(SPI1_RCC);
 * ...
 * @endcode
 * For multiple SPI clock enable:
 * @code
 * ...
 * // This enable SPI 2 and SPI 1 clocks
 * spi_clk_en(SPI2_RCC | SPI1_RCC);
 * ...
 * @endcode
 */
void spi_clk_en(spi_rcc_t mask);

/** ### spi:clock:enable
 * @ingroup public_spi
 * @brief Enable single or multiple SPI peripheral/s clock.
 * 
 * Enable clock in RCC_APB2 or RCC_APB21 to masked SPI/s.
 * 
 * @param[in] mask SPI mask to be enabled.
 * 
 * @return None.
 * 
 * @note You can enable multiple SPI's at same time passing each of them with
 *       an OR operator.
 * 
 * @see spi_rcc_t Mask type.
 * @see rcc_clk_en_apb1 Internal RCC function
 * @see rcc_clk_en_apb2 Internal RCC function
 * 
 * E.g. @n
 * For one SPI clock enable:
 * @code
 * ...
 * // This disable SPI 1 clock
 * spi_clk_dis(SPI1_RCC);
 * ...
 * @endcode
 * For multiple SPI clock enable:
 * @code
 * ...
 * // This disable SPI 2 and SPI 1 clocks
 * spi_clk_dis(SPI2_RCC | SPI1_RCC);
 * ...
 * @endcode
 */
void spi_clk_dis(spi_rcc_t mask);

/** ### spi:master:initialization
  * @ingroup public_spi
  * @brief Init SPI as master.
  * 
  * Configure a target .spi_p from /spi as master with /spi configurations.
  * Also configure a respective GPIO to work with the peripheral.
  * 
  * @param[in] spi Address to spi variable configurator.
  * 
  * @return None.
  * 
  * @note 1. .sck_pin, .miso_pin & .mosi_pin from /spi must be from same GPIO 
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
  * //   - SPI standar mode = 3.
  * int main(void)
  * {
  *     spi_clk_en(SPI2_RCC);
  * 
  *     spi_t *spi = {
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
  *     spi_master_init(&spi);
  * }
  * ...
  * @endcode
  */
void spi_master_init(spi_t *spi);

/** ### spi:master:write:raw
  * @ingroup public_spi
  * @brief Execute a RAW write comand to target spi.
  * 
  * Writes /data to DR register on .spi_p from /spi. The data format transaction
  * will be 8 or 16 bits depending .data_format on /spi.
  * 
  * @param[in] spi Target SPI configuration to write.
  * @param[in] data Target data to write.
  * 
  * @return None.
  * 
  * E.g. @n
  * @code
  * ...
  * // This will RAW writes 0xA5 (8 bits) on SPI2 without SS signal.
  * // Note: By default spi mode = 0, clk_prescaler = SPI_PRESCALER_2,
  * // .transfer_format = SPI_TF_MSB
  * int main(void)
  * {
  *     spi_clk_en(SPI2_RCC);
  * 
  *     spi_t *spi = {
  *         .spi_p = SPI2, .gpio_spi = GPIOB,
  *         .sck_pin = GPIO_IO15, .miso_pin = GPIO_IO14, .mosi = GPIO_IO13,
  *         .data_format = SPI_DF_8BITS
  *     }
  * 
  *     spi_master_init(&spi);
  *     spi_master_write_raw(&spi, 0xA5);
  *     while(1);
  * }
  * ...
  * @endcode
  */
void spi_master_write_raw(spi_t *spi, uint16_t data);

/** ### spi:master:write:and:read:raw
  * @ingroup public_spi
  * @brief Execute a RAW write and read comand to target spi.
  * 
  * Writes /data to TX DR register and returns the RX DR register on .spi_p from /spi
  * The data format transaction will be 8 or 16 bits depending .data_format on /spi.
  * 
  * @param[in] spi Target SPI configuration to write and read.
  * @param[in] data Target data to write.
  * 
  * @return (uint16_t) Target SPI data readed.
  * 
  * E.g. @n
  * @code
  * ...
  * // This will RAW writes 0xA5 (8 bits) on SPI2 without SS signal and espect 
  * // an answer.
  * // Note: By default spi mode = 0, clk_prescaler = SPI_PRESCALER_2,
  * // .transfer_format = SPI_TF_MSB
  * int main(void)
  * {
  *     // SPI data in.
  *     uint8_t spi_in;
  * 
  *     spi_clk_en(SPI2_RCC);
  * 
  *     spi_t *spi = {
  *         .spi_p = SPI2, .gpio_spi = GPIOB,
  *         .sck_pin = GPIO_IO15, .miso_pin = GPIO_IO14, .mosi = GPIO_IO13,
  *         .data_format = SPI_DF_8BITS
  *     }
  * 
  *     spi_master_init(&spi);
  * 
  *     spi_in = (uint8_t) spi_master_write_read_raw(&spi, 0xA5);
  *     while(1);
  * }
  * ...
  * @endcode
  */
uint16_t spi_master_write_and_read_raw(spi_t *spi, uint16_t data);

/** ### spi:master:write
  * @ingroup public_spi
  * @brief Execute a write comand to target spi on target slave.
  * 
  * Writes /data to DR register on .spi_p from /spi with control of target SS 
  * signal selected by /ss (indexing .ss_pin array from /spi) by software or 
  * hardware depending of .software_ss enabler on /spi. The data format transaction
  * will be 8 or 16 bits depending .data_format on /spi.
  * 
  * @param[in] spi Target SPI configuration to write.
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
  * // Note: By default spi mode = 0, clk_prescaler = SPI_PRESCALER_2,
  * // .transfer_format = SPI_TF_MSB
  * int main(void)
  * {
  *     spi_clk_en(SPI2_RCC);
  * 
  *     spi_t *spi = {
  *         .spi_p = SPI2, .gpio_spi = GPIOB, .gpio_ss = GPIOC, 
  *         .sck_pin = GPIO_IO15, .miso_pin = GPIO_IO14, .mosi_IO13, 
  *         .ss_pin = {GPIO_IO9, GPIO_IO10}, .ss_size = 2
  *         .data_format = SPI_DF_8BITS
  *     }
  *     spi_master_init(&spi);
  * 
  *     // Write 0xA5 to SS @ GPIO_IO9
  *     spi_master_write(&spi, 0xA5, 0);
  *     // Write 0xA6 to SS @ GPIO_IO10
  *     spi_master_write(&spi, 0xA6, 1);
  * 
  *     while(1);
  * }
  * ...
  * @endcode
  */
void spi_master_write(spi_t *spi, uint16_t data, uint8_t ss);

/** ### spi:master:write:and:read
  * @ingroup public_spi
  * @brief Execute a write and read comand to target spi on target slave.
  * 
  * Writes /data to TX DR register on .spi_p from /spi with control of target SS 
  * signal selected by /ss (indexing .ss_pin array from /spi) by software or 
  * hardware depending of .software_ss enabler on /spi. And returns RX DR register
  * from target spi. 
  * The data format transaction will be 8 or 16 bits depending .data_format on /spi.
  * 
  * @param[in] spi Target SPI configuration to write and read.
  * @param[in] data Target data to write.
  * 
  * @return (uint16_t) Target SPI data readed.
  * 
  * @note Hardware SS control not implemented yet.
  * @todo Hardware SS control.
  * 
  * E.g. @n
  * @code
  * ...
  * // Note: By default spi mode = 0, clk_prescaler = SPI_PRESCALER_2,
  * // .transfer_format = SPI_TF_MSB
  * int main(void)
  * {
  *     // SPI data inputs.
  *     uint8_t spi_in_0, spi_in_1;
  * 
  *     spi_clk_en(SPI2_RCC);
  * 
  *     spi_t *spi = {
  *         .spi_p = SPI2, .gpio_spi = GPIOB, .gpio_ss = GPIOC, 
  *         .sck_pin = GPIO_IO15, .miso_pin = GPIO_IO14, .mosi_IO13, 
  *         .ss_pin = {GPIO_IO9, GPIO_IO10}, .ss_size = 2
  *         .data_format = SPI_DF_8BITS
  *     }
  * 
  *     spi_master_init(&spi);
  * 
  *     // Write 0xA5 to SS @ GPIO_IO9 (Expect an answer)
  *     spi_in_0 = (uint8_t) spi_master_write(&spi, 0xA5, 0);
  *     // Write 0xA6 to SS @ GPIO_IO10 (Expect an answer)
  *     spi_in_1 = (uint8_t) spi_master_write(&spi, 0xA6, 1);
  * 
  *     while(1);
  * }
  * ...
  * @endcode
  */
uint16_t spi_master_write_and_read(spi_t *spi, uint16_t data, uint8_t ss);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _SPI_H_ */