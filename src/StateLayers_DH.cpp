#include "StateLayers_DH.h"

//set active layer and update LEDs
void StateLayers_DH::setActiveLayer(const uint8_t layer)
{
    refIndicatorLEDs.layerLEDsOff(activeLayer);
    activeLayer = layer;
    refIndicatorLEDs.updateLayerLEDs(activeLayer, activeMFSubLayer);
}

bool StateLayers_DH::getLazyNumLock()
{
    return lazyNumLock;
}

//update numLock and return active numberLayer
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

void StateLayers_DH::lockMFSubLayer(bool sublayer)
{
    activeMFSubLayer = sublayer;
    refIndicatorLEDs.MouseOnLEDUpdate(activeMFSubLayer);
}

bool StateLayers_DH::getActiveMFSubLayer()
{
    return activeMFSubLayer;
}

/* Restore first 3 LEDs.  restoreLEDs() is called when LEDsBlinker is done blinking.
restoreLEDs() function is in StateLayers_DH because activeLayer and lazyNumLock values are needed by IndicatorLEDs.
And if IndicatorLEDs called StateLayers_DH.getActiveLayer(), it would create a circular dependency.
*/
void StateLayers_DH::restoreLEDs()
{
    //todo, move this function's logic to refIndicatorLEDs.restoreLEDs(activeLayer, lazyNumLock);

    refIndicatorLEDs.updateLayerLEDs(activeLayer, activeMFSubLayer);
    refIndicatorLEDs.updateNumLockLED(lazyNumLock);
    //scrollLock.updateLED(); Scroll lock LED removed, explanation in Code_LEDLock.cpp
}
