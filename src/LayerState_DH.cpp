#include "LayerState_DH.h"
#include "IndicatorLEDs.h"  //included here for circular dependency

//set active layer and update LEDs
void LayerState_DH::setActiveLayer(const uint8_t layer)
{
    refIndicatorLEDs.layerLEDsOff(activeLayer);
    activeLayer = layer;
    refIndicatorLEDs.updateLayerLEDs(activeLayer);
    refIndicatorLEDs.updateLayerSubMFLayerLEDs(activeLayer, activeMFSubLayer);
}

void LayerState_DH::getLayerStates(uint8_t& refActiveLayer, bool& refActiveMFSubLayer,
                                   bool& refLazyNumLock)
{
    refActiveLayer = activeLayer;
    refLazyNumLock = lazyNumLock;
    refActiveMFSubLayer = activeMFSubLayer;
}

// =================== NumLock =================
bool LayerState_DH::getLazyNumLock()
{
    return lazyNumLock;
}

//update numLock and return active numberLayer: 0 for KEY, 1 for KEYPAD.
//Called from Code_LayeredNumber::setScancodeNum().
bool LayerState_DH::getNumberLayer()
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
void LayerState_DH::toggleLazyNumLock()
{
    lazyNumLock = !lazyNumLock;                 //toggle
    refIndicatorLEDs.updateNumLockLED(lazyNumLock);
}

//sending KEY_NUM_LOCK is lazy to minimize USB traffic
void LayerState_DH::updateNumLock(bool numLock)
{
    if ( (keyboard_leds & 1) != numLock)
    {
        Keyboard.press(KEY_NUM_LOCK);
        Keyboard.release(KEY_NUM_LOCK);
    }
}

// ================= MF SubLayer ===============
void LayerState_DH::lockMFSubLayer(bool sublayer)
{
    activeMFSubLayer = sublayer;
    refIndicatorLEDs.mouseOnLEDUpdate(activeMFSubLayer);
}

bool LayerState_DH::getActiveMFSubLayer()
{
    return activeMFSubLayer;
}
