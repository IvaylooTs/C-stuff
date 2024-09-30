// daden broi dni izvejda den ot sedmicata dneshniq den i
//broqt na dnite se vuvejda i denqt ot sedmicata
#include <stdio.h>

int main(){
    int dnes, broi, sled;
    scanf("%i", &dnes);
    scanf("%i", &broi);
    sled = (dnes+broi)%7;

    printf("Dnes: %i, Den sled %i broi dni: %i", dnes, broi, sled );
    switch(sled) {
    case 0: printf("Ponedelnik");
    break;
    case 1: printf("Vtornik");
    break;
    case 2: printf("Srqda");
    break;
    case 3: printf("Chetv");
    break;
    case 4: printf("Petuk");
    break;
    case 5: printf("Subota");
    break;
    case 6: printf("Nedelq");
    break;
    }
    return 0;
}
