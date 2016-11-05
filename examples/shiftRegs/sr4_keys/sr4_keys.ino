/* sr4_keys.ino

This sketch is a simple 2-layer keyboard with two rows of PISO shift registers.

IR LED rays are blocked by a square piece of tag board taped on.
The tape acts as a hinge so that the tag board can be pushed out of the way with a paper-clip wire.

Two indicator LEDs are on POSI shift registers.

 Layout of left row         Layout of right row 
|       | **0** | **1** | |       | **0** | **1** |
|-------|-------|-------| |-------|-------|-------|
| **1** |  fn   | a   1 | | **1** |   b   |   c   |
*/
// ################## GLOBAL ###################
// ================= INCLUDES ==================
#include <ScanDelay.h>
#include <LayerState_LED.h>
#include <Code_LayerHold.h>
#include <Key_LayeredKeys.h>
#include <Code_Sc.h>
#include <Row.h>
#include <Debug.h>

//scanner
#include <Scanner_ShiftRegsReadStrobed.h>

//LEDs
#include <Port_ShiftRegs.h>
#include <LED_Port.h>

// ============ SPEED CONFIGURATION ============
ScanDelay scanDelay(4000);

// ==================== ICs ====================
// ---------------- LEFT SCANNER ---------------
Scanner_ShiftRegsReadStrobed scanner_L(HIGH, 6, 1); //active HIGH, slave select 6, 1 byte

// ---------------- RIGHT SCANNER --------------
Scanner_ShiftRegsReadStrobed scanner_R(HIGH, 7, 1); //active HIGH, slave select 7, 1 byte

// ----------------- RIGHT LEDs ----------------
Port_ShiftRegs shiftRegs(8);                    //slave select 8

LED_Port LED_top(shiftRegs, 1<<6);              //pin 6
LED_Port LED_bot(shiftRegs, 1<<7);              //pin 7

// =================== CODES ===================
// ---------------- LAYER CODE -----------------
enum layerIds { NORMAL, FN };

LEDInterface* prtsLayerLEDs[] = { &LED_top, &LED_bot };
LayerState_LED layerState(prtsLayerLEDs);

Code_LayerHold l_fn(FN, layerState);

// ---------------- SCAN CODES -----------------
Code_Sc s_A(KEY_A);
Code_Sc s_B(KEY_B);
Code_Sc s_C(KEY_C);
Code_Sc s_X(KEY_X);
Code_Sc s_Y(KEY_Y);
Code_Sc s_1(KEY_1);

// =================== KEYS ====================
Key* const ptrsKeys_a[] = { &s_A, &s_1 };
Key_LayeredKeys k_a(ptrsKeys_a);

LayerStateInterface& Key_LayeredKeys::refLayerState = layerState;

// ==================== ROWS ===================
Key* ptrsKeys_L[] = { &s_X, &l_fn, &k_a };
const uint8_t KEY_COUNT_L = sizeof(ptrsKeys_L)/sizeof(*ptrsKeys_L);
Row row_L(scanner_L, 16, ptrsKeys_L, KEY_COUNT_L); //strobe pin 0

Key* ptrsKeys_R[] = { &s_Y, &s_B, &s_C };
const uint8_t KEY_COUNT_R = sizeof(ptrsKeys_R)/sizeof(*ptrsKeys_R);
Row row_R(scanner_R, 17, ptrsKeys_R, KEY_COUNT_R); //strobe pin 1

// ################### MAIN ####################
Debug debug;

void setup()
{
    Keyboard.begin();
    delay(6000);
    Keyboard.print(" in setup() ");
    scanner_L.begin();
    scanner_R.begin();
}

void loop()
{
    row_L.process();
    //scanDelay.delay();                          //monitor trackball here

    row_R.process();
    //scanDelay.delay();                          //monitor trackball here

    //debug.printMicrosecondsPerScan(); //63 microseconds per scan when scanDelays are commented
}
