#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "BlueTooth.h"
#include "Servo.h"
#include "PetAction.h"
#include "Face_Config.h"
#include "UltrasonicWave.h"

int main(void)
{
	Servo_Init();//舵机初始化
	OLED_Init();//OLED初始化
	BlueTooth_Init();//蓝牙初始化
	OLED_ShowImage(0,0,128,64,Face_sing);
	OLED_Update();
	while(1)
	{	
		if(Action_Mode==3){Action_relaxed_getdowm();WServo_Angle(90);}//放松趴下
		else if(Action_Mode==1){Action_sit();}//坐下
		else if(Action_Mode==2){Action_upright();}//站立
		else if(Action_Mode==3){Action_getdowm();}//趴下
		else if(Action_Mode==4){Action_advance();}//前进
		else if(Action_Mode==5){Action_back();}//后退
		else if(Action_Mode==6){Action_Lrotation();}//左转
		else if(Action_Mode==7){Action_Rrotation();}//右转
		else if(Action_Mode==8){Action_Swing();}//摇摆
		else if(Action_Mode==9){Action_SwingTail();}//摇尾巴
		else if(Action_Mode==10){Action_JumpU();}//前跳
		else if(Action_Mode==11){Action_JumpD();}//后跳
		else if(Action_Mode==12){Action_upright2();}//站立方式2
		else if(Action_Mode==13){Action_Hello();}//打招呼
		else if(Action_Mode==14){Action_dance();}//跳舞
		else if(Action_Mode==17){Action_juepi();}//撅屁股
		else if(Action_Mode==18){Action_sleep();}//睡觉
		else if(Action_Mode==19){Action_stretch();}//伸懒腰
		else if(Action_Mode==20){Action_Lstretch();}//后退拉伸
	}
}
