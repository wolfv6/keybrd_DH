#ifndef LAYERSTATE_DH_H
#define LAYERSTATE_DH_H

#include <Arduino.h>
#include <inttypes.h>
#include <StateLayers.h>
#include <LED.h>
#include <LED_AVR.h>
#include "IndicatorLEDs.h"

extern volatile uint8_t keyboard_leds;

/* StateLayers for DH layers: NORMAL, TEN_KEY_ON, TEN_KEY_OFF, MF
StateLayers is part of a layer scheme explained in keybrd_DH/doc/keybrd_DH_library_developer_guide.md
*/
class StateLayers_DH : public StateLayers
{
    private:
        const uint8_t TEN_KEY_ON;
        IndicatorLEDs& refIndicatorLEDs;
        LED* *const ptrsLayerLEDs;              //array of pointers to layer indicator lights
        LED_AVR& refLED_numLock;
        bool lazyNumLock;                       //toggled by numLock key
        virtual void setActiveLayer(const uint8_t layer);
    public:
        StateLayers_DH(
                const uint8_t TEN_KEY_ON,
                IndicatorLEDs& refIndicatorLEDs,
                LED* ptrsLayerLEDs[], LED_AVR& refLED_numLock)
            : TEN_KEY_ON(TEN_KEY_ON),
                refIndicatorLEDs(refIndicatorLEDs),
                ptrsLayerLEDs(ptrsLayerLEDs), refLED_numLock(refLED_numLock),
                lazyNumLock(NUMLOCK_OFF) {}
        enum numLock { NUMLOCK_OFF, NUMLOCK_ON };
        bool getLazyNumLock();
        bool getNumberLayer();
        void numLock();
        void updateNumLock(bool numLock);
        void restoreLEDs();
};
#endif
