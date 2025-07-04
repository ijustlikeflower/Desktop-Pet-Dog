#ifndef __OLED_DATA_H
#define __OLED_DATA_H

#include <stdint.h>

/*中文字符字节宽度*/
#define OLED_CHN_CHAR_WIDTH			3		//UTF-8编码格式给3，GB2312编码格式给2

/*字模基本单元*/
typedef struct 
{
	char Index[OLED_CHN_CHAR_WIDTH + 1];	//汉字索引
	uint8_t Data[32];						//字模数据
} ChineseCell_t;

/*ASCII字模数据声明*/
extern const uint8_t OLED_F8x16[][16];
extern const uint8_t OLED_F6x8[][6];

/*汉字字模数据声明*/
extern const ChineseCell_t OLED_CF16x16[];

/*图像数据声明*/
extern const uint8_t Diode[];
extern const uint8_t Face_eyes[];
extern const uint8_t Face_happy[];
extern const uint8_t Face_mania[];
extern const uint8_t Face_sleep[];
extern const uint8_t Face_stare[];
extern const uint8_t Face_very_happy[];
extern const uint8_t Face_hello[];
extern const uint8_t Face_left[];
extern const uint8_t Face_right[];
extern const uint8_t Face_sing[];
extern const uint8_t Face_haha[];
extern const uint8_t Face_wuyu[];
extern const uint8_t Face_xiaosheng[];
extern const uint8_t Face_dasheng[];
extern const uint8_t Face_exit[];
extern const uint8_t Face_mihu[];
/*按照上面的格式，在这个位置加入新的图像数据声明*/
//...

#endif

