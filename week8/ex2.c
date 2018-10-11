#include <stdlib.h>
#include <stdio.h>


int main(){
	char * mem;
	for (int i = 0; i < 10; i++) {
		printf("Allocating memory...");
		mem = malloc(10485760);
		memset(mem, 0, 10485760);
		sleep(1);
	}
	
	return 0;
}