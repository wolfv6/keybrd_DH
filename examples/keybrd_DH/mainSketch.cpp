// ================ INCLUDES ===================
#include <Arduino.h>

#include <Debug.h>
#include <MouseMove.h>
#include <IndicatorLEDs.h>

// ================= DEBUG =====================
Debug debug;

// ======= INSTANTIATION THE KEYBOARD ==========
#include "config.h"
#include <instantiations_pins.h>
#include <instantiations_codes.h>
#include <instantiations_rows.h>                //layout table is with instantiations_rows.h

// ================== MAIN =====================
void setup()
{
    Wire.begin(); //todo has not been tested yet,
        //Wire.begin() must be called before rowPort.begin() colPort.begin()
    strobePort1_R.begin();
    readPort0_R.begin();
    indicatorLEDs.begin(&layerState_DH);
    Keyboard.begin();
    Mouse.begin();

    delay(1000);        //time for OS to detect USB before printing
    Keyboard.println(F("keybrd_DH.ino"));
}

void loop()
{
    //left matrix
    row_L0.process();
    row_L1.process();
    row_L2.process();
    row_L3.process();
    row_L4.process();
/*
*/

    //right matrix
    row_R0.process();
    row_R1.process();
    row_R2.process();
    row_R3.process();
    row_R4.process();

/*todo uncommment
    indicatorLEDs.blink();
    mouseMove.send();
*/
    //debug.print_scans_per_second();
    //debug.print_microseconds_per_scan();
}
