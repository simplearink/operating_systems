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

int print_right_triangle(int height) {
    for (int i = 1; i <= height; i++) {
            for (int j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }

    return 0;
}

int print_arrow(int height) {
    if (height % 2 == 1) {
        for (int i = 1; i <= height/2 + 1; i++) {
                for (int j = 1; j <= i; j++) {
                    printf("*");
                }
                printf("\n");
            }
        for (int i = height/2; i >= 1; i--) {
                  for (int j = i; j >= 1; j--) {
                    printf("*");
            }
                printf("\n");
            }

    } else {
        printf("It's impossible :(");
    }

    return 0;
}

int print_rectangle(int height) {
    for (int i = 1; i <= height; i++) {
            for (int j = 1; j <= 10; j++) {
                printf("*");
            }
            printf("\n");
        }

    return 0;
}

int main(int argv, char**argc) {
    int n;
    int h;
    printf("Choose the shape:\n");
    printf("1 - triangle \n");
    printf("2 - a right triangle \n");
    printf("3 - an arrow\n");
    printf("4 - a rectangle \n");
    printf("Your choice is: \n");
	scanf("%d", &n);
    if (n < 1 && n > 4){
         printf("Something goes wrong :(\n" );
     } else {
        printf("What is the height?");
        scanf("%d", &h);
        if (n == 1) {
            print_triangle(h);
        } else if (n == 2) {
            print_right_triangle(h);
        } else if (n == 3) {
            print_arrow(h);
        } else {
            print_rectangle(h);
        }
    }

	return 0;
}