#ifndef _SPI_NOR_CMD_H_
#define	_SPI_NOR_CMD_H_

#include "stdint.h"

//SPI NOR����3����ȫ�Ĵ���ҳ������ͬ���洢��ҳ��ֻ��ָ�ͬ�� ��ҳ��д������״̬�Ĵ�����LBλָ����LBλ��OPTλ��
//��ҳ��ʼ��ַ 0x001000, 0x002000, 0x003000��ÿҳ1KB����������ֻʹ��ǰ256�ֽڣ���Ϊ������ݵ�����������ЩIC��ҳ�ߴ�Ϊ256.
//״̬�Ĵ�����LBλ��0ʱ����ȫ�Ĵ������������д��LB��Ϊ1��LB����ȫ�Ĵ�����д��������Զ�����ٴβ�����

//The Write Status Register (WRSR) command has no effect on S23, S20, S19, S18, S17, S16, S15, S10, S1 and S0

//statue cfg POS define�� ��������λ��Ϊ����ʧ����λ������һ�μ��ɡ� ����LBΪOPT��SRP�ڲ���оƬ�Ͽ�������status��������λ��ΪOPT
#define SPI_NOR_ST_DRV_POS                                   21          //drv 2bits, ָʾ�ܽ���������
#define SPI_NOR_ST_QE_POS                                    9           //ָʾQPI�ܽ��Ƿ�ʹ�� 
#define SPI_NOR_ST_LB_POS                                    11          //LB 3bits, ��ȫ�Ĵ���д����λ��OPT

// statue define
#define SPI_NOR_ST_BUSY_MASK                                0x01
#define SPI_NOR_ST_WRITE_EN                                 0x02


// command list
#define SPI_NOR_CMD_Write_Enable                              0x06
#define SPI_NOR_CMD_Write_Disable                             0x04
#define SPI_NOR_CMD_SRWrite_Enable                            0x50

#define SPI_NOR_CMD_Read_StReg1                               0x05
#define SPI_NOR_CMD_Read_StReg2                               0x35
#define SPI_NOR_CMD_Read_StReg3                               0x15
#define SPI_NOR_CMD_Write_StReg1                              0x01
#define SPI_NOR_CMD_Write_StReg2                              0x31
#define SPI_NOR_CMD_Write_StReg3                              0x11

#define SPI_NOR_CMD_Read_Data                                 0x03 //SPI ��
#define SPI_NOR_CMD_Fast_Read                                 0x0B //SPI ��

#define SPI_NOR_CMD_Quad_Read                                 0x6B //CMD�͵�ַΪSPIģʽ������ΪQSPI
#define SPI_NOR_CMD_Quad_Read_IO                              0xEB //CMDΪSPIģʽ����ַ�����ݾ�ΪQSPI

#define SPI_NOR_CMD_Page_Program                              0x02 //SPI д
#define SPI_NOR_CMD_Quad_Page_Program                         0x32 //CMD�͵�ַΪSPIģʽ������ΪQSPI

#define SPI_NOR_CMD_Sector_Erase                              0x20
#define SPI_NOR_CMD_Block_Erase_32K                           0x52
#define SPI_NOR_CMD_Block_Erase_64K                           0xD8
#define SPI_NOR_CMD_Chip_Erase                                0x60

#define SPI_NOR_CMD_Enable_Reset                              0x66
#define SPI_NOR_CMD_Reset                                     0x99


#define SPI_NOR_CMD_Erase_SecurityReg                         0x44
#define SPI_NOR_CMD_Program_SecurityReg                       0x42
#define SPI_NOR_CMD_Read_SecurityReg                          0x48

#define SPI_NOR_CMD_Read_Identification                       0x9F

/*spi mode enum*/
typedef enum
{
    SPI_NOR_SPI_MODE = 0,
    SPI_NOR_QPI_READ_MODE,
    SPI_NOR_QPI_WRITE_MODE,
} nor_spi_type;

typedef struct
{
    //* extern api
    void(*cs)(uint8_t st);
    void(*spi_mode)(nor_spi_type mode);
    void(*spi_wb)(uint8_t dataW);
    uint8_t(*spi_rb)(void);
    uint8_t(*spi_cmd_send)(uint8_t *dataw, uint8_t Len);
    uint8_t(*spi_write)(uint8_t *dataw, uint32_t Len);
    uint8_t(*spi_read)(uint8_t *datar, uint32_t Len);
    uint8_t(*qpi_write)(uint8_t *dataw, uint32_t Len);
    uint8_t(*qpi_read)(uint8_t *datar, uint32_t Len);
} spi_nor_hal_layer_type;



//function
uint32_t spi_nor_init(const spi_nor_hal_layer_type *spiflash, uint8_t qspi_en);

void spi_nor_cmd_signal_exe(const spi_nor_hal_layer_type *spiflash, uint8_t cmd);
void spi_nor_cmd_exe(const spi_nor_hal_layer_type *spiflash, uint8_t cmd, uint8_t par);

uint32_t spi_nor_st_read(const spi_nor_hal_layer_type *spiflash); //st read
uint8_t  spi_nor_busy(const spi_nor_hal_layer_type *spiflash); // get busy st
uint8_t spi_nor_wait_for_busy(const spi_nor_hal_layer_type *spiflash); //return 1 is ok, 0 is error.

uint8_t  spi_nor_id_read(const spi_nor_hal_layer_type *spiflash, uint8_t *des);

void spi_nor_write_enable(const spi_nor_hal_layer_type *spiflash);
void spi_nor_write_disable(const spi_nor_hal_layer_type *spiflash);

uint8_t spi_nor_sector_erase(const spi_nor_hal_layer_type *spiflash, uint32_t addr);
uint8_t spi_nor_block_erase(const spi_nor_hal_layer_type *spiflash, uint32_t addr);
uint8_t spi_nor_chip_erase(const spi_nor_hal_layer_type *spiflash);

uint8_t spi_nor_read(const spi_nor_hal_layer_type *spiflash, uint32_t addr, uint32_t Len, uint8_t *Des);
uint8_t spi_nor_write(const spi_nor_hal_layer_type *spiflash, uint32_t addr, uint32_t Len, uint8_t *Src);

uint8_t spi_nor_q_read(const spi_nor_hal_layer_type *spiflash, uint32_t addr, uint32_t Len, uint8_t *Des);
uint8_t spi_nor_q_write(const spi_nor_hal_layer_type *spiflash, uint32_t addr, uint32_t Len, uint8_t *Src); //����оƬQPIд��Ҫ��ϵ͵�ʱ��Ƶ��

uint8_t spi_nor_security_reg_read(const spi_nor_hal_layer_type *spiflash, uint32_t addr, uint32_t Len, uint8_t *Des);
uint8_t spi_nor_security_reg_write(const spi_nor_hal_layer_type *spiflash, uint32_t addr, uint32_t Len, uint8_t *Src);
uint8_t spi_nor_security_reg_erase(const spi_nor_hal_layer_type *spiflash, uint32_t addr);

#endif	/* _SPI_NOR_CMD_H_ */

