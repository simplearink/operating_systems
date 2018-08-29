#include <stdio.h>
void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int main() {
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	swap(&a, &b);

	printf("%d\n", a);
	printf("%d\n", b);


	return 0;
}