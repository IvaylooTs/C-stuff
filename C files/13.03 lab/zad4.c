#include <stdio.h>
#include <stdlib.h>

long factoriel(int num)
{
    long f = 1;
        for (int i=2; i <=num; i++){
        f *=i;

    }
    return f;
}

int main() {
    long x,num = 3, sum ;
    printf("Type X: ");
    scanf("%i", &x);
    while (1) {
        if (sum < 1e-10) {
            x*=x*(-x);
            num +=2;
            sum += (x)/(factoriel(num));
            printf("%ld", sum);
        }
        else if (sum > 1e-10){
            printf("%ld", sum);
            break;
        }

    }
    return 0;
}
