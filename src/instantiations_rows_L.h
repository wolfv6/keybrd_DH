#ifndef INSTANTIATIONS_MATRIX_L_H
#define INSTANTIATIONS_MATRIX_L_H

/* This file instantiates key and row objects for left matrix.
*/

#include <Row_DH.h>
#include <Key_LayeredKeysArray.h>

/* ================ COORDINATES ================
Key names identify the key's position by coordinates
Key coordinates are matrix+row+column.  For example:
    k_L01  is key at Left matrix, row 0, column 1
Row coordinates are matrix+row.  For example:
    row_L0 is top row of left matrix

-------- Fist coordinate is L or R matrix --------
matrix letter:          L       R
meaning:                Left    Right

-------- Second coordinate is row number ---------
direction
        col 0-3     col 4   col 5
        L finger    thumb   thumb
row 0   North       nail    hard down
row 1   East        knuckle pad
row 2   Center      down    up
row 3   South
row 4   West

 (left-right fingers swap West-East because PCB is flipped)

------- Third coordinate is column number ------
column number:  0       1       2       3       4       5
finger:         pinky   ring    middle  index   thumb   thumb
*/

Code_LayeredDoublePressToggle& Row_DH::refCtrl = t_ctrl;

// --------------- LEFT KEYS -------------------
//Layers:                    {normal,      10KeyOff,       10KeyOn,        mouseOn  };

//row_L0 North keys
Key* const ptrsCodes_L00[] = {&s_q,        &s_exclamation, &s_exclamation, &p_F2    };
Key_LayeredKeysArray k_L00(ptrsCodes_L00);

Key* const ptrsCodes_L01[] = {&s_w,        &s_at,          &s_at,          &p_F4    };
Key_LayeredKeysArray k_L01(ptrsCodes_L01);

Key* const ptrsCodes_L02[] = {&s_e,        &s_number,      &s_number,      &p_F6    };
Key_LayeredKeysArray k_L02(ptrsCodes_L02);

Key* const ptrsCodes_L03[] = {&s_r,        &s_dollar,      &s_up,          &mqA_up   };
Key_LayeredKeysArray k_L03(ptrsCodes_L03);

//row_L1 East keys
Key* const ptrsCodes_L10[] = {&s_leftBracket, &s_tilde,    &s_tilde,       &o_scrollLock };
Key_LayeredKeysArray k_L10(ptrsCodes_L10);

Key* const ptrsCodes_L11[] = {&s_b,        &pNAS_numLock,     &code_null,     &pMF_numLock };
Key_LayeredKeysArray k_L11(ptrsCodes_L11);

Key* const ptrsCodes_L12[] = {&s_t,        &s_greaterThan, &s_greaterThan, &s_enter };
Key_LayeredKeysArray k_L12(ptrsCodes_L12);

Key* const ptrsCodes_L13[] = {&s_g,        &n_5,           &s_right,       &mqA_right };
Key_LayeredKeysArray k_L13(ptrsCodes_L13);

//row_L2 Center keys
Key* const ptrsCodes_L20[] = {&s_a,        &n_1,           &s_comma,       &p_LRModf  };
Key_LayeredKeysArray k_L20( ptrsCodes_L20);

Key* const ptrsCodes_L21[] = {&s_s,        &n_2,           &s_dollar,      &mb_3    };
Key_LayeredKeysArray k_L21(ptrsCodes_L21);

Key* const ptrsCodes_L22[] = {&s_d,        &n_3,           &s_ampersand,   &p_mouseOn};
Key_LayeredKeysArray k_L22(ptrsCodes_L22);

Key* const ptrsCodes_L23[] = {&s_f,        &n_4,           &s_home,        &mb1Home    };
Key_LayeredKeysArray k_L23(ptrsCodes_L23);

//row_L3 South keys (
Key* const ptrsCodes_L30[] = {&s_z,        &s_equal,       &s_leftParen,   &p_F1    };
Key_LayeredKeysArray k_L30(ptrsCodes_L30);

Key* const ptrsCodes_L31[] = {&s_x,        &n_00,        &s_rightParen,  &p_F3    };
Key_LayeredKeysArray k_L31(ptrsCodes_L31);

Key* const ptrsCodes_L32[] = {&s_c,        &s_percent,     &s_percent,     &p_F5    };
Key_LayeredKeysArray k_L32(ptrsCodes_L32);

Key* const ptrsCodes_L33[] = {&s_v,        &lr_minus,       &s_down,        &mqA_down };
Key_LayeredKeysArray k_L33(ptrsCodes_L33);

//row_L4 West keys
Key* const ptrsCodes_L42[] = {&s_graves,   &s_lessThan,    &s_lessThan,    &s_equal };
Key_LayeredKeysArray k_L42(ptrsCodes_L42);

Key* const ptrsCodes_L43[] = {&s_doubleQuote,&lr_slash,     &s_left,        &mqA_left };
Key_LayeredKeysArray k_L43(ptrsCodes_L43);

// --------------- LEFT ROWS -------------------
//column number:  0       1       2       3       4       5
//finger:         pinky   ring    middle  index   thumb   thumb
// /home/wolfv/Documents/dev_proj/alt_keybrd/alt_doc/dodohand/schematic_teensy2_pin_assignments.png

//row_L0 North
Key* const ptrsKeys_L0[] = { &k_L00, &k_L01, &k_L02, &k_L03, &s_tab, &o_capsLock };
Row_DH row_L0(scanner_L, 21, ptrsKeys_L0, 6, 0);

//row_L1 East
Key* const ptrsKeys_L1[] = { &k_L10, &k_L11, &k_L12, &k_L13, &t_ctrl, &s_enter };
Row_DH row_L1(scanner_L, 20, ptrsKeys_L1, 6, 0);

//row_L2 center
Key* const ptrsKeys_L2[] = { &k_L20, &k_L21, &k_L22, &k_L23, &lr_shift, &l_normalLock };
Row_DH row_L2(scanner_L, 19, ptrsKeys_L2, 6, 0);

//row_L3 South
Key* const ptrsKeys_L3[] = { &k_L30, &k_L31, &k_L32, &k_L33 };
Row_DH row_L3(scanner_L_short, 18, ptrsKeys_L3, 4, 0);

//row_L4 West
Key* const ptrsKeys_L4[] = { &lr_delete, &s_esc, &k_L42, &k_L43 };
Row_DH row_L4(scanner_L_short, 17, ptrsKeys_L4, 4, 0);

#endif
