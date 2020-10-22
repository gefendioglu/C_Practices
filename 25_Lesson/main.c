#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

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

int get_array_max(const int* ptr, int size)
{
	int max = *ptr; // p[0]
	for (int i = 1; i < size; ++i)
	{
		if (ptr[i] > max)
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

void get_array_min_max(const int* ptr, int size, int* pmax, int* pmin)
{
	*pmax = *pmin = *ptr;

	for (int i = 1; i < size; ++i)
	{
		if (ptr[i] > * pmax)
			*pmax = ptr[i];
		else if (ptr[i] < *pmin)
			*pmin = ptr[i];
	}
}

int sum_array(const int* ptr, int size) {
	int sum = 0;
	while (size--) {
		sum += *ptr;
		++ptr;
	}
	return sum;
}

double get_mean(const int* ptr, int size) {
	return (double)sum_array(ptr, size) / size;
}

double get_std_dev(const int* ptr, int size) {
	double sum_square = 0.0;
	double mean = get_mean(ptr, size);
	for (int i = 0; i < size; ++i)
	{
		sum_square += (ptr[i] - mean) * (ptr[i] - mean);
	}
	return sqrt(sum_square / size);
}

void reverse_array(int* ptr, int size) {
	for (int i = 0; i < size / 2; ++i)
	{
		// swap(&ptr[i], &ptr[SIZE - 1 - i]);
		// swap(ptr + i, ptr + size - 1 - i);

		int temp = ptr[i];
		ptr[i] = ptr[SIZE - 1 - i];
		ptr[SIZE - 1 - i] = temp;
	}
}

void copy_array(int* pdest, const int* psource, int size) {

	while (size--) {
		*pdest++ = *psource++;
	}
}

void sort_array(int* ptr, int size) {
	for (int i = 0; i < size - 1; ++i)
	{
		for (int k = 0; k < size - 1 - i; ++k)
		{
			if (ptr[k] > ptr[k + 1])
			{
				//swap(ptr + k, ptr + k + 1);
				int temp = ptr[k];
				ptr[k] = ptr[k + 1];
				ptr[k + 1] = temp;
			}
		}
	}
}

// Dutch Flag Algorithm 
// istenilen aralýkta [low,high] diziyi doldurur
void set_random_array_2(int* ptr, int size, int low, int high)
{
	while (size--) {
		*ptr = rand() % (high - low + 1) + low;
		++ptr;
	}
}

void reverse_copy(int* pdest, const int* psource, int size) {

	pdest += size; // dizinin bittiði yerin adresine gidilir. 

	while (size--) {
		*--pdest = *psource++;
	}
}

void strange(int* ptr, int size) {
	while (size--) {
		++* ptr++;
		// öncelik *ptr --> *ptr ++ --> ++ *ptr ++ 
	}
}

void print_array_2(const int* pbeg, const int* pend) {
	while (pbeg != pend) {
		printf("%d ", *pbeg++);
	}
}

void reverse_array_2(int* ptr, int size) {
	int* pe = ptr + size; // pe dizinin bittiði yerin adresini tutar.
	while (ptr < pe) {
		//swap(ptr++, --pe);
	}
}

typedef int Tarray[10];
typedef int (*Fcmp) (const char*, const char*);

typedef double Kilogram;
Kilogram k1, k2, k3;

typedef int CounterType;
CounterType cnt = 0;

int g1 = 10;
int g2 = 20;
int* foo1(void) {

	//...
	return &g1;
}

int* foo2(void) {

	//...
	return &g2;
}

void func(int* ptr) {
	*ptr = 999;
}

// There is a logic error because of x local variable
// x is only defined in this function scope
// return value points a dangling pointer 
int* get_value(void) {
	int x;
	printf("Enter a number : ");
	scanf("%d", &x);

	return &x;
}


int* func(int value) {

	int* ptr = &value;
	int* p = ptr;
	//...

	return p;
}
int main() {

	int* ptr;
	ptr = get_value(); // ptr is a dangling pointer, ub

	printf("the value = %d\n", *ptr); 

	/*
	Enter a number : 3465
	the value = 3465
	*/
}
