/*
 * File:   myType.h
 * Author: Administrator
 * version : v1.0.0
 * Created on 2014年7月5日, 下午5:51
 */

#ifndef MYTYPE_H
#define MYTYPE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stdint.h"

#ifndef bool
#define bool uint8_t
#endif

#ifndef u8
	typedef unsigned char u8;
	typedef unsigned short u16;
	typedef unsigned long u32;
	typedef unsigned long long u64;

	typedef signed char i8;
	typedef signed short i16;
	typedef signed long i32;
	typedef signed long long i64;
#endif

#ifndef uv8
	typedef volatile unsigned char uv8;
	typedef volatile unsigned short uv16;
	typedef volatile unsigned long uv32;
	typedef volatile unsigned long long uv64;

	typedef volatile signed char iv8;
	typedef volatile signed short iv16;
	typedef volatile signed long iv32;
	typedef volatile signed long long iv64;
#endif

#ifndef uc8
	typedef const unsigned char uc8;
	typedef const unsigned short uc16;
	typedef const unsigned long uc32;
	typedef const unsigned long long uc64;

	typedef const signed char ic8;
	typedef const signed short ic16;
	typedef const signed long ic32;
	typedef const signed long long ic64;
#endif

#ifndef inrom
#define inrom const
#endif

#ifndef code
#define code const
#endif

#ifndef TRUE            
#define TRUE            1
#endif

#ifndef FALSE                              
#define FALSE           0
#endif

#ifndef ENABLE
#define ENABLE          1
#endif

#ifndef DISABLE
#define DISABLE         0
#endif

	/*get memory data*/
#ifndef outpw
#define outpw(port,value)     *((volatile unsigned long *)(port)) = value
#define inpw(port)            (*((volatile unsigned long *)(port)))
#define outps(port,value)     *((volatile unsigned short *)(port)) = value
#define inps(port)            (*((volatile unsigned short *)(port)))
#define outpb(port,value)     *((volatile unsigned char *)(port)) = value
#define inpb(port)            (*((volatile unsigned char *)(port)))
#define outp32(port,value)    *((volatile unsigned long *)(port)) = value
#define inp32(port)           (*((volatile unsigned long *)(port)))
#define outp16(port,value)    *((volatile unsigned short *)(port)) = value
#define inp16(port)           (*((volatile unsigned short *)(port)))
#define outp8(port,value)     *((volatile unsigned char *)(port)) = value
#define inp8(port)            (*((volatile unsigned char *)(port)))
#endif

#define mem32(port)           (*((volatile unsigned long *)(port)))
#define mem16(port)           (*((volatile unsigned short *)(port))) 
#define mem8(port)           (*((volatile unsigned char *)(port)))
    
	/*类型合并分离*/
#define byte_lb(x) (x & 0xFF)
#define byte_hb(x) ((x >> 8) & 0xFF)
#define byte_ub(x) ((x >> 16) & 0xFF)
#define byte_mb(x) ((x >> 24) & 0xFF)

#define word_make(lb,hb)    ((uint16_t)((uint8_t)lb | ((uint8_t)hb << 8)))
#define dword_make(lw,hw)   ((uint32_t)((uint16_t)lw | ((uint16_t)hw << 16)))

	/*比较*/
#if !defined(MAX)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#if !defined(MIN)
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

	/*交换*/
#define swap32(ap, bp)          \
		      {                         \
            uint32_t temp = ap; \
            ap = bp;            \
            bp = temp;          \
		      }

#define swap16(ap, bp)          \
		      {                         \
            uint16_t temp = ap; \
            ap = bp;            \
            bp = temp;          \
		      }

#define swap08(ap, bp)         \
		      {                        \
            uint8_t temp = ap; \
            ap = bp;           \
            bp = temp;         \
		      }

	/*位处理*/
#ifndef SetBit
#define SetBit(VAR, Pos) ((VAR) |= (1ul << (Pos)))
#define ClrBit(VAR, Pos) ((VAR) &= ~(1ul << (Pos)))
#define TogBit(VAR, Pos) ((VAR) ^= (1ul << (Pos)))
#define GetBit(VAR, Pos) ((VAR) & (1ul << (Pos)))
#endif

#ifndef set_bit
#define set_bit SetBit
#define clr_bit ClrBit
#define tog_bit TogBit
#define get_bit GetBit
#endif

    /*范围检测*/
#define rang_offset(val, set, offset)  (((val+offset) >= set) && (val <= (set + offset)))    
#define rang_check(val, min, max)      ((val >= min)&&(val <= max))           
              
	/*UINT8 UINT16 UINT32 BITS */
	typedef union {
		uint8_t Val;
		uint8_t uVal;
		int8_t iVal;
		struct
		{
			uint8_t b0 : 1;
			uint8_t b1 : 1;
			uint8_t b2 : 1;
			uint8_t b3 : 1;
			uint8_t b4 : 1;
			uint8_t b5 : 1;
			uint8_t b6 : 1;
			uint8_t b7 : 1;
		} bits;
	} UINT8_VAL, UINT8_BITS;

	typedef union {
		uint16_t Val;
		uint16_t uVal;
		int16_t iVal;

		uint8_t v[2];
		struct
		{
			uint8_t LB;
			uint8_t HB;
		} byte;

		struct
		{
			uint16_t b0 : 1;
			uint16_t b1 : 1;
			uint16_t b2 : 1;
			uint16_t b3 : 1;
			uint16_t b4 : 1;
			uint16_t b5 : 1;
			uint16_t b6 : 1;
			uint16_t b7 : 1;
			uint16_t b8 : 1;
			uint16_t b9 : 1;
			uint16_t b10 : 1;
			uint16_t b11 : 1;
			uint16_t b12 : 1;
			uint16_t b13 : 1;
			uint16_t b14 : 1;
			uint16_t b15 : 1;
		} bits;
	} UINT16_VAL, UINT16_BITS;

	typedef union {
		uint32_t Val;
		uint32_t uVal;
		int32_t iVal;

		uint16_t w[2];
		uint8_t v[4];

		struct
		{
			uint8_t LB;
			uint8_t HB;
			uint8_t UB;
			uint8_t MB;
		} byte;

		struct
		{
			uint16_t LW;
			uint16_t HW;
		} word;

		struct
		{
			uint32_t b0 : 1;
			uint32_t b1 : 1;
			uint32_t b2 : 1;
			uint32_t b3 : 1;
			uint32_t b4 : 1;
			uint32_t b5 : 1;
			uint32_t b6 : 1;
			uint32_t b7 : 1;
			uint32_t b8 : 1;
			uint32_t b9 : 1;
			uint32_t b10 : 1;
			uint32_t b11 : 1;
			uint32_t b12 : 1;
			uint32_t b13 : 1;
			uint32_t b14 : 1;
			uint32_t b15 : 1;
			uint32_t b16 : 1;
			uint32_t b17 : 1;
			uint32_t b18 : 1;
			uint32_t b19 : 1;
			uint32_t b20 : 1;
			uint32_t b21 : 1;
			uint32_t b22 : 1;
			uint32_t b23 : 1;
			uint32_t b24 : 1;
			uint32_t b25 : 1;
			uint32_t b26 : 1;
			uint32_t b27 : 1;
			uint32_t b28 : 1;
			uint32_t b29 : 1;
			uint32_t b30 : 1;
			uint32_t b31 : 1;
		} bits;
	} UINT32_VAL, UINT32_BITS;


	/*BYTE WORD DWORD BITS */
	typedef union {
		uint8_t Val;
		uint8_t uVal;
		int8_t iVal;
		struct
		{
			uint8_t b0 : 1;
			uint8_t b1 : 1;
			uint8_t b2 : 1;
			uint8_t b3 : 1;
			uint8_t b4 : 1;
			uint8_t b5 : 1;
			uint8_t b6 : 1;
			uint8_t b7 : 1;
		} bits;
	} BYTE_VAL, BYTE_BITS, byte_tt;

	typedef union {
		uint16_t Val;
		uint16_t uVal;
		int16_t iVal;

		uint8_t v[2];
		struct
		{
			byte_tt LB;
			byte_tt HB;
		} byte;

		struct
		{
			uint16_t b0 : 1;
			uint16_t b1 : 1;
			uint16_t b2 : 1;
			uint16_t b3 : 1;
			uint16_t b4 : 1;
			uint16_t b5 : 1;
			uint16_t b6 : 1;
			uint16_t b7 : 1;
			uint16_t b8 : 1;
			uint16_t b9 : 1;
			uint16_t b10 : 1;
			uint16_t b11 : 1;
			uint16_t b12 : 1;
			uint16_t b13 : 1;
			uint16_t b14 : 1;
			uint16_t b15 : 1;
		} bits;
	} WORD_VAL, WORD_BITS, word_tt;

	typedef union {
		uint32_t Val;
		uint32_t uVal;
		int32_t iVal;

		uint16_t w[2];
		uint8_t v[4];

		struct
		{
			byte_tt LB;
			byte_tt HB;
			byte_tt UB;
			byte_tt MB;
		} byte;

		struct
		{
			word_tt LW;
			word_tt HW;
		} word;

		struct
		{
			uint32_t b0 : 1;
			uint32_t b1 : 1;
			uint32_t b2 : 1;
			uint32_t b3 : 1;
			uint32_t b4 : 1;
			uint32_t b5 : 1;
			uint32_t b6 : 1;
			uint32_t b7 : 1;
			uint32_t b8 : 1;
			uint32_t b9 : 1;
			uint32_t b10 : 1;
			uint32_t b11 : 1;
			uint32_t b12 : 1;
			uint32_t b13 : 1;
			uint32_t b14 : 1;
			uint32_t b15 : 1;
			uint32_t b16 : 1;
			uint32_t b17 : 1;
			uint32_t b18 : 1;
			uint32_t b19 : 1;
			uint32_t b20 : 1;
			uint32_t b21 : 1;
			uint32_t b22 : 1;
			uint32_t b23 : 1;
			uint32_t b24 : 1;
			uint32_t b25 : 1;
			uint32_t b26 : 1;
			uint32_t b27 : 1;
			uint32_t b28 : 1;
			uint32_t b29 : 1;
			uint32_t b30 : 1;
			uint32_t b31 : 1;
		} bits;
	} DWORD_VAL, DWORD_BITS, dword_tt;

#ifdef __cplusplus
}
#endif

#endif /* MYTYPE_H */
