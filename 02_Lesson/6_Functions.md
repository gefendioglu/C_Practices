## Function Types  
/----------------------------------------------
/----------------------------------------------

What does the return value of a function mean?\
- Some functions calculate a value. These functions usually send the calculated value to the calling code via the return value mechanism.
  
```c
int get_abs(int val) 
{
	if (val > 0)
		return val;
	return -val;
}
```

- The function may exist to answer a question as yes-no / valid-invalid (Test functions / predicates / query functions).
  - In C, int return value is usually used.
    - non-zero values --> TRUE\ 
      zero --> FALSE 
    - Usually int return value is used in C
      ```c
      int is_prime(int val); // --> C 
      int is_upper(int c);
      int is_valid_card_no(int val);
      bool isprime(int val); // --> C++ 
      ```

- Bazi fonksiyonlarin varlik nedeni bir gorevi yerine getirmek. Ornegin bir aga/veritabanina baglanmak, bellek alani ayirmak gibi vs.
Bu fonksiyonlarin basarili olabilmesi icin belli kosullarin saglanmis olmasi gerekebilir. 
Eger kosullar programin calisma aninda saglanmazsa fonksiyon gorevi basari ile yerine getiremez. 

The reason for the existence of some functions is to fulfill a task. For example connecting to a network/database, allocating memory space etc.
In order for these functions to be successful, certain conditions may need to be met.
If the conditions are not met at the time the program is running, the function cannot perform its task successfully.


return value --> adres olarak belirlendiginde 
 - NULL    --> unsuccessful result 
   address --> successful result 

- Examples from standard library:
   fseek()
   remove()


- Bazi fonksiyonlarin geri donus degerleri cagiran kodun opsiyonel olarak kullanabilecegi tamamlayici bir bilgi
Example: printf(...) function 
Genellikle printf fonksiyonun geri donus degeri kullanilmaz 

Example: Bir diziden veya veri yapisindan belirli bir kosulu saglayan degerleri silen fonksiyon
Eger kac adet degerin silindigi bilgisi donduruluyorsa, cagiran kod tarafinda bu deger kullanilmayabilir.

Normalde geri donulen degerin cagiran tarafta kullanilmamasi hatali bir durumdur. 
Ancak bu fonksiyonlar bu hatali durumun disinda degerlendirilir. 


- Geri donus degeri olmayan fonksiyonlar 
  - ve cagiran koda ilettigi bir deger yok --> void clear(void);
	- veya cagiran koda baska bir yol ile bir deger iletiyor. --> call by reference 

/----------------------------------------------
/----------------------------------------------

## Main Function

- the return value of a main function isletim sistemi seviyesinde kullanilabilen bir deger
programin calistirilmasi baska bir programin calismasina bagliysa, o zaman return value basari bilgisi 
acisindan kullanilacaktir. 
return 0; --> SUCCESS

- main fonksiyonu icin void return value kullanimi programin basari bilgisi gonderilemez. 
Cpp da bu kullanim gecerli degildir. 

- C99 ve Cpp standartlarina gore return value yazilmadiginda, return 0; otomatik olarak eklenmektedir.

- main fonksiyonun parametre degeri kullanilir mi? 
int main(int argc, char **argv){...}
programin komut satirindan calistirilmasi durumunda bu parametreler kullanilir. 

int main(void){...}

```c
int main()
{
	FILE *f;
	//code...

	f = fopen("database.dat", "rb");
	if (f == NULL)
	{
		fprintf(stderr, "file is not opened!!!/n");
		return 1;
	}
	//code...
	return 0; // code readibility 
}
```
 
- The meaning of return value as int: 
  ```c
  int day_of_year(Date date); --> int represents a calculated value 
  int isxdigit(int c);  --> int represents a boolean value
  int fseek();  --> int represents an address value
  ```

/----------------------------------------------
/----------------------------------------------
- **Example** : The difference using void parameter for functions

```c
void func(){...}
void foo(void){...}

int main()
{
	func(12); // NOT ERROR
	foo(12);  // NOT ERROR, probably a logic error
}
```

/----------------------------------------------
/----------------------------------------------

- C ve C++ dillerinde bazi programlama dillerinde olan nested-function ozelligi bulunmaz
  - Tum fonksiyonlar global isim alaninda tanimlanmak zorundadir. 

- Function overloading ve default argument mekanizmalari  C dilinde yoktur!!! 
  - C++, Java, CSharp gibi dillerde bu ozellik mevcuttur.

- Default argument mekanizmalari C dilinde bulunmaz !!! 
```c
void func(int a, int b, int c = 0); // NOT OK !!!

int main()
{
	func(1, 2, 3);
	return 0;
}
```

- Fonksiyon tanimlama sirasi onemli midir? 
  - Eger birbirlerini cagiriyorlarsa EVET (name-lookup)

```c
void func3(void)
{
	//code...
}

void func1(void) 
{
	func3();
}

void func2(void)
{
	//code...
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Old style function definition - backward compatibility
  - Not available for C++ language 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//old-style function
sum(a, b, c)
{
	return a + b + c;
}

//old-style function
double sum2(a, b, c)
double a, b, c;
{
	return a + b + c;
}

int main()
{
	int result = 0;
	result = sum(10, 12, 13);
	printf("int result : %d\n", result );

	double dresult = 0.0;
	dresult = sum2(1.2, 1.3, 1.4);
	printf("double result : %f\n", dresult);

	return 0;
}
```

/----------------------------------------------
/----------------------------------------------

Function Calls 

- Bir fonksiyon cagrisi bir ifadedir --> function call expression
- Fonksiyon cagrilari operator seviyesinde bir islemdir. Function call operator ()
- Bu operatorun operandi function name
- Fonksiyona gonderilen ifadelere --> argument 
- Bir fonksiyon cagrisi ifadesinde once argument olan ifadelerin degerleri hesaplanir
sonra fonksiyon cagrisi yapilir.
- Bir fonksiyon cagri ifadesi ile neler yapilabilir? 
  - Geri donus degeri olmayan fonksiyonlar statement haline getirilerek kullanilir.
  - Geri donus degeri olan fonksiyonlarin dogrudan statement olarak kullanilmasi bir syntax error degildir. 
  discard the return value of a function 
    - Bir fonksiyonun geri donus degerini ilk deger olarak vermek (statik omurlu olmadigi surece) veya bir degiskene atamak


- Neden bir fonksiyonun geri donus degeri bir degiskende saklanir? 
  - Ayni fonksiyonun surekli cagrilmasini engellemek, bunun yerine atanan degerin kendisini kullanmak
  - Fonksiyon cagirmak run time asamasinda maliyetlidir 
  - Eger derleyici optimizasyon yapmiyorsa kaynak kaybi soz konusu olabilir. 
  
  Bad code example:
  ```c
  a = sin(x) + .3;
  // x not changed 
  b = sin(x) + .3;
  // x not changed 
  c = sin(x) + .5;
  ```

  Good code example: 
  ```c
  d = sin(x); 
  a = d + .3;
  // x not changed 
  b = d + .3;
  // x not changed 
  c = d + .5;
  ```


- Kodun kalitesini bozan ogelerden biri
  - Bir fonksiyonun geri donus degerini bir degiskende saklamak 
  - Bir fonksiyonun geri donus degerini bir degiskende saklamamak 
  duruma gore degisebilmektedir. 

  Bad code example: 
  ```c
  int val = max(a, b);
  if(val > 10){...}
  // if val is nou used anymore...
  ```

  Good code example: 
  ```c
  if(max(a, b) > 10){...}
  // if val is nou used anymore...
  // you specify this using function call directly in if statement
  ```

- Sub-expression olarak fonksiyon cagrilari
  ```c
  int a = sin(b) + sin(c);
  if(sin(b) * sin(c) > sqrt(c)){...}
  ```

- Once argument olan ifadenin degeri hesaplanacagi icin yerine fonksiyon cagrisi da kullanilabilir.
  ```c
  int max(ndigit(x), ndigit(y));
  double dval = sin(cos(x));
  double ival = sin(sqrt(x)+ sqrt(y));
  draw_point(sin(pow(x,y)));
  strcat(strcpy(sstr1, str2), str3);
  ```

- unevaulated context for a function call
  int x = sizeof(printf("alican"));

/----------------------------------------------
/----------------------------------------------
 
- **Example** : Function call as a sub-expression for the same function

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max_number(int a, int b)
{
	return a > b ? a : b; 
}

int main()
{
	int a, b, c, d; 
	int max; 

	printf("Enter 4 numbers : ");
	scanf("%d%d%d%d", &a, &b, &c, &d);

	max = max_number(max_number(a, b), max_number(c, d));
	printf("max number : %d\n", max);

	return 0;
}

/----------------------------------------------
/----------------------------------------------

- **Example** : Function call as an expression or a sub-expression for the return value of a function 

int max_number(int a, int b)
{
	return a > b ? a : b; 
}

int func(int a, int b)
{
	//...

	return max_number(a, b);
	// return max_number(a, b) + 10;
}

/----------------------------------------------
/----------------------------------------------

- **Example** : Function call as an expression or a sub-expression for the return value of a function 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int func(int a)
{
	//...

	return printf("%d", a);
}

int main()
{
	int a = 10 , b = 40, c; 
	c = func(a + b);

	printf("\nc : %d\n", c);
	
	return 0;
	/*
		50
		c : 3
	*/
}

/----------------------------------------------
/----------------------------------------------

### Variadic Function 
- degisen sayida arguman gonderilebilen fonksiyonlardir 
- standard kutuphanedeki fonksiyonlardan -->  printf
  int printf(const char *, ...);
- ellipses token is used to write a variadic function 
  void func(int x, ...){...}
- variadic parametreden onceki tum parametrelere argument gonderilmek zorunludur!!!

/----------------------------------------------
/----------------------------------------------

- **Example** : Variadic function example

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// variadic function definition
void func(int a, ...){/*code*/ }

int main()
{
	func(1);              // OK
	func(1, 10);          // OK
	func(1, 10, 20);      // OK
	func(1, 10, 20, 30);  // OK
	return 0;
}

/----------------------------------------------
/----------------------------------------------

- **Example** : Variadic function example

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// variadic function definition
void func(int a, int b, ...){/*code*/ }

int main()
{
	func(1);              // NOT OK 
	func(1, 10);          // OK
	func(1, 10, 20);      // OK
	func(1, 10, 20, 30);  // OK
	return 0;
}

/----------------------------------------------
/----------------------------------------------

### Call By Value / Call By Reference 

- C de her fonksiyon cagrisi default olarak --> call by value 

- C de call by reference pointer semantigi ile saglanir.
  standard library --> scanf(...)

- C++ ise call by reference hem pointer hem de referans semantigi ile saglanir. 
  void func_ref(int &a);
  void func_ref(int *a);

- Operator - Declarator Farki? 
  bildirimde kullanilan --> declarator
  diger kullanimlarda   --> operator 
  
  int x = 10;
  int *ptr = &x; --> * is a declarator
  *ptr = 20;     --> * is an operator (dereferencing operator)

  int arr[2] = {1,2,3}; --> [] is a declarator
  arr[0] = 4;           --> [] is an array operator

/----------------------------------------------
/----------------------------------------------

- **Example** : Call By Value

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//call by value
void func_val(int a)
{
	a = 1000; 
}

//call by reference
void func_ref(int *a)
{
	*a = 1000;
}

int main()
{
	int x = 10;
	func_val(x);
	printf("x : %d\n", x);

	func_ref(&x);
	printf("x : %d\n", x);

	return 0;
	/*
		x : 10
		x : 1000
	*/
}

/----------------------------------------------
/----------------------------------------------

### Standard Library 

- Dilin kurallarinin on gordugu sekilde dilin derleyicisinin kullaniciya sundugu kodlardir.

- Standard C fonksiyonlari standard kutuphanenin bilesenlerinden biridir. 
  - standard uder defined types
  - standard macros
    - object-like macros
	- function-like macros 
  - standard C functions
  - standard type alias

- 3rd party library function is not a part of standard library

/----------------------------------------------
/----------------------------------------------

- **Example** : Standard library usage

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int x = RAND_MAX; // standard macro
	struct tm tx;     // standard type 
	time_t timer;     // standard type alias
	time(&timer);     // standard function

	return 0;
}

/----------------------------------------------
/----------------------------------------------
