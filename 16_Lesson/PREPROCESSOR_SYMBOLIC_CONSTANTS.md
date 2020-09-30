## PREPROCESSOR SYMBOLIC CONSTANTS (PREDEFINED MACRO):

/----------------------------------------------
/----------------------------------------------

- #line, #error, #pragma preprocessor commands: 
  - #error  --> kodun bilerek isteyerek önişlemci aşamasında sonlandırılması
  - #pragma -->
  - #line   --> 


#error this project should not been compiled!!!

/----------------------------------------------
/----------------------------------------------

// c derleyicisi ile derlenmek istendiğinde bu blok içine girecektir:
// programcı sadece cpp derleyicisi ile derlemek istediğinde 

```c
#ifndef __cplusplus 
#error this project should not been compiled!!!
#endif
```

/----------------------------------------------
/---------------------------------------------- 

- önceden tanımlanmış makro sabitleri:  __cplusplus 
- diğer makrolar ile çakışma riskini ortadan kaldırmak için __ ile başlar ve biter. 
  - __LINE__  : assert makrosu içinde de tanımlıdır. 
  - __FILE__
  - __DATE__
  - __TIME__
  - __STDC__
  - __func__

/----------------------------------------------
/----------------------------------------------

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

* You can use assert functional macro (from <assert.h> library) instead of previous code sample
 - assert(x != 0); --> parantez içinde doğru olması gereken ifade yazılmalı!

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

* assert functional macro definition in standard lib. 

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

* #define NDEBUG ile debug süreci sonlandığında assert makrolarının elle silinmesine gerek kalmadan derleme aşamasında koddan çıkarılması sağlanır. 
 - #define NDEBUG --> #include <assert.h> öncesinde eklenmesi gerekmektedir. 
 - Bu sayede boş deyim dönmesi sağlanacaktır 
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

* __DATE__ , __TIME__, __FILE makroları
     - __TIME__ otomatik olarak derleme zamanına göre değişir.
     - __DATE__ otomatik olarak derleme zamanına göre değişir.

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

* __func__ makrosu:

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

* __STDC__ : 
    - c ile derlenmesi istenen kod blokları için koşul olarak kullanılır. 
    - __cpluscplus ifadesi ise aynı makro yapısının cpp tarafındaki hali 

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
    - eğer bir derleyici önişlemci programa ilave işler yaptırmak istiyorsa bu komut kullanılmaktadır.
    - hangi amaçla kullanılacağı standartlara bağlı değildir. 
    - portability sorunu ortaya çıkabilir. Çünkü derleyiciye specifik pragma komutları yazılmaktadır. 
    - #pragma once : multiple inclusion guard
    - #pragma warning(disable:4552) : to disable a warning

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


