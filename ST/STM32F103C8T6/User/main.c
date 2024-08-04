#include "stm32f10x.h"
#include "bsp_led.h"

void Delay(uint32_t count)
{
	for(; count!=0;count--);
}

int main(void)
{
	uint16_t i;
	 LED_GPIO_Config();
	while(1)
	{
//		for(i=0;i<3;i++)
//		{
//			if(i==0)
//				LED_R(0);
//			if(i==1)
//				LED_G(0);
//			if(i==2)
//				LED_B(0);
//			Delay(0xfffff);
//		}
//		for(i=0;i<3;i++)
//		{
//			if(i==0)
//				LED_R(1);
//			if(i==1)
//				LED_G(1);
//			if(i==2)
//				LED_B(1);
//			Delay(0xfffff);
//		}
    for(i=0;i<9;i++)
		{
			if(i==1)
				LED_D0(0);
			if(i==2)
				LED_D1(0);
			if(i==3)
				LED_D2(0);
			if(i==4)
				LED_D3(0);
			if(i==5)
				LED_D4(0);
			if(i==6)
				LED_D5(0);
			if(i==7)
				LED_D6(0);
			if(i==8)
				LED_D7(0);
			Delay(0xfffff);
		}
		Delay(0xfffff);
		for(i=0;i<9;i++)
		{
			if(i==1)
				LED_D0(1);
			if(i==2)
				LED_D1(1);
			if(i==3)
				LED_D2(1);
			if(i==4)
				LED_D3(1);
			if(i==5)
				LED_D4(1);
			if(i==6)
				LED_D5(1);
			if(i==7)
				LED_D6(1);
			if(i==8)
				LED_D7(1);
			Delay(0xfffff);
		}
	}
	
}


