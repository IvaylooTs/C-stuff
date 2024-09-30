#include <stdio.h>

int main()
{
    char arr[6][2] = {{'a', 20},
                     {'b', 30},
                     {'c', 44},
                     {'d', 55},
                     {'e', 0xAA},
                     {'f', 77}};

    char input = getc(stdin);
    switch (input)
    {
        case 'a': printf("%d", arr[0][1]);
        break;
        case 'b': printf("%d", arr[1][1]);
        break;
        case 'c': printf("%d", arr[2][1]);
        break;
        case 'd': printf("%d", arr[3][1]);
        break;
        case 'e': printf("%d", arr[4][1]);
        break;
        case 'f': printf("%d", arr[5][1]);
        break;
    }
    return 0;
}
