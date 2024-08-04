#ifndef _BSP_LED_H
#define _BSP_LED_H
#include "stm32f10x.h"

#define LED_GPIO_PIN         GPIO_Pin_ALL
#define LED_GPIO_PORT         GPIOD
#define LED_GPIO_CLK          RCC_APB2Periph_GPIOD

#define LED_D0(a0)   if(a0)\
													GPIO_ResetBits(LED_GPIO_PORT, GPIO_Pin_7);\
										else GPIO_SetBits(LED_GPIO_PORT, GPIO_Pin_7);
#define LED_D1(a1)   if(a1)\
													GPIO_ResetBits(LED_GPIO_PORT, GPIO_Pin_5);\
										else GPIO_SetBits(LED_GPIO_PORT, GPIO_Pin_5);
#define LED_D2(a2)   if(a2)\
													GPIO_ResetBits(LED_GPIO_PORT, GPIO_Pin_3);\
										else GPIO_SetBits(LED_GPIO_PORT, GPIO_Pin_3);
#define LED_D3(a3)   if(a3)\
													GPIO_ResetBits(LED_GPIO_PORT, GPIO_Pin_1);\
										else GPIO_SetBits(LED_GPIO_PORT, GPIO_Pin_1);
#define LED_D4(a4)   if(a4)\
													GPIO_ResetBits(LED_GPIO_PORT, GPIO_Pin_6);\
										else GPIO_SetBits(LED_GPIO_PORT, GPIO_Pin_6);
#define LED_D5(a5)   if(a5)\
													GPIO_ResetBits(LED_GPIO_PORT, GPIO_Pin_4);\
										else GPIO_SetBits(LED_GPIO_PORT, GPIO_Pin_4);
#define LED_D6(a6)   if(a6)\
													GPIO_ResetBits(LED_GPIO_PORT, GPIO_Pin_2);\
										else GPIO_SetBits(LED_GPIO_PORT, GPIO_Pin_2);
#define LED_D7(a7)   if(a7)\
													GPIO_ResetBits(LED_GPIO_PORT, GPIO_Pin_0);\
										else GPIO_SetBits(LED_GPIO_PORT, GPIO_Pin_0);
#define LED_R(R)   if(R)\
													GPIO_ResetBits(LED_GPIO_PORT, GPIO_Pin_12);\
										else GPIO_SetBits(LED_GPIO_PORT, GPIO_Pin_12);
#define LED_B(B)   if(B)\
													GPIO_ResetBits(LED_GPIO_PORT, GPIO_Pin_10);\
										else GPIO_SetBits(LED_GPIO_PORT, GPIO_Pin_10);
#define LED_G(G)   if(G)\
													GPIO_ResetBits(LED_GPIO_PORT, GPIO_Pin_8);\
										else GPIO_SetBits(LED_GPIO_PORT, GPIO_Pin_8);


void LED_GPIO_Config(void);


#endif /*_BSP_LED_H*/
