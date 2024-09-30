#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main()
{
    int numbers[SIZE];
    int length;
    printf("Number of digits: ");
    scanf("%d", &length);

    for(int i = 0;i<length; i++ )
    {
        scanf("%d", &numbers[i]);
    }

    for(int i = 0;i<length; i++ )
    {
        numbers[i]*=numbers[i];
        printf("%d\n", numbers[i]);
    }
    return 0;
}
