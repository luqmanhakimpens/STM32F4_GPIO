#include "stm32f4xx.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "F4DiscoBoard.h"

void f4Disco_led_init()
{
	GPIO_InitTypeDef	GPIO_InitStructure;
	  /* GPIOD Periph clock enable */
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	  /* Configure PD0:red, PD1:yellow, PD2:green and PD3:blue in led-output pushpull mode */
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	  GPIO_Init(GPIOD, &GPIO_InitStructure);

	  GPIO_Write(GPIOD,0x0000); //led off

}
void f4Disco_button_init()
{
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	  GPIO_InitTypeDef	GPIO_InitStructure;
	  /* Configure PA0 */
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	  //GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  //With pull down resistor
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	  //50MHz pin speed
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void F4DiscoBoard_init()
{
	f4Disco_button_init();
	f4Disco_led_init();
}

