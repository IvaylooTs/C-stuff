#include <stdio.h>
#include <stdlib.h>

int globalVariable; // goleminata na promenlivta e 0 zatova e hubavo da gi inicializirame
// naprimer int globalVariable = 0
static int a=1;

void CMemberPrint(void);

int main()
{
    printf("Hello world!\n");
    printf("Global Variable default value:%d\n", globalVariable);
    {
        int Val;
        printf("loval block value:%d\n", Val);
    }
    CMemberPrint();
    return 0;
}

void CMemberPrint(void)
{
    char * txt = "Text stream";
    char c = 0x30;
    char cc = 0xFF;
    unsigned char uc = 10;
    short sval = 30;
    int intval = 3333;
    unsigned int uint= 0xFFFFFFFFF;
    unsigned long ulong = 0xFFFFFFFF;
    double dval = 3.9;
    float fval = -5.0;
    uint = (unsigned int)cc&0x000000ff; //bitova maska za da iskarA 255
    printf("%c=%u\n",c,c);
    printf("%u or %d\n", uint, cc);
    for (int a=0; a<4;a++)
        for(int b=0;b<4;b++)
            printf("a(%u)&b (%u) = %u\n",a,b, (a&b)&0xFF);
}
