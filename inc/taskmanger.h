/*
 * File:   taskmanger.h
 * Author: Administrator
 */

#ifndef TASKMANGER_H
#define	TASKMANGER_H

#include "stdint.h"

#define TASK_PRIO_MAX           64
#define TASK_TASK_STATE_SLEEP   0
#define TASK_TASK_STATE_ACTIVE  1

typedef struct OST_CB
{
    uint8_t  Priority;
    uint8_t  TaskSt;
    struct OST_CB * NextTask;
    void(*TaskPtr)(void);
} TASK_TCB;

/* for signal thread, 该组有开关中断操作*/
void os_task_init(void);
void os_task_add(TASK_TCB *TaskTCB, uint8_t Prio, void(*TaskPtr)(void));
void os_task_del(TASK_TCB *TaskTCB);
void os_task_run(void);
void os_task_pend(TASK_TCB *TCB);
void os_task_post(TASK_TCB *TCB);

/*extern function*/
void task_switchHook(void);
void task_enable_irq(void);
void task_disable_irq(void);

/* for multi list， 以下模型无开关中断操作, 最大可添加16个任务*/
typedef struct 
{
    void (*list[16])(uint8_t *);
    void (*switchHook)(uint8_t *);
} task_vector_type;


void task_list_init(task_vector_type *vect, void(*IdleTaskPtr)(uint8_t*), void(*sw_hook)(uint8_t*));
void task_list_add(task_vector_type *vect, void(*TaskPtr)(uint8_t*));
void task_list_del(task_vector_type *vect, void(*TaskPtr)(uint8_t*));
void task_list_run(task_vector_type *vect);

#ifdef	__cplusplus
extern "C" {
#endif



#ifdef	__cplusplus
}
#endif

#endif	/* TASK_H */

