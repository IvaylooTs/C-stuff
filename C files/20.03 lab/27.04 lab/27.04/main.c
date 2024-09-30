#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATETIME 50
#define PRODUCT 30
#define CURRENCY 5
#define BUYER 50

    typedef struct {
        char datetime[DATETIME];
        char product[PRODUCT];
        double price;
        char currency[CURRENCY];
        char buyer[BUYER];
    } Sale;

void add_sale(FILE *zad1) {
    Sale sale;
    printf("Enter date: ");
    fgets(sale.datetime, DATETIME, stdin);
    printf("Enter product name: ");
    fgets(sale.product, PRODUCT , stdin);
    printf("Enter price: ");
    scanf("%lf", &sale.price);
    printf("Enter currency: ");
    fgets(sale.currency, CURRENCY, stdin);
    printf("Enter buyer name: ");
    getchar(); // maha \n
    fgets(sale.buyer, BUYER, stdin);

    fprintf(zad1,"%s, %s, %.2lf, %s,\n %s\n", sale.datetime, sale.product, sale.price, sale.currency, sale.buyer);

}

int main()
{
    char choice = 'y';
    FILE *zad1 = fopen("zad1.txt", "a");
    if (zad1 == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (choice == 'y') {
        add_sale(zad1);
        printf("Do you want to add another sale? (y/n): ");
        scanf(" %c", &choice);
    }
    fclose(zad1);



    return 0;
}
