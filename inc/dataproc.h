/* 
 * File:   dataProc.h
 * Author: Administrator
 *
 * Created on 2014��9��15��, ����8:29
 */

#ifndef DATAPROC_H
#define	DATAPROC_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "stdlib.h"
#include "string.h"
  
#define DATA_PROC_ERR_NONE           0x0
#define DATA_PROC_ERR_RES            0x21
    
    extern uint8_t const led_code[];
    extern uint8_t const ascii_code[];
    extern uint16_t const sinx_0r5pi_2048_16384[];
    extern uint16_t const sinx2_0r5pi_2048_16384[];
    
    
    typedef struct{
        uint8_t IncCoef;  //32-255
        uint8_t bDir; 
        uint16_t min; 
        uint16_t max; 
        uint16_t Out;
        uint16_t min_keep_time_sv; 
        uint16_t max_keep_time_sv;
        uint16_t min_keep_time_cnt; 
        uint16_t max_keep_time_cnt;
        uint32_t Cal;
    } led_breath_type;
    
    uint16_t AsciiToUpper(uint8_t *pSrc, uint16_t Len); //ת��asciiΪ��д
    uint16_t AsciiToLower(uint8_t *pSrc, uint16_t Len); //ת��asciiΪСд
    
    void Hex4ToBCD4(uint16_t Data ,uint8_t *Des );
    void Hex4ToBCD8(uint16_t Data ,uint8_t *Des );
    void Hex2ToBCD2(uint8_t Data ,uint8_t *Des );
    void Hex2ToBCD4(uint8_t Data ,uint8_t *Des );
    
    uint8_t BCD2ToHex(uint8_t Data, uint8_t *Des);
    uint8_t BCD4ToHex(uint16_t Data, uint8_t *Des);
    uint8_t BCD8ToHex(uint32_t Data, uint8_t *Des);
    
    void Hex8ToAscii(uint32_t Num,uint8_t *Des);
    void Hex4ToAscii(uint16_t Num,uint8_t *Des);
    void Hex2ToAscii(uint8_t Num,uint8_t *Des);
    
/*****************************************************************************
*          ת������Ҷ���
* @param   Attr:
*          [7]:   1���㣬0����
*          [6]:
*          [5-4]: С����λ��
*          [3]:
*          [2-0]: ʮ���ƽ��λ��,x+1λ
*****************************************************************************/    
    void Int16ToAscii(int16_t Num,uint8_t Attr,uint8_t *Des);
	void Uint16ToAscii(uint16_t Num,uint8_t Attr,uint8_t *Des);
    
/*****************************************************************************
*          ת����������
* @param   Attr:
*          [6]:
*          [5-4]: С����λ��
*          [3]:
*          [2-0]:
*****************************************************************************/
    uint8_t Uint16ToString(uint16_t Num,uint8_t Attr,uint8_t *Des);
    uint8_t Int16ToString(int16_t Num,uint8_t Attr,uint8_t *Des);
    
    int16_t AsciiToInt16(uint8_t *pSrc, uint8_t Len);
    int16_t AsciiToInt16_P0(uint8_t *pSrc, uint8_t Len); //��С��
    int16_t AsciiToInt16_P1(uint8_t *pSrc, uint8_t Len); //һλС��
    
    //Data:-1999 �� 9999
    //Des:4λ�������
    //zero_clr : �����Ƿ�����
    //PointSite: С����λ��
    //nodisp :����λ���ƣ�bit[7]�����Ƿ����أ�bit[1:0]ָʾ���ص�λ 0�����λ��3����ǧλ
    void i16_to_led_code(int16_t Data, uint8_t *Des, uint8_t zero_clr, uint8_t PointSite, uint8_t nodisp);
    
    //�����żУ��
    uint8_t EvenU8(uint8_t Data);                 //����8λ���ݵ�żУ������0��ʾż����1��1��ʾ������1
    uint8_t OddU8(uint8_t Data);                  //����8λ���ݵ���У������0��ʾ������1��0��ʾż����1
    uint8_t NoneParity(uint8_t Data);             //����8λ���ݵ���У����
    
    //����Ƚ�
    int8_t ArrayComp(uint8_t *Array1, uint8_t *Array2, uint16_t Len); //����Ƚ�
    
    //ascii ת hex
    uint8_t AsciiToHex2(uint8_t *Src);
    
    
    //�ƹ⽥�����
    uint32_t LedBreathHandle(led_breath_type *Brj);
    
    //��������
    int32_t Sub2Add8(float f_real, int32_t i_now); //�������
    int32_t SubAdd_x(float f_real, int32_t i_now, float val_sub); //�������룬����ֵval_sub[0.1-0.49]
    int32_t int_Sub2Add8(int32_t real, int32_t i_now);
    int32_t int_SubAdd_x(int32_t real, int32_t i_now, int32_t val_sub);
    
    /*memory */
    void copy_u8(void * src, void * des, uint32_t len); //len ָ��Ԫ������
    void copy_u16(void * src, void * des, uint32_t len); //len ָ��Ԫ������
    void copy_u32(void * src, void * des, uint32_t len); //len ָ��Ԫ������
    void set_u8(void * des, uint8_t data, uint32_t len); //len ָ��Ԫ������
    void set_u16(void * des, uint16_t data, uint32_t len); //len ָ��Ԫ������
    void set_u32(void * des, uint32_t data, uint32_t len); //len ָ��Ԫ������
    
    /*lrc = ~sum(list)+1 */
    uint8_t lrc_u8(void * dat, uint32_t len); //len ָ��Ԫ������
    uint16_t lrc_u16(void * dat, uint32_t len); //len ָ��Ԫ������
    uint32_t lrc_u32(void * dat, uint32_t len); //len ָ��Ԫ������
    
    /*xor =  0 xor (list) */
    uint8_t xor_u8(void * dat, uint32_t len); //len ָ��Ԫ������
    uint16_t xor_u16(void * dat, uint32_t len); //len ָ��Ԫ������
    uint32_t xor_u32(void * dat, uint32_t len); //len ָ��Ԫ������
    
    /*data add.*/
    void dat_add_u8(void *src, uint8_t data, uint32_t Len); //len ָ��Ԫ������
    void dat_add_u16(void *src, uint16_t data, uint32_t Len); //len ָ��Ԫ������
    void dat_add_u32(void *src, uint32_t data, uint32_t Len); //len ָ��Ԫ������
    void dat_sub_u8(void *src, uint8_t data, uint32_t Len); //len ָ��Ԫ������
    void dat_sub_u16(void *src, uint16_t data, uint32_t Len); //len ָ��Ԫ������
    void dat_sub_u32(void *src, uint32_t data, uint32_t Len);  //len ָ��Ԫ������
    
    /*----------------------------------------------------------------------*
    * ���ݼ�¼�����ݲ��ڵ�ǰ����λ��
    * p_list-��¼�б�dat-�����ݣ�p_index-����������ַ�� Len�б�Ԫ������
    *-----------------------------------------------------------------------*/
    void u8_record(void *p_list, uint8_t dat, uint16_t* p_index, uint16_t Len);
    void u16_record(void *p_list, uint16_t dat, uint16_t* p_index, uint16_t Len);
    void u32_record(void *p_list, uint32_t dat, uint16_t* p_index, uint16_t Len);
    
    /*----------------------------------------------------------------------*
    * ���ݼ�¼�������ݲ��ڱ�ͷ���������ݺ���
    * p_list-��¼�б�dat-������, Len�б���
    *-----------------------------------------------------------------------*/
    void u8_record_in_first(void *vp_list, uint8_t dat, uint16_t Len);
    void u16_record_in_first(void *vp_list, uint16_t dat, uint16_t Len);
    void u32_record_in_first(void *vp_list, uint32_t dat, uint16_t Len);
    
    /*����ƽ���ָ�*/
    void u16_average_segmentation(uint16_t dat, uint16_t amount, uint8_t *des);
        
    /*--���ݰ�ͼ�Ӽ�-- des =src1+src2, des=src1-src2*/
    void u32_map_add(uint32_t *src1, uint32_t *src2, uint32_t *des, uint32_t len);//len ָ��Ԫ������
    void u32_map_sub(uint32_t *src1, uint32_t *src2, uint32_t *des, uint32_t len);//len ָ��Ԫ������
    void u16_map_add(uint16_t *src1, uint16_t *src2, uint16_t *des, uint32_t len);//len ָ��Ԫ������
    void u16_map_sub(uint16_t *src1, uint16_t *src2, uint16_t *des, uint32_t len);//len ָ��Ԫ������
    void u8_map_add(uint8_t *src1, uint8_t *src2, uint8_t *des, uint32_t len);    //len ָ��Ԫ������
    void u8_map_sub(uint8_t *src1, uint8_t *src2, uint8_t *des, uint32_t len);    //len ָ��Ԫ������
    
    /*i16�����б�����*/
    typedef struct
    {
        int16_t sort_val;
        int16_t element_val;
    } str_2e_list_sort_val_type;
    
    void str_2e_list_sort(str_2e_list_sort_val_type *list, uint8_t len, int16_t min);
    
    /*i16�����б�����*/
    typedef struct
    {
        int16_t i_src;
        int16_t i_offset;
    } correct_i16point_type;
    
    float i16point_list_correct( correct_i16point_type *list, uint16_t list_len, float fval );
    
    /*float�����б�����*/
    typedef struct
    {
        float f_src;
        float f_offset;
    } correct_fpoint_type;
    
    float fpoint_list_correct( correct_fpoint_type *list, uint16_t list_len, float fval );
    
#ifdef	__cplusplus
}
#endif

#endif	/* DATAPROC_H */

