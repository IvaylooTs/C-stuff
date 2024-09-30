#include <stdio.h>
#include "upperlower_H.h"


int main()
{
    char lower, upper;
    printf("Enter character: ");
    scanf("%c", &lower);
    upper = upperchar(lower);
    printf("Your %c upper char is %c.", lower, upper);
    return 0;
}
