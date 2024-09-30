#include <stdio.h>

void AB() {
    int sum(int a, int b) {
        int total = 0;
        for (int i = a; i <= b; i++) {
            total += i;
        }
        return total;
    }

    int x , y ;
    scanf("%i", &x);
    scanf("%i", &y);
    printf("The sum of integers between %d and %d is %d\n", x, y, sum(x, y));
}

int main() {
    AB();
    return 0;
}
