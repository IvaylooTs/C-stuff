#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool a = true;
    int b, sum = 0;
    while (a){
        scanf("%i", &b);
        sum +=b;
        if (b==0) {
            a = false;
        }
    }
    printf("Sum: %i", sum);
    return 0;
}
