//gradusi po celsii na farenhait

#include <stdio.h>

int main()
{
    float cel, fahr;
    printf("Vuvedete temperatura v Cel: ");
    scanf("%f", &cel);
    fahr = cel * 1.8 + 32.0;
    printf("%f Cel => %f Fahr", cel, fahr);
    return 0;
}
