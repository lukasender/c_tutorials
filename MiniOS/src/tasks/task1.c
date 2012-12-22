/*
 * task1_poll.c
 *
 *  Created on: 15.11.2012
 *      Author: lumannnn
 */

#include <stdio.h>

int task1_init(int taskId) {
	return 0;
}

int task1_poll() {
	printf("task1\n");

	/*
	int i = 0;
	i = getchar();
	// '0' == 48 in ASCII
	if (i == 48) {
		i = 0;
	}
	*/

	return 0;
}

/*
 * Returns the message which the next task has to respond with.
 * I don't know if this is the right thing to do... but fuck it.. it's the way it is.
 */
int task1_notify(int msg) {
	if (msg == 0x1) {
		printf("HELLO\n");
		return 0x1;
	}
	if (msg == 0x2) {
		printf("BUSY\n");
		return 0x2;
	}
	if (msg == 0x4) {
		printf("BYE\n");
		return 0x4;
	}
	return 0x0;
}
