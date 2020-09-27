#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x = 1, y = 1;
	char str[100];
	str[0] = 'O';
	str[1] = 'K';
	str[2] = '\0';

	for (int i = 0; str[i]!='\0'; ++i)
		printf("%c ", str[i]);

	str[x + y] = 'T';
	// undefined behaviour -- null karakterin ezilmesi
	for (int i = 0; str[i] != '\0'; ++i)
		printf("%c ", str[i]);
}




