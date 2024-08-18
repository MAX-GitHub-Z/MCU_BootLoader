# 关于基于单片机的BOOT程序说明

## 目标：通过单片机的BOOT程序实现APP程序的更新

计划使用串口+上位机的方式实现APP程序的更新

## BOOT成果物

每个工程里面都会有一个 output 文件夹，文件夹中有一个 output.py python脚本，在编译工程之后会自动触发该脚本，将成果物更新到该文件夹下

## 文件含义

一级目录下是芯片厂家的型号 如：

STM32 简称ST  

GD32 简称GD

二级目录是常用型号下的BOOT程序与APP程序 如 

STM32F103x 是指该型号的固件库BOOT程序 

STM32F103x_app是指对应的APP程序

## APP程序编译引导注意事项

1、修改IROM1的起始地址，按照BOOT程序中规划的APP起始地址进行修改，例如起始地址为：0x0800 4000时如图：

Size大小，需要根据芯片的大小具体进行修改与填写，如STM32F103C8T6 flash：0x0800 0000 ~ 0x0800 FFFF 共64K

size = 0x0800 FFFF - 0x0800 4000 +1 =0x0000 c000



![](doc/figures/boot%E7%A8%8B%E5%BA%8FAPP%E5%BC%95%E5%AF%BC%E7%BC%96%E8%AF%91.jpg)

2、修改中断向量偏向量

STM32F103的向量表 的宏定义为： VECT_TAB_OFFSET 在 system_stm32f10x.c 中定义 如图：

![](doc/figures/APP%E4%BF%AE%E6%94%B9%E4%B8%AD%E6%96%AD%E5%81%8F%E7%A7%BB%E9%87%8F.jpg)

修改的大小=APP程序的起始地址-BOOT程序的起始地址

如本项目的例程中 BOOT 程序的起始地址为 0x0800 0000 ,APP 的起始地址为 0x0800 4000.则修改的大小为0x4000

3、当你完成了这两步时，就可以使用BOOT引导对应APP并启动APP了

