
 ## ARRAYS : 

- Dizilerin boyutu constant expression olmak zorundadır!
- Fixed array dizi yapısı mevcuttur !!
  int a[10]; // type : int[10], garbage value
  int a[0];  // Tanımlanamaz!
  static int c[20];

- Ayrılan bellek alanı bellidir, dinamik olarak değiştirilemez. Bu sebeple, diziler üzerinde silme ekleme işlemleri uygulanamaz
- Global ve lokal değişken olarak tanımlanabilir!
- Bir fonksiyonun parametre değişkeni dizi olamaz !!!
  void func(int a[]); --> burada parametre değişkeni bir pointer
					  --> dizi adresi parametre olarak gönderilmektedir.
- Bir fonksiyonun geri dönüş değer değişkeni bir dizi türü olamaz !!!
- Dizilerin boyutları genelde sembolik sabitler olarak tanımlanır. 


* array decay (array to pointer conversion)
* arrays are not assignable !!!
* but in cpp there is a container called array can be assignable
* diziler fonksiyonlara parametre olarak atanamazlar. Ancak fonksiyonlara argüman olarak gönderilebilirler. 
* diziler fonksiyonlarýn geri dönüþ deðerleri olamazlar.
* diziler birbirlerine atanamazlar.
* dizi indexleri tamsayý olmak zorundadýr. Genelde isimlendirilmiþ sabitler kullanýlmaktadýr (macrolar).

#define SIZE 10
int a[SIZE]; // instead of int a[10];

/----------------------------------------------
/----------------------------------------------

* operators: 
&x   --> address of x 
*ptr --> dereferencing operator
->   --> member selection operator
[]   --> subscript operator (pointer operator)

/----------------------------------------------
/----------------------------------------------

* a[i] ile dizinin i indexli elemanýna eriþilmektedir.
* diziler 0 deðerinden baþlanarak indexlenmektedir.
* int a[100]; --> ilk eleman : a[0] 
			  --> son eleman : a[99]
			  --> a[100] : hata deðil, ancak diziye dahil deðil!!!
* a[expr] --> exp>= 0 && exp<size olmalýdýr
* derleyiciler index doðruluðunu compile time sýrasýnda kontrol edemez. Bu kontrol programcýnýn kontrolündedir. 
* Eðer diziye ait olmayan bir indexe eriþmek istenildiðinde --> undefined behaviour

* [] () . -> --> 1. Level Operators * 

int a[100];
int number = 20;
a[9] = number;
func(a[7]);
a[5] = 10; --> L-Value
++a[5];
&a[5];
~a[5]; // bitsel deðil operatorü

* dizi elemanlarý, bellekte birbiri ardýna sýralanarak saklanmaktadýr. 

int a[4];    --> bellekte tek blok altýnda saklanýr.
int x,y,z,t; --> bellekte tek blok altýnda saklanmaz.bu durumu garantiye almak için dizide saklanmalarý gerekmektedir. 

* If local arrays are not initialized, they have got garbage values. 
  - int a[100]; --> indetermined (garbage) value 
* If global arrays and static local arrays are not initialized, they have got zero values. 

/----------------------------------------------
/----------------------------------------------

- **Example**:

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 100 

int main() {
	int a[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		//...
	}
}
```

/----------------------------------------------
/----------------------------------------------

* Dizi boyutlarını belirleyen maksimum bir değer var mıdır? 

- Stack otomatik ömürlü değişkenlerin tutulduğu bellek alanıdır. 
- Static ömürlü varlıklar için ayrılan alan --> Data segment ? 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a[1'000'000'000] = {0};
	// Error C2148: total size of array must not exceed 0x7fffffff bytes	
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**:

* Array Decay --> Array to Pointer Conversion (C, C++)
- &a[0] --> R-Value Expression 
- Bir dizi ismi atama operatörünün sol operandı olamaz !!!

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a[100] = {0};
	int b[100] = {0};
	a = b; // Error	C2106 '=': left operand must be l - value	
}
```
/----------------------------------------------
/----------------------------------------------

- **Example**: The values of arrays defined in different scopes. 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5
int g_array[SIZE];

int main() {

	static int s_array[SIZE];

	for (int i = 0; i < SIZE; ++i)
		printf("static arrays[%d] : %d\n", i, s_array[i]);

	/* static arrays[0] : 0
	   static arrays[1] : 0
	   static arrays[2] : 0
	   static arrays[3] : 0
	   static arrays[4] : 0 */

	printf("\n\n");

	int l_array[SIZE];
	for (int i = 0; i < SIZE; ++i)
		printf("local arrays[%d] : %d\n", i, l_array[i]);

	/*  local arrays[0] : -858993460
		local arrays[1] : -858993460
		local arrays[2] : -858993460
		local arrays[3] : -858993460
		local arrays[4] : -858993460 */

	printf("\n\n");

	for (int i = 0; i < SIZE; ++i)
		printf("global arrays[%d] : %d\n", i, g_array[i]);

	/*  global arrays[0] : 0
		global arrays[1] : 0
		global arrays[2] : 0
		global arrays[3] : 0
		global arrays[4] : 0 */
}
```

/----------------------------------------------
/----------------------------------------------

* Warning ayarlarýnýn maksimuma çekilmesi nasýl saðlanmaktadýr ? 
- Deðiþkene ilk deðer vermemek deðil, ilk deðer vermeden kullanmak problem yaratmaktadýr. 

```c
int x;
prinff("x = %d\n", x);
for(x = 0; x< SIZE; ++x){};
```

- Bir deðiþkeni tanýmlarken ilk deðer vermek CPP için genel geçer kuraldýr. 
- CPP --> deðiþken tanýmý ilk deðer belirlendiðinde yapýlmalýdýr. 
- C --> tanýmlama yapýlýrken ilk deðer verilmeyebilir. Linux core kodlarýnda da kullanýmý bu þekildedir.

/----------------------------------------------
/----------------------------------------------

- Variable Length Array (VLA) : 
  - dizi indexlerinin dinamik olarak tanýmlanmasýný saðlayan araçtýr. 
  - C11 standartlarý ile bu araç opsiyonel hale getirildi. Yani derleyici bu araç için destek saðlayabilir ya da saðlamaz.
  - Bu araç Cpp'de tanýmlý olmadýðýndan hata verecektir. 
  - Normalde kullanýmý tercih edilmemelidir.
  - VS2019 C99 desteðini arttýðý için kullanýmý tercih edilmelidir.

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(int n) {
	int a[10] = {0};
	//...
	a[n] = 5; // C   --> VLA kullanýmý söz konusu
	          // CPP --> Error
}

int main() {

	int x = 10;
	int a[x];     // Error: expression must have a constant value

	const int n = 20;
	int array[n]; // Error : expression must have a constant value
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Compiler doesnt know the return value of function in compile time. That's why, the size of defined array can not be known in compile time either. 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int foo(void) {}

int main() {

	int a[10] = { 0 };
	//...
	a[foo()] = 5; // undefined behaviour --> depends on the function return value
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Array Initialization with {} 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

int main() {

	int array[5] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < SIZE; ++i)
		printf("arrays[%d] : %d\n", i, array[i]);

	/*  arrays[0] : 1
	    arrays[1] : 2
	    arrays[2] : 3
	    arrays[3] : 4
	    arrays[4] : 5 */
}
```

/----------------------------------------------
/----------------------------------------------

* Example: What happened if array initialization is provided with more than array size or less than array size? 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

int main() {

	// int array[5] = { 1, 2, 3, 4, 5, 6 }; // Compile time error
	// int array[SIZE] = { 1, 2, 3, }; // not error - trailing comma
	int array[SIZE] = { 1, 2, 3 }; 

	for (int i = 0; i < SIZE; ++i)
		printf("arrays[%d] : %d\n", i, array[i]);

	/*  arrays[0] : 1
	    arrays[1] : 2
	    arrays[2] : 3
	    arrays[3] : 0
	    arrays[4] : 0 */
}
```

/----------------------------------------------
/----------------------------------------------

* Example: 
  - Küme parantezinin içi C 'de boþ býrakýlamaz. 
  - CPP'de boþ býrakýlabilir. 
  - trailing comma kullanýmý dizi boyutunun belirlenmesinde etkili deðildir. 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

int main() {

	int array[SIZE] = { 0 }; // first index of array is assigned with 0 

	for (int i = 0; i < SIZE; ++i)
		printf("arrays[%d] : %d\n", i, array[i]);

	/*  arrays[0] : 0
	    arrays[1] : 0
	    arrays[2] : 0
	    arrays[3] : 0
	    arrays[4] : 0 */
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Specifying the length of array with initialization

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// int array[]; // Syntax Error - in local level
	int array[] = { 1, 2, 3 }; // array size is defined in compile time 
	int length = sizeof(array) / sizeof(array[0]);

	for (int i = 0; i < length; ++i)
		printf("arrays[%d] : %d\n", i, array[i]);

	/*  arrays[0] : 1
	    arrays[1] : 2
	    arrays[2] : 3 */
}
```

/----------------------------------------------
/----------------------------------------------

* Example: designated initializer (C++20)
  - designated initializer CPP için sýralý olarak verilmek zorundadýr

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

int main() {

	int array[SIZE] = { [1] = 59, [2] = 15, [3] = 10};
	for (int i = 0; i < SIZE; ++i)
		printf("arrays[%d] : %d\n", i, array[i]);

	/*  arrays[0] : 0
	    arrays[1] : 59
	    arrays[2] : 15
	    arrays[3] : 10
	    arrays[4] : 0 */
}
```

/----------------------------------------------
/----------------------------------------------

* Example: designated initializer (C++20)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int array[] = { [4] = 59, [5] = 15, [6] = 3 };
	int length = sizeof(array) / sizeof(array[0]);

	for (int i = 0; i < length; ++i)
		printf("arrays[%d] : %d\n", i, array[i]);

	/*  arrays[0] : 0
	    arrays[1] : 0
	    arrays[2] : 0
	    arrays[3] : 0
	    arrays[4] : 59
	    arrays[5] : 15
	    arrays[6] : 3 */
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Array initialization and compiler extentions 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x = 10, y = 20, z = 30, t = 40;
	int array[] = {x, y, z+t, t-x}; 
	// Normally it should be an error
	// However some compiler extensions provide this spec. (Ex. gcc)
	
	int length = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < length; ++i)
		printf("arrays[%d] : %d\n", i, array[i]);

	/*  arrays[0] : 10
	    arrays[1] : 20
	    arrays[2] : 70
	    arrays[3] : 30 */
}
```

/----------------------------------------------
/----------------------------------------------
