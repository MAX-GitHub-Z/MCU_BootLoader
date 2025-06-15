/**
  ************************* Copyright ********************** 
  *
  *          (C) Copyright 2025,China.
  *                    All Rights Reserved
  *                              
  *                 https://github.com/MAX-GitHub-Z/MCU_BootLoader
  *                 email:3014759318@qq.com
  *                 QQ   :3014759318
  *    
  * FileName     : bsp_sys..c   
  * Version      : v1.0     
  * Author       : MAX-GitHub-Z         
  * Date         : 2025-06-15         
  * Description  :    
  * Function List:  
  * Toolchain : RealView Development Suite
  *             RealView Microcontroller Development Kit (MDK)
  *             ARM Developer Suite (ADS)
  *             Keil uVision
  **********************************************************
 */
#include "bsp_sys.h"

/*************************************
  * @Name   : bsp_SysInit
  * @brief  :初始化时钟 中断等
  * @param  : None
  * @retval ：None
  * @author : MAX-GitHub-Z 
  * @Data   : 2025-06-15
  * <description> :
 ****************************************/
void bsp_SysInit(void)
{
    // Initialize the system clock
    
}

//设置时钟
void RCC_HSE_Config(uint32_t RCC_PLLMul_x) //自定义系统时间（可以修改时钟）
{
	RCC_DeInit(); //将外设RCC寄存器重设为缺省值
	RCC_HSEConfig(RCC_HSE_ON);//设置外部高速晶振（HSE）使能
	if(RCC_WaitForHSEStartUp()==SUCCESS) //等待HSE起振
	{
		RCC_HCLKConfig(RCC_SYSCLK_Div1);//设置AHB时钟（HCLK）
		RCC_PCLK1Config(RCC_CFGR_PPRE2_DIV2);//设置低速AHB时钟（PCLK1）
		RCC_PCLK2Config(RCC_CFGR_PPRE2_DIV1);//设置高速AHB时钟（PCLK2）
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_x);//设置PLL时钟源及倍频系数
		RCC_PLLCmd(ENABLE); //使能或者失能PLL
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET);//检查指定的RCC标志位设置与否,PLL就绪
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);//设置系统时钟（SYSCLK）
		while(RCC_GetSYSCLKSource()!=0x08);//返回用作系统时钟的时钟源,0x08：PLL作为系统时钟,0x40:HSE作为时钟源
	}
}
