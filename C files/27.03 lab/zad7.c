#include <stdio.h>


int main() {
    int nomer = 1;
    int size;

    printf("Broi studenti: ");
    scanf("%d", &size);

    float student[size];
    float percent, average, sum = 0;


    for (int i=0; i<size; i++){
        printf("Uspeh: ");
        scanf("%f", &student[i]);
        sum += student[i];
    }

    average = sum/(float)size;
    printf("average: %.2f\n", average);


    for (int i=0; i<size; i++) {
        percent = (student[i]/average)*100;
        printf("Nomer: %d: Uspeh sprqmo sredniq: %.2f%%\n", nomer, percent);
        nomer++;
    }

    return 0;
}
