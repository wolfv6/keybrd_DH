/* hardware: shift registers, 3.3 volts, and 2 tactile switches
modified from keybrd_4b_split_keyboard_with_shift_registers.ino
use Scanner_ShiftRegsPISOMultiRow to strobe one row of LEDs at a time
Tested on Teensy LC and two 74HC165 shift registers

 Two shift registers
| Left  | **0** | **1** |
|-------|-------|-------|
| **1** |   6   |   b   |
*/
// ################## GLOBAL ###################
// ================= INCLUDES ==================
#include <Debug.h>
#include <ScanDelay.h>
#include <Code_Sc.h>

#include <Row.h>
#include <Scanner_ShiftRegsPISOMultiRow.h>

// =============== CONFIGURATION ===============
ScanDelay scanDelay(9000);
Debug debug;

// =================== CODES ===================
Code_Sc s_a(KEY_A);
Code_Sc s_b(KEY_B);
Code_Sc s_c(KEY_C);
Code_Sc s_d(KEY_D);
Code_Sc s_e(KEY_E);
Code_Sc s_f(KEY_F);
Code_Sc s_g(KEY_G);

Code_Sc s_0(KEY_0);
Code_Sc s_1(KEY_1);
Code_Sc s_2(KEY_2);
Code_Sc s_3(KEY_3);
Code_Sc s_4(KEY_4);
Code_Sc s_5(KEY_5);
Code_Sc s_6(KEY_6);

// ================= SCANNERS ==================
// --------------- LEFT SCANNER ----------------
Scanner_ShiftRegsPISOMultiRow scanner_L(HIGH, SS, 2); //active HIGH

// =================== ROWS ====================
// ----------------- LEFT ROWS -----------------
Key* ptrsKeys_L0[] = { &s_6, &s_5, &s_4, &s_3,  //74HC165 on right
                       &s_c, &s_d, &s_e, &s_f,
                       &s_2, &s_1, &s_0, &s_g,  //74HC165 on left
                       &s_a, &s_b
                     };
//Teensy LC pin 16 has 20mA
//in Scanner_ShiftRegsPISOMultiRow::scan(), delayMicroseconds(50) to stablize voltage
//on Teensy 2.0 it only needs delayMicroseconds(3)
//might be due to lower voltage on IRPhotoTrans and/or IR LED
Row row_L0(scanner_L, 16, ptrsKeys_L0, sizeof(ptrsKeys_L0)/sizeof(*ptrsKeys_L0));

// ################### MAIN ####################
void setup()
{
    Keyboard.begin();
    scanner_L.begin();
}

void loop()
{
    //left matrix
    row_L0.process();

    scanDelay.delay();
    //debug.printMicrosecondsPerScan();
}
