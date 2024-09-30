#include <stdio.h>

int main()
{
    int T;
    int size;
    scanf("%d", &size);
    int arr[size];

    for (int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    for (int i=1; i<size-1; i++){
    if (i%2 == 1 && arr[i]<arr[i-1] && arr[i]<arr[i+1]) {
            printf("False");
            break;
    }
    else {
        printf("True");
        break;

    }
    }

    return 0;
}
