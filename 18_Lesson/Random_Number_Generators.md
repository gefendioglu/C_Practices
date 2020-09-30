### Random Number Generator : 

/----------------------------------------------
/----------------------------------------------

- tek başına bir sayının rasgele olup olmadığı hakkında konuşulamaz
- bir sayı dizi içinden seçilmiş bir sayı rasgele olabilir
- 2 3 5 7 2 3 5 7 2 3 5 ? --> rasgele olma durumu düşük, sayının 7 olma ihtimali yüksek
- rasgele olmak öngörülemez olmakla ilgilidir. 
- test işlemlerinde, simülasyonlarda, oyun programlarında, genetik algoritmalarında, kriptolojide, olasılık hesaplamanın olduğu her alanda vb. kullanımları bulunmaktadır. 
- iki ayrı rasgele sayı üretimi vardır: 
	- true(ly) random number generation : 
		--> doğadan kaynaklanan sayı üretimi
	- pseudo random number generation   : 
		--> random number generator engine ile bazı algoritmalara göre ragele sayı üretimidir (kullanılan algoritmaya göre random number oluşturma hızı değişecektir.)
		--> mersenne - twister algorithm is used commonly to generate pseudo random number
		--> ancak başlangıç değeri (seed value) aynı olduğunda, uygulanan algoritmanın da aynı olması ile her defasında aynı değerler üretilecektir. 
		--> bu sebeple aynı algoritma kullanımlarında seed value değerinin  değişmesi  önemlidir !!!
		--> seed value --> 4 byte unsigned value rasgele olma ihtimali 2 byte unsigned value olmasına göre daha yüksek ihtimaldir. 
		--> seed value ne kadar geniş bir aralıkta olursa olsun bir noktadan sonra tekrarlama olacaktır.
		--> doğadan kaynaklı rasgele sayı üretimi sağlayan algoritmaları çalıştıran cihazlar mevcuttur; ancak pahallıdır. 
		
/----------------------------------------------
/----------------------------------------------

bitwise exor işlemi ile random sayı üretimi : 
dosya byte değerlerinin farklı sayılarla exor işlemine sokulması
dosyayı açan tarafın aynı değerler ile exor işlemine sokması ile aynı byte değerleri elde edilmektedir.

/----------------------------------------------
/----------------------------------------------

* Programlama dilleri random number üretiminde verdiği destek: 
- C   --> yok denecek kadar zayıf 
- C++ --> random lib. kullanılan ve istenilen dağılım modeli seçilebilir. 
	  --> 3 temel rasgele sayı üretim algoritması mevcuttur: 
		  std::mersenne_twister_engine (mt19937, mt19937_64)
		  std::subtract_with_carry_engine
		  std::linear_congruential_engine
- rasgele sayı üretimi ile, üretilen rasgele sayıların istenilen şekilde dağıtılması birbirinden farklı süreçlerdir. Dağılım farklı modellere göre gerçekleştirilir.
- uniform distribution (her rakamın aynı sayıda gelmesine dayanan model):
	--> zarın 0-6 aralığında rasgele gelen rakamlarının dağılımını temsil edebilir. 
	--> bu model 0-100yaş aralığındaki insanlar için yaş dağılımını temsil edemez. 
	--> bu model 30-250 kilo aralığındaki insanlar için kilo dağılımını temsil edemez.
- bernoulli distribution
- poisson distribution
- normal distribution
- sampling distribution

/----------------------------------------------
/----------------------------------------------

* C --> random number generator with rand(), srand() functions in stdlib.h
- int rand(void); // 0 - RAND_MAX (Derleyici tipine göre değişir.)
			      // RAND_MAX : 32767 (generally)

- void srand(unsigned int); // ilk değer verilerek random number üretmek 
							// her seed value için 

/----------------------------------------------
/----------------------------------------------

- **Example**: Random number generation with different seed values 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// standart rand fonksiyonun default seed value 1 için üretilen rasgele sayılar
int main() {

	srand(1u);
	for (int i = 0; i < 20; ++i)
		printf("%d\n",rand());  

	printf("\n\n\n");

	srand(1992);
	for (int i = 0; i < 20; ++i)
		printf("%d\n", rand());
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Random number generation with functions and different seed values 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void printRandomNumbers(unsigned int seed) {
	
	printf("seed value : %u\n\n", seed);
	srand(seed);

	for (int i = 0; i < 100; ++i) {
		if(i && i%10 == 0)
			printf("\n");
		printf("%-5d", rand());

	}
	printf("\n");
	_getch();
	system("cls");
}

int main() {
	for (int i = 0; i < 100; ++i) 
		printRandomNumbers(i);
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Belli sayı aralığında random number üretmek 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define RANDOM_MIN_YEAR 1960
#define RANDOM_MAX_YEAR 2010

int main() {
	
	// 1960 - 2010 arasında random year generator
	for (int i = 0; i < 20; ++i)
		printf("%d\n", rand() % (RANDOM_MAX_YEAR - RANDOM_MIN_YEAR + 1) + RANDOM_MIN_YEAR);
	
	printf("\n\n\n");

	for (int i = 0; i < 20; ++i)
		printf("%d\n", rand()%6+1);
	
	printf("\n\n\n");

	for (int i = 0; i < 20; ++i)
		printf("%d\n", rand()%2);
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Example: Random Number Generator

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int roll_dice(void) {
	return rand() % 6 + 1;
}

int main() {

	for (int i = 0; i < 20; ++i)
		printf("%d %d\n", roll_dice(), roll_dice());

	printf("\n\n\n");
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: default seed value aynı olduğunda, random number dizisi de aynı olacaktır. 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {

	srand(rand());
	for (int i = 0; i < 20; ++i)
		printf("%d \n", rand());
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Randomize Idiom: 
  - Belli bir sayıdan geçen zamanı bulmak --> time point noktası (epoch time)
  - 1.1.1970 00:00:00 --> epoch time

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>

int main() {

	long long timer;

	for (;;) {
		time(&timer); // scanf gibi call by reference olarak çağırır
		printf("%lld\n", timer);
	}
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Farklı seed değerleri ile random number üretmek 
  - Epoch time sebebiyle her çalıştırma süresi arasında en az 1 saniye geçmelidir.

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main() {

	printf("%lld\n\n", time(NULL));  // 1.1.1970 ten geçen saniye sayısı alınır
	srand((unsigned int)time(NULL)); // seed value her defasında değişecektir. 
	
	for (int i = 0; i < 20; ++i)
		printf("%d\n", rand());
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**:

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

void sleep(double sec) {
	clock_t start = clock();
	while ((double)(clock() - start) / CLOCKS_PER_SEC < sec)
		; // null statement
}

int main() {

	int c; 
	srand((unsigned int)time(NULL)); // seed value her defasında değişecektir. 
	
	for (;;) {
		putchar(rand()%5 + 'A');
		sleep(0.05);
	}

	/*
	for (;;) {
		while (!isdigit(c = rand() % 128));
		putchar(c);
		sleep(0.05);
	}
	*/

	/*
	for (;;) {
		while (!ispunct(c = rand() % 128));
		putchar(c);
		sleep(0.05);
	}
	*/

	/*
	for (;;) {
		while (!isprint(c = rand() % 128));
		putchar(c);
		sleep(0.05);
	}
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**:
* randomize idiomu, döngüsel yapıda ya da fonksiyon içinde çağrıldığında aynı değeri döndürecek kadar hızlı işlem görür. 
- bu sebeple genelde random sayı üretilmeden önce çağırılması tercih edilmelidir.  

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

void printRandomPassword(void) {
	
	int len;
	//srand((unsigned int)time(NULL)); // NOT OK here --> same time value 

	len = rand() % 8 + 5;
	while (len--)
		putchar(rand()%26 + 'A');
		
	putchar('\n');
}

int main() {
	
	srand((unsigned int)time(NULL)); // OK here --> different time value 
	for (int i = 0; i < 10; ++i)
		printRandomPassword();
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Tura Gelme Olasılığı 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

#define NTOSS 100000
#define HEADS 1

int main() {
	
	int headsCount = 0;
	for (int  i = 0; i < NTOSS; ++i)
	{
		if (rand() % 2 == HEADS)
			++headsCount; 
	}

	printf("tura gelme olasiligi %.12f\n", (double)headsCount / NTOSS);
	// NTOSS arttıkça olasılık artacaktır.
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**:
  - Oyun: 
    - 7, 11        --> WIN
    - 2, 3, 12     --> LOSE
    - 4,5,6,8,9,10 --> OYUN ASKIDA, ilk atılan zarın atılması gerekir, 7 attığı ilk anda kaybecektir. 7 atmadan ilk attığını atarsa kazanır. 

  - Sample: 
    - WIN Case  : 8 12 6 8 
    - LOSE Case : 8 12 6 7

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define NGAMES 100'000'000
// NGAMES 100'000'000 --> kazanma olasiligi : 0.492305970000
// NGAMES 10'000'000  --> kazanma olasiligi : 0.492299200000
// NGAMES 1'000'000   --> kazanma olasiligi : 0.492245000000

int rollDice(void) {
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	return dice1 + dice2;
}

// Win Case  --> return value = 1
// Lose Case --> return value = 0

int game_(int dice) {
	int new_dice;
	for (;;)
	{
		new_dice = rollDice();
			if (new_dice == 7)
				return 0;
			if (new_dice == dice)
				return 1;
	}
}

int game(void) {

	int dice = rollDice();
	switch (dice)
	{
	case 2:
	case 3:
	case 12:
		return 0;
	case 7:
	case 11:
		return 1;
	default:
		return game_(dice);
	}
}

int main() {
	int winCount = 0;
	for (size_t i = 0; i < NGAMES ;++i)
		winCount += game();

	printf("kazanma olasiligi : %.12f\n", (double)winCount/NGAMES );
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: The same example with rollDice() function in cpp 
  - kazanma olasılığı çok daha fazla artar

```c
Cpp_RollDice.cpp
-------------------
#include <stdlib.h>
#include <random>

#define NGAMES 100'000'000
// NGAMES 100'000'000 --> kazanma olasiligi : 0.492305970000
// NGAMES 10'000'000  --> kazanma olasiligi : 0.492299200000
// NGAMES 1'000'000   --> kazanma olasiligi : 0.492245000000

int rollDice(void) {
	static std::mt19937 eng; 
	std::uniform_int_distribution<int> dist{ 1,6 };

	int dice1 = dist(eng);
	int dice2 = dist(eng);
	return dice1 + dice2;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Bir noktanın karenin yarı alanında bulunma olasılığı ve kaç tanesinin bu alanda bulunduğunun bulunması  

```c
// main.c
#include <stdio.h>
#include <stdlib.h>
#include <random>

#define NPOINTS 1'000'000
// Chudnovsky algorithm
// NPOINTS 1'000'000 --> 3.140452000000

int main() {
	static std::mt19937 eng;
	std::uniform_real_distribution<> dist{ 0.,1 };
	int inside_count = 0;

	for (int i = 0; i < NPOINTS; ++i)
	{
		double x = dist(eng);
		double y = dist(eng);
		if (x*x + y*y <= 1) {
			++inside_count;
		}
	}

	printf("%.12f\n", 4.* inside_count/ NPOINTS);
}
```


/----------------------------------------------
/----------------------------------------------
