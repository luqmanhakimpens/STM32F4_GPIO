#include "stm32f4xx.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

#ifndef __DiscoBoard_h
#define __DiscoBoard_h

#define led_green_on		GPIOD->BSRRL  = GPIO_Pin_12
#define led_orange_on		GPIOD->BSRRL  = GPIO_Pin_13
#define led_red_on			GPIOD->BSRRL  = GPIO_Pin_14
#define led_blue_on			GPIOD->BSRRL  = GPIO_Pin_15

#define led_green_off		GPIOD->BSRRH  = GPIO_Pin_12
#define led_orange_off		GPIOD->BSRRH  = GPIO_Pin_13
#define led_red_off			GPIOD->BSRRH  = GPIO_Pin_14
#define led_blue_off		GPIOD->BSRRH  = GPIO_Pin_15


#define led_green_togle		GPIOD->ODR ^= GPIO_Pin_12
#define led_orange_togle	GPIOD->ODR ^= GPIO_Pin_13
#define led_red_togle		GPIOD->ODR ^= GPIO_Pin_14
#define led_blue_togle		GPIOD->ODR ^= GPIO_Pin_15

#define button_pressed 		GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)

void F4Disco_led_init();
void F4Disco_button_init();
void  F4DiscoBoard_init();

void delay_ms(u32 ms);
void delay_us(u32 us);
void TimeTickDec();
void SystickInit(u32 TickTime);

#endif
