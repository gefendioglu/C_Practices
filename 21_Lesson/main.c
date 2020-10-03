#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#pragma warning(disable:4244)

#define INWORD  1
#define OUTWORD 0

char* sgets(char* ptr) {
	char c;
	char* ptemp = ptr;
	while ((c = (char)getchar()) != '\n')
		*ptr++ = c;

	*ptr = '\0';
	return ptemp;
}

int is_separator(int c) {
	return isspace(c) || c == '.' || c == ',' || c == '!' || c == ';';
}

#define SIZE 100

int main() {

	int size = 10;
	if(SIZE){}
}










