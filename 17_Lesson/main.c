#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// The size of signed data types 
	printf("sizeof(long double) : %ld\n", sizeof(long double));
	printf("sizeof(double)      : %lu\n", sizeof(double));
	printf("sizeof(float)       : %lu\n", sizeof(float));
	printf("sizeof(long long)   : %lu\n", sizeof(long long));
	printf("sizeof(long)        : %lu\n", sizeof(long));
	printf("sizeof(int)         : %lu\n", sizeof(int));
	printf("sizeof(short)       : %lu\n", sizeof(short));
	printf("sizeof(_Bool)       : %lu\n\n", sizeof(_Bool));

	// The size of unsigned data types 
	printf("sizeof(unsigned long long) : %lu\n", sizeof(unsigned long long));
	printf("sizeof(unsigned long)      : %lu\n", sizeof(unsigned long));
	printf("sizeof(unsigned int)       : %lu\n", sizeof(unsigned int));
	printf("sizeof(unsigned short)     : %lu\n", sizeof(unsigned short));

/*
	sizeof(long double) : 8
	sizeof(double)      : 8
	sizeof(float)       : 4
	sizeof(long long)   : 8
	sizeof(long)        : 4
	sizeof(int)         : 4
	sizeof(short)       : 2
	sizeof(_Bool)       : 1
*/

/*
	sizeof(unsigned long long) : 8
	sizeof(unsigned long)      : 4
	sizeof(unsigned int)       : 4
	sizeof(unsigned short)     : 2
*/

}