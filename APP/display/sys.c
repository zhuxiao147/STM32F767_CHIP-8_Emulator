#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F7开发板
//系统时钟初始化	
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2015/6/10
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved
//********************************************************************************
//修改说明
//无
////////////////////////////////////////////////////////////////////////////////// 

//使能CPU的L1-Cache
void Cache_Enable(void)
{
    SCB_EnableICache();//使能I-Cache
    SCB_EnableDCache();//使能D-Cache 
	SCB->CACR|=1<<2;   //强制D-Cache透写,如不开启,实际使用中可能遇到各种问题	
}

void delay_us(uint32_t us) {
    uint32_t count = us * 216 / 5; // 估算循环次数
    while (count--) {
        __NOP();  // 空操作，防止优化
    }
}

void delay_ms(uint32_t ms) {
    while (ms--) {
        delay_us(1000);  // 调用微秒延时
    }
}

#ifdef  USE_FULL_ASSERT
//当编译提示出错的时候此函数用来报告错误的文件和所在行
//file：指向源文件
//line：指向在文件中的行数
void assert_failed(uint8_t* file, uint32_t line)
{ 
	while (1)
	{
	}
}
#endif

//判断I_Cache是否打开
//返回值:0 关闭，1 打开
// u8 Get_ICahceSta(void)
// {
//     u8 sta;
//     sta=((SCB->CCR)>>17)&0X01;
//     return sta;
// }

// //判断I_Dache是否打开
// //返回值:0 关闭，1 打开
// u8 Get_DCahceSta(void)
// {
//     u8 sta;
//     sta=((SCB->CCR)>>16)&0X01;
//     return sta;
// }

// //THUMB指令不支持汇编内联
// //采用如下方法实现执行汇编指令WFI  
// __asm void WFI_SET(void)
// {
// 	WFI;		  
// }
// //关闭所有中断(但是不包括fault和NMI中断)
// __asm void INTX_DISABLE(void)
// {
// 	CPSID   I
// 	BX      LR	  
// }
// //开启所有中断
// __asm void INTX_ENABLE(void)
// {
// 	CPSIE   I
// 	BX      LR  
// }
// //设置栈顶地址
// //addr:栈顶地址
// __asm void MSR_MSP(u32 addr) 
// {
// 	MSR MSP, r0 			//set Main Stack value
// 	BX r14
// }
