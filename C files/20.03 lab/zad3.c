#include <stdio.h>
#include <string.h>
#define SIZE 100

void swap(char *left, char *right)
{
    char temp = *left;
    *left = *right;
    *right = temp;
}

int main() {

    char text[SIZE];
    int sum = 0;

    fgets(text, SIZE, stdin);

    for(int i = 0; i< strlen(text); i++)
    {
         if ((text[i] < 'A' || text[i] > 'Z') && (text[i] < 'a' || text[i] > 'z')){ //ako ne e bukva e razdelitel

            sum++;
        }
    }
    for(int i = 0; i< strlen(text)/2; i++)
    {
        swap(&text[i], &text[strlen(text) - 1 - i]);
    }

    printf("%s\n", text);

    printf("%d", sum);
    return 0;
}
