#include "IndicatorLEDs.h"
#include "StateLayers_DH.h"  //included here for circular dependency

/* Initialize LEDs.  This should be called once from setup().
*/
void IndicatorLEDs::begin(StateLayers_DH* ptrStateLayers_DH)
{
    for (uint8_t i=0; i<LED_COUNT_PER_ARRAY; i++)
    {
        ptrsLEDs_L[i]->off();
        ptrsLayerLEDs[i]->off();
    }
    ptrsLayerLEDs[0]->on();                     //default layer
}

void IndicatorLEDs::layerLEDsOff(uint8_t activeLayer)
{
    ptrsLayerLEDs[activeLayer]->off();

    if (activeLayer == TEN_KEY_ON )
    {
        ptrsLayerLEDs[TEN_KEY_OFF]->off();
    }
}

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

void IndicatorLEDs::startBlinking(LED*const ptrsLEDs[])
{
    if (scansSinceFirstBlink > 0)               //if previous blinking not done yet
    {
        //todo restore
    }

    ptrsBlinkingLEDs = ptrsLEDs;
    scansSinceFirstBlink = SCANS_BLINK_ON;
}

void IndicatorLEDs::blink()
{
    if (scansSinceFirstBlink > 0)               //continue blinking
    {
        if ( (scansSinceFirstBlink + SCANS_BLINK_ON) % (SCANS_PER_BLINK) == 0 )
        {
            ptrsBlinkingLEDs[0]->on();
            ptrsBlinkingLEDs[1]->on();
            ptrsBlinkingLEDs[2]->on();
        }
        else if ( scansSinceFirstBlink % (SCANS_PER_BLINK) == 0 )
        {
            ptrsBlinkingLEDs[0]->off();
            ptrsBlinkingLEDs[1]->off();
            ptrsBlinkingLEDs[2]->off();
            //todo restore dim L or R?

            if (scansSinceFirstBlink == NUM_BLINKS * SCANS_PER_BLINK)
            {
                scansSinceFirstBlink = 0;       //stop blinking
                //todo restore bright L or R?
                //refStateLayers_DH.restoreLEDs();
                return;
            }
        }
        scansSinceFirstBlink++;
    }
}

/* Restore first 3 LEDs.  restoreLEDs() is called when LEDsBlinker is done blinking.
*/
void IndicatorLEDs::restoreLEDs(uint8_t activeLayer, bool activeMFSubLayer, bool lazyNumLock)
{
    updateLayerLEDs(activeLayer, activeMFSubLayer);
    updateNumLockLED(lazyNumLock);
    //scrollLock.updateLED(); Scroll lock LED removed, explanation in Code_LEDLock.cpp
}
