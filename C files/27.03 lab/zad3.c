#include <stdio.h>
#define SIZE 20

int main() {
    short arr[SIZE];
    int len = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;

    printf("%d\n", len);


    for(int i = 0; i<SIZE; i++){
        arr[i] = rand()%10;
        printf("%d, ", arr[i]);
    }
    printf("\n");


     for(int i = 1; i<SIZE; i++){
            if (arr[i]%i == 0) {
                sum +=arr[i];
            }
     }


    printf ("Sum = %d", sum);


    return 0;
}
