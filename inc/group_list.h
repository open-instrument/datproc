/* 
 * File:   group_list.h
 * Author: apleilx
 */

#ifndef __GROUP_LIST__H_
#define	__GROUP_LIST__H_

#include "stdint.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define GROUP_LIST_ERR_NONE                0x00
#define GROUP_LIST_ERR_NO_PROG             0x01
#define GROUP_LIST_ERR_POS_EE              0x02
#define GROUP_LIST_ERR_GRP_EE              0x03


typedef struct
{
    uint8_t group_size; //
    uint8_t pos_size;   //set with the max program number
    uint8_t group;
    uint8_t pos;
    int8_t prog; //program number
    int8_t *p_prog_num_list;
    uint8_t err;
} mj_group_list_st_type;

 
void mj_group_list_reset(mj_group_list_st_type* list);
void mj_group_list_creat(mj_group_list_st_type* list);

/*-----------------------------------------------------------------------------------*
* search next program number
* reasurt in str->group,pos,prog
* return prog, -1 is nothing
*------------------------------------------------------------------------------------*/
int8_t mj_group_list_next_pos(mj_group_list_st_type* list, uint8_t group_now, uint8_t pos_now);

/*-----------------------------------------------------------------------------------*
* search next program number
* reasurt in str->group,pos,prog
* return prog, -1 is nothing
*------------------------------------------------------------------------------------*/
int8_t mj_group_list_next_prog(mj_group_list_st_type* list, uint8_t prog_now);

/*-----------------------------------------------------------------------------------*
* search fore program number
* reasurt in str->group,pos,prog
* return prog, -1 is nothing
*------------------------------------------------------------------------------------*/
int8_t mj_group_list_fore_pos(mj_group_list_st_type* list, uint8_t group_now, uint8_t pos_now);

/*-----------------------------------------------------------------------------------*
* search fore program number
* reasurt in str->group,pos,prog
* return prog, -1 is nothing
*------------------------------------------------------------------------------------*/
int8_t mj_group_list_fore_prog(mj_group_list_st_type* list, uint8_t prog_now);

/*-----------------------------------------------------------------------------------*
* get the first space in group
* retrun sapce pos , -1 is nothing
*------------------------------------------------------------------------------------*/
int8_t mj_group_list_get_space_offset(mj_group_list_st_type* list, uint8_t group_now);

/*-----------------------------------------------------------------------------------*
* get program number
* reasurt in str->prog
* return prog
*------------------------------------------------------------------------------------*/
int8_t mj_group_list_get_prog(mj_group_list_st_type* list, uint8_t group_now, uint8_t pos_now);

/*-----------------------------------------------------------------------------------*
* get group pos
* reasurt in str->prog
* return pos
*------------------------------------------------------------------------------------*/
int8_t mj_group_list_get_pos(mj_group_list_st_type* list, uint8_t prog_now);

/*-----------------------------------------------------------------------------------*
* add prog
* retrun sapce pos , -1 is err
*------------------------------------------------------------------------------------*/
int8_t mj_group_list_prog_add(mj_group_list_st_type* list, uint8_t group, uint8_t pos, uint8_t prog);

/*-----------------------------------------------------------------------------------*
* delete prog
* retrun sapce pos , -1 is err
*------------------------------------------------------------------------------------*/
int8_t mj_group_list_prog_del(mj_group_list_st_type* list, uint8_t group, uint8_t pos);

#ifdef	__cplusplus
}
#endif

#endif	/* __GROUP_LIST__H_ */

