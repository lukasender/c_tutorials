/*
 * task2_poll.c
 *
 *  Created on: 15.11.2012
 *      Author: lumannnn
 */

#include <stdio.h>

int task2_init(int taskId) {
	return 0;
}

int task2_poll() {
	printf("task2\n");
	return 0;
}

/*
 * Returns the message which the next task has to respond with.
 * I don't know if this is the right thing to do... but fuck it.. it's the way it is.
 */
int task2_notify(int msg) {
	if (msg == 0x1) {
		printf("HELLO\n");
		return 0x2;
	}
	if (msg == 0x2) {
		printf("BUSY\n");
		return 0x4;
	}
	if (msg == 0x4) {
		printf("BYE\n");
		return 0x1;
	}
	return 0x0;
}
