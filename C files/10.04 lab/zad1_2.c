#include <stdio.h>

int main() {
    FILE *zad1;
    zad1 = fopen("zad1.bin", "rb");

    int N = 0;
    fread(&N, sizeof(N), 1, zad1);

    int arr[N], even = 0, odd = 0;

    fread(arr, sizeof(arr[0]), N, zad1);

    for (size_t i = 0; i < N; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    printf("Even: %d, Odd: %d\n", even, odd);

    fclose(zad1);
    return 0;
}
