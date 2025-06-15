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


/* 添加在文件开头 */
volatile uint32_t sysTick = 0;/*滴答定时器的TICK数*/


void RCC_HSE_Config(uint32_t RCC_PLLMul_x); //自定义系统时间（可以修改时钟）

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
    RCC_HSE_Config(RCC_PLLMul_9); //设置系统时钟为9倍HSE时钟
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//两个抢占优先级 两个子优先级
    HAL_InitSysTick(); //初始化SysTick定时器

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


/*************************************
  * @Name   : HAL_InitSysTick
  * @brief  :初始化SysTick定时器
  * @param  : None
  * @retval ：None
  * @author : MAX-GitHub-Z 
  * @Data   : 2025-06-15
  * <description> :
 ****************************************/
static void HAL_InitSysTick(void)
{
    /* SystemCoreClock / 1000 = 1ms中断 */
    if (SysTick_Config(SystemCoreClock / 1000))
    {
        /* 捕获错误 */
        while (1);
    }
    
    /* 配置SysTick中断优先级 */
    NVIC_SetPriority(SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);
}

/*************************************
  * @Name   : HAL_GetTick
  * @brief  : 获取当前的tick数
  * @param  : None
  * @retval ：None
  * @author : MAX-GitHub-Z 
  * @Data   : 2025-06-15
  * <description> :
 ****************************************/
uint32_t HAL_GetTick(void)
{
    return sysTick;
}

/*************************************
  * @Name   : SysTick_Handler
  * @brief  : SysTick中断处理函数
  * @param  : None
  * @retval ：None
  * @author : MAX-GitHub-Z 
  * @Data   : 2025-06-15
  * <description> :
 ****************************************/
void SysTick_Handler(void)
{
    sysTick++;
}
