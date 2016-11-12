// ================ INCLUDES ===================
#include <Arduino.h>

#include <Debug.h>
#include <MouseMove.h>
#include <IndicatorLEDs.h>

// ================= DEBUG =====================
Debug debug;

// ========= INSTANTIATE THE KEYBOARD ==========
//layout table is in keybrd_DH_library_developer_guide.md
#include "config.h"
#include <instantiations_scannersLEDs.h>
#include <instantiations_scancodes.h>
#include <instantiations_layercodes.h>
#include <instantiations_rows_L.h>
#include <instantiations_rows_R.h>

// ================== MAIN =====================
void setup()
{
    Keyboard.begin();
    Mouse.begin();
    scanner_R.begin();
    indicatorLEDs.begin(&layerState_DH);

    delay(1000);                                //time for OS to detect USB before printing
    Keyboard.println(F("keybrd_DH.ino"));
}

void loop()
{
    left matrix
    row_L0.process();
    row_L1.process();
    row_L2.process();
    row_L3.process();
    row_L4.process();

    //right matrix
    row_R0.process();
    row_R1.process();
    row_R2.process();
    row_R3.process();
    row_R4.process();

    indicatorLEDs.blink();
    mouseMove.send();

    //debug.print_scans_per_second();
    //debug.print_microseconds_per_scan();
}
