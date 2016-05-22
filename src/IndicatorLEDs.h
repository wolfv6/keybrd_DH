#ifndef LEDS
#define LEDS

#include <Arduino.h>
#include <inttypes.h>
#include <StateLayers.h>
#include <LED.h>
#include <LED_AVR.h>
#include <LEDsBlinker.h>
#include <StateLayers_DH.h>
#include <StateLayers_MF.h>

/* IndicatorLEDs

*/
class IndicatorLEDs
{
    private:
        StateLayers_DH& stateLayers_DH;
        LED* *const ptrsLEDs_L;                 //array of pointers to indicator LEDs on left unit
        LED* *const ptrsLayerLEDs;              //array of pointers to indicator LEDs on right unit
        LEDsBlinker blinker_L;
        LEDsBlinker blinker_R;
    public:
        IndicatorLEDs(StateLayers_DH& stateLayers_DH,
                LED* ptrsLEDs_L[], LED* ptrsLayerLEDs[] );
        void startBlinking_L();
        void startBlinking_R();
        void blink();
        void restoreLEDs();
};
#endif
