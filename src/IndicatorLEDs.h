#ifndef INDICATORLEDS_H
#define INDICATORLEDS_H

#include <Arduino.h>
#include <inttypes.h>
#include <LED.h>

/* IndicatorLEDs
ptrsLEDs_L[] and ptrsLEDs_R[] arrays contain indicator LEDs in the order of appearance on keyboard.
*/
class IndicatorLEDs
{
    private:
        //Enumerators are LED role assignments, used as ptrsLEDs_L and ptrsLEDs_R array indexes.
        //Enumerator roles are in the order of corresponding LEDs as they appear on the keyboard.
        enum LED_ROLES_L { LED_SCROLL_LOCK, LED_NUM_LOCK, LED_MOUSE_ON, LED_CAPS_LOCK };
        enum LED_ROLES_R { LED_NAS, LED_NORMAL, LED_MF, LED_TEN_KEY_ON };
        LED*const *const ptrsLEDs_L;            //array of pointers to indicator LEDs on left unit
        const uint8_t TEN_KEY_ON;               //layer id
        const uint8_t TEN_KEY_OFF;              //layer id
        const uint8_t MF;                       //layer id
        LED* *ptrsLayerLEDs;                    //array of pointers to indicator LEDs on right unit,
                                                //ordered by layer number
    public:
        IndicatorLEDs( LED*const ptrsLEDs_L[], LED* ptrsLEDs_R[],
                const uint8_t TEN_KEY_ON, const uint8_t TEN_KEY_OFF, const uint8_t MF)
              : ptrsLEDs_L(ptrsLEDs_L), TEN_KEY_ON(TEN_KEY_ON), TEN_KEY_OFF(TEN_KEY_OFF), MF(MF)
        {
            //map layer ids to LED roles
            ptrsLayerLEDs[0] = ptrsLEDs_R[LED_NORMAL];
            ptrsLayerLEDs[1] = ptrsLEDs_R[LED_NAS]; //TEN_KEY_OFF
            ptrsLayerLEDs[2] = ptrsLEDs_R[LED_TEN_KEY_ON];
            ptrsLayerLEDs[3] = ptrsLEDs_R[LED_MF];
            //should be const array, but C++ can not initialize a const array in a class initializer
        }
        void layerLEDsOff(uint8_t activeLayer);
        void updateLayerLEDs(uint8_t activeLayer);
        void updateNumLockLED(uint8_t lazyNumLock);
        void MouseOnLEDUpdate(uint8_t activeLayer);
};
#endif
