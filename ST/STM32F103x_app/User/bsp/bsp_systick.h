/********************************************
*该文件使用滴答定时器实现相对标准的延时，与时间戳
*The file uses a tick timer to achieve a 
*relatively standard delay, with time stamps
*****************************************/
#ifndef _SYSTICK_H
#define _SYSTICK_H
#include "stm32f10x.h"
#define SYSTICK_TIME 1000

/*systick config*/
void Systick_init(void);
/*滴答定时器的中断函数*/
void SysTick_Handler(void);
/*获取当前时间戳*/
uint32_t GetTick(void);
/*ms级别的延时*/
void Delay_ms(uint32_t ms);

#endif /*_SYSTICK_H*/


