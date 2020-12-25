/*--------------------------------------------------------------*                                       
 *--------------------------------------------------------------*/

#ifndef _EXT_NOT_LOG_H_
#define _EXT_NOT_LOG_H_

#include <stdint.h>

#define FLASH_NOR_ERR_NONE       0
#define FLASH_NOR_ERR_SECSIZE    1  /*扇区尺寸错误*/
#define FLASH_NOR_ERR_NORSIZE    2  /*NOR数量错误*/
#define FLASH_NOR_ERR_BLKSIZE    3  /*数据块空间*/
#define FLASH_NOR_ERR_DATSIZE    4  /*实际数据个数*/
#define FLASH_NOR_ERR_NORBASE    5  /*基址错误,基址未对齐到扇区边界*/
#define FLASH_NOR_ERR_DATOVE     6  /*数据尺寸大于eep尺寸*/
#define FLASH_NOR_ERR_DATOVK     7  /*数据尺寸大于数据块*/
#define FLASH_NOR_ERR_BLKOVE     8  /*数据块大于NOR空间*/
#define FLASH_NOR_ERR_DATPER     9  /*数据尺寸必须为4的倍数*/
#define FLASH_NOR_ERR_EMPTY     10  /*扇区全空 ,表示从未写过数据*/
#define FLASH_NOR_ERR_DATBL     11  /*数据块太小，至少为4*/
#define FLASH_NOR_ERR_NORSST    12  /*NOR尺寸不是扇区的倍数*/
#define FLASH_NOR_ERR_BLKSEC    13  /*blocks_per_sector 配置不对*/
#define FLASH_NOR_ERR_BLOCKS    14  /*blocks 配置不对*/
#define FLASH_NOR_ERR_PGSIZE    15  /*页尺寸错误*/

typedef struct{
    uint32_t addr_now; /*当前待写入地址, 相对于起始地址*/
    uint32_t addr_data_start;   /*开始扇区地址， 相对于起始地址*/
    uint16_t Err;      /*上次错误代码*/
    uint16_t Checked;  /*参数已经通过检测*/
} ext_nor_log_Info_Type;

typedef const struct {
    uint32_t EepBase;    /*虚拟Eep基址  ,扇区边界对齐*/
    uint32_t EepSize;    /*虚拟Eep尺寸  ,必须为扇区的整数倍 字节数*/
    uint32_t SectorSize; /*扇区擦除尺寸 ,2^n边界对齐  必须和硬件物理参数一致,字节数 */
    uint32_t PageSize;   /*页尺寸，页边界对齐,2^n*/
    uint32_t DataSize;   /*实际数据块尺寸,必须为4的倍数  字节数*/
    uint32_t blocks_per_sector; /*每扇区块数 SectorSize/DataSize*/
    uint32_t blocks;     /*分割块数 (EepSize/SectorSize) * blocks_per_sector*/ 
    uint8_t *Data;       /*数据源，实际尺寸应大于等于DataSize*/
	uint32_t *WorkBuff;  /*工作缓存,不小于山区尺寸*/
    ext_nor_log_Info_Type *Info; /*运行时信息*/
    uint8_t (*Erase)(uint32_t AddrBase, uint32_t Nums); /*从指定地址擦除，Nums指定擦除的扇区个数*/
    uint8_t (*Program)(uint32_t Addr, uint32_t Len, uint8_t *Data);    /*向指定指定地址编程数据*/
    uint8_t (*Read)(uint32_t Addr, uint32_t Len, uint8_t *Data);       /*从指定位置读取数据*/
} ext_nor_log_Cfg_Type;

/*数据状态检测*/
uint16_t ext_nor_log_FlashCheck(ext_nor_log_Cfg_Type *EepCfg);
/*存储一组数据*/
uint16_t ext_nor_log_FlashSave(ext_nor_log_Cfg_Type *EepCfg);
/*如果 addr_now 没有对齐在扇区边界，将其对齐到下一扇区边界*/
uint16_t ext_nor_log_SectorAlign(ext_nor_log_Cfg_Type *EepCfg);
/*从当前位置向前搜索指定的 head_val, num指定个数，搜索完毕返回结果开始地址*/
uint16_t ext_nor_log_head_search(ext_nor_log_Cfg_Type *EepCfg, uint32_t head_val, uint32_t num, uint32_t *addr_des);
uint16_t ext_nor_log_fixed_head_search(ext_nor_log_Cfg_Type *EepCfg, uint32_t num, uint32_t *addr_des);
uint16_t ext_nor_log_time_search(ext_nor_log_Cfg_Type *EepCfg, uint32_t time, uint32_t *addr_des);

#endif
