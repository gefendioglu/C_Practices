
## Type Conversion: 

/----------------------------------------------
- makine seviyesinde farklý türdeki  sayýlar arasýnda aritmetik iþlemler uygulanamaz. Ayný türde olmalarý gerekmektedir. 

- int ival; 
  double dval; 
  ival + dval; --> double temp = ival; 
				   temp + double; olacak þekilde arka planda iþlem uygulanýr.

- usual arithmetic conversions 
- assignment type conversion 
ival = dval; --> double --> int dönüþümü yapýldýktan sonra atama iþlemi uygulanýr.

- implicit type conversion : hiçbir iþlem uygulamadan derleyici tarafýndan otomatik olarak gerçekleþtirilmektedir. 
- Not 
- int ival;
  long lval;
  (long)ival + lval; --> Type Casting: operator yoluyla yapýlan tür dönüþümleri

- Syntax hatasýndan ziyade, undefined behaviour, unspecifed behaviour veya data loss sebebiyle, en fazla kodlama hatasýna yol açacak iþlemlerden biridir.

* Type Conversions and Ranks: 
- Tür dönüþümü sýra seviyesi (rank) yüksek olana göre gerçekleþtirilmektedir. (ekran görüntüsünde yer alan açýklamalar eklenecek.) 
- Ayný tamsayý türünün signed ve unsigned olanlarý da ayný rank tedir.???
- unsigned long - unsigned short --> unsigned long 
- unsigned long - signed int  --> unsigned long 
- signed long - unsigned int  --> signed long, unsigned int türünün alabileceði tüm deðerleri temsil edebilebiliyorsa --> signed long türünde iþlem görülür. 
  Ancak signed long (4 byte), unsigned int (4 byte) olduðunda bu temsil gerçekleþtirilemez. Bu durumda --> unsigned long türünde iþlem görülür. 

- double - float --> double
- float - int --> float
- unsigned long - long --> same rank --> unsigned long
- unsigned long - signed int --> unsigned long
- long - unsigned int --> long, unsigned int türünün alabileceði deðerleri temsil edebiliyorsa, long ile iþlem görecektir. 
  eðer temsil edilemiyorsa --> unsigned long ile iþlem görecektir. 
  temsil edilip edilmeme kararý türlerin size'ýna göre verilmektedir. 
  long: 4 byte
  unsigned int : 4 byte olduðudan ;
  long - unsigned int --> unsigned long ile iþlem görecektir.

- The rank of data types: 
  - long double
  - double
  - float 
  - long long
  - long 
  - int
/----------------------------------------------
  - short
  - char 
  - _Bool 

* integral promotion (int altý türlerin int e yükseltilmesi)
- int altý türlerin hepsi iþleme int e çevrildikten sonra sokulmaktadýr. 



###Explicit Type Conversion:
 - This kind of type conversions realized by programmer intentionally
 
###Implicit Type Conversion:
 - This kind of type conversions realized by automatically
  
int ival = 10;
ival --> int, L-Value 
(double)ival --> double , R-Value

ival = 15;           // OK --> L-Value expression
(double)ival = 12.5; // NOT OK --> R-Value expression



ival + dval --> 
	- ival türü deðiþmez 
	- sadece ival için double tür açýsýndan geçici bir nesne oluþturulup iþleme sokulur.
	- Kodun devamýnda ival kullanýlýrsa, yine int türünden iþlem görecektir.
	
* int + double --> double
* integral promotion:
	- bir iþlemde binary operandýn operandýnda
	- variadic fonksiyonlarda 
	- default declare edilmiþ



/----------------------------------------------
/----------------------------------------------

- **Example**: Finding the size of signed/unsigned data types (considering their rank)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// The size of signed data types 
	printf("sizeof(long double) : %ld\n", sizeof(long double));
	printf("sizeof(double)      : %lu\n", sizeof(double));
	printf("sizeof(float)       : %lu\n", sizeof(float));
	printf("sizeof(long long)   : %lu\n", sizeof(long long));
	printf("sizeof(long)        : %lu\n", sizeof(long));
	printf("sizeof(int)         : %lu\n", sizeof(int));
	printf("sizeof(short)       : %lu\n", sizeof(short));
	printf("sizeof(_Bool)       : %lu\n\n", sizeof(_Bool));
	
	/* (Windows-10 x64 Visual Studio 2019 - MSVC) 
	sizeof(long double) : 8
	sizeof(double)      : 8
	sizeof(float)       : 4
	sizeof(long long)   : 8
	sizeof(long)        : 4
	sizeof(int)         : 4
	sizeof(short)       : 2
	sizeof(_Bool)       : 1
	*/

	// The size of unsigned data types 
	printf("sizeof(unsigned long long) : %lu\n", sizeof(unsigned long long));
	printf("sizeof(unsigned long)      : %lu\n", sizeof(unsigned long));
	printf("sizeof(unsigned int)       : %lu\n", sizeof(unsigned int));
	printf("sizeof(unsigned short)     : %lu\n", sizeof(unsigned short));

	/* (Windows-10 x64 Visual Studio 2019 - MSVC) 
	sizeof(unsigned long long) : 8
	sizeof(unsigned long)      : 4
	sizeof(unsigned int)       : 4
	sizeof(unsigned short)     : 2
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Comparing signed and unsigned variables

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int ival = -1;
	unsigned int uival = 1;

	// prints True!!! BUT we have a warning:
	// warning C4018: '>': signed/unsigned mismatch
	if (ival> uival) 
		printf("True!!\n");
	else
		printf("Wrong!!\n");
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Applying arithmetic operations

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int first_val = 10;
	int second_val = 7;
	double dval;

	dval = first_val / second_val;
	printf("%f\n", dval); // 1.000000
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Type conversions for char typed data

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char name = 178;
	
	// Prints False!!!
	// Not returning a warning message with Windows compiler
	if (name == 178)
		printf("True!!!\n"); 
	else
		printf("False!!!\n"); 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: The macro called "_CRT_SECURE_NO_WARNINGS" is a special macro for Windows copmpilers. 
  - #define _CRT_SECURE_NO_WARNINGS

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	char s1[100];
	char s2[100] = "gamze";
	strcpy(s1, s2);
	// Error C4996 'strcpy': This function or variable may be unsafe. Consider using strcpy_s instead. 
	// To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: without using _CRT_SECURE_NO_WARNINGS macro (not specified "#define _CRT_SECURE_NO_WARNINGS")

```c
#include <stdio.h>
#include <string.h>

int main() {

	char s1[100];
	char s2[100] = "gamze";
	strcpy_s(s1, sizeof(s2), s2);

}
```
/----------------------------------------------
/----------------------------------------------

- **Example**: Applying both explicit and implicit type conversions

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int x = 10, y = 20;
	(long long)x + y = 28;	             // NOT OK --> R-Value expression
	long long number = (long long)x + y; // OK --> L-Value expression
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**:

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	double dval;
	int ival;

	printf("Number: ");
	scanf("%lf", &dval);

	ival = dval;		// OK --> narrowing conversion
	printf("ival: %d\n ", ival);

	ival = (int)dval;   // OK --> narrowing conversion with explicit type conv. 
	printf("ival: %d\n ", ival);
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**:

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	char str[100];
	str[5] = (char)getchar();
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**:

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x, y;
	double dval; 

	printf("two real numbers: ");
	scanf("%d%d", &x, &y);      // two real numbers : 5 6
	
	dval = x / y;
	printf("dval: %f\n", dval); // dval : 0.000000
	
	dval =(double) x / y; 
	printf("dval: %f\n", dval); // dval : 0.833333

	int  counter;
	(long long) dval*counter;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Implicit Type conversion for ternary operators 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x = 10;
	int y = 10;
	double dval = (x > 5 ? y : 3.4) / 3;

	printf("dval: %f\n", dval); // dval: 3.333333

}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Rounding down and rounding up a number to a closer value 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int ival;
	double dval;

	printf("real number: "); 
	scanf("%lf", &dval);

	//ival = (int)round(dval);
	//ival = (int)(dval + dval > 0 ? .5 : -0.5);
	ival =(int)(dval + .5) - (dval < 0.);
	printf("ival : %d\n", ival);
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Applying type conversion by changing the constant type (?) 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int val) {
	return val < 2 ? 1 : val * factorial(val - 1);
}

int main() {

	double sum = 0.;
	for (int i = 0; i < 12; ++i)
		sum += 1. / factorial(i);
	printf("sum : %f\n", sum); // sum : 2.718282
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Applying type conversion by changing the constant type (?)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int min, sec;
	printf("dakika ve saniye :  "); 
	scanf("%d%d", &min, &sec);

	printf("%d dakika ve %d saniye ve %f saat\n", min, sec, min/60.+sec/3600.);
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Formatting to print double values

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	double dval = 1.7889765;
	printf("%f\n",dval);    // 1.788976 --> 6 numbers after comma (default)
	printf("%.2f\n",dval);  // 1.79     --> 2 numbers after comma
}
```

/----------------------------------------------
/----------------------------------------------

