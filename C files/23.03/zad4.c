#include <stdio.h>

int main()
{
    float V, t1, t2, N, pulno;
    printf("V: ");
    scanf("%f", &V);
    printf("t1: ");
    scanf("%f", &t1);
    printf("t2: ");
    scanf("%f", &t2);
    printf("N: ");
    scanf("%f", &N);

    V *=1000;
    pulno = N*(t1+t2);

    if (pulno>V){
        printf("Baseinut preliva s %.2f litra", V-pulno);
    }
    else {
        printf("Baseinut e pulen s %.2f litra", pulno);
    }


    return 0;
}
