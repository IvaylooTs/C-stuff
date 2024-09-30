#include <stdio.h>

int main() {
    int a, b, sum = 0, i;
    scanf("%i", &a);
    scanf("%i", &b);
    for (i = a; i<=b; i++ ) {
            sum +=i;
        }
    if (a>b) {
        for (i = b; i<=a; i++){
            sum+=i;
        }
    }
    printf("%i", sum);
    return 0;
}
