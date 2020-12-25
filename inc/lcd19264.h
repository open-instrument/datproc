/* 
 * File:   lcd19264.h
 * Author: Administrator
 */

#ifndef Lcd_H
#define	Lcd_H

#include "ascii.h"
#include "lcd19264_hal.h"
#include "stdint.h"

#ifdef	__cplusplus
extern "C" {
#endif

/******************************************************************************
 * 基本设置接口
 *****************************************************************************/
void lcd_u8_init(void);
void lcd_u8_disp_buff_set(uint8_t *pbuff);//设置画布显存，必须在调用绘制API前设置
void lcd_u8_font_set(uint8_t Fontx, uint8_t Fonty, const uint8_t *Ascii); //x,y must be mul of 2  (y=8-56)(x=8-blocks*blocksize)，必须在绘制字符、文字前设置
void lcd_u8_half_en(void);//小数点半显
void lcd_u8_half_dis(void);//小数点正常显示
void lcd_u8_anti(void);//反显
void lcd_u8_normal(void);//正显
void lcd_u8_space_set(uint8_t Space);//字符串间距
void lcd_u8_origin_set(unsigned short x0,unsigned short y0);//绘制相对原点设置。接口所有xy坐标均受控，page不受控

/******************************************************************************
 * 绘制图形接口，基于画布操作，不受物理屏幕限制。
 * API中所有 x y坐标在画布中的的实际位置为 (x+x0, y+y0)。x0、y0是 lcd_u8_origin_set 设置的原点。
 * API中的page是画布中的页编号，和相对原点无关。
 *****************************************************************************/
void lcd_u8_put_space(unsigned short x,unsigned short y, unsigned char Amounts); //绘制空格
void lcd_u8_put_char(unsigned short x,unsigned short y, unsigned char DispCh); //绘制ASCII字符
void lcd_u8_put_cn(unsigned short x,unsigned short y,unsigned char const *pCN); //绘制中文
void lcd_u8_puts(unsigned short x,unsigned short y,unsigned char *DispStr);   //绘制ASCII字符串
void lcd_u8_put_nums(unsigned short x,unsigned short y,unsigned char *DispStr);  //点阵顺序 0123456789.-  //注意最后一个是空格
void lcd_u8_put_cns(unsigned short x,unsigned short y,unsigned char Amount, unsigned char const *pCN); //绘制中文文本
void lcd_u8_ram_set(unsigned short x,unsigned char Page,unsigned char Data);//设置显存内容
unsigned char lcd_u8_ram_read(unsigned short x,unsigned short Page);//读取显存内容
void lcd_u8_dot_set(unsigned short x,unsigned short y);//设置点
void lcd_u8_dot_clr(unsigned short x,unsigned short y);//清除点
void lcd_u8_ram_fill(unsigned char Val);//全显存内容
void lcd_u8_line( short x0, short y0, short x1, short y1);//绘制线
void lcd_u8_square(unsigned short x0,unsigned short y0,unsigned short x1,unsigned short y1);//绘制矩形
void lcd_u8_square_fill(unsigned short x0,unsigned short y0,unsigned short x1,unsigned short y1, uint8_t Dat);//绘制填充矩形

/******************************************************************************
 * 底层输出接口
 * 截取画布显示，该接口须实现 Lcd_Data_Write硬件输出
 * ram_cs：画布块数 
 * disp_cs: 显示块数
 * x0:截取画布x方向相对位置,以指针为基点
 * p_ram:画布显存，指针应对齐在画布行首
 *****************************************************************************/
void lcd_u8_poll(uint8_t ram_cs, uint8_t disp_cs, uint16_t x0,  uint8_t *p_ram); //将显存数据输出到端口

/******************************************************************************/
#ifdef	__cplusplus
}
#endif

#endif	/* Lcd_H */

