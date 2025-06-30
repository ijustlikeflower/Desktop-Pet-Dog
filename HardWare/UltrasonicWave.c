#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Timer.h"
#include "PetAction.h"
//***��������***//
extern uint16_t T;  //��¼����
int cf=0;//��¼�ظ����� ���bug��

uint16_t Time; //��¼ʱ��
void UltrasonicWave_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//����GPIOB��ʱ��
	/*GPIO��ʼ��*/ 
	GPIO_InitTypeDef GPIO_InitStructure;
	

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);					//��PB14 TRIG
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);					//��PB15 ECHO

	GPIO_ResetBits(GPIOB, GPIO_Pin_14);
	
	
}
void UltrasonicWave_Start(void)
{
	//�������ź�
	GPIO_SetBits(GPIOB, GPIO_Pin_14);
	Delay_us(45);
	GPIO_ResetBits(GPIOB, GPIO_Pin_14);

	
	Timer_Init();  //��ʱ ����ʱ��������
}

uint16_t UltrasonicWave_Getvalue(void)
{
	UltrasonicWave_Start();
	Delay_ms(100);
	return ((Time * 0.0001) * 34000) / 2;
}
void Bizhang(void)
{
	T=UltrasonicWave_Getvalue();
	Delay_ms(10);
	if(T>=15)
	{
		{
		Action_advance();
		//Delay_ms(10);
		cf++;
		}
	}
	else
	{
		//move_behind();
		T=UltrasonicWave_Getvalue();
	while(T<15)
	{	cf=0;  
		Action_Rrotation();//һ��Լ30��
		Action_Rrotation();
		Delay_ms(10);
		T=UltrasonicWave_Getvalue();
		if(T>15)
		{
			break;
		}
	}	
}
}
