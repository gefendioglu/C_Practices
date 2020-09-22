#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 

typedef enum 
{
	COLOR_BLACK,
	COLOR_WHITE, 
	COLOR_PURPLE,
	COLOR_YELLOW,
	COLOR_GREEN
}Colors;

void print_color(Colors color) {

	switch (color)
	{
	case COLOR_BLACK  : printf("Black\n"); break;
	case COLOR_WHITE  : printf("White\n"); break;
	case COLOR_PURPLE : printf("Purple\n"); break;
	case COLOR_YELLOW : printf("Yellow\n"); break;
	case COLOR_GREEN  : printf("Green\n"); break;
	default: printf("Invalid Color Selection\n"); break;
	}
}

int main() {

	Colors color = COLOR_BLACK; 

	while (SIZE != 0) {

		printf("0 : Black   \n");
		printf("1 : White   \n");
		printf("2 : Purple  \n");
		printf("3 : Yellow  \n");
		printf("4 : Green   \n\n");
		printf("What is the selected card ? (0/1/2/3/4): ");

		scanf("%d", &color);
		print_color(color);
		putchar('\n');
	}
	
}