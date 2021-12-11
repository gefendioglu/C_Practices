
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//call by value
void func_val(int a)
{
	a = 1000; 
}

//call by reference
void func_ref(int *a)
{
	*a = 1000;
}

int main()
{
	int x = RAND_MAX; // standard macro
	struct tm tx;     // standard type 
	time_t timer;     // standard type alias
	time(&timer);     // standard function

	return 0;
}

/*
int main()
{
	FILE *f;
	//code...

	f = fopen("database.dat", "rb");
	if (f == NULL)
	{
		fprintf(stderr, "file is not opened!!!/n");
		return 1;
	}
	//code...
	return 0; // code readibility
}
*/


