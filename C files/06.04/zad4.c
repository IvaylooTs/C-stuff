#include<stdio.h>

int main()
{
    int count = 0;
    int k, biggest = 0;
     printf("K: ");
    scanf("%d", &k);
    int size;
    printf("Size: ");
    scanf("%d", &size);
    int arr[size];
    int temp;
    int i, j;

    for (int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

     printf("Before Sorting ");


    for(i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }

    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++) {
                if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
     printf("\nAfter Sorting ");
    for(i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
 }

        printf("\n");

        for(i=0; i<size; i++) {
            if (count == k) {
                    break;
            }
            else if (biggest < arr[i]) {
                biggest = arr[i];
                count++;
            }


    }


    printf("%d", biggest);

 return 0;
}

