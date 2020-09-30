
 ## ARRAYS : 
/----------------------------------------------
/----------------------------------------------

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

/----------------------------------------------
/----------------------------------------------

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
