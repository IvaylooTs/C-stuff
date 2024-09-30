#include <stdio.h>

int main(){
int n = 0;
printf("n = ");
scanf("%i", &n);
if ((n%8) > 4) {
    printf("n%8 is >4");
}
return 0;
}
