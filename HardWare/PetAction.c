#include "stm32f10x.h"                  // Device header
#include "Servo.h"
#include "Delay.h"
#include "BlueTooth.h"

	/*舵机位置
	    1        2
	
	

	
	    3        4
	*/
	
	//舵机充当腿，括号里的值为0时表示的是腿向前进的方向甩，90度是站立
uint16_t TiaoTurn=0;
uint16_t TiaoTurn2=0;

void Action_relaxed_getdowm(void)
{
	Servo_Angle1(20);
	Servo_Angle2(20);
	Delay_ms(150);
	Servo_Angle3(20);
	Servo_Angle4(20);
}

void Action_upright(void)//站立
{
	Servo_Angle1(90);
	Servo_Angle2(90);
	Delay_ms(150);
	Servo_Angle3(90);
	Servo_Angle4(90);
	
	if(WeiBa==1)
	{
		Action_Mode=9;
	}
	
}

void Action_upright2(void)//站立2
{
	Servo_Angle3(90);
	Servo_Angle4(90);
	Delay_ms(150);
	Servo_Angle1(90);
	Servo_Angle2(90);
	
	if(WeiBa==1)
	{
		Action_Mode=9;
	}
}

void Action_getdowm(void)//趴下
{
	Servo_Angle1(20);
	Servo_Angle2(20);
	Delay_ms(150);
	Servo_Angle3(20);
	Servo_Angle4(20);
	
	if(WeiBa==1)
	{
		Action_Mode=9;
	}
}

void Action_sit(void)//坐下
{
	Servo_Angle1(90);
	Servo_Angle2(90);
	Delay_ms(150);
	Servo_Angle3(20);
	Servo_Angle4(20);
	
	if(WeiBa==1)
	{
		Action_Mode=9;
	}
}

void Action_juepi(void)//撅屁
{
	Servo_Angle1(20);
	Servo_Angle2(20);
	Delay_ms(150);
	Servo_Angle3(90);
	Servo_Angle4(90);
	
	if(WeiBa==1)
	{
		Action_Mode=9;
	}
}

void Action_sleep(void)//睡觉
{
	Servo_Angle1(20);
	Servo_Angle2(20);
	Delay_ms(150);
	Servo_Angle3(180);
	Servo_Angle4(180);
}

void Action_advance(void)//前进
{

	while(Action_Mode==4)
	{

			Servo_Angle2(45);	
			Servo_Angle3(45);
			Delay_ms(SpeedDelay);
			if(Action_Mode!=4)break;
			Servo_Angle1(135);	
			Servo_Angle4(135);
			Delay_ms(SpeedDelay);
			if(Action_Mode!=4)break;
			Servo_Angle2(90);	
			Servo_Angle3(90);
			Delay_ms(SpeedDelay);
			if(Action_Mode!=4)break;
			Servo_Angle1(90);	
			Servo_Angle4(90);
			Delay_ms(SpeedDelay);
			if(Action_Mode!=4)break;
	
			Servo_Angle1(45);	
			Servo_Angle4(45);
			Delay_ms(SpeedDelay);
			if(Action_Mode!=4)break;
			Servo_Angle2(135);	
			Servo_Angle3(135);
			Delay_ms(SpeedDelay);
			if(Action_Mode!=4)break;
			Servo_Angle1(90);	
			Servo_Angle4(90);
			Delay_ms(SpeedDelay);
			if(Action_Mode!=4)break;
			Servo_Angle2(90);	
			Servo_Angle3(90);
			Delay_ms(SpeedDelay);
			if(Action_Mode!=4)break;
		
	}
}

void Action_back(void)//后退
{
	while(Action_Mode==5)
	{

		Servo_Angle2(135);	
		Servo_Angle3(135);
		Delay_ms(SpeedDelay);
		if(Action_Mode!=5)break;
		Servo_Angle1(45);	
		Servo_Angle4(45);
		Delay_ms(SpeedDelay);
		if(Action_Mode!=5)break;
		Servo_Angle2(90);	
		Servo_Angle3(90);
		Delay_ms(SpeedDelay);
		if(Action_Mode!=5)break;
		Servo_Angle1(90);	
		Servo_Angle4(90);
		Delay_ms(SpeedDelay);
		if(Action_Mode!=5)break;
		
		Servo_Angle1(135);	
		Servo_Angle4(135);
		Delay_ms(SpeedDelay);
		if(Action_Mode!=5)break;
		Servo_Angle2(45);	
		Servo_Angle3(45);
		Delay_ms(SpeedDelay);
		if(Action_Mode!=5)break;
		Servo_Angle1(90);	
		Servo_Angle4(90);
		Delay_ms(SpeedDelay);
		if(Action_Mode!=5)break;
		Servo_Angle2(90);	
		Servo_Angle3(90);
		Delay_ms(SpeedDelay);
		if(Action_Mode!=5)break;

	}
}

void Action_Lrotation(void)//向左旋转
{
	while(Action_Mode==6)
	{
		Servo_Angle2(45);
		Servo_Angle3(135);
		Delay_ms(SpeedDelay);
		if(Action_Mode!=6)break;
		Servo_Angle1(45);
		Servo_Angle4(135);
		Delay_ms(SpeedDelay);
		if(Action_Mode!=6)break;
		Servo_Angle2(90);
		Servo_Angle3(90);	
		Delay_ms(SpeedDelay);
		if(Action_Mode!=6)break;
		Servo_Angle1(90);
		Servo_Angle4(90);	
		Delay_ms(SpeedDelay);
		if(Action_Mode!=6)break;
	}

}


void Action_Rrotation(void)//向右旋转
{
	while(Action_Mode==7)
	{
		Servo_Angle1(45);
		Servo_Angle4(135);
		Delay_ms(SpeedDelay);
		if(Action_Mode!=7)break;
		Servo_Angle2(45);
		Servo_Angle3(135);
		Delay_ms(SpeedDelay);
		if(Action_Mode!=7)break;
		Servo_Angle1(90);
		Servo_Angle4(90);	
		Delay_ms(SpeedDelay);
		if(Action_Mode!=7)break;
		Servo_Angle2(90);
		Servo_Angle3(90);	
		Delay_ms(SpeedDelay);
		if(Action_Mode!=7)break;
	}

}

void Action_Swing(void)//摇摆
{
	while(Action_Mode==8)
	{
		for(uint8_t i=30;i<150;i++)
		{
			Servo_Angle1(i);
			Servo_Angle2(i);
			Servo_Angle3(i);
			Servo_Angle4(i);
			Delay_ms(SwingDelay);
			if(Action_Mode!=8)break;
		}
		for(uint8_t i=150;i>30;i--)
		{
			Servo_Angle1(i);
			Servo_Angle2(i);
			Servo_Angle3(i);
			Servo_Angle4(i);
			Delay_ms(SwingDelay);
			if(Action_Mode!=8)break;
		}
		if(Action_Mode!=8)break;
	}
}


void Action_SwingTail(void)//摇尾巴
{
	Delay_ms(150);
	while(Action_Mode==9)
	{
		for(uint8_t i=30;i<150;i++)
		{
			WServo_Angle(i);
			Delay_ms(SwingDelay);
			if(Action_Mode!=9)break;
		}
		for(uint8_t i=150;i>30;i--)
		{
			WServo_Angle(i);
			Delay_ms(SwingDelay);
			if(Action_Mode!=9)break;
		}
		if(Action_Mode!=9)break;
	}
	Delay_ms(150);
}

void Action_JumpU(void)//向前跳
{
	if(TiaoTurn==0)
	{
		Servo_Angle1(140);
		Servo_Angle4(35);
		Delay_ms(SpeedDelay);
		
		Servo_Angle2(140);
		Servo_Angle3(35);
		Delay_ms(SpeedDelay+80);
		
		Action_Mode=2;
		TiaoTurn=1;
	}
	else
	{
		Servo_Angle2(140);
		Servo_Angle3(35);
		Delay_ms(SpeedDelay);
		
		Servo_Angle1(140);
		Servo_Angle4(35);
		Delay_ms(SpeedDelay+80);
		
		Action_Mode=2;
		TiaoTurn=0;
	}
}

void Action_JumpD(void)//向后跳
{
	if(TiaoTurn2==0){
		Servo_Angle4(35);
		Servo_Angle1(140);
		Delay_ms(SpeedDelay);
	
		Servo_Angle3(35);
		Servo_Angle2(140);
		Delay_ms(SpeedDelay);
	
		Action_Mode=12;
		TiaoTurn2=1;
	}
	else
	{
		Servo_Angle3(35);
		Servo_Angle2(140);
		Delay_ms(SpeedDelay);
	
		Servo_Angle4(35);
		Servo_Angle1(140);
		Delay_ms(SpeedDelay);
	
		Action_Mode=12;
		TiaoTurn2=0;
	}
}
void Action_Hello(void)//打招呼
{
	Servo_Angle3(20);
	Servo_Angle4(45);
	Delay_ms(150);
	Servo_Angle1(90);
	while(Action_Mode==13)
	{
		if(Action_Mode!=13)break;
		for(int i=0;i<=45;i++)
		{
			if(Action_Mode!=13)break;
			Servo_Angle2(i);
			Delay_ms(SwingDelay);
		}
		for(int i=45;i>0;i--)
		{
			if(Action_Mode!=13)break;
			Servo_Angle2(i);
			Delay_ms(SwingDelay);
		}
		if(Action_Mode!=13)break;
	}
}
void Action_dance(void)//跳舞
{while(Action_Mode==14)
	{
	Servo_Angle1(135);
	Servo_Angle2(135);
	Delay_ms(SpeedDelay);
	Servo_Angle3(135);
	Servo_Angle4(135);
	Delay_ms(SpeedDelay);
	Servo_Angle1(90);
	Servo_Angle2(90);
	Delay_ms(SpeedDelay);
	Servo_Angle3(90);
	Servo_Angle4(90);
	Delay_ms(SpeedDelay);
	
	Servo_Angle2(135);
	Servo_Angle1(135);
	Servo_Angle3(45);
	Servo_Angle4(45);
	Delay_ms(150);
	Servo_Angle1(90);
	Servo_Angle2(90);
	Servo_Angle3(90);
	Servo_Angle4(90);
	Delay_ms(150);
	
	
	Servo_Angle3(45);
	Servo_Angle4(45);
	Delay_ms(SpeedDelay);
	Servo_Angle1(45);
	Servo_Angle2(45);
	Delay_ms(SpeedDelay);
	Servo_Angle3(90);
	Servo_Angle4(90);
	Delay_ms(SpeedDelay);
	Servo_Angle1(90);
	Servo_Angle2(90);
	Delay_ms(SpeedDelay);
	
	Servo_Angle2(45);
	Servo_Angle1(45);
	Servo_Angle3(135);
	Servo_Angle4(135);
	Delay_ms(150);
	Servo_Angle1(90);
	Servo_Angle2(90);
	Servo_Angle3(90);
	Servo_Angle4(90);
	Delay_ms(150);
	}
}

void Action_stretch(void)//伸懒腰
{
	Servo_Angle3(90);
	Servo_Angle4(90);
	Delay_ms(80);
	for(int i=90;i>10;i--)
	{
		Servo_Angle1(i);
		Servo_Angle2(i);
		if(Action_Mode!=19)break;
		Delay_ms(15);
	}
	for(int i=10;i<90;i++)
	{
		Servo_Angle1(i);
		Servo_Angle2(i);
		if(Action_Mode!=19)break;
		Delay_ms(15);
	}
	for(int i=90;i<170;i++)
	{
		Servo_Angle3(i);
		Servo_Angle4(i);
		if(Action_Mode!=19)break;
		Delay_ms(15);
	}
	
	for(int i=170;i>90;i--)
	{
		Servo_Angle3(i);
		Servo_Angle4(i);
		if(Action_Mode!=19)break;
		Delay_ms(15);
	}
	if(Action_Mode==19)
	Action_Mode=20;
}

void Action_Lstretch(void)//后腿拉伸
{
	int breakvalue=1;
	int temp=3;
	while(breakvalue)
	{
		Servo_Angle1(90);
		Servo_Angle2(20);
		Delay_ms(60);
		Servo_Angle4(110);
		for(int i=90;i<180;i++)
		{
			if(Action_Mode!=20)break;
			Servo_Angle3(i);
			Delay_ms(6);
		}
		while(temp && Action_Mode==20)
		{
			for(int i=180;i>150;i--)
			{
				if(Action_Mode!=20)break;
				Servo_Angle3(i);
				Delay_ms(15);
			}
			temp--;
		}
		if(Action_Mode!=20)break;
		Delay_ms(100);
		Servo_Angle1(90);
		Servo_Angle2(90);
		if(Action_Mode!=20)break;
		Delay_ms(80);
		Servo_Angle3(90);
		Servo_Angle4(90);
		Delay_ms(100);
		if(Action_Mode!=20)break;
		
		temp=3;
		
		Servo_Angle2(90);
		Servo_Angle1(20);
		if(Action_Mode!=20)break;
		Delay_ms(60);
		Servo_Angle3(110);
		for(int i=90;i<180;i++)
		{
			if(Action_Mode!=20)break;
			Servo_Angle4(i);
			Delay_ms(6);
		}
		while(temp && Action_Mode==20)
		{
			for(int i=180;i>150;i--)
			{
				if(Action_Mode!=20)break;
				Servo_Angle4(i);
				Delay_ms(15);
			}
			temp--;
		}
		if(Action_Mode==20)
		Action_Mode=2;
		
		
		breakvalue=0;
		}
	}
