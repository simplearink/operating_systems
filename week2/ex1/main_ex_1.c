#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int i = INT_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;
    printf("The size of max int is %zu and the value is %d\n", sizeof(i), i);
    printf("The size of max float is %zu and the value is %f\n", sizeof(f), f);
    printf("The size of max double is %zu and the value is %lf\n", sizeof(d), d);
    return 0;
}