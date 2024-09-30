#include <stdio.h>
#define SIZE 10

int main()
{
    int numbers[SIZE];
    int positive[SIZE];
    int len = sizeof(numbers)/sizeof(int);
    int j = 0;

    for (int i=0; i<SIZE; i++){
    scanf("%d", &numbers[i]);
    }


    for (int i=0; i<SIZE; i++) {
        if (numbers[i] >= 0) {
            positive[j] = numbers[i];
            j++;
        }
    }
    for (int i=0; i<SIZE; i++){
    printf("%d, ", numbers[i]);
    }
    printf("\n");
    for (int i = 0; i < j; i++) {
        printf("%d, ", positive[i]);
    }
    return 0;

}
