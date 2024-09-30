//konvertor ot inch kum mm, dm, cm, m

#include <stdio.h>

int main() {
    float inch, cm, mm, dm, m;
    printf("Vuvedete inchove: ");
    scanf("%f", &inch);
    cm = inch *2.54;
    mm = cm * 10.0;
    dm = cm/ 10.0;
    m = cm/ 100.0;
    printf("Vuvedenite inch %6.2f sa =\n %6.2f cm,\n %6.2f dm,\n %6.2f mm,\n %6.2f m.\n", inch, cm, dm, mm, m);

    return 0;

}
