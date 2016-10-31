/* sr0_LED_shiftRegs.ino

This sketch:
    is a simple 2-layer keyboard with keys on one row of PISO shift registers
    indicator 1 LED on controller and 2 LEDs on POSI shift register

| Left  | **0** | **1** | **2** |
|-------|-------|-------|-------|
| **0** |  fn   |CapsLck| a  1  |
*/
// ################## GLOBAL ###################
// ================= INCLUDES ==================
#include <ScanDelay.h>
#include <LayerState_LED.h>
#include <Code_LayerHold.h>
#include <Code_LEDLock.h>
#include <Key_LayeredKeys.h>
#include <Code_Sc.h>
#include <Row.h>

//scanner
#include <Scanner_ShiftRegsPISOMultiRow.h>

//LEDs
#include <LED_uC.h>
#include <Port_ShiftRegs.h>
#include <LED_Port.h>

// ============ SPEED CONFIGURATION ============
ScanDelay scanDelay(9000);

// ==================== ICs ====================
// ---------------- LEFT SCANNER ---------------
Scanner_ShiftRegsPISOMultiRow scanner_L(HIGH, 6, 1); //active HIGH, slave select 6, 1 byte

// ----------------- LEFT LED ------------------
LED_uC LED_left(4);                             //pin 4

// ---------------- RIGHT SCANNER --------------
Scanner_ShiftRegsPISOMultiRow scanner_R(HIGH, 7, 1); //active HIGH, slave select 7, 1 byte

// ----------------- RIGHT LEDs ----------------
Port_ShiftRegs shiftRegs(8);                    //slave select 8

LED_Port LED_rightTop(shiftRegs, 1<<6);         //pin 6
LED_Port LED_rightBot(shiftRegs, 1<<7);         //pin 7

// =================== CODES ===================
// ---------------- LAYER CODE -----------------
enum layerIds { NORMAL, FN };

LEDInterface* prtsLayerLEDs[] = { &LED_rightTop, &LED_left };
LayerState_LED layerState(prtsLayerLEDs);

Code_LayerHold l_fn(FN, layerState);

// ---------------- SCAN CODES -----------------
Code_Sc s_a(KEY_A);
Code_Sc s_x(KEY_X);
Code_Sc s_y(KEY_Y);
Code_Sc s_1(KEY_1);
Code_LEDLock o_capsLock(KEY_CAPS_LOCK, LED_rightBot);

// =================== KEYS ====================
Key* const ptrsKeys_a[] = { &s_a, &s_1 };
Key_LayeredKeys k_a(ptrsKeys_a);

LayerStateInterface& Key_LayeredKeys::refLayerState = layerState;

// ==================== ROWS ===================
Key* ptrsKeys_L[] = { &s_x, &l_fn, &o_capsLock };
const uint8_t KEY_COUNT_0 = sizeof(ptrsKeys_L)/sizeof(*ptrsKeys_L);
Row row_L(scanner_L, 0, ptrsKeys_L, KEY_COUNT_0); //strobe pin 0

Key* ptrsKeys_R[] = { &s_y, &k_a };
const uint8_t KEY_COUNT_1 = sizeof(ptrsKeys_R)/sizeof(*ptrsKeys_R);
Row row_R(scanner_R, 1, ptrsKeys_R, KEY_COUNT_1); //strobe pin 1

/* ################### MAIN ####################
LayerState_LED::begin() is called after Scanner_IOE::begin()
so that scanner's ports can turn on LayerState_LED's default-layer LED.
*/
void setup()
{
    Keyboard.begin();
    delay(6000);
    Keyboard.print(" in setup() ");
    scanner_L.begin();
    scanner_R.begin();
    layerState.begin();                 //call LayerState_LED::begin() after Scanner::begin()
}

void loop()
{
    row_L.process();
    row_R.process();

    scanDelay.delay();
    //debug.print_scans_per_second();
    //debug.print_microseconds_per_scan();
}
