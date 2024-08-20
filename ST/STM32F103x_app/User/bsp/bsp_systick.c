/********************************************
*���ļ�ʹ�õδ�ʱ��ʵ����Ա�׼����ʱ����ʱ���
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
	while(SysTick_Config(SystemCoreClock/SYSTICK_TIME)){}//STM32F103X 72MƵ�� 8��Ƶ
	
	Ststick_ms = 1000u / SYSTICK_TIME;
	
  NVIC_SetPriority(SysTick_IRQn,0x00);
	
	if(Ststick_ms == 0)
		Ststick_ms = 1;
}

/*�δ�ʱ�����жϺ���*/
void SysTick_Handler(void)
{
	uwTick += Ststick_ms;//��ʱ�������һ
	if(Ststick != 0)
	{
		Ststick--;
	}
}

/*��ȡ��ǰʱ���*/
uint32_t GetTick(void)
{
		return uwTick;
}

/*ms�������ʱ*/
void Delay_ms(uint32_t ms)
{
	Ststick = ms;
	while(Ststick);
}

