/* 
 * File:   staticpulse.h
 * Author: apleilx
 */

#ifndef __STATIC_PULSE_N_H_
#define	__STATIC_PULSE_N_H_

#include "stdint.h"

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef __STATIC_PULSE_MODEL__
#define MY_EXT
#else
#define MY_EXT extern
#endif

typedef struct
{
     uint8_t  b_pulse_100ms, b_pulse_200ms, b_pulse_500ms, b_pulse_1s;
     uint8_t  b_pulse_10ms, b_pulse_20ms, b_pulse_30ms, b_pulse_50ms;
     uint8_t  b_wave_100ms, b_wave_200ms, b_wave_500ms, b_wave_1s;

     uint8_t  pulse_tick_old;
     uint8_t  pulse_100ms_cnt;  //base on 1ms
     uint8_t  pulse_200ms_cnt;  //base on 100ms
     uint8_t  pulse_500ms_cnt;  //base on 100ms
     uint8_t  pulse_1s_cnt;     //base on 100ms
     uint8_t  pulse_10ms_cnt;   //base on 1ms
     uint8_t  pulse_20ms_cnt;   //base on 1ms
     uint8_t  pulse_30ms_cnt;   //base on 1ms
     uint8_t  pulse_50ms_cnt;   //base on 1ms

} sc_pulse_type;

MY_EXT sc_pulse_type  sc_pulse;

void sc_pulse_creat(uint8_t uTick);

#ifdef	__cplusplus
}
#endif


#endif	/* __STATIC_PULSE_N_H_ */

