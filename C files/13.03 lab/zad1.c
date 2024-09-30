#include <stdio.h>
// 1 zad
float temp(float fahr)
{
    float cel;
    cel = (fahr - 32)*5/9;
    return cel;
}

int main()
{
    float fahr;
    printf("Enter fahr: ");
    scanf("%f", &fahr);


    printf("%.2f Fahr = %.2f Cel", fahr, temp(fahr));
    return 0;
}
