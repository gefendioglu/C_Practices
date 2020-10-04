
## COMPILER ERRORS 

- The most important compiler warnings and errors are defined hereafter:  

/----------------------------------------------
/----------------------------------------------

**Example**:
  - C4189 : local variable is initialized but not referenced 
    - This error is received when a local variable is defined but not used for the remaining part of the code. 


  - C4700 : uninitialized local variable 'x' used
    - This error is received when non-static local variables are not initialized. 
    - This error is not received for global variables and static local variables. They are automatically initialized with zero value. 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int x;
	int y = x; 
	// Error C4700 : uninitialized local variable 'x' used	
}
```
/----------------------------------------------
/----------------------------------------------

**Example**: C4716 : must return a value 
  
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int func(int x, int y) {
	if (x > y)
		x -= y;
	++y;
	++x;
}
```
/----------------------------------------------
/----------------------------------------------

**Example**: C4715 : not all control paths return a value

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int foo(int a, int b) {
	if (a > b)
		return a - 1;
	//...code
	if (b > a)
		return 1;
	//...code
	// return ?
}
```

/----------------------------------------------
/----------------------------------------------

**Example**: C4552 : '+' : result of expression not used

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x = 10;
	++x;
	//...code
	x + 5; // "+" is written accidentally instead of "+=" 
}
```

/----------------------------------------------
/----------------------------------------------

**Example**: C4706 :  assignment within conditinal expression 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int x = 10;
	if (x = 5)
		printf("gamze");
}
```

/----------------------------------------------
/----------------------------------------------

**Example**: C4702 : unreachable code (because of using return statement or exit function)

- Because of using return statement:
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int func(int x) {

	if (x > 10)
		return x;
	//...code
	return x + 10; // the remaining code is not run !!!
	//...code
	return x; 
}
```

- Because of using exit function:
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void func(int x) {
	++x;
	x += 5;
	//...code
	exit(EXIT_FAILURE); // the remaining code is not run !!!
	//...code
	return x; 
}
```

/----------------------------------------------
/----------------------------------------------

**Example**: 
  - C4244: '=': conversion from 'double' to 'int', possible loss of data 
  - Narrowing conversion warnings
  - Warning or error messages can be disabled at the begining of the programme using pragma directives --> #pragma warning(disable:4244) 
  - However, some fundamental compiler error/warning messages shall not be disabled !!!

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	double dval = 234.7878;
	int ival = 0;
	ival = dval; // double --> int (narrowing conversion)
}
```
/----------------------------------------------
/----------------------------------------------

**Example**: C4305: 'function': truncation from 'double' to 'float'	

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(float);

int main() {
	func(13.78458); // double --> float (narrowing conversion)
}
```

/----------------------------------------------
/----------------------------------------------
 
**Example**: C4477 'scanf' : format string '%d' requires an argument of type 'int *', but variadic argument 1 has type 'int'

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int value; 
	scanf("%d", value); // this function requires the address of x value
}
```

/----------------------------------------------
/----------------------------------------------
 
 **Example**: 
   - C4013: 'func' undefined; assuming extern returning int 
   - Calling for an undeclared function 
   - Before C99 standard, this situation is acceptable. Because even if the function is not declared, it is assumed that the declaration is made automatically like: extern int func();
    
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	func();
}
```

/----------------------------------------------
/----------------------------------------------

**Example**: 
  - C4127: conditional expression is constant
  - C4189: 'size': local variable is initialized but not referenced

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 100

int main() {
	int size = 10;
	if(SIZE){} // the usage of SIZE (instead of size) erroneously !!!
}
```
/----------------------------------------------
/----------------------------------------------

