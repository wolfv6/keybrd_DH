/* keybrd_DH_unit_tests.ino unit test most classes used in DH on a 5x5 matrix

 layout    | **0**                        | **1**                  | **2**                   | **3**                     | **4**                    |
0          |------------------------------|------------------------|-------------------------|---------------------------|--------------------------|
 class     | Code_LayeredDoublePressToggle| Code_ScS               | Code_Protected_ByNASLock| Code_Protected_ByMFLock   | Code_DoublePressProtected|
 object    | t_ctrl (s_l s_r)             | s_at                   | p_n                     | p_m                       | d_d                      |
 stateLayer| t_LRModf                     |                        | l_NASLock               | l_MFLock                  |                          |
 test case | ctrl ctrl                    | @                      | n NASLock+n             | m MFLock+m                | dd                       |
 output    | l    r                       | @                      |           n             |          m                |  d                       |
1          |------------------------------|------------------------|-------------------------|---------------------------|--------------------------|
 class     | Code_LayeredDoublePressToggle| Code_Sc                | Code_LayeredNumber      | Code_Mouse_Quick          | Code_Mouse_Slow          |
 object    | t_alt (s_0 s_1)              | s_a                    | n_8 (KEY_8)             | mq_up                     | ms_up                    |
 stateLayer| t_LRModf                     |                        | stateLayers_DH          |                           |                          |
 test case | alt alt                      | a                      | 8 numLock 8 numLock 8   | up                        | up                       |
 output    | 0   1                        | a                      | 8         8         8   | <mouse ponter moves up>   | <mouse pointer move slow>|
2          |------------------------------|------------------------|-------------------------|---------------------------|--------------------------|
 class     | Code_LayerState_Toggle       | Code_LEDLock           | Code_NumLock            | Code_StickyMouseButton    | Code_LayeredCodeSc       |
 object    | t_LRModf                     | o_capsLock             | t_numLock               | mb_1                      | mA_ma (s_m KEY_A)        |
 stateLayer|                              |                        |                         |                           | stateLayers_MF           |
 test case | test case below this table   | a capsLck a capLck a   | numLock numLock         | MFLock+mb_1 move   @      |                          |
 output    |                              | a         A        a   | LED-on  LED-off (later) |             select replace|                          |
3          |------------------------------|------------------------|-------------------------|---------------------------|--------------------------|
 class     | Key_LayeredKeysArray         | Code_Layer             | Code_LayerLock          | Code_LayerLock            | Code_LayerLock           |
 l_object  | s_0 s_1 s_2 s_3              | l_tenKeyOff            | l_tenKeyOn              | l_mouseOn                 | l_arrowOn                |
 stateLayer| stateLayers_DH               | l_NASLock              | l_NASLock               | stateLayers_MF            | stateLayers_MF           |
 test case | test case below this table   | tenKeyOff 1            | tenKeyOn 2              | mouseOn ma                |  arrowOn ma              |
 output    |                              |           1            |          2              |         m                 |          a               |
4          |------------------------------|------------------------|-------------------------|---------------------------|--------------------------|
 class     | Code_LayerLock               | Code_NASHold           | Code_NASLock_Protector  | Code_LayerLockMF_Protector| Code_Shift               |
 object    | l_normalLock                 | l_NASHold              | l_NASLock               | l_MFLock                  | s_shift                  |
 stateLayer| stateLayers_DH               | stateLayers_DH         | stateLayers_DH          | stateLayers_DH            | shiftState               |
 test case | NormalLock 0                 | NASHold+1 NASHold+2    | NASLock 1 NASLock 2     | MFLock 3                  | a shift a release a      |
 output    |            0                 |         1         2    |         1         2     |        3                  | a       A         a      |
           |------------------------------|------------------------|-------------------------|---------------------------|--------------------------|

 test case   ctrl @ ctrl @ LRMof ctrl @ ctrl LRModf ctrl @ ctrl ctrl ctrl ctrl
 output      l    @ l    @       r    @ r           l    @ l    r    l    r

 test case   NormalLock 0 NASHold 0 NASHold+1 NASLock 1 tenKeyOn 2 MFLock 3 NASHold+2 3 NASLock 2 tenKeyOff 1 NormalLock 0
 output                 0         0         1         1          2        3         2 3         2           1            0

 not tested:
    Code_LayeredNav
    Code_LayeredOperator
    Code_LayeredScSc
    Code_LayeredNumber_00
    Code_Null
*/
// ################# GLOBAL ####################
// ================ INCLUDES ===================
//Code
#include <Code_Shift.h>
#include <Code_AutoShift.h>
#include <Code_Sc.h>
#include <Code_ScS.h>
#include <Code_Null.h>
#include <Code_LEDLock.h>
#include <Code_NumLock.h>

//Mouse
#include <StateStickyMouseButtons.h>
#include <Code_StickyMouseButton.h>
#include <Code_Mouse_Slow.h>
#include <Code_Mouse_Quick.h>

//StateLayers
#include <StateLayers.h>
#include <StateLayers_DH.h>
#include <StateLayers_NAS.h>
#include <Code_NASHold.h>
#include <Code_NASLock_Protector.h>

//Layer
#include <Code_LayerLock.h>
#include <Code_LayerLockMF_Protector.h>
#include <Code_LayerState_Toggle.h>

//Layered
#include <Key_LayeredKeysArray.h>
#include <Code_LayeredCodeSc.h>
#include <Code_LayeredNumber.h>
#include <Code_LayeredNumber_00.h>
#include <Code_LayeredDoublePressToggle.h>

//protected
#include <Code_Protected_ByMFLock.h>
#include <Code_Protected_ByNASLock.h>
#include <Code_DoublePressProtected.h>

//back end
#include <RowPort_AVR_Optic.h>
#include <ColPort_AVR.h>
#include <LED_AVR.h>

#include <Wire.h>
#include <Row_DH.h>
#include <Matrix.h>
#include <MouseMove.h>

#include <Debug.h>

// =========== SPEED CONFUGURATIONS ============
const unsigned int Row::DELAY_MICROSECONDS = 1000;

const uint8_t Code_DoublePressProtected::DOUBLE_PRESS_MILLIS = 250;

//Configure START_ values (START SPEED units are mouseMove() runs sinceSlowPressed).
const uint8_t Code_MouseSpeed::START_NUDGE = 4;
const uint8_t Code_MouseSpeed::START_SLOW = 16;

//Configure _SPEED values (SPEED units are in pixels per Mouse.move sent).
//Configure SCANS_PER_MOUSE_MOVE in class MouseMove constructor.
//Max SPEED is 127 because Arduino Mouse.move(signed char, signed char, signed char).
const uint8_t Code_MouseSpeed::NUDGE_SPEED = 2; //3x
const uint8_t Code_MouseSpeed::SLOW_SPEED = 6;
const uint8_t Code_MouseSpeed::QUICK_SPEED = 18;
const uint8_t Code_MouseSpeed::HIGH_SPEED = 54;

// ================= PORTS =====================
RowPort_AVR_Optic rowPortF_L(DDRF, PORTF);

ColPort_AVR colPortB_L(DDRB, PORTB, PINB, 1<<0 | 1<<1 | 1<<2 | 1<<3 );
ColPort_AVR colPortD_L(DDRD, PORTD, PIND, 1<<2 ); //| 1<<3

ColPort* const ptrsColPorts_L[] = { &colPortB_L, &colPortD_L };
const uint8_t COL_PORT_L_COUNT = sizeof(ptrsColPorts_L)/sizeof(*ptrsColPorts_L);

// ---------------- led pins -------------------
LED_AVR LED_LB6_1green(PORTB, 1<<6);            //CapsLock
LED_AVR LED_LB4_3yellow(PORTB, 1<<4);           //NumLock

// will test LED flash later
// insert blue 10K resistor in left green LED

// ================= CODES =====================
// -------------- layer codes ------------------
//            NORMAL  NAS          NAS         MF
enum layers { NORMAL, TEN_KEY_OFF, TEN_KEY_ON, MF };

Code_LayerState_Toggle t_LRModf;
Code_LayerState_Toggle& Code_LayeredDoublePressToggle::refStateLayers = t_LRModf;

StateLayers_DH stateLayers_DH(t_LRModf, TEN_KEY_ON);
Code_LayerLock l_normalLock(NORMAL, stateLayers_DH);
Code_LayerLockMF_Protector l_MFLock(MF, stateLayers_DH);

StateLayers_NAS stateLayers_NAS(TEN_KEY_OFF, stateLayers_DH);
Code_NASHold l_NASHold(stateLayers_NAS);
Code_NASLock_Protector l_NASLock(stateLayers_NAS);
Code_LayerLock l_tenKeyOff(TEN_KEY_OFF, stateLayers_NAS);
Code_LayerLock l_tenKeyOn(TEN_KEY_ON, stateLayers_NAS);

StateLayers stateLayers_MF;
Code_LayerLock l_mouseOn(0, stateLayers_MF);
Code_LayerLock l_arrowOn(1, stateLayers_MF);

// --------------- shift code ------------------
Code_Shift s_shift(MODIFIERKEY_LEFT_SHIFT);
Code_Shift *const ptrsS[] = { &s_shift };
Code_Shift *const *const Code_AutoShift::ptrsShifts = ptrsS;
const uint8_t Code_AutoShift::shiftCount = sizeof(ptrsShifts)/sizeof(*ptrsShifts);

// --------------- scan codes ------------------
Code_Sc s_0(KEY_0);
Code_Sc s_1(KEY_1);
Code_Sc s_2(KEY_2);
Code_Sc s_3(KEY_3);

Code_Sc s_a(KEY_A);
Code_Sc s_d(KEY_D);
Code_Sc s_m(KEY_M);
Code_Sc s_n(KEY_N);

Code_ScS s_at(KEY_2);
//Code_LayeredNumber_00 s_00;
//Code_Null code_null;

// ------------- number codes ------------------
Code_NumLock t_numLock(stateLayers_DH);

Code_LayeredNumber n_8(KEY_8);
StateLayers_DH& Code_LayeredNumber::refStateLayers = stateLayers_DH;

// ------------- ctrl alt codes ----------------
Code_LayeredDoublePressToggle t_ctrl(KEY_L, KEY_R);
Code_LayeredDoublePressToggle t_alt(KEY_0, KEY_1);

//define static variables
Code_LayeredDoublePressToggle& Row_DH::refCtrl = t_ctrl; 
Code_LayeredDoublePressToggle& Row_DH::refAlt = t_alt; 

// ------------ protected codes ----------------
Code_Protected_ByNASLock p_n(s_n);
Code_NASLock_Protector& Code_Protected_ByNASLock::refProtector = l_NASLock;

Code_Protected_ByMFLock p_m(s_m);
Code_LayerLockMF_Protector& Code_Protected_ByMFLock::refProtector = l_MFLock;

Code_DoublePressProtected d_d(s_d);

// -------------- mouse codes ------------------
Code_Mouse_Quick mq_up(1<<7);
Code_Mouse_Slow ms_up(1<<6, 0, -1);

MouseMove mouseMove(16);

Code_StickyMouseButton mb_1(MOUSE_LEFT);
StateStickyMouseButtons mouseButtons(l_MFLock);

StateStickyMouseButtons& Code_StickyMouseButton::refMouseButtons = mouseButtons;
StateStickyMouseButtons& Code_MouseSpeed::refMouseButtons = mouseButtons;
StateStickyMouseButtons& Row_DH::refMouseButtons = mouseButtons;

// ----------- mouse-arrow keys ----------------
Code_LayeredCodeSc mA_ma(s_m, KEY_A);
StateLayersInterface& Code_LayeredCodeSc::refStateLayers = stateLayers_MF;

// --------------- lock codes ------------------
Code_LEDLock o_capsLock(KEY_CAPS_LOCK, LED_LB6_1green);
//Code_LEDLock o_numLock(KEY_NUM_LOCK, LED_LB4_3yellow);

// -------------- layered keys -----------------
Key* const ptrsCodes_0123[] = {&s_0, &s_1, &s_2, &s_3};
Key_LayeredKeysArray k_0123(ptrsCodes_0123);
StateLayersInterface& Key_LayeredKeysArray::refStateLayers = stateLayers_DH;

// ================= LAYOUT ====================
// ------------------ rows ---------------------
Key* const ptrsKeys_L0[] = { &t_ctrl, &s_at, &p_n, &p_m, &d_d };
Row_DH row_L0(rowPortF_L, 1<<0, ptrsColPorts_L, COL_PORT_L_COUNT, ptrsKeys_L0);

Key* const ptrsKeys_L1[] = { &t_alt, &s_a, &n_8, &mq_up, &ms_up };
Row_DH row_L1(rowPortF_L, 1<<1, ptrsColPorts_L, COL_PORT_L_COUNT, ptrsKeys_L1);

Key* const ptrsKeys_L2[] = { &t_LRModf, &o_capsLock, &t_numLock, &mb_1, &mA_ma };
Row_DH row_L2(rowPortF_L, 1<<4, ptrsColPorts_L, COL_PORT_L_COUNT, ptrsKeys_L2);

Key* const ptrsKeys_L3[] = { &k_0123, &l_tenKeyOff, &l_tenKeyOn, &l_mouseOn, &l_arrowOn };
Row_DH row_L3(rowPortF_L, 1<<5, ptrsColPorts_L, COL_PORT_L_COUNT, ptrsKeys_L3);

Key* const ptrsKeys_L4[] = { &l_normalLock, &l_NASHold, &l_NASLock, &l_MFLock, &s_shift };
//Key* const ptrsKeys_L4[] = { &l_normalLock, &l_NASHold, &l_NASLock, &l_MFLock, &s_at };
Row_DH row_L4(rowPortF_L, 1<<6, ptrsColPorts_L, COL_PORT_L_COUNT, ptrsKeys_L4);

// ----------------- matrix --------------------
Row* const ptrsRows_L[] = { &row_L0, &row_L1, &row_L2, &row_L3, &row_L4 };
const uint8_t ROW_L_COUNT = sizeof(ptrsRows_L)/sizeof(*ptrsRows_L);

Matrix matrix_L(ptrsRows_L, ROW_L_COUNT, 1);

// ================= DEBUG =====================
Debug debug;

// ################## MAIN #####################
void setup()
{
    Keyboard.begin();
    delay(1000);        //time for OS to detect USB before printing
    Keyboard.print(F("keybrd_DH_unit_tests.ino, "));
    debug.print_free_RAM();
}

void loop()
{
    matrix_L.scan();
    mouseMove.send();
}
