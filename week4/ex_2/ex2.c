#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 

int main(int argv, char**argc) {
	int n = atoi(argc[1]);
    for (int i = 0; i < n; i++) {
    	fork();
    }
    sleep(5);
    return 0;
}