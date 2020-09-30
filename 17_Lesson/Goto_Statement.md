
## GOTO STATEMENT: 
/----------------------------------------------
/----------------------------------------------

- There are two different types of jumping style for goto statement:  
  - Long Jump: 
    - Using the function jumping sequence such as f5()--> f1() instead of f5()-->f4()-->f3()-->f2()-->f1()
    - Applying with standard library functions such as setjmp() and longjmp()
  - Local Jump (Near Jump): 
    - Jumping in the same state frame (where the place including the same local variables like as the same function scope for C programming language) 
    - Applying with goto statements for C and C++
  
- The reasons of using goto statements: 
  - Cleanly exiting a function 
  - Exiting nested loops
  - low level performance improvements (only for performance critical codes)

- The labels of goto statement: 
  - A label can be defined once in anywhere of a function scope. 
  - A label can only be used with a goto statement.
  - A label shall have a statement, even if it is a NULL statement --> out: ;
  - goto out; --> jumping the first "out" label and the programme continues from that point to the end. 
  
- Why goto statements are not generally preferred? 
  - The following specifications are more difficult with goto statements: 
    - Readability
    - Testability 
    - Modifiability
  - If a programme is oriented with a goto statement to the one of the previous code lines, it can not be said that it is a good style of using this statement.  
    
/----------------------------------------------
/----------------------------------------------

* Preferable type of the using style of a goto statement: 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	goto out;
out:;
}
```

/----------------------------------------------
/----------------------------------------------

* Not preferable type of the using style of goto statement: 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
out:;
	goto out;
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Without using goto statement, how to jump to the end of outermost loop? 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_true(int, int, int);

int main() {

	int flag = 0;

	for (size_t i = 0; i < 1'000'000; ++i)
	{
		//...
		for (size_t j = 0; i < 10'000; ++j)
		{
			//...
			for (size_t k = 0; k < 100; ++k)
			{
				//...
				if (is_true(i,j,k))
				{
					//..
					flag = 1;
					break;
				}
			}
			// 1: with using of break
			if (flag)
				break;
		}
		// 2: 
		if (flag)
			break;
	}
	// 3: with using of If - flag - break
}
```

/----------------------------------------------
/----------------------------------------------

* Example: With using goto statement, how to jump to the end of the outermost loop? 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_true(int, int, int);

int main() {

	int flag = 0;

	for (size_t i = 0; i < 1'000'000; ++i)
	{
		//...
		for (size_t j = 0; i < 10'000; ++j)
		{
			//...
			for (size_t k = 0; k < 100; ++k)
			{
				//...
				if (is_true(i,j,k))
				{
					//..
					goto out;
				}
			}// 1
		}// 2
	}// 3 : with using goto statement 
	
out:
	//...
	;
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Goto statement example with if-else block

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SUCCESS 1
#define ERROR   0

int allocate_memory(void) {
	//...
	return 1;
}

int setup_interrupts(void) {
	//...
	return 1;
}

int setup_registers(void) {
	//...
	return 0;
}

void teardown_interrupts(void) {}
void free_memory(void){}


int init_device(void) {

	if (allocate_memory() != SUCCESS) goto out1;
	if (setup_interrupts() != SUCCESS) goto out2;
	if (setup_registers() != SUCCESS) goto out3;
	//...
	return SUCCESS;
out1:
	teardown_interrupts();
out2:
	free_memory();
out3:
	return ERROR;
}

int main() {
	if (init_device()) {
		printf("The initialization is successful");
	}
}
```

/----------------------------------------------
/----------------------------------------------

* The same function defining with different style of code for the previous example (specifically "int init_device(void)" function): 

```cpp
int init_device(void) {

	if (allocate_memory() == ERROR) 
		goto out1;
	if (setup_interrupts() == ERROR) 
		goto out2;
	if (setup_registers() == ERROR) 
		goto out3;
	//...
	return SUCCESS;
out1:
	teardown_interrupts();
out2:
	free_memory();
out3:
	return ERROR;
}
```

/----------------------------------------------
/----------------------------------------------
