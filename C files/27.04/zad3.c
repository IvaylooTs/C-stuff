#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, current, biggest = 0, smallest = 1000000, indlow, indbig;
    scanf("%d", &N);
    scanf("%d", &M);

    int arr[N][M];
    int arr1[N][M];
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++) {

            arr[i][j] = rand()%20;
            arr1[i][j] = arr[i][j];
        }
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++) {
            printf("%2d ", arr[i][j]);


        }
        printf("\n");
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++) {
            current  = arr[i][j];
            if (biggest<current) {

                indbig = i;
            }
            if (smallest>current){

                indlow = i;
            }
        }
    }

    for (int j=0; j<M; j++) {
        arr1[indbig][j] = arr[indlow][j];
        arr1[indlow][j] = arr[indbig][j];
    }

    printf("\n");

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++) {
            printf("%2d ", arr1[i][j]);
        }
        printf("\n");
    }


    return 0;
}
