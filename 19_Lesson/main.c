#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 10

void dline(void) {
	printf("\n-----------------------------------------------------\n");
}

void randomize(void) {
	srand((unsigned int)time(NULL));
}

void set_random_array(int* ptr, int size)
{
	while (size--) {
		*ptr++ = rand() % 1000;
	}
}

void print_array(const int* ptr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (i && i % 20 == 0)
			printf("\n");
		printf("%3d ", ptr[i]);

	}
	dline();
}

int func(void) {
	printf("func() is called!!\n");
	return 1;
}

#define array_size(x)  (sizeof(x)) / (sizeof((x)[0]))

int main() {

	int array[] = { 1,2,3,4,5 };

	for (int i = 0; i < array_size(array); ++i)
		printf("%d ", i[array]);
	    // 1 2 3 4 5
}
