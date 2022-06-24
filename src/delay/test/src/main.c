/**
 * @file delay_test.c
 * @author David A. Aguirre M. (daguirre.m@outlook.com)
 * @brief
 * @version 0.1
 * @date 2021-05-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stm32F4xx.h>
#include "delay.h"
#include "gpio.h"
#include "rcc.h"

int main(void)
{
    rcc_pll_param_cpte_set(100, RCC_PLLCLK_HSE);
    rcc_sysclk_select(RCC_SYSCLK_PLL | RCC_SYSCLK_HSE);
    gpio_clock_en(GPIOA_RCC);
    gpio_config_mode(GPIOA, GPIO_MODE_OUTPUT, GPIO_IO6);
    gpio_config_speed(GPIOA, GPIO_SPEED_VHIGH, GPIO_IO6);
    
    while (1)
    {
        gpio_port_tgl(GPIOA, GPIO_IO6);
        delay_ms(273);
    }
}
