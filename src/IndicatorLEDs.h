#ifndef INDICATORLEDS_H
#define INDICATORLEDS_H

#include <Arduino.h>
#include <inttypes.h>
#include <StateLayers.h>
#include <LED.h>
#include <LED_AVR.h>
//#include <StateLayers_DH.h> circular dependency
//#include <StateLayers_MF.h> circular dependency

/* IndicatorLEDs
*/
class IndicatorLEDs
{
    private:
        //enums are indexes for ptrsLEDs_L and ptrsLEDs_R arrays
        enum LEDs_L { LED_SCROLL_LOCK, LED_NUM_LOCK, LED_MOUSE_ON, LED_CAPS_LOCK };
        enum LEDs_R { LED_NAS, LED_NORMAL, LED_MF, LED_TEN_KEY_ON };
        LED* *const ptrsLEDs_L;                 //array of pointers to indicator LEDs on left unit
        //LED* *const ptrsLEDs_R; not needed?? //array of pointers to indicator LEDs on right unit
        const uint8_t TEN_KEY_ON;
        const uint8_t TEN_KEY_OFF;
        const uint8_t MF;
        LED* *ptrsLayerLEDs;   //array of pointers to indicator LEDs on right unit todo const
    public:
        IndicatorLEDs( LED* ptrsLEDs_L[], LED* ptrsLEDs_R[],
                const uint8_t TEN_KEY_ON, const uint8_t TEN_KEY_OFF, const uint8_t MF)
              : ptrsLEDs_L(ptrsLEDs_L), TEN_KEY_ON(TEN_KEY_ON), TEN_KEY_OFF(TEN_KEY_OFF), MF(MF)
        {
            //map layer indexes to LED pointers
            ptrsLayerLEDs[0] = ptrsLEDs_R[LED_NORMAL];
            ptrsLayerLEDs[1] = ptrsLEDs_R[LED_NAS];
            ptrsLayerLEDs[2] = ptrsLEDs_R[LED_TEN_KEY_ON];
            ptrsLayerLEDs[3] = ptrsLEDs_R[LED_MF];
        }
        void LEDsOff(uint8_t activeLayer);
        void LEDsOn(uint8_t activeLayer);
        void updateLayerLEDs(uint8_t activeLayer);
        void updateNumLockLED(uint8_t lazyNumLock);
        void MouseLEDOn(uint8_t activeLayer);
        void MouseLEDOff();
};
#endif
