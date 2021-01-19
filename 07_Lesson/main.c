#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int f1() {
	printf("f1() is called\n");
	return 3;
}

int f2() {
	printf("f2() is called\n");
	return 5;
}

int main() {

	int x;
	x = f1() + 5 * f2(); 
	
	printf("x : %d\n", x);

	return 0;
	/*
		f1() is called
		f2() is called
		x : 28
	*/
}
	


