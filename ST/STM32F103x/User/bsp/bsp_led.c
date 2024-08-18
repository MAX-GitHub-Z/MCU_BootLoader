#include "bsp_led.h"


void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStrudct;
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);
	GPIO_InitStrudct.GPIO_Pin =GPIO_Pin_All;
	GPIO_InitStrudct.GPIO_Mode =GPIO_Mode_Out_PP;
	GPIO_InitStrudct.GPIO_Speed =GPIO_Speed_50MHz;
  GPIO_Init(LED_GPIO_PORT, &GPIO_InitStrudct);
	
	
}
