#include <stdio.h>
#include <stdlib.h>

int main(int argv, char**argc) {
	int n = atoi(argc[1]);
    for (int i = 1; i <= n; i++) {
    	for (int j = n - i; j >= 1; j--) {
    		printf(" ");
    	}
    	for (int b = 2*i - 1; b >= 1; b--) {
    		printf("*");
    	}
    	printf("\n");
    }
	return 0;
}