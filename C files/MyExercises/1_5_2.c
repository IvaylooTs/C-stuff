#include <stdio.h>
/* character counting

int main(){
    long nc;
    nc = 0;
    while (getchar()!= EOF)
        ++nc;
    printf("%ld\n", nc);
    return 0;
}   */

/*line counting

int main()
{
    int c,nl;
    nl = 0;
    while ((c = getchar()) != EOF){
        if (c == '\n')
            ++nl;
    }
    printf("%d\n", nl);
    return 0;
}
*/

//ex 1-8

int main()
{
    int c,nl;
    nl = 0;
    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\t' || c=='|n')
            ++nl;
    }
    printf("%d\n", nl);
    return 0;
}
