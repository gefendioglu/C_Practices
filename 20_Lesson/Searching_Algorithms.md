## SEARCHING ALGORITHMS:

* binary search algoritmasý : complexity: --> log n
 - sýralý bir dizide deðer aramak 
 - her defasýnda veri setinin ikiye ayrýlarak aramanýn devam etmesi
 - sýralý dizilerde linear search yapýlmamalýdýr !!!

/----------------------------------------------
/----------------------------------------------
- ** Example**: 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ASIZE 10

void randomize(void) {
	srand((unsigned int)time(NULL));
}

static int icmp(const void* vp1, const void* vp2) {

	return *(const int*)vp1 - *(const int*)vp2;
}

void array_sort(int* p, int size) {

	qsort(p, size, sizeof(*p), icmp);
}
int main() {

	int a[ASIZE];
	int idx_first, idx_last, idx_mid;
	int svalue;


	// aset
	randomize();

	for (int i = 0; i < ASIZE; ++i) {
		a[i] = (rand() % ASIZE);
		printf("array[%d]: %3d\n", i, a[i]);
	}
	printf("\n\n");

	array_sort(a, ASIZE);
	for (int i = 0; i < ASIZE; ++i) {
		printf("array[%d]: %3d\n", i, a[i]);
	}
	// aprint
	printf("\n\n");

	printf("Aranan deger: ");
	scanf("%d", &svalue);
	idx_first = 0;
	idx_last = ASIZE - 1;
	while (idx_first <= idx_last)
	{
		idx_mid = (idx_first + idx_last) / 2;
		if (a[idx_mid] == svalue)
		{
			break;
		}

		if (a[idx_mid] > svalue)
		{
			idx_last = idx_mid - 1; 
		}
		else
		{
			idx_first = idx_mid + 1;

		}
	}

	if (idx_first > idx_last)
	{
		printf("Bulunamadi \n");
			
	}
	else
	{
		printf("Bulundu : %d \n", idx_mid);

	}
}
```

/----------------------------------------------
/----------------------------------------------

