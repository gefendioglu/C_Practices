## MACRO 
 - It can be used for avoiding the cost of function calls
 - The compiler only writes the specified code with macros where there is a function call.
 - There is no return value definition for macros. 

/----------------------------------------------
/----------------------------------------------

```c
#define _USE_MATH_DEFINES
#include <math.h>
#include <limits.h>
#include <stdio.h>


#ifdef _USE_MATH_DEFINES // define edildiği için by bloğa girilir. 
#define SIZE 100
#define MAX 500
#endif // _USE_MATH_DEFINES


int main() {

	int sqrtNumberWithMacro = M_SQRT2;
	printf("sqrtNumberWithMacro : %d\n", sqrtNumberWithMacro);

	int sqrtNumberWithFunction = sqrt(2);
	printf("sqrtNumberWithFunction : %d\n", sqrtNumberWithFunction);

	int number = INT_MAX;
	printf("number : %d\n", number);

	return 0;
}
```

/----------------------------------------------
/----------------------------------------------

### Functional Macro:
 - It is expected to work faster since there will be no entry and exit code from the function.
 - It should be preferred for functions whose code is small and frequently called.
 - It is also preferred because of its ease of writing.
 - It is common to use functional macros when using bit elements.
 - It has a security vulnerability; but its use can not be abandoned.

```c
#define max(a,b) ((a) > (b) ? (a):(b))
#include <stdio.h>

int main() {

	int x = 34, y = 67;
	int ival = max(x, y);
	printf("ival : %d\n", ival);

	return 0;
}
```

/----------------------------------------------
/----------------------------------------------
