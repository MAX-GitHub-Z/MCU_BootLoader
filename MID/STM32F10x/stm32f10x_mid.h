/**
  ************************ Copyright *************** 
  *           (C) Copyright 2024,txt1994,China.
  *                  All Rights Reserved
  *
  *                 https://github.com/MAX-GitHub-Z/MCU_BootLoader
  *                 email:3014759318@qq.com
  *                 QQ   :3014759318
  *      
  * FileName     : stm32f10x_fmc.h   
  * Version      : v1.0     
  * Author       : MAX-GitHub-Z         
  * Date         : 2024-11-23         
  * Description  :    
  * Function List:  
  * Toolchain : RealView Development Suite
  *             RealView Microcontroller Development Kit (MDK)
  *             ARM Developer Suite (ADS)
  *             Keil uVision
  ******************************************************
**/

#ifndef __STM32F10X_FMC_H_
#define __STM32F10X_FMC_H_


#include "stm32f10x.h"


#include <stdarg.h>
#include <stdio.h>
#include <string.h>


#define  DEBUG_USARTx                   USART1
#define  DEBUG_USART_BAUDRATE           115200
    
#define  DEBUG_USART_TX_GPIO_PORT       GPIOA   
#define  DEBUG_USART_TX_GPIO_PIN        GPIO_Pin_9
#define  DEBUG_USART_RX_GPIO_PORT       GPIOA
#define  DEBUG_USART_RX_GPIO_PIN        GPIO_Pin_10

#define  DEBUG_USART_IRQ                USART1_IRQn
#define  DEBUG_USART_IRQHandler         USART1_IRQHandler


/*************************************
  * @Name   : usart_init
  * @brief  :  串口初始化
  * @param  :  [输入/出] 
  * @retval ：None
  * @author : MAX-GitHub-Z 
  * @Data   : 2024-11-25
  * <description> :
 ****************************************/
void usart_init(void);
	
#endif

