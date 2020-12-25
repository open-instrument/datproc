/* 
 * File:   flt.h
 * Author: apleilx
 */

#ifndef __FILTERN_H_
#define	__FILTERN_H_

#include "stdint.h"

#ifdef	__cplusplus
extern "C" {
#endif
/****************************************************************************
 * ȡ�����Сֵ
 * ����ָ�����Ϊ0����ʱ��Ӧ�Ĳ�����Ч
 * ����Դ����
 * dat-����Դ
 * len-���ݳ���
 * pmax_index - ���ڱ������ֵ�������
 * pmin_index - ���ڱ�����Сֵ�������
 * **************************************************************************/
int i16_maxmin_get(int16_t *dat, uint16_t Len, uint16_t *pmax_index, uint16_t *pmin_index);
int u16_maxmin_get(uint16_t *dat, uint16_t Len, uint16_t *pmax_index, uint16_t *pmin_index);
int i32_maxmin_get(int32_t *dat, uint16_t Len, uint16_t *pmax_index, uint16_t *pmin_index);
int u32_maxmin_get(uint32_t *dat, uint16_t Len, uint16_t *pmax_index, uint16_t *pmin_index);

/****************************************************************************
 * ƽ��ֵ�˲� 
 * ȥ�������Сֵ����������Ԫ��, ����Դ����
 * dat-����Դ
 * len-���ݳ���
 * **************************************************************************/
int16_t i16_average_filter(int16_t *dat, uint16_t Len);
uint16_t ui16_average_filter(uint16_t *dat, uint16_t Len);
int32_t i32_average_filter(int32_t *dat, uint16_t Len);
uint32_t u32_average_filter(uint32_t *dat, uint16_t Len);

/****************************************************************************
 * ��λֵ�˲� 
 * �ڲ�ִ������
 * ��ı�Դ����Ԫ��˳��
 * dat-����Դ
 * len-���ݳ���
 * **************************************************************************/
int16_t i16_middle_filter(int16_t *dat, uint16_t Len);
uint16_t u16_middle_filter(uint16_t *dat, uint16_t Len);
int32_t i32_middle_filter(int32_t *dat, uint16_t Len);
uint32_t u32_middle_filter(uint32_t *dat, uint16_t Len);

/****************************************************************************
 * ��ֵƽ���˲� , �ص�CutLen�����ֵ��CutLen����Сֵ��ʣ������ƽ����
 * �ڲ�ִ�����򣬻�ı�Ԫ��˳��
 * **************************************************************************/
int32_t i32_middle_average_filter(int32_t *dat, uint16_t Len, uint16_t CutLen);
uint32_t u32_middle_average_filter(uint32_t *dat, uint16_t Len, uint16_t CutLen);
int16_t i16_middle_average_filter(int16_t *dat, uint16_t Len, uint16_t CutLen);
uint16_t ui16_middle_average_filter(uint16_t *dat, uint16_t Len, uint16_t CutLen);

/****************************************************************************
 * ��Ȩ�˲� 
 * Ȩֵ���鳤�ȱ����Lenһ�£�StartIndexָʾ��������Ԫ��λ��
 * ��֤Ȩֵ����ֵ�ĳ˻������� u32, Ȩֵ�б�Ͳ�Ϊ0
 * Ȩֵ�б��һ��Ԫ��Ϊ����ֵȨֵ�������Դ�����
 * **************************************************************************/
uint32_t u32_coef_filter(uint32_t *dat, uint16_t *coef, uint16_t StartIndex, uint16_t Len);
uint16_t u16_coef_filter(uint16_t *dat, uint16_t *coef, uint16_t StartIndex, uint16_t Len);


/****************************************************************************
 * 3���˲� 
 * **************************************************************************/
 typedef struct
 {
    float flt_coef; //0.001~0.999
    float out_order1; //1�����
    float out_order2; //2�����
    float out_order3; //2�����
 } f_order_filter_type;
/****************************************************************************
 * �����˲� 
 * ����ʵ��ִ�е��˲�ϵ��
 * **************************************************************************/
float f_order_filter (f_order_filter_type *flt, float new_data);
 
 
#ifdef	__cplusplus
}
#endif

#endif	/* __FILTERN_H_ */

