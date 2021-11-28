
#define LIFESPAN

/* LifeSpan*/
#if defined(LIFESPAN)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n_digit(int val) 
{
	int digit_cnt = 0;
	if (val == 0)
		return 1;

	while (val!=0)
	{
		++digit_cnt;
		val /= 10;
	}

	return digit_cnt;
}

int main()
{
	int digit = 0;
	printf("enter a digit number = ");
	scanf("%d", &digit);
	printf("digit number = %d", n_digit(digit));
}
#endif

