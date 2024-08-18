#include "stm32f10x.h"
#include "bsp_led.h"
#include "config.h"
/* BOOT程序地址 			0x0800 0000 - 0x0800 3BFF
** BOOT程序变量地址	0x0800 3C00 - 0x0800 3FFF
**/

typedef void (*pFunction)(void);


void jump_to_app(void)
{
	pFunction jump_to_application;
	uint32_t jump_address;
	if (((*(__IO uint32_t*)APP_STATUP_ADDRESS) & 0x2FFE0000 ) == 0x20000000)
	{
		      jump_address = *(__IO uint32_t*) (APP_STATUP_ADDRESS + 4);
      jump_to_application = (pFunction) jump_address;
      /* Initialize user application's Stack Pointer */
      __set_MSP(*(__IO uint32_t*) jump_address);
      jump_to_application();
	}
}

int main(void)
{
	
	LED_GPIO_Config();
	jump_to_app();
	while(1)
	{
		LED_D0(1);//低电平点亮
	}
	
}

