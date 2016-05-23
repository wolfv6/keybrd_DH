#ifndef LEDS
#define LEDS

#include <Arduino.h>
#include <inttypes.h>
#include <StateLayers.h>
#include <LED.h>
#include <LED_AVR.h>
//#include <StateLayers_DH.h> circular dependency
#include <StateLayers_MF.h>

/* IndicatorLEDs

*/
class IndicatorLEDs
{
    private:
        LED* *const ptrsLEDs_L;                 //array of pointers to indicator LEDs on left unit
        LED* *const ptrsLayerLEDs;              //array of pointers to indicator LEDs on right unit
        const uint8_t TEN_KEY_ON;
        const uint8_t TEN_KEY_OFF;
        const uint8_t MF;
    public:
        IndicatorLEDs( LED* ptrsLEDs_L[], LED* ptrsLayerLEDs[],
                const uint8_t TEN_KEY_ON, const uint8_t TEN_KEY_OFF, const uint8_t MF)
            : ptrsLEDs_L(ptrsLEDs_L), ptrsLayerLEDs(ptrsLayerLEDs),
                TEN_KEY_ON(TEN_KEY_ON), TEN_KEY_OFF(TEN_KEY_OFF), MF(MF) {}
        void LEDsOff(uint8_t activeLayer);
        void LEDsOn(uint8_t activeLayer);
        void updateLayerLEDs(uint8_t activeLayer);
        void updateNumLockLED(uint8_t lazyNumLock);
};
#endif
