/*
 * scheduler.c
 *
 *  Created on: Nov 5, 2024
 *      Author: User
 */

#include "scheduler.h"
#include <stddef.h>  // Đảm bảo NULL được định nghĩa

sTasks SCH_tasks_G[SCH_MAX_TASKS];
void SCH_Init(void){
	unsigned char i;
	for(i=0;i<SCH_MAX_TASKS;i++){
		SCH_Delete_Task(i);
	}

}


void SCH_Add_Task ( void (*pFunction)(),
					uint32_t DELAY,
					uint32_t PERIOD){
	unsigned char Index = 0;
	while ((SCH_tasks_G[Index].pTask != NULL) && (Index < SCH_MAX_TASKS)) {
	        Index++;
	    }

	if (Index < SCH_MAX_TASKS) {
	        SCH_tasks_G[Index].pTask = pFunction;
	        SCH_tasks_G[Index].Delay = DELAY / TICK;
	        SCH_tasks_G[Index].Period = PERIOD / TICK;
	        SCH_tasks_G[Index].RunMe = 0;
	        SCH_tasks_G[Index].TaskID = Index;
	    }
}

void SCH_Update ( void ) {
	unsigned char Index ;
	for ( Index = 0; Index < SCH_MAX_TASKS; Index++) {
		if ( SCH_tasks_G [Index].pTask ) {
			if ( SCH_tasks_G [Index].Delay == 0 ) {
				SCH_tasks_G [Index].RunMe ++;
				if ( SCH_tasks_G[Index].Period ) {
					SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period ;
				}
			} else {
				SCH_tasks_G [Index].Delay --;
			 }
		}
	 }
}


void SCH_Delete_Task(uint32_t taskID) {
    if (taskID >= SCH_MAX_TASKS) return;
    SCH_tasks_G[taskID].pTask = NULL;
    SCH_tasks_G[taskID].Delay = 0;
    SCH_tasks_G[taskID].Period = 0;
    SCH_tasks_G[taskID].RunMe = 0;
}

void SCH_Dispatch_Tasks(void) {
    for (unsigned char Index = 0; Index < SCH_MAX_TASKS; Index++) {
        if (SCH_tasks_G[Index].pTask != NULL && SCH_tasks_G[Index].RunMe > 0) {
            (*SCH_tasks_G[Index].pTask)();
            SCH_tasks_G[Index].RunMe--;
            if (SCH_tasks_G[Index].Period == 0) {
                SCH_Delete_Task(Index);
            }
        }
    }
}
