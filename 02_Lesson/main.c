/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {

	int ival;
	printf("Enter an integer number : ");
	scanf("%d", &ival);

	printf("|%d|--> %d\n", ival, abs(ival));

	double dval;
	printf("Enter a double number : ");
	scanf("%lf", &dval);

	printf("|%f|--> %f\n", dval, fabs(dval));

	/*
		Enter an integer number : -89
		|-89|--> 89
		Enter a double number : -3.2
		|-3.200000|--> 3.200000
	*/
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double dval1 = 1.3e5;    
	double dval2 = 1.3e-5;
	
	printf("dval1 : %f\n", dval1);
	printf("dval2 : %f\n", dval2);

	/*
		dval1 : 130000.000000
		dval2 : 0.000013
	*/
}