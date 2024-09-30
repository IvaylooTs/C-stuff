#include <stdio.h>

int AB(){
    int a, b, sum = 0, i;
    scanf("%i", &a);
    scanf("%i", &b);
        int ABinner() {
            for (i = a; i<=b; i++ ) {
            sum +=i;
            }
            if (a>b) {
                for (i = b; i<=a; i++){
            sum+=i;
            }
        }
    return sum;
    }
    ABinner();
    printf("%i", sum);
}

int main()
{
    AB();
    return 0;
}
