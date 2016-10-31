/* sr0_LED_shiftRegs.ino

This sketch:
    is a simple 2-layer keyboard with keys on one row of PISO shift registers
    indicator 1 LED on controller and 2 LEDs on POSI shift register

| Left  | **0** | **1** | **2** |
|-------|-------|-------|-------|
| **0** |CapsLck|  fn   | a  1  |
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
#include <LED_ShiftReg.h>

// ============ SPEED CONFIGURATION ============
ScanDelay scanDelay(9000);

// ==================== ICs ====================
// ---------------- LEFT SCANNER ---------------
Scanner_ShiftRegsPISOMultiRow scanner_L(HIGH, 6, 1); //active HIGH, SS pin 6, 1 byte

// ----------------- LEFT LED ------------------
LED_uC LED_left(4);                             //pin 4

// ---------------- RIGHT LEDs -----------------
Port_ShiftRegs shiftRegs(8);                    //slave select 8

LED_ShiftReg LED_rightTop(shiftRegs, 1<<6);     //pin 6
LED_ShiftReg LED_rightBot(shiftRegs, 1<<7);     //pin 7

// =================== CODES ===================
// ---------------- LAYER CODE -----------------
enum layerIds { NORMAL, FN };

LEDInterface* prtsLayerLEDs[] = { &LED_rightTop, &LED_left };
LayerState_LED layerState(prtsLayerLEDs);

Code_LayerHold l_fn(FN, layerState);

// ---------------- SCAN CODES -----------------
Code_Sc s_a(KEY_A);
Code_Sc s_x(KEY_X);
Code_Sc s_1(KEY_1);
Code_LEDLock o_capsLock(KEY_CAPS_LOCK, LED_rightBot);

// =================== KEYS ====================
Key* const ptrsKeys_01[] = { &s_a, &s_1 };
Key_LayeredKeys k_01(ptrsKeys_01);

LayerStateInterface& Key_LayeredKeys::refLayerState = layerState;

// ==================== ROW ====================
Key* ptrsKeys_0[] = { &s_x, &o_capsLock, &l_fn, &k_01 };
const uint8_t KEY_COUNT_0 = sizeof(ptrsKeys_0)/sizeof(*ptrsKeys_0);
Row row_L(scanner_L, 0, ptrsKeys_0, KEY_COUNT_0); //strobe pin 0

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
    layerState.begin();                 //call LayerState_LED::begin() after Scanner::begin()
}

void loop()
{
    row_L.process();

    scanDelay.delay();
    //debug.print_scans_per_second();
    //debug.print_microseconds_per_scan();
}
