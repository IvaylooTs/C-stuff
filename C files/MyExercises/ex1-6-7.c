#include <stdio.h>
/* verify that  getchar != EOF is 0 or 1
int main()
{
    int c;
    c = getchar()!= EOF;
    printf("%i", c);
    return 0;
}
*/

int main()
{
    int c = EOF;
    printf("%i", c);
    return 0;
}
