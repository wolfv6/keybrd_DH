/* sr4_keys.ino

This sketch is a simple 2-layer keyboard with two rows of PISO shift registers

| Left  | **0** | **1** | | Right | **0** | **1** |
|-------|-------|-------| |-------|-------|-------|
| **1** |   l   |   6   | | **1** |   r   |   7   |
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

// ============ SPEED CONFIGURATION ============
ScanDelay scanDelay(9000);

// ==================== ICs ====================
// ---------------- LEFT SCANNER ---------------
Scanner_ShiftRegsPISOMultiRow scanner_L(HIGH, 6, 1); //active HIGH, slave select 6, 1 byte

// ---------------- RIGHT SCANNER --------------
Scanner_ShiftRegsPISOMultiRow scanner_R(HIGH, 7, 1); //active HIGH, slave select 7, 1 byte

// =================== CODES ===================
// ---------------- SCAN CODES -----------------
Code_Sc s_L(KEY_L);
Code_Sc s_R(KEY_R);
Code_Sc s_X(KEY_X);
Code_Sc s_Y(KEY_Y);
Code_Sc s_6(KEY_6);
Code_Sc s_7(KEY_7);

// ==================== ROWS ===================
Key* ptrsKeys_L[] = { &s_X, &s_L, &s_6 };
const uint8_t KEY_COUNT_0 = sizeof(ptrsKeys_L)/sizeof(*ptrsKeys_L);
Row row_L(scanner_L, 16, ptrsKeys_L, KEY_COUNT_0); //strobe pin 0

Key* ptrsKeys_R[] = { &s_Y, &s_R, &s_7 };
const uint8_t KEY_COUNT_1 = sizeof(ptrsKeys_R)/sizeof(*ptrsKeys_R);
Row row_R(scanner_R, 17, ptrsKeys_R, KEY_COUNT_1); //strobe pin 1

// ################### MAIN ####################
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
    row_R.process();

    scanDelay.delay();
    //debug.print_scans_per_second();
    //debug.print_microseconds_per_scan();
}
