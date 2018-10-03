#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int main(int argv, char**argc) {
	int n = atoi(argc[1]);
    int *arr = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    for (int j = 0; j < n; j++) {
        printf("%d \n", arr[j]);
    }
    printf("Free the memory!\n");
    free(arr);

	return 0;
}