/*--------------------------------------------------------------*                                       
 *--------------------------------------------------------------*/

#ifndef _EXT_NOT_LOG_H_
#define _EXT_NOT_LOG_H_

#include <stdint.h>

#define FLASH_NOR_ERR_NONE       0
#define FLASH_NOR_ERR_SECSIZE    1  /*�����ߴ����*/
#define FLASH_NOR_ERR_NORSIZE    2  /*NOR��������*/
#define FLASH_NOR_ERR_BLKSIZE    3  /*���ݿ�ռ�*/
#define FLASH_NOR_ERR_DATSIZE    4  /*ʵ�����ݸ���*/
#define FLASH_NOR_ERR_NORBASE    5  /*��ַ����,��ַδ���뵽�����߽�*/
#define FLASH_NOR_ERR_DATOVE     6  /*���ݳߴ����eep�ߴ�*/
#define FLASH_NOR_ERR_DATOVK     7  /*���ݳߴ�������ݿ�*/
#define FLASH_NOR_ERR_BLKOVE     8  /*���ݿ����NOR�ռ�*/
#define FLASH_NOR_ERR_DATPER     9  /*���ݳߴ����Ϊ4�ı���*/
#define FLASH_NOR_ERR_EMPTY     10  /*����ȫ�� ,��ʾ��δд������*/
#define FLASH_NOR_ERR_DATBL     11  /*���ݿ�̫С������Ϊ4*/
#define FLASH_NOR_ERR_NORSST    12  /*NOR�ߴ粻�������ı���*/
#define FLASH_NOR_ERR_BLKSEC    13  /*blocks_per_sector ���ò���*/
#define FLASH_NOR_ERR_BLOCKS    14  /*blocks ���ò���*/
#define FLASH_NOR_ERR_PGSIZE    15  /*ҳ�ߴ����*/

typedef struct{
    uint32_t addr_now; /*��ǰ��д���ַ, �������ʼ��ַ*/
    uint32_t addr_data_start;   /*��ʼ������ַ�� �������ʼ��ַ*/
    uint16_t Err;      /*�ϴδ������*/
    uint16_t Checked;  /*�����Ѿ�ͨ�����*/
} ext_nor_log_Info_Type;

typedef const struct {
    uint32_t EepBase;    /*����Eep��ַ  ,�����߽����*/
    uint32_t EepSize;    /*����Eep�ߴ�  ,����Ϊ������������ �ֽ���*/
    uint32_t SectorSize; /*���������ߴ� ,2^n�߽����  �����Ӳ���������һ��,�ֽ��� */
    uint32_t PageSize;   /*ҳ�ߴ磬ҳ�߽����,2^n*/
    uint32_t DataSize;   /*ʵ�����ݿ�ߴ�,����Ϊ4�ı���  �ֽ���*/
    uint32_t blocks_per_sector; /*ÿ�������� SectorSize/DataSize*/
    uint32_t blocks;     /*�ָ���� (EepSize/SectorSize) * blocks_per_sector*/ 
    uint8_t *Data;       /*����Դ��ʵ�ʳߴ�Ӧ���ڵ���DataSize*/
	uint32_t *WorkBuff;  /*��������,��С��ɽ���ߴ�*/
    ext_nor_log_Info_Type *Info; /*����ʱ��Ϣ*/
    uint8_t (*Erase)(uint32_t AddrBase, uint32_t Nums); /*��ָ����ַ������Numsָ����������������*/
    uint8_t (*Program)(uint32_t Addr, uint32_t Len, uint8_t *Data);    /*��ָ��ָ����ַ�������*/
    uint8_t (*Read)(uint32_t Addr, uint32_t Len, uint8_t *Data);       /*��ָ��λ�ö�ȡ����*/
} ext_nor_log_Cfg_Type;

/*����״̬���*/
uint16_t ext_nor_log_FlashCheck(ext_nor_log_Cfg_Type *EepCfg);
/*�洢һ������*/
uint16_t ext_nor_log_FlashSave(ext_nor_log_Cfg_Type *EepCfg);
/*��� addr_now û�ж����������߽磬������뵽��һ�����߽�*/
uint16_t ext_nor_log_SectorAlign(ext_nor_log_Cfg_Type *EepCfg);
/*�ӵ�ǰλ����ǰ����ָ���� head_val, numָ��������������Ϸ��ؽ����ʼ��ַ*/
uint16_t ext_nor_log_head_search(ext_nor_log_Cfg_Type *EepCfg, uint32_t head_val, uint32_t num, uint32_t *addr_des);
uint16_t ext_nor_log_fixed_head_search(ext_nor_log_Cfg_Type *EepCfg, uint32_t num, uint32_t *addr_des);
uint16_t ext_nor_log_time_search(ext_nor_log_Cfg_Type *EepCfg, uint32_t time, uint32_t *addr_des);

#endif
