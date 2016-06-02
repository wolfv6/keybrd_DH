#include <Row_DH.h>
#include <Code_DoublePressProtected.h>
#include <Code_MouseSpeed.h>
#include <IndicatorLEDs.h>

// =========== SPEED CONFIGURATIONS ============
const unsigned int RowBase::DELAY_MICROSECONDS = 0; //optic switches don't bounce, I2C poling slow

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

//three LEDs blink when LRModf is pressed.
const uint8_t IndicatorLEDs::NUM_BLINKS = 5;       //number of blinks to stop blinking
const uint8_t IndicatorLEDs::SCANS_PER_BLINK = 50; //smaller number makes blinking faster
const uint8_t IndicatorLEDs::SCANS_BLINK_ON = 5;   //number of scans per blink that LED is on

