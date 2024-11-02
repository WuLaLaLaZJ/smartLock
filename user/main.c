#include "stm32f10x.h"
#include"Delay.h"

int main(void)
{	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA,ENABLE);//开启时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;//定义结构体
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;//GPIO模式，推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//GPIO的0号引脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//输出速度
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//第一个参数是指初始化GPIOA端口，第二个指初始化GPIO_InitStructure，以便用来定义
	//&指需要结构体的地址来进行初始化
	
	//GPIO_ResetBits(GPIOA,GPIO_Pin_0);//低电平设置函数	
	//GPIO_SetBits(GPIOA,GPIO_Pin_0);//高电平设置函数
	//GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);//第三个变量是一个枚举enum变量,可以在Bit_RESET和Bit_SET中选择
	
	


	while(1)
	{
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
		GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_SET);
		Delay_ms(500);
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);
		GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_RESET);
		Delay_ms(500);
		
	}
}
