/* 
 * File:   lcd19264.h
 * Author: Administrator
 */

#ifndef Lcd_HAL_H
#define	Lcd_HAL_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stdint.h"

void LcdHalInit(void);
/****************************************************************************
 * The flowing function can be run independently.
 * Other functions rely on these functions.
 * so if you delete it, some functions may not work.
 ****************************************************************************/

void Lcd_Data_Write(char cs, char page, char nums, uint8_t *pdata);

/******************************************************************************/
#ifdef	__cplusplus
}
#endif

#endif	/* Lcd_H */

