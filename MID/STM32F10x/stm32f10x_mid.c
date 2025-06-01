/**
  ************************* Copyright **********************
  *
  *          (C) Copyright 2024,China.
  *                    All Rights Reserved
  *
  *                 https://github.com/MAX-GitHub-Z/MCU_BootLoader
  *                 email:3014759318@qq.com
  *                 QQ   :3014759318
  *
  * FileName     : stm32f10x_fmc.c
  * Version      : v1.0
  * Author       : MAX-GitHub-Z
  * Date         : 2024-11-23
  * Description  :
  * Function List:
  * Toolchain : RealView Development Suite
  *             RealView Microcontroller Development Kit (MDK)
  *             ARM Developer Suite (ADS)
  *             Keil uVision
  **********************************************************
 */


#include "stm32f10x_mid.h"



/*************************************
  * @Name   : mid_init
  * @brief  : 芯片驱动初始化
  * @param  : : [输入/出] 
  * @retval ：None
  * @author : MAX-GitHub-Z 
  * @Data   : 2025-06-01
  * <description> :
 ****************************************/
void mid_init()
{

	usart_init();
}


