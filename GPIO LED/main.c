
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

void led_init()
{
	GPIO_InitTypeDef	GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	  GPIO_Init(GPIOD, &GPIO_InitStructure);

	  GPIO_Write(GPIOD,0x00ff); //turn off all led

}

int main(void)
{
	// initialize cpu with hse from 8MHz crystal
	SystemInit();
	RCC_HSEConfig(RCC_HSE_ON);
	while(!RCC_WaitForHSEStartUp());

	led_init(); //initialize led

    while(1)
    {
    	GPIO_ToggleBits(GPIOD,GPIO_Pin_14); //togle led on gpio pin D12
    	for(unsigned int i=0;i<500000;++i); //set a few delay
    }
}
