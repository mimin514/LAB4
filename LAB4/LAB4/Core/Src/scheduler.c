/*
 * scheduler.c
 *
 *  Created on: Nov 5, 2024
 *      Author: User
 */

#include "scheduler.h"

sTasks SCH_tasks_G[SCH_MAX_TASKS];

uint8_t current_index_task = 0;

void SCH_Init(void){
	current_index_task=0;

	for(uint8_t i = 0; i < SCH_MAX_TASKS; i++) {
	        SCH_tasks_G[i].pTask = 0;
	        SCH_tasks_G[i].Delay = 0;
	        SCH_tasks_G[i].Period = 0;
	        SCH_tasks_G[i].RunMe = 0;
	        SCH_tasks_G[i].TaskID = 0xFF; // Assuming 0xFF means unused
	    }

}

uint32_t SCH_Add_Task ( void (*pFunction)(),
					uint32_t DELAY,
					uint32_t PERIOD){
	if(current_index_task < SCH_MAX_TASKS){
		SCH_tasks_G[current_index_task].pTask=pFunction;
		SCH_tasks_G[current_index_task].Delay=DELAY/ TICK;
		SCH_tasks_G[current_index_task].Period=PERIOD/ TICK;
		SCH_tasks_G[current_index_task].RunMe=0;

		SCH_tasks_G[current_index_task].TaskID=current_index_task;

		return current_index_task++ ;
	}
	return SCH_MAX_TASKS;
}

void SCH_Update(void){
	for(uint8_t i=0;i<current_index_task;i++){
		if(SCH_tasks_G[i].Delay > 0)
			SCH_tasks_G[i].Delay --;
		else {
			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
			SCH_tasks_G[i].RunMe++;
		}
	}
}

void SCH_Dispatch_Tasks(void){
	for (uint8_t i = 0; i < current_index_task; i++) {
		if (SCH_tasks_G[i].RunMe > 0) {
			(*SCH_tasks_G[i].pTask)(); // Gọi task
			SCH_tasks_G[i].RunMe--;

			if (SCH_tasks_G[i].Period == 0) {
				SCH_Delete_Task(SCH_tasks_G[i].TaskID); 			}
		}
	}
}
uint8_t SCH_Delete_Task(uint32_t taskID) {
    if (taskID >= SCH_MAX_TASKS || SCH_tasks_G[taskID].pTask == 0) {
        return 0;
    }

    SCH_tasks_G[taskID].pTask = 0;
    SCH_tasks_G[taskID].Delay = 0;
    SCH_tasks_G[taskID].Period = 0;
    SCH_tasks_G[taskID].RunMe = 0;
    SCH_tasks_G[taskID].TaskID = 0xFF;
    return 1;
}
