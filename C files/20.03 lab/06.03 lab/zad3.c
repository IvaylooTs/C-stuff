#include <stdio.h>
int main(){
    double n1, n2, n3, nsmall = n1;
    scanf("%lf", &n1);
    scanf("%lf", &n2);
    scanf("%lf", &n3);
    if (n1>n2){
        nsmall = n2;
    }
    if (n2>n3) {
        nsmall = n3;
    }
    printf("%lf is the smallest" , nsmall);
    return 0;
}
