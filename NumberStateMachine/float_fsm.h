#ifndef FLOAT_FSM_H
#define FLOAT_FSM_H
#include <stdio.h>
#include <ctype.h>
#include "states.h"

int is_digit(char ch) { return ch >= '0' && ch <= '9'; }

// Float FSM function
State float_fsm(const char *word)
{
    State f_state = F_STATE_START;
    int i = 0;

    while (1)
    {
        char ch = tolower(word[i]); // to lower!!!!!

        if ('\0' == ch)
            break;

        switch (f_state)
        {
            case F_STATE_START:
                if ('+' == ch || '-' == ch)
                {
                    f_state = F_STATE_SIGN;
                }
                else if (is_digit(ch))
                {
                    f_state = F_STATE_DIGIT;
                }
                else if ('.' == ch)
                {
                    f_state = F_STATE_POINT;
                }
                else
                {
                    f_state = F_STATE_ERROR;
                }
                break;

            case F_STATE_SIGN:
                if (is_digit(ch))
                {
                    f_state = F_STATE_SIGN_DIGIT;
                }
                else if ('.' == ch)
                {
                    f_state = F_STATE_POINT;
                }
                else
                {
                    f_state = F_STATE_ERROR;
                }
                break;

            case F_STATE_DIGIT:
                if (is_digit(ch))
                {
                    // Stay in STATE_DIGIT
                }
                else if ('.' == ch)
                {
                    f_state = F_STATE_DIGIT_POINT;
                }
                else if ('e' == ch)
                {
                    f_state = F_STATE_E;
                }
                else
                {
                    f_state = F_STATE_ERROR;
                }
                break;

            case F_STATE_DIGIT_POINT:
                if (is_digit(ch))
                {
                    f_state = F_STATE_ALLPOINT_DIGIT;
                }
                else if ('e' == ch)
                {
                    f_state = F_STATE_E;
                }
                else if ('l' == ch)
                {
                    f_state = F_STATE_DIGIT_POINT_L;
                }
                else if ('f' == ch)
                {
                    f_state = F_STATE_DIGIT_POINT_F;
                }
                else
                {
                    f_state = F_STATE_ERROR;
                }
                break;

            case F_STATE_DIGIT_POINT_L:
                // No further characters are allowed
                f_state = F_STATE_ERROR;
                break;

            case F_STATE_DIGIT_POINT_F:
                // No further characters are allowed
                f_state = F_STATE_ERROR;
                break;

            case F_STATE_SIGN_DIGIT:
                if (is_digit(ch))
                {
                    // Stay in F_STATE_SIGN_DIGIT
                }
                else if ('.' == ch)
                {
                    f_state = F_STATE_SIGN_DIGIT_POINT;
                }
                else if ('e' == ch)
                {
                    f_state = F_STATE_E;
                }
                else
                {
                    f_state = F_STATE_ERROR;
                }
                break;

            case F_STATE_POINT:
                if (is_digit(ch))
                {
                    f_state = F_STATE_ALLPOINT_DIGIT;
                }
                else if ('e' == ch)
                {
                    f_state = F_STATE_E;
                }
                else if ('f' == ch)
                {
                    f_state = F_STATE_POINT_F;
                }
                else if ('l' == ch)
                {
                    f_state = F_STATE_POINT_L;
                }
                else
                {
                    f_state = F_STATE_ERROR;
                }
                break;

            case F_STATE_POINT_F:
                // No further characters are allowed
                f_state = F_STATE_ERROR;
                break;
            case F_STATE_POINT_L:
                // No further characters are allowed
                f_state = F_STATE_ERROR;
                break;

            case F_STATE_SIGN_DIGIT_POINT:
                if (is_digit(ch))
                {
                    f_state = F_STATE_ALLPOINT_DIGIT;
                }
                else if ('e' == ch)
                {
                    f_state = F_STATE_E;
                }
                else if ('f' == ch)
                {
                    f_state = F_STATE_SIGN_DIGIT_POINT_F;
                }
                else if ('l' == ch)
                {
                    f_state = F_STATE_SIGN_DIGIT_POINT_L;
                }
                else
                {
                    f_state = F_STATE_ERROR;
                }
                break;

            case F_STATE_SIGN_DIGIT_POINT_F:
                // No further characters are allowed
                f_state = F_STATE_ERROR;
                break;

            case F_STATE_SIGN_DIGIT_POINT_L:
                // No further characters are allowed
                f_state = F_STATE_ERROR;
                break;

            case F_STATE_ALLPOINT_DIGIT:
                if (isdigit(ch))
                {
                    // Stay in F_STATE_ALLPOINT_DIGIT
                }
                else if ('f' == ch)
                {
                    f_state = F_STATE_ALLPOINT_DIGIT_F;
                }
                else if ('l' == ch)
                {
                    f_state = F_STATE_ALLPOINT_DIGIT_L;
                }
                else if ('e' == ch)
                {
                    f_state = F_STATE_E;
                }
                else
                {
                    f_state = F_STATE_ERROR;
                }
                break;

            case F_STATE_ALLPOINT_DIGIT_F:
                // No further characters are allowed
                f_state = F_STATE_ERROR;
                break;

            case F_STATE_ALLPOINT_DIGIT_L:
                // No further characters are allowed
                f_state = F_STATE_ERROR;
                break;

            case F_STATE_E:
                if (isdigit(ch))
                {
                    f_state = F_STATE_E_DIGIT;
                }
                else if ('-' == ch)
                {
                    f_state = F_STATE_E_SIGN;
                }
                else if ('+' == ch)
                {
                    f_state = F_STATE_E_SIGN;
                }
                else
                {
                    f_state = F_STATE_ERROR;
                }
                break;

            case F_STATE_E_DIGIT:
                if (isdigit(ch))
                {
                }
                else if ('f' == ch)
                {
                    f_state = F_STATE_E_DIGIT_F;
                }
                else if ('l' == ch)
                {
                    f_state = F_STATE_E_DIGIT_L;
                }
                else
                {
                    f_state = F_STATE_ERROR;
                }
                break;

            case F_STATE_E_DIGIT_F:
                // No further characters are allowed
                f_state = F_STATE_ERROR;
                break;

            case F_STATE_E_DIGIT_L:
                // No further characters are allowed
                f_state = F_STATE_ERROR;
                break;

            case F_STATE_E_SIGN:
                if (isdigit(ch))
                {
                    f_state = F_STATE_E_SIGN_DIGIT;
                }
                else
                {
                    f_state = F_STATE_ERROR;
                }
                break;

            case F_STATE_E_SIGN_DIGIT:
                if (isdigit(ch))
                {
                }
                else if ('f' == ch)
                {
                    f_state = F_STATE_E_SIGN_DIGIT_F;
                }
                else if ('l' == ch)
                {
                    f_state = F_STATE_E_SIGN_DIGIT_L;
                }
                else
                {
                    f_state = F_STATE_ERROR;
                }
                break;

            case F_STATE_E_SIGN_DIGIT_F:
                // No further characters are allowed
                f_state = F_STATE_ERROR;
                break;

            case F_STATE_E_SIGN_DIGIT_L:
                // No further characters are allowed
                f_state = F_STATE_ERROR;
                break;

            case F_STATE_ERROR:
                // Once in ERROR state, stay there
                break;
        }

        i++;
    }
    return f_state;
}

#endif