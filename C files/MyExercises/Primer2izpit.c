#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int code;
    char PersonName[30];
    char PicName[30];
    float price;
} Picture;

float Sredno(Picture arr[], int count, float price) {
    float sum = 0;
    float broi = 0;
    for (int i=0; i<count; i++){
        if (price < arr[i].price){
            sum+=arr[i].price;
            broi++;
        }
    }
    if (sum == 0){
        return 0;
    }
    else {
        return sum/broi;
    }
}

int AddToFile(Picture arr[], int count, char letter){
    int broi=0;
    FILE *info = fopen("info.txt", "a");
    if (info == NULL){
        printf("Error opening file!");
    }
    for (int i=0; i<count; i++){
        if (letter == arr[i].PersonName[0]){
            fprintf(info, "%d;%s;%f leva", arr[i].code, arr[i].PicName, arr[i].price);
            broi++;
        }
    }
    return broi;
    fclose(info);
}

void ReadFromBin(char painter[]){
    FILE *picture = fopen("picture.bin", "rb");
    if (picture == NULL){
        printf("Error opening file!");
    }
    Picture pic;
    while (feof(picture)!=1){
        int size;
        int sizepic;
        fread(&pic.code, sizeof(int), 1, picture);
        fread(&size, sizeof(int), 1,picture);
        fread(&pic.PersonName, sizeof(char),size, picture);
        pic.PersonName[size]='\0';
        fread(&sizepic, sizeof(int), 1,picture);
        fread(&pic.PicName, sizeof(char),sizepic, picture);
        pic.PicName[sizepic] == '\0';
        fread(&pic.price, sizeof(float),1, picture);


        if(strcmp(pic.PersonName, painter)==0){
            printf("%s\n%f", pic.PicName, pic.price);
        }
        }
        fclose(picture);
    }



int main(){
    int n;
    printf("N na broi el: ");
    scanf("%d", &n);
    while (n>=30 || n<=3) {
        printf("n ne otgovarq na uslovieto, molq vuvedete novo n\nN:");
        scanf("%d", &n);
        }

    Picture *pictures = (Picture *)calloc(n, sizeof(Picture));
    if (pictures == NULL) {
        printf("Error!");
        exit(0);
    }
    for (int i=0; i<n; i++){
        scanf("%d", &pictures[i].code);
        getchar();
        fgets(pictures[i].PersonName, 30, stdin);
        fgets(pictures[i].PicName,30,stdin);
        scanf("%f", &pictures[i].price);
        getchar();
    }

    free(pictures);
    return 0;
}
