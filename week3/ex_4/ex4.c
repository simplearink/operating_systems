#include <stdio.h>
#define ARR_SIZE(a) (sizeof(a) / sizeof(*a))

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high) {
	int piv = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (arr[j] < piv) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i+1], &arr[high]);
	return (i+1);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
	int pivot = partition(arr, low, high);

	quickSort(arr, low, pivot - 1);
	quickSort(arr, pivot + 1, high);
	}
}

void print_array(int arr[], int size) {
	for (int i = 0; i < size; i ++) {
		printf("%d\n", arr[i]);
	}
}

int main(){

	int array[] = {5, 4, 3, 2, 1};
	quickSort(array, 0, ARR_SIZE(array) - 1);
	print_array(array, ARR_SIZE(array));

	 
	return 0;
}