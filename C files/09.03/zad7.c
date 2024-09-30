/* n dni v meseca, m dolari na den, v kraq na godinata bonus = 2.5 mesechni zaplati.
ot spechelenoto se zadurjat 25% danuk. kolko e chistata sredna pechalba na den v LEVA
dolara se chete ot klaviaturata */

#include <stdio.h>

int main()
{
    int N;
    float M, bonus, dolar, zaplata, godina;
    printf("Vuvedete dni v meseca: ");
    scanf("%i", &N);
    printf("Vuvedete dolari na den: ");
    scanf("%f", &M);
    printf("Vuvedete kurs na dolar: ");
    scanf("%f", &dolar);

    zaplata = M*N;
    bonus = 2.5*zaplata;
    godina = zaplata*12 + bonus;

    printf("Dnevna zaplata v lev: %f", godina/365*1.59*0.75);

    return 0;

}
