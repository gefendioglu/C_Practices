
#define max(a,b) ((a) > (b) ? (a):(b))
#define min(a,b) (!max(a,b))
#include <stdio.h>

int main() {

	int x = 34, y = 67;
	int ival = max(x, y);
	int ivalmin = min(x, y);
	printf("ival : %d\n", ival);
	printf("ivalmin : %d\n", ivalmin);

	return 0;
}