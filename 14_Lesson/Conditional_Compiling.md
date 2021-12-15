## Conditional Compiling 

- Conditional compilation uses a preprocessor program. It is the process that ensures that some code participates in the compilation and some does not.
- One of the reasons is due to different operating systems. For example, the code structure to be compiled can be changed depending on whether the operating system is Linux or Windows.
- It may also be possible to have different hardware for the same operating system. Differences can be achieved with the preprocessor command.
  
- Conditional Compiling işlemine neden ihtiyaç duyulmaktadır? 
  - İşletim sistemine bağlı kod farklılıkları 
  - İşlemci/kontrolcü/donanıma bağlı kod farklılıkları
  - Derleyicilere bağlı kod farklılıkları
    - Derleyicinin farklı versiyonlarına bağlı kod farklılıkları\
      https://wandbox.org/
  - Programlama diline bağlı kod farklılıkları 
  - Ülke/yöre/dile bağlı kod farklılıkları 
  - Versiyona bağlı kod farklılıkları 

- Why is Conditional Compiling needed?
  - Code differences depending on the operating system
  - Code differences depending on processor/controller/hardware
  - Code differences due to compilers
  - Code differences due to different versions of the compiler (check it from the link: https://wandbox.org/)
  - Code differences depending on programming language
  - Code differences depending on country/region/language
  - Code differences depending on version
  
- Assertion
  - static assertion : the assertion made during translation (_Static_assert) 
  - dynamic assertion : the assertion made during runtime (assert.h - ASSERT macro)
  - The codes written to prevent any undefined behavior from occurring are called "assertion code".
  - It is also used to write coding errors.
  - However, assertion codes are only used in the debug version as they increase the code size. In the release version (in the .exe stage), these codes should be removed.\
   In this way, assertion codes can be used only in debug version with conditional compilation commands.

- Conditional Compiling Commands : 
  - #if
  - #else
  - #endif
  - #define
  - #undef
  - #ifdef
  - #ifndef 

- Conditional Compiling Operator : defined

/----------------------------------------------
/---------------------------------------------- 

- **Example** : #if - #endif 

```c
#if MAX>10
    #include <stdarg.h>
    #define SIZE 100  // preprocessor command
    typedef int Word; // the code sent to the compiler
#endif
```

/----------------------------------------------
/---------------------------------------------- 

```c
#define NEC  100 // enters in this code block 
#if NEC 
    #include <stdarg.h>
    #define SIZE 100  // preprocessor command
    typedef int Word; // the code sent to the compiler
#endif
```

/----------------------------------------------
/---------------------------------------------- 

```c
#define NEC  0 // not enter in this code block
#if NEC 
    #include <stdarg.h>
    #define SIZE 100  // preprocessor command
    typedef int Word; // the code sent to the compiler
#endif
```

/----------------------------------------------
/---------------------------------------------- 

```c
// It is entered in the code block even if the NEC is not defined !!!
#if NEC>-1 
    #include <stdarg.h>
    #define SIZE 100  // preprocessor command
    typedef int Word; // the code sent to the compiler
#endif
```

/----------------------------------------------
/---------------------------------------------- 

- Preprocessor expression rules: Gerçek sayı aritmetiği kullanılamaz. 
   
```c
#define CNST 4.5
#if CNST>2.5
//...
#endif
```
  
/----------------------------------------------
/---------------------------------------------- 
- **Example** : if-else conditional compiling code block

```c
#define SIZE 100

#if SIZE > 50
	typedef int int32_type;   
#else 
	typedef long int32_type; 
#endif
```

/----------------------------------------------
/---------------------------------------------- 
- **Example** : if-else conditional compiling code block

```c
#define USD 0
#define EUR 1
#define GBP 2
#define CHF 3

#define CURRENCY EUR

#if CURRENCY ==  USD
const char* pcur = "American Dolar";
#else

#if CURRENCY == GBP
const char* pcur = "British Pound";
#else

#if CURRENCY == CHF
const char* pcur = "Swich Franc";
#else

#if CURRENCY == EUR
const char* pcur = "Euro"; 

#endif
#endif
#endif
#endif
```

/----------------------------------------------
/---------------------------------------------- 
- **Example** : if-else conditional compiling code block with using #elif

```c
#define USD 0
#define EUR 1
#define GBP 2
#define CHF 3

#define CURRENCY GBP 

#if CURRENCY ==  USD
	const char* pcur = "American Dolar";
#elif CURRENCY == GBP
	const char* pcur = "British Pound"; 
#elif CURRENCY == CHF
	const char* pcur = "Swich Franc";
#elif CURRENCY == EUR
	const char* pcur = "Euro";
#endif
```

/----------------------------------------------
/---------------------------------------------- 
- **Example** : #ifdef  - #ifndef conditional compiling commands example 

```c
//#define NEC

#ifdef NEC
	typedef int Word;
	typedef unsigned char Byte; 
#endif

// This block will be used 
#ifndef NEC 
	typedef int Word;
	typedef unsigned char Byte;
#endif
```

/----------------------------------------------
/---------------------------------------------- 
- **Example** : #ifdef  - #ifndef conditional compiling commands example 

```c
card.h: 
----------
/*
Club    = Sinek
Diamond = Karo
Heart   = Kupa
Spade   = Maça
*/

#ifdef POKER
	typedef enum { Club, Diamond, Heart, Spade}Suit;
#else
	typedef enum { Club, Diamond, Spade, Heart}Suit;
#endif

main.c:
----------
#include <stdio.h>

#define POKER
#include "card.h"

int main() {

} 
```

/----------------------------------------------
/---------------------------------------------- 

myMath.h:
----------
```c
#ifdef _USE_MATH_DEFINES
	#define M_PI 3.1415926
#endif
```

main.c:
----------
```c
#include <stdio.h>

#define _USE_MATH_DEFINES
#include "myMath.h"

int main() {
	int ival = M_PI;
}
```

/----------------------------------------------
/---------------------------------------------- 

- **Example** :  defined operator example --> The following definitions are the same

```c
#ifdef SIZE
#endif
``

```c
#if defined (SIZE)
#endif
```

/----------------------------------------------
/---------------------------------------------- 

- **Example** : defined operator example --> The following definitions are the same

```c
#ifndef SIZE
#endif
```

```c
#if !defined SIZE
#endif
```

/----------------------------------------------
/----------------------------------------------

- **Example** : defined operator example --> The following definitions are the same

```c
#ifdef SIZE
    #ifdef PRT
    //....
#endif
#endif
```

```c
#if defined SIZE && defined PRT
    //....
#endif
```

/----------------------------------------------
/---------------------------------------------- 

- **Example** : defined oprator example: 

```c
#include <stdio.h>

#define SIZE
#define PRT

// This block will be run
#if defined SIZE && defined PRT
	typedef int Word; 
#endif

#if defined SIZE && !defined PRT
	typedef int Word;
#endif

#if !defined SIZE && defined PRT
	typedef int Word;
#endif

#if !defined SIZE && !defined PRT
	typedef int Word;
#endif

int main() {
} 
```

/----------------------------------------------
/---------------------------------------------- 

### Multiple Inclusion Guard : 
 - Çoklu dahil etmeye karşı yapılan koruma
 - Derleyicinin aynı başlık dosyasına tekrar girmesine karşı yapılan koruma. Aynı kodun #include ile tekrar yapıştırılması bazı durumlarda hataya sebep olur. 

/----------------------------------------------
/---------------------------------------------- 

- **Example** : Multiple Inclusion Guard Example 

myStruct.h:
----------
```c
// #ifndef MYSTRUCT_INCLUDED
// #if !defined MYSTRUCT_H
#ifndef MYSTRUCT_H
#define MYSTRUCT_H
	struct Data {
		int a, b, c;
	};
#endif
```

main.c:
---------- 
```c
#include "myStruct.h"
#include "myStruct.h" // not return a redefinition error

int main() {
} 
```

/----------------------------------------------
/---------------------------------------------- 

- #pragma pre-processor command
  - bir header dosyasının sadece tek sefer include edilmesini saglar. 
  - taşınabilirlik açısından problem yaratabilir. 
  - #pragma once --> quasi standard kategorisindedir. 
     multiple inclusion guard otomatik bir yapıya bağlanmış olur. 

/----------------------------------------------
/---------------------------------------------- 

* Makroların son kullanılma amacı koddan bazı ön işlemci isimlerinin silinmesini sağlamaktır. 

#define PUBLIC 
PUBLIC int foo(void) {
} 

/----------------------------------------------
/---------------------------------------------- 

- **Question** : Aynı kaynak dosyada aynı isimde hem bir fonksiyonel makro hem de gerçek bir fonksiyon oluşturulduğunda ne olur? --> macro çağrılır

// not a syntax error for the following code 
#include <stdio.h>

int sum_square(int a, int b) {
	
	printf("FONKSIYON !!!!\n");
	return a * a + b * b;
}

#define sum_square(x,y) ((x*x)+(y*y))

int main() {
	int firstNumber = 10;
	int secondNumber = 20;

	// macro sum_square(x,y) will be used here
	int ival = sum_square(firstNumber, secondNumber);
	printf("ival = %d\n", ival);
}

/----------------------------------------------
/---------------------------------------------- 

* Mülakat --> Aynı kaynak dosyada aynı isimde hem bir fonksiyonel makro hem de gerçek bir fonksiyon oluşturulduğunda, fonksiyonun çağrılmasını sağlamak için ne yapmak gerekir? 
  - function to pointer ile fonksiyon adresi kullanılır.
  - Makronun açılabilmesi için kendi isminden sonra açılan parantezin gelmiş olması gerekmektedir. Bu durum engellenirse onun yerine aynı isimle tanımlı fonksiyonu çağırmak için parantez içine alınabilir. 
  	int ival = sum_square(firstNumber, secondNumber); yerine -->
    int ival = (sum_square)(firstNumber, secondNumber);

#include <stdio.h>

int sum_square(int a, int b) {
	
	printf("FONKSIYON !!!!\n");
	return a * a + b * b;
}

#define sum_square(x,y) ((x*x)+(y*y))

int main() {
	int firstNumber = 10;
	int secondNumber = 20;

	// macro sum_square(x,y) will be used here
	int ival = (sum_square)(firstNumber, secondNumber);
	printf("ival = %d\n", ival);
} 

/----------------------------------------------
/---------------------------------------------- 

* Eğer makro fonksiyondan önce tanımlanırsa, fonksiyon aşağıdaki şekilde de parantez içinde tanımlanmalıdır!!! 
  - int (sum_square)(int a, int b) {


#include <stdio.h>

#define sum_square(x,y) ((x*x)+(y*y))

int (sum_square)(int a, int b) {
	
	printf("FONKSIYON !!!!\n");
	return a * a + b * b;
}

int main() {
	int firstNumber = 10;
	int secondNumber = 20;

	// macro sum_square(x,y) will be used here
	int ival = (sum_square)(firstNumber, secondNumber);
	printf("ival = %d\n", ival);
} 

/----------------------------------------------
/---------------------------------------------- 

* Neden aynı isimli bir fonksiyonel makro ile fonksiyon tanımı aynı dosyada yer alır? Buna neden ihtiyaç duyulur? 
 - Güvenli olmayan durumda fonksiyonun çağrılması tercih edilebilir. 
 - Her zaman fonksiyon kullanımı daha güvenilirdir. Çünkü fonksiyona gönderilen parametrelerin türleri bellidir. Fonksiyonel makrolarda ise değildir. Bu durum undefined behaviour a yol açabilir. 
 - Fonksiyonlar debug friendly ve test edilmeye daha uygundur. 
