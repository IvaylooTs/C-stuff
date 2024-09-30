#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    int arr[N][M];

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++) {
            printf("arr[i][j] = ");
            scanf("%d", &arr[i][j]);

        }
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++) {
            printf("%d\n", arr[i][j]);


        }
    }
    for (int i=0; i<N-1; i++){
        for (int j=0; j<M-1; j++) {
            if (arr[i][j]>arr[i][j+1]) {
                printf("False");
                break;
            }
            if (arr[i][j]<arr[i+1][j]) {
                printf("False");
                break;
            }
        }
    }

    return 0;
}
