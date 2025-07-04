#include "stm32f10x.h"      
#include "OLED.h"
#include "BlueTooth.h"

//实现表情变化，调节是进中断后

void Face_Config(void)
{
	if(Face_Mode==0)
	{	
		OLED_Clear();
		OLED_ShowImage(0,0,128,64,Face_sleep);//睡觉
		OLED_Update();
	}
	else if(Face_Mode==1)
	{	
		OLED_Clear();
		OLED_ShowImage(0,0,128,64,Face_stare);//瞪大眼
		OLED_Update();
	}
	else if(Face_Mode==2)
	{
		OLED_Clear();
		OLED_ShowImage(0,0,128,64,Face_happy);//快乐
		OLED_Update();
	}
	else if(Face_Mode==3)
	{
		OLED_Clear();
		OLED_ShowImage(0,0,128,64,Face_mania);//狂热
		OLED_Update();
	}
	else if(Face_Mode==4)
	{
		OLED_Clear();
		OLED_ShowImage(0,0,128,64,Face_very_happy);//非常快乐
		OLED_Update();
	}
	else if(Face_Mode==5)
	{
		OLED_Clear();
		OLED_ShowImage(0,0,128,64,Face_eyes);//眼睛
		OLED_Update();
	}
	else if(Face_Mode==6)
	{
		OLED_Clear();
		OLED_ShowImage(0,0,128,64,Face_hello);//打招呼
		OLED_Update();
	}
	else if(Face_Mode==7)
	{
		OLED_Clear();
		OLED_ShowImage(0,0,128,64,Face_left);//左转
		OLED_Update();
	}
	else if(Face_Mode==8)
	{
		OLED_Clear();
		OLED_ShowImage(0,0,128,64,Face_right);//右转
		OLED_Update();
	}
	else if(Face_Mode==9)
	{
		OLED_Clear();
		OLED_ShowImage(0,0,128,64,Face_sing);//唱歌
		OLED_Update();
	}
	else if(Face_Mode==10)
	{
		OLED_Clear();
		OLED_ShowImage(0,0,128,64,Face_haha);//哈哈
		OLED_Update();
	}
	else if(Face_Mode==11)
	{
		OLED_Clear();
		OLED_ShowImage(0,0,128,64,Face_wuyu);//无语
		OLED_Update();
	}
	else if(Face_Mode==12)
	{
		OLED_Clear();
		OLED_ShowImage(0,0,128,64,Face_xiaosheng);//小声
		OLED_Update();
	}
	else if(Face_Mode==13)
	{
		OLED_Clear();
		OLED_ShowImage(0,0,128,64,Face_dasheng);//大声
		OLED_Update();
	}
	else if(Face_Mode==14)
	{
		OLED_Clear();
		OLED_ShowImage(0,0,128,64,Face_exit);//退出
		OLED_Update();
	}
	else if(Face_Mode==15)
	{
		OLED_Clear();
		OLED_ShowImage(0,0,128,64,Face_mihu);//迷糊脸
		OLED_Update();
	}
}
