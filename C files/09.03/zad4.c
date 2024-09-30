/* Po dadeni koordinati na 2 sreshtupolojni ugula na pravougulnik,
namerete liceto na pravougulnika, ogranichen ot 2te tochki */

#include <stdio.h>
#include <math.h>


int main()
{
    float x1,x2,y1,y2, razlikaX, razlikaY, lice;
    printf("Vuvedete x1: ");
    scanf("%f", &x1);
    printf("Vuvedete y1: ");
    scanf("%f", &y1);
    printf("Vuvedete x2: ");
    scanf("%f", &x2);
    printf("Vuvedete y2: ");
    scanf("%f", &y2);
    //abs ot math.h vadi absolutna stoinost
    razlikaX = abs(x1-x2);
    razlikaY = abs(y1-y2);

    lice = razlikaX*razlikaY;
    printf("Lice = %f", lice);




    return 0;
}
