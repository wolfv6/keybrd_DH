#ifndef INSTANTIATIONS_MATRIX_R_H
#define INSTANTIATIONS_MATRIX_R_H

/* This file instantiates key and row objects for right matrix.
*/

#include <Row_DH.h>
#include <Key_LayeredKeysArray.h>

/* ================ COORDINATES ================
Key names identify the key's position by coordinates
Key coordinates are matrix+row+column.  For example:
    k_R01  is key at Right matrix, row 0, column 1
Row coordinates are matrix+row.  For example:
    row_R0 is top row of right matrix

-------- Fist coordinate is L or R matrix --------
matrix letter:  R
meaning:        Right

-------- Second coordinate is row number ---------
direction
        col 0       col 1       col 2-5
        thumb       thumb       R finger
row 0   hard down   nail        North
row 1   pad         knuckle     West
row 2   up          down        Center
row 3                           South
row 4                           East

 (left-right fingers swap West-East because PCB is flipped)

------- Third coordinate is column number ------
column number:  0       1       2       3       4       5
finger:         thumb   thumb   index   middle  ring    pinky
*/

Code_LayeredDoublePressToggle& Row_DH::refAlt = t_alt;

// -------------- RIGHT KEYS -------------------
//Layers:                   {normal,      10KeyOff,       10KeyOn,        mouseOn   };
//row_R0 North keys
Key* const ptrsCodes_R02[]= {&s_u,        &s_ampersand,   &n_7,           &msA_up    };
Key_LayeredKeysArray k_R02(ptrsCodes_R02);

Key* const ptrsCodes_R03[]= {&s_i,        &lr_asterix,    &n_8,           &p_F8     };
Key_LayeredKeysArray k_R03(ptrsCodes_R03);

Key* const ptrsCodes_R04[]= {&s_o,        &s_leftParen,   &n_9,           &p_F10    };
Key_LayeredKeysArray k_R04(ptrsCodes_R04);

Key* const ptrsCodes_R05[]= {&s_p,        &s_rightParen,  &lr_asterix,    &lr_pageUp };
Key_LayeredKeysArray k_R05(ptrsCodes_R05);

//row_R1 West keys
Key* const ptrsCodes_R12[]= {&s_h,        &n_6,           &n_0,           &msA_left  };
Key_LayeredKeysArray k_R12(ptrsCodes_R12);

Key* const ptrsCodes_R13[]= {&s_y,        &s_circumflex,  &lr_plus,        &lr_end    };
Key_LayeredKeysArray k_R13(ptrsCodes_R13);

Key* const ptrsCodes_R14[]= {&s_n,        &s_semicolon,   &s_equal,       &lr_insert };
Key_LayeredKeysArray k_R14(ptrsCodes_R14);

Key* const ptrsCodes_R15[]= {&s_rightBracket, &p_tenKeyOff, &p_tenKeyOff, &p_F11    };
Key_LayeredKeysArray k_R15(ptrsCodes_R15);

//row_R2 Center keys
Key* const ptrsCodes_R22[]= {&s_j,        &n_7,           &n_4,           &mb2Home      };
Key_LayeredKeysArray k_R22(ptrsCodes_R22);

Key* const ptrsCodes_R23[]= {&s_k,        &n_8,           &n_5,           &p_arrowOn};
Key_LayeredKeysArray k_R23(ptrsCodes_R23);

Key* const ptrsCodes_R24[]= {&s_l,        &n_9,           &n_6,        &d_printscreen};
Key_LayeredKeysArray k_R24(ptrsCodes_R24);

Key* const ptrsCodes_R25[]= {&s_semicolon, &n_0,          &s_period,      &s_pause  };
Key_LayeredKeysArray k_R25(ptrsCodes_R25);

//row_R3 South keys
Key* const ptrsCodes_R32[]= {&s_m,        &lr_plus,        &n_1,           &msA_down  };
Key_LayeredKeysArray k_R32(ptrsCodes_R32);

Key* const ptrsCodes_R33[]= {&s_comma,    &s_comma,       &n_2,           &p_F7     };
Key_LayeredKeysArray k_R33(ptrsCodes_R33);

Key* const ptrsCodes_R34[]= {&s_period,   &s_period,      &n_3,           &p_F9     };
Key_LayeredKeysArray k_R34(ptrsCodes_R34);

Key* const ptrsCodes_R35[]= {&lr_slash,    &s_question,    &lr_slash,       &lr_pageDown};
Key_LayeredKeysArray k_R35(ptrsCodes_R35);

//row_R4 East
Key* const ptrsCodes_R42[]= {&s_quote,    &s_underscore,  &n_00,        &msA_right };
Key_LayeredKeysArray k_R42(ptrsCodes_R42);

Key* const ptrsCodes_R43[]= {&s_colon,    &s_colon,       &lr_minus,       &rl_shift  };
Key_LayeredKeysArray k_R43(ptrsCodes_R43);

Key* const ptrsCodes_R45[]= {&s_backslash, &p_tenKeyOn,   &p_tenKeyOn,    &p_F12    };
Key_LayeredKeysArray k_R45(ptrsCodes_R45);

// -------------- RIGHT ROWS -------------------
//column number:  0       1       2       3       4       5
//finger:         thumb   thumb   index   middle  ring    pinky

//row_R0 North  col
Key* const ptrsKeys_R0[] = { &l_NASLock, &s_backspace, &k_R02, &k_R03, &k_R04, &k_R05 };
Row_DH row_R0(scanner_R, 1<<0, ptrsKeys_R0, 6, 0);

//row_R1 West
Key* const ptrsKeys_R1[] = { &s_space, &t_alt, &k_R12, &k_R13, &k_R14, &k_R15 };
Row_DH row_R1(scanner_R, 1<<1, ptrsKeys_R1, 6, 0);

//row_R2 center
Key* const ptrsKeys_R2[] = { &l_MFLock, &l_NASHold, &k_R22, &k_R23, &k_R24, &k_R25 };
Row_DH row_R2(scanner_R, 1<<2, ptrsKeys_R2, 6, 0);

//row_R3 South
Key* const ptrsKeys_R3[] = { &k_R32, &k_R33, &k_R34, &k_R35 };
Row_DH row_R3(scanner_R, 1<<3, ptrsKeys_R3, 4, 2);

//row_R4 East
Key* const ptrsKeys_R4[] = { &k_R42, &k_R43, &s_KPEnter, &k_R45 }; //s_KPEnter 101-keyboard mode
Row_DH row_R4(scanner_R, 1<<4, ptrsKeys_R4, 4, 2);

#endif
