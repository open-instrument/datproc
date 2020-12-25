/*--------------------------------------------------------------*
 * Creat Date: 2015/7/20 										*
 * Modify    : 
 *
 * 描述：用于管理64KB以内的IIC接口EEPROM                                     
 *--------------------------------------------------------------*/

#ifndef _AT24C04_H_
#define _AT24C04_H_

#include "stdint.h"

#define AT24C02                    0
#define AT24C04                    0
#define AT24C16                    0
#define AT24C32                    1
#define AT24C64                    0
#define AT24C256                   0


/*---------------------------------------------------------------*
 * ADDR_TYPE:
 * [0]: 指示子地址字节数 ，0一字节，1两字节
 * [3-1]:指示内部芯片地址的掩蔽位
 * [7-4]:必须为0，否则程序将不能正常运行
 *---------------------------------------------------------------*/

#if AT24C02 > 0
#define EEP_PAGE_SIZE              8
#define EEP_PAGE_MASK              0x07	   //Page Addr :3bits
#define EEP_ADDR_SIZE              0x100
#define EEP_SUBA_SIZE              0x100
#define EEP_SUBA_MASK              0xFF
#define EEP_ADDR_TYPE              0       //1 byte       

#elif AT24C04 > 0
#define EEP_PAGE_SIZE              16
#define EEP_PAGE_MASK              0x0F	   //Page Addr :4bits
#define EEP_ADDR_SIZE              0x200            
#define EEP_SUBA_SIZE              0x100           
#define EEP_SUBA_MASK              0xFF            
#define EEP_ADDR_TYPE              2       //1+.x byte       

#elif AT24C16 > 0
#define EEP_PAGE_SIZE              16
#define EEP_PAGE_MASK              0x0F	   //Page Addr :4bits
#define EEP_ADDR_SIZE              0x800                           
#define EEP_SUBA_SIZE              0x100                       
#define EEP_SUBA_MASK              0xFF                    
#define EEP_ADDR_TYPE              0x0E    //1+.x byte    

#elif AT24C32 > 0
#define EEP_PAGE_SIZE              32
#define EEP_PAGE_MASK              0x1F	   //Page Addr :5bits
#define EEP_ADDR_SIZE              0x1000                  
#define EEP_SUBA_SIZE              0x1000                       
#define EEP_SUBA_MASK              0x0FFF                    
#define EEP_ADDR_TYPE              0x01    //2 byte  

#elif AT24C64 > 0
#define EEP_PAGE_SIZE              32
#define EEP_PAGE_MASK              0x1F	   //Page Addr :5bits
#define EEP_ADDR_SIZE              0x2000                  
#define EEP_SUBA_SIZE              0x2000                       
#define EEP_SUBA_MASK              0x1FFF                    
#define EEP_ADDR_TYPE              0x01    //2 byte  

#elif AT24C256 > 0
#define EEP_PAGE_SIZE              64
#define EEP_PAGE_MASK              0x3F	   //Page Addr :6bits         
#define EEP_ADDR_SIZE              0x8000       
#define EEP_SUBA_SIZE              0x8000          
#define EEP_SUBA_MASK              0x7FFF               
#define EEP_ADDR_TYPE              1       //2 byte 
#else
#error AT24 SEL ERROR
#endif  

#define EEP_CHIP_ADDR              0xA0   //左对齐

typedef const struct 
{
    uint8_t CHIP_ADDR;
    uint8_t ADDR_TYPE;
    uint16_t PAGE_SIZE;
    uint16_t PAGE_MASK;
    uint16_t ADDR_SIZE;                
    uint16_t SUBA_SIZE;                    
    uint16_t SUBA_MASK;                  
} at24c_cfg_type;


uint8_t at24_write(uint16_t DataAdd, uint16_t Len, uint8_t *Rsc);
uint8_t at24_read(uint16_t DataAdd, uint16_t Len, uint8_t *Des);

#endif
