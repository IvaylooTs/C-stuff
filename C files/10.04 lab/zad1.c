#include <stdio.h>

int main() {
   int N = 5;

    FILE *zad1 = fopen("zad1.bin", "wb");


    int arr[] = {N, 1, 3, 4, 8, 6};

    fwrite(arr, sizeof(arr[0]), N + 1, zad1);

    fclose(zad1);
    return 0;
}
