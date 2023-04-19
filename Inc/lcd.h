/*
 * lcd.h
 *
 *  Created on: Sep 29, 2022
 *      Author: 31866
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "main.h"
#include "gpio.h"
#include "fsmc.h"
#include "tim.h"

//LCD地址结构体
typedef struct
{
	volatile uint16_t LCD_REG; //寄存器
	volatile uint16_t LCD_RAM; //数据
}LCD_TypeDef;

/*我们使用Bank1 的NE4，因此NE4
0X000007FE是A10的偏移量，7FE可化成 0111 1111 1110，
右移一位再加1就会变成1000 0000 0000，因此实现了对RS的控制：
RS=0时，写寄存器；RS=1，写数据；*/
#define LCD_BASE   ((uint32_t)(0x6C000000|0x000007FE))
#define LCD   ((LCD_TypeDef*)LCD_BASE)

//扫描方向定义
#define L2R_U2D  0 //从左到右,从上到下
#define L2R_D2U  1 //从左到右,从下到上
#define R2L_U2D  2 //从右到左,从上到下
#define R2L_D2U  3 //从右到左,从下到上

#define U2D_L2R  4 //从上到下,从左到右
#define U2D_R2L  5 //从上到下,从右到左
#define D2U_L2R  6 //从下到上,从左到右
#define D2U_R2L  7 //从下到上,从右到左

#define DFT_SCAN_DIR  L2R_U2D  //默认的扫描方向

//画笔颜色
#define WHITE           0xFFFF
#define BLACK           0x0000
#define BLUE            0x001F
#define BRED            0XF81F
#define GRED            0XFFE0
#define GBLUE           0X07FF
#define RED             0xF800
#define MAGENTA         0xF81F
#define GREEN           0x07E0
#define CYAN            0x7FFF
#define YELLOW          0xFFE0
#define BROWN           0XBC40  //棕色
#define BRRED           0XFC07  //棕红色
#define GRAY            0X8430  //灰色
//GUI颜色

#define DARKBLUE        0X01CF  //深蓝色
#define LIGHTBLUE       0X7D7C  //浅蓝色
#define GRAYBLUE        0X5458  //灰蓝色
//以上三色为PANEL的颜色

#define LIGHTGREEN      0X841F  //浅绿色
#define LGRAY           0XC618  //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE       0XA651  //浅灰蓝色(中间层颜色)
#define LBBLUE          0X2B12  //浅棕蓝色(选择条目的反色)

#define u8 uint8_t
#define u16 uint16_t
//LCD重要参数集
typedef struct
{
	uint16_t width;   //LCD宽度
	uint16_t height;  //LCD高度
	uint16_t id;   //LCD的ID号
	uint8_t dir;   //横屏还是竖屏控制
	uint16_t wramcmd;  //开始写GRAM指令
	uint16_t setxcmd;  //设置x坐标指令
	uint16_t setycmd;  //设置y坐标指令
}_lcd_dev;

//LCD参数
extern _lcd_dev lcddev;   //管理LCD重要参数

//画笔颜色
extern uint16_t POINT_COLOR;
extern u16  BACK_COLOR;     //背景颜色.默认为白色

//LCD分辨率设置
#define SSD_HOR_RESOLUTION      800     //LCD水平分辨率
#define SSD_VER_RESOLUTION      480     //LCD垂直分辨率
//LCD驱动参数设置
#define SSD_HOR_PULSE_WIDTH     1       //水平脉宽
#define SSD_HOR_BACK_PORCH      46      //水平前廊
#define SSD_HOR_FRONT_PORCH     210     //水平后廊

#define SSD_VER_PULSE_WIDTH     1       //垂直脉宽
#define SSD_VER_BACK_PORCH      23      //垂直前廊
#define SSD_VER_FRONT_PORCH     22      //垂直前廊
//如下几个参数，自动计算
#define SSD_HT  (SSD_HOR_RESOLUTION+SSD_HOR_BACK_PORCH+SSD_HOR_FRONT_PORCH)
#define SSD_HPS (SSD_HOR_BACK_PORCH)
#define SSD_VT  (SSD_VER_RESOLUTION+SSD_VER_BACK_PORCH+SSD_VER_FRONT_PORCH)
#define SSD_VPS (SSD_VER_BACK_PORCH)


//函数声明
void LCD_WR_REG(uint16_t regval);
void LCD_WR_DATA(uint16_t data);
void LCD_WR_DATA(uint16_t data);
uint16_t LCD_RD_DATA(void);
void LCD_WriteReg(uint16_t LCD_Reg,uint16_t LCD_RegValue);
uint16_t LCD_ReadReg(uint16_t LCD_Reg);
void LCD_WriteRAM_Prepare(void);
void LCD_WriteRAM(uint16_t RGB_Code);
uint16_t LCD_BGR2RGB(uint16_t c);
void opt_delay(uint8_t i);
uint16_t LCD_ReadPoint(uint16_t x, uint16_t y);
void LCD_DisplayOn(void);
void LCD_DisplayOff(void);
void LCD_Init(void);
void LCD_Clear(uint16_t color);
void LCD_Display_Dir(uint8_t dir);
void LCD_SSD_BackLightSet(uint8_t pwm);
void LCD_Scan_Dir(uint8_t dir);
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);
void LCD_DrawPoint(uint16_t x, uint16_t y);
void LCD_Fast_DrawPoint(uint16_t x, uint16_t y, uint16_t color);
void LCD_Fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t color);
void LCD_Color_Fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t *color);
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void LCD_DrawDashed(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint8_t interval);
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void LCD_Draw_Circle(uint16_t x0, uint16_t y0, uint8_t r);
void LCD_ShowChar(uint16_t x, uint16_t y, uint8_t num, uint8_t size, uint8_t mode);
uint32_t LCD_Pow(uint8_t m, uint8_t n);
void LCD_ShowNum(uint16_t x, uint16_t y, uint32_t num, uint8_t len, uint8_t size);
void LCD_ShowxNum(uint16_t x, uint16_t y, uint32_t num, uint8_t len, uint8_t size, uint8_t mode);
void LCD_ShowString(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t size, uint8_t *p);
void Chinese_Show_one(u8 x, u16 y,  u8 num, u8 size,u8 mode);
void DrawGrid(uint16_t yend);
int GetPlace(int n);
void DrawParameter();
void Show_Picture(u16 x,u16 y,u16 column,u16 row,unsigned short *pic);


#endif /* INC_LCD_H_ */
