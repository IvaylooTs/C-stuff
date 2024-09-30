#include <stdio.h>

int main() {

    float X, Y, Z, rekolta,vino, litur;

    printf("Plosht X: ");
    scanf("%f", &X);
    printf("Ot 1 kv metur Y kg loze: ");
    scanf("%f", &Y);
    printf("Kolichestvo za prodan Z: ");
    scanf("%f", &Z);

    rekolta = X*Y;
    printf("Rekolta: %f\n", rekolta);
    vino = (40*rekolta)/100;

    litur = vino/2.5;
    printf("Litri: %f\n", litur);

    if (litur>Z) {
        litur -= Z;
        printf("Ostava %f litra vino", litur);
    }
    else {
        Z-=litur;
        printf("Ne dostigat %f litra", litur);
    }



    return 0;
}
