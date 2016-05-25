#ifndef INDICATORLEDS_H
#define INDICATORLEDS_H

#include <Arduino.h>
#include <inttypes.h>
#include <LED.h>

/* IndicatorLEDs
ptrsLEDs_L[] and ptrsLEDs_R[] arrays contain indicator LEDs in the order of appearance on keyboard.
*/
#define LED_COUNT_PER_ARRAY 4

class IndicatorLEDs
{
    private:
        //Enumerators are LED-role assignments, used as ptrsLEDs_L and ptrsLEDs_R array indexes.
        //Enumerator roles are in the order of corresponding LEDs as they appear on the keyboard.
        enum LED_ROLES_L { LED_SCROLL_LOCK, LED_NUM_LOCK, LED_MOUSE_ON, LED_CAPS_LOCK };
        enum LED_ROLES_R { LED_NAS, LED_NORMAL, LED_MF, LED_TEN_KEY_ON };
        LED*const *const ptrsLEDs_L;            //array of pointers to indicator LEDs on left unit
        const uint8_t NORMAL;                   //layer id
        const uint8_t TEN_KEY_OFF;              //layer id
        const uint8_t TEN_KEY_ON;               //layer id
        const uint8_t MF;                       //layer id
        LED* ptrsLayerLEDs[LED_COUNT_PER_ARRAY];//array of ptrs to indicator LEDs on right unit,
                                                //ordered by layer id
    public:
        IndicatorLEDs( LED*const ptrsLEDs_L[], LED*const ptrsLEDs_R[], const uint8_t NORMAL,
                const uint8_t TEN_KEY_OFF, const uint8_t TEN_KEY_ON, const uint8_t MF)
              : ptrsLEDs_L(ptrsLEDs_L), NORMAL(NORMAL),
              TEN_KEY_OFF(TEN_KEY_OFF), TEN_KEY_ON(TEN_KEY_ON), MF(MF)
        {
            //map layer ids to LED roles.  ptrsLayerLEDs is used to turn LED on or off by layer id.
            ptrsLayerLEDs[0] = ptrsLEDs_R[LED_NORMAL];
            ptrsLayerLEDs[1] = ptrsLEDs_R[LED_NAS]; //TEN_KEY_OFF
            ptrsLayerLEDs[2] = ptrsLEDs_R[LED_TEN_KEY_ON];
            ptrsLayerLEDs[3] = ptrsLEDs_R[LED_MF];
            //should be const array, but C++ can not initialize a const array in a class initializer
        }
        void begin();
        void layerLEDsOff(uint8_t activeLayer);
        void updateLayerLEDs(uint8_t activeLayer, bool activeSubMFLayer);
        void updateNumLockLED(bool lazyNumLock);
        void MouseOnLEDUpdate(uint8_t activeSubMFLayer);
        void restoreLEDs(uint8_t activeLayer, bool activeMFSubLayer, bool lazyNumLock);
};
#endif
