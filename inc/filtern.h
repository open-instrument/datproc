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
 * 取最大最小值
 * 索引指针可以为0，此时对应的参数无效
 * 不变源数据
 * dat-数据源
 * len-数据长度
 * pmax_index - 用于保存最大值索引编号
 * pmin_index - 用于保存最小值索引编号
 * **************************************************************************/
int i16_maxmin_get(int16_t *dat, uint16_t Len, uint16_t *pmax_index, uint16_t *pmin_index);
int u16_maxmin_get(uint16_t *dat, uint16_t Len, uint16_t *pmax_index, uint16_t *pmin_index);
int i32_maxmin_get(int32_t *dat, uint16_t Len, uint16_t *pmax_index, uint16_t *pmin_index);
int u32_maxmin_get(uint32_t *dat, uint16_t Len, uint16_t *pmax_index, uint16_t *pmin_index);

/****************************************************************************
 * 平均值滤波 
 * 去掉最大最小值，最少三个元素, 不变源数据
 * dat-数据源
 * len-数据长度
 * **************************************************************************/
int16_t i16_average_filter(int16_t *dat, uint16_t Len);
uint16_t ui16_average_filter(uint16_t *dat, uint16_t Len);
int32_t i32_average_filter(int32_t *dat, uint16_t Len);
uint32_t u32_average_filter(uint32_t *dat, uint16_t Len);

/****************************************************************************
 * 中位值滤波 
 * 内部执行排序
 * 会改变源数据元素顺序
 * dat-数据源
 * len-数据长度
 * **************************************************************************/
int16_t i16_middle_filter(int16_t *dat, uint16_t Len);
uint16_t u16_middle_filter(uint16_t *dat, uint16_t Len);
int32_t i32_middle_filter(int32_t *dat, uint16_t Len);
uint32_t u32_middle_filter(uint32_t *dat, uint16_t Len);

/****************************************************************************
 * 中值平均滤波 , 截掉CutLen个最大值和CutLen个最小值，剩余数据平均数
 * 内部执行排序，会改变元素顺序
 * **************************************************************************/
int32_t i32_middle_average_filter(int32_t *dat, uint16_t Len, uint16_t CutLen);
uint32_t u32_middle_average_filter(uint32_t *dat, uint16_t Len, uint16_t CutLen);
int16_t i16_middle_average_filter(int16_t *dat, uint16_t Len, uint16_t CutLen);
uint16_t ui16_middle_average_filter(uint16_t *dat, uint16_t Len, uint16_t CutLen);

/****************************************************************************
 * 加权滤波 
 * 权值数组长度必须和Len一致，StartIndex指示最新数据元素位置
 * 保证权值和数值的乘机不超过 u32, 权值列表和不为0
 * 权值列表低一个元素为最新值权值，后续以此类推
 * **************************************************************************/
uint32_t u32_coef_filter(uint32_t *dat, uint16_t *coef, uint16_t StartIndex, uint16_t Len);
uint16_t u16_coef_filter(uint16_t *dat, uint16_t *coef, uint16_t StartIndex, uint16_t Len);


/****************************************************************************
 * 3阶滤波 
 * **************************************************************************/
 typedef struct
 {
    float flt_coef; //0.001~0.999
    float out_order1; //1阶输出
    float out_order2; //2阶输出
    float out_order3; //2阶输出
 } f_order_filter_type;
/****************************************************************************
 * 三阶滤波 
 * 返回实际执行的滤波系数
 * **************************************************************************/
float f_order_filter (f_order_filter_type *flt, float new_data);
 
 
#ifdef	__cplusplus
}
#endif

#endif	/* __FILTERN_H_ */

