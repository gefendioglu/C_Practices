## PREPROCESSOR SYMBOLIC CONSTANTS (PREDEFINED MACRO):

- #line, #error, #pragma preprocessor commands: 
  - #error  --> finalizing the code intentionally in the preprocessor phase
  - #pragma -->
  - #line   --> 

#error this project should not been compiled!!!

/----------------------------------------------
/----------------------------------------------

- ** Example ** : It will enter this block when it wants to be compiled with the c compiler.

```c
#ifndef __cplusplus 
#error this project should not been compiled!!!
#endif
```

/----------------------------------------------
/---------------------------------------------- 

- ** Example ** : Predefined macro constants (such as __cplusplus )
  - It starts and ends with __ to avoid the risk of conflicts with other macros.
    - __LINE__  : defined in assert macro 
    - __FILE__  :
    - __DATE__  :
    - __TIME__  :
    - __STDC__  :
    - __func__  :

/----------------------------------------------
/----------------------------------------------

- ** Example ** : __LINE__

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	printf("The row of source code :  %d\n", __LINE__); //  : 5
	printf("The row of source code :  %d\n", __LINE__); //  : 6
}
```

/----------------------------------------------
/----------------------------------------------

- ** Example ** : Macro definition for DEBUG 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define DEBUG

void func(int x) {
#ifdef DEBUG 
	if (x == 0) {
		printf("Error error...");
		abort();
	}
#endif
}

int main() {
	func(0); // The program was aborted !!!
}
```

/----------------------------------------------
/----------------------------------------------

- ** Example ** : You can use assert functional macro (from <assert.h> library) instead of previous code sample
  - assert(x != 0); --> The expression in the parentheses must be true !!!

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void func(int x) {
	assert(x != 0);
}

int main() {
	func(0);
}
```

/----------------------------------------------
/----------------------------------------------

- ** Example ** : assert functional macro definition in standard lib. 

```c
#ifdef NDEBUG

    #define assert(expression) ((void)0)

#else

    _ACRTIMP void __cdecl _wassert(
        _In_z_ wchar_t const* _Message,
        _In_z_ wchar_t const* _File,
        _In_   unsigned       _Line
        );

    #define assert(expression) (void)(                                                       \
            (!!(expression)) ||                                                              \
            (_wassert(_CRT_WIDE(#expression), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)), 0) \
        )

#endif
```

/----------------------------------------------
/----------------------------------------------

- ** Example ** : 
  - When the debug process ends with "#define NDEBUG", assert macros are removed from the code during compilation without having to manually delete them.
  - #define NDEBUG --> should be added before #include <assert.h> 
  - In this way, an empty statement will be returned.
    --> #define assert(expression) ((void)0)

```c
#define _CRT_SECURE_NO_WARNINGS
#define NDEBUG
#include <assert.h>

void func(int x) {
	assert(x != 0);
}
```

/----------------------------------------------
/----------------------------------------------

- ** Example ** :  __DATE__ , __TIME__ , __FILE 
  - __TIME__  : It changes automatically with respect to the compile time. 
  - __DATE__  : It changes automatically with respect to the compile time. 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	printf("SOURCE CODE : %s\n", __FILE__);
	//SOURCE CODE : C:\Users\user\Desktop\GitHub_Repo\C_Practices\16_Lesson\main.c

	printf("Compile date : %s\n", __DATE__); 
	// Compile time : Sep 13 2020

	printf("Compile time : %s\n", __TIME__);
	// Compile time : 10 : 08 : 26
}
```

/----------------------------------------------
/----------------------------------------------

- ** Example ** : __func__ 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void foo(void) {
	printf("The row %d of %s function in %s file \n", __LINE__, __func__, __FILE__);

}
int main() {
	foo();
}
```

/----------------------------------------------
/----------------------------------------------

- ** Example ** : __STDC__  
  - This macro is used as a condition for the code blocks that are requested to be compiled with c.
  - __cpluscplus is the same macro structure on the cpp side.  

```c
#ifdef __STDC__     // Defined for c compiler
#error C Compiler
#endif

#ifdef __cpluscplus // Defined for cpp compiler
#error CPP Compiler
#endif
```

/----------------------------------------------
/----------------------------------------------

* #pragma : 
  - This command is used if a compiler wants the preprocessor program to do additional work.
  - Which purpose that it will be used is not depending on the standards. 
  - "Portability" issue may arise. Because specific "pragma" commands are written to the compiler. 
  - #pragma once : multiple inclusion guard
  - #pragma warning(disable:4552) : to disable a warning

- ** Example ** :  #pragma

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning(disable:4552)

int main() {

	int x = 10;
	x + 5;
	// warning C4552: '+': result of expression not used
}
```

/----------------------------------------------
/----------------------------------------------


