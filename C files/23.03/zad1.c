#include <stdio.h>

int main(){
    int vreme, vreme1, vreme2, vreme3, min, sek;
do {
        printf("Vuvedete vremena: ");
        scanf("%d", &vreme1);
        scanf("%d", &vreme2);
        scanf("%d", &vreme3);

} while (vreme1>=50 || vreme2>=50 || vreme3>=50);
vreme = vreme1 + vreme2 + vreme3;
min = vreme/60;
sek= vreme%60;
if (sek<10){
    printf("%d:0%d", min, sek);
            }
            else {
                printf("%d:%d", min, sek);
}


    return 0;
}
