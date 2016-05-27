#ifndef LEDSBLINKER_H
#define LEDSBLINKER_H

#include <Arduino.h>
#include <inttypes.h>
#include <StateLayers_DH.h>
#include <LED.h>
/*
When LRModf key is pressed, first 3 LEDs on L or R side blink.
NUM_BLINKS * SCANS_PER_BLINK + SCANS_BLINK_ON < 256
*/
class LEDsBlinker
{
    private:
        LED* *const ptrsLEDs;                   //array of pointers to indicator LEDs
        static StateLayers_DH& refStateLayers_DH;
        static const uint8_t NUM_BLINKS;        //number of blinks to stop
        static const uint8_t SCANS_PER_BLINK;   //smaller number makes blinking faster
        static const uint8_t SCANS_BLINK_ON;    //number of scans per blink that LED is on
        uint8_t scansSinceFirstBlink;           //magic number 0 means not blinking
    public:
        LEDsBlinker(LED* ptrsLEDs[]) : ptrsLEDs(ptrsLEDs), scansSinceFirstBlink(0) {}
        void startBlinking();
        void blink();                           //called from sketch loop()
};
#endif
