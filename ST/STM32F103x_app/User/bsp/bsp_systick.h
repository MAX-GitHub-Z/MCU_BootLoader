/********************************************
*���ļ�ʹ�õδ�ʱ��ʵ����Ա�׼����ʱ����ʱ���
*The file uses a tick timer to achieve a 
*relatively standard delay, with time stamps
*****************************************/
#ifndef _SYSTICK_H
#define _SYSTICK_H
#include "stm32f10x.h"
#define SYSTICK_TIME 1000

/*systick config*/
void Systick_init(void);
/*�δ�ʱ�����жϺ���*/
void SysTick_Handler(void);
/*��ȡ��ǰʱ���*/
uint32_t GetTick(void);
/*ms�������ʱ*/
void Delay_ms(uint32_t ms);

#endif /*_SYSTICK_H*/


