#include <stdio.h>

void swap_arrays(int *arr1, int *arr2, int size) {
    for (int i = 0; i < size; i++) {
        int temp = *arr1;
        *arr1 = *arr2;
        *arr2 = temp;
        arr1++;
        arr2++;
    }
}

int main() {
    int arr1[100];
    int arr2[100];
    int length;
    printf("Number of digits: ");
    scanf("%d", &length);

    for(int i = 0;i<length; i++ )
    {
        scanf("%d", &arr1[i]);
    }

    for(int i = 0;i<length; i++ )
    {
        scanf("%d", &arr2[i]);
    }

    printf("Original arrays:\n");
    printf("arr1: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\narr2: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    swap_arrays(arr1, arr2, length);

    printf("Swapped arrays:\n");
    printf("arr1: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\narr2: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}
