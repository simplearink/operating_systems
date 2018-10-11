#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>


int main(){
	char * mem;
	for (int i = 0; i < 10; i++) {
		mem = malloc(10485760);
		struct rusage use;
		memset(mem, 0, 10485760);
		getrusage(RUSAGE_SELF, &use);
		printf("Iteration: %d \n", i);
		printf("max resident set size: %ld \n", use.ru_maxrss);
		printf("integral shared memory size: %ld\n", use.ru_ixrss);
		printf("integral unshared data size: %ld\n", use.ru_idrss);
		printf("integral unshared stack size : %ld\n", use.ru_isrss);
		printf("page reclaims (soft page faults): %ld\n", use.ru_minflt);
		printf("page faults (hard page faults): %ld\n", use.ru_majflt);
		printf("swaps: %ld \n", use.ru_nswap);

		sleep(1);
	}
	
	return 0;
}