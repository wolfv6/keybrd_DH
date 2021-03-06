#ifndef INDICATORLEDS_H
#define INDICATORLEDS_H

#include <Arduino.h>
#include <inttypes.h>
#include <LEDInterface.h>

/* IndicatorLEDs
ptrsLEDs_L[] and ptrsLEDs_R[] arrays contain indicator LEDs in the order of appearance on keyboard.

begin() should be called once in setup().
*/
#define LED_COUNT_PER_ARRAY 4

class LayerState_DH;

class IndicatorLEDs
{
    private:
        //Enumerators are LED-role assignments, used as ptrsLEDs_L and ptrsLEDs_R array indexes.
        //Enumerator roles are in the order of corresponding LEDs as they appear on the keyboard.
        enum LED_ROLES_L { LED_SCROLL_LOCK, LED_NUM_LOCK, LED_MOUSE_ON, LED_CAPS_LOCK };
        enum LED_ROLES_R { LED_NAS, LED_NORMAL, LED_MF, LED_TEN_KEY_ON };
        LayerState_DH* ptrLayerState_DH;
        LEDInterface*const *const ptrsLEDs_L;   //pointer to left-indicator LEDs pointer array
        // ordered by appearance on keyboard
        const uint8_t TEN_KEY_OFF;              //layerId
        const uint8_t TEN_KEY_ON;               //layerId
        const uint8_t MF;                       //layerId
        LEDInterface* ptrsLayerLEDs[LED_COUNT_PER_ARRAY];//pointer to right-indicator LEDs ptr array
        //ordered by layerId
        // ============ blinker ================
        LEDInterface*const * ptrsBlinkingLEDs;  //array of pointers to blinking indicator LEDs
        static LayerState_DH& refLayerState_DH;
        static const uint8_t NUM_BLINKS;        //number of blinks to stop
        static const uint8_t SCANS_PER_BLINK;   //smaller number makes blinking faster
        static const uint8_t SCANS_BLINK_ON;    //number of scans per blink that LED is on
        uint16_t scansSinceFirstBlink;          //magic number 0 means not blinking
    public:
        IndicatorLEDs(LEDInterface*const ptrsLEDs_L[], LEDInterface*const ptrsLEDs_R[],
                      const uint8_t TEN_KEY_OFF, const uint8_t TEN_KEY_ON, const uint8_t MF)
            : ptrsLEDs_L(ptrsLEDs_L),
              TEN_KEY_OFF(TEN_KEY_OFF), TEN_KEY_ON(TEN_KEY_ON), MF(MF)
        {
            //map layerIds to LED roles.  ptrsLayerLEDs is used to turn LED on or off by layerId.
            ptrsLayerLEDs[0] = ptrsLEDs_R[LED_NORMAL];
            ptrsLayerLEDs[1] = ptrsLEDs_R[LED_NAS]; //TEN_KEY_OFF
            ptrsLayerLEDs[2] = ptrsLEDs_R[LED_TEN_KEY_ON];
            ptrsLayerLEDs[3] = ptrsLEDs_R[LED_MF];
            //should be const array, but C++ can not initialize a const array in a class initializer
        }
        void begin(LayerState_DH* ptrLayerState_DH);
        void layerLEDsOff(uint8_t activeLayer);
        void updateLayerLEDs(uint8_t activeLayer);
        void updateLayerSubMFLayerLEDs(uint8_t activeLayer, bool activeMFSubLayer);
        void mouseOnLEDUpdate(uint8_t activeMFSubLayer);
        void updateNumLockLED(bool lazyNumLock);

        // ============ blinker ================
        void startBlinking(LEDInterface*const pLEDs[]);
        void blink();
        void restoreBlinkingLEDs();
};
#endif
