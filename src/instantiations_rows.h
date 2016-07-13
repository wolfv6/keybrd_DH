#ifndef INSTANTIATIONS_MATRIX_H
#define INSTANTIATIONS_MATRIX_H

#include <Row_DH_uC.h>
#include <Row_DH_IOE.h>
#include <Key_LayeredKeysArray.h>

/* DH QWERTY layout
101-keyboard mode (ENTER key on right ring finger sends KEYPAD_ENTER, there is no "Windows" key)
on breadboard, finger keys are on the outer 4 columns
            LEFT                                        RIGHT
 NORMAL
    NORTH   q      w      e      r              NORTH   u      i      o      p
    EAST    [{     b      t      g              WEST    h      y      n      ]}
    CENTER  a      s      d      f              CENTER  j      k      l      ;:
    SOUTH   z      x      c      v              SOUTH   m      ,      .      /?
    WEST    Del    Esc    `      "              EAST    '      :      Ent    \|

 NAS TEN_KEY_OFF                    NASLck proected: 10KeyOff, 10KeyOn, NumLck
    NORTH   !      @      #      $              NORTH   &      *      (      )
    EAST    ~      NumLck >      5              WEST    6      ^      ;      10KeyOff
    CENTER  1      2      3      4              CENTER  7      8      9      0
    SOUTH   =      00     %      -              SOUTH   +      ,      .      ?
    WEST    Del    Esc    <      /              EAST    _      :      Ent    10KeyOn

 NAS TEN_KEY_ON
    NORTH   !      @      #      Up             NORTH   7      8      9      *
    EAST    ~      null   >      Right          WEST    0      +      =      10KeyOff
    CENTER  ,      $      &      Home           CENTER  4      5      6      .
    SOUTH   (      )      %      Down           SOUTH   1      2      3      /
    WEST    Del    Esc    <      Left           EAST    00     -      Ent    10KeyOn

                                    MF protected: ArrowOn, MouseOn, F1-F12, NumLck, L/RModf, Print
 MF MOUSE_ON                     QUICK                  SLOW
    NORTH   F2     F4     F6     Up             NORTH   Up     F8     F10    PgUp
    EAST    ScrLck NumLck Ent    Right          WEST    Left   End    Ins    F11
    CENTER  L/RModf MB3  MouseOn MB1            CENTER  MB2    ArrowOn Print Pause
    SOUTH   F1     F3     F5     Down           SOUTH   Down   F7     F9     PgDn
    WEST    Del    Esc    =      Left           EAST    Right  Shift  Ent    F12

 MF ARROW_ON
    NORTH                        Up             NORTH   Up
    EAST                         Right          WEST    Left
    CENTER                       Home           CENTER  Home
    SOUTH                        Down           SOUTH   Down
    WEST                         Left           EAST    Right

on breadboard, thumb keys are inner 2 columns on first 3 rows
            LEFT                                        RIGHT
    NORTH   Tab    CapLck                       NORTH   NASLck BkSp
    EAST    Ctrl   Ent                          WEST    Sp     Alt
    CENTER  Shift  Normal                       CENTER  MF     NAS

PCB thumb keys
            LEFT                                        RIGHT
    TOP     Ent    Shift  Tab                   TOP     BkSp   NAS    Sp
    BOT     Normal CapLck Ctrl                  BOT     Alt    NASLck MF
*/
/* ============ KEY COORDINATES ================
Key names identify the key's position by coordinates
Key coordinates are matrix+row+column.  For example:
        k_L01  is key at Left matrix, row 0, column 1

-------- Fist coordinate is L or R matrix --------
matrix letter:          L       R
meaning:                Left    Right

-------- Second coordinate is row number ---------
direction
        col 0-3     col 0-3     col 4   col 5
        L finger    R finger    thumb   thumb
row 0   North       North       nail    hard down
row 1   East        West        knuckle pad
row 2   Center      Center      down    up
row 3   South       South
row 4   West        East

 (left-right fingers swap West-East because PCB is flipped)

------- Third coordinate is column number ------
column number:                          0       1       2       3       4       5
finger:                                 pinky   ring    middle  index   thumb   thumb
*/
Code_LayeredDoublePressToggle& Row_DH::refCtrl = t_ctrl; 
Code_LayeredDoublePressToggle& Row_DH::refAlt = t_alt; 

// ============== LEFT LAYOUT ==================
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
//column number:                          0       1       2       3       4       5
//finger:                                 pinky   ring    middle  index   thumb   thumb
// /home/wolfv/Documents/dev_proj/alt_keybrd/alt_doc/dodohand/schematic_teensy2_pin_assignments.png

//row_L0 North
Key* const ptrsKeys_L0[] = { &k_L00, &k_L01, &k_L02, &k_L03, &s_tab, &o_capsLock };
Row_DH_uC row_L0(21, readPins_L, READ_PIN_COUNT, ptrsKeys_L0);

//row_L1 East
Key* const ptrsKeys_L1[] = { &k_L10, &k_L11, &k_L12, &k_L13, &t_ctrl, &s_enter };
Row_DH_uC row_L1(20, readPins_L, READ_PIN_COUNT, ptrsKeys_L1);

//row_L2 center
Key* const ptrsKeys_L2[] = { &k_L20, &k_L21, &k_L22, &k_L23, &lr_shift, &l_normalLock };
Row_DH_uC row_L2(19, readPins_L, READ_PIN_COUNT, ptrsKeys_L2);

//row_L3 South
Key* const ptrsKeys_L3[] = { &k_L30, &k_L31, &k_L32, &k_L33 };
Row_DH_uC row_L3(18, readPins_L_short, READ_PIN_COUNT_SHORT, ptrsKeys_L3);

//row_L4 West
Key* const ptrsKeys_L4[] = { &lr_delete, &s_esc, &k_L42, &k_L43 };
Row_DH_uC row_L4(17, readPins_L_short, READ_PIN_COUNT_SHORT, ptrsKeys_L4);

// ============== RIGHT LAYOUT =================
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
//column number:                          0       1       2       3       4       5
//finger:                                 pinky   ring    middle  index   thumb   thumb

//row_R0 North  col
Key* const ptrsKeys_R0[] = { &l_NASLock, &s_backspace, &k_R02, &k_R03, &k_R04, &k_R05 };
Row_DH_IOE row_R0(strobePort1_R, 1<<0, readPort0_R, READ_PIN_COUNT, ptrsKeys_R0);

//row_R1 West
Key* const ptrsKeys_R1[] = { &s_space, &t_alt, &k_R12, &k_R13, &k_R14, &k_R15 };
Row_DH_IOE row_R1(strobePort1_R, 1<<1, readPort0_R, READ_PIN_COUNT, ptrsKeys_R1);

//row_R2 center
Key* const ptrsKeys_R2[] = { &l_MFLock, &l_NASHold, &k_R22, &k_R23, &k_R24, &k_R25 };
Row_DH_IOE row_R2(strobePort1_R, 1<<2, readPort0_R, READ_PIN_COUNT, ptrsKeys_R2);

//row_R3 South
Key* const ptrsKeys_R3[] = { &k_R32, &k_R33, &k_R34, &k_R35 };
Row_DH_IOE row_R3(strobePort1_R, 1<<3, readPort0_R, READ_PIN_COUNT_SHORT, ptrsKeys_R3);

//row_R4 East
Key* const ptrsKeys_R4[] = { &k_R42, &k_R43, &s_KPEnter, &k_R45 }; //s_KPEnter 101-keyboard mode
    Row_DH_IOE row_R4(strobePort1_R, 1<<4, readPort0_R, READ_PIN_COUNT_SHORT, ptrsKeys_R4);

#endif
