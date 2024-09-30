#include <stdio.h>

int main()
{
    int a;
    scanf("%i", &a);
    if (a<1 || a>7) {
        printf("You must enter a number between 1 and 7!");
    }
    else if (a>0 && a<8) {
        switch (a){
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    case 7:
        printf("Sunday");
        break;
        }
    }
    return 0;
}
