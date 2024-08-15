#include "stm32f10x.h"
#include "bsp_led.h"

void Delay(uint32_t count)
{
	for(; count!=0;count--);
}

int main(void)
{
	
	LED_GPIO_Config();
	LED_D0(1);
	while(1)
	{

	}
	
}


