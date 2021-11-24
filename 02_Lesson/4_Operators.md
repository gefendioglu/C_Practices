## Operators

- There are 45 operators in C language. 
- sizeof keyword is also an operator 

- What kind of operators are there with respect to their operands? 
  - unary operators take one operand --> !x, ++y, ~z, m-- 
  - binary operators take two operands --> a<b, x*y, m%z
  - ternary operators take three operators --> ? :
    - there is only one ternary operator --> exp1 ? exp2 : exp3

- The operator (or operands) of an operator must be expression.
  - x + return y; // NOT OK ! --> return y; is a statement
  - x + y; // OK!

- What kind of operators are there with respect to their place? 
  - Prefix operators --> ++x, !x, ~x, &x (unary prefix)
  - Postfix operators --> x++ (unary postfix)
  - Infix operators --> a + b (binary infix)

- expression --> a + b (without ;)
- expression statement --> a + b;

- side effect : some operators can change the values of their operands --> ++x
  - Which operators have side effects?
    - ++, --, assignment operators (+=, -=, etc.)
 
- The priority (precedence) of operators:
  - 4 operators have both unary and binary features and can undertake different tasks: 
    - + operator --> +x, a+b
    - - operator --> -x, a-b 
    - & operator --> &x, a&b
    - * operator --> *ptr, x*y

- operator precedence does not specify the physical precedence of an operation. It is a definition that determines the operands of the operator.

- operator precedence table:
----------------------------------------------
1 () [] . ->
----------------------------------------------
2 ++ -- ! ~ & * sizeof (type conversion) + - (sign operators)
----------------------------------------------
3 * / %
----------------------------------------------
4 + -
----------------------------------------------
5 << >>
----------------------------------------------
6 < <= > >=
----------------------------------------------
7 == !=
----------------------------------------------
8 &
----------------------------------------------
9 ^
----------------------------------------------
10 | 
----------------------------------------------
11 &&
----------------------------------------------
12 ||
----------------------------------------------
13 ? : (ternary)
----------------------------------------------
14 = += -= /= %= <<= >>= &= ^= |=
----------------------------------------------
15 , (comma)
----------------------------------------------



/----------------------------------------------
/----------------------------------------------

- **Example** : Interview question for the precedence of operators

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int f1() {
	printf("f1() is called\n");
	return 3;
}

int f2() {
	printf("f2() is called\n");
	return 5;
}

int main() {

	int x;
	x = f1() + 5 * f2(); // unspecified behaviour
	// which function is called firstly? 
	// it might be f1() or f2() depending on compilers
	
	// operator precedence provides that the output is always 28 
	printf("x : %d\n", x);

	return 0;
	/*
		f1() is called
		f2() is called
		x : 28
	*/
}
```
