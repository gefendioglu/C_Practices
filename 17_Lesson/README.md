## goto statement 
- jumping another line of project
    - long jump: f5-f4-f3-f2-f1 sýralý jumping yerine f5-f1 jump yapýldýðýnda
    - local jump (near jump): ayný state frame içinde (ayný yerel deðiþkenlerin bulunduðu alanda - yani C gibi bir dilde ayný fonksiyon içinde) yapýlan sýçramalardýr.  
    - long ve local jump iþlemleri farklý syntaxlar ile ifade ediliyor olabilir. 
    - local jump --> goto (C, C++)
    - long jump  --> standard kütüphanenin bazý fonksiyonlarý ile yapýlýr. (setjmp, longjmp)
      - setjmp: saves the context
      - longjmp: jumps to specified location
- program akýþýný bir noktadan baþka bir noktaya yöneltmektir. 


* goto kullanma sebepleri: (alýnan ekran görüntüsünden ekleme yapýlacak!!!)
- Cleanly exiting a function 
- Exiting nested loops
- low level performance improvements (only for performance critical codes)


* labels : fonksiyon içinde tanýmlanan isimlerdir. 
- function scope'a dahildir. Bir label fonksiyon içinde herhangi bir noktada kullanýlabilir. 
- labellar sadece goto deyimleri ile birlikte kullanýlmaktadýr. 
- goto out; --> ile ilk out: labeline ait statement'a atlar ve o satýrdan itibaren program akýþý devam eder. 
- out: label mutlaka NULL bile olsa bir statement a sahip olmalýdýr. --> out: ;
- ayný label birden fazla kez ayný function scope altýnda kullanýlamaz.
- kodun okunabilirliðini, test edilebilmesini ve deðiþtirilebilmesini zorlaþtýrdýðý için genellikle kullanýmý tercih edilmez.
- switch-case bloklarýnda yer alan case isimlendirmeleri de labeldýr.
- hangi senaryolarda goto kullanýmý tercih edilmektedir? 
    - goto kullanýmý ile program akýþý daha öncesinde bir noktaya yönlendiriliyorsa, bu durumda kötü bir kullaným yapýldýðý söylenebilir. 
    - iç içe döngülerin hepsinden çýkmak için kullanýmý yaygýndýr. 
    
/----------------------------------------------
* Preferable usage of goto statement: 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	goto out;

out:;
}

/----------------------------------------------
* Not preferable usage of goto statement: 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

out:;

	goto out;
}

/----------------------------------------------
/----------------------------------------------

* Example: Without using goto statement, how to jump to the end of the outermost loop 
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
	// 3: with using of If - flag - break - not guaranteed
}

/----------------------------------------------
/----------------------------------------------

* Example: With using goto statement, how to jump to the end of the outermost loop? 
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

/----------------------------------------------
/----------------------------------------------

* Example: Goto statement

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

/----------------------------------------------
/----------------------------------------------

* The same function defining with different style of code for the previous example (specifically int init_device(void) function): 

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

/----------------------------------------------
/----------------------------------------------
