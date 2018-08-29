#include <stdio.h>
#include <stdlib.h>
int print_triangle(int height) {
	for (int i = 1; i <= height; i++) {
    	for (int j = height - i; j >= 1; j--) {
    		printf(" ");
    	}
    	for (int b = 2*i - 1; b >= 1; b--) {
    		printf("*");
    	}
    	printf("\n");
    }

    return 0;
}

int main(int argv, char**argc) {
	int n = atoi(argc[1]);
    print_triangle(n);
	return 0;
}