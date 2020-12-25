/*--------------------------------------------------------------*                                       
 *--------------------------------------------------------------*/

#ifndef _EXT_BLOCK_LOG_H_
#define _EXT_BLOCK_LOG_H_

#include <stdint.h>
#include "rtctime.h"

#define FLASH_BLOCK_ERR_NONE         0
#define FLASH_BLOCK_ERR_PAGE_SIZE    1  /*�����ߴ����*/
#define FLASH_BLOCK_ERR_BLOCK_SIZE   2  /*BLOCK�ߴ����*/
#define FLASH_BLOCK_ERR_BLOCK_NUMS   3
#define FLASH_BLOCK_ERR_SIZE         4  /*ʵ�����ݸ���*/
#define FLASH_BLOCK_ERR_PAG_PER_BLK  5  /*��ַ����,��ַδ���뵽�����߽�*/
#define FLASH_BLOCK_ERR_LOG_SIZE     6  /*���ݳߴ����eep�ߴ�*/


typedef struct{
    uint32_t block_now;       /*ָ��ǰ׼��д��Ŀ�λ�ã� ���base��λ��*/
    uint32_t block_start;     /*������ʼ���ַ�� ���base��λ��*/
    uint16_t Err;             /*�ϴδ������*/
    uint8_t Checked;          /*�����Ѿ�ͨ�����*/
	uint8_t full;             /*�����Ѿ������������洢����ʼ����ʽд��*/
} ext_block_log_Info_Type;


typedef const struct {
	uint32_t block_base;    /*��ʼ���߼���*/
	uint32_t block_amount;  /*�ܿ���*/
    uint32_t page_size;     /*ҳ��ߴ磬�ֽ��� */
    uint32_t block_size;    /*��ߴ磬*/
	uint32_t size;          /*�ܳߴ磬�ֽ���*/
    uint32_t page_per_block; /*ÿ��ҳ��*/
	uint32_t log_size;       /*ÿ����־�ߴ磬��������λ��*/
	uint32_t *WorkBuff;      /*��������,��С����־�ߴ�*/
    ext_block_log_Info_Type *Info; /*����ʱ��Ϣ*/
    uint8_t (*Erase)(uint32_t block_addr, uint32_t Nums); /*��ָ����ַ������Numsָ����������������*/
    uint8_t (*Program)(uint32_t block_addr);    /*��ָ��ָ����ַ�������*/
    uint8_t (*Read)(uint32_t block_addr, uint32_t page_offset, uint32_t Len, uint8_t *Data);       /*��ָ��λ�ö�ȡ����*/
} ext_block_log_Cfg_Type;

uint16_t ext_block_log_FlashCheck(ext_block_log_Cfg_Type *EepCfg);
uint16_t ext_block_log_FlashSave(ext_block_log_Cfg_Type *EepCfg);

#endif
