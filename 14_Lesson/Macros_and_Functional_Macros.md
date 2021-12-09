## MACRO 
 - Fonksiyon yazmak yerine önişlemciye bu işlemi aktarmak icin kullanilir. 
 - It can be used for avoiding the cost of function calls
 - The compiler only writes the specified code with macros where there is a function call.
 - There is no return value definition for macros. 

/----------------------------------------------
/----------------------------------------------

```c
#define _USE_MATH_DEFINES
#include <math.h>
#include <limits.h>
#include <stdio.h>


#ifdef _USE_MATH_DEFINES // define edildiği için by bloğa girilir. 
#define SIZE 100
#define MAX 500
#endif // _USE_MATH_DEFINES


int main() {

	int sqrtNumberWithMacro = M_SQRT2;
	printf("sqrtNumberWithMacro : %d\n", sqrtNumberWithMacro);

	int sqrtNumberWithFunction = sqrt(2);
	printf("sqrtNumberWithFunction : %d\n", sqrtNumberWithFunction);

	int number = INT_MAX;
	printf("number : %d\n", number);

	return 0;
}
```

/----------------------------------------------
/----------------------------------------------

### Functional Macro:
- It is expected to work faster since there will be no entry and exit code from the function.
- It should be preferred for functions whose code is small and frequently called.
- It is also preferred because of its ease of writing.
- It is common to use functional macros when using bit elements.
- It has a security vulnerability; but its use can not be abandoned.

```c
#define max(a,b) ((a) > (b) ? (a):(b))
#include <stdio.h>

int main() {

	int x = 34, y = 67;
	int ival = max(x, y);
	printf("ival : %d\n", ival);

	return 0;
}
```

/----------------------------------------------
/----------------------------------------------

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Instead of function wrapper, a macro might be defined.  
#define randomizeMacro() srand((unsigned int)time(NULL))

// Function wrapper - forwarding function
void randomizeFunc(void) {
	srand((unsigned int)time(NULL));
}

int main() {
	randomizeMacro(); // Calling macro
	randomizeFunc();  // Calling function 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : 
  - The definition    --> ptr->a[5][5] * ptr->a[5][5] 
  - The macro version --> #define get_elem(x) (ptr->a[(x)][(x)] * ptr->a[(x)][(x)])

/----------------------------------------------
/----------------------------------------------

- **Example** : Functional macro example (from standard library)

```c
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// From stddef.h
#define offsetof(s,m) ((size_t)&(((s*)0)->m))

struct Data {
	int x, y, z;
	//...
};

int main() {

	offsetof(struct Data, z); 
	// ((size_t) & (((struct Data*)0)->z));
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Functional macro example (user defined)

```c
#include <stddef.h>

#define sum_square(a,b) ((a)*(a) + (b)*(b))
#define is_upper(c)     ((c)>='A'&& (c)>='Z') 
#define square(x)       ((x)*(x))

int main() {

	int a = 10;
	int x = square(a++); // Wrong macro implementation - ub 
	// int x = ((a++)*(a++)) = ((10++)*(10++)); 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** :

```c
#include <stddef.h>
#define square(x)       ((x)*(x))

int foo(void) {}

int main() {

	int a = 10;
	int x = square(foo()); 
	// int x = (foo()*foo()); 
}
```

/----------------------------------------------
/----------------------------------------------

- Compiler plugins (especially gcc) provide non-C standard plugins (especially in macro definitions)
  - Syntax tool expressed as statement expression can be used.
  - It can be google searched with these keywords : "gcc extension statement expression".
    - https://gcc.gnu.org/onlinedocs/gcc/Statement-Exprs.html
    - #define maxint(a,b) ({int _a = (a), _b = (b); _a > _b ? _a : _b; })
  - clang, ibm plugins may not have a plugin defined in gcc.
 
/----------------------------------------------
/----------------------------------------------

- **Question** : What are the differences between functional macros and functions?  
  - Functional macros are not a real function. That's why, they havent got any address definition. 
  - Functional macros tend to expand the source code (compiled code). 
  - Functional macros are not debugger friendly like as functions. Debug sürecinde fonksiyon kullanıp, daha sonra macro kullanımına geçmek daha uygun bir yöntem olabilir. 
  - Functions are more secure than functional macros. 
  - Functional macros are independent of data types, but functions are dependent of data types.
  
    ```c
    // Aynı fonksiyon için türe bağımlı farklı tanımlamalar: 
    int imax(int, int);
    double dmax(double, double); 
    ```
    ```c
    // Macrolar için tek bir tanımlama mevcut (türden bağımsız)
    #define max(a,b) ((a) > (b) ? (a):(b))
    max(int, double) olarak çağrılırsa, tür dönüşümünden ötürü geri dönülen ifade double olacaktır (int --> double)
    ```

/----------------------------------------------
/---------------------------------------------- 

### Operators for Macro Definitions 
#       --> stringizing (stringification) operator
##      --> token-pasting operator
defined --> defined operator 

### Stringizing (stringification) operator
- It writes the following statement in double quotes.
 
```c
#include <stdio.h>

#define str(a)  #a 

int main() {

	printf("%s\n", str(gamze efendioglu)); // new string literal
    
    // One string literal
	printf("[1] Para yatirn"
		   "[2] Para cek\n"
		   "[3] Havale yap\n"
		   "[4] Fatura öde\n"
		   "[5] Cikis");
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Functional macro definition for printing

```c
#include <stdio.h>

#define iprint(i)  printf("%d\n",i)

int main() {

	int x = 10;
	int y = 5;
	int z = 4;

	iprint(x);		
	// printf("%d\n",x)

	iprint(x + y);  
	// printf("%d\n",x + y)

	iprint(x * x + y * y + z * z); 
	// printf("%d\n",x * x + y * y + z * z)
} 
```

/----------------------------------------------
/---------------------------------------------- 

- **Example** : For the example above, how should the macro expression be written to the screen as follows?\ 
x = 10\ 
x + y = 15\
x * x + y * y + z * z = 141

```c
#include <stdio.h>

#define iprint(i)  printf(#i " = %d\n",i)

int main() {

	int x = 10;
	int y = 5;
	int z = 4;

	iprint(x);		
	// printf("x"" = %d\n",x)

	iprint(x + y);  
	// printf("x + y" " = %d\n",x + y)

	iprint(x * x + y * y + z * z); 
	// printf("x*x + y*y + z*z "" = %d\n",x * x + y * y + z * z)
} 
```

/----------------------------------------------
/---------------------------------------------- 

### Token-Pasting Operator
- The preprocessor is a tool that writes code to the program.
- It is used to create a single text by combining left and right operands

```c
#include <stdio.h>

#define uni(a,b)  a##b

int main() {

	int counter = 0;
	++uni(cou, nter); // ++counter;
	printf("counter = %d\n", counter);
} 
```

/----------------------------------------------
/---------------------------------------------- 
