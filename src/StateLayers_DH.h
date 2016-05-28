#ifndef LAYERSTATE_DH_H
#define LAYERSTATE_DH_H

#include <Arduino.h>
#include <inttypes.h>
#include <StateLayers.h>

extern volatile uint8_t keyboard_leds;

class IndicatorLEDs;

/* StateLayers for DH layers: NORMAL, TEN_KEY_ON, TEN_KEY_OFF, MF
StateLayers is part of a layer scheme explained in keybrd_DH/doc/keybrd_DH_library_developer_guide.md
*/
class StateLayers_DH : public StateLayers
{
    private:
        const uint8_t TEN_KEY_ON;
        IndicatorLEDs& refIndicatorLEDs;
        bool lazyNumLock;                       //toggled by numLock key
        bool activeMFSubLayer;
        virtual void setActiveLayer(const uint8_t layer);
    public:
        StateLayers_DH(
                const uint8_t TEN_KEY_ON,
                IndicatorLEDs& refIndicatorLEDs)
            : TEN_KEY_ON(TEN_KEY_ON),
                refIndicatorLEDs(refIndicatorLEDs),
                lazyNumLock(NUMLOCK_OFF) {}
        void getLayerStates(uint8_t& refActiveLayer, bool& refLazyNumLock, bool& refActiveMFSubLayer);

        // ============= NumLock ===============
        enum numLock { NUMLOCK_OFF, NUMLOCK_ON };
        bool getLazyNumLock();
        bool getNumberLayer();
        void numLock();
        void updateNumLock(bool numLock);

        // =========== MF SubLayer =============
        void lockMFSubLayer(bool subLayer);
        bool getActiveMFSubLayer();
};
#endif
