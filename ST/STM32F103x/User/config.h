/*���ļ���boot����������ļ�����ͨ���޸ĸ��ļ������䲻ͬ�ͺŵ�STM32F103X
* �ĵ�Ƭ��������ص�ҵ����������ַ�� ���ڹ��ܵ�*/

/*This file is the configuration file of the boot program. You can 
* modify this file to adapt different models of STM32F103X microcontroller 
* and related services, such as startup address and serial port function*/
#ifndef _CONFIG_H
#define _CONFIG_H
#include "stm32f10x.h"

/*�δ�ʱ��ʱ������*/
#define SYSTICK_TIME 1000

/*APP������ַ*/
#define APP_STATUP_ADDRESS  0X08004000


#endif /*_CONFIG_H*/




