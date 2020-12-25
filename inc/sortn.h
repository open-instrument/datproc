/* 
 * File:   sort.h
 * Author: apleilx
 */

#ifndef __SORT_N_H_
#define	__SORT_N_H_

#include "stdint.h"

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef INT_CPU
#define INT_CPU uint32_t
#endif

/****************************************************************************
 *  冒泡排序
 * arr-数据源
 * Len-数据长度
 * **************************************************************************/
void i32_bubble_sort(int32_t arr[], INT_CPU Len);
void u32_bubble_sort(uint32_t arr[], INT_CPU Len);
void i16_bubble_sort(int16_t arr[], INT_CPU Len);
void u16_bubble_sort(uint16_t arr[], INT_CPU Len);
void i8_bubble_sort(int8_t arr[], INT_CPU Len);
void u8_bubble_sort(uint8_t arr[], INT_CPU Len);

/****************************************************************************
 *  选择排序
 * arr-数据源
 * Len-数据长度
 * **************************************************************************/
void i32_select_sort(int32_t arr[], INT_CPU Len);
void u32_select_sort(uint32_t arr[], INT_CPU Len);
void u16_select_sort(uint16_t arr[], INT_CPU Len);
void i16_select_sort(int16_t arr[], INT_CPU Len);
void i8_select_sort(int8_t arr[], INT_CPU Len);
void u8_select_sort(uint8_t arr[], INT_CPU Len);

#ifdef	__cplusplus
}
#endif


#endif	/* __SORT_N_H_ */

