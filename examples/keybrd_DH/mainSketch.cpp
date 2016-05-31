// ================ INCLUDES ===================
#include <Arduino.h>

#include <Debug.h>
#include <MouseMove.h>
#include <IndicatorLEDs.h>

// ================= DEBUG =====================
#define PRINT_FREE_RAM      //print free RAM and headers
//#define PRINT_SCAN_RATE     //print scan rate every second

Debug debug;

// ======= INSTANTIATION THE KEYBOARD ==========
#include "config.h"
#include <instantiations_ports.h>
#include <instantiations_codes.h>
#include <instantiations_matrix.h>              //layout table is with instantiations_matrix.h

// ================== MAIN =====================
void setup()
{
    rowPort1_R.begin();
    colPort0_R.begin();
    indicatorLEDs.begin(&layerState_DH);
    Keyboard.begin();
    Mouse.begin();

#ifdef PRINT_FREE_RAM
    delay(1000);        //time for OS to detect USB before printing
    Keyboard.print(F("keybrd_DH.ino "));
    debug.print_free_RAM();
#endif //end PRINT_FREE_RAM
}

void loop()
{
    matrix_L.scan();
    matrix_R.scan();
    indicatorLEDs.blink();
    mouseMove.send();

#ifdef PRINT_SCAN_RATE
    //debug.print_scans_per_second();
    debug.print_microseconds_per_scan();
#endif
}
