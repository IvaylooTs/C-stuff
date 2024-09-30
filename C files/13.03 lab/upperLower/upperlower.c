#include <stdio.h>

char upperchar(char lower)
{
    char high;
    if (lower >= 'a' && lower <= 'z'){

       high = lower - 32;
       return high;

    }


}
