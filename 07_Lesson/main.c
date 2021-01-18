#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void clear_input_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}

int main() {

	int x;
	int retval;

	printf("Enter an integer: ");
	retval = scanf("%d", &x);

	/*



	*/
}


