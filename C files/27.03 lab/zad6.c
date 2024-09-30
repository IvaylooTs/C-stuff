#include <stdio.h>
#include "sizeofarrayforZAD6.h"
#include <limits.h>

int main() {
    int arr[SIZE];
    int sum = 0;
    int product = 1;
    int min = INT_MAX, max = INT_MIN;


    for (int i = 0; i < SIZE; i++) {
        printf("Number: ");
        scanf("%d", &arr[i]);
        sum += arr[i];
        product *= arr[i];
        if (arr[i] > max){
            max = arr[i];
        }
        if (arr[i]<min) {
            min = arr[i];
        }
    }
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);

    return 0;
}
