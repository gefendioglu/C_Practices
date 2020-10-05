#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 100

void dline(void) {
	printf("\n-----------------------------------------------------\n");
}

void randomize(void) {
	srand((unsigned int)time(NULL));
}

void set_random_array(int *ptr, int size)
{
	while (size--) {
		*ptr++ = rand() % 1000;
	}
}

void print_array(const int *ptr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (i && i % 20 == 0)
			printf("\n");
		printf("%3d ", ptr[i]);

	}
	dline();
}

int main() {

	int a[SIZE];
	int value;
	int i; 

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	printf("Enter a number : ");
	scanf("%d", &value);


	for (i = 0; i < SIZE; ++i) {
		if (a[i] == value) 
			break;
	}
		
	if (i == SIZE)
		printf("NOT FOUND !!!\n");
	else 
		printf("FOUND !!! The array index : %d\n", i);
}
