// ================ INCLUDES ===================
#include <Arduino.h>

//todo are forward declares enough for static vars?
#include <Debug.h>
#include <Row_DH.h> //todo or Row.h?
#include <Code_DoublePressProtected.h>
#include <MouseMove.h>
#include <IndicatorLEDs.h>
#include <Key_LayeredKeysArray.h> //todo delete?


// ================= DEBUG =====================
#define PRINT_FREE_RAM      //print free RAM and headers
//#define PRINT_SCAN_RATE     //print scan rate every second

Debug debug;

// =========== SPEED CONFIGURATIONS ============
const unsigned int Row::DELAY_MICROSECONDS = 0; //optic switches don't bounce, and I2C is slow

const uint8_t Code_DoublePressProtected::DOUBLE_PRESS_MILLIS = 250;

//Configure START_ values (START SPEED units are mouseMove() runs sinceSlowPressed).
const uint8_t Code_MouseSpeed::START_NUDGE = 4;
const uint8_t Code_MouseSpeed::START_SLOW = 16;

//Configure _SPEED values (SPEED units are in pixels per Mouse.move sent).
//Max SPEED is 127 because Arduino Mouse.move(signed char, signed char, signed char).
const uint8_t Code_MouseSpeed::NUDGE_SPEED = 2; //each speed is 3x faster than the previouse speed
const uint8_t Code_MouseSpeed::SLOW_SPEED = 6;
const uint8_t Code_MouseSpeed::QUICK_SPEED = 18;
const uint8_t Code_MouseSpeed::HIGH_SPEED = 54;

//smaller SCANS_PER_MOUSE_MOVE parameter results in faster mouse
MouseMove mouseMove(4);

//3 LEDs blink when LRModf is pressed.
const uint8_t IndicatorLEDs::NUM_BLINKS = 5;       //number of blinks to stop
const uint8_t IndicatorLEDs::SCANS_PER_BLINK = 50; //smaller number makes blinking faster
const uint8_t IndicatorLEDs::SCANS_BLINK_ON = 5;   //number of scans per blink that LED is on

// ========= OBJECT INSTANTIATIONS =============
#include <instantiations_ports.h>
#include <instantiations_codes.h>
#include <instantiations_matrix.h>              //layout table is with instantiations_matrix.h

// ================== MAIN =====================
void setup()
{
    rowPort1_R.begin();
    colPort0_R.begin();
    indicatorLEDs.begin(&stateLayers_DH);
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
