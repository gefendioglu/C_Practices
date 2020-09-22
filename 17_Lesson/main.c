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