// ================ INCLUDES ===================
#include <Arduino.h>

#include <Key_LayeredKeysArray.h>
#include <Code_DoublePressProtected.h>
#include <Row_DH.h>

#include <MouseMove.h>
#include <Debug.h>

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

// ========= OBJECT INSTANTIATIONS =============
#include <instantiations_ports.h>
#include <instantiations_codes.h>
#include <instantiations_matrix.h>              //layout table is with instantiations_matrix.h

// ================== MAIN =====================
void setup()
{
    rowPort1_R.begin();
    colPort0_R.begin();
    Keyboard.begin();
    Mouse.begin();

    LED_LB6_1green.off();
    LED_LB5_2yellow.off();
    LED_LB4_3yellow.off();
    LED_LB7_4yellow.off();

    LED_R16_1green.on();                        //NORMAL mode on
    LED_R15_2blue.off();
    LED_R06_3red.off();
    LED_R07_4yellow.off();

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

    mouseMove.send();

#ifdef PRINT_SCAN_RATE
    //debug.print_scans_per_second();
    debug.print_microseconds_per_scan();
#endif
}
