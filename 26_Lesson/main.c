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


//int get_array_max(const int* ptr, int size)
//{
//	int max = *ptr; // p[0]
//	for (int i = 1; i < size; ++i)
//	{
//		if (ptr[i] > max)
//		{
//			max = ptr[i];
//		}
//	}
//	return max;
//
//}
//
//int get_array_min(const int* ptr, int size)
//{
//	int min = *ptr; // p[0]
//	for (int i = 1; i < size; ++i)
//	{
//		if (ptr[i] < min)
//		{
//			min = ptr[i];
//		}
//	}
//	return min;
//
//}

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

// There is a logic error because of x local variable
// x is only defined in this function scope
// return value points a dangling pointer 
int* get_value(void) {
	int x;
	static* ptr;
	printf("Enter a number : ");
	scanf("%d", &x);

	ptr = &x;
	return ptr; // undefined behaviour  
}

char* get_name(void) {

	static char buffer[100];
	printf("enter a name: ");
	scanf("%s", buffer);

	return buffer;
}

char* get_day_name(int daynumber) {

	switch (daynumber)
	{
	case 1: return "Monday";
	case 2: return "Tuesday";
	case 3: return "Wednesday";
	case 4: return "Thursday";
	case 5: return "Friday";
	case 6: return "Saturday";
	case 7: return "Sunday";
	}
	return "";
}

char* str_rev(char* ptr) {

	size_t length = strlen(ptr);
	for (size_t i = 0; i < length / 2; ++i)
	{
		char temp = ptr[i];
		ptr[i] = ptr[length - 1 - i];
		ptr[length - 1 - i] = temp;
	}
	return ptr;
}

// const-cast (const int* --> int* manually conversion for return value)
// returns the address of max value in an array
int* get_array_max(const int* ptr, size_t size) {
	const int* ptr_max = ptr;
	for (size_t i = 0; i < size; ++i)
	{
		if (ptr[i] > * ptr_max)
			ptr_max = ptr + i; // the address of bigger value 
	}

	return (int*)ptr_max; // not return a local value 
}

// returns the address of min value in an array
int* get_array_min(const int* ptr, size_t size) {
	const int* ptr_min = ptr;
	for (size_t i = 0; i < size; ++i)
	{
		if (ptr[i] < *ptr_min)
			ptr_min = ptr + i; // the address of bigger value 
	}

	return (int*)ptr_min; // not return a local value 
}

// Complexity : O(n^2)
// Besides for loop, get_array_max function has another internal loop
//void selection_sort_min(int* ptr, size_t size) {
//
//	for (size_t i = 0; i < size-1; ++i)
//		swap(get_array_min(ptr + i, size - i), ptr + i);
//}

//void selection_sort_max(int* ptr, size_t size) {
//
//	for (size_t i = 0; i < size - 1; ++i)
//		swap(get_array_max(ptr + i, size - i), ptr + i);
//}

typedef int* IPTR;

int main() {

	int x = 10;
	int* ptr = &x;


	if (ptr != NULL) // --> if(ptr)
		printf("Equal\n");
	else
		printf("Not equal\n");

}
