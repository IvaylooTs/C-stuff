#include <stdio.h>
#include <stdlib.h>

long factoriel(int num)
{
    long f = 1;
        for (int i=2; i <=num; i++){
        f *=i;

    }
    return f;
}

long combination(unsigned int n,unsigned int p){
    long combination;
    combination = factoriel(n)/(factoriel(p)*factoriel(n-p));
    return combination;
}



int main()
{
    unsigned int n, p;

    printf("Type N: ");
    scanf("%u", &n);
    printf("Type P: ");
    scanf("%u", &p);

    printf("Combination: %ld", combination(n, p));
    return 0;

}
