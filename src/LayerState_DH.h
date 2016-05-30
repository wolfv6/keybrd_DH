#ifndef LAYERSTATE_DH_H
#define LAYERSTATE_DH_H

#include <Arduino.h>
#include <inttypes.h>
#include <LayerState.h>

extern volatile uint8_t keyboard_leds;

class IndicatorLEDs;

/* LayerState for DH layers: NORMAL, TEN_KEY_ON, TEN_KEY_OFF, MF
LayerState is part of a layer scheme explained in keybrd_DH/doc/keybrd_DH_library_developer_guide.md
*/
class LayerState_DH : public LayerState
{
    private:
        const uint8_t TEN_KEY_ON;
        IndicatorLEDs& refIndicatorLEDs;
        bool lazyNumLock;
        bool activeMFSubLayer;
        virtual void setActiveLayer(const uint8_t layer);
    public:
        LayerState_DH(
                const uint8_t TEN_KEY_ON,
                IndicatorLEDs& refIndicatorLEDs)
            : TEN_KEY_ON(TEN_KEY_ON),
                refIndicatorLEDs(refIndicatorLEDs),
                lazyNumLock(NUMLOCK_OFF) {}
        void getLayerStates(uint8_t& refActiveLayer, bool& refActiveMFSubLayer, bool& refLazyNumLock);

        // ============= NumLock ===============
        enum numLock { NUMLOCK_OFF, NUMLOCK_ON };
        bool getLazyNumLock();
        bool getNumberLayer();
        void toggleLazyNumLock();
        void updateNumLock(bool numLock);

        // =========== MF SubLayer =============
        void lockMFSubLayer(bool subLayer);
        bool getActiveMFSubLayer();
};
#endif
