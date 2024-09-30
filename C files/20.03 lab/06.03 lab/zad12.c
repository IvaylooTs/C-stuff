#include <stdio.h>

int main() {
    int a, b, min, max,i, product;
    scanf("%i", &a);
    scanf("%i", &b);
    if (a>b) {
        max = a;
        min = b;
    }
    else {
        min = a;
        max = b;
    }
    for (i = min; i<=max; i++) {
        product = i*i-4;
        printf("Product of %i: %i\n", i,product);
    }
    return 0;
}
