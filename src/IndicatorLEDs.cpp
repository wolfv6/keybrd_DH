#include "IndicatorLEDs.h"

/* called from StateLayers_DH
*/
void IndicatorLEDs::layerLEDsOff(uint8_t activeLayer)
{
    ptrsLayerLEDs[activeLayer]->off();

    if (activeLayer == TEN_KEY_ON )
    {
        ptrsLayerLEDs[TEN_KEY_OFF]->off();
    }
}

/* called from StateLayers_DH
*/
void IndicatorLEDs::updateLayerLEDs(uint8_t activeLayer, bool activeSubMFLayer)
{
    ptrsLayerLEDs[activeLayer]->on();

    if (activeLayer == TEN_KEY_ON)
    {
        ptrsLayerLEDs[TEN_KEY_OFF]->on();
    }

    if (activeLayer == MF)
    {
        MouseOnLEDUpdate(activeSubMFLayer);
    }
    else
    {
        ptrsLEDs_L[LED_MOUSE_ON]->off();
    }
}

/* called from StateLayers_DH
*/
void IndicatorLEDs::updateNumLockLED(bool lazyNumLock)
{
    if (lazyNumLock == 1)
    {
        ptrsLEDs_L[LED_NUM_LOCK]->on();
    }
    else
    {
        ptrsLEDs_L[LED_NUM_LOCK]->off();
    }
}

/*
also called from StateLayers_MF
*/
void IndicatorLEDs::MouseOnLEDUpdate(uint8_t activeSubMFLayer)
{
    if (activeSubMFLayer)                       //if arrow on
    {
        ptrsLEDs_L[LED_MOUSE_ON]->off();
    }
    else                                        //if mouse on
    {
        ptrsLEDs_L[LED_MOUSE_ON]->on();
    }
}
