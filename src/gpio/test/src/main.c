/**
 * @file main.c
 * @author David A. Aguirre M. (daguirre.m@outlook.com)
 * @brief Testing File of GPIO Custom HAL Lib for DSP Board.
 * @version d0.1
 * @date 2022-04-20
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

/** 
 * @todo Test RST GPIO
 */

#include "system.h"
#include "gpio.h"
#include "delay.h"

const gpio_io_t leds[2] = {
    GPIO_IO6, /*!< Led D2 on board */ 
    GPIO_IO7  /*!< Led D3 on board */ 
};

const gpio_io_t buttons[2] = {
    GPIO_IO3, /*!< Button K1 on board */ 
    GPIO_IO4  /*!< Button K0 on board */ 
};

int main (void)
{
    sys_clk_update();
    /* GPIO[A,B,C] clock should be enabled on RCC register ----------------|*/
    gpio_clk_en(GPIOA_RCC | GPIOB_RCC | GPIOE_RCC);                    /*<-|*/  /*[ok]*/

    /* GPIOB RCC clock should be disabled ---------------------------------|*/
    gpio_clk_dis(GPIOB_RCC);                                           /*<-|*/  /*[ok]*/

    /* GPIOA leds[1:0] should be configured as output pins ----------------|*/
    gpio_config_mode(GPIOA, GPIO_MODE_OUTPUT, leds[0] | leds[1]);      /*<-|*/  /*[ok]*/

    /* Leds on board should be on -----------------------------------------|*/
    gpio_port_set(GPIOA, leds[0] | leds[1]);                           /*<-|*/  /*[ok]*/

    /* Led D3 on board should be off --------------------------------------|*/
    gpio_port_clr(GPIOA, leds[0]);                                     /*<-|*/  /*[ok]*/

    /* GPIOA_OTYPER[6] should be 1 [Open-Drain] ---------------------------|*/
    gpio_config_output_mode(GPIOA, GPIO_OUTPUT_OD, GPIO_IO6);          /*<-|*/  /*[ok]*/

    /* GPIOA_OTYPER[6] should be 0 [Push-Pull] ----------------------------|*/
    gpio_config_output_mode(GPIOA, GPIO_OUTPUT_PP, GPIO_IO6);          /*<-|*/  /*[ok]*/

    /* GPIOE buttons[1:0] should be configured as input pull-up pins ------|*/
    gpio_config_all(                                                     /*|*/
        GPIOE,                                                           /*|*/
        GPIO_CONFIG_MODE_INPUT | GPIO_CONFIG_PULL_UP,                    /*|*/
        buttons[0] | buttons[1]                                          /*|*/
    );                                                                 /*<-|*/  /*[ok]*/

    /* GPIOE input should be 1 up to press button -------------------------|*/
    while((gpio_port_read_input(GPIOE) & buttons[0]) != 0);            /*<-|*/  /*[ok]*/

    /* It should stay on 'while' while the buttons K0 & K1 don´t be pressed at
       same time ----------------------------------------------------------|*/
    while(gpio_port_read_input_mask(GPIOE, buttons[0] | buttons[1])!=0)  /*|*/
    {                                                                    /*|*/
        /* LED D2 should toggle every second --|                           |*/
        gpio_port_tgl(GPIOA, leds[0]);       /*|                           |*/  
        delay_ms(1000);                    /*<-|                           |*/  /*[ok]*/
    }                                                                  /*<-|*/  /*[ok]*/

    delay_ms(1999);

    /* It should lock the button[0] config [If lock sequence fail bucles the
       program] -----------------------------------------------------------|*/
    while(gpio_config_lock(GPIOE, buttons[0]) == 1);                   /*<-|*/  /*[ok?]*/ /*?: Apparently sometimes fails*/

    /* Config should be applied only on the button[1] ---------------------|*/
    gpio_config_input_pull_mode(                                         /*|*/
        GPIOE,                                                           /*|*/
        GPIO_PULL_NONE,                                                  /*|*/
        buttons[0] | buttons[1]                                          /*|*/
    );                                                                 /*<-|*/  /*[ok]*/

    /* LED D2 [GPIOA6] should have low speed mode output ------------------|*/
    gpio_config_speed(GPIOA, GPIO_SPEED_MEDIUM, leds[0]);              /*<-|*/  /*[ok]*/

    /* GPIOA[15,0] should have been configured as AF1 Alternate function --|*/
    gpio_config_af(GPIOA, GPIO_ALT_AF1, GPIO_IO15 | GPIO_IO0);         /*<-|*/  /*[ok]*/

    while (1)
    {
        /* LEDS should blink every second if everyting is fine ------------|*/
        gpio_port_set(GPIOA, leds[0] | leds[1]);                         /*|*/
        delay_ms(20);                                                    /*|*/
        gpio_port_clr(GPIOA, leds[0] | leds[1]);                         /*|*/
        delay_ms(979);                                                 /*<-|*/  /*[ok]*/
    }
}
