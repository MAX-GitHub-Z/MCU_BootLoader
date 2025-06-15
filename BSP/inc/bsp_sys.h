/**
  ************************ Copyright *************** 
  *           (C) Copyright 2025,txt1994,China.
  *                  All Rights Reserved
  *
  *                 https://github.com/MAX-GitHub-Z/MCU_BootLoader
  *                 email:3014759318@qq.com
  *                 QQ   :3014759318
  *      
  * FileName     : bsp_sys.h   
  * Version      : v1.0     
  * Author       : MAX-GitHub-Z         
  * Date         : 2025-06-15         
  * Description  :    
  * Function List:  
  * Toolchain : RealView Development Suite
  *             RealView Microcontroller Development Kit (MDK)
  *             ARM Developer Suite (ADS)
  *             Keil uVision
  ******************************************************
**/

#ifndef __BSP_SYS_H_
#define __BSP_SYS_H_

#include "stm32f10x.h"

/*************************************
  * @Name   : bsp_SysInit
  * @brief  :初始化时钟 中断等
  * @param  : None
  * @retval ：None
  * @author : MAX-GitHub-Z 
  * @Data   : 2025-06-15
  * <description> :
 ****************************************/
void bsp_SysInit(void);
/*************************************
  * @Name   : HAL_InitSysTick
  * @brief  :初始化SysTick定时器
  * @param  : None
  * @retval ：None
  * @author : MAX-GitHub-Z 
  * @Data   : 2025-06-15
  * <description> :
 ****************************************/
static void HAL_InitSysTick(void);
/*************************************
  * @Name   : HAL_GetTick
  * @brief  : 获取当前的tick数
  * @param  : None
  * @retval ：None
  * @author : MAX-GitHub-Z 
  * @Data   : 2025-06-15
  * <description> :
 ****************************************/
uint32_t HAL_GetTick(void);

#endif

