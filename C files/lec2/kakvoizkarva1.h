#include <studio.h>
#define PRINT(format,x) prinf(""#x" = %"#format"\n",x)
int integer = 5;
char character = '5';
char *string = "5"
int main()
{
    PRINT(d,string); PRINT(d,character); PRINT(d,integer);
    PRINT(s,string); PRINT(c,character); PRINT(c,integer=53);
    PRINT(d,('5'>5));
    /*първи€ принт печати адреса на стринга като десетично, 2рото кода на символа '5' като десетично число (53)
    3тото печати 5, 4тото изкарва 5
    %s -> стрингова
    %c -> знаци
    %d -> код или адрес
    5toto ??, 6тото символа зад 53 демек 5
    7мото ако е в€рно печати 1 ако не, 0, в случа€ 53>5 =>1, защото кода на знака 5('5') е 53 и е по-гол€м от 5
    %о -> 8мична бройна система
    */

    {
        int sx = -8;
        unsigned ux = -8;
        //unsigned - 0
        PRINT(o,sx); PRINT(o,ux);
        PRINT(o,sx>>3); PRINT(o,ux>>3);
        PRINT(d,sx>>3); PRINT(d,ux>>3);
        //>> преместване над€сно, в случа€ с 3
    }
}

