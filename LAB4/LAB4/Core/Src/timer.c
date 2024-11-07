/*
 * timer.c
 *
 *  Created on: Sep 30, 2024
 *      Author: User
 */


#include "main.h"
#include "input_reading.h"
#include "input_processing.h"
 #include "led_display.h"
 #include "timer.h"



#define NUM_TIMERS 10  // Number of timers you want to handle
#define TICK 10
int timer_flag[NUM_TIMERS];  // Timer flags for each timer
int timer_counter[NUM_TIMERS];  // Timer counters for each timer

void setTimer(int timer_id, int duration)
{
	if (timer_id >= 0 && timer_id < NUM_TIMERS)
	    {
	        timer_counter[timer_id] = duration / TICK;
	        timer_flag[timer_id] = 0;
	    }
}
void timerRun(void)
{
    for (int i = 0; i < NUM_TIMERS; i++)
    {
        if (timer_counter[i] >= 0)
        {
            timer_counter[i]--;

            if (timer_counter[i] <= 0)
            {
                timer_flag[i] = 1;
            }
        }
    }
}
void update_handlemode(){
//	if (timer_flag[1] == 1){
//		timeledlight();
//		setTimer(1,10);
//	 }
//	if (timer_flag[2] == 1) {
//		button_reading();
//		setTimer(2, 10);
//	}
//	if (timer_flag[5] == 1) {
//		handle_mode();
//		setTimer(5, 500);
//	}
//	  SCH_Add_Task(button_reading, 10, 10);
//	  SCH_Add_Task(handle_mode, 10, 10);
//	  SCH_Add_Task(timeledlight, 500, 500);
}


