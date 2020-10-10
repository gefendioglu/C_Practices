#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10 

void randomize(void) 
{
	srand((unsigned int)time(NULL));
}

void print_array(const int* ptr, int size)
{
	while (size--) {
		printf("%d ", *ptr);
		++ptr;
	}
	printf("\n");
}

void set_random_array(int* ptr, int size) 
{
	while (size--) {
		*ptr = rand() % 1000;
		++ptr;
	}
}

int get_array_max(const int *ptr, int size) 
{
	int max = *ptr; // p[0]
	for (int i = 1; i < size; ++i)
	{
		if (ptr[i]>max)
		{
			max = ptr[i];
		}
	}
	return max;

}

int get_array_min(const int* ptr, int size)
{
	int min = *ptr; // p[0]
	for (int i = 1; i < size; ++i)
	{
		if (ptr[i] < min)
		{
			min = ptr[i];
		}
	}
	return min;

}

void get_array_min_max(const int* ptr, int size, int *pmax, int *pmin)
{
	*pmax = *pmin = *ptr;

	for (int i = 1; i < size; ++i)
	{
		if (ptr[i] > *pmax)
			*pmax = ptr[i];
		else if (ptr[i] < *pmin)
			*pmin = ptr[i];
	}
}

int main() {

	int iarray[SIZE]; 
	int n;
	int max_value;
	int min_value;
	randomize();
	set_random_array(iarray, SIZE);
	print_array(iarray, SIZE);
	max_value = get_array_max(iarray, SIZE);
	min_value = get_array_min(iarray, SIZE);

	printf("max_value = %d\n", max_value);
	printf("min_value = %d\n", min_value);
	printf("\n");

	get_array_min_max(iarray, SIZE, &max_value, &min_value);
	printf("max_value = %d\n", max_value);
	printf("min_value = %d\n", min_value);

	/*
		385 429 123 495 546 618 624 406 727 172
		max_value = 727
		min_value = 123

		max_value = 727
		min_value = 123
	*/

}
