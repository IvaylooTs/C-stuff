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
    /*������ ����� ������ ������ �� ������� ���� ���������, 2���� ���� �� ������� '5' ���� ��������� ����� (53)
    3���� ������ 5, 4���� ������� 5
    %s -> ���������
    %c -> �����
    %d -> ��� ��� �����
    5toto ??, 6���� ������� ��� 53 ����� 5
    7���� ��� � ����� ������ 1 ��� ��, 0, � ������ 53>5 =>1, ������ ���� �� ����� 5('5') � 53 � � ��-����� �� 5
    %� -> 8����� ������ �������
    */

    {
        int sx = -8;
        unsigned ux = -8;
        //unsigned - 0
        PRINT(o,sx); PRINT(o,ux);
        PRINT(o,sx>>3); PRINT(o,ux>>3);
        PRINT(d,sx>>3); PRINT(d,ux>>3);
        //>> ����������� �������, � ������ � 3
    }
}

