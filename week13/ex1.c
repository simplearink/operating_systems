#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int is_in(int v, int *arr, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] = v)
			return 1;
	}
	return 0;
}

int ri_less_a(int *r, int *a, int size) {
	for (int i = 0; i < size; i++) {
		if (a[i] < r[i]) {
			return 0;
		}
	}
	return 1;
}

int main(int argv, char**argc) {
	int dev = atoi(argc[1]);
	int pr = atoi(argc[2]);

	FILE* fp;

	fp = fopen("input.txt", "r");
	int *e = malloc(dev*sizeof(int));
	int *a = malloc(dev*sizeof(int));
	int c[pr][dev];
	int r[pr][dev];

	for (int i = 0; i < dev; i++) {
		int k;
		fscanf(fp, "%d", &k);
		e[i] = k;
	}

	for (int i = 0; i < dev; i++) {
		int k;
		fscanf(fp, "%d", &k);
		a[i] = k;
	}

	for (int i = 0; i < pr; i++) {
		for (int j = 0; j < dev; j++) {
			int k;
			fscanf(fp, "%d", &k);
			c[i][j] = k;
		}
	}

	for (int i = 0; i < pr; i++) {
		for (int j = 0; j < dev; j++) {
			int k;
			fscanf(fp, "%d", &k);
			r[i][j] = k;
		}
	}

	fclose(fp);

	int marked[pr];
	int n = 0; 
	int nodead = 0;

	while (n < pr) {
		if ((is_in(n, marked, pr) == 0) && (ri_less_a(r[n], a, pr) == 1)) {
			for (int i = 0; i < pr; i++) {
				a[i] += c[n][i];
			}
			marked[nodead] = n;
			nodead++;
			n = -1;
		}
		n++;
	}

	int detector = 0;

	for (int j = 0; j < pr; j++) {
		if (is_in(pr, marked, pr) == 0) {
			printf("Process with deadlock: %d\n", j);
			detector++;
		}
	}

	if (detector == 0) {
		printf("No deadlocks detected!\n");
	}

  	return 0;
   }