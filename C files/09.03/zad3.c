//prodava zelenchuci za N leva na kg i plodove za M na kg.
//Programa na prihodite na rekoltata v evro ako evroto e 1.95 leva.
//Ot konzolata se chetat 4 chisla po edno na red. Purvi red cena za kg zelenchuci.
//2ri red cena za kg plodove.
//3ti obsht kilo na zelenchuchite CQLO CHISLO
//4ti red OBSHTO kilo na plod CQLO CHISLO

#include <stdio.h>

int main()
{
    float N, M, euro = 1.95, prihod;
    int kiloZ, kiloP;
    printf("Cena na kg zelenchuci: ");
    scanf("%f", &N);
    printf("Cena za kg plodove: ");
    scanf("%f", &M);
    printf("Obshto kilo na zelenchucite: ");
    scanf("%i", &kiloZ);
    printf("Obshto kilo na plod: ");
    scanf("%i", &kiloP);

    prihod = (kiloZ*N + kiloP*M) / euro;
    printf("Prihodi: %f euro", prihod);


    return 0;

}
