#include "stm32f10x.h"                  // Device header
//Ϊ�������Ϸ���
extern uint16_t Time;
void Timer_Init(void)
{
	Time = 0;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	//ѡ��APB1�����µĶ�ʱ��Timer2
	
	TIM_InternalClockConfig(TIM2);		//TIM2ʹ���ڲ�ʱ��
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;		//����ģʽ���˴�Ϊ���ϼ���
	TIM_TimeBaseInitStructure.TIM_Period = 7200-1;		//ARR 1 = 0.0001S
	TIM_TimeBaseInitStructure.TIM_Prescaler = 0;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;		//�߼���ʱ�����У��ظ�����
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);		//ʹ���ж�
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;		//�ж�ͨ��ѡ��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		//���ȼ���ͬ��
	
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM2, ENABLE);		//�򿪶�ʱ��
	
}
void TIM2_IRQHandler()		//��ʱ��2���жϺ���
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{

		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15) == 1)
		{
			Time ++;
		}
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);		//��ձ�־λ
	}
}
