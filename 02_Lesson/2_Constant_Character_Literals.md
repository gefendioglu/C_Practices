## Constant Literals

- constant literals is accepted as token in C
- "constant literals" and "constant expressions" are different concepts. 
- constant literals can have different data types like as the following (but not short and char types): 
  - 5          --> int type
  - 5u, 5U     --> unsigned type 
  - 5L, 5l     --> long type 
  - 5LL, 5ll   --> long long type 
  - 5ULL, 5ull --> unsigned long long type (5llu, 5LLU, 5uLL)
  - 5.         --> double type 
  - 5.F, 5.f   --> float type 
  - 5.L        --> long double type 

- constant literals can be written in different number systems such as decimal, hexadecimal, octal, etc. 
  - 0X1ABC, 0x1abc --> hexadecimal number systems
  - 0123 --> octal number systems 

- Question: If the value of a constant is greater than the boundary value of the int type in the system, then what is the type of the constant?
  - 0x3444u  --> unsigned int  (in hexadecimal system) 
  - 0x345L   --> signed long   (in hexadecimal system) 
  - 0x345UL  --> unsigned long (in hexadecimal system) 
  - 0x345LU  --> unsigned long (in hexadecimal system) 
  - 0x345Lu  --> unsigned long (in hexadecimal system) 
  - 0x345lu  --> unsigned long (in hexadecimal system) 
  - 03123u   --> unsigned int  (in octal systems) 

- constant literals can be divided two groups:
  - integral constants:
    - signed int / unsigned int
    - signed long / unsigned long
    - signed long long / unsigned long long
  - floating constants:
    - float (1.F, 1.f)
    - double (0.76, .76, 1.0, 1.)
    - long double (0.35L, 35.L)

- If integral constants do not use a suffix and the written constant falls within the boundaries of the int type in the system, the constant will be of type int. 

- Floating constants:
  - 1.0  --> 1.
  - 0.76 --> .76
  - 35.L --> long double type

/----------------------------------------------
/----------------------------------------------

- **Example** : Constant Literals and Number Systems

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x_dec   = 123;   // decimal number system
	int x_hexa  = 0x123; // hexadecimal number system
	int x_octal = 0123;  // octal number system
	int x_sum = 123 + 0x123 + 0123; // not syntax error
	// int x_sum = 123 + 291 + 83;   

	printf("x_dec  : %d\n", x_dec);
	printf("x_hexa : %d\n", x_hexa);
	printf("x_octal: %d\n", x_octal);
	printf("x_sum  : %d\n", x_sum);
	
	/*
		x_dec  : 123
		x_hexa : 291
		x_octal: 83
		x_sum  : 497
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Floating constants 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	double dval = 0.1;
	for (int i = 0; i < 10; ++i)
		dval += 0.1;
	
	if (dval == 1)
		printf("dval is equal to 1\n");
	else
		printf("dval is not equal to 1\n");

	printf("dval : %f ", dval);
	/*
		dval is not equal to 1
		dval : 1.100000
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Floating constants with float variables 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	float fval = 1.3;
	if(fval == 1.3)
		printf("fval is equal to 1.3 \n");
	else 
		printf("fval is not equal to 1.3 \n");
	
	printf("fval : %f ", fval);

	/*
		fval is not equal to 1.3
		fval : 1.300000
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Floating constants with float variables (using the correct comparison definition)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	float fval = 1.3f;
	if(fval == 1.3f)
		printf("fval is equal to 1.3 \n");
	else 
		printf("fval is not equal to 1.3 \n");
	
	printf("fval : %f ", fval);

	/*
		fval is equal to 1.3
		fval : 1.300000
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Writing real number constants with exponential (scientific)notation
  - 2.3E-5, 2.3e-5, 2e2, 2E2 --> double types
  - 2.3E, 2.3e

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	double dval1 = 2.3e5;
	double dval2 = 2.3e-5;
	float fval1 = 2.3e5f;
	float fval2 = 2.3e-5f;
	
	printf("dval1 : %f\n", dval1);
	printf("dval2 : %f\n", dval2);
	printf("fval1 : %f\n", fval1);
	printf("fval2 : %f\n", fval2);

	/*
		dval1 : 230000.000000
		dval2 : 0.000023
		fval1 : 230000.000000
		fval2 : 0.000023
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- If the integer constant is written in decimal system and it has not any suffix, when it does not fit the int type, the following types are looked at in order (214748364):
  - long (2147483648)
  - unsigned long
  - long long (21474836488)
  - unsigned long long

- If the integer constant is written in octal or hexadecimal system and it has not any suffix, when it does not fit the int type, the following types are looked at in order:
  - unsigned int (the only difference with respect to the previous) 
  - long 
  - unsigned long 
  - long long 
  - unsigned long long

- If the number doesn't fit into any integer type -> syntax error

- What should be considered when dealing with very large integers?
  - Compiler extensions can be used (especially for gcc compilers)
    - extended integer types can be provided by a compiler extension
	  int128_t ival; // for ex: the size of int128_t types is 16 bytes
  - Big Integer libraries can be used as a third library
  - Instead of using int types, you can define the same int type as double or long double type.  

/----------------------------------------------
/----------------------------------------------

### Character Literals 
- Character literals ('A') --> its type is "int" type in C 
- Character literals ('A') --> its type is "char" type in C++
- 'G' : char literal is a integer constant in C

- In the character encoding used in the system, the int value (coding place) corresponding to this character is used.

- 128 different characters in ASCII character encoding:
   - For example: 'A' --> (int)65 --> 0100 0001
   - 0 - 31 : Control Characters (not printable)
   - 127 : Control Character (not printable)
   - 65 - 90 : Uppercase Letters Code
   - 97 - 122 : Lowercase Letters Code
   - There are 6 characters in between, in order to increase the difference between the uppercase and the lowercase of the same character to 32. Thus, by changing the fifth bit of the binary number, a conversion from uppercase to lowercase is achieved:
     - 0100 0001 : 65 ('A')
	 - 0110 0001 : 97 ('a')

- The nibble (4 bytes) of binary code defined in ASCII encoding system is the same with int numbers

 ASCII    Binary Code   Int Number 
------ | ------------ | ----------- |
  48   |  0011 0000   |      0      |
  49   |  0011 0001   |      1      |
  50   |  0011 0010   |      2      |
  51   |  0011 0011   |      3      |
  52   |  0011 0100   |      4      |
  53   |  0011 0101   |      5      |
  54   |  0011 0110   |      6      |
  55   |  0011 0111   |      7      |
  56   |  0011 1000   |      8      |
  57   |  0011 1001   |      9      |


/----------------------------------------------
/----------------------------------------------

- **Example** :  ASCII Coding for character literals

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	printf("'A' : %d\n", 'A');
	printf("'a' : %d\n", 'a');
	printf("'1' : %d\n", '1');
	/*
		'A' : 65
		'a' : 97
		'1' : 49
	*/
} 
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Printing all ASCII Characters in a text file

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main() {

	FILE* f = fopen("ascii.txt", "w");
	//...
	for (int i = 0; i < 128; ++i)
	{
		if(iscntrl(i))
			fprintf(f, "0x%-3x  %-4d Control Character\n", i, i);
		else 
			fprintf(f, "0x%-3x  %-4d %c\n", i, i, i);
	}
	fclose(f);
	/* ascii.txt file is created */
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Printing all ASCII Characters 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	for (int i = 0; i < 128; ++i)
	{
		if(iscntrl(i))
			printf("%-3d Control Character\n", i);
		else 
			printf("%-3d %c\n", i, i);
	}

	/*
		0   Control Character
		1   Control Character
		2   Control Character
		3   Control Character
		4   Control Character
		5   Control Character
		6   Control Character
		7   Control Character
		8   Control Character
		9   Control Character
		10  Control Character
		11  Control Character
		12  Control Character
		13  Control Character
		14  Control Character
		15  Control Character
		16  Control Character
		17  Control Character
		18  Control Character
		19  Control Character
		20  Control Character
		21  Control Character
		22  Control Character
		23  Control Character
		24  Control Character
		25  Control Character
		26  Control Character
		27  Control Character
		28  Control Character
		29  Control Character
		30  Control Character
		31  Control Character
		32
		33  !
		34  "
		35  #
		36  $
		37  %
		38  &
		39  '
		40  (
		41  )
		42  *
		43  +
		44  ,
		45  -
		46  .
		47  /
		48  0
		49  1
		50  2
		51  3
		52  4
		53  5
		54  6
		55  7
		56  8
		57  9
		58  :
		59  ;
		60  <
		61  =
		62  >
		63  ?
		64  @
		65  A
		66  B
		67  C
		68  D
		69  E
		70  F
		71  G
		72  H
		73  I
		74  J
		75  K
		76  L
		77  M
		78  N
		79  O
		80  P
		81  Q
		82  R
		83  S
		84  T
		85  U
		86  V
		87  W
		88  X
		89  Y
		90  Z
		91  [
		92  \
		93  ]
		94  ^
		95  _
		96  `
		97  a
		98  b
		99  c
		100 d
		101 e
		102 f
		103 g
		104 h
		105 i
		106 j
		107 k
		108 l
		109 m
		110 n
		111 o
		112 p
		113 q
		114 r
		115 s
		116 t
		117 u
		118 v
		119 w
		120 x
		121 y
		122 z
		123 {
		124 |
		125 }
		126 ~
		127 Control Character
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Escape Sequence 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	printf("newline		     %d\n", '\n');
	printf("vertical tab     %d\n", '\t');
	printf("horizontal tab   %d\n", '\v');
	printf("carriage return  %d\n", '\r');
	printf("backspace	     %d\n", '\b');
	printf("alert	         %d\n", '\a');
	printf("form feed	     %d\n", '\f');
	printf("null character   %d\n", '\0');
	printf("back slash       %d\n", '\\');
	printf("single quote     %d\n", '\'');
	printf("double quote     %d\n", '\"');
	printf("double quote     %d\n", '"');
	printf("question mark    %d\n", '\?');
	printf("question mark    %d\n", '?');

	/*
		newline              10
		vertical tab     9
		horizontal tab   11
		carriage return  13
		backspace            8
		alert            7
		form feed            12
		null character   0
		back slash       92
		single quote     39
		double quote     34
		double quote     34
		question mark    63
		question mark    63
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Printing different types of characters

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x = '\x41';
	printf("x : %d\n", x);
	
	int y = '\xaa';
	printf("y : %d\n", y);

	int z = '\012';
	printf("z : %d\n", z);

	/*
		x : 65
		y : -86
		z : 10
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : In C ++ language, an integer constant can be written directly in binary system. In C language, extension should be used for this. It is not a standard feature.

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x = 0b100101;
	printf("x : %d\n", x);
	
	x = 0b1000'1101'0101;
	printf("x : %d\n", x);
	/*
		x : 37
		x : 2261
	*/
}
```

/----------------------------------------------
/----------------------------------------------
