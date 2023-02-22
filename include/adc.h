/**
 * @file adc.h
 * @author David A. Aguirre M. (daguirre.m@outlook.com)
 * @brief ADC - Custom HAL for DSP Board SDK.
 * @version d0.1.1
 * @date 2022-06-27
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
#ifndef _ADC_H_
#define _ADC_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @addtogroup adc ADC
 */

/** 
 * @addtogroup public_adc Public
 * @ingroup adc
 * 
 */

#include "system.h"
#include "rcc.h"

#define ADC_VREF_P 3300
#define ADC_VREF_N 0
#define ADC_VREF (ADC_VREF_P - ADC_VREF_N)

/*----------------------------------------------------------------------------*/
/* Enums */
/*----------------------------------------------------------------------------*/

typedef enum {
    ADC1_RCC = RCC_APB2_ADC1, //!< ADC0 RCC mask
    ADC2_RCC = RCC_APB2_ADC2, //!< ADC1 RCC mask
    ADC3_RCC = RCC_APB2_ADC3  //!< ADC2 RCC mask
} adc_rcc_t;

typedef enum {
    ADC_RES_12BITS = 0,
    ADC_RES_10BITS = 1,
    ADC_RES_8BITS  = 2,
    ADC_RES_6BITS  = 3
} adc_res_t;

typedef enum {
    ADC_ALIGN_RIGHT = 0,
    ADC_ALIGN_LEFT = 1
} adc_align_t;

typedef enum {
    ADC_PRE_2 = 0,
    ADC_PRE_4 = 1,
    ADC_PRE_6 = 2,
    ADC_PRE_8 = 3
} adc_pre_t;

typedef enum {
    ADC_INCH_VBAT = ADC_CCR_VBATE,
    ADC_INCH_TVREF = ADC_CCR_TSVREFE
} adc_ich_t;

/*----------------------------------------------------------------------------*/
/* Structs */
/*----------------------------------------------------------------------------*/

typedef struct {
    uint8_t lenght;
    uint8_t sequece[16];
    uint16_t raw[16];
    uint32_t voltage[16];
} adc_seqr_rgl_t;

typedef struct {
    uint8_t lenght;
    uint8_t sequece[4];
    uint16_t raw[4];
    uint32_t voltage[4];
} adc_seqr_ijt_t;

/*----------------------------------------------------------------------------*/
/* Variables */
/*----------------------------------------------------------------------------*/

extern const uint16_t resbits_decode[];

/*----------------------------------------------------------------------------*/
/* Functions */
/*----------------------------------------------------------------------------*/

/** ### adc:reset
 * @ingroup public_adc
 * @brief Reset single or multiple ADC peripheral/s.
 * 
 * Reset masked peripheral/s in RCC_APB2RSTR, This will reset ALL registers
 * associated with the target peripheral/s.
 * 
 * @param[in] mask ADC mask to be reset.
 * 
 * @return None.
 * 
 * @note 1. You can reset multiple ADC's at same time passing each of them with 
 *          an OR operator.
 * @note 2. It is a forced inline function.
 * 
 * @see adc_rcc_t Mask type.
 * @see rcc_rst_apb2 Internal RCC function
 * 
 * E.g. @n
 * For one ADC peripheral reset:
 * @code
 * ...
 * // This reset ADC 1 peripheral
 * adc_rst(ADC1_RCC);
 * ...
 * @endcode
 * For multiple ADC peripheral reset:
 * @code
 * ...
 * // This reset ADC 2 and ADC 1 peripherals
 * adc_rst(ADC2_RCC | ADC1_RCC);
 * ...
 * @endcode
 */
__FORCE_INLINE void adc_rst(adc_rcc_t mask)
{
    rcc_rst_apb2((rcc_apb2_t) mask);
}

/** ### adc:clock:enable
 * @ingroup public_adc
 * @brief Enable single or multiple ADC peripheral/s clock.
 * 
 * Enable clock in RCC_APB2 to masked ADC/s.
 * 
 * @param[in] mask ADC mask to be enabled.
 * 
 * @return None.
 * 
 * @note 1. You can enable multiple ADC's at same time passing each of them with
 *          an OR operator.
 * @note 2. It is a forced inline function.
 * 
 * @see adc_rcc_t Mask type.
 * @see rcc_clk_en_apb2 Internal RCC function
 * 
 * E.g. @n
 * For one ADC clock enable:
 * @code
 * ...
 * // This enable ADC 1 clock
 * adc_clk_en(ADC1_RCC);
 * ...
 * @endcode
 * For multiple ADCs clock enable:
 * @code
 * ...
 * // This enable ADC 2 and ADC 1 clocks
 * adc_clk_en(ADC2_RCC | ADC1_RCC);
 * ...
 * @endcode
 */
__FORCE_INLINE void adc_clk_en(adc_rcc_t mask)
{
    rcc_clk_en_apb2((rcc_apb2_t) mask);
}

/** ### adc:clock:disable
 * @ingroup public_adc
 * @brief Disable single or multiple ADC peripheral/s clock.
 * 
 * Disable clock in RCC_APB2 to masked ADC/s.
 * 
 * @param[in] mask ADC mask to be disabled.
 * 
 * @return None.
 * 
 * @note 1. You can disable multiple ADC's at same time passing each of them with
 *          an OR operator.
 * @note 2. It is a forced inline function.
 * 
 * @see adc_rcc_t Mask type.
 * @see rcc_clk_dis_apb2 Internal RCC function
 * 
 * E.g. @n
 * For one ADC clock disable:
 * @code
 * ...
 * // This disable ADC 1 clock
 * adc_clk_dis(ADC1_RCC);
 * ...
 * @endcode
 * For multiple ADCs clock disable:
 * @code
 * ...
 * // This disable ADC 2 and ADC 1 clocks
 * adc_clk_dis(ADC2_RCC | ADC1_RCC);
 * ...
 * @endcode
 */
__FORCE_INLINE void adc_clk_dis(adc_rcc_t mask)
{
    rcc_clk_dis_apb2((rcc_apb2_t) mask);
}

/** ### adc:power:on
 * @ingroup public_adc
 * @brief Power on the target ADC.
 * 
 * Power on target ADC by setting ADON bit on ADCx_CR2 register.
 * 
 * @param[in] adc ADC to be power on.
 * 
 * @return None.
 * 
 * @note It is a forced inline function.
 * 
 * E.g. @n
 * @code
 * ...
 * // This power on the ADC 1
 * adc_power_on(ADC1);
 * // This power on the ADC 2
 * adc_power_on(ADC2);
 * ...
 * @endcode
 */
__FORCE_INLINE void adc_power_on(ADC_TypeDef *adc)
{
    adc->CR2 |= ADC_CR2_ADON;
}

/** ### adc:power:down
 * @ingroup public_adc
 * @brief Power down the target ADC.
 * 
 * Power down target ADC by clearing ADON bit on ADCx_CR2 register.
 * 
 * @param[in] adc ADC to be power down.
 * 
 * @return None.
 * 
 * @note It is a forced inline function.
 * 
 * E.g. @n
 * @code
 * ...
 * // This power down the ADC 1
 * adc_power_down(ADC1);
 * // This power down the ADC 2
 * adc_power_down(ADC2);
 * ...
 * @endcode
 */
__FORCE_INLINE void adc_power_down(ADC_TypeDef *adc)
{
    adc->CR2 &= ~ADC_CR2_ADON;
}

/** ### TODO:
  * @ingroup public_module
  * @brief 
  * 
  * Detailed Description
  * 
  * @param[in] 
  * 
  * @return None
  * 
  * @note
  * 
  * @see
  * 
  * E.g. @n
  * 
  * @code
  * ...
  * ...
  * @endcode
  */
__FORCE_INLINE void adc_start_sw(ADC_TypeDef *adc)
{
    adc->CR2 |= ADC_CR2_SWSTART;
}

/** ### adc:common:configure:prescaler
 * @ingroup public_adc
 * @brief Configure common prescaler between ADCs.
 * 
 * Configure ADCPRE bits on ADC_CCR to get desired ADC clock prescaler.
 * 
 * @param[in] preescaler
 * 
 * @return None.
 * 
 * @note It is a forced inline function.
 * 
 * @see adc_pre_t Prescaler type.
 * 
 * E.g. @n
 * 
 * @code
 * ...
 * // This configure in all ADCs the clock to (PCLK2 / 8)
 * adc_common_config_pre(ADC_PRE_8)
 * ...
 * @endcode
 */
__FORCE_INLINE void adc_common_config_pre(adc_pre_t prescaler)
{
    ADC->CCR &= ~ADC_CCR_ADCPRE;
    ADC->CCR |= prescaler << ADC_CCR_ADCPRE_Pos;
}

/*----------------------------------------------------------------------------*/

/** ### adc:individual:configure
 * @ingroup public_adc
 * @brief Set resolution and alignment on target ADC.
 * 
 * Configure the target ADC to individual mode and set the resolution and the 
 * alignment of the result. By default, the single channel mode is enabled.
 * 
 * @param[in] adc ADC to configure.
 * @param[in] resolution ADC resolution to configure.
 * @param[in] alignment ADC result alignment to configure.
 * 
 * @return None.
 * 
 * @see adc_res_t Resolution type.
 * @see adc_align_t Alignment type.
 * 
 * E.g. @n
 * @code
 * ...
 * // This configure the ADC1 to get 12 bits resolution and right alignment result
 * // on individual mode
 * adc_ind_config(ADC1, ADC_RES_12BITS, ADC_ALIGN_RIGHT);
 * ...
 * @endcode
 */
void adc_ind_config(
    ADC_TypeDef *adc, adc_res_t resolution, adc_align_t alignment
);

/**
 * @todo adc_ind_config_mode_sgl documentation
 * @brief 
 * 
 * @param adc 
 * @return __FORCE_INLINE 
 */
__FORCE_INLINE void adc_ind_config_mode_sgl(ADC_TypeDef *adc)
{
    adc->CR1 &= ~ADC_CR1_SCAN;
}

/**
 * @todo adc_ind_config_mode_scan documentation
 * @brief 
 * 
 * @param adc 
 * @return __FORCE_INLINE 
 */
__FORCE_INLINE void adc_ind_config_mode_scan(ADC_TypeDef *adc)
{
    // TODO: Force to shutdown other modes?
    adc->CR1 |= ADC_CR1_SCAN;
}

/* TODO: ¿? */
void adc_ind_mode_con();
void adc_ind_mode_discon();

/** ### adc:individual:configure:sequencer:single[channel]
 * @ingroup public_adc
 * @brief Configure the target ADC to read a single channel.
 * 
 * Configure the sequencer adc to read a single channel on target ADC.
 * 
 * @param[in] adc Target ADC to configure.
 * @param[in] channel Target channel to be read.
 * 
 * @return None.
 * 
 * E.g. @n
 * @code
 * ...
 * // This configure channel 0 of ADC1 to be read
 * adc_ind_config_seq_sgl(ADC1, 0);
 * ...
 * @endcode
 */
__FORCE_INLINE void adc_ind_config_seq_sgl(ADC_TypeDef *adc, uint8_t channel)
{
    /* Clear lenght */
    /* Clear first sequence */
    /* Assign desired channel to read */
    adc->SQR1 &= ~(0x0F << ADC_SQR1_L_Pos);
    adc->SQR3 &= ~(0x1F);
    adc->SQR3 |= channel;
}

/** ### adc:individual:read:single[channel]
 * @ingroup public_adc
 * @brief Read a single preconfigured channel of target ADC.
 * 
 * Start single channel reading of target ADC and bucle while until the reading
 * its ready, then returns the result.
 * 
 * @param[in] adc ADC to be read.
 * 
 * @return None.
 * 
 * @note It is a forced inline function.
 * 
 * @see adc_ind_config_seq_sgl To preconfigure the target channel before call
 *      this function.
 * 
 * E.g. @n
 * @code
 * ...
 * uint16_t adc_raw;
 * ...
 * // This preconfigure a channel 0 to be readed
 * adc_ind_config_seq_sgl(ADC1, 0);
 * // This read a preconfigured channel 0
 * adc_raw = adc_ind_read_sgl(ADC1);
 * ...
 * @endcode
 */
__FORCE_INLINE uint16_t adc_ind_read_sgl(ADC_TypeDef *adc)
{
    adc_start_sw(adc);
    while((adc->SR & ADC_SR_EOC) == 0);
    uint16_t raw = adc->DR;
    adc->SR &= ~ADC_SR_STRT;
    return raw;
}

/** ### adc:individual:read:scan:regular
 * @ingroup public_adc
 * @brief Execute the scanner mode of target ADC to read the preconfigured
 *        channels on the sequencer.
 * 
 * Execute the reading of each preconfigured sequencer channel and save the
 * result on respective raw indexed array of sequencer variable.
 * 
 * @param[in] adc ADC to be readed.
 * @param[out] sequencer Sequencer where the results will be saved
 * 
 * @return None.
 * TODO:
 * @note
 * 
 * @see
 * 
 * E.g. @n
 * 
 * @code
 * ...
 * ...
 * @endcode
 */
void adc_ind_read_scan_rgl(ADC_TypeDef *adc, adc_seqr_rgl_t *sequencer);

 /** ### adc:configure:sequencer:regular
 * @ingroup public_adc
 * @brief Preconfigure internal [regualar] sequencer.
 * 
 * Configure the lenght and the channels of the sequencer to scanner adc mode.
 * 
 * @param[in] adc ADC to be configured.
 * @param[in] sequencer Sequencer configurator.
 * 
 * @return Return error codes [uint8_t]: @n
 *          0 [OK]. @n
 *         -1 [Sequencer lengh is not allowed].
 * 
 * @see adc_seqr_rgl_t Sequencer type.
 * 
 * E.g. @n
 * 
 * @code
 * ...
 * // This preconfigure the sequencer to read 2 channels [first ch 17 and then 
 * // ch 1]
 * adc_seqr_rgl_t sequencer;
 * sequencer.lenght = 2;
 * sequencer.sequence[0] = 17;
 * sequencer.sequence[1] = 1;
 * adc_config_seq_rgl(ADC1, &sequencer);
 * ...
 * @endcode
 */
int8_t adc_config_seq_rgl(ADC_TypeDef *adc, adc_seqr_rgl_t *sequencer);

 /** ### adc:configure:sequencer:injected
 * @ingroup public_adc
 * @brief Preconfigure internal [injected] sequencer.
 * 
 * Configure the lenght and the channels of the sequencer to scanner adc mode.
 * 
 * @param[in] adc ADC to be configured.
 * @param[in] sequencer Sequencer configurator.
 * 
 * @return Return error codes [uint8_t]: @n
 *          0 [OK]. @n
 *         -1 [Sequencer lengh is not allowed].
 * 
 * @see adc_seqr_ijt_t Sequencer type.
 * 
 * E.g. @n
 * 
 * @code
 * ...
 * // This preconfigure the sequencer to read 2 channels [first ch 0 and then 
 * // ch 1]
 * adc_seqr_ijt_t sequencer;
 * sequencer.lenght = 2;
 * sequencer.sequence[0] = 0;
 * sequencer.sequence[1] = 1;
 * adc_config_seq_ijtADC1, &sequencer);
 * ...
 * @endcode
 */
int8_t adc_config_seq_ijt(ADC_TypeDef *adc, adc_seqr_ijt_t *sequencer);

/** ### adc:get:voltage
 * @ingroup public_adc
 * @brief Compute the voltage [in mV] from RAW ADC result.
 * 
 * Returns the voltage [mV] of RAW ADC result based on ADC_VREF value and 
 * resolution of adc reading.
 * 
 * @param[in] raw RAW ADC result to be computed.
 * @param[in] resolution ADC reading resolution of raw adc result.
 * 
 * @return Computed voltage in milivolts [mV] [uint32_t].
 * 
 * @note 1. ADC_VREF by default value is 3300 [mV].
 * @note 2. It is a forced inline function.
 * 
 * @see ADC_VREF ADC Voltaje reference.
 * @see adc_res_t Resolution type.
 * 
 * E.g. @n
 * @code
 * ...
 * // This returns a voltage value from RAW adc read [E.g. 512]
 * uint16_t adc_raw = 512; // or adc_ind_read_sgl(ADCx);
 * uint32_t adc_voltage = adc_get_voltage(adc_raw, ADC_RES_12BITS);
 * ...
 * @endcode
 */
__FORCE_INLINE uint32_t adc_get_voltage(uint16_t raw, adc_res_t resolution)
{
    return (raw * ADC_VREF) / resbits_decode[resolution];
}


/** ### adc:i[nternal]channel:enable
 * @ingroup public_adc
 * @brief Enable internal adc channel.
 * 
 * Enable internal VBAT and/or V_{TEMP} / V_{REFIN} ADC channels.
 * 
 * @param[in] mask Channel mask to be enabled.
 * 
 * @return None.
 * 
 * @note It is a forced inline function.
 * 
 * @see adc_ich_t Channel mask type.
 * 
 * E.g. @n
 * @code
 * ...
 * // This enable the VBAT channel and the V_{TEMP} / V_{REFIN} channel
 * adc_ich_en(ADC_INCH_TVREF | ADC_INCH_VBAT);
 * ...
 * @endcode
 */
__FORCE_INLINE void adc_ich_en(adc_ich_t mask)
{
    ADC->CCR |= mask;
}

/** ### adc:i[nternal]channel:disable
 * @ingroup public_adc
 * @brief Disable internal adc channel.
 * 
 * Disable internal VBAT and/or V_{TEMP} / V_{REFIN} ADC channels.
 * 
 * @param[in] mask Channel mask to be disabled.
 * 
 * @return None.
 * 
 * @note It is a forced inline function.
 * 
 * @see adc_ich_t Channel mask type.
 * 
 * E.g. @n
 * @code
 * ...
 * // This disable the VBAT channel and the V_{TEMP} / V_{REFIN} channel
 * adc_ich_dis(ADC_INCH_TVREF | ADC_INCH_VBAT);
 * ...
 * @endcode
 */
__FORCE_INLINE void adc_ich_dis(adc_ich_t mask)
{
    ADC->CCR &= ~mask;
}

/** ### adc:sequencer:get:voltages:regular
 * @ingroup public_adc
 * @brief Compute the voltages [in mV] from RAW ADC results of [regular]
 *        sequencer.
 * 
 * Compute the voltage [mV] of RAW ADC results based on ADC_VREF value and 
 * resolution of adc reading, and store them on voltage indexed array member
 * of sequencer variable.
 * 
 * @param[in/out] sequencer Sequencer where ADC RAW results are stored and
 *                          where results of voltage compute will be stored.
 * @param[in] resolution ADC reading resolution of raw adc result.
 * 
 * @return None.
 * 
 * @note 1. ADC_VREF by default value is 3300 [mV].
 * @note 2. It is a forced inline function.
 * 
 * @see ADC_VREF ADC Voltaje reference.
 * @see adc_res_t Resolution type.
 * @see adc_seqr_rgl_t Sequencer type.
 * 
 * E.g. @n
 * @code
 * ...
 * // This returns a voltage value from RAW adc read [E.g. 512]
 * uint16_t adc_raw = 512; // or adc_ind_read_sgl(ADCx);
 * uint32_t adc_voltage = adc_get_voltage(adc_raw, ADC_RES_12BITS);
 * ...
 * @endcode
 */
__FORCE_INLINE void adc_seq_get_voltages_rgl(
    adc_seqr_rgl_t *sequencer, adc_res_t resolution
)
{
    for (uint8_t i = 0; i < sequencer->lenght; i++)
    {
        sequencer->voltage[i] = adc_get_voltage(sequencer->raw[i], resolution);
    }
}

/** ### adc:sequencer:get:voltages:regular
 * @ingroup public_adc
 * @brief Compute the voltages [in mV] from RAW ADC results of [injected]
 *        sequencer.
 * 
 * Compute the voltage [mV] of RAW ADC results based on ADC_VREF value and 
 * resolution of adc reading, and store them on voltage indexed array member
 * of sequencer variable.
 * 
 * @param[in/out] sequencer Sequencer where ADC RAW results are stored and
 *                          where results of voltage compute will be stored.
 * @param[in] resolution ADC reading resolution of raw adc result.
 * 
 * @return None.
 * 
 * @note 1. ADC_VREF by default value is 3300 [mV].
 * @note 2. It is a forced inline function.
 * 
 * @see ADC_VREF ADC Voltaje reference.
 * @see adc_res_t Resolution type.
 * @see adc_seqr_rgl_t Sequencer type.
 * 
 * E.g. @n
 * @code
 * ...
 * // This returns a voltage value from RAW adc read [E.g. 512]
 * uint16_t adc_raw = 512; // or adc_ind_read_sgl(ADCx);
 * uint32_t adc_voltage = adc_get_voltage(adc_raw, ADC_RES_12BITS);
 * ...
 * @endcode
 */
__FORCE_INLINE void adc_seq_get_voltages_ijt(
    adc_seqr_ijt_t *sequencer, adc_res_t resolution
)
{
    for (uint8_t i = 0; i < sequencer->lenght; i++)
    {
        sequencer->voltage[i] = adc_get_voltage(sequencer->raw[i], resolution);
    }
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _ADC_H_ */
