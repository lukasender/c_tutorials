/*
 ============================================================================
 Name        : MiniOS.c
 Author      : Lukas Ender
 Version     :
 Copyright   : 
 Description : MiniOS in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "tasks.h"
#include "tasks/task1.h"
#include "tasks/task2.h"

/* define tasks */
Task_t tasks[] = { {&task1_init, &task1_poll, &task1_notify}, {&task2_init, &task2_poll, &task2_notify} };

#define NR_OF_TASKS ( sizeof(tasks) / sizeof(Task_t) )

/* Event handles a taskId and stores a message for that task with the specified taskId */
typedef struct {
	int taskId;
	int message;
} Event_t;

/* global event which is handled by the OS */
Event_t event = { 0, 0x1 };

/* helper functions for the OS. implementation see below */
void setEvent(int taskId, int msg);
void delay(int d);

int main(void) {
	int currTask = 0;	/* task which has to be handled in the current cycle */
	int nextTask = 0;	/* task which has to be handled in the next cycle */

	/* initialize tasks */
	for (currTask = 0; currTask < NR_OF_TASKS; currTask++) {
		tasks[currTask].init(currTask);
	}

	currTask = -1;
	int i = 0;

	/* set a default event for task with taskId = 0 */
	setEvent(0, 0x1);

	while(i == 0) {
		currTask = (++currTask) % NR_OF_TASKS;		/* get current taskId */
		nextTask = (currTask + 1) % NR_OF_TASKS;	/* get next taskId */

		i = tasks[currTask].poll();					/* execute poll function */

		/* set event for the next task with the message from the current task */
		if (currTask == event.taskId && event.message != 0x0) {
			setEvent(nextTask, tasks[currTask].notify(event.message));
		}

		/* delay... C is quite fast. I want to see what I did.. so force it to slow down... */
		delay(100);
	}

	return EXIT_SUCCESS;
}

/* set global event */
void setEvent(int taskId, int msg) {
	event.taskId = taskId;
	event.message = msg;
}

/* just a delay. nothing specific :D  */
void delay(int d) {
	d*=1000000;
	while(d-- > 0);
}
