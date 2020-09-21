#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>


int main() {
	
	srand((unsigned)time(NULL));

	for (int i = 0; i < 20; ++i)
	{
		switch (rand() % 7 + 1){
		case 1: printf("Monday "); break;
		case 2: printf("Tuesday "); break;
		case 3: printf("Wednesday "); break;
		case 4: printf("Thursday "); break;
		case 5: printf("Friday "); break;
		case 6: printf("Saturday "); break;
		case 7: printf("Sunday "); break;
		}
		
		_getch();
	}
	
}