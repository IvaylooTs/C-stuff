#ifndef ZAD1_STATES_H
#define ZAD1_STATES_H

typedef enum
{
    STATE_START = 6,            // Initial state
    STATE_SIGN_P,               // +
    STATE_SIGN_M,               // -
    STATE_DECIMAL_P,            // +d
    STATE_DECIMAL_P_U,          // +du
    STATE_DECIMAL_P_U_L,        // +dul
    STATE_DECIMAL_P_U_LL,       // +dull
    STATE_DECIMAL_P_L,          // +dl
    STATE_DECIMAL_P_L_U,        // +dlu
    STATE_DECIMAL_P_LL,         // +dll
    STATE_DECIMAL_P_LL_U,       // +dllu
    STATE_DECIMAL_M,            // -d
    STATE_DECIMAL_M_L,          // -dl
    STATE_DECIMAL_M_LL,         // -dll
    STATE_ZERO_P,               // +0
    STATE_ZERO_P_U,             // +0u
    STATE_ZERO_P_U_L,           // +0ul
    STATE_ZERO_P_U_LL,          // +0ull
    STATE_ZERO_P_L,             // +0l
    STATE_ZERO_P_L_U,           // +0lu
    STATE_ZERO_P_LL,            // +0ll
    STATE_ZERO_P_LL_U,          // +0llu
    STATE_ZERO_M,               // -0
    STATE_ZERO_M_L,             // -0l
    STATE_ZERO_M_LL,            // -0ll
    STATE_DECIMAL,              // d
    STATE_DECIMAL_U,            // du
    STATE_DECIMAL_U_L,          // dul
    STATE_DECIMAL_U_LL,         // dull
    STATE_DECIMAL_L,            // dl
    STATE_DECIMAL_L_U,          // dlu
    STATE_DECIMAL_LL,           // dll
    STATE_DECIMAL_LL_U,         // dllu
    STATE_ZERO,                 // 0
    STATE_ZERO_U,               // 0u
    STATE_ZERO_U_L,             // 0ul
    STATE_ZERO_U_LL,            // 0ull
    STATE_ZERO_L,               // 0l
    STATE_ZERO_L_U,             // 0lu
    STATE_ZERO_LL,              // 0ll
    STATE_ZERO_LL_U,            // 0llu
    STATE_OCTAL,                // 0o
    STATE_OCTAL_U,              // 0ou
    STATE_OCTAL_U_L,            // 0oul
    STATE_OCTAL_U_LL,           // 0oull
    STATE_OCTAL_L,              // 0ol
    STATE_OCTAL_L_U,            // 0olu
    STATE_OCTAL_LL,             // 0oll
    STATE_OCTAL_LL_U,           // 0ollu
    STATE_HEX_PREFIX,           // 0x
    STATE_HEX,                  // 0xz
    STATE_HEX_U,                // 0xzu
    STATE_HEX_U_L,              // 0xzul
    STATE_HEX_U_LL,             // 0xzull
    STATE_HEX_L,                // 0xzl
    STATE_HEX_L_U,              // 0xzlu
    STATE_HEX_LL,               // 0xzll
    STATE_HEX_LL_U,             // 0xzllu
    STATE_ERROR,                // Error state
    F_STATE_START,              // Initial state
    F_STATE_SIGN,               // +/-
    F_STATE_SIGN_DIGIT,         // +/-d
    F_STATE_DIGIT,              // d
    F_STATE_DIGIT_POINT,        // d.
    F_STATE_DIGIT_POINT_F,      // d.f
    F_STATE_DIGIT_POINT_L,      // d.l
    F_STATE_POINT,              // .
    F_STATE_POINT_F,            // .F
    F_STATE_POINT_L,            // .L
    F_STATE_SIGN_DIGIT_POINT,   // +/-d.
    F_STATE_SIGN_DIGIT_POINT_F, // +/-d.F
    F_STATE_SIGN_DIGIT_POINT_L, // +/-d.L
    F_STATE_ALLPOINT_DIGIT,     // *.d
    F_STATE_ALLPOINT_DIGIT_F,   // *.df
    F_STATE_ALLPOINT_DIGIT_L,   // *.dl
    F_STATE_E,                  // *e
    F_STATE_E_DIGIT,            // *ed
    F_STATE_E_DIGIT_F,          // *edf
    F_STATE_E_DIGIT_L,          // *edl
    F_STATE_E_SIGN,             // *e+/-
    F_STATE_E_SIGN_DIGIT,       // *e+/-d
    F_STATE_E_SIGN_DIGIT_F,     // *e+/-df
    F_STATE_E_SIGN_DIGIT_L,     // *e+/-dl
    F_STATE_ERROR               // Error state
} State;

#endif //ZAD1_STATES_H
