/* 
 * File:   iohandle.h
 * Author: Administrator
 *
 * Created on 2014年9月15日, 下午8:29
 */

#ifndef IO_HANDLE_H_
#define	IO_HANDLE_H_

#ifdef	__cplusplus
extern "C" {
#endif

#include "stdint.h"
 
    /*key handle*/
    typedef struct {
        uint8_t  b_pulse_100ms;
        uint8_t read_flt_cnt; //采样滤波计数
        uint8_t read_flt_sv;  //采样滤波次数设置//小于2均为2次采样滤波
        uint8_t b_first_key;  //首个按键
        uint16_t found_time_cnt;
        uint16_t lost_time_cnt;
        uint16_t keep_time_cnt;
        uint32_t val;
        uint32_t old;
        uint32_t edge;
        uint32_t found_edge;
        uint32_t lost_edge;
        uint32_t read;
        uint32_t read_old;
    } key_type;
    void key_st_handle(key_type *key);
    void key_st_sample(key_type *key, uint32_t key_read);
    #define key_st_isr   key_st_sample
    
    /*io st*/
    typedef struct {
        uint8_t  time_pulse;  //计时脉冲
        uint8_t  sample_pulse; //采样脉冲    
        uint8_t  val   ;
        uint8_t  old    ;
        uint8_t found_edge;
        uint8_t lost_edge;
        uint8_t sample_old;
        uint8_t sample_keep_cnt;//0-UINT8_MAX
        uint32_t found_time_cnt;//0-UINT32_MAX
        uint32_t lost_time_cnt;//0-UINT32_MAX
    } in_switch_st_type;

    typedef struct {
        struct
        {
            uint8_t  time_pulse : 1;  //计时脉冲
            uint8_t  sample_pulse: 1; //采样脉冲    
            uint8_t  val   : 1;
            uint8_t  old    : 1;
            uint8_t found_edge: 1;
            uint8_t lost_edge: 1;
            uint8_t sample_old: 1;
        } st;
        uint8_t sample_keep_cnt;//0-UINT8_MAX
        uint16_t found_time_cnt;//0-UINT16_MAX
        uint16_t lost_time_cnt;//0-UINT16_MAX
    } simp_switch_st_type;  //采用位态（节省内存，效率略降），最大计时缩短，功能同in_switch_st_type
    
    typedef struct {
        uint8_t  time_pulse;  //计时脉冲 
        uint8_t  old;
        uint8_t enable_edge;
        uint8_t disable_edge;
        uint32_t enable_time_cnt;//0-UINT32_MAX
        uint32_t disable_time_cnt;//0-UINT32_MAX
    } out_st_type;
    
    typedef struct {
        struct
        {
            uint8_t  time_pulse :1;  //计时脉冲 
            uint8_t  old:1;
            uint8_t enable_edge:1;
            uint8_t disable_edge:1;
        } st;
        uint16_t enable_time_cnt;//0-UINT16_MAX
        uint16_t disable_time_cnt;//0-UINT16_MAX
    } simp_out_st_type;
    
    void in_switch_handle(in_switch_st_type *swobj, uint8_t sw_now);  //内部滤波次数固定值6，输入可以是0和任意非零状态
    void simp_switch_handle(simp_switch_st_type *swobj, uint8_t sw_now);  //内部滤波次数固定值6，输入必须是0和1两个状态
    void out_st_handle(out_st_type *obj, uint8_t out_now);
    void simp_out_st_handle(simp_out_st_type *obj, uint8_t out_now);
    
    /*--------------------------------------------------------------------------------------------------------------------------*/
    /*rot st*/
    typedef struct {
        uint8_t a_st;
        uint8_t a_old;
        uint8_t b_st;
        uint8_t b_old;
        uint8_t b_clock;
        uint8_t b_unti_clock;
        uint16_t clock_none_time_cnt; //间隔计时器，每次调用递增，检测到任意有效旋转，记录该值到 clock_interval
        uint16_t clock_interval;      //间隔
    } rot_key_type;
    
    void rot_key_handle(rot_key_type *key, uint8_t a, uint8_t b);
    
    /*--------------------------------------------------------------------------------------------------------------------------*/
    typedef struct 
    {
        uint8_t st;     //当前有效状态
        int8_t flt_cnt; //滤波计数，负方向为无效状态，正方向为有效状态，回差带内保持(包含边界)
    } io_flt_type;

    typedef struct 
    {
        struct
        {
            uint8_t st : 1;     //当前有效状态
            uint8_t old : 1;
            uint8_t edge : 1;
            uint8_t edge_found : 1;
            uint8_t edge_lost : 1;
            uint8_t pulse_sample: 1; //采样脉冲
            uint8_t pulse_time: 1; //计时脉冲
        } st;

        int8_t flt_cnt; //滤波计数，负方向为无效状态，正方向为有效状态，回差带内保持(包含边界)
        uint16_t found_time_cnt;
        uint16_t lost_time_cnt;
    } io_flt_ext_type;
    
    uint8_t io_flt(io_flt_type *io_obj, int8_t flt_sv, uint8_t st_now); //flt_sv 滤波设定，回差带为 (-sv~sv)  ,输出状态改变需要1+2*sv个持续输入
    uint8_t io_flt_ext(io_flt_ext_type *io_obj, int8_t flt_sv, uint8_t st_now); //flt_sv 滤波设定，回差带为 (-sv~sv)  ,输出状态改变需要1+2*sv个持续输入
    
    /*--------------------------------------------------------------------------------------------------------------------------*/
    typedef struct
    {
        uint8_t out;
        uint8_t en_edge;
        uint8_t dis_edge;
        uint8_t en_req;
        uint8_t dis_req;
        uint32_t en_time;
        uint32_t dis_time;
    } out_sw_type;;
    /* time_sv 设为0保持一个脉冲，设为其他值保持设定数值脉冲数    */
    /* pulse 为计时脉冲                                           */
    uint8_t out_sw_manage(out_sw_type * out_obj, uint32_t en_time_sv, uint32_t dis_time_sv, uint8_t pulse);
    
    /*--------------------------------------------------------------------------------------------------------------------------*/
    typedef struct
    {
        uint8_t out;
        uint8_t err;
        uint16_t en_time;
        uint16_t dly_time;
    } wt_add_type;;

    /* ot_time_sv  为0时无补水功能，强制关闭输出 */
    /* pulse 为计时脉冲                                           */
    uint8_t wt_add_manage(wt_add_type * out_obj, uint8_t wt_st, uint16_t ot_time_sv, uint16_t dly_time_sv, uint8_t pulse);

    /*-------------------------------------------------------------------------------------------------------------------------*/
    typedef struct
    {
        uint8_t out0;    //X
        uint8_t out1;    //X
        uint8_t mode;    //Y 0-关闭，1out0,2-out1, 其他切换
        uint8_t out_sel; //X
        int32_t out0_en_time;   //X
        int32_t out0_dis_time;  //X
        int32_t out1_en_time;   //X
        int32_t out1_dis_time;  //X
        int32_t delay_cnt;  //X
        int32_t dev_off_min_time;  //Y 设备最小停机时间
    } dev_double_sw_type;;
    
    /*****************************************************************************-/
    * @brief   Double cool time handle.
    *          switch_time 必须大于 switch_time_befor+mintime，否则将强制switch_time = switch_time_befor+mintime
    * @param   dev： obj
    * @param   switch_time_set : switch time
    * @param   switch_time_befor : 正数 before-time, 负数delay-time
    * @param   pulse : 计时脉冲
    *****************************************************************************/
    void dev_double_sw(dev_double_sw_type * dev, int32_t switch_time_set, int32_t switch_time_befor, uint8_t pulse);

    
#ifdef	__cplusplus
}
#endif

#endif	/* IO_HANDLE_H_ */

