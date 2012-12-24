/*
 ============================================================================
 Name        : StdInputOutput.c
 Author      : Lukas Ender
 Version     :
 Copyright   : 
 Description : This little program should count all characters, words and lines.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define IN 1		/* within a word */
#define OUT 0		/* not within a word */

int main(void) {

	int c, nw, nl, state;
	double nc;

	nw = nl = nc = 0;
	state = OUT;

	while((c = getchar()) != EOF) {
		nc++;
		if (c == '\n') {
			nl++;	// found another line
		}
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
		} else if (state == OUT) {
			state = IN;
			nw++;
		}
	}

	printf("characters:\t%.0f\n", nc);
	printf("words:\t%d\n", nw);
	printf("lines:\t%d\n", nl);

	return EXIT_SUCCESS;
}
