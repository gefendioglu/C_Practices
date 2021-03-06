#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>
#include <Windows.h>

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
// istenilen aral�kta [low,high] diziyi doldurur
void set_random_array_2(int* ptr, int size, int low, int high)
{
	while (size--) {
		*ptr = rand() % (high - low + 1) + low;
		++ptr;
	}
}

void reverse_copy(int* pdest, const int* psource, int size) {

	pdest += size; // dizinin bitti�i yerin adresine gidilir. 

	while (size--) {
		*--pdest = *psource++;
	}
}

void strange(int* ptr, int size) {
	while (size--) {
		++* ptr++;
		// �ncelik *ptr --> *ptr ++ --> ++ *ptr ++ 
	}
}

void print_array_2(const int* pbeg, const int* pend) {
	while (pbeg != pend) {
		printf("%d ", *pbeg++);
	}
}

void reverse_array_2(int* ptr, int size) {
	int* pe = ptr + size; // pe dizinin bitti�i yerin adresini tutar.
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


int my_stricmp(const char* ptr_left, const char* ptr_right) {

	while (toupper(*ptr_left) == toupper(*ptr_right)) {

		if (*ptr_left == '\0')
			return 0;
		++ptr_left;
		++ptr_right;
	}
	return toupper(*ptr_left) - toupper(*ptr_right);
}

int my_strcmp(const char* ptr_left, const char* ptr_right) {

	while (*ptr_left == *ptr_right) {

		if (*ptr_left == '\0')
			return 0;
		++ptr_left;
		++ptr_right;
	}
	// no need to use int casting, because intergral promotion 
	return (int)*ptr_left - (int)*ptr_right;
}

char* set_locale(int category, const char* ptr_locale) {

}

// First sentence: polathan - Second sentence : han 
int is_at_end(const char *ptr1, const char *ptr2){
	size_t length_ptr1 = strlen(ptr1);
	size_t length_ptr2 = strlen(ptr2);
	if (length_ptr2 > length_ptr1)
		return 0;
	// ptr1 + length_ptr1 - length_ptr2 --> the address of 'h'
	return !strcmp(ptr1 + length_ptr1 - length_ptr2, ptr2); 
}

// Adding at the beginning ptr2 --> ptr1
char* str_prepend(char* ptr1, const char* ptr2) {

}

char* my_strpbrk(const char* ptr1, const char* ptr2) {
	while (*ptr1) { // *ptr1 != '\0' 
		if (strchr(ptr2, *ptr1) != NULL)
			return (char*)ptr1;
		++ptr1;
	}

	return NULL;
}

int to_hex_char(int value) {
	return "0123456789ABCDEF"[value];
}

char* get_str(int n) {
	switch (n)
	{
	case 0: return "zero";
	case 1: return "one";
	case 2: return "two";
	case 3: return "three";
	case 4: return "four";
	case 5: return "five";
	case 6: return "six";
	case 7: return "seven";
	case 8: return "eigth";
	case 9: return "nine";
	}
	return "";
}

int main() {

	// unspecified behaviour
	char* ptr1 = "gamze";
	char* ptr2 = "gamze";

	if (ptr1 == ptr2) // It depends on compiler
		printf("True");
	else
		printf("False");
}
