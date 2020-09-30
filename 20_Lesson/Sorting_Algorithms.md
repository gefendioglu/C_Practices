
## SORTING ALGORITHMS

- veri yapýsýnýn sýralamadan önceki durumu
- en iyisýralama algoritmasý diye bir tanýmlama yapýlamaz. En iyi sýralama, problem açýsýndan en uygun olan sýralamadýr.
- en çok kullanýlan quick ve heap sort algoritmalarýdýr
- worst case --> n log n, n log^2 n, n^2 karmaþýklýðýna sahip
- sorting criteria
- belirli koþullar oluþtuktan sonra swap iþlemi uygulanmalý
- bir kritere göre dizinin elemanlarýný yeniden konumlandýrmaktýr
- Type of sýrting algorithms: 
	- bubble sort
	- liner sort
	- merge sort
	- radix sort
	- quick sort
	- shell sort
	- insertion sort
	- intro sort
	- selection sort

- bubble sort neden en popüler olan algoritmadr?
	  - O(n^2) --> karmaþýklýðý --> iç içe döngü ihtiyacý vardýr.
    
- Neden farklý sýralama algoritmalarý bulunmaktadýr? 
  - Bu farklý tipteki sorting algoritmalarýnýn karmaþýklýklarý birbirinden farklýdýr (best case, worst case ve average case a göre karþýlaþtýrma yapýlmalýdýr)
	- stable olup olmamasý (stable sorting): yapýlan farklý sýramalar sonucunda da önceki mantýklý sýralama sonuçlarýnýn deðiþmemesidir. (birden fazla özellik taaþýyan veriler için)

- Yaþa göre yapýlan sýralama: 
	ahmet  45
	ali 
	faruk 
	selin
	ahmet  34
	metin 
	ahmet  20

- isme göre yapýlan sýralama: 
	ahmet  45
	ahmet  34
	ahmet  20
	ali
	faruk
	metin
	selin

- efficiency of sorting algorithms: 
  - kullanýlan programlama dili
	- c ve cpp derleyicileri optimization iþlemi uygular (optimization ayarlarý da burada önemlidir)

- complexity of algorithms: 
  - time complexity
  - space complexity

/----------------------------------------------
/----------------------------------------------

- **Example**: Benchmarking for sorting algorithms: 

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

	int array[SIZE] = {0};

	randomize();
	// aset (array, SIZE);
	// aprint (array, SIZE);

	for (int i = 0; i < SIZE; ++i) {
		array[i] = rand() % SIZE;
		printf("array[%d]: %3d\n", i, array[i]);
	}
	printf("\n\n");

	// SIZE-1 : her turda bir öðe yerine konulacak
	for (int i = 0; i < SIZE-1; ++i) 
	{
		for (int k = 0; k < SIZE-1-i; ++k)
		{
			// sorting criteria
			if (array[k] > array[k+1])
			{
				// swap function
				int temp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = temp;
			}
		}
		printf("array[%d]: %3d", i, array[i]);
		getchar();
	}
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Sorting criteria deðiþtirildi - Tekler baþta ve kendi içinde sýralý, çiftler sonda ve kendi içinde sýralý 
  - (array[k] % 2 == 0 && array[k+1] %2 != 0) --> tekler baþa
  - (array[k]  % 2 == array[k + 1] ) --> iki sayýnýn tekliði veya çiftliði aynýysa (audity)
  - (array[k]>array[k + 1]) --> sýralama için eklenen son kýsým

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

	int array[SIZE] = {0};

	randomize();
	// aset (array, SIZE);
	// aprint (array, SIZE);

	for (int i = 0; i < SIZE; ++i) {
		array[i] = rand() % SIZE;
		printf("array[%d]: %3d\n", i, array[i]);
	}
	printf("\n\n");

	// SIZE-1 : her turda bir öðe yerine konulacak
	for (int i = 0; i < SIZE-1; ++i) 
	{
		for (int k = 0; k < SIZE-1-i; ++k)
		{
			// sorting criteria
			if ((array[k] % 2 == 0 && array[k+1] %2 != 0) || (array[k]  % 2 == array[k + 1] % 2 && array[k]>array[k + 1]))
			{
				// swap function
				int temp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = temp;
			}
		}

		printf("array[%d]: %3d\n", i, array[i]);
		//getchar();
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

#define SIZE 100

void randomize(void) {
	srand((unsigned int)time(NULL));
}

int main() {

	// dynamic memory management
	int* pd = (int*)malloc(SIZE * sizeof(int));
	clock_t start, end;

	if (!pd)
	{
		printf("not enough memory space!!!");
		return 1;
	}

	randomize();
	// aset (pd, SIZE);
	// aprint (pd, SIZE);

	for (int i = 0; i < SIZE; ++i) {
		pd[i] = rand() % SIZE;
		printf("array[%d]: %3d\n", i, pd[i]);
	}

	start = clock();
	printf("Sorting starting\n");

	for (int i = 0; i < SIZE-1; ++i) 
	{
		for (int k = 0; k < SIZE - 1-i; ++k) {

			if (pd[k] > pd[k+1])
			{
				int temp = pd[k];
				pd[k] = pd[k + 1];
				pd[k + 1] = temp;
			}
		}
		
		printf("array[%d]: %3d\n", i, pd[i]);

	}
	end = clock();
	printf("Sorting stopped : %f\n", (double)(end-start)/CLOCKS_PER_SEC);
	getchar();

	free(pd);
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: quick sort algorithm

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void randomize(void) {
	srand((unsigned int)time(NULL));
}

int icmp(const void* vp1, const void* vp2) {

	return *(const int*)vp1 - *(const int*)vp2;
}

int main() {

	// dynamic memory management
	int* pd = (int*)malloc(SIZE * sizeof(int));
	clock_t start, end;

	if (!pd)
	{
		printf("not enough memory space!!!");
		return 1;
	}

	randomize();
	// aset (pd, SIZE);
	// aprint (pd, SIZE);

	for (int i = 0; i < SIZE; ++i) {
		pd[i] = rand() % SIZE;
		printf("array[%d]: %3d\n", i, pd[i]);
	}

	start = clock();
	printf("Sorting starting\n");
	qsort(); // tamamlanacak !!! --> n log n
	
	// printf("array[%d]: %3d\n", i, pd[i]); ???

	end = clock();
	printf("Sorting stopped : %f\n", (double)(end-start)/CLOCKS_PER_SEC);
	getchar();

	free(pd);
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: merge sorting algorithm 
  - 2   5 12  80 120 987 1234
  - 17 23 99 176 234 812
  - After merging : 2   5 12 17 ...
  
  - her iki dizide de kalýnan yeri gösteren bir index tutulmasý gerekir
  - diziye eklenen index her iki dizi için ilerletilerek kullanýlýr. 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ASIZE 10
#define BSIZE 12
#define CSIZE (ASIZE+BSIZE)

void randomize(void) {
	srand((unsigned int)time(NULL));
}

int icmp(const void* vp1, const void* vp2) {

	return *(const int*)vp1 - *(const int*)vp2;
}

int main() {

	int a[ASIZE];
	int b[BSIZE];
	int c[CSIZE];
	int idx_a = 0;
	int idx_b = 0;

	randomize();
	// aset (a, ASIZE);
	// aset (b, BSIZE);

	qsort(a, ASIZE, sizeof(*a), icmp);

	// aprint (a, ASIZE);
	// aprint (b, BSIZE);

	for (int i = 0; i < ASIZE; ++i) {
		a[i] = rand() % ASIZE;
	}

	qsort(a, ASIZE, sizeof(*a), icmp);
	for (int i = 0; i < ASIZE; ++i) {
		printf("array[%d]: %3d ", i, a[i]);
	}
	printf("\n\n");

	for (int i = 0; i < BSIZE; ++i) {
		b[i] = rand() % BSIZE;
		printf("array[%d]: %3d ", i, b[i]);
	}

	qsort(b, BSIZE, sizeof(*b), icmp);
	for (int i = 0; i < BSIZE; ++i) {
		printf("array[%d]: %3d  ", i, b[i]);
	}

	printf("\n\n");

	for (int i = 0; i < CSIZE; ++i)
	{
		if (idx_a == ASIZE)
		{
			c[i] = b[idx_b++];
		}
		else if (idx_b == BSIZE)
		{
			c[i] = a[idx_a++];

		}
		else if (a[idx_a] < b[idx_b])
		{
			c[i] = a[idx_a++];

		}
		else
		{
			c[i] = b[idx_b++];

		}

	}

	for (int i = 0; i < CSIZE; ++i) {
		printf("array[%d]: %3d\n ", i, c[i]);
	}
}
```

/----------------------------------------------
/----------------------------------------------

* Homework: maximum subsequence problem 
	- What is the complexity of this problem? --> O(n)
	- instead of  O(n^2) or O(n^3) 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ASIZE 10

void randomize(void) {
	srand((unsigned int)time(NULL));
}

int main() {

	int a[ASIZE];
	int idx_a = 0;

	randomize();

	for (int i = 0; i < ASIZE; ++i) {
		a[i] = ((rand() % 2) ? 1: -1)*(rand()%1000);
		printf("array[%d]: %3d ", i, a[i]);
	}
	printf("\n\n");

	// Find the maximum subsequence value of this array
}
```

/----------------------------------------------
/----------------------------------------------
