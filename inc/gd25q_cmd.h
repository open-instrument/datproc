#ifndef _GD25Q_CMD_H_
#define	_GD25Q_CMD_H_

#include "stdint.h"

//GD25Q 包含3个安全寄存器页，操作同主存储器页，只是指令不同。 三页的写保护由状态寄存器的LB位指定，LB位是OPT位；
//三页起始地址 0x001000, 0x002000, 0x003000。每页1KB容量。建议只使用前256字节，因为与其兼容的其他厂家有些IC的页尺寸为256.
//状态寄存器的LB位是0时，安全寄存器区可随意读写，LB设为1后，LB及安全寄存器被写保护，永远不可再次操作。

//The Write Status Register (WRSR) command has no effect on S23, S20, S19, S18, S17, S16, S15, S10, S1 and S0

//statue cfg POS define， 以下配置位均为非易失配置位，配置一次即可。 其中LB为OPT，SRP在部分芯片上可令整个status所有配置位变为OPT
#define GD25_ST_DRV_POS                                   21          //drv 2bits, 指示管脚驱动能力
#define GD25_ST_CMP_POS                                   14          //主存储区保护模型
#define GD25_ST_LB_POS                                    11          //LB 3bits, 安全寄存器写保护位，OPT
#define GD25_ST_QE_POS                                    9           //指示QPI管脚是否使能 
#define GD25_ST_SRP_POS                                   7           //指示状态寄存器保护状态 //部分芯片 设为0b11后状态寄存器变为OPT
#define GD25_ST_BP_POS                                    2           //保护区域配置

//只读位
#define GD25_ST_HPF_POS                                   20          //只读，指示芯片处于高性能模式
#define GD25_ST_SUS_POS                                   15          //编程擦除状态

// statue define
#define GD25Q_ST_BUSY_MASK                                0x01
#define GD25Q_ST_WRITE_EN                                 0x02


// command list
#define GD25CMD_Write_Enable                              0x06
#define GD25CMD_Write_Disable                             0x04
#define GD25CMD_SRWrite_Enable                            0x50

#define GD25CMD_Read_StReg1                               0x05
#define GD25CMD_Read_StReg2                               0x35
#define GD25CMD_Read_StReg3                               0x15
#define GD25CMD_Write_StReg1                              0x01
#define GD25CMD_Write_StReg2                              0x31
#define GD25CMD_Write_StReg3                              0x11

#define GD25CMD_Read_Data                                 0x03 //SPI 读
#define GD25CMD_Fast_Read                                 0x0B //SPI 读

#define GD25CMD_Quad_Read                                 0x6B //CMD和地址为SPI模式，数据为QSPI
#define GD25CMD_Quad_Read_IO                              0xEB //CMD为SPI模式，地址和数据均为QSPI

#define GD25CMD_Page_Program                              0x02 //SPI 写
#define GD25CMD_Quad_Page_Program                         0x32 //CMD和地址为SPI模式，数据为QSPI

#define GD25CMD_Sector_Erase                              0x20
#define GD25CMD_Block_Erase_32K                           0x52
#define GD25CMD_Block_Erase_64K                           0xD8
#define GD25CMD_Chip_Erase                                0x60

#define GD25CMD_Enable_Reset                              0x66
#define GD25CMD_Reset                                     0x99


#define GD25CMD_Erase_SecurityReg                         0x44
#define GD25CMD_Program_SecurityReg                       0x42
#define GD25CMD_Read_SecurityReg                          0x48

#define GD25CMD_Read_Identification                       0x9F

// flash information
#define GD25Q_PAGE_SIZE                                0x100UL          //256bytes 
#define GD25Q_PAGE_MASK                                0xFFUL
#define GD25Q_SECTOR_SIZE                              0x1000UL         //4kbytes
#define GD25Q_SECTOR_MASK                              0xFFFUL
#define GD25Q_BLOCK_SIZE                               0x8000UL         //32kbytes
#define GD25Q_BLOCK_MASK                               0x7FFFUL
#define GD25Q_CHIP_SIZE                                0x1000000UL      //16mbytes
#define GD25Q_CHIP_MASK                                0xFFFFFFUL

/*spi mode enum*/
typedef enum
{
    GD25_SPI_MODE=0,
    GD25_QPI_READ_MODE,
    GD25_QPI_WRITE_MODE,
} gd25_spi_type;

//function
uint32_t gd25_init(uint8_t qspi_en);

void gd25_cmd_signal_exe (uint8_t cmd);
void gd25_cmd_exe (uint8_t cmd, uint8_t par);

uint32_t gd25_st_read(void); //st read
uint8_t  gd25_busy(void); // get busy st
uint8_t gd25_wait_for_busy(void); //return 1 is ok, 0 is error.

uint8_t  gd25_id_read(uint8_t *des);

void gd25_write_enable(void);
void gd25_write_disable(void);

uint8_t gd25_sector_erase(uint32_t addr);
uint8_t gd25_block_erase(uint32_t addr);
uint8_t gd25_chip_erase(void );

uint8_t gd25_read(uint32_t addr,uint32_t Len,uint8_t *Des);
uint8_t gd25_write(uint32_t addr,uint32_t Len,uint8_t *Src);

uint8_t gd25_q_read(uint32_t addr,uint32_t Len,uint8_t *Des);
uint8_t gd25_q_write(uint32_t addr,uint32_t Len,uint8_t *Src); //部分芯片QPI写入要求较低的时钟频率

uint8_t gd25_security_reg_read(uint32_t addr, uint32_t Len, uint8_t *Des);
uint8_t gd25_security_reg_write(uint32_t addr, uint32_t Len, uint8_t *Src);
uint8_t gd25_security_reg_erase(uint32_t addr);

#endif	/* _GD25Q_CMD_H_ */

