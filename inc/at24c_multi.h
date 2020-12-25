/*--------------------------------------------------------------*
 * Creat Date: 2015/7/20 										*
 * Modify    : 
 *
 * 描述：用于管理64KB以内的IIC接口EEPROM                                     
 *--------------------------------------------------------------*/

#ifndef _AT24C04_MULTI_H_
#define _AT24C04_MULTI_H_

#include "at24c.h"

typedef const struct 
{
    uint8_t CHIP_ADDR;
    uint8_t ADDR_TYPE;
    uint16_t PAGE_SIZE;
    uint16_t PAGE_MASK;
    uint16_t ADDR_SIZE;                
    uint16_t SUBA_SIZE;                    
    uint16_t SUBA_MASK;   
    
    void (*at_iic_start)(void);
    void (*at_iic_stop)(void);
    uint8_t (*at_iic_snd_byte)(uint8_t data); //返回ack or nack
    uint8_t (*at_iic_rcv_byte)(void);
    void (*at_iic_ack)(uint8_t);
    void (*at_iic_delay_ms)(uint32_t ms);
} at24c_multi_cfg_type;

uint8_t at24_multi_write(at24c_multi_cfg_type *at24c, uint16_t DataAdd, uint16_t Len, uint8_t *Rsc);
uint8_t at24_multi_read(at24c_multi_cfg_type *at24c, uint16_t DataAdd, uint16_t Len, uint8_t *Des);

#endif
