#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char code[2];
    char name[20];
    int weight;
    float priceKG;
} IceCream;

float allPrice(IceCream arr[], int count, char letter) {
    float sum = 0;
    for (int i=0; i<count; i++){
       // char temp[2] = { arr[i].name[0], '\0' };
       // if (strcmp(temp, &letter) == 0)
            if (arr[i].name[0] == letter) {
            sum += arr[i].priceKG;
        }
    }
    if (sum == 0) {
        return 0;
    }
    else {
        return sum;
    }
}

int AddToFile(IceCream arr1[], int count1, float price, int kilo) {
    int AddCount=0;
    FILE *info = fopen("info.txt", "a");
    if (info == NULL) {
        printf("Грешка при отваряне на файл.\n");
        exit(1);
    }
    for (int i=0; i<count1; i++){
        if (arr1[i].priceKG < price && arr1[i].weight > kilo){
            fprintf(info, "%s;%s;%d;%f leva", arr1[i].code, arr1[i].name, arr1[i].weight, arr1[i].priceKG);
            AddCount++;
        }
    }

    fclose(info);
    if (AddCount == 0){
        return 0;
    }
    else {
    return AddCount;
    }
}

void Check(char ProCode[2]) {
    FILE *icecream = fopen("icecream.bin", "rb");
    if (icecream == NULL) {
        printf("Грешка при отваряне на файл.\n");
        exit(1);
    }
    int check=0;
    IceCream cream;
    while (fread(&cream, sizeof(cream), 1, icecream) == 1){
            if(strcmp(cream.code, ProCode)==0) {
                printf("%s,\n %f", cream.name, cream.priceKG);
                check++;
            }

    }
    if (check == 0){
        printf("No products!");
    }
    fclose(icecream);
}



int main(){

    int n;
    printf("N broi elementi mejdu 5 i 15: ");
    scanf("%d", &n);
    while (n>=15 || n<=5) {
        printf("n ne otgovarq na uslovieto, molq vuvedete novo n\nN:");
        scanf("%d", &n);
        }

    IceCream *products = (IceCream *)malloc(n * sizeof(IceCream));
    if (products == NULL) {
        printf("Error!");
        exit(0);
    }
    for (int i=0; i<n; i++){
        fgets(products[i].code, 2, stdin);
        fgets(products[i].name, 20, stdin);
        scanf("%d", &products[i].weight);
        scanf("%f", &products[i].priceKG);
    }

    free(products);
    return 0;
}
