
## ALGORITHM EXAMPLES: 

- sizeof operatoru
	- variable length array sizeof açýsýndan problemlidir.
	- sizeof(int)
	- sizeof(x+10)
	- sizeof(x++) --> x++ iþlemi gerçekleþtirilmez. derleyici sadece x türüne bakacaktýr.
	- sizeof(array) --> dizinin byte olarak kapladýðý alan 
	- sizeof(array)/ sizeof(array[0]) --> dizinin eleman sayýsý

- size_t --> not a type, it is a type alias
	- unsigned int, unsigned long, unsigned long long türlerinden biri olabilir. 

/----------------------------------------------
/----------------------------------------------

- **Example**: unique random number generator

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define URAND_MAX 20

// unique random number generator
// bir dizide depolanarak ayný sayýnýn ürtilip  üretilmediði kontrol edilebilir. 
int urand(void) {

	// kontrol dýþý deðiþtirilmesini engellemek için glbal yerine static local 
	static int array[URAND_MAX] = { 0 };

	// fonksiyonun üretilebilecek bütün rasgele sayýlarý üretip üretmediðini kontrol etmesi gerekir.
	static int count = 0;
	int value;

	// C de çýkarým  yapýlabilecek else parçalarýnýn yazýlmasý tercih edilmez. 
	// hidden else 
	if (count == URAND_MAX)
		return -1;

	/*while (1) {
		value = rand() % URAND_MAX;
		if (array[value] == 0)
			break;
	}*/

	while (array[value = rand() % URAND_MAX])
		;

	++count;
	array[value] = 1;

	return value;
}

void randomize(void) {
	srand((unsigned int)time(NULL));
}

int main() {

	randomize();

	for (int i = 0; i < URAND_MAX; ++i)
		printf("%3d", urand());
	
  printf("\n");
	printf("%3d", urand());
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Dizide unique olan deðerlerin yazdýrýlmasý 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void randomize(void) {
	srand((unsigned int)time(NULL));
}


int main() {

	int array[SIZE];
	randomize();

	for (int i = 0; i < SIZE; ++i)
		array[i] = rand() % 20;
	print("array[%d] : ");

	for (int i = 0; i < SIZE; ++i)
	{
		int flag = 0;

		for (size_t k = 0; k < SIZE; ++k)
		{
			if (array[i] == array[k] && i != k)
			{
				// array[i] unique olmadýðýndan döngüden çýk
				flag = 1;
				break;
			}
		}
		if (flag == 0) //-->array[i] bu durumda unique
			printf("%3d", array[i]);
	}
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: The same example with different style 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void randomize(void) {
	srand((unsigned int)time(NULL));
}

int main() {

	int array[SIZE];
	int k = 0;
	randomize();

	for (int i = 0; i < SIZE; ++i) {
		array[i] = rand() % 20;
		printf("array[%d] : %d", i, array[i]);
	}
		
	for (int i = 0; i < SIZE; ++i)
	{

		for (size_t k = 0; k < SIZE; ++k)
		{
			if (array[i] == array[k] && i != k)
			{
				// array[i] unique olmadýðýndan döngüden çýk
				break;
			}
		}
		if (k == SIZE) //-->array[i] bu durumda unique
			printf("%3d", array[i]);
	}
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Finding the maximum value of an array 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void randomize(void) {
	srand((unsigned int)time(NULL));
}


int main() {

	int array[SIZE];
	int max;
	int max_index = 0;
	
	randomize();
	//aset(array, SIZE);
	//aprint(array, SIZE);

	max = array[0];

	for (int k = 0; k < SIZE; k++)
	{
		if (array[k] > max)
		{
			max = array[k];
			max_index = k;
		}

	}
	printf("max = %d\n", max);
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Finding the minimum value of an array  

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void randomize(void) {
	srand((unsigned int)time(NULL));
}

int main() {

	int array[SIZE];
	int min;
	int min_index = 0;
	
	randomize();
	//aset(array, SIZE);
	//aprint(array, SIZE);

	min = array[0];

	for (int k = 0; k < SIZE; k++)
	{
		if (array[k] < min)
		{
			min = array[k];
			min_index = k;
		}

	}
	printf("min = %d\n", min);
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Finding both the minimum and maximum values placed in an array

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void randomize(void) {
	srand((unsigned int)time(NULL));
}

int main() {

	int array[SIZE];
	int max, min;

	randomize();
	//aset(array, SIZE);
	//aprint(array, SIZE);

	max = min = array[0];

	for (int k = 0; k < SIZE; k++)
	{
		if (array[k] > max)
		{
			max = array[k];
		}
		else if (array[k] < min)
		{
			min = array[k];
		}

	}
	printf("min = %d\n", min);
	printf("max = %d\n", max);
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Finding the second max  value in an array (runner-up  algorithm)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void randomize(void) {
	srand((unsigned int)time(NULL));
}

int main() {

	int array[SIZE];
	int max, runner_up;
	//int min_index = 0;

	randomize();
	//aset(array, SIZE);
	//aprint(array, SIZE);

	max = array[0];
	runner_up = array[1];
	// max = array[0], runner_up = array[1];

	if (array[0] < array[1])
	{
		max = array[1], runner_up = array[0];
	}

	for (int i = 2; i < SIZE; ++i)
	{
		if (array[i] > max)
		{
			runner_up = max;
			max = array[i];
		}
		else if (array[i] > runner_up)
		{
			runner_up = max;
		}
	}

	printf("max = %d\n", max);
	printf("runner-up = %d\n", runner_up);
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Dizinin her elemaný kadar * ekleyen bir algoritma tasarýmý

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void randomize(void) {
	srand((unsigned int)time(NULL));
}

int main() {

	int array[SIZE];
	randomize();

	for (int i = 0; i < SIZE; ++i)
	{
		array[i] = rand() % 20;
		printf("array[%d] = %d\n", i, array[i]);
	}

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < array[i]; ++j)
			putchar('*');
		putchar('\n');
	}
  
}
```
/----------------------------------------------
/----------------------------------------------

- **Example**:

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void randomize(void) {
	srand((unsigned int)time(NULL));
}

int main() {

	int array[SIZE];
	int counts[SIZE] = { 0 };

	randomize();

	for (int i = 0; i < SIZE; ++i)
	{
		array[i] = rand() % 20;
		printf("array[%d] = %d\n", i, array[i]);
	}

	for (int i = 0; i < SIZE; ++i)
	{
		++counts[array[i]];
	}

	for (int i = 0; i < SIZE; i++)
	{
		if (counts[i]==1)
		{
			printf("%3d", i);
		}
	}
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Partition Algorithm
	- verinin koþulu saðlayan ve saðlamayanlar olarak ikiye ayrýlmasý
	- partition point : koþulu saðlamayan ilk verinin konumunu tutar.

  - Homework: The condition is 
    - Koþulu saðlayanlar --> baþta
	  - Koþulu saðlamayanlar --> sonda
    - Koþul sayýnýn çift olmasý olabilir. 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void randomize(void) {
	srand((unsigned int)time(NULL));
}

int main() {

	int array[SIZE];
	int counts[SIZE] = { 0 };

	randomize();
	// aset (array, SIZE);
	// aprint (array, SIZE);
	// partition algorithmn here...

	// Çift sayýlar baþta olacak þekilde yazdýrýlacak.
	// Tek sayýlar sonra olacak þekilde yazdýrýlacak.
	// partition point yazdýrýlacak. 

	// Algoritma karmaþýklýðý = O(n) 
	// Ýç içe iki döngü olmadan tek bir döngü ile yazdýrýlabilir demek
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: c dizisi son kez yazdýrýldýðýnda, c dizisi a ve b dizilerinin birleþtirilmiþ halini temsil etsin

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void randomize(void) {
	srand((unsigned int)time(NULL));
}

int main() {

	int a[SIZE];
	int b[SIZE];
	int c[SIZE * 2];
	int i, k; 

	randomize();
	// aset (a, SIZE);
	// aprint (a, SIZE);
	// aset (b, SIZE);
	// aprint (b, SIZE);

	for (i = 0; i < SIZE; ++i)
		c[i] = a[i];

	for (k = 0; k < SIZE; ++k)
		c[i + k] = b[k];

	// aprint (c, 2*SIZE);

}
```

/----------------------------------------------
/----------------------------------------------
