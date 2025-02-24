#ifndef DECIMAL_FSM_H
#define DECIMAL_FSM_H
#include <stdio.h>
#include <ctype.h>
#include "states.h"

int is_decimal_digit(char ch) { return ch >= '1' && ch <= '9'; }
int is_octal_digit(char ch) { return ch >= '0' && ch <= '7'; }
int is_hex_digit(char ch) { return isxdigit(ch); }

// Decimal FSM function
State decimal_fsm(const char *word)
{
    State state = STATE_START;
    int i = 0;

    while (1)
    {
        char ch = tolower(word[i]); // to lower!!!!!

        if ('\0' == ch)
            break;

        switch (state)
        {
            case STATE_START:
                if ('+' == ch)
                {
                    state = STATE_SIGN_P; // plus sign
                }
                else if ('-' == ch)
                {
                    state = STATE_SIGN_M; //  minus sign
                }
                else if (is_decimal_digit(ch))
                {
                    state = STATE_DECIMAL; //  decimal
                }
                else if ('0' == ch)
                {
                    state = STATE_ZERO; //  single zero
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_SIGN_P: // Plus sign
                if (is_decimal_digit(ch))
                {
                    state = STATE_DECIMAL_P; // positive decimal
                }
                else if ('0' == ch)
                {
                    state = STATE_ZERO_P; // plus single zero
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_SIGN_M: // Minus sign
                if (is_decimal_digit(ch))
                {
                    state = STATE_DECIMAL_M; // negative decimal
                }
                else if ('0' == ch)
                {
                    state = STATE_ZERO_M; // minus single zero
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_DECIMAL_P: // Positive decimal
                if (is_decimal_digit(ch) || '0' == ch)
                {
                    // Stay in STATE_DECIMAL_P
                }
                else if ('u' == ch)
                {
                    state = STATE_DECIMAL_P_U; //  Positive decimal unsigned suffix
                }
                else if ('l' == ch)
                {
                    state = STATE_DECIMAL_P_L; // Positive decimal long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_DECIMAL_P_U: // Positive decimal with unsigned suffix
                if ('l' == ch)
                {
                    state = STATE_DECIMAL_P_U_L; // Positive decimal unsigned long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_DECIMAL_P_U_L: // Positive decimal unsigned long suffix
                if ('l' == ch)
                {
                    state = STATE_DECIMAL_P_U_LL; // Positive decimal unsigned long-long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_DECIMAL_P_U_LL: // Positive decimal unsigned long-long suffix
                state = STATE_ERROR;
                break;

            case STATE_DECIMAL_P_L: // Positive decimal long suffix
                if ('u' == ch)
                {
                    state = STATE_DECIMAL_P_L_U; // Positive decimal long unsigned suffix
                }
                else if ('l' == ch)
                {
                    state = STATE_DECIMAL_P_LL; // Positive decimal  long-long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_DECIMAL_P_L_U: // Positive decimal long unsigned suffix
                state = STATE_ERROR;
                break;

            case STATE_DECIMAL_P_LL: // Positive decimal long-long suffix
                if ('u' == ch)
                {
                    state = STATE_DECIMAL_P_LL_U; // Positive decimal  long-long unsigned suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_DECIMAL_P_LL_U: // Positive decimal long-long unsigned suffix
                state = STATE_ERROR;
                break;

            case STATE_DECIMAL_M:
                if (is_decimal_digit(ch) || '0' == ch)
                {
                    // Stay in STATE_DECIMAL_M
                }
                else if ('l' == ch)
                {
                    state = STATE_DECIMAL_M_L; // Negative decimal long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_DECIMAL_M_L: // Negative decimal long suffix
                if ('l' == ch)
                {
                    state = STATE_DECIMAL_M_LL; // Negative decimal long long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_DECIMAL_M_LL: // Negative decimal long long suffix
                state = STATE_ERROR;
                break;

            case STATE_DECIMAL: // decimal
                if (is_decimal_digit(ch) || '0' == ch)
                {
                    // Stay in STATE_DECIMAL
                }
                else if ('u' == ch)
                {
                    state = STATE_DECIMAL_U; // decimal unsigned suffix
                }
                else if ('l' == ch)
                {
                    state = STATE_DECIMAL_L; // decimal long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_DECIMAL_U: // decimal unsigned suffix
                if ('l' == ch)
                {
                    state = STATE_DECIMAL_U_L; // decimal unsigned long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_DECIMAL_U_L: //  decimal unsigned long suffix
                if ('l' == ch)
                {
                    state = STATE_DECIMAL_U_LL; // decimal unsigned long-long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_DECIMAL_U_LL: // decimal unsigned long-long suffix
                state = STATE_ERROR;
                break;

            case STATE_DECIMAL_L: // decimal long suffix
                if ('u' == ch)
                {
                    state = STATE_DECIMAL_L_U;
                }
                else if ('l' == ch)
                {
                    state = STATE_DECIMAL_LL;
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_DECIMAL_L_U: // decimal long unsigned suffix
                state = STATE_ERROR;
                break;

            case STATE_DECIMAL_LL: //  decimal with long-long suffix
                if ('u' == ch)
                {
                    state = STATE_DECIMAL_LL_U;
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_DECIMAL_LL_U: // decimal long-long unsigned suffix
                state = STATE_ERROR;
                break;

            case STATE_ZERO_P: // Positive zero state
                if ('u' == ch)
                {
                    state = STATE_ZERO_P_U;
                }
                else if ('l' == ch)
                {
                    state = STATE_ZERO_P_L;
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_ZERO_P_U: // Positive decimal with unsigned suffix
                if ('l' == ch)
                {
                    state = STATE_ZERO_P_U_L; // Move to STATE_DECIMAL_P_U_L for unsigned long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_ZERO_P_U_L: // Positive decimal with unsigned long suffix
                if ('l' == ch)
                {
                    state = STATE_ZERO_P_U_LL; // Move to STATE_DECIMAL_P_U_LL for unsigned long-long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_ZERO_P_U_LL: // Positive decimal with unsigned long-long suffix
                // No further characters are allowed after the unsigned long-long suffix
                state = STATE_ERROR;
                break;

            case STATE_ZERO_P_L: // Positive decimal with long suffix
                if ('u' == ch)
                {
                    state = STATE_ZERO_P_L_U; // Move to STATE_DECIMAL_P_L_U for long unsigned suffix
                }
                else if ('l' == ch)
                {
                    state = STATE_ZERO_P_LL; // Move to STATE_DECIMAL_P_LL for long-long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_ZERO_P_L_U: // Positive decimal with long unsigned suffix
                // No further characters are allowed after the long unsigned suffix
                state = STATE_ERROR;
                break;

            case STATE_ZERO_P_LL: // Positive decimal with long-long suffix
                if ('u' == ch)
                {
                    state = STATE_DECIMAL_P_LL_U; // Move to STATE_DECIMAL_P_LL_U for long-long unsigned suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_ZERO_P_LL_U: // Positive decimal with long-long unsigned suffix
                // No further characters are allowed after the long-long unsigned suffix
                state = STATE_ERROR;
                break;

            case STATE_ZERO_M:
                if ('l' == ch)
                {
                    state = STATE_ZERO_M_L; // Move to STATE_DECIMAL_M_L for long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_ZERO_M_L:
                if ('l' == ch)
                {
                    state = STATE_ZERO_M_LL; // Move to STATE_DECIMAL_M_LL
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_ZERO_M_LL:
                // No further characters are allowed after the long-long unsigned suffix
                state = STATE_ERROR;
                break;

            case STATE_ZERO:
                if ('x' == ch)
                {
                    state = STATE_HEX_PREFIX; // Move to HEX_PREFIX state
                }
                else if (is_octal_digit(ch))
                {
                    state = STATE_OCTAL;
                }
                else if ('u' == ch)
                {
                    state = STATE_ZERO_U; // Move to UNSIGNED state
                }
                else if ('l' == ch)
                {
                    state = STATE_ZERO_L; // Move to STATE_ZERO_P_L for long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_ZERO_U: // Positive_ZERO with unsigned suffix
                if ('l' == ch)
                {
                    state = STATE_ZERO_U_L; // Move to STATE_ZERO_P_U_L for unsigned long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_ZERO_U_L: // Positive_ZERO with unsigned long suffix
                if ('l' == ch)
                {
                    state = STATE_ZERO_U_LL; // Move to STATE_ZERO_P_U_LL for unsigned long-long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_ZERO_U_LL: // Positive_ZERO with unsigned long-long suffix
                // No further characters are allowed after the unsigned long-long suffix
                state = STATE_ERROR;
                break;

            case STATE_ZERO_L: // Positive_ZERO with long suffix
                if ('u' == ch)
                {
                    state = STATE_ZERO_L_U; // Move to STATE_ZERO_P_L_U for long unsigned suffix
                }
                else if ('l' == ch)
                {
                    state = STATE_ZERO_LL; // Move to STATE_ZERO_P_LL for long-long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_ZERO_L_U: // Positive_ZERO with long unsigned suffix
                // No further characters are allowed after the long unsigned suffix
                state = STATE_ERROR;
                break;

            case STATE_ZERO_LL: // Positive_ZERO with long-long suffix
                if ('u' == ch)
                {
                    state = STATE_ZERO_LL_U; // Move to STATE_ZERO_P_LL_U for long-long unsigned suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_ZERO_LL_U: // Positive_ZERO with long-long unsigned suffix
                // No further characters are allowed after the long-long unsigned suffix
                state = STATE_ERROR;
                break;

            case STATE_OCTAL: // Positive OCTAL state
                if (is_octal_digit(ch))
                {
                    // Stay in STATE_OCTAL
                }
                else if ('u' == ch)
                {
                    state = STATE_OCTAL_U; // Move to STATE_OCTAL_P_U for unsigned suffix
                }
                else if ('l' == ch)
                {
                    state = STATE_OCTAL_L; // Move to STATE_OCTAL_P_L for long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_OCTAL_U: // Positive OCTAL with unsigned suffix
                if ('l' == ch)
                {
                    state = STATE_OCTAL_U_L; // Move to STATE_OCTAL_P_U_L for unsigned long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_OCTAL_U_L: // Positive OCTAL with unsigned long suffix
                if ('l' == ch)
                {
                    state = STATE_OCTAL_U_LL; // Move to STATE_OCTAL_P_U_LL for unsigned long-long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_OCTAL_U_LL: // Positive OCTAL with unsigned long-long suffix
                // No further characters are allowed after the unsigned long-long suffix
                state = STATE_ERROR;
                break;

            case STATE_OCTAL_L: // Positive OCTAL with long suffix
                if ('u' == ch)
                {
                    state = STATE_OCTAL_L_U; // Move to STATE_OCTAL_P_L_U for long unsigned suffix
                }
                else if ('l' == ch)
                {
                    state = STATE_OCTAL_LL; // Move to STATE_OCTAL_P_LL for long-long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_OCTAL_L_U: // Positive OCTAL with long unsigned suffix
                // No further characters are allowed after the long unsigned suffix
                state = STATE_ERROR;
                break;

            case STATE_OCTAL_LL: // Positive OCTAL with long-long suffix
                if ('u' == ch)
                {
                    state = STATE_OCTAL_LL_U; // Move to STATE_OCTAL_P_LL_U for long-long unsigned suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_OCTAL_LL_U: // Positive OCTAL with long-long unsigned suffix
                // No further characters are allowed after the long-long unsigned suffix
                state = STATE_ERROR;
                break;

            case STATE_HEX_PREFIX:
                if (is_hex_digit(ch))
                {
                    state = STATE_HEX; // Move to HEX_DIGIT state
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_HEX: // Positive HEX state
                if (is_hex_digit(ch))
                {
                    // Stay in STATE_HEX
                }
                else if ('u' == ch)
                {
                    state = STATE_HEX_U; // Move to STATE_HEX_P_U for unsigned suffix
                }
                else if ('l' == ch)
                {
                    state = STATE_HEX_L; // Move to STATE_HEX_P_L for long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_HEX_U: // Positive HEX with unsigned suffix
                if ('l' == ch)
                {
                    state = STATE_HEX_U_L; // Move to STATE_HEX_P_U_L for unsigned long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_HEX_U_L: // Positive HEX with unsigned long suffix
                if ('l' == ch)
                {
                    state = STATE_HEX_U_LL; // Move to STATE_HEX_P_U_LL for unsigned long-long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_HEX_U_LL: // Positive HEX with unsigned long-long suffix
                // No further characters are allowed after the unsigned long-long suffix
                state = STATE_ERROR;
                break;

            case STATE_HEX_L: // Positive HEX with long suffix
                if ('u' == ch)
                {
                    state = STATE_HEX_L_U; // Move to STATE_HEX_P_L_U for long unsigned suffix
                }
                else if ('l' == ch)
                {
                    state = STATE_HEX_LL; // Move to STATE_HEX_P_LL for long-long suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_HEX_L_U: // Positive HEX with long unsigned suffix
                // No further characters are allowed after the long unsigned suffix
                state = STATE_ERROR;
                break;

            case STATE_HEX_LL: // Positive HEX with long-long suffix
                if ('u' == ch)
                {
                    state = STATE_HEX_LL_U; // Move to STATE_HEX_P_LL_U for long-long unsigned suffix
                }
                else
                {
                    state = STATE_ERROR;
                }
                break;

            case STATE_HEX_LL_U: // Positive HEX with long-long unsigned suffix
                // No further characters are allowed after the long-long unsigned suffix
                state = STATE_ERROR;
                break;

            case STATE_ERROR:
                // Once in ERROR state, stay there
                break;
        }

        i++;
    }

    return state;
}

#endif