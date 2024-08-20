#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_systick.h"

int main(void)
{
	SystemInit();
	Systick_init();//初始化滴答定时器
	LED_GPIO_Config();
	while(1)
	{
		LED_D0(1);//低电平点亮
		Delay_ms(100);
		LED_D0(0);//低电平点亮
		Delay_ms(100);
		LED_D0(1);//低电平点亮
		Delay_ms(1000);
		LED_D0(0);//低电平点亮
		Delay_ms(1000);
	}
	
}


