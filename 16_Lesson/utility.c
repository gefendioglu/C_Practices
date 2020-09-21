#include"utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int isprime(int x){
	return 0;
}
int ndigit(int y){
	return 0;
}

void dline(void) {
	printf("\n-----------------------------------------------------\n");
}

void sleep(double sec) {

	clock_t start = clock();

	while ((double)(clock() - start) / CLOCKS_PER_SEC < sec)
		; // null statement
}

// The Tomohiko Sakamoto Algorithm 
// https://www.geeksforgeeks.org/tomohiko-sakamotos-algorithm-finding-day-week/

int day_of_week(int day, int month, int year)
{
	// array with leading number of days values 
	// look-up table --> const int[]
	static const int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

	// if month is less than 3 reduce year by 1 
	if (month < 3)
		year -= 1;

	return ((year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7);
}

void randomize(void) {
	srand((unsigned int)time(NULL));
}


