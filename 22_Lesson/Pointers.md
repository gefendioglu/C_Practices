
## POINTERS:

* Address - Pointers --> 
  - Deðiþkenler bellekte yer kaplamaktadýr.
  
  - Eðer bir ifade T bir tür olmak üzere, T türünden bir nesnenin adresi anlamýna geliyorsa,bu ifadenin türü C'de T* olarak gösterilmektedir. 
    int *, double *, char * 

  - p int* türünden bir deðiþkendir.
  - p  deðiþkeninin deðeri int türden bir nesnenin adresidir.
    int x = 10;
    int* ptr = &x;

  - Declarator kurallarý:
    * , [] --> declarator, they are not operators
    int* p1, p2, p3; --> sadece p1 pointer türündedir. p2 ve p3 int türündedir!!
	int *p1, *p2, *p3; --> olarak yazýlmalýdýr. 
    int x, a[5], *p1, y; --> sadece p1 pointer türündendir. 

  - static int* ptr; yerel deðiþkeni için deðer otomatik olarak 0 mý olurdu?
    özel bir adres deðeri ile hayata baþlar --> nullptr

  -  int*, double* vb. olmasýndan baðýmsýz olarak pointer'larýn bellekte kapladýklarý alan aynýdýr. Genellikle 4 byte 

  - pointer operatörleri ve öncelikleri: 
    1)  [], -> 
	  2)  &,  * 
	
	&  : address of operator
	*  : dereferencing operator - indirection operator
	[] : subscript operator - index operator
	-> : member selection operator - arrow operator
	user defined types ve structure konularýndan sonra arrow operator kullanýlacak

  - a & b : bit-wise AND
    &x    : address of operator
	compiler --> operatorün türünü operand sayýsýna bakarak anlar

  - x * y : multiplication
    * ptr : dereferencing operator 

  - pointerlar baþka deðiþkenlerin adresini tutarken; ayný zamanda kendisinin de bellekte bir adresi mevcuttur.
  - pointerlar kullanýlarak gösterilen deðiþkenlere eriþim olanaklýdýr. 

  - address operator kullanýlarak oluþturulan ifade --> R-Value kategorisindedir !!!!
   - Bir adres bilgisi aþaðýdaki ifadelerden biri olabilir:
     - ptr           (L-Value) --> assignment is available for L-Value cat. 
     - &x            (R-Value)
     - a             (L-Value  --> R-Value) the conversion is made by compiler automatically 
     - (int*)0x1AC4  (R-Value)

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : The size of data types and pointers 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	printf("sizeof(char)  = %zu\n", sizeof(char));      // sizeof(char)  = 1
	printf("sizeof(char*) = %zu\n", sizeof(char*));     // sizeof(char*) = 4
	printf("\n");
	
	printf("sizeof(short)  = %zu\n", sizeof(short));    // sizeof(short)  = 2
	printf("sizeof(short*) = %zu\n", sizeof(short*));   // sizeof(short*) = 4
	printf("\n");

	printf("sizeof(int)  = %zu\n", sizeof(int));        // sizeof(int)  = 4
	printf("sizeof(int*) = %zu\n", sizeof(int*));       // sizeof(int*) = 4
	printf("\n");

	printf("sizeof(double)  = %zu\n", sizeof(double));  // sizeof(double) = 8
	printf("sizeof(double*) = %zu\n", sizeof(double*)); // sizeof(double*) = 4
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x = 10;
	int* ptr = &x;
	printf("sizeof(ptr) = %zu\n", sizeof(ptr)); // sizeof(ptr) = 4
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : global, static local, local deðiþken scope larýnda yer alabilir. 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int* gptr;
void func(int* p) {}

int main() {
	int value = 10;
	int* ptr = &value;       // pointer to int, ptr points to x
	static double* sptr;     // pointer to double 
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : 
  - Address of Operator (&): 
    - Second level and from right to left priority
    - The operand of this operator must be L-Value.
    - If we want to check whether a value is a L-value or not, we can use address operator. 
      - If there is no syntax error --> L-Value
      - If there is a syntax error  --> R-Value

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int x = 10;
	double dval = 2.3;

	// &10 --> syntax error     -->  R-Value 
	// &x  --> not syntax error --> L-Value
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : Each data has a data type and value category. 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int ival1 = 10;
	int ival2 = 20;

	int* iptr = &ival1; // an initialization to initialize iptr
	* iptr = &ival2;    // an assignment to change iptr value 
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : 
  - address operator kullanýlarak oluþturulan ifade --> R-Value kategorisindedir !!!!
  - ek olarak, nesne adresinin deðiþtirilmesi mümkün deðildir. &ival1 = ival2; yazýlamaz. 
  - nesne adreslerinin hayata geldikten sonra bellekte deðiþmesi gibi bir durum söz konusu deðildir. 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int ival1 = 10;
	int ival2 = 20;
	&ival1 = ival2; // syntax error --> &ival1 : R-Value expression 
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : Assigning a pointer to the another pointer

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int ival1 = 10;
	int ival2 = 20;

	int* iptr1 = &ival1;
	int* iptr2 = &ival2;
	
	printf("iptr1 = %p\n", iptr1);  // iptr1 = 0133F930
	printf("iptr2 = %p\n", iptr2);  // iptr2 = 1992B532
	printf("\n");
	
	iptr2 = iptr1;
	printf("iptr1 = %p\n", iptr1);  // iptr1 = 0133F930
	printf("iptr2 = %p\n", iptr2);  // iptr2 = 0133F930
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : 
  - Tamsayý türünden adres türüne dönüþüm 
  - C'de yanlýþ ancak geçerli (not syntax error), otomatik olarak adres türüne dönüþüm gerçekleþir. 
  - CPP'de yanlýþ ve geçersiz (syntax error)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int ival1 = 10;
	int* iptr1 = &ival1;
	int* iptr2 = ival1;  // warning C4047: 'initializing': 'int *' differs in levels of indirection from 'int'

	printf("iptr1 = %p\n", iptr1);  // iptr1 = 0133F930
	printf("iptr2 = %p\n", iptr2);  // iptr2 = 10
	printf("\n");
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : 
  - Tamsayý türünden adres türüne dönüþüm farklý türde atama yapýlýrsa
  - C'de yanlýþ ancak geçerli (not syntax error)
  - CPP'de yanlýþ ve geçersiz (syntax error)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int ival1 = 10;
	double* iptr1 = &ival1;        // warning C4133: 'initializing': incompatible types - from 'int *' to 'double *'

	printf("iptr1 = %p\n", iptr1); // iptr1 = 0133F930
	printf("\n");
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** :

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int ival1 = 10;
	int* iptr1 = &ival1;

	printf("&ival1 = %p\n", &ival1);  // &ival1 = 00B3F9EC
	printf("iptr1  = %p\n",  iptr1);  // iptr1  = 00B3F9EC
	printf("&iptr1 = %p\n", &iptr1);  // &iptr1 = 00B3F9E0
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int ival1 = 10;
	int* iptr1 = &ival1;
	int* iptr2 = iptr1;

	printf("&ival1 = %p\n", &ival1);  // &ival1 = 012FFA34
	printf("iptr1  = %p\n",  iptr1);  // iptr1  = 012FFA34
	printf("iptr2  = %p\n",  iptr2);  // iptr2  = 012FFA34
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** :  
  - &&ival --> öncelik yönü saðdan sola --> &(&ival) --> not L-Value cat.
  - bu tarz bir kullaným söz konusu deðildir --> adresin adresi þeklinde bir kavram yoktur. 
  - normal deðiþkene adres verisi  atamak --> int iptr1 = &ival1;
    - C'de yanlýþ ancak geçerli (not syntax error)
    - CPP'de yanlýþ ve geçersiz (syntax error)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int ival1 = 10;
	int iptr1 = &ival1;
	printf("iptr1  = %p\n",  iptr1);  // iptr1  = 00DFFBDC
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : Array decay (array to pointer conversion)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int arr[10] = { 0 };
	int* ptr = arr; // --> arr = &arr[0]

	printf("&arr[0] = %p\n", &arr[0]); // &arr[0] = 008FF760
	printf("arr     = %p\n", arr);     // arr     = 008FF760
	printf("ptr     = %p\n", ptr);     // ptr     = 008FF760
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : The definitions of different types of variables, pointers

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// int value = 10, *ptr1 = &value, arr[] = { 1,2,3 }, *ptr2 = arr;
	int value = 10;
	int* ptr1 = &value;
	int  arr[]  = { 1,2,3 };
	int* ptr2 = arr;
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : 
  - The sizeof operator and array to pointer conversion
  - array to pointer conversion is not available for sizeof operator
  
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int arr[10] = { 0 };
	printf("sizeof(arr)     = %zu\n", sizeof(arr));      // sizeof(arr)     = 40
	printf("sizeof(&arr[0]) = %zu\n", sizeof(&arr[0]));  // sizeof(&arr[0]) = 4 
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : 
   - *ptr --> unary prefix operator
   - operandý adres olmak zorundadýr!!
   - dereferencing operator ile oluþturulan bir ifade L-Value ifadesidir!!!
   - *adres --> bu adreste yer alan nesneyi ifade eder. 
   - indirect olarak nesneye eriþmeye saðladýðý için --> indirect operator

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int arr[10] = { 0 };
	int value = 10;
	int* ptr = &value;
	
	*arr;     // not syntax error 
	*value;   // syntax error
	*&value;  // not syntax error
	*ptr;     // not syntax error
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** :

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int arr[10] = { 0 };
	int value = 10; // value --> *(&value) 
	int* ptr = &value;
	
	printf("value     = %d\n", value);     // value     = 10
	printf("*(&value) = %d\n", *(&value)); // *(&value) = 10 
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int arr[10] = { 0 };
	int value = 10;   // value --> *(&value) 
	
	printf("value     = %d\n", value);     // value     = 10
	printf("*(&value) = %d\n", *(&value)); // *(&value) = 10
	printf("\n");

	*(&value) = 99;
	printf("value     = %d\n", value);     // value     = 99
	printf("*(&value) = %d\n", *(&value)); // *(&value) = 99
	printf("\n");

	++*(&value);
	printf("value     = %d\n", value);     // value     = 100
	printf("*(&value) = %d\n", *(&value)); // *(&value) = 100
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** :

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a[] = { 1,2,4 };
	printf("a[0] = %d\n", a[0]);  // a[0] = 1
	
	*a = 90; // *a --> a[0] = 90;
	printf("a[0] = %d\n", a[0]);  // a[0] = 90
}
```

/ ----------------------------------------------
/ ----------------------------------------------

 **Example** : 
   - ptr  --> pointer
   - *ptr --> pointee (gösterilen nesne)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int value = 89;
	int* ptr = &value;
	printf("value = %d\n", value); // value = 89

	*ptr = 79;
	printf("value = %d\n", value); // value = 79
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : pointee example

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int value1 = 10;
	int value2 = 56;
	int* ptr1 = &value1;
	int* ptr2 = &value2;

	printf("* ptr1 = %d\n", *ptr1);  // * ptr1 = 10
	printf("* ptr2 = %d\n", *ptr2);  // * ptr2 = 56

	*ptr1 = *ptr2; // value1 = value2 
	printf("* ptr1 = %d\n", *ptr1);  // * ptr1 = 56
	printf("* ptr2 = %d\n", *ptr2);  // * ptr2 = 56
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : 
  - arithmetic operations with pointees 
  - the same address of variables can be taken by a few different pointers

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int value = 10;
	int* ptr1 = &value;
	int* ptr2 = ptr1;
	int* ptr3 = ptr2;

	printf("* ptr1 = %d\n", *ptr1);  // * ptr1 = 10
	printf("* ptr2 = %d\n", *ptr2);  // * ptr2 = 10
	printf("* ptr3 = %d\n", *ptr3);  // * ptr3 = 10

	++* ptr1;
	++* ptr2;
	++* ptr3;

	printf("* ptr1 = %d\n", *ptr1);  // * ptr1 = 13
	printf("* ptr2 = %d\n", *ptr2);  // * ptr2 = 13
	printf("* ptr3 = %d\n", *ptr3);  // * ptr3 = 13
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** :
  - arithmetic operations with pointees
  - the address of different variables can be taken by the same pointer


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int value1 = 10;
	int value2 = 40;
	int value3 = 90;
	int* ptr1;

	ptr1 = &value1;
	*ptr1 = 99;

	ptr1 = &value2;
	*ptr1 = 99;

	ptr1 = &value3;
	*ptr1 = 99;

	printf("value1 = %d\n", value1);  // value1 = 99
	printf("value2 = %d\n", value2);  // value2 = 99
	printf("value3 = %d\n", value3);  // value3 = 99
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : arithmetic operations with pointees, but not initialized variables

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int value1;
	int value2;

	int* ptr1 = &value1; 
	ival2 = *ptr1 + 5; // *ptr --> garbage value, undefined behaviour

	printf("value1 = %d\n", value1);  // value1 = -858993460
	printf("value2 = %d\n", value2);  // value2 = -858993455
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : The same example like as previous one, but with global variable (or static local variable)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int value1;

int main() {
	int value2;

	int* ptr1 = &value1; 
	value2 = *ptr1 + 5; // *ptr --> 0,  not undefined behaviour

	printf("value1 = %d\n", value1);  // value1 = 0
	printf("value2 = %d\n", value2);  // value2 = 5
}
```

/ ----------------------------------------------
/ ----------------------------------------------

Pointerlar niçin kullanýlmaktadýr?
   - call by value - call by reference kullanýmýný saðlamak amacýyla 
   - scanf fonksyionunda olduðu gibi --> parametre olarak pointer alýnýr

**Example** : call by value: the argument sent to a function is not changed !!!

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(int x) { 
	x = 9999;
}

int main() {
	int value = 60;
	func(value);
	printf("value = %d\n", value); // value = 60
}
```

**Example** : call by reference: the argument sent to a function is changed !!!

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(int *x) {
	// x is the address of "val"
	*x = 9999;
}

int main() {
	int val = 60;
	func(&val);
	printf("val = %d\n", val);  // val = 9999
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : Defining a function called scan_int similar as scanf

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void scan_int(int* ptr) {
	int ch;
	*ptr = 0;

	while ((ch = getchar()) != '\n') {
		*ptr = (*ptr * 10) + ch - '0'; // the digit value is found !!
	}
}

int main() {

	int value = 60;
	printf("Enter a number = "); 
	scan_int(&value);

	printf("value = %d\n", value);

	/*
	   Enter a number =  5612
    	   value = 5612
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : Defining swap function with call by value. Variables are not swapped !!!

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int first_value, int second_value) {
	int temp = first_value;
	first_value = second_value;
	second_value = temp;
}

int main() {
	int value1 = 10;
	int value2 = 45;
	swap(value1, value2);

	printf("value1 = %d\n", value1);  // value1 = 10
	printf("value2 = %d\n", value2);  // value2 = 45
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : Defining swap function with call by reference. Variables are swapped !!!

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int *first_value, int *second_value) {
	int temp = *first_value;
	*first_value = *second_value;
	*second_value = temp;
}

int main() {
	int value1 = 10;
	int value2 = 45;
	swap(&value1, &value2);

	printf("value1 = %d\n", value1);  // value1 = 45 
	printf("value2 = %d\n", value2);  // value2 = 10
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : Defining swap function with call by reference and arrays. 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int *first_value, int *second_value) {
	int temp = *first_value;
	*first_value = *second_value;
	*second_value = temp;
}

int main() {
	int a[] = { 1, 2, 3 };
	int b[] = { -1,-2,-3 };
	swap(a, b); // --> swap(&a[0], &b[0]);

	printf("a[0] = %d\n", a[0]);  // a[0] = -1
	printf("b[0] = %d\n", b[0]);  // b[0] = 1
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : Defining swap function with call by reference and pointers. 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int *first_value, int *second_value) {
	int temp = *first_value;
	*first_value = *second_value;
	*second_value = temp;
}

int main() {
	int value1 = 23;
	int value2 = 87;
	int* ptr1 = &value1;
	int* ptr2 = &value2;

	swap(ptr1, ptr2);  // --> swap(&value1, &value2);
	
	printf("value1 = %d\n", value1);  // value1 = 87
	printf("value2 = %d\n", value2);  // value2 = 23
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : Pointers with function (call by value and call by reference methods)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func3(int y) {
	y *= 10;
}
void func2(int *p) {
	*p *= 5;
}

void func1(int *ptr) {
	f2(ptr);
	f3(*ptr); // call-by value
}

int main() {
	int value = 10;
	func1(&value);

	printf("value = %d\n", value);  // value = 50 --> because, func3 iscall by value
}
```

/ ----------------------------------------------
/ ----------------------------------------------

- Neden call by reference kullanýlmaktadýr?
   - öyle fonksiyonlar vardýr ki bunlarýn varlýk nedeni bir deðeri hesaplamak ve hesapladýklarý deðeri, kendilerini çaðýran koda iletmektir. return value dýþýnda call by reference ile de nesne için yeni hesaplanan deðer döndürülmektedir. 
   - büyük boyutlu verilerin foksiyonlara argüman olarak gönderilmesinde maliyeti azaltýr. 
   
**Example** :

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double get_sum_square(int a, int b) {
	double value = a * a + b * b;
	return sqrt(value);
}

int main() {
	int value1, value2;
	double dvalue;

	printf("Two numbers = " );
	scanf("%d %d",  &value1, &value2);

	dval = get_sum_square(value1, value2);
	printf("dvalue = %f\n", dvalue);

	/*
	   Two numbers = 23 45
	   dvalue = 50.537115	
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : TO BE CONTROLLED !!!

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void get_sum_square(int a, int b, int *c) {
	double value = a * a + b * b;
	*c =  sqrt(value);
}

int main() {
	int value1, value2;
	double dvalue;

	printf("Two numbers = " );
	scanf("%d %d", &value1, &value1);

	get_sum_square(value1, value2, &dvalue);
	printf("dvalue = %f\n", dvalue);

	/*
	   Two numbers = 23 45
	   dvalue = 50.537115	
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double get_sum_square(int a, int b) {
	double value = a * a + b * b;
	return  sqrt(value);
}

int main() {
	int value1 = 23, value2 = 45;
	double dvalue;

	dvalue = get_sum_square(value1, value2);
	printf("dvalue = %f\n", dvalue); // dvalue = 50.537115

	// double gn = sqrt(value);
	// dvalue = gn;
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : The size of struct data type 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Matrix {
	int a[10][20];
	int row, col;
};

int main() {
	printf("sizeof(struct Matrix) = %zu\n", sizeof(struct Matrix));  // sizeof(struct Matrix) = 808
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : TO BE CONTROLLED !!!

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct  {
	int a[10][20];
	int row, col;
}Matrix;

Matrix add_matrix(Matrix a, Matrix b);

// tercih edilmesi gereken yapý budur
void add_matrix_ptr(Matrix a, Matrix b, Matrix* c) {}

int main() {
	Matrix val1, val2, val3;
	Matrix* ptr;

	val1 = add_matrix(val2, val3);
	printf("sizeof(val1) = %zu\n", sizeof(val1));

	add_matrix_ptr(val2, val3, ptr);
	printf("sizeof(val1) = %zu\n", sizeof(val1));
}
```

/ ----------------------------------------------
/ ----------------------------------------------

