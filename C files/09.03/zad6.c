/* postavqt se plochki, ploshtadkata e kvadrat sus strana N metra, plochkite sa
pravougulni na ploshtadkata ima peika s shirina M metra i duljina O metra
pod neq ne e nujno da se slagat plochki. vsqka plochka se postavq za o.2 min.
chetat se ot konzolata razmerite na ploshtadkata, plochkite i peikata
i presmqta kolko plochki sa nujni i vremeto za postavqne */

#include <stdio.h>
#include <math.h>

int main()
{
    float N, plochkaSH, plochkaDul, M, O, vreme , liceKV, licePL, licePeika, Plochki;
    printf("Vuvedete strana N: ");
    scanf("%f", &N);
    printf("Vuvedete plochkaSH: ");
    scanf("%f", &plochkaSH);
    printf("Vuvedete plochkaDul: ");
    scanf("%f", &plochkaDul);
    printf("Vuvedete duljina O: ");
    scanf("%f", &O);
    printf("Vuvedete shirina M: ");
    scanf("%f", &M);

    licePeika = M*O;
    liceKV = (N*N) - licePeika;
    licePL = plochkaSH*plochkaDul;
    Plochki = ceil(liceKV/licePL);
    vreme = 0.2*Plochki;

    printf("Trqbvat %.0f plochki, shte budat slojeni za %0.2f min", Plochki, vreme);


    return 0;
}
