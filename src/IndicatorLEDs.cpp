#include "IndicatorLEDs.h"

void IndicatorLEDs::LEDsOff(uint8_t activeLayer)
{
    ptrsLayerLEDs[activeLayer]->off();

    if (activeLayer == 2)//TEN_KEY_ON todo
    {
        ptrsLayerLEDs[1]->off();//TEN_KEY_OFF todo
    }
}

void IndicatorLEDs::LEDsOn(uint8_t activeLayer)
{
    ptrsLayerLEDs[activeLayer]->on();
    updateLayerLEDs(activeLayer);
}

void IndicatorLEDs::updateLayerLEDs(uint8_t activeLayer)
{
    ptrsLayerLEDs[activeLayer]->on();

    if (activeLayer == TEN_KEY_ON)
    {
        ptrsLayerLEDs[TEN_KEY_OFF]->on();
    }

    if (activeLayer == MF)
    {
        MouseLEDOn(activeLayer );
    }
    else
    {
        MouseLEDOff();
    }
}

void IndicatorLEDs::updateNumLockLED(uint8_t lazyNumLock)
{
    if (lazyNumLock == 1)//NUMLOCK_ON todo consider global layer and sublayer numbers
    {
        ptrsLEDs_L[2]->on();
    }
    else
    {
        ptrsLEDs_L[2]->off();
    }
}

void IndicatorLEDs::MouseLEDOn(uint8_t activeLayer)
{
    if (activeLayer)                            //if arrow on
    {
        ptrsLEDs_L[3]->off();
    }
    else                                        //if mouse on
    {
        ptrsLEDs_L[3]->on();
    }
}

void IndicatorLEDs::MouseLEDOff()
{
        ptrsLEDs_L[3]->off();
}

