#include <stdio.h>

int main() {
    int a, b, min, max,i, sum = 0, multip = 1;
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
    for (i = min; i<=max; i++ ) {
            if (i%2 ==0){
              sum +=i;
            }
            if (i%2 == 1) {
                multip *=i;
            }
    }
    printf("Sum: %i\n", sum);
    printf("Multiplication: %i", multip);
    return 0;
}
