#include <stdio.h>
#define ARR_SIZE(a) (sizeof(a) / sizeof(*a))

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					swap(&arr[j], &arr[j+1]);
				}
		}
	}
}

void print_array(int arr[], int size) {
	for (int i = 0; i < size; i ++) {
		printf("%d\n", arr[i]);
	}
}

int main(){

	int array[] = {5, 4, 3, 2, 1};
	bubble_sort(array, ARR_SIZE(array));
	print_array(array, ARR_SIZE(array));

	 
	return 0;
}