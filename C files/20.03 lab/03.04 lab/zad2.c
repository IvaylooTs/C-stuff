#include <stdio.h>
#include <string.h>

int main()
{
    const char * arr[5][2] = {{"Show", "Display current state of element."},
                                    {"ADD", "Command for adding of value to element"},
                                    {"DEC", "Command for decrease of element"},
                                    {"PX", "This command make e=e^x. Where \"e\" is the element value.\nWhere x is on of(0,2,4,8,16)"},
                                    {"Help", "Showing help information"}};
    int t=1;
    char input[5];
    scanf("%s", &input);

    for (int i=0; i<5; i++)
    {
        if(strcmp(input, arr[i][0]) == 0) {
            printf("%s", arr[i][1]);
            t=0;
            break;

        }
    }
    if (t==1) {
        printf("No such command!");
    }


    return 0;
}
