#ifndef _GD25Q_CMD_H_
#define	_GD25Q_CMD_H_

#include "stdint.h"

//GD25Q ����3����ȫ�Ĵ���ҳ������ͬ���洢��ҳ��ֻ��ָ�ͬ�� ��ҳ��д������״̬�Ĵ�����LBλָ����LBλ��OPTλ��
//��ҳ��ʼ��ַ 0x001000, 0x002000, 0x003000��ÿҳ1KB����������ֻʹ��ǰ256�ֽڣ���Ϊ������ݵ�����������ЩIC��ҳ�ߴ�Ϊ256.
//״̬�Ĵ�����LBλ��0ʱ����ȫ�Ĵ������������д��LB��Ϊ1��LB����ȫ�Ĵ�����д��������Զ�����ٴβ�����

//The Write Status Register (WRSR) command has no effect on S23, S20, S19, S18, S17, S16, S15, S10, S1 and S0

//statue cfg POS define�� ��������λ��Ϊ����ʧ����λ������һ�μ��ɡ� ����LBΪOPT��SRP�ڲ���оƬ�Ͽ�������status��������λ��ΪOPT
#define GD25_ST_DRV_POS                                   21          //drv 2bits, ָʾ�ܽ���������
#define GD25_ST_CMP_POS                                   14          //���洢������ģ��
#define GD25_ST_LB_POS                                    11          //LB 3bits, ��ȫ�Ĵ���д����λ��OPT
#define GD25_ST_QE_POS                                    9           //ָʾQPI�ܽ��Ƿ�ʹ�� 
#define GD25_ST_SRP_POS                                   7           //ָʾ״̬�Ĵ�������״̬ //����оƬ ��Ϊ0b11��״̬�Ĵ�����ΪOPT
#define GD25_ST_BP_POS                                    2           //������������

//ֻ��λ
#define GD25_ST_HPF_POS                                   20          //ֻ����ָʾоƬ���ڸ�����ģʽ
#define GD25_ST_SUS_POS                                   15          //��̲���״̬

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

#define GD25CMD_Read_Data                                 0x03 //SPI ��
#define GD25CMD_Fast_Read                                 0x0B //SPI ��

#define GD25CMD_Quad_Read                                 0x6B //CMD�͵�ַΪSPIģʽ������ΪQSPI
#define GD25CMD_Quad_Read_IO                              0xEB //CMDΪSPIģʽ����ַ�����ݾ�ΪQSPI

#define GD25CMD_Page_Program                              0x02 //SPI д
#define GD25CMD_Quad_Page_Program                         0x32 //CMD�͵�ַΪSPIģʽ������ΪQSPI

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
uint8_t gd25_q_write(uint32_t addr,uint32_t Len,uint8_t *Src); //����оƬQPIд��Ҫ��ϵ͵�ʱ��Ƶ��

uint8_t gd25_security_reg_read(uint32_t addr, uint32_t Len, uint8_t *Des);
uint8_t gd25_security_reg_write(uint32_t addr, uint32_t Len, uint8_t *Src);
uint8_t gd25_security_reg_erase(uint32_t addr);

#endif	/* _GD25Q_CMD_H_ */

