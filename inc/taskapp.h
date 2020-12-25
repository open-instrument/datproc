/* 
 * File:   taskapp.h
 * Author: Administrator
 */

#ifndef TASKAPP_H
#define	TASKAPP_H

#ifdef   _TASKAPP_MODULE_
#define  TASKAPP_EXT
#else
#define  TASKAPP_EXT  extern
#endif

#include "taskmanger.h"

	TASKAPP_EXT TASK_TCB    IdleTaskTCB;

	void idle_task(void);
	void idle_task_hook(void);

#ifdef	__cplusplus
extern "C" {
#endif



#ifdef	__cplusplus
}
#endif

#undef TASKAPP_EXT

#endif	/* TASK_H */

