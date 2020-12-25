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
 * �������ýӿ�
 *****************************************************************************/
void lcd_u8_init(void);
void lcd_u8_disp_buff_set(uint8_t *pbuff);//���û����Դ棬�����ڵ��û���APIǰ����
void lcd_u8_font_set(uint8_t Fontx, uint8_t Fonty, const uint8_t *Ascii); //x,y must be mul of 2  (y=8-56)(x=8-blocks*blocksize)�������ڻ����ַ�������ǰ����
void lcd_u8_half_en(void);//С�������
void lcd_u8_half_dis(void);//С����������ʾ
void lcd_u8_anti(void);//����
void lcd_u8_normal(void);//����
void lcd_u8_space_set(uint8_t Space);//�ַ������
void lcd_u8_origin_set(unsigned short x0,unsigned short y0);//�������ԭ�����á��ӿ�����xy������ܿأ�page���ܿ�

/******************************************************************************
 * ����ͼ�νӿڣ����ڻ�������������������Ļ���ơ�
 * API������ x y�����ڻ����еĵ�ʵ��λ��Ϊ (x+x0, y+y0)��x0��y0�� lcd_u8_origin_set ���õ�ԭ�㡣
 * API�е�page�ǻ����е�ҳ��ţ������ԭ���޹ء�
 *****************************************************************************/
void lcd_u8_put_space(unsigned short x,unsigned short y, unsigned char Amounts); //���ƿո�
void lcd_u8_put_char(unsigned short x,unsigned short y, unsigned char DispCh); //����ASCII�ַ�
void lcd_u8_put_cn(unsigned short x,unsigned short y,unsigned char const *pCN); //��������
void lcd_u8_puts(unsigned short x,unsigned short y,unsigned char *DispStr);   //����ASCII�ַ���
void lcd_u8_put_nums(unsigned short x,unsigned short y,unsigned char *DispStr);  //����˳�� 0123456789.-  //ע�����һ���ǿո�
void lcd_u8_put_cns(unsigned short x,unsigned short y,unsigned char Amount, unsigned char const *pCN); //���������ı�
void lcd_u8_ram_set(unsigned short x,unsigned char Page,unsigned char Data);//�����Դ�����
unsigned char lcd_u8_ram_read(unsigned short x,unsigned short Page);//��ȡ�Դ�����
void lcd_u8_dot_set(unsigned short x,unsigned short y);//���õ�
void lcd_u8_dot_clr(unsigned short x,unsigned short y);//�����
void lcd_u8_ram_fill(unsigned char Val);//ȫ�Դ�����
void lcd_u8_line( short x0, short y0, short x1, short y1);//������
void lcd_u8_square(unsigned short x0,unsigned short y0,unsigned short x1,unsigned short y1);//���ƾ���
void lcd_u8_square_fill(unsigned short x0,unsigned short y0,unsigned short x1,unsigned short y1, uint8_t Dat);//����������

/******************************************************************************
 * �ײ�����ӿ�
 * ��ȡ������ʾ���ýӿ���ʵ�� Lcd_Data_WriteӲ�����
 * ram_cs���������� 
 * disp_cs: ��ʾ����
 * x0:��ȡ����x�������λ��,��ָ��Ϊ����
 * p_ram:�����Դ棬ָ��Ӧ�����ڻ�������
 *****************************************************************************/
void lcd_u8_poll(uint8_t ram_cs, uint8_t disp_cs, uint16_t x0,  uint8_t *p_ram); //���Դ�����������˿�

/******************************************************************************/
#ifdef	__cplusplus
}
#endif

#endif	/* Lcd_H */

