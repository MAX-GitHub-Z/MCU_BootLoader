/********************************************
*该文件使用滴答定时器实现相对标准的延时，与时间戳
*The file uses a tick timer to achieve a 
*relatively standard delay, with time stamps
*****************************************/
#include "bsp_systick.h"
#include "core_cm3.h"

volatile static uint32_t Ststick = 0;
static uint32_t Ststick_ms = 0;
static uint32_t uwTick = 0;
/*systick config*/
void Systick_init(void)
{
	while(SysTick_Config(SystemCoreClock/SYSTICK_TIME)){}//STM32F103X 72M频率 8分频
	
	Ststick_ms = 1000u / SYSTICK_TIME;
	
  NVIC_SetPriority(SysTick_IRQn,0x00);
	
	if(Ststick_ms == 0)
		Ststick_ms = 1;
}

/*滴答定时器的中断函数*/
void SysTick_Handler(void)
{
	uwTick += Ststick_ms;//定时器节奏加一
	if(Ststick != 0)
	{
		Ststick--;
	}
}

/*获取当前时间戳*/
uint32_t GetTick(void)
{
		return uwTick;
}

/*ms级别的延时*/
void Delay_ms(uint32_t ms)
{
	Ststick = ms;
	while(Ststick);
}

