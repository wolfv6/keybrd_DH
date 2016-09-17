#ifndef INSTANTIATIONS_LAYERCODES_H
#define INSTANTIATIONS_LAYERCODES_H

/* This file instantiates layer-code and scancode objects that depend on layer codes.
*/

//LED
#include <IndicatorLEDs.h>

//LayerState
class LayerStateInterface;
#include <LayerState_DH.h>
#include <LayerState_NAS.h>

//Layer
#include <Code_LayerLock.h>
#include <Code_LayerLockMF_Protector.h>
#include <Code_NASHold.h>
#include <Code_NASLock_Protector.h>
#include <Code_NumLock.h>
#include <Code_LayerLock_MFSub.h>
#include <Code_LayerState_Toggle.h>

//Layered
#include <Key_LayeredKeysArray.h>
#include <Key_LayeredCodeSc_MF.h>
#include <Key_LayeredNumber.h>
#include <Key_LayeredNumber_00.h>
#include <Key_LayeredNav.h>
#include <Key_LayeredOperator.h>
#include <Key_LayeredDoublePressToggle.h>
#include <Key_LayeredScSc.h>

//Mouse
#include <StateStickyMouseButtons.h>
#include <Code_StickyMouseButton.h>
#include <Code_Mouse_Slow.h>
#include <Code_Mouse_Quick.h>
#include <Row_DH.h>

//protected
#include <Code_Protected_ByMFLock.h>
#include <Code_Protected_ByNASLock.h>
#include <Code_DoublePressProtected.h>

// -------------- PRIMARY LAYERS ---------------
//            NORMAL  NAS          NAS         MF
enum layers { NORMAL, TEN_KEY_OFF, TEN_KEY_ON, MF };

IndicatorLEDs indicatorLEDs(ptrsLEDs_L, ptrsLEDs_R, TEN_KEY_OFF, TEN_KEY_ON, MF);

LayerState_DH layerState_DH(TEN_KEY_ON, indicatorLEDs);
Code_LayerLock l_normalLock(NORMAL, layerState_DH);
Code_LayerLockMF_Protector l_MFLock(MF, layerState_DH);

LayerState_NAS layerState_NAS(TEN_KEY_OFF, layerState_DH);
Code_NASHold l_NASHold(layerState_NAS);
Code_NASLock_Protector l_NASLock(layerState_NAS);
Code_LayerLock l_tenKeyOff(TEN_KEY_OFF, layerState_NAS);
Code_LayerLock l_tenKeyOn(TEN_KEY_ON, layerState_NAS);

Code_LayerLock_MFSub l_mouseOn(0, layerState_DH);
Code_LayerLock_MFSub l_arrowOn(1, layerState_DH);

LayerStateInterface& Key_LayeredKeysArray::refLayerState = layerState_DH;

// ----------------- L-R CODES -----------------
Code_LayerState_Toggle t_LRModf(indicatorLEDs, ptrsLEDs_L, ptrsLEDs_R);

Key_LayeredDoublePressToggle t_ctrl(MODIFIERKEY_LEFT_CTRL, MODIFIERKEY_RIGHT_CTRL);
Key_LayeredDoublePressToggle t_alt(MODIFIERKEY_LEFT_ALT, MODIFIERKEY_RIGHT_ALT);
Code_LayerState_Toggle& Key_LayeredDoublePressToggle::refLayerState = t_LRModf;
//To remove Key_LayeredDoublePressToggle feature,
//remove refCtrl and refAlt from Row_DH and use Key_LayeredScSc instead:
//Key_LayeredScSc t_ctrl(MODIFIERKEY_LEFT_CTRL, MODIFIERKEY_RIGHT_CTRL);
//Key_LayeredScSc t_alt(MODIFIERKEY_LEFT_ALT, MODIFIERKEY_RIGHT_ALT);

Key_LayeredNav lr_insert(KEY_INSERT, KEYPAD_0);
Key_LayeredNav lr_delete(KEY_DELETE, KEYPAD_PERIOD);
Key_LayeredNav lr_pageUp(KEY_PAGE_UP, KEYPAD_9);
Key_LayeredNav lr_pageDown(KEY_PAGE_DOWN, KEYPAD_3);
Key_LayeredNav lr_end(KEY_END, KEYPAD_1);
LayerState_DH& Key_LayeredNav::refLayerState_DH = layerState_DH;
Code_LayerState_Toggle& Key_LayeredNav::refStateLRModf = t_LRModf;

Key_LayeredOperator lr_plus(s_plus, KEYPAD_PLUS);
Key_LayeredOperator lr_asterix(s_asterix, KEYPAD_ASTERIX);
Key_LayeredOperator lr_minus(s_minus, KEYPAD_MINUS);
Key_LayeredOperator lr_slash(s_slash, KEYPAD_SLASH);  //also Normal layer
LayerState_DH& Key_LayeredOperator::refLayerState_DH = layerState_DH;
Code_LayerState_Toggle& Key_LayeredOperator::refStateLRModf = t_LRModf;
const uint8_t Key_LayeredOperator::TEN_KEY_ON = TEN_KEY_ON;

Key_LayeredScSc lr_shift(MODIFIERKEY_LEFT_SHIFT, MODIFIERKEY_RIGHT_SHIFT); //thumb shift
Key_LayeredScSc rl_shift(MODIFIERKEY_LEFT_SHIFT,
                          MODIFIERKEY_RIGHT_SHIFT); //finger shift acts opposite
LayerStateInterface& Key_LayeredScSc::refLayerState = t_LRModf;

// ------------- NUMBER CODES ------------------
Code_NumLock t_numLock(layerState_DH);

//n_0 through n_9 are used in TEN_KEY_OFF and TEN_KEY_ON
Key_LayeredNumber n_0(KEY_0);
Key_LayeredNumber n_1(KEY_1);
Key_LayeredNumber n_2(KEY_2);
Key_LayeredNumber n_3(KEY_3);
Key_LayeredNumber n_4(KEY_4);
Key_LayeredNumber n_5(KEY_5);
Key_LayeredNumber n_6(KEY_6);
Key_LayeredNumber n_7(KEY_7);
Key_LayeredNumber n_8(KEY_8);
Key_LayeredNumber n_9(KEY_9);
Key_LayeredNumber_00 n_00;

LayerState_DH& Key_LayeredNumber::refLayerState_DH = layerState_DH;

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
Key_LayeredCodeSc_MF mqA_right(mq_right, KEYPAD_6); //mouse quick, Arrow
Key_LayeredCodeSc_MF mqA_left(mq_left, KEYPAD_4);
Key_LayeredCodeSc_MF mqA_down(mq_down, KEYPAD_2);
Key_LayeredCodeSc_MF mqA_up(mq_up, KEYPAD_8);
Key_LayeredCodeSc_MF mb1Home(mb_1, KEY_HOME); //mouse-button 1, Home

Key_LayeredCodeSc_MF msA_right(ms_right, KEY_RIGHT); //mouse slow, Arrow
Key_LayeredCodeSc_MF msA_left(ms_left, KEY_LEFT);
Key_LayeredCodeSc_MF msA_down(ms_down, KEY_DOWN);
Key_LayeredCodeSc_MF msA_up(ms_up, KEY_UP);
Key_LayeredCodeSc_MF mb2Home(mb_2, KEY_HOME); //mouse-button 2, Home

//define static variable
LayerState_DH& Key_LayeredCodeSc_MF::refLayerState_DH = layerState_DH;

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
