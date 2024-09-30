#include <stdio.h>

int main() {
    int N, K, i, numOfNums = 0, currNum;
    scanf("%i", &N);
    scanf("%i", &K);
    for (i = 1; i<=N; i++) {
        printf("num = ");
        scanf("%i", &currNum);
        if (currNum>K && currNum%3==0){
            numOfNums++;
        }
    }
    printf("number of numbers: %i", numOfNums);
    return 0;
}
