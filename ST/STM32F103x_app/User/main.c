#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_systick.h"

int main(void)
{
	SystemInit();
	Systick_init();//��ʼ���δ�ʱ��
	LED_GPIO_Config();
	while(1)
	{
		LED_D0(1);//�͵�ƽ����
		Delay_ms(100);
		LED_D0(0);//�͵�ƽ����
		Delay_ms(100);
		LED_D0(1);//�͵�ƽ����
		Delay_ms(1000);
		LED_D0(0);//�͵�ƽ����
		Delay_ms(1000);
	}
	
}


