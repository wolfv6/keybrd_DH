#include "StateLayers_DH.h"
#include "IndicatorLEDs.h"  //included here for circular dependency

//set active layer and update LEDs
void StateLayers_DH::setActiveLayer(const uint8_t layer)
{
    refIndicatorLEDs.layerLEDsOff(activeLayer);
    activeLayer = layer;
    refIndicatorLEDs.updateLayerLEDs(activeLayer);
    refIndicatorLEDs.updateLayerSubMFLayerLEDs(activeLayer, activeMFSubLayer);
}

void StateLayers_DH::getLayerStates(uint8_t& refActiveLayer, bool& refLazyNumLock, bool& refActiveMFSubLayer)
{
    refActiveLayer = activeLayer;
    refLazyNumLock = lazyNumLock;
    refActiveMFSubLayer = activeMFSubLayer;
}

// =================== NumLock =================
bool StateLayers_DH::getLazyNumLock()
{
    return lazyNumLock;
}

//update numLock and return active numberLayer: 0 for KEY, 1 for KEYPAD.
//Called from Code_LayeredNumber::setScancodeNum().
bool StateLayers_DH::getNumberLayer()
{
    bool numberLayer;

    if (activeLayer == TEN_KEY_ON)              //in TEN_KEY_ON, lazyNumLock determines numberLayer
    {
        numberLayer = lazyNumLock;
        updateNumLock(NUMLOCK_ON);
    }
    else                                        //in TEN_KEY_OFF, only use numberLayer 0
    {
        numberLayer = 0;
    }

    return numberLayer;
}

//toggle lazyNumLock and update numLock LED
void StateLayers_DH::numLock()
{
    lazyNumLock = !lazyNumLock;                 //toggle
    refIndicatorLEDs.updateNumLockLED(lazyNumLock);
}

//sending KEY_NUM_LOCK is lazy to minimize USB traffic
void StateLayers_DH::updateNumLock(bool numLock)
{
    if ( (keyboard_leds & 1) != numLock)
    {
        Keyboard.press(KEY_NUM_LOCK);
        Keyboard.release(KEY_NUM_LOCK);
    }
}

// ================= MF SubLayer ===============
void StateLayers_DH::lockMFSubLayer(bool sublayer)
{
    activeMFSubLayer = sublayer;
    refIndicatorLEDs.mouseOnLEDUpdate(activeMFSubLayer);
}

bool StateLayers_DH::getActiveMFSubLayer()
{
    return activeMFSubLayer;
}
