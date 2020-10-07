## ALGORITHMS :

- The complexity of algorithm depends on 
  - the compiler optimization
  - the special commands of operating system 
  - the placement of data items 
- The benchmarking criteria can be time or space. However, time is dependent on hardware, the optimization capability of compiler and the amount of data size.
- Generally, the following three different case are used for benchmarking:   
  - best case
  - average case
  - worst case   

-Big O Notation: 
 - It is used to specify the algorithm complexity
 - It is the measurement of the relation between the data and cost  
   - constant time algorithm --> the constant relation between data size and cost
   - linear complexity       --> the linear relation between data size and cost
   - square complexity       --> verideki eleman sayısının karesi ile maliyetin orantılı olarak artması 

/----------------------------------------------
/----------------------------------------------

- O(1)     :  constant time algorithm 
- O(logn)  : logaritma 2 tabanýnda orantýlý complexity (low complexity)
           : algoritmada sürekli ikiye bölme durumu söz konusu ise (ex: binary search algorithm)
- O(n)     : linear complexity (n veri sayýsý - O(c*n) c constant olarak düþünülebilir.)
	   : c farklý katsayýlar olsa bile O(n) ile belirtilir.
- O(nlogn) 
- O(n^2)   : karesi ile orantýlý complexity 
           : iç içe iki döngü varsa ve her bir döngü verideki eleman sayýsý kadar dönüyorsa 
- O(n^3)   : complexity in proportion to the cube of data  
- O(2^n)   : high complexity 
- O(n!)    : high complexity 

- bir dizide belli bir elemana ulaþmak her zaman constnt complexity (O(1))
- dizideki eleman sayýsýnýn artmasý ölçüsünde worst case artýyorsa linear (O(n))
- bir dizinin tersine çevrilmesi probleminde her defasýnda dizinin baþtaki deðeri ile sonda kendi indisine denk gelen deðerin yerinin deðiþtirilmesi gerekmektedir. Dizinin yarýsý oranýnda iþlem gerçekleþtirilir. Dolayýsýyla dizideki eleman sayýsý arttýkça  iþlem sayýsý doðru orantýlý olarak artacaktýr --> linear complexity (O(n))
- farklý adýmlardan oluþan algoritmalar için, complexity deðeri en yüksek olan adým ile tüm algoritmanýn karmaþýklýðý temsil edilir. 

/----------------------------------------------
/----------------------------------------------

Veri yapýsý üzerinde yapýlan en temel iþlemler: 
- Insertion / Eraser iþlemleri
- dinamik diziye sondan yapýlan ekleme/silme iþlemleri --> constant complexity 
- dinamik dizinin herhangi bir noktasýndan yapýlan ekleme silme iþlemleri --> linear comp.
- dinamik dizi üretimde en fazla kullanýlan veri yapýsýdýr. 
- C deki dizi yapýsý  dinamik diiz yapýsý ile ayný; ancak diziye ekleme ve silme iþlemi uygulanamaz. Bunlar fixed array olarak isimlendirilir. dizinin hayatý devam ettði sürece "size"  ayný kalacaktýr.
- Eðer C'de dinamik dizi oluþturulmak istenirse 

/----------------------------------------------
/----------------------------------------------

* Example: 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10

void dline(void) {
	printf("\n-----------------------------------------------------\n");
}

void randomize(void) {
	srand((unsigned int)time(NULL));
}

void set_random_array(int *ptr, int size)
{
	while (size--) {
		*ptr++ = rand() % 1000;
	}
}

void print_array(const int *ptr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (i && i % 20 == 0)
			printf("\n");
		printf("%3d ", ptr[i]);
	}
	dline();
}

int main() {
	int a[SIZE];
	
	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);
	// 463 300 523 225 432 682 348 551 629 607
}
```

/----------------------------------------------
/----------------------------------------------

* Example: 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define SIZE 10

void dline(void) {
	printf("\n-----------------------------------------------------\n");
}

void randomize(void) {
	srand((unsigned int)time(NULL));
}

void set_random_array(int *ptr, int size)
{
	while (size--) {
		*ptr++ = rand() % 1000;
	}
}

void print_array(const int *ptr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (i && i % 20 == 0)
			printf("\n");
		printf("%3d ", ptr[i]);
	}
	dline();
}

int main() {

	int a[SIZE];
	int sum = 0;
	double mean;
	double sum_square = 0;
	double std_dev;

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	// The sum of data elements
	for (int i = 0; i < SIZE; ++i) // O(n)
	{
		sum += a[i];
	}
	printf("sum  : %d\n", sum);

	// The mean value of data elements 
	mean = (double)sum / SIZE;
	printf("mean : %f\n", mean);

	// standard deviation
	for (int i = 0; i < SIZE; ++i)  // O(n)
	{
		sum_square += (a[i] - mean)* (a[i] - mean);
	}

	std_dev = sqrt(sum_square / SIZE);
	printf("standard deviation : %f\n", std_dev);

	/* 
	The complexity of all  algorithm --> O(n)
	449 349 369 977 379 254 700  50 467 155
	-----------------------------------------------------
	sum  : 4149
	mean : 414.900000
	standard deviation : 252.079928
	*/
}
```

/----------------------------------------------
/----------------------------------------------

* Example: 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define SIZE 10

void dline(void) {
	printf("\n-----------------------------------------------------\n");
}

void randomize(void) {
	srand((unsigned int)time(NULL));
}

void set_random_array(int *ptr, int size)
{
	while (size--) {
		*ptr++ = rand() % 1000;
	}
}

void print_array(const int *ptr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (i && i % 20 == 0)
			printf("\n");
		printf("%3d ", ptr[i]);

	}
	dline();
}

// Linear Search Algorithm
int main() {
	int a[SIZE];
	int value;
	int flag = 0;
	int i; 

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	printf("Enter a number : ");
	scanf("%d", &value);

	for (i = 0; i < SIZE; ++i) 
	{
		if (a[i] == value) {
			flag = 1;
			break;
		}
	}
	
	if (flag)
		printf("Found !!! The array index is: %d \n", i);
	else
		printf("Not Found !!! \n");

	// Test code: Found
	/*
		896 533 109 657 216  92 260 987 838 305
		---------------------------------------------------- -
		Enter a number : 216
		Found !!!The array index is : 4
	*/

	// The complexity of algorithm : O(n)
	// Test code: Not Found
	/*
		85 348 655  73 637 466 942  45 238 165
		---------------------------------------------------- -
		Enter a number : 12
		Not Found !!!

	*/
}
```

/----------------------------------------------
/----------------------------------------------

* Example: The same example, but not using flag to control whether we are out of the for loop ot not !!!

```c
// Linear Search Algorithm
int main() {

	int a[SIZE];
	int value;
	int i; 

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	printf("Enter a number : ");
	scanf("%d", &value);

	for (i = 0; i < SIZE; ++i) 
	{
		if (a[i] == value) {
			break;
		}
		
	}
	if (i < SIZE)
		printf("Found !!! The array index is: %d \n", i);
	else
		printf("Not Found !!! \n");
}
```

/----------------------------------------------
/----------------------------------------------

* Example: The same example, but with optimized for-loop

```c
// Linear Search Algorithm
int main() {

	int a[SIZE];
	int value;
	int i; 

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	printf("Enter a number : ");
	scanf("%d", &value);

	for (i = 0; i < SIZE && a[i] != value; ++i)
		; // null statement

	if (i < SIZE)
		printf("Found !!! The array index is: %d \n", i);
	else
		printf("Not Found !!! \n");
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Dizide ayný deðerden kaç tane olduðunu bulma 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 100

void dline(void) {
	printf("\n-----------------------------------------------------\n");
}

void randomize(void) {
	srand((unsigned int)time(NULL));
}

void set_random_array(int *ptr, int size)
{
	while (size--) {
		*ptr++ = rand() % 100;
	}
}

void print_array(const int *ptr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (i && i % 20 == 0)
			printf("\n");
		printf("%3d ", ptr[i]);

	}
	dline();
}

// Linear Search Algorithm
int main() {

	int a[SIZE];
	int value;
	int i; 
	int counter = 0;

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	printf("Enter a number : ");
	scanf("%d", &value);


	for (i = 0; i < SIZE; ++i)
	{
		if (a[i] == value) {
			printf("The index of value : a[%d]\n", i);
			++counter;
		}

	}

	if (counter)
		printf("The total count : %d \n", counter);
	else 
		printf("Not Found !!! \n");

	/*
	10  14  41  62  14  81  22  67  53  20  91  57  19  14  95  47  70  28  98  86
	46  71  81  13  16  61  20  47  66  44   8  40  62  31  27  36  77  33  51  84
	78  35  85  59  95  69  90  64  63  92   6  80  28  34  12  87  87  63  86  30
	6  75  65  28  41  80  20  84   8  58  49  77  40  59  32  17  84  63  99  75
	98  88  45  81   2  39  31  25  58  96  36  54  39  18  16  12  19  66  27   0
	---------------------------------------------------- -
	Enter a number : 28
	The index of value : a[17]
	The index of value : a[52]
	The index of value : a[63]
	The total count : 3
	*/
}
```

/----------------------------------------------
/----------------------------------------------

* Example: 
  - The question from Donald Knuth on the previous code (Donald Knuth - The Art of Computer Programming )
  - i<SIZE, ++i, a[i] == value --> there are 3 arithmetic operations 
  - for loop'unu iki iþlem kullanýlarak gerçekleyiniz !!!

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 100

void dline(void) {
	printf("\n-----------------------------------------------------\n");
}

void randomize(void) {
	srand((unsigned int)time(NULL));
}

void set_random_array(int *ptr, int size)
{
	while (size--) {
		*ptr++ = rand() % 1000;
	}
}

void print_array(const int *ptr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (i && i % 20 == 0)
			printf("\n");
		printf("%3d ", ptr[i]);

	}
	dline();
}

int main() {

	int a[SIZE];
	int value;
	int i; 

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	printf("Enter a number : ");
	scanf("%d", &value);


	for (i = 0; i < SIZE; ++i) {
		if (a[i] == value) 
			break;
	}
		
	if (i == SIZE)
		printf("NOT FOUND !!!\n");
	else 
		printf("FOUND !!! The array index : %d\n", i);
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Reverse Algorithm
  - Dizinin eleman sayısının yarısı için olan bir döngüde , bastaki ve sondaki elemanların yer degistirmesi
  - Dizideki eleman sayısı tek olduğunda da sonuç değişmeyecektir. Son kalan eleman baþka bir elemanla yerini değiştirmez.

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 10

void dline(void) {
	printf("\n-----------------------------------------------------\n");
}

void randomize(void) {
	srand((unsigned int)time(NULL));
}

void set_random_array(int *ptr, int size)
{
	while (size--) {
		*ptr++ = rand() % 1000;
	}
}

void print_array(const int *ptr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (i && i % 20 == 0)
			printf("\n");
		printf("%3d ", ptr[i]);

	}
	dline();
}

int main() {

	int a[SIZE];
	int value;
	int i; 

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	for (i = 0; i < SIZE/2; ++i) {
		int temp = a[i];
		a[i] = a[SIZE - 1 - i];
		a[SIZE - 1 - i] = temp; 
	}

	print_array(a, SIZE);
	/*
	461 959 584 646 544 614 373 244 155   3
	-----------------------------------------------------
    3 155 244 373 614 544 646 584 959 461
	-----------------------------------------------------
	*/
}
```

/----------------------------------------------
/----------------------------------------------


