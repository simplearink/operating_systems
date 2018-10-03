#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_realloc(void *ptr, size_t currentSize, size_t newSize) {
    if (newSize == 0) {
        free(ptr);
    } else if (ptr == NULL) {
       return malloc(newSize);
    } else if (currentSize < newSize) {
        int *newArray = malloc(newSize);
        memcpy(newArray, ptr, currentSize);
        free(ptr);
        return newArray;

    } else if (currentSize > newSize) {
        return ptr;
    }
}

int main() {
    int *a1 = malloc(4*sizeof(int));
    a1[0] = 100;
    a1[1] = 200;
    a1[2] = 300;
    a1[3] = 0;
    a1 = my_realloc(a1, 4*sizeof(int), 10*sizeof(int));
    for (int i=0; i < 10; i++) {
        printf("%d ", a1[i]);
    }
    printf("\n");


	return 0;
}