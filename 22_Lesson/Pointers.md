
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

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char* sgets(char* ptr) {
	char c;
	char* ptemp = ptr;
	while ((c = (char)getchar()) != '\n')
		*ptr++ = c;

	*ptr = '\0';
	return ptemp;
}

#define SIZE 100

int main() {

	printf("sizeof(char) = %zu\n", sizeof(char));
	printf("sizeof(char*) = %zu\n", sizeof(char*));
	printf("\n");
	
	printf("sizeof(short) = %zu\n", sizeof(short));
	printf("sizeof(short*) = %zu\n", sizeof(short*));
	printf("\n");

	printf("sizeof(int) = %zu\n", sizeof(int));
	printf("sizeof(int*) = %zu\n", sizeof(int*));
	printf("\n");

	printf("sizeof(double) = %zu\n", sizeof(double));
	printf("sizeof(double*) = %zu\n", sizeof(double*));

    /*
	sizeof(char) = 1
	sizeof(char*) = 4

	sizeof(short) = 2
	sizeof(short*) = 4

	sizeof(int) = 4
	sizeof(int*) = 4

	sizeof(double) = 8
	sizeof(double*) = 4 */
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 100

int main() {

	int x = 10;
	int* ptr = &x;
	printf("sizeof(ptr) = %zu\n", sizeof(ptr));
	/*sizeof(ptr) = 4*/
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

	int x = 10;
	int* ptr = &x;       // pointer to int, ptr points to x
	static double* sptr; // pointer to double 
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : 
* Address of Operator (&):
  - 2. öncelik seviyesinde ve saðdan sola öncelik 
  - the operand of address operators must be L-Value.
  - to test whether the value is L-value or not --> adres operatorü kullanýlarak check yapýlýr. Syntax hatasý olmazsa --> Lvalue

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x = 10;
	double dval = 2.3;

	// &10 --> syntax error
	// &x --> not syntax error --> L-Value
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : her ifadenin bir türü (data type) ve deðer kategorisi (value category ) vardýr:

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int ival1 = 10;
	int ival2 = 2.3;

	int* iptr = &ival1; // initialization to initialize iptr
	* iptr = &ival2;    // assignment to change iptr value 
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : 
  - address operator kullanýlarak oluþturulan ifade --> R-Value kategorisindedir !!!!
  - ek olarak, nesne adresinin deðiþtirilmesi mümkün deðildir. 
     &ival1 = ival2; yazýlamaz. 
  - nesne adreslerinin hayata geldikten sonra bellekte deðiþmesi gibi bir durum söz konusu deðildir. 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int ival1 = 10;
	int ival2 = 20;
	&ival1 = ival2; // syntax error --> &ival1 R-Value expression 
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
	int ival2 = 20;

	int* iptr1 = &ival1;
	int* iptr2 = &ival2;
	
	printf("iptr1 = %p\n", iptr1);
	printf("iptr2 = %p\n", iptr2);
	printf("\n");
	iptr2 = iptr1;

	printf("iptr1 = %p\n", iptr1);
	printf("iptr2 = %p\n", iptr2);
	
	/*
	iptr1 = 19922532
	iptr2 = 19922520

	iptr1 = 19922532
	iptr2 = 19922532
	*/
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
	int* iptr2 = ival1; 
	// warning C4047: 'initializing': 'int *' differs in levels of indirection from 'int'

	printf("iptr1 = %p\n", iptr1);
	printf("iptr2 = %p\n", iptr2);
	printf("\n");
	
	/*
		iptr1 = 12581484
		iptr2 = 10
	*/
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
	double* iptr1 = &ival1;
	// warning C4133: 'initializing': incompatible types - from 'int *' to 'double *'

	printf("iptr1 = %p\n", iptr1);
	printf("\n");
	
	/*
		iptr1 = 0133F930
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : %p pointer yazdýrmak için kullanýlýr

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int ival1 = 10;
	int* iptr1 = &ival1;

	printf("&ival1 = %p\n", &ival1);
	printf("iptr1  = %p\n",  iptr1);
	printf("&iptr1 = %p\n", &iptr1);
	printf("\n");
	
	/*
		&ival1 = 00B3F9EC
		iptr1  = 00B3F9EC
		&iptr1 = 00B3F9E0
	*/
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

	printf("&ival1 = %p\n", &ival1);
	printf("iptr1  = %p\n",  iptr1);
	printf("iptr2  = %p\n",  iptr2);
	printf("\n");
	
	/*
		&ival1 = 012FFA34
		iptr1  = 012FFA34
		iptr2  = 012FFA34

	*/
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
	printf("iptr1  = %p\n",  iptr1);
	printf("\n");
	
	/*
		iptr1  = 00DFFBDC
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : Array decay (array to pointer conversion)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int a[10] = { 0 };
	int* ptr = a; // --> a = &a[0]

	printf("&a[0] = %p\n", &a[0]);
	printf("a     = %p\n", a);
	printf("ptr   = %p\n", ptr);
	printf("\n");
	
	/*
		&a[0] = 008FF760
		a     = 008FF760
		ptr   = 008FF760
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** :
  - int x = 10, * p1 = &x, a[] = { 1,2,3 }, * p2 = a;
	  int x = 10;
	  int* p1 = &x;
	  int  a[] = { 1,2,3 };
	  int* p2 = a;

/ ----------------------------------------------
/ ----------------------------------------------

 * Bir adres bilgisi aþaðýdaki ifadelerden biri olabilir:
   - ptr           (L-Value) --> sadece buna atama yapýlabilir. 
     &x            (R-Value)
	   a             (L-Value  --> R-Value) derleyici tarafýndan dönüþüm yapýlýr. 
	   (int*)0x1AC4  (R-Value)

/ ----------------------------------------------
/ ----------------------------------------------

**Example** :sizeof operator and array to pointer conversion

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int a[10] = { 0 };
	printf("sizeof(a) = %zu\n", sizeof(a));
	printf("sizeof(&a[0]) = %zu\n", sizeof(&a[0])); 
	// array to pointer conversion sizeof operatorü için geçerli deðildir
	
	/*
		sizeof(a) = 40
		sizeof(&a[0]) = 4 
	*/
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

	int a[10] = { 0 };
	int x = 10;
	int* ptr = &x;
	
	*a;   // not syntax error 
	*x;   // syntax error
	*&x;  // not syntax error
	*ptr; // not syntax error
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : obfuscatiton 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int a[10] = { 0 };
	int x = 10;   // x --> *(&x) 
	int* ptr = &x;
	
	printf("x     = %d\n", x);
	printf("*(&x) = %d\n", *(&x));

	/*
		x     = 10
		*(&x) = 10
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int a[10] = { 0 };
	int x = 10;   // x --> *(&x) 
	
	printf("x     = %d\n", x);
	printf("*(&x) = %d\n", *(&x));
	printf("\n");

	*(&x) = 99;
	printf("x     = %d\n", x);
	printf("*(&x) = %d\n", *(&x));
	printf("\n");

	++*(&x);
	printf("x     = %d\n", x);
	printf("*(&x) = %d\n", *(&x));

	/*
		x     = 10
		*(&x) = 10

		x     = 99
		*(&x) = 99

		x     = 100
		*(&x) = 100
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** :: 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int a[] = { 1,2,4 };
	
	printf("a[0] = %d\n", a[0]);
	*a = 90; // *a --> a[0] = 90;
	printf("a[0] = %d\n", a[0]);

	/*
	a[0] = 1
    a[0] = 90

	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

 **Example** : 
   - ptr  --> pointer
   - *ptr --> pointee (gösterilen nesne anlamýnda)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int ival = 89;
	int* ptr = &ival;
	printf("ival = %d\n", ival);

	*ptr = 79;
	printf("ival = %d\n", ival);

	/*
	 ival = 89
     ival = 79
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : pointee example

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int ival1 = 10;
	int ival2 = 56;
	int* ptr1 = &ival1;
	int* ptr2 = &ival2;

	printf("* ptr1 = %d\n", *ptr1);
	printf("* ptr2 = %d\n", *ptr2);

	*ptr1 = *ptr2; // ival1 = ival2 

	printf("* ptr1 = %d\n", *ptr1);
	printf("* ptr2 = %d\n", *ptr2);

	/*
		* ptr1 = 10
		* ptr2 = 56

		* ptr1 = 56
		* ptr2 = 56
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : arithmetic operations with pointees 
   - ayný deðiþken adresinin birden fazla pointer tarafýndan tutulmasý

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int ival1 = 10;
	int* ptr1 = &ival1;
	int* ptr2 = ptr1;
	int* ptr3 = ptr2;

	printf("* ptr1 = %d\n", *ptr1);
	printf("* ptr2 = %d\n", *ptr2);
	printf("* ptr3 = %d\n", *ptr3);

	++* ptr1;
	++* ptr2;
	++* ptr3;

	printf("* ptr1 = %d\n", *ptr1);
	printf("* ptr2 = %d\n", *ptr2);
	printf("* ptr3 = %d\n", *ptr3);

	/*
		* ptr1 = 10
		* ptr2 = 10
		* ptr3 = 10

		* ptr1 = 13
		* ptr2 = 13
		* ptr3 = 13
	*/
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
	int ival2 = 40;
	int ival3 = 90;
	int* ptr1;

	ptr1 = &ival1;
	*ptr1 = 99;

	ptr1 = &ival2;
	*ptr1 = 99;

	ptr1 = &ival3;
	*ptr1 = 99;

	printf("ival1 = %d\n", ival1);
	printf("ival2 = %d\n", ival2);
	printf("ival3 = %d\n", ival3);


	/*
		ival1 = 99
		ival2 = 99
		ival3 = 99
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** :

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int ival1;
	int ival2;

	int* ptr1 = &ival1; 
	ival2 = *ptr1 + 5; // *ptr --> garbage value / ub

	printf("ival1 = %d\n", ival1);
	printf("ival2 = %d\n", ival2);

	/*
		ival1 = -858993460
		ival2 = -858993455
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : the same example, but with global value (or static local)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ival1;

int main() {

	int ival2;

	int* ptr1 = &ival1; 
	ival2 = *ptr1 + 5; // *ptr --> 0 / not ub

	printf("ival1 = %d\n", ival1);
	printf("ival2 = %d\n", ival2);

	/*
		ival1 = 0
		ival2 = 5
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : Pointerlar niçin kullanýlmaktadýr?
   - call by value - call by reference kullanýmýný saðlamak amacýyla 
   - scanf fonksyionunda olduðu gibi --> parametre olarak pointer alýnýr

- call by value: nesne deðeri deðiþmez

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(int x) {
	x = 9999;
}

int main() {

	int ival1 = 60;
	func(ival1);
	printf("ival1 = %d\n", ival1);

	/*
		ival1 = 60
	*/
}
```

- call by reference: nesne deðeri deðiþir 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(int *x) {
	// x'in deðeri ival'in adresi olacaktýr
	*x = 9999;
}

int main() {

	int ival1 = 60;
	func(&ival1);
	printf("ival1 = %d\n", ival1);

	/*
		ival1 = 9999
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : scanf benzeri örnek 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void scanint(int* ptr) {
	int ch;
	*ptr = 0;

	while ((ch = getchar()) != '\n') {
		*ptr = (*ptr * 10) + ch - '0'; // basamak deðeri elde edilir. 
	}
}

int main() {

	int ival = 60;
	printf("A number = ");
	scanint(&ival);

	printf("ival = %d\n", ival);

	/*
		A number = 5612
		ival = 5612
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : call by value old. --> swap fonk verilmese bile gönderilen deðerler deðiþmez. 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {

	int ival1 = 10;
	int ival2 = 45;
	swap(ival1, ival2);

	printf("ival1 = %d\n", ival1);
	printf("ival2 = %d\n", ival2);

	/*
		ival1 = 10
		ival2 = 45
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : the same problem, but with call by reference. Values are swapped !!!

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {

	int ival1 = 10;
	int ival2 = 45;
	swap(&ival1, &ival2);

	printf("ival1 = %d\n", ival1);
	printf("ival2 = %d\n", ival2);

	/*
		ival1 = 45
		ival2 = 10
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : swap function with arrays 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {

	int a[] = { 1, 2, 3 };
	int b[] = { -1,-2,-3 };
	swap(a, b); // swap(&a[0], &b[0]);

	printf("a[0] = %d\n", a[0]);
	printf("b[0] = %d\n", b[0]);

	/*
		a[0] = -1
		b[0] = 1
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : pointers with swap function

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {

	int ival1 = 23;
	int ival2 = 87;
	int* ptr1 = &ival1;
	int* ptr2 = &ival2;

	swap(ptr1, ptr2);  // --> swap(&ival1, &ival2);

	printf("ival1 = %d\n", ival1);
	printf("ival2 = %d\n", ival2);

	/*
		ival1 = 87
		ival2 = 23
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : pointers with function (call by value and call by reference methods)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void f3(int y) {
	y *= 10;
}
void f2(int *p) {
	*p *= 5;
}

void f1(int *ptr) {
	f2(ptr);
	f3(*ptr); // call-by value
}

int main() {
	
	int ival1 = 10;
	f1(&ival1);

	printf("ival1 = %d\n", ival1);

	/*
		ival1 = 50 // f3 call by value old
	*/
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
	
	int ival1, ival2;
	double dval;

	printf("Two numbers = " );
	scanf("%d %d",  &ival1, &ival2);

	dval = get_sum_square(ival1, ival2);
	printf("dval = %f\n", dval);

	/*
		Two numbers = 23 45
		dval = 50.537115	
		
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : KONTROL EDÝLECEK !!!

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void get_sum_square(int a, int b, int*c) {
	
	double value = a * a + b * b;
	*c =  sqrt(value);
}

int main() {
	
	int ival1, ival2;
	double dval;

	printf("Two numbers = " );
	scanf("%d %d",  &ival1, &ival2);

	get_sum_square(ival1, ival2, &dval);
	printf("dval = %f\n", dval);

	/*
		Two numbers = 23 45
		dval = 50.537115	
		
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
	
	int ival1 = 23, ival2 = 45;
	double dval;

	dval = get_sum_square(ival1, ival2);
	printf("dval = %f\n", dval);

	// double gn = sqrt(value);
	// dval = gn;

	/*
		dval = 50.537115	
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : struct size 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Matrix {
	int a[10][20];
	int row, col;
};

int main() {
	
	printf("sizeof(struct Matrix) = %zu\n", sizeof(struct Matrix));
	/*
		sizeof(struct Matrix) = 808	
	*/
}
```

/ ----------------------------------------------
/ ----------------------------------------------

**Example** : DÜZENLENECEK - KONTROL EDÝLECEK!! 

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
void add_matrix_ptr(Matrix a, Matrix b, Matrix* c) {

}

int main() {
	Matrix x, y, z;
	Matrix* ptr;

	x = add_matrix(y, z);
	printf("sizeof(x) = %zu\n", sizeof(x));

	add_matrix_ptr(y, z, ptr);
	printf("sizeof(x) = %zu\n", sizeof(x));
}
```

/ ----------------------------------------------
/ ----------------------------------------------

