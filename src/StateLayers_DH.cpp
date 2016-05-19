#include "StateLayers_DH.h"

void StateLayers_DH::setActiveLayer(const uint8_t layer)
{
    //turn off LEDs
    ptrsLayerLEDs[activeLayer]->off();

    if (activeLayer == TEN_KEY_ON)
    {
        ptrsLayerLEDs[TEN_KEY_OFF]->off();
    }

    //udate activeLayer
    activeLayer = layer;

    //turn on LEDs
    ptrsLayerLEDs[activeLayer]->on();

    if (activeLayer == TEN_KEY_ON)
    {
        ptrsLayerLEDs[TEN_KEY_OFF]->on();
    }

    //update MF mouse LED
    if (layer == MF)
    {
        refStateLayers_MF.MouseLEDActivate();
    }
    else
    {
        refStateLayers_MF.MouseLEDOff();
    }
}

//update numLock and return layer for Code_LayeredNav
bool StateLayers_DH::getNavLayer()
{
    bool layer = refStateLRModf.getActiveLayer(); //LRModf determines layer

    if (layer == 1) //only layer 1 is numLock sensitive, don't bother updating numLock for layer 0
    {
        updateNumLock(NUMLOCK_OFF);
    }

    return layer;
}

//update numLock and return layer for Code_LayeredOperator
bool StateLayers_DH::getOperatorLayer()
{
    bool layer;

    if (activeLayer == TEN_KEY_ON)              //in TEN_KEY_ON, lazyNumLock determines layer
    {
        layer = lazyNumLock;
    }
    else                                        //in TEN_KEY_OFF, LRModf determines layer
    {
        layer = refStateLRModf.getActiveLayer();
    }

    if (layer == 1) //only layer 1 is numLock sensitive, don't bother updating numLock for layer 0
    {
        updateNumLock(NUMLOCK_OFF);
    }

    return layer;
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

    //if ( (activeLayer != NORMAL) && (lazyNumLock == 1) ) //NumLock has no function on NORMAL layer
    if (lazyNumLock == 1)
    {
        ptrsLayerLEDs[4]->on();
        //todo move NUM_LOCK LED to const variable? see if free SRAM changes
    }
    else
    {
        ptrsLayerLEDs[4]->off();
    }
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
