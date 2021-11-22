## Input - Output Stream

- Bytes to the program --> standard input stream (default keyboard)
- Bytes from the program --> standard output stream (default display unit - monitor)
- standard input stream and standard output stream can be changed and this operation is called as "direction"

- unformatted output operation: the operation of writing the value held in the memory to the screen without converting it to the codes in the character encoding
- formatted output operation: the operation of converting the value kept in the memory to the codes in the character encoding and writing it to the screen

- unformatted input operation: entering the binary value entered from the keyboard directly into the memory
- formatted input operation: entering the value entered from the keyboard into the memory in the binary number system according to the ascii character encoding

- There are functions that perform formatted output and formatted input operations in the standard library of C.
- <stdio.h> header file is responsible these operations 
  - standart output functions: 
    - printf()  --> prints to standart output 
    - sprintf() --> prints to memory 
    - fprintf() --> prints to a file 
  - standart input functions: 
    - scanf()  --> scans from standart input 
    - sscanf() --> scans from memory 
    - fscanf() --> scans from a file 

- Formatted Output: 
   - Which number system will it be written?
   - Will the prefix showing the prefix of the number system be written?
   - Will characters be written in uppercase or lowercase in the hexadecimal system?
   - Will the + and - characters be used to write for positive/negative numbers?

- width character: writing area width
987551   gamze efendioglu
   764  mehmet efendioglu

- fill character: 

 
/----------------------------------------------
/----------------------------------------------

### printf function

- int printf(const char *ptr, ...); --> at least one argument must be sent

   - const char *ptr : If the text whose address is taken will not be changed, if it will be used for reading (access) purposes only, the const keyword should be used.

   - return value is int to show how many characters are written in output stream.

- In C, strings are kept in arrays of char type (const char *). There is no string class or library that specifically holds text.
   - char str[20]; --> char array
   - When a text is wanted to be sent to a function, it is sent with a call by reference (with address) instead of call by value, since it will send a char array. For this reason, the parameter of the function will be of pointer type.
    
- "BABA" is comprised of --> 'B' 'A' 'B' 'A' '\n'

/----------------------------------------------
/----------------------------------------------

- **Example**: 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// The address of a string literal ("Enter a value : ") is sent as an argument for the first parameter of printf function 
	printf("Enter a value : ");
}
```

/----------------------------------------------
/----------------------------------------------

- The arguments sent to the variadic parameters of the printf function are formatted and written to the screen. Conversion specifier samples are:
   - %d   --> decimal
   - %x   --> hexadecimal
   - %o   --> octal
   - %f   --> double types ( by default, 6 digits are written after the period.)
   - %.3f --> double types ( 3 digits will be written after the period.)
   - %c   --> writes integer characters
   - %%   --> to print % character

/----------------------------------------------
/----------------------------------------------

- **Example** : 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x = 298012;
	printf(" x : %d\n", x);
	printf(" x : %x\n", x);
	printf(" x : %o\n", x);

	/*
		x : 298012
		x : 48c1c
		x : 1106034
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	for (int i = 0; i < 26; ++i)
		printf("%c ", 'A'+i);
	
	printf("\n");

	for (int i = 0; i < 26; ++i)
		printf("%c ", 'a' + i);

	printf("\n");

	for (int i = 0; i < 10; ++i)
		printf("%c ", '0' + i);

	printf("\n");

	for (int i = 33; i < 127; ++i)
		printf("%c ", i);

	/*
		A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
		a b c d e f g h i j k l m n o p q r s t u v w x y z
		0 1 2 3 4 5 6 7 8 9
		! " # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \ ] ^ _ ` a b c d e f g h i j k l m n o p q r s t u v w x y z { | } ~
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Using  the return value of printf function 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x = 110, y = 56;
	int retval;

	retval = printf("%d+%d=%d", x, y, x + y);
	printf("\nretval : %d\n", retval);

	/*
		110+56=166
		retval : 10
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x = 1976;
	printf("%d", printf("%d", printf("%d", x))); // 197641
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of %% character 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x,y;
	printf("Enter two values: ");
	scanf("%d%d", &x, &y);

	printf("%d %% %d = %d\n", x, y, x%y); 
	/*
		Enter two values: 15 12
		15 % 12 = 3
	*/
}
```

/----------------------------------------------
/----------------------------------------------

### scanf function

- The return value of scanf function is the number of variables set by scanf

- It sets the characters coming from the standard input stream in accordance with the formatted format.

- int scanf(const char *ptr, ...);
   - Since the first parameter has nothing to do with the output stream, a format information that can be string literal (such as %d, %o, &x, etc.) should always be sent as an argument, and the address information of the object should always be sent to the variadic parameter.
   - Conversion specifiers that differ from the printf function:
     - %f --> float
     - %lf --> double
     - %u --> unsigned int

- The buffer of standard input stream :
   - For example, when 123 879(enter) is entered; The ASCII code of each character is added to the input buffer. 
   - In this example, in order: 49 50 51 32 56 55 57 10 code is added to the buffer.
     - scanf is a line buffered function (newline (\n) character is needed to exit the buffer.)
     - emptying the buffer

```cpp
void clear_input_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The buffer of standard input stream

```cpp
int main() {

	int ival;
	double dval;
	printf("Enter two values: ");
	scanf("%d%lf", &ival, &dval); 
	// ival = 12.95 --> ival = 12 
	// dval = .95 
	// input stream buffer dan sadece 12 karakterleri alýnýr.
	// buffer da kalan karakterler dval tarafýndan alýnýr.
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int ival;
	printf("Enter an integer: ");
	scanf("%d", &ival); // decimal
	printf("ival = %d\n", ival);

	printf("Enter the same integer: ");
	scanf("%x", &ival); // hexadecimal
	printf("ival = %d\n", ival);

	printf("Enter the same integer: ");
	scanf("%o", &ival); // octal
	printf("ival = %d\n", ival);

	/*
		Enter an integer: 12
		ival = 12
		Enter the same integer: 12
		ival = 18
		Enter the same integer: 12
		ival = 10
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The return value of scanf function 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int ival;
	int retval;

	printf("Enter an integer: ");
	retval = scanf("%d", &ival);
	
	printf("retval : %d\n", retval);


	/*
		Enter an integer: 12
		retval : 1

		Enter an integer: mehmet
		retval : 0
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The return value of scanf function 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int ival;
	int retval;

	printf("Enter an integer: ");
	retval = scanf("%x", &ival); 

	printf("retval : %d\n", retval);
	
	/*
		Enter an integer: ali // a is a hex number 
		retval : 1

		Enter an integer: mehmet // m is not a hex number
		retval : 0
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** :

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x,y,z;
	int retval;

	printf("Enter three integers: ");
	retval = scanf("%d%d%d", &x, &y, &z);

	printf("retval : %d\n", retval);

	/*
		Enter three integers: 12 34 58
		retval : 3

		Enter three integers: 12 34 mehmet
		retval : 2
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** :

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x,y;

	printf("Enter an integer: ");
	scanf("%d", &x);

	printf("Enter an integer: ");
	scanf("%d", &y);

	printf("x : %d\n", x);
	printf("y : %d\n", y);

	/*
		Enter an integer: 12
		Enter an integer: 25
		x : 12
		y : 25

		Enter an integer: 12mehmet
		Enter an integer: x : 12
		y : -858993460
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Different conversion specifiers for scanf func

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x;

	printf("Enter an integer: ");
	scanf("%*d%*d%d", &x);

	printf("x :%d\n", x);
	/*
		Enter an integer: 12 45 87
		x :87
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Using scanf func with diffent type of input data 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int age;
	char name[100];

	printf("Enter your name and age: ");
	scanf("%s%d", &name, &age);

	// dont want to take name from input stream
	//scanf("%*s%d", &age); 

	printf("name :%s\n age:%d\n", name, age);

	/*
		Enter an integer: ahmet 15
		name :ahmet
		age: 15
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Printing the max value for three different integer numbers

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max_value(int a, int b, int c) {
	int max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	return max;
}
int main() {

	int x,y,z;

	printf("Enter three integers: ");
	scanf("%d%d%d", &x, &y, &z);

	printf("The max value : %d\n", max_value(x,y,z) );

	/*
		Enter three integers: 12 58 48
		The max value : 58
	*/
}
```

/----------------------------------------------
/----------------------------------------------
