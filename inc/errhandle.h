/*
  * @brief   �����������Ϊ����״̬��������֧�ֶ������趨
*/

#ifndef ERR_HANDLE_H_H
#define ERR_HANDLE_H_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __ERR_HANDLE_MOUDLE__
#define ___EXT
#else
#define ___EXT extern
#endif

#define ERR_GROUP_LEN 4

  typedef struct
  {
    uint8_t b_global;                   //X�ⲿ��ȡ
    uint8_t b_found_edge;               //X�ⲿ��ȡ
    uint8_t b_lost_edge;                //X�ⲿ��ȡ
    uint8_t b_disp_switch_pulse;        //Y�ⲿ�趨����ʾֵ�л�����
    uint8_t b_space_en;                 //Y�ⲿ�趨����ʾֵ�л�����      
    uint8_t b_space_st;                 //X�ⲿ��ȡ�����ܼ�����ʱ�����һ����ʾѭ����������һ������ļ��������� disp_code=0xFFFF��disp_err=0
    uint16_t disp_code;                 //X�ⲿ��ȡ����ǰ��ʾֵ[15:8-group][7:0-bitpos]��0xFFFF������Чֵ
    uint32_t disp_err;                  //X�ⲿ��ȡ������ֵ����sys_err_make���ɵ�ֵ��    0x0000������Чֵ
    uint16_t val[ERR_GROUP_LEN];        //XY��ǰֵ,�ⲿ�趨
    uint16_t old[ERR_GROUP_LEN];        //X�ڲ�ʹ��
    uint16_t found_edge[ERR_GROUP_LEN]; //X�ⲿ��ȡ
    uint16_t lost_edge[ERR_GROUP_LEN];  //X�ⲿ��ȡ
    uint16_t mask[ERR_GROUP_LEN];       //X�ⲿ�趨
  } sys_err_type;

/*
  ����err��������
  bits[15:0]  - err flag
  bits[18:16] - err group
  */
  
#define sys_err_make(group, pos) (((uint32_t)group<<16)|(1UL << pos))
  
#define sys_err_set(obj, err) obj.val[err >> 16] |=  (err & 0xFFFF)
#define sys_err_clr(obj, err) obj.val[err >> 16] &= ~(err & 0xFFFF)
#define sys_err_msk(obj, msk) obj.mask[msk >> 16] = msk & 0xFFFF

#define sys_err_get(obj, err) (obj.val[err >> 16] & (err & 0xFFFF))
#define sys_err_found_edge_get(obj, err) (obj.found_edge[err >> 16] & (err & 0xFFFF))
#define sys_err_lost_edge_get(obj, err) (obj.lost_edge[err >> 16] & (err & 0xFFFF))

  void err_init(sys_err_type *sys_err);
  void err_poll(sys_err_type *sys_err);

#ifdef __cplusplus
}
#endif

#endif /* ERR_HANDLE_H_H */
