#ifndef _RTC_TIME_H_
#define	_RTC_TIME_H_

#include "stdint.h"     
#include "time.h"    

    typedef struct {
        uint8_t Sec; 		/*!< Seconds Register */
        uint8_t Min; 		/*!< Minutes Register */
        uint8_t Hour; 		/*!< Hours Register */
		uint8_t Week;       /*!< Week Register */
        uint8_t Day;		/*!< Day of Month Register */
        uint8_t Mon; 	    /*!< Months Register */
        uint16_t Year; 		/*!< Years Register */
    } TIME_Type;

//*********************************Time ***********************************//
    typedef union{
        uint32_t val;
        struct {
            uint32_t sec2t:5;
            uint32_t min  :6;
            uint32_t hour :5;
            uint32_t day  :5;
            uint32_t mon  :4;
            uint32_t year :7;
        } time;
        
        struct {
            uint32_t rs   :3; //0-nor, 1-start, 2-tail, 
            uint32_t flag :2; //0-dat, 1-info
            uint32_t min  :6;
            uint32_t hour :5;
            uint32_t day  :5;
            uint32_t mon  :4;
            uint32_t year :7;
        } log; 
    } sig_time_type;

    typedef union{
        uint32_t val;
        struct {
            uint32_t min  :7;
            uint32_t hour :6;
            uint32_t day  :6;
            uint32_t mon  :5;
            uint32_t year :8;
        } time;
    } bcd_time_type;

 
    //基本时间操作
    void TimeRun(TIME_Type *TimeCur);
    void rtc_time_run_sec(TIME_Type *TimeCur, uint32_t sec_add);
    void rtc_time_run_min(TIME_Type *TimeCur, uint32_t min_add);
    void rtc_time_run_hour(TIME_Type *TimeCur, uint32_t hour_add);
    
    int8_t TimeCompare(TIME_Type *pTime1,TIME_Type *pTime2);//* @pTime1-pTime2【  == : 0        >: 1           <: -1 】
    void TimeCopy(TIME_Type *pTimeSrc,TIME_Type *pTimeDes);
    
    //格式转换
    bcd_time_type time_sig_to_bcd( sig_time_type sig_time);
    sig_time_type  time_bcd_to_sig(bcd_time_type  bcd_time);
    bcd_time_type time_to_bcd( TIME_Type * time);
    sig_time_type time_to_sig(TIME_Type *pTimeSrc);
    void time_sig_to_time(sig_time_type sig, TIME_Type *pTimeSrc);
    
    /*时间字符串转换*/
    int8_t AsciiToTime(uint8_t *Src,TIME_Type *pTime);
    uint8_t TimeToAscii(TIME_Type *pTime,uint8_t *Des);
    uint8_t TimeNoSecToAscii(TIME_Type *pTime,uint8_t *Des);
    uint8_t DateToAscii(TIME_Type *pTime,uint8_t *Des);
    uint8_t ClockTimeToAscii(TIME_Type *pTime,uint8_t *Des);
    uint8_t bcd_time_to_ascii(bcd_time_type  bcd_time, uint8_t *des);
    
    //time.h扩展
    time_t sig_time_diff(sig_time_type end, sig_time_type start);
    uint8_t sig_time_to_tm(sig_time_type sig, struct tm *tim);
    uint8_t time_to_tm(TIME_Type *time, struct tm *tim);
    
#undef TIME_EXT

#endif	/* _RTC_TIME_H_ */

