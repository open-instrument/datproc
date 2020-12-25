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
    int16_t  SetPoint;      //�ⲿ����      YYY
	int16_t  CurPoint;      //�ⲿ����      YYY
    int8_t   Coef;          //YYY   >1Ϊ��̬��С�ڵ���1Ϊ��̬
    uint8_t  bFollowSt;     //�Ƿ������٣��ⲿ���� �趨ֵ�仯�Զ��˳�      YYY
    uint8_t  bStadySt;      //XX �¶�״̬
    uint8_t  bCalPulse;     //��������    ���ⲿ����      YYY
    uint8_t  KeepTimeSv;    //�����׶α���ʱ��,�ⲿ����      YYY
    uint16_t FollowQuitPeriod;   //�˸������ڣ��ⲿ����      YYY
    uint16_t FollowEntryPeriod;  //���������ڣ��ⲿ����      YYY
    uint16_t FollowQuitDelaySv;  //�ⲿ����      YYY
    uint16_t FollowEntryDelaySv; //�ⲿ����      YYY
    int16_t  FollowValMaxSet;    //�ⲿ����      YYY
    uint16_t DataOutPeriod;      //���ݼ�¼����,�������      YYY
    
    uint16_t PulseAutoCnt;       //�ڲ�����
	int16_t  FollowVal;          //�ڲ�����
    int16_t  DispVal;            //�ڲ�����XX
    int16_t  SetPointOld;        // XX
    int16_t  CurPointOld;        // XX
    int16_t  KeepVal;            // XX
    uint8_t  KeepTimeCnt;        // XX
    
    uint16_t FollowQuitDelayCnt; //�ڲ����� XX
    uint16_t FollowEntryDelayCnt;//�ڲ�����  XX
} disp_flt_t;


void disp_flt_mixed(disp_flt_t *DispObj);

#ifdef	__cplusplus
}
#endif



#endif	/* _FLT_DISPLIB_H_ */

