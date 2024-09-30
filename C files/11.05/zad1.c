#include <stdio.h>
#include <string.h>
#define CHAIR 13.99
#define TABLE 42.00
#define GLASS 5.98
#define PLATE 21.02

int main()
{
   int guest, T=0, countC=0, countT=0, countG=0, countP=0;
   float sum=0;
   printf("Enter guests: ");
   scanf("%d", &guest);
   char all[4][20] = {"Chair", "Table", "Glass","Plate" };
   char purchase[20];

   while (T!=1) {
    scanf("%s", &purchase);
    if (strcmp(purchase, "PARTY!") == 0) {
        T=1;
    }
    else if (strcmp(purchase, all[0]) == 0) {
        sum += CHAIR;
        countC++;
    }
    else if (strcmp(purchase, all[1]) == 0) {
        sum += TABLE;
        countT++;;
    }
    else if (strcmp(purchase, all[2]) == 0) {
        sum += GLASS;
        countG+=6;
   }
   else if (strcmp(purchase, all[3]) == 0) {
        sum += PLATE;
        countP+=6;
   }
   }

    printf("\n");
    printf ("%.2f\n", sum);
    if (guest>countC) {
        printf("%d Chairs\n", guest-countC);
    }
    if (guest>countT*8) {
        printf("%d Tables\n", guest - ((countT*8)/8));
    }
    if (guest>countG) {
        printf("%d Glasses\n", guest-countG);
    }
    if (guest>countP) {
        printf("%d Dishes\n", guest-countP);
    }

    return 0;
}
