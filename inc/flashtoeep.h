/*--------------------------------------------------------------*                                       
 *--------------------------------------------------------------*/

#ifndef _FlashToEEP_H_
#define _FlashToEEP_H_

#include <stdint.h>
#include "rtctime.h"

#define FLASH_EEP_ERR_NONE 0
#define FLASH_EEP_ERR_SECSIZE 1 /*�����ߴ����*/
#define FLASH_EEP_ERR_EEPSIZE 2 /*EEP��������*/
#define FLASH_EEP_ERR_BLKSIZE 3 /*���ݿ�ռ�*/
#define FLASH_EEP_ERR_DATSIZE 4 /*ʵ�����ݸ���*/
#define FLASH_EEP_ERR_EEPBASE 5 /*��ַ����,��ַδ���뵽�����߽�*/
#define FLASH_EEP_ERR_DATOVE 6  /*���ݳߴ����eep�ߴ�*/
#define FLASH_EEP_ERR_DATOVK 7  /*���ݳߴ�������ݿ�*/
#define FLASH_EEP_ERR_BLKOVE 8  /*���ݿ����EEP�ռ�*/
#define FLASH_EEP_ERR_DATPER 9  /*���ݳߴ����Ϊ4�ı���*/
#define FLASH_EEP_ERR_EMPTY 10  /*����ȫ�� ,��ʾ��δд������*/
#define FLASH_EEP_ERR_DATBL 11  /*���ݿ�̫С������Ϊ4*/
#define FLASH_EEP_ERR_EEPSST 12 /*EEP�ߴ粻�������ı���*/
#define FLASH_EEP_ERR_EXTPAG 13 /*EEP�ߴ粻�������ı���*/

/*--------------------------------------------Inner Flash to eep-----------------------------------------------*/
typedef struct
{
    uint32_t EepAddr;       /*��ǰ������ʼ��ַ*/
    uint32_t Site;          /*��ǰָ���λ��*/
    uint32_t Blocks;        /*�ָ����*/
    uint32_t AddrDataStart; /*��ʼ������ַ*/
    uint32_t SiteDataStart; /*��ʼ����λ��*/
    uint16_t Err;           /*�ϴδ������*/
    uint16_t Checked;       /*�����Ѿ�ͨ�����*/
} FlashEepInfo_Type;

typedef const struct
{
    uint32_t SectorSize;                             /*���������ߴ� ,2^n�߽����  �����Ӳ���������һ��,�ֽ��� */
    uint32_t EepSize;                                /*����Eep�ߴ�  ,�����ߴ��2^n����  �ֽ���*/
    uint32_t DataBlockSize;                          /*ÿ�����ݿ�ռ�ÿռ� ,2^�߽���� ,�ֽ���*/
    uint32_t DataSize;                               /*ʵ�����ݿ�ߴ�,����Ϊ4�ı���  �ֽ���*/
    uint32_t EepBase;                                /*����Eep��ַ  ,�����߽����*/
    uint16_t *Data;                                  /*����Դ��ʵ�ʳߴ�Ӧ���ڵ���DataSize*/
    FlashEepInfo_Type *Info;                         /*����ʱ��Ϣ*/
    void (*Erase)(uint32_t AddrBase, uint32_t Nums); /*��ָ����ַ������Numsָ����������������*/
    void (*Program)(uint32_t Addr, uint32_t Data);   /*��ָ��ָ����ַ�������*/
    void (*Unlock)(void);                            /*flash����  0��ִ��*/
    void (*Lock)(void);                              /*flash����  0��ִ��*/
} FlashEepCfg_Type;

uint16_t FlashEepRead(FlashEepCfg_Type *EepCfg);
uint16_t FlashEepSave(FlashEepCfg_Type *EepCfg);

uint16_t FlashMulEepSave(FlashEepCfg_Type *EepCfg);
uint16_t FlashMulEepRead(FlashEepCfg_Type *EepCfg);

/*--------------------------------------------ext Flash to eep-----------------------------------------------*/
typedef struct
{
    uint32_t EepAddr;       /*��ǰ������ʼ��ַ*/
    uint32_t Site;          /*��ǰָ���λ��*/
    uint32_t Blocks;        /*�ָ����*/
    uint32_t AddrDataStart; /*��ʼ������ַ*/
    uint32_t SiteDataStart; /*��ʼ����λ��*/
    uint16_t Err;           /*�ϴδ������*/
    uint16_t Checked;       /*�����Ѿ�ͨ�����*/
} ExtFlashEepInfo_Type;

typedef const struct
{
    uint32_t SectorSize;    /*���������ߴ� ,2^n�߽����  �����Ӳ���������һ��,�ֽ��� */
    uint32_t EepSize;       /*����Eep�ߴ�  ,�����ߴ��2^n����  �ֽ���*/
    uint32_t PageSize;      /*�ⲿflashҳ�ߴ�2^n*/
    uint32_t DataBlockSize; /*ÿ�����ݿ�ռ�ÿռ� ,2^�߽���� ,�ֽ���*/
    uint32_t DataSize;      /*ʵ�����ݿ�ߴ�,����Ϊ4�ı���  �ֽ���, ���4�ֽ�Ԥ��ΪУ����*/
    uint32_t EepBase;       /*����Eep��ַ  ,�����߽����*/
    uint8_t *Data;          /*����Դ��ʵ�ʳߴ�Ӧ���ڵ���DataSize,ǰ2�ֽڲ�����ȫΪ0xFF������ȷ�������Ƿ񱣴���򣬷�ֹ�����ݹ����жϵ絼�����ݲ�����*/
    uint32_t *WorkBuff;
    ExtFlashEepInfo_Type *Info;                                  /*����ʱ��Ϣ*/
    uint8_t (*Erase)(uint32_t AddrBase, uint32_t Nums);             /*��ָ����ַ������Numsָ����������������*/
    uint8_t (*Program)(uint32_t Addr, uint8_t *Data, uint16_t Len); /*��ָ��ָ����ַ�������*/
    uint8_t (*Read)(uint32_t Addr, uint8_t *Data, uint16_t Len);
} ExtFlashEepCfg_Type;

uint16_t ExtFlashMulEepSave(ExtFlashEepCfg_Type *EepCfg);
uint16_t ExtFlashMulEepRead(ExtFlashEepCfg_Type *EepCfg);

/*--------------------------------------------ext Flash to Log Buffer--------------------------------------*/
typedef struct
{
    uint32_t EepAddr; /*��ǰ������ʼ��ַ*/
    uint32_t Site;    /*ָ��ǰ���洢λ��*/
    uint32_t Blocks;  /*�ָ����*/
    uint16_t Err;     /*�ϴδ������*/
    uint16_t Checked; /*�����Ѿ�ͨ�����*/
} ext_flash_log_buff_info_Type;

typedef const struct
{
    uint32_t EepBase;                                            /*����Eep��ַ  ,�����߽����*/
    uint32_t SectorSize;                                         /*buff���������ߴ� ,2^n�߽����  �����Ӳ���������һ��,�ֽ��� */
    uint32_t SectorAmount;                                       /*buff����Eep�ߴ�  ,�����ߴ��2^n����  ��������*/
    uint32_t ExtPageSize;                                        /*�ⲿ�洢��ҳ�ߴ磬ִ��alainʱ���մ˱߽����*/
    uint32_t DataBlockSize;                                      /*ÿ�����ݿ�ռ�ÿռ� ,2^�߽���� ,�ֽ���*/
    uint32_t DataSize;                                           /*ʵ�����ݿ�ߴ�,����Ϊ4�ı���  �ֽ������˳��򲻼��ҳ�ߴ磬���ݿ�ӦС��һ����ҳflash*/
    uint8_t *Data;                                               /*����Դ��ʵ�ʳߴ�Ӧ���ڵ���DataSize*/
    uint32_t *WorkBuff;                                          /*��������*/
    ext_flash_log_buff_info_Type *Info;                           /*����ʱ��Ϣ*/
    void (*Erase)(uint32_t AddrBase, uint32_t Nums);             /*��ָ����ַ������Numsָ����������������*/
    void (*Program)(uint32_t Addr, uint8_t *Data, uint16_t Len); /*��ָ��ָ����ַ�������*/
    void (*Read)(uint32_t Addr, uint8_t *Data, uint16_t Len);    /*��ȡ������*/
    void (*FlashFullCallBack)(void); /*�����ص�*/
} ext_flash_log_buff_cfg_Type;

uint16_t ext_flash_log_buff_save(ext_flash_log_buff_cfg_Type *EepCfg);
uint16_t ext_flash_log_buff_init(ext_flash_log_buff_cfg_Type *EepCfg);
uint16_t ext_flash_log_buff_align(ext_flash_log_buff_cfg_Type *EepCfg);
uint16_t ext_flash_log_buff_head_search(ext_flash_log_buff_cfg_Type *EepCfg, uint32_t num, uint32_t *addr_des);
uint16_t ext_flash_log_buff_time_search(ext_flash_log_buff_cfg_Type *EepCfg, sig_time_type time, uint32_t *addr_des);

#endif
