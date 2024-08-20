/*该文件是boot程序的配置文件，可通过修改该文件来适配不同型号的STM32F103X
* 的单片机，与相关的业务，如启动地址， 串口功能等*/

/*This file is the configuration file of the boot program. You can 
* modify this file to adapt different models of STM32F103X microcontroller 
* and related services, such as startup address and serial port function*/
#ifndef _CONFIG_H
#define _CONFIG_H
#include "stm32f10x.h"

/*滴答定时器时间配置*/
#define SYSTICK_TIME 1000

/*APP启动地址*/
#define APP_STATUP_ADDRESS  0X08004000


#endif /*_CONFIG_H*/




