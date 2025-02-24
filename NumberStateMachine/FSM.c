#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "decimal_fsm.h"
#include "float_fsm.h"


#define MAX_WORD_LENGTH 30

int main()
{
    FILE *file;
    char c[MAX_WORD_LENGTH];
    char filename[] = "test_FSM.txt";
//    char filename[] = "C:\\Users\\User\\Desktop\\sysprog\\upr\\zad1\\test_FSM.txt";
    int ch = 0;
    int index = 0;
    State counter_type = 0;

    int decimal_count = 0;         // Decimal constants
    int floating_point_count = 0;  // Floating-point constants
    int whole_constants_count = 0; // Whole constants in all systems
    int unsigned_count = 0;        // Unsigned numbers
    int octal_count = 0;           // Octal numbers
    int hex_count = 0;             // Hexadecimal numbers
    int float_count = 0;           // Numbers of type float

    file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (1)
    {
        ch = fgetc(file);

        if (isspace(ch) || ch == ',' || ch == EOF)
        {
            if (index > 0)
            {
                c[index] = '\0'; // Null-terminate for end of word

                counter_type = decimal_fsm(c);
                if (counter_type == F_STATE_ERROR || counter_type == STATE_ERROR)
                {
                    counter_type = float_fsm(c);
                }

                switch (counter_type)
                {
                    case STATE_DECIMAL_P:
                    case STATE_DECIMAL_P_L:
                    case STATE_DECIMAL_P_LL:
                    case STATE_DECIMAL_M:
                    case STATE_DECIMAL_M_L:
                    case STATE_DECIMAL_M_LL:
                    case STATE_ZERO_P:
                    case STATE_ZERO_P_L:
                    case STATE_ZERO_P_LL:
                    case STATE_ZERO_M:
                    case STATE_ZERO_M_L:
                    case STATE_ZERO_M_LL:
                    case STATE_DECIMAL:
                    case STATE_DECIMAL_L:
                    case STATE_DECIMAL_LL:
                    case STATE_ZERO:
                    case STATE_ZERO_L:
                    case STATE_ZERO_LL:
                        decimal_count++;
                        whole_constants_count++;
                        break;
                    case STATE_DECIMAL_P_U:
                    case STATE_DECIMAL_P_U_L:
                    case STATE_DECIMAL_P_U_LL:
                    case STATE_DECIMAL_P_L_U:
                    case STATE_DECIMAL_P_LL_U:
                    case STATE_ZERO_P_U:
                    case STATE_ZERO_P_U_L:
                    case STATE_ZERO_P_U_LL:
                    case STATE_ZERO_P_L_U:
                    case STATE_ZERO_P_LL_U:
                    case STATE_DECIMAL_U:
                    case STATE_DECIMAL_U_L:
                    case STATE_DECIMAL_U_LL:
                    case STATE_DECIMAL_L_U:
                    case STATE_DECIMAL_LL_U:
                    case STATE_ZERO_U:
                    case STATE_ZERO_U_L:
                    case STATE_ZERO_U_LL:
                    case STATE_ZERO_L_U:
                    case STATE_ZERO_LL_U:
                        decimal_count++;
                        whole_constants_count++;
                        unsigned_count++;
                        break;
                    case STATE_OCTAL:
                    case STATE_OCTAL_U:
                    case STATE_OCTAL_U_L:
                    case STATE_OCTAL_U_LL:
                    case STATE_OCTAL_L:
                    case STATE_OCTAL_L_U:
                    case STATE_OCTAL_LL:
                    case STATE_OCTAL_LL_U:
                        decimal_count++;
                        whole_constants_count++;
                        octal_count++;
                        unsigned_count++;
                        break;
                    case STATE_HEX:
                    case STATE_HEX_U:
                    case STATE_HEX_U_L:
                    case STATE_HEX_U_LL:
                    case STATE_HEX_L:
                    case STATE_HEX_L_U:
                    case STATE_HEX_LL:
                    case STATE_HEX_LL_U:
                        decimal_count++;
                        whole_constants_count++;
                        hex_count++;
                        unsigned_count++;
                        break;
                    case F_STATE_DIGIT_POINT:
                    case F_STATE_DIGIT_POINT_L:
                    case F_STATE_SIGN_DIGIT_POINT:
                    case F_STATE_SIGN_DIGIT_POINT_L:
                    case F_STATE_ALLPOINT_DIGIT:
                    case F_STATE_ALLPOINT_DIGIT_L:
                    case F_STATE_E_DIGIT:
                    case F_STATE_E_DIGIT_L:
                    case F_STATE_E_SIGN_DIGIT:
                    case F_STATE_E_SIGN_DIGIT_L:
                        floating_point_count++;
                        whole_constants_count++;
                        break;
                    case F_STATE_DIGIT_POINT_F:
                    case F_STATE_SIGN_DIGIT_POINT_F:
                    case F_STATE_ALLPOINT_DIGIT_F:
                    case F_STATE_E_DIGIT_F:
                    case F_STATE_E_SIGN_DIGIT_F:
                        floating_point_count++;
                        whole_constants_count++;
                        float_count++;
                        break;
                    default:
                        break;
                }

                // printf("Word: %s - %d\n", c, counter_type);
                index = 0;
            }

            if (ch == EOF)
            {
                break; // end of file is reached
            }
        }
        else
        {
            if (index < MAX_WORD_LENGTH - 1)
            {
                c[index++] = ch;
            }
            else
            {
                printf("Word exceeds maximum length! \n");
                break;
            }
        }
    }

    fclose(file);

    printf("\nCounters:\n");
    printf("Decimal constants: %d\n", decimal_count);
    printf("Floating-point constants: %d\n", floating_point_count);
    printf("Whole constants (all systems): %d\n", whole_constants_count);
    printf("Unsigned numbers: %d\n", unsigned_count);
    printf("Octal numbers: %d\n", octal_count);
    printf("Hexadecimal numbers: %d\n", hex_count);
    printf("Float numbers: %d\n", float_count);

    return EXIT_SUCCESS;
}