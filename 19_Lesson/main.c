#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x = 10, y = 20, z = 30, t = 40;
	int array[] = {x, y, z+t, t-x}; 
	// Normally it should be an error
	// However some compiler extensions provide this spec. (Ex. gcc)
	
	int length = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < length; ++i)
		printf("arrays[%d] : %d\n", i, array[i]);

	/*  arrays[0] : 10
		arrays[1] : 20
		arrays[2] : 70
		arrays[3] : 30 */
}












