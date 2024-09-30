#include <stdio.h>

int main()
{
    do {
    int x1,y1,x2,y2,x,y;
    printf("Vuvedete x1: ");
    scanf("%d", &x1);
    printf("Vuvedete y1: ");
    scanf("%d", &y1);
    printf("Vuvedete x2: ");
    scanf("%d", &x2);
    printf("Vuvedete y2: ");
    scanf("%d", &y2);
    printf("Vuvedete x: ");
    scanf("%d", &x);
    printf("Vuvedete y: ");
    scanf("%d", &y);
    } while (x1<x2 && y1<y2);

    if (x<=x2 && x>=x1 && y<=y2 && y>=y1)
    {
        printf("Inside");
    }
    else {
        printf("Outside");
    }

    return 0;
}
