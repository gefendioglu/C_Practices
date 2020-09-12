#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define sum_square(x,y) ((x*x)+(y*y))

int (sum_square)(int a, int b) {
	
	printf("FONKSIYON !!!!\n");
	return a * a + b * b;
}

int main() {
	int firstNumber = 10;
	int secondNumber = 20;

	// macro sum_square(x,y) will be used here
	int ival = (sum_square)(firstNumber, secondNumber);
	printf("ival = %d\n", ival);
} 