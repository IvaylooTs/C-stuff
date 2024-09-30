#include <stdio.h>



int main() {
    int k;
     printf("K: ");
    scanf("%d", &k);
    int size;
     printf("Size: ");
    scanf("%d", &size);
    int arr[size];
    int add[size];

    for (int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    for (int i=0; i<size; i++){
        printf("%d", arr[i]);
    }

    printf("\n");

    for (int i=0; i<size; i++) {
        if (i+k <size) {

            add[i+k] = arr[i];


        }
        else {

            add[i+k-size] = arr[i];

        }
    }
    for (int i=0; i<size; i++){
        printf("%d", add[i]);
    }
    return 0;
}
