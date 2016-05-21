#ifndef LEDSBLINKER_H
#define LEDSBLINKER_H

#include <Arduino.h>
#include <inttypes.h>
#include <StateLayers_DH.h>
#include <LED.h>
/*
When LRModf key is pressed, 3 LEDs on L or R side blink 4 times in 2 seconds.
*/
class LEDsBlinker
{
    private:
        LED& LED0;
        LED& LED1;
        LED& LED2;
        static StateLayers_DH& refStateLayers;
        const uint8_t NUM_BLINKS;               //number of blinks to stop
        const uint8_t SCANS_PER_BLINK;          //NUM_BLINKS * SCANS_PER_BLINK < 256
        uint8_t scansSinceFirstBlink;           //0 means not blinking
    public:
        LEDsBlinker(LED& LED0, LED& LED1, LED& LED2) //todo add speed param SCANS_PER_BLINK
            : LED0(LED0), LED1(LED1), LED2(LED2),
            NUM_BLINKS(8), SCANS_PER_BLINK(62), scansSinceFirstBlink(0) {}
        void startBlinking();
        void blink();                           //called from sketch loop()
};
#endif
