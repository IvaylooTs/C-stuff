#include <stdio.h>

int main() {
    FILE *zad1;
    zad1 = fopen("zad1.bin", "rb");
    int N = 0;
    fread(&N, sizeof(N), 1, zad1);
    int counter, counter1, swap_var;

    int arr[N];

    fread(arr, sizeof(arr[0]), N, zad1);


    for (counter = 0 ; counter < N - 1; counter++)
    {
    for (counter1 = 0 ; counter1 < N - counter - 1; counter1++)
    {
    if (arr[counter1] > arr[counter1+1])
    {
    swap_var        = arr[counter1];
    arr[counter1]   = arr[counter1+1];
    arr[counter1+1] = swap_var;
    }
    }
    }

    for (int i=0; i<N; i++) {
        printf("%d ", arr[i]);
    }


    return 0;
}
