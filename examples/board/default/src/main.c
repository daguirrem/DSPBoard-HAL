/**
 * @file main.c
 * @author David A. Aguirre M. <daguirre.m@outlook.com>
 * @brief 
 * @version d0.1
 * @date 2023-06-22
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

#include <stdbool.h>
#include <math.h>

#include "system.h"
#include "gpio.h"
#include "rcc.h"
#include "adc.h"
#include "dsp.h"
#include "utils.h"

#include "fir_coeff.h"
#include "iir_coeff.h"

#include "ui/ui.h"


#include "ks0108.h"

#define SAMPLE_RATE 44100

volatile bool render = true;
volatile bool rst_options = false;

struct {
    uint8_t depht;
    int8_t mode;
    int8_t option;
    int8_t volume;
    int8_t gain[4];
    float gain_l[4];
    float wet;
    float feedback;
    float dry;
    uint16_t fc1[4];
    uint16_t fc2[2];
    uint16_t delay;

} menu = {
    .depht = 1, .mode = 0, .option = 0,
    .volume = 100,
    .gain = {}, .gain_l = {1.0f, 1.0f, 1.0f, 1.0f},
    .wet = 0.5f, .feedback = 0.6f, .dry = 0.6f,
    .delay = 100,
    .fc1 = {500, 200, 200, 1000},
    .fc2 = {1000,1000},
};

union {
    struct {
        bool bandpass;
        bool bandstop;
        bool lowpass;
        bool highpass;
        bool eco;
    };
    bool flags[5];

} enabler = {
    .bandpass = false,
    .bandstop = false,
    .lowpass = false,
    .highpass = false,
    .eco = false
};

dsp_filter_fir_declarate(
    fir_filter,
    FIR_ORDER, __CCM_VAR_I
);

dsp_filter_iir_declarate(
    iir_filter,
    IIR_ORDER, __CCM_VAR_I
);

dsp_eco_t *eco;
bool eco_update = false;

void board_sysclk_init(void);
void board_io_init(void);
void board_analog_init(void);

int main (void)
{
    board_sysclk_init();
    board_io_init();
    board_analog_init();

    iir_filter->b.pass = &b_band_pass[0];
    iir_filter->a.pass = &a_band_pass[0];
    iir_filter->b.stop = &b_band_stop[0];
    iir_filter->a.stop = &a_band_stop[0];

    fir_filter->b.low = &b_low[0];
    fir_filter->b.high = &b_high[0];

    eco = dsp_effect_eco_init(0.5f, 44100);
    dsp_effect_eco_update(eco, 0.08f);
    

    ks0108_init();
    ui_init();

    while(1)
    {
        if(render){
            render = false;
            ks0108_screen_render();
        }
        if(eco_update) {
            eco_update = false;
            dsp_effect_eco_update(eco, (menu.delay / 1000.0f));
        }
        delay_ms(250);
        gpio_port_tgl(GPIOH, GPIO_IO11);
    }
}

void board_sysclk_init(void)
{
    rcc_pll_param_cpte_set(168, RCC_PLLCLK_HSE);
    rcc_sysclk_select(RCC_SYSCLK_PLL | RCC_SYSCLK_HSE);
}

void board_io_init(void)
{
    gpio_clk_en(GPIOH_RCC);
    gpio_config_all(GPIOH, GPIO_CONFIG_MODE_OUTPUT, GPIO_IO10 | GPIO_IO11);
    rcc_clk_en_apb2(RCC_APB2_SYSCFG);

    gpio_clk_en(GPIOB_RCC);
    gpio_config_mode(
        GPIOB, GPIO_MODE_INPUT,
        GPIO_IO7 | GPIO_IO6 | GPIO_IO5 | GPIO_IO4
    );
    gpio_config_input_pull_mode(
        GPIOB, GPIO_PULL_UP,
        GPIO_IO7 | GPIO_IO6 | GPIO_IO5 | GPIO_IO4
    );

    SYSCFG->EXTICR[1] = 0x1 << 12;
    SYSCFG->EXTICR[1] |= 0x1 << 8;
    SYSCFG->EXTICR[1] |= 0x1 << 4;

    EXTI->IMR = 0xE0;
    EXTI->FTSR = 0xE0;

    NVIC_SetPriority(EXTI9_5_IRQn, 1);
    NVIC_EnableIRQ(EXTI9_5_IRQn);

    rcc_clk_en_apb1(RCC_APB1_TIM3);

    TIM3->SR = 0;
    TIM3->PSC = 0;
    TIM3->RCR = 0;
    TIM3->ARR = (SystemCoreClock / (1 * 1000)) - 1;
    TIM3->DIER |= TIM_DIER_UIE;
    CoreDebug->DEMCR |=  CoreDebug_DEMCR_TRCENA_Msk;

    NVIC_SetPriority(TIM3_IRQn, 2);
    NVIC_EnableIRQ(TIM3_IRQn);
}

void board_analog_init(void)
{
    gpio_clk_en(GPIOA_RCC | GPIOE_RCC);
    adc_clk_en(ADC1_RCC);

    gpio_config_mode(
          GPIOA, GPIO_MODE_ANALOG,
          GPIO_IO7    /*ADC R*/
        | GPIO_IO6    /*ADC L*/
        | GPIO_IO4    /*DAC R*/
    );

    gpio_config_all(
        /* GPIO del DAC */
        GPIOE, 
        /* Modo de salida, velocidad alta */
        GPIO_CONFIG_MODE_OUTPUT | GPIO_CONFIG_SPEED_VHIGH,
        /* 12 bits */
        GPIO_IO0 | GPIO_IO1 | GPIO_IO2 | GPIO_IO3 | GPIO_IO4 | GPIO_IO5 |
        GPIO_IO6 | GPIO_IO7 | GPIO_IO8 | GPIO_IO9 | GPIO_IO10| GPIO_IO11
    );

    rcc_clk_en_apb1(RCC_APB1_TIM2);

    TIM2->SR = 0;
    TIM2->PSC = 0;
    TIM2->RCR = 0;
    TIM2->ARR = (SystemCoreClock / (1 * SAMPLE_RATE)) - 1;
    TIM2->DIER |= TIM_DIER_UIE;    

    NVIC_SetPriority(TIM2_IRQn, 0);
    NVIC_EnableIRQ(TIM2_IRQn);

    adc_common_config_pre(ADC_PRE_6);
    adc_ind_config(ADC1, ADC_RES_12BITS, ADC_ALIGN_RIGHT);
    adc_ind_config_seq_sgl(ADC1, 6);
    adc_power_on(ADC1);

    DAC->CR |= (1 << 0);            // Canal 1
    DAC->CR |= (1 << 1);            // Output Buffered
    DAC->CR |= (1 << 2);            // Trigger
    DAC->CR |= (7 << 3);            // Trigger controlado por software
    TIM2->CR1 |= TIM_CR1_CEN;
}

void TIM2_IRQHandler(void)
{
    gpio_port_set(GPIOH, GPIO_IO10);
    float x = 0, y = 0;
    const uint8_t n_samples = 4;
    /* Oversampling */
    for (uint8_t i = 0; i < n_samples; i++)
    {
        x += (float) adc_ind_read_sgl(ADC1);
    }
    x /= n_samples;
    x -= 2048;

    if(enabler.bandpass)
    {
        /* Implementación IIR */
        dsp_filter_iir(iir_filter, FILTER_TYPE_BANDPASS, x);
        y += iir_filter->y[0];
        y *= menu.gain_l[0];
    }
    if(enabler.bandstop)
    {
        /* Implementación IIR */
        dsp_filter_iir(iir_filter, FILTER_TYPE_BANDSTOP, x);
        y += iir_filter->y[0];
        y *= menu.gain_l[1];
    }
    if(enabler.lowpass)
    {
        /* Implementación FIR */
        dsp_filter_fir(fir_filter, FILTER_TYPE_LOWPASS, x);
        y += fir_filter->y;
        y *= menu.gain_l[2];
    }
    if(enabler.highpass)
    {
        /* Implementación FIR */
        dsp_filter_fir(fir_filter, FILTER_TYPE_HIGHPASS, x);
        y += fir_filter->y;
        y *= menu.gain_l[3];
    }
    if(enabler.eco)
    {
        float _x;

        if(y == 0)
            _x = x;
        else
            _x = y;

        y += dsp_effect_eco(eco, _x);
    }
    
    if(y == 0)
    {
        /* Bypass */
        y = x;
    }

    y *= menu.volume / 100.0f;

    /* Salida del DAC interno */
    DAC->DHR12R1 = (uint16_t) (y + 2048.0f);
    DAC->SWTRIGR |= (1 << 0);

    /* Salida del DAC R2R */
    gpio_port_write(GPIOE, (uint16_t) (y + 2048.0f));

    gpio_port_clr(GPIOH, GPIO_IO10);
    TIM2->SR &= ~TIM_SR_UIF;
}


uint16_t ms = 0;
bool debounced = true;
uint16_t debounce_time = 100;
/* Debounce Handler */
void TIM3_IRQHandler(void)
{
    ms += 1;
    if(ms >= debounce_time)
    {
        ms = 0;

        debounced = true;

        TIM3->CR1 &= ~TIM_CR1_CEN;
        TIM3->CNT = 0;

        EXTI->PR |= 0xFFFFFF;
        NVIC_ClearPendingIRQ(EXTI9_5_IRQn);
    }
    TIM3->SR &= ~TIM_SR_UIF;
}

/* UI Menu Handler */
void EXTI9_5_IRQHandler(void)
{
    uint32_t pr = EXTI->PR;

    if(debounced == true) {
        if(pr & GPIO_IO6)
        {
            EXTI->PR |= GPIO_IO6;
            uint16_t dir = gpio_port_read_input_mask(GPIOB, GPIO_IO4);
            while(gpio_port_read_input_mask(GPIOB, GPIO_IO4) != dir);
            if(dir) {
                switch (menu.depht)
                {
                    case 0:
                        menu.volume += 5;
                        if (menu.volume > 100)
                            menu.volume = 100;
                        render = true;
                        break;
                    case 1:
                        menu.mode += 1;
                        if(menu.mode > 4)
                            menu.mode = 4;
                        
                        ks0108_vram_write(
                            (const uint8_t (*)[128]) 
                            ui[MENU_BACKGROUND]
                        );

                        ks0108_vram_add_layer(
                            (const uint8_t (*)[128])
                            ui[menu.mode + MENU_OFFSET]
                        );

                        if(enabler.flags[menu.mode]) {
                            switch (menu.mode)
                            {
                                case 0:
                                case 1:
                                    ks0108_vram_set_xy(4,25);
                                    ks0108_vram_printf("%1d", menu.fc2[menu.mode] / 1000);

                                case 2:
                                case 3:
                                    ks0108_vram_set_xy(5,22);
                                    ks0108_vram_printf("%+1d", menu.gain[menu.mode]);

                                    if(menu.option > 1)
                                        menu.option = 0;

                                    ks0108_vram_set_xy(3,25);
                                    ks0108_vram_printf("%3d", menu.fc1[menu.mode]);

                                    break;
                                case 4:
                                    ks0108_vram_set_xy(2,25);
                                    ks0108_vram_printf("%3d", menu.delay);
                                    ks0108_vram_set_xy(3,25);
                                    ks0108_vram_printf("%1.1f", menu.wet);
                                    ks0108_vram_set_xy(4,25);
                                    ks0108_vram_printf("%1.1f", menu.feedback);
                                    ks0108_vram_set_xy(5,25);
                                    ks0108_vram_printf("%1.1f", menu.dry);
                                    
                                    if(menu.option > 4)
                                        menu.option = 0;

                                    break;
                            default:
                                break;
                            }
                            ks0108_vram_set_xy(7,110);
                            ks0108_vram_printf("%s", enabler.flags[menu.mode] ? " ON" : "OFF");

                        }

                        break;

                    case 2:
                        switch (menu.mode)
                        {
                        case 0:
                        case 1:
                        case 2:
                        case 3:

                            if(menu.option == 0) {
                                menu.gain[menu.mode] += 1;
                                if (menu.gain[menu.mode] > 9)
                                    menu.gain[menu.mode] = 9;
                                
                                menu.gain_l[menu.mode] = powf(10, menu.gain[menu.mode] / 20.0f);
                            }
                            ks0108_vram_set_xy(5,22);
                            ks0108_vram_printf("%+1d", menu.gain[menu.mode]);

                            
                            if(menu.option >= 1)
                            {
                                enabler.flags[menu.mode] ^= true;

                                if((menu.mode <= 1) && enabler.flags[menu.mode])
                                {
                                    enabler.highpass = false;
                                    enabler.lowpass = false;

                                    if(menu.mode == 0)
                                        enabler.bandstop = false;

                                    if(menu.mode == 1)
                                        enabler.bandpass = false;
                                    
                                    ks0108_vram_set_xy(4,25);
                                    ks0108_vram_printf("%1d k", menu.fc2[menu.mode] / 1000);
                                } else if (enabler.flags[menu.mode]) {
                                    enabler.bandstop = false;
                                    enabler.bandpass = false;
                                }
                            }

                            ks0108_vram_set_xy(3,25);
                            ks0108_vram_printf("%3d Hz", menu.fc1[menu.mode]);

                            ks0108_vram_set_xy(7,110);
                            ks0108_vram_printf("%s", enabler.flags[menu.mode] ? " ON" : "OFF ");

                            break;
                        
                        case 4:
                            switch (menu.option)
                            {
                            case 0:
                            enabler.eco ^= true;

                            ks0108_vram_set_xy(7,110);
                            ks0108_vram_printf("%s", enabler.eco ? " ON" : "OFF ");
                            break;
                            case 1:
                                menu.delay += 10;
                                if(menu.delay > 500)
                                    menu.delay = 1000;

                                eco_update = true;

                                ks0108_vram_set_xy(2,25);
                                ks0108_vram_printf("%3d", menu.delay);
                                break;
                            case 2:
                                menu.wet += 0.1f;
                                if(menu.wet > 1.0f)
                                    menu.wet = 1.0f;
                                
                                ks0108_vram_set_xy(3,25);
                                ks0108_vram_printf("%1.1f", menu.wet);
                                break;
                            case 3:
                                menu.feedback += 0.1f;
                                if(menu.feedback > 1.0f)
                                    menu.feedback = 1.0f;
                                
                                ks0108_vram_set_xy(4,25);
                                ks0108_vram_printf("%1.1f", menu.feedback);
                                break;
                            case 4:
                                menu.dry += 0.1f;
                                if(menu.dry > 1.0f)
                                    menu.dry = 1.0f;
                                
                                ks0108_vram_set_xy(5,25);
                                ks0108_vram_printf("%1.1f", menu.dry);
                                break;
                            default:
                                break;
                            }
                            break;
                        default:
                            break;
                        }
                    default:
                        break;
                }

                ks0108_vram_set_xy(7,18);
                ks0108_vram_printf("%3d", menu.volume);

            }
            else {
                switch (menu.depht)
                {
                    case 0:
                        menu.volume -= 5;
                        if (menu.volume < 0)
                            menu.volume = 0;
                        break;
                    case 1:
                        menu.mode -= 1;
                        if(menu.mode < 0)
                            menu.mode = 0;
                        
                        ks0108_vram_write(
                            (const uint8_t (*)[128]) 
                            ui[MENU_BACKGROUND]
                        );

                        ks0108_vram_add_layer(
                            (const uint8_t (*)[128])
                            ui[menu.mode + MENU_OFFSET]
                        );

                        if(enabler.flags[menu.mode]) {
                            switch (menu.mode)
                            {
                                case 0:
                                case 1:
                                    ks0108_vram_set_xy(4,25);
                                    ks0108_vram_printf("%1d k", menu.fc2[menu.mode] / 1000);
                                case 2:
                                case 3:
                                    ks0108_vram_set_xy(5,22);
                                    ks0108_vram_printf("%+1d", menu.gain[menu.mode]);

                                    if(menu.option > 1)
                                        menu.option = 0;

                                    ks0108_vram_set_xy(3,25);
                                    ks0108_vram_printf("%3d", menu.fc1[menu.mode]);

                                    break;
                                case 4:
                                    ks0108_vram_set_xy(2,25);
                                    ks0108_vram_printf("%3d", menu.delay);
                                    ks0108_vram_set_xy(3,25);
                                    ks0108_vram_printf("%1.1f", menu.wet);
                                    ks0108_vram_set_xy(4,25);
                                    ks0108_vram_printf("%1.1f", menu.feedback);
                                    ks0108_vram_set_xy(5,25);
                                    ks0108_vram_printf("%1.1f", menu.dry);
                                    
                                    if(menu.option > 4)
                                        menu.option = 0;

                                    break;
                            default:
                                break;
                            }
                            ks0108_vram_set_xy(7,110);
                            ks0108_vram_printf("%s", enabler.flags[menu.mode] ? " ON" : "OFF");
                        }

                        break;

                    case 2:
                        switch (menu.mode)
                        {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                            if(menu.option == 0) {
                                menu.gain[menu.mode] -= 1;
                                if (menu.gain[menu.mode] < -9)
                                    menu.gain[menu.mode] = -9;
                                
                                menu.gain_l[menu.mode] = powf(10, menu.gain[menu.mode] / 20.0f);
                            }
                            ks0108_vram_set_xy(5,22);
                            ks0108_vram_printf("%+1d", menu.gain[menu.mode]);

                            if(menu.option >= 1)
                            {
                                enabler.flags[menu.mode] ^= true;

                                if((menu.mode <= 1) && enabler.flags[menu.mode])
                                {
                                    enabler.highpass = false;
                                    enabler.lowpass = false;

                                    if(menu.mode == 0)
                                        enabler.bandstop = false;

                                    if(menu.mode == 1)
                                        enabler.bandpass = false;
                                        
                                    ks0108_vram_set_xy(4,25);
                                    ks0108_vram_printf("%1d k", menu.fc2[menu.mode] / 1000);
                                } else if (enabler.flags[menu.mode]) {
                                    enabler.bandstop = false;
                                    enabler.bandpass = false;
                                }
                            }

                            ks0108_vram_set_xy(3,25);
                            ks0108_vram_printf("%3d", menu.fc1[menu.mode]);

                            ks0108_vram_set_xy(7,110);
                            ks0108_vram_printf("%s", enabler.flags[menu.mode] ? " ON" : "OFF ");

                            break;
                        case 4:
                            switch (menu.option)
                            {
                            case 0:
                                enabler.eco ^= true;

                                ks0108_vram_set_xy(7,110);
                                ks0108_vram_printf("%s", enabler.eco ? " ON" : "OFF");
                                break;
                            case 1:
                                menu.delay -= 10;
                                if(menu.delay < 10)
                                    menu.delay = 10;
                                
                                eco_update = true;
    
                                ks0108_vram_set_xy(2,25);
                                ks0108_vram_printf("%3d", menu.delay);
                                break;
                            case 2:
                                menu.wet -= 0.1f;
                                if(menu.wet < 0.1f)
                                    menu.wet = 0.1f;
                                
                                ks0108_vram_set_xy(3,25);
                                ks0108_vram_printf("%1.1f", menu.wet);
                                break;
                            case 3:
                                menu.feedback -= 0.1f;
                                if(menu.feedback < 0.1f)
                                    menu.feedback = 0.1f;
                                
                                ks0108_vram_set_xy(4,25);
                                ks0108_vram_printf("%1.1f", menu.feedback);
                                break;
                            case 4:
                                menu.dry -= 0.1f;
                                if(menu.dry < 0.1f)
                                    menu.dry = 0.1f;
                                
                                ks0108_vram_set_xy(5,25);
                                ks0108_vram_printf("%1.1f", menu.dry);
                                break;
                            default:
                                break;
                            }
                        default:
                            break;
                        }
                    default:
                        break;
                }
            }
            
            ks0108_vram_set_xy(7,18);
            ks0108_vram_printf("%3d", menu.volume);

            debounce_time = 100;
        }
        /* Menu buttons */
        if ((pr & GPIO_IO7) && (gpio_port_read_input_mask(GPIOD, GPIO_IO7) == 0))
        {
            EXTI->PR |= GPIO_IO7;
            menu.depht += 1;
                if(menu.depht > 2)
                    menu.depht = 2;

            if(menu.depht == 2)
            {
                menu.option += 1;
                switch (menu.mode)
                {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                        ks0108_vram_set_xy(5,22);
                        ks0108_vram_printf("%+1d", menu.gain[menu.mode]);

                        if(menu.option > 1)
                            menu.option = 0;
                        break;
                    case 4:
                        ks0108_vram_set_xy(2,25);
                        ks0108_vram_printf("%3d", menu.delay);
                        ks0108_vram_set_xy(3,25);
                        ks0108_vram_printf("%1.1f", menu.wet);
                        ks0108_vram_set_xy(4,25);
                        ks0108_vram_printf("%1.1f", menu.feedback);
                        ks0108_vram_set_xy(5,25);
                        ks0108_vram_printf("%1.1f", menu.dry);
                        
                        if(menu.option > 4)
                            menu.option = 0;

                        break;
                default:
                    break;
                }

                ks0108_vram_set_xy(7,110);
                ks0108_vram_printf("%s", enabler.flags[menu.mode] ? " ON" : "OFF");
            }

            debounce_time = 10000;
        }
        else {
            EXTI->PR |= GPIO_IO7;
        }
        if (pr & GPIO_IO5)
        {
            EXTI->PR |= GPIO_IO5;
            if(menu.depht >= 2)
                menu.depht = 0;

            menu.depht ^= 1;

            if(menu.depht == 1)
                menu.option = -1;

            debounce_time = 10000;
        }

        render = true;
        debounced = false;
        TIM3->CR1 |= TIM_CR1_CEN;
    } else {
        EXTI->PR |= 0xFFFFFF;
    }
}
