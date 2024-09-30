#include <stdio.h>

int main()
{
    int n;
    char day;
    float taxi, bus, train;

    printf("Vuvedete broi km: \n");
    scanf("%d", &n);
    // scanf("%c");
    fflush(stdin); // tova go pishem da izchistim scanf-a shtoto sega iskame char a predi e zapametilo chislo v bufera
    printf("Vuvedete den ili nosht(D/N): \n");
    scanf("%c", &day);

    printf("Za vashite km %d, Cenite sa: \n", n);

    if (day == 'D') {
        taxi = 0.70+n*0.79;
    }
    else {
        taxi = 0.70+n*0.90;
    }
    printf("Taxi: %.2f\n", taxi);

    if (n>=20) {
        bus = 0.09*n;
        printf("Bus: %.2f\n", bus);
    }
    else {
        printf("Bus moje samo nad 20 km.\n");
    }
    if (n>=100) {
        train = 0.06*n;
        printf("Train: %.2f\n", train);
    }
    else{
        printf("train moje samo nad 100km\n");
    }


    return 0;
}
