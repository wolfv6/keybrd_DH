#ifndef LAYERSTATE_DH_H
#define LAYERSTATE_DH_H

#include <Arduino.h>
#include <inttypes.h>
#include <StateLayers.h>
#include "Code_LayerState_Toggle.h"
//#include "LED.h"

extern volatile uint8_t keyboard_leds;

/* StateLayers for DH layers: NORMAL, TEN_KEY_ON, TEN_KEY_OFF, MF
*/
class StateLayers_DH : public StateLayers
{
    private:
        enum numLock { NUMLOCK_OFF, NUMLOCK_ON };
        Code_LayerState_Toggle& refStateLRModf;
        bool lazyNumLock;                       //toggled by numLock key
        const uint8_t TEN_KEY_ON;
        virtual void setActiveLayer(const uint8_t layer);
    public:
        StateLayers_DH(Code_LayerState_Toggle& refStateLRModf, const uint8_t TEN_KEY_ON)
            : refStateLRModf(refStateLRModf), lazyNumLock(NUMLOCK_OFF), TEN_KEY_ON(TEN_KEY_ON) {}
        bool getNavLayer();
        bool getOperatorLayer();
        bool getNumberLayer();
        void numLock();
        void updateNumLock(bool numLock);
};
#endif
