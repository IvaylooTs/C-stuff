#include <stdio.h>
#define SIZE 50


int main()
{
    char text[SIZE];
    fgets(text, SIZE, stdin);
    int count = 0;

    for (int i=0; i<SIZE; i++){
        if ((text[i] >= '0' && text[i] <= '9') || (text[i]>='A' && text[i]<='Z') || (text[i]>='a' && text[i]<='z')) {
            count++;
            }
    }

    printf("%d", count-1);


    return 0;
}
