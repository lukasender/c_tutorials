/*
 * tasks.h
 *
 *  Created on: 15.11.2012
 *      Author: lumannnn
 */

#ifndef TASKS_H_
#define TASKS_H_

/*
 * Data structure of all known functions a task is able to execute.
 */
typedef struct {
	int (*init) (int taskId);
	int (*poll) (void);
	int (*notify) (int msg);
} Task_t;

#endif /* TASKS_H_ */
