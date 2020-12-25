/* 
 * File:   disp flt.h
 * Author: apleilx
 */

#ifndef _FLT_DISPLIB_H_
#define	_FLT_DISPLIB_H_

#include <stdint.h>


#ifdef	__cplusplus
extern "C" {
#endif

typedef struct {
    int16_t  SetPoint;      //外部更新      YYY
	int16_t  CurPoint;      //外部更新      YYY
    int8_t   Coef;          //YYY   >1为动态，小于等于1为静态
    uint8_t  bFollowSt;     //是否开启跟踪，外部控制 设定值变化自动退出      YYY
    uint8_t  bStadySt;      //XX 温定状态
    uint8_t  bCalPulse;     //计算脉冲    ，外部更新      YYY
    uint8_t  KeepTimeSv;    //消抖阶段保持时间,外部更新      YYY
    uint16_t FollowQuitPeriod;   //退跟踪周期，外部更新      YYY
    uint16_t FollowEntryPeriod;  //进入踪周期，外部更新      YYY
    uint16_t FollowQuitDelaySv;  //外部设置      YYY
    uint16_t FollowEntryDelaySv; //外部设置      YYY
    int16_t  FollowValMaxSet;    //外部设置      YYY
    uint16_t DataOutPeriod;      //数据记录周期,输出周期      YYY
    
    uint16_t PulseAutoCnt;       //内部管理
	int16_t  FollowVal;          //内部管理
    int16_t  DispVal;            //内部管理，XX
    int16_t  SetPointOld;        // XX
    int16_t  CurPointOld;        // XX
    int16_t  KeepVal;            // XX
    uint8_t  KeepTimeCnt;        // XX
    
    uint16_t FollowQuitDelayCnt; //内部管理 XX
    uint16_t FollowEntryDelayCnt;//内部管理  XX
} disp_flt_t;


void disp_flt_mixed(disp_flt_t *DispObj);

#ifdef	__cplusplus
}
#endif



#endif	/* _FLT_DISPLIB_H_ */

