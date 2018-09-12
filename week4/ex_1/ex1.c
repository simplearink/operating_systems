#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 

int main() {
	int n = 6;
    fork();
    if (fork() == 0) 
        printf("Hello from child [%d]\n", getpid() - n);
  
    // parent process because return value non-zero. 
    else
         printf("Hello from parent [%d]\n", getpid() - n);
    return 0;
}