#include <stdio.h>
#define SIZE 10

int main() {
    int arr[SIZE];
    int len = sizeof(arr) / sizeof(arr[0]);\
    int swap;

    printf("%d\n", len);


    for(int i = 0; i<SIZE; i++){
        arr[i] = rand()%20;
        printf("%d, ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i<SIZE/2; i++){
        int swap = arr[i];
        arr[i] = arr[len-i-1];
        arr[len-i-1]= swap;


    }
    for (int i = 0; i < SIZE; i++) {
        printf("%d, ", arr[i]);
    }

    return 0;
}
