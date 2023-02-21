/**
 * @file main.c
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief Ejemplo de implementación de un filtro tipo FIR.
 * @version d0.1
 * @date 2023-02-18
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

#include "system.h"

#include "adc.h"
#include "dsp.h"
#include "rcc.h"
#include "gpio.h"

#include "fir_coeff.h"

/* Habilita (1) o deshabilita (0) la asignación dinámica de memoria para las
 * variables del filtro FIR.
 */
#define FIR_DYNAMIC_ALLOCATION 0

/* Habilita (1) o deshabilita (0) el DAC R2R. Cuando el DAC R2R está deshabilitado
 * la salida de audio se realiza por el DAC interno.
 */
#define DAC_R2R_EN 1

/*Mode: [0] - Sin filtro */
/*      [1] - Pasa Bajos */
/*      [2] - Pasa Altos */
/*      [3] - Pasa Banda */
uint8_t mode = 0;

int main (void)
{
    /* Inicialización de clock del sistema @ 168 MHz con HSE como fuente del PLl */
    rcc_pll_param_cpte_set(168, RCC_PLLCLK_HSE);
    rcc_sysclk_select(RCC_SYSCLK_PLL | RCC_SYSCLK_HSE);

    /* Clock de los periféricos a usar */
    /* Clock DAC y TIM3 */
    rcc_clk_en_apb1(
        RCC_APB1_TIM3
        #if DAC_R2R_EN == 0
        | RCC_APB1_DAC
        #endif
    );
    
    /* Clock GPIO */
    gpio_clk_en(
          GPIOA_RCC /* ADC y DAC */
        | GPIOD_RCC /* Botón (Selector de filtros) */
        | GPIOH_RCC /* LED */
        #if DAC_R2R_EN == 1
        | GPIOE_RCC /* DAC R2R */
        #endif
    );
    
    /* Clock ADC */
    adc_clk_en(ADC1_RCC);

    /* Configuración de GPIO del LED de la board */
    gpio_config_mode(GPIOH, GPIO_MODE_OUTPUT, GPIO_IO11);

    /* Configuración GPIO Botón */
    gpio_config_mode(GPIOD, GPIO_MODE_INPUT, GPIO_IO7);
    gpio_config_input_pull_mode(GPIOD, GPIO_PULL_UP, GPIO_IO7);

    /* Configuración GPIO Anáogo */
    gpio_config_mode(
          GPIOA, GPIO_MODE_ANALOG,
          GPIO_IO7    /*ADC R*/
        | GPIO_IO4    /*DAC R*/
    ); 

    #if DAC_R2R_EN == 1
    /* Configuración R2R */
    gpio_config_all(
        /* GPIO del DAC */
        GPIOE, 
        /* Modo de salida, velocidad alta */
        GPIO_CONFIG_MODE_OUTPUT | GPIO_CONFIG_SPEED_VHIGH,
        /* 12 bits */
        GPIO_IO0 | GPIO_IO1 | GPIO_IO2 | GPIO_IO3 | GPIO_IO4 | GPIO_IO5 |
        GPIO_IO6 | GPIO_IO7 | GPIO_IO8 | GPIO_IO9 | GPIO_IO10| GPIO_IO11
    );
    #endif

    /* Configuración timmer @ 22 kHz */
    TIM3->SR = 0;
    TIM3->PSC = 0;
    TIM3->RCR = 0;
    TIM3->ARR = (SystemCoreClock / (1 * 22100)) - 1;

    /* ADC */
    /* Prescaler en 8 */
    adc_common_config_pre(ADC_PRE_8);
    
    /* Alineación hacia la derecha y configuración a 12 bits */
    adc_ind_config(ADC1, ADC_RES_12BITS, ADC_ALIGN_RIGHT);

    /* Configuración de lectura de únicamente el canal 7 */
    adc_ind_config_seq_sgl(ADC1, 7);
    adc_power_on(ADC1);

    #if DAC_R2R_EN == 0
    /* TODO: (DAC INIT) */
    DAC->CR |= (1 << 0);            // Canal 1
    DAC->CR |= (1 << 1);            // Output Buffered
    DAC->CR |= (1 << 2);            // Trigger
    DAC->CR |= (7 << 3);            // Trigger controlado por software
    #endif

    /* Enable TRC */
    CoreDebug->DEMCR |=  CoreDebug_DEMCR_TRCENA_Msk; // 0x01000000;
    TIM3->CR1 |= TIM_CR1_CEN;


    /* Inicialización de las variables del filtro FIR */

    #if FIR_DYNAMIC_ALLOCATION == 1
    /* En caso de una asignación de memoria dinámica, la variable se asgina 
     * en la memoria HEAP de la RAM.
     */
    fir_t *fir_filter = dsp_filter_fir_init(FIR_ORDER);
    if(fir_filter == NULL)
        error |= -1;
    #else
    /* En caso de una asignación estática, la variable se asigna en la sección
     * CCM de la RAM.
     */
    dsp_filter_fir_declarate(
        fir_filter,
        FIR_ORDER, __CCM_VAR_I
    );
    #endif
    /* Inicialización de los coeficientes B en la variable fir_filter */
    fir_filter->b.low = &b_low[0];
    fir_filter->b.high = &b_high[0];
    fir_filter->b.pass = &b_pass[0];
    fir_filter->b.stop = &b_stop[0];

    while(1)
    {
        /* Espere a que se desborde el timmer @ 22 kHz */
        while((TIM3->SR & TIM_SR_UIF) == 0);
        TIM3->SR &= ~TIM_SR_UIF;

        /* DEPURACIÓN, Prende el LED de la board */
        gpio_port_set(GPIOH, GPIO_IO11);

        /* Verificación de pulsación de botón */
        if (gpio_port_read_input_mask(GPIOD, GPIO_IO7) == 0)
        {
            /* Debounce de botón */
            delay_ms(500);
            if (gpio_port_read_input_mask(GPIOD, GPIO_IO7) == 0)
            {
                /* Cambia de modo de filtro */
                mode = (mode + 1) % (FILTER_TYPE_END + 1);
                while(gpio_port_read_input_mask(GPIOD, GPIO_IO7) == 0);
            }
        }

        /* Realiza la lectura del canal del ADC configurado en el secuenciador
         * con oversampling de 16 muestras y elimina el componente DC de la señal.
         */
        float x = 0;
        const uint8_t n_samples = 16;
        /* Oversampling */
        for (uint8_t i = 0; i < n_samples; i++)
        {
            x += (float) adc_ind_read_sgl(ADC1);
        }
        x /= n_samples;
        x -= 2048;

        /* Verificación de modo de filtro */
        if (mode != 0)
        {
            /* Implementación FIR */
            dsp_filter_fir(fir_filter, mode - 1, x);
        }
        else
        {
            /* Bypass */
            fir_filter->y =  x;
        }

        #if DAC_R2R_EN == 0
        /* Salida del DAC interno */
        dac_output((uint16_t) ((fir_filter->y) + 2048.0f));
        #else
        /* Salida del DAC R2R */
        gpio_port_write(GPIOE, (uint16_t) ((fir_filter->y) + 2048.0f));
        #endif 

        /* DEPURACIÓN, Apaga LED de la board */
        gpio_port_clr(GPIOH, GPIO_IO11);
    }
}
