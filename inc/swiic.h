/* 
 * File:   iic.h
 * Author: apleilx
 */

#ifndef SWIIC_H_
#define SWIIC_H_

#include "stdint.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef IIC_ACK
#define IIC_ACK 0
#endif

#ifndef IIC_NACK
#define IIC_NACK 1
#endif

    typedef struct
    {
        uint8_t ack;
    } swiic_info_type;

    typedef const struct
    {

        void (*sda_out_high)(void);
        void (*sda_out_low)(void);

        void (*scl_out_high)(void);
        void (*scl_out_low)(void);

        void (*scl_out_mode)(void);
        void (*sda_out_mode)(void);
        void (*sda_in_mode)(void);

        uint8_t (*sda_st_get)(void);

        void (*delayx_1us)(uint16_t count);

        swiic_info_type *info;
    } swiic_cfg_type;

    //线控
    void sw_iic_init(swiic_cfg_type *iicobj);
    void sw_iic_start(swiic_cfg_type *iicobj);
    void sw_iic_stop(swiic_cfg_type *iicobj);
    void sw_iic_ack_send(swiic_cfg_type *iic, uint8_t a);
    
    //基本字节收发
    void sw_iic_send_byte(swiic_cfg_type *iicobj, uint8_t c);
    uint8_t sw_iic_rcv_byte(swiic_cfg_type *iicobj);
    
    //芯片功能
    uint8_t sw_iic_chip_rcv_byte(swiic_cfg_type *iicobj, int8_t sla, uint8_t *c);
    uint8_t sw_iic_chip_send_byte(swiic_cfg_type *iicobj, uint8_t sla, uint8_t c);
    uint8_t sw_iic_chip_send_str(swiic_cfg_type *iicobj, uint8_t sla, uint8_t suba, uint8_t *s, uint8_t no);
    uint8_t sw_iic_chip_rcv_str(swiic_cfg_type *iicobj, uint8_t sla, uint8_t suba, uint8_t *s, uint8_t no);


#ifdef __cplusplus
}
#endif

#endif /* SWIIC_H_ */
