#include "StateLayers_DH.h"

void StateLayers_DH::setActiveLayer(const uint8_t layer)
{
    refIndicatorLEDs.LEDsOff(activeLayer);
    activeLayer = layer;
    refIndicatorLEDs.LEDsOn(activeLayer);
}

bool StateLayers_DH::getLazyNumLock()
{
    return lazyNumLock;
}

//update numLock and return layer for Code_LayeredNumber
bool StateLayers_DH::getNumberLayer()
{
    bool layer;

    if (activeLayer == TEN_KEY_ON)              //in TEN_KEY_ON, lazyNumLock determines layer
    {
        layer = lazyNumLock;
        updateNumLock(NUMLOCK_ON);
    }
    else                                        //in TEN_KEY_OFF, only use layer 0
    {
        layer = 0;
    }

    return layer;
}

//toggle lazyNumLock
void StateLayers_DH::numLock()
{
    lazyNumLock = !lazyNumLock;                 //toggle
    refIndicatorLEDs.updateNumLockLED(lazyNumLock);
}

//sending KEY_NUM_LOCK is lazy to minimize USB traffic
//updateNumLock() is called in the above getter functions when NUMLOCK_OFF or NUMLOCK_ON is needed
void StateLayers_DH::updateNumLock(bool numLock)
{
    if ( (keyboard_leds & 1) != numLock)
    {
        Keyboard.press(KEY_NUM_LOCK);
        Keyboard.release(KEY_NUM_LOCK);
    }
}

void StateLayers_DH::restoreLEDs()
{
    refIndicatorLEDs.updateLayerLEDs(activeLayer);
    refIndicatorLEDs.updateNumLockLED(lazyNumLock);
    //scrollLock.updateLED(); Scroll lock LED removed, explanation in Code_LEDLock.cpp
}
