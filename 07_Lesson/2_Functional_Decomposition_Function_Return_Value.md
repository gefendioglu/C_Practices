## Functional Decomposition

- Function Declaration
- Function Definition
- Function Call Expression

### The details about "Function Definition":

- The concept of function definition is used in the same sense as the concept of function implementation.

- The concepts of "Integration" and "Implementation" are theoretically different from each other.

- While implementation is writing the code of a function that did not exist before, integration can be interpreted as, for example, adding a function from a third party library to an existing software so that it works together correctly.

- Although function parameters are called "formal parameters" in theory, it is more common to use them only as "parameters".

- Functions without parameters should be expressed with the void keyword in parentheses. By the way, "void function" is the function with no return value.
  - void clear_screen(void);

- "implicit int" rule: In accordance with the backward compatibility rule, C functions that do not have type information are accepted as "int" type by default. If this rule is not valid, it means backward compatibility is not applied, a "missing type specifier" error is received.

### The details about "Function Call Expression": 

- In C and C ++ languages, function calls are in an operator level and performed using function-call-operator (). 

- Expressions whose values are sent to function parameters through the function call are named as "argument" or "actual parameters".

```c
int maxValue(int a, int b, int c); // a,b,c --> function parameters

int main() {
	maxValue(10, 20, 30); // 10,20,30 --> arguments 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Old style function calling (before standards)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// The old function definition style for int types 
sum(a, b, c) {
	return a + b + c;
}

int main() {

	int ival = sum(10, 12, 13);
	double dval = sum(10.2, 12.5, 13.8);

	printf("ival = %d\n", ival);
	printf("dval = %f\n", dval);

	return 0;
	/*
		ival = 35
		dval = -1500853044.000000
	*/
}
```

/----------------------------------------------
/----------------------------------------------

-**Example**: Old style function calling (before standards)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// The old function definition style for int types 
sum(a, b, c) {
	return a + b + c;
}

// The old function definition style for different types
double dsum(a, b, c)
double a, b, c; {
	return a + b + c;
}

int main() {

	int ival = sum(10, 12, 13);
	double dval = dsum(10.2, 12.5, 13.8);

	printf("ival = %d\n", ival);
	printf("dval = %f\n", dval);

	return 0;
	/*
		ival = 35
		dval = 36.500000
	*/
}
```

/----------------------------------------------
/----------------------------------------------

### Function Return Value:

- Returning a value for a function can be provided with:
  - a return value
  - call by reference (with pointer semantic): It is provided by writing the function output to the object address.
 
- With return value, the function code is terminated and the code that calls this function is returned.

- Which type of statements that C language has?
  - expression statement 
    x=5 --> expression, x=5; --> expression statement
  - null statement (;)
  - compound statement
    it is like blocked statements: 
    ```cpp
	  { 
	    statement1;
	    statement2;
	  }
    ```
  - control statement
    - if, for, while, do-while, switch, goto, break, continue, etc.

- Return statement is a kind of control statement
  
- Return statement without expression --> return;
  - this type of return value is used with void functions to terminate the function
  - not applicable for the other type of functions

- Return statement with expression --> return expr;
- "one liner function": this function has only a return statement

- int main()  --> In C, the return value doesn't have to be "int"
  void main(void); --;> this definition is also used !

- For functions that have an int return value type: 
  - return 0; --> successful function termination
  - return 1; --> unsuccessful function termination

- int func(void){...}
  - warning for C
  - syntax error for C++ (must return a value error)

- Functions without a return value:
   - they do not pass a value to the calling code.
   - they pass value to the calling code by another method. In this case, they send the value indirectly by writing data to the object address received by call-by-reference. 

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of return value without expression in void function

```c
void func(int value) {
	// code
	if (cond.) {
		return; // return statement without expression is used to terminate the function code here. 
	}
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of a return value with expression in a normal function which its return value is int type

```c
int func() {
	double dval;
	return dval; // not a syntax error
	// It could be a "warning" depending on compiler
	// Cause it is a narrowing conversion from double (8 bytes) --> to int (4 bytes)
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Return statement can be R-Value or L-Value

```c
int func() {
	int x = 45;
	if (x > 10) {
		return x;     // --> L-Value
		return x + 5; // --> R-Value
	}
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The function that finds the maximum value of two numbers

```c
int max_value(int number1, int number2) {
	if (number1 > number2)
		return number1;
	else
		return number2;
	// or this line can be written directly 
	// return number2; (without specifying "else")
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The function that finds the maximum value of two numbers with ternary operator (one liner function)

```cpp
int max_value(int number1, int number2) {
	return (number1 > number2 ? number1 : number2);
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The function that finds the maximum value of three numbers

```c
int max_value(int number1, int number2, int number3) {
	int max = number1;
	if (number2 > max)
		return number2;
	if (number3 > max)
		return number3;
	return max;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Finding digit count for a given number
  - The use of postfix - prefix is not important for "digit_count" here, since the variable "digit_count" is not used elsewhere.

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ndigit(int value) {
	int digit_count = 0;
	if (value == 0)
		return 1;
	while (value != 0) {
		++digit_count; // 
		value /= 10;
	}
	return digit_count;
}

int main() {

	int value;
	printf("Enter a value: ");
	scanf("%d", &value);

	printf("The digit value of %d : %d", value, ndigit(value));

	/*
		Enter a value: 15400
		The digit value of 15400 : 5
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Prefix - Postfix Example

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int a = 20;
	printf("a: %d\n", a);

	int b = a++;
	printf("b: %d\n", b);

	int c = ++a;
	printf("c: %d\n", c);
	
	/*
		a: 20
		b: 20
		c: 22
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Designing a function that prints the square root of numbers in between low and high values 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {

	int low, high;
	printf("Enter two values: ");
	scanf("%d%d", &low, &high);

	for (int i = low; i < high; ++i)
		printf("%5d --> %f\n", i, sqrt(i));
	/*
		Enter two values: 15 25
		15 --> 3.872983
		16 --> 4.000000
		17 --> 4.123106
		18 --> 4.242641
		19 --> 4.358899
		20 --> 4.472136
		21 --> 4.582576
		22 --> 4.690416
		23 --> 4.795832
		24 --> 4.898979
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** :  Designing a function that prints the pow of numbers in between low and high values 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {

	double base, power;
	printf("Enter two values: ");
	scanf("%lf%lf", &base, &power);

	printf("%f --> %f = %f\n", base, power, pow(base, power));

	/*
		Enter two values: 5 12
		5.000000 --> 12.000000 = 244140625.000000
	
		Enter two values: 6 13
		6.000000 --> 13.000000 = 13060694016.000000
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- Usually "int" type is used for logic data type in C. This type of function starts with "is".
  - bool isPrime(int); --> C++, C# (returns true or false)
  - int isPrime(int);  --> C (returns non-zero (true) or zero (false) value)
  - int isUpper(int); --> C
  - int is_valid_card_no(int); --> C

/----------------------------------------------
/----------------------------------------------

## General C Features:

- It is not possible to use nested function (local function definition) in C and C ++ languages.
- In C, all functions must be defined in the global namespace and outside of each other.

```c
int main(){
  int func(){...} // syntax error
}
```

- The order of calling functions in C is important for name lookup rules.

```c
void func1();
void func2() {
	func1(); // not syntax error
	func3(); // syntax error (name lookup)
}
void func3();
```
