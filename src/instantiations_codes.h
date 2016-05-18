#ifndef INSTANTIATIONS_CODES_H
#define INSTANTIATIONS_CODES_H

//Code
#include <Code_Shift.h>
#include <Code_Sc.h>
#include <Code_ScS.h>
#include <Code_Null.h>
#include <Code_LEDLock.h>

//Mouse
#include <StateStickyMouseButtons.h>
#include <Code_StickyMouseButton.h>
#include <Code_Mouse_Slow.h>
#include <Code_Mouse_Quick.h>

//LED
#include "LED.h"
#include <LED_AVR.h>
#include <LED_PCA9655E.h>

//StateLayers
class StateLayersInterface;
#include <StateLayers_DH.h>
#include <StateLayers_NAS.h>
#include <StateLayers_MF.h>

//StateLayer controllers
#include <Code_NASHold.h>
#include <Code_NASLock_Protector.h>
#include <Code_NumLock.h>

//Layer
#include <Code_LayerLock.h>
#include <Code_LayerLockMF_Protector.h>
#include <Code_LayerState_Toggle.h>

//Layered
#include <Code_LayeredCodeSc.h>
#include <Code_LayeredNumber.h>
#include <Code_LayeredNumber_00.h>
#include <Code_LayeredNav.h>
#include <Code_LayeredOperator.h>
#include <Code_LayeredDoublePressToggle.h>
#include <Code_LayeredScSc.h>

//protected
#include <Code_Protected_ByMFLock.h>
#include <Code_Protected_ByNASLock.h>
#include <Code_DoublePressProtected.h>

// ================= CODES =====================
// ---------- SCANCODES ---------
/* scancode macros are defined in the top part of
Arduino\hardware\teensy\cores\teensy\keylayouts.h which is intended for use in "normal" programs.
This has been tested on teensy2.0.
*/
Code_Sc s_a(KEY_A);
Code_Sc s_b(KEY_B);
Code_Sc s_c(KEY_C);
Code_Sc s_d(KEY_D);
Code_Sc s_e(KEY_E);
Code_Sc s_f(KEY_F);
Code_Sc s_g(KEY_G);
Code_Sc s_h(KEY_H);
Code_Sc s_i(KEY_I);
Code_Sc s_j(KEY_J);
Code_Sc s_k(KEY_K);
Code_Sc s_l(KEY_L);
Code_Sc s_m(KEY_M);
Code_Sc s_n(KEY_N);
Code_Sc s_o(KEY_O);
Code_Sc s_p(KEY_P);
Code_Sc s_q(KEY_Q);
Code_Sc s_r(KEY_R);
Code_Sc s_s(KEY_S);
Code_Sc s_t(KEY_T);
Code_Sc s_u(KEY_U);
Code_Sc s_v(KEY_V);
Code_Sc s_w(KEY_W);
Code_Sc s_x(KEY_X);
Code_Sc s_y(KEY_Y);
Code_Sc s_z(KEY_Z);

Code_Sc s_enter(KEY_ENTER);
Code_Sc s_esc(KEY_ESC);
Code_Sc s_backspace(KEY_BACKSPACE);
Code_Sc s_tab(KEY_TAB);
Code_Sc s_space(KEY_SPACE);
Code_Sc s_minus(KEY_MINUS);
Code_Sc s_equal(KEY_EQUAL);
Code_Sc s_leftBracket(KEY_LEFT_BRACE);           //[ ("brace" means curly bracket {})
Code_Sc s_rightBracket(KEY_RIGHT_BRACE);         //]
Code_Sc s_backslash(KEY_BACKSLASH);
Code_Sc s_semicolon(KEY_SEMICOLON);
Code_Sc s_quote(KEY_QUOTE);
Code_Sc s_graves(KEY_TILDE);                      //`
//Code_Sc s_graves(ASCII_60);                       //`
Code_Sc s_comma(KEY_COMMA);
Code_Sc s_period(KEY_PERIOD);
Code_Sc s_slash(KEY_SLASH);
//Code_Sc s_capsLock(KEY_CAPS_LOCK); todo

Code_Sc s_F1(KEY_F1);
Code_Sc s_F2(KEY_F2);
Code_Sc s_F3(KEY_F3);
Code_Sc s_F4(KEY_F4);
Code_Sc s_F5(KEY_F5);
Code_Sc s_F6(KEY_F6);
Code_Sc s_F7(KEY_F7);
Code_Sc s_F8(KEY_F8);
Code_Sc s_F9(KEY_F9);
Code_Sc s_F10(KEY_F10);
Code_Sc s_F11(KEY_F11);
Code_Sc s_F12(KEY_F12);

Code_Sc s_printscreen(KEY_PRINTSCREEN);
//Code_Sc s_scrollLock(KEY_SCROLL_LOCK); todo
Code_Sc s_pause(KEY_PAUSE);
//Code_Sc s_insert(KEY_INSERT); todo
Code_Sc s_home(KEY_HOME);
//Code_Sc s_pageUp(KEY_PAGE_UP); todo
//Code_Sc s_delete(KEY_DELETE);
Code_Sc s_end(KEY_END);
//Code_Sc s_pageDown(KEY_PAGE_DOWN); todo
Code_Sc s_right(KEY_RIGHT);                      //arrow
Code_Sc s_left(KEY_LEFT);
Code_Sc s_down(KEY_DOWN);
Code_Sc s_up(KEY_UP);

Code_Sc s_KPEnter(KEYPAD_ENTER);
Code_Null code_null;                            //usefull for blank codes

// ---------- SCANCODES SHIFTED ---------
// shifted objects are named after ascii symbol names
Code_ScS s_exclamation(KEY_1);
Code_ScS s_at(KEY_2);
Code_ScS s_number(KEY_3);                        //#
Code_ScS s_dollar(KEY_4);
Code_ScS s_percent(KEY_5);
Code_ScS s_circumflex(KEY_6);                    //^
Code_ScS s_ampersand(KEY_7);
Code_ScS s_asterix(KEY_8);
Code_ScS s_leftParen(KEY_9);                     //parenthesis
Code_ScS s_rightParen(KEY_0);

Code_ScS s_underscore(KEY_MINUS);
Code_ScS s_plus(KEY_EQUAL);
Code_ScS s_leftBrace(KEY_LEFT_BRACE);            //{
Code_ScS s_rightBrace(KEY_RIGHT_BRACE);          //}
Code_ScS s_vertBar(KEY_BACKSLASH);               //|
Code_ScS s_colon(KEY_SEMICOLON);
Code_ScS s_doubleQuote(KEY_QUOTE);
Code_ScS s_tilde(KEY_TILDE);
Code_ScS s_lessThan(KEY_COMMA);
Code_ScS s_greaterThan(KEY_PERIOD);
Code_ScS s_question(KEY_SLASH);

// -------------- LAYER CODES ------------------
//            NORMAL  NAS          NAS         MF
enum layers { NORMAL, TEN_KEY_OFF, TEN_KEY_ON, MF };

//layer LEDs
LED_PCA9655E LED_R16_1green(port1_R, 1<<6);     //LED_D6_3  NORMAL
LED_PCA9655E LED_R15_2blue(port1_R, 1<<5);      //LED_2     NAS TEN_KEY_OFF (or TEN_KEY_ON)
LED_AVR LED_LB7_4yellow(PORTB, 1<<7);           //LED_2     MF

LED_AVR LED_LB4_3yellow(PORTB, 1<<4);           //          NumLock
//LED_AVR LED_LD6_3yellow(PORTD, 1<<6);           //LED_D6_3  NumLock, only Teensy's on-board LED
//LED_AVR LED_LD7_3yellow(PORTD, 1<<7);           //          NumLock, dim

LED_PCA9655E LED_R06_3red(port0_R, 1<<6);       //LED_0     TEN_KEY_ON
//mode indicator LEDs      NORMAL           TEN_KEY_OFF     TEN_KEY_ON    MF
LED * ptrsLayerLEDs[] = { &LED_R16_1green, &LED_R15_2blue, &LED_R06_3red, &LED_LB7_4yellow,
//                       NUM_LOCK
                        &LED_LB4_3yellow };
const uint8_t LED_COUNT = sizeof(ptrsLayerLEDs)/sizeof(*ptrsLayerLEDs);

Code_LayerState_Toggle t_LRModf;
Code_LayerState_Toggle& Code_LayeredDoublePressToggle::refStateLayers = t_LRModf;

//StateLayers_DH stateLayers_DH(t_LRModf, TEN_KEY_ON);
StateLayers_DH stateLayers_DH(t_LRModf, TEN_KEY_ON, ptrsLayerLEDs, LED_COUNT);
Code_LayerLock l_normalLock(NORMAL, stateLayers_DH);
Code_LayerLockMF_Protector l_MFLock(MF, stateLayers_DH);

StateLayers_NAS stateLayers_NAS(TEN_KEY_OFF, stateLayers_DH);
Code_NASHold l_NASHold(stateLayers_NAS);
Code_NASLock_Protector l_NASLock(stateLayers_NAS);
Code_LayerLock l_tenKeyOff(TEN_KEY_OFF, stateLayers_NAS);
Code_LayerLock l_tenKeyOn(TEN_KEY_ON, stateLayers_NAS);

LED_PCA9655E LED_R07_4yellow(port0_R, 1<<7);    //LED_1     MOUSE_ON
StateLayers_MF stateLayers_MF(LED_R07_4yellow);
Code_LayerLock l_mouseOn(0, stateLayers_MF);
Code_LayerLock l_arrowOn(1, stateLayers_MF);

StateLayersInterface& Key_LayeredKeysArray::refStateLayers = stateLayers_DH;

// --------------- SHIFT CODE ------------------
Code_Shift s_shift(MODIFIERKEY_LEFT_SHIFT);
Code_Shift* const ptrsS[] = { &s_shift };
Code_Shift* const* const Code_AutoShift::ptrsShifts = ptrsS;
const uint8_t Code_AutoShift::shiftCount = sizeof(ptrsShifts)/sizeof(*ptrsShifts);

// ----------------- L-R CODES -----------------
Code_LayeredDoublePressToggle t_ctrl(MODIFIERKEY_LEFT_CTRL, MODIFIERKEY_RIGHT_CTRL);
Code_LayeredDoublePressToggle t_alt(MODIFIERKEY_LEFT_ALT, MODIFIERKEY_RIGHT_ALT);
    /* If Code_LayeredDoublePressToggle feature is undesirable,
     * remove refCtrl and refAlt from Row_DH and use Code_LayeredScSc instead:
    Code_LayeredScSc t_ctrl(MODIFIERKEY_LEFT_CTRL, MODIFIERKEY_RIGHT_CTRL);
    Code_LayeredScSc t_alt(MODIFIERKEY_LEFT_ALT, MODIFIERKEY_RIGHT_ALT);
     */

Code_LayeredScSc lr_shift(MODIFIERKEY_LEFT_SHIFT, MODIFIERKEY_RIGHT_SHIFT); //thumb shift
Code_LayeredScSc rl_shift(MODIFIERKEY_LEFT_SHIFT, MODIFIERKEY_RIGHT_SHIFT); //finger shift acts opposite

Code_LayeredNav lr_insert(KEY_INSERT, KEYPAD_0);
Code_LayeredNav lr_delete(KEY_DELETE, KEYPAD_PERIOD);
Code_LayeredNav lr_pageUp(KEY_PAGE_UP, KEYPAD_9);
Code_LayeredNav lr_pageDown(KEY_PAGE_DOWN, KEYPAD_3);
Code_LayeredNav lr_end(KEY_END, KEYPAD_1);

Code_LayeredOperator lr_plus(s_plus, KEYPAD_PLUS);
Code_LayeredOperator lr_asterix(s_asterix, KEYPAD_ASTERIX);
Code_LayeredOperator lr_minus(s_minus, KEYPAD_MINUS);
Code_LayeredOperator lr_slash(s_slash, KEYPAD_SLASH);  //also Normal layer

//define static variables
StateLayers_DH& Code_LayeredNav::refStateLayers = stateLayers_DH;
StateLayers_DH& Code_LayeredOperator::refStateLayers = stateLayers_DH;
Code_LayeredDoublePressToggle& Row_DH::refCtrl = t_ctrl; 
Code_LayeredDoublePressToggle& Row_DH::refAlt = t_alt; 
StateLayersInterface& Code_LayeredScSc::refStateLayers = t_LRModf;

// --------------- LOCK CODES ------------------
LED_AVR LED_LB6_1green(PORTB, 1<<6);            //LED_0     CapsLock
Code_LEDLock o_capsLock(KEY_CAPS_LOCK, LED_LB6_1green);

LED_AVR LED_LB5_2yellow(PORTB, 1<<5);           //LED_1     ScrollLock
Code_LEDLock o_scrollLock(KEY_SCROLL_LOCK, LED_LB5_2yellow);

// -------------- MOUSE CODES ------------------
Code_Mouse_Quick mq_right(1<<1);
Code_Mouse_Quick mq_left(1<<3);
Code_Mouse_Quick mq_down(1<<5);
Code_Mouse_Quick mq_up(1<<7);

Code_Mouse_Slow ms_right(1<<0, 1, 0);
Code_Mouse_Slow ms_left(1<<2, -1, 0);
Code_Mouse_Slow ms_down(1<<4, 0, 1);
Code_Mouse_Slow ms_up(1<<6, 0, -1);

Code_StickyMouseButton mb_1(MOUSE_LEFT);
Code_StickyMouseButton mb_2(MOUSE_RIGHT);
StateStickyMouseButtons mouseButtons(l_MFLock);
Code_Sc mb_3(MOUSE_MIDDLE);

StateStickyMouseButtons& Code_StickyMouseButton::refMouseButtons = mouseButtons;
StateStickyMouseButtons& Code_MouseSpeed::refMouseButtons = mouseButtons;
StateStickyMouseButtons& Row_DH::refMouseButtons = mouseButtons;

// ----------- MOUSE-ARROW CODES ---------------
Code_LayeredCodeSc mqA_right(mq_right, KEYPAD_6); //mouse quick, Arrow
Code_LayeredCodeSc mqA_left(mq_left, KEYPAD_4);
Code_LayeredCodeSc mqA_down(mq_down, KEYPAD_2);
Code_LayeredCodeSc mqA_up(mq_up, KEYPAD_8);
Code_LayeredCodeSc mb1Home(mb_1, KEY_HOME); //mouse-button 1, Home

Code_LayeredCodeSc msA_right(ms_right, KEY_RIGHT); //mouse slow, Arrow
Code_LayeredCodeSc msA_left(ms_left, KEY_LEFT);
Code_LayeredCodeSc msA_down(ms_down, KEY_DOWN);
Code_LayeredCodeSc msA_up(ms_up, KEY_UP);
Code_LayeredCodeSc mb2Home(mb_2, KEY_HOME); //mouse-button 2, Home

//define static variable
StateLayersInterface& Code_LayeredCodeSc::refStateLayers = stateLayers_MF;

// ------------- NUMBER CODES ------------------
Code_NumLock t_numLock(stateLayers_DH);

//n_0 through n_9 are used in TEN_KEY_OFF and TEN_KEY_ON
Code_LayeredNumber n_0(KEY_0);
Code_LayeredNumber n_1(KEY_1);
Code_LayeredNumber n_2(KEY_2);
Code_LayeredNumber n_3(KEY_3);
Code_LayeredNumber n_4(KEY_4);
Code_LayeredNumber n_5(KEY_5);
Code_LayeredNumber n_6(KEY_6);
Code_LayeredNumber n_7(KEY_7);
Code_LayeredNumber n_8(KEY_8);
Code_LayeredNumber n_9(KEY_9);
Code_LayeredNumber_00 n_00;

StateLayers_DH& Code_LayeredNumber::refStateLayers = stateLayers_DH;

// ------------ PROTECTED CODES ----------------
Code_Protected_ByMFLock p_mouseOn(l_mouseOn);
Code_Protected_ByMFLock p_arrowOn(l_arrowOn);
Code_Protected_ByMFLock p_LRModf(t_LRModf);
Code_Protected_ByMFLock p_printscreen(s_printscreen);
Code_Protected_ByMFLock p_F1(s_F1);
Code_Protected_ByMFLock p_F2(s_F2);
Code_Protected_ByMFLock p_F3(s_F3);
Code_Protected_ByMFLock p_F4(s_F4);
Code_Protected_ByMFLock p_F5(s_F5);
Code_Protected_ByMFLock p_F6(s_F6);
Code_Protected_ByMFLock p_F7(s_F7);
Code_Protected_ByMFLock p_F8(s_F8);
Code_Protected_ByMFLock p_F9(s_F9);
Code_Protected_ByMFLock p_F10(s_F10);
Code_Protected_ByMFLock p_F11(s_F11);
Code_Protected_ByMFLock p_F12(s_F12);
Code_Protected_ByMFLock pMF_numLock(t_numLock);
Code_LayerLockMF_Protector& Code_Protected_ByMFLock::refProtector = l_MFLock;

Code_Protected_ByNASLock p_tenKeyOff(l_tenKeyOff);
Code_Protected_ByNASLock p_tenKeyOn(l_tenKeyOn);
Code_Protected_ByNASLock pNAS_numLock(t_numLock);
Code_NASLock_Protector& Code_Protected_ByNASLock::refProtector = l_NASLock;

Code_DoublePressProtected d_printscreen(p_printscreen);

#endif
