#include "IndicatorLEDs.h"
#include "StateLayers_DH.h"  //included here for circular dependency

/* Initialize LEDs.  This should be called once from setup().
*/
void IndicatorLEDs::begin(StateLayers_DH* ptrStateLayers)
{
    for (uint8_t i=0; i<LED_COUNT_PER_ARRAY; i++)
    {
        ptrsLEDs_L[i]->off();
        ptrsLayerLEDs[i]->off();
    }
    ptrsLayerLEDs[0]->on();                     //default layer

    //close circular dependency (circular because restoreBlinkingLEDs() calls StateLayers_DH)
    ptrStateLayers_DH = ptrStateLayers;
}

void IndicatorLEDs::layerLEDsOff(uint8_t activeLayer)
{
    ptrsLayerLEDs[activeLayer]->off();

    if (activeLayer == TEN_KEY_ON )
    {
        ptrsLayerLEDs[TEN_KEY_OFF]->off();
    }
}

void IndicatorLEDs::updateLayerLEDs(uint8_t activeLayer)
{
    ptrsLayerLEDs[activeLayer]->on();

    if (activeLayer == TEN_KEY_ON)
    {
        ptrsLayerLEDs[TEN_KEY_OFF]->on();
    }
}

void IndicatorLEDs::updateLayerSubMFLayerLEDs(uint8_t activeLayer, bool activeMFSubLayer)
{
    if (activeLayer == MF)
    {
        mouseOnLEDUpdate(activeMFSubLayer);
    }
    else
    {
        ptrsLEDs_L[LED_MOUSE_ON]->off();
    }
}

void IndicatorLEDs::mouseOnLEDUpdate(uint8_t activeMFSubLayer)
{
    if (activeMFSubLayer)                       //if arrow on
    {
        ptrsLEDs_L[LED_MOUSE_ON]->off();
    }
    else                                        //if mouse on
    {
        ptrsLEDs_L[LED_MOUSE_ON]->on();
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

// ================== blinker ==================
/* How blinker works:
blink() is called from sketch loop().
blink() does nothing as long as scansSinceFirstBlink is 0.
startBlinking() sets scansSinceFirstBlink to SCANS_BLINK_ON.
Then blink() increments scansSinceFirstBlink on every loop().
At predetermined values of scansSinceFirstBlink, LEDs are turned on or off.
At end of the blink cycle, scansSinceFirstBlink is set to 0, and the LEDs' states are restored.
*/
void IndicatorLEDs::startBlinking(LED*const ptrsLEDs[])
{
    if (scansSinceFirstBlink > 0)               //if previous blinking not done yet
    {
        restoreBlinkingLEDs();
    }

    ptrsBlinkingLEDs = ptrsLEDs;
    scansSinceFirstBlink = SCANS_BLINK_ON;      //start blinking
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
            //turn LEDs off (DataHand dims LEDs that where on)
            ptrsBlinkingLEDs[0]->off();
            ptrsBlinkingLEDs[1]->off();
            ptrsBlinkingLEDs[2]->off();

            if (scansSinceFirstBlink == (uint16_t)NUM_BLINKS * SCANS_PER_BLINK)
            {
                scansSinceFirstBlink = 0;       //stop blinking
                restoreBlinkingLEDs();
                return;
            }
        }
        scansSinceFirstBlink++;
    }
}

/* Restore state of first 3 LEDs.
*/
void IndicatorLEDs::restoreBlinkingLEDs()
{
    uint8_t activeLayer;

    if (ptrsBlinkingLEDs == ptrsLEDs_L)         //if left unit blinking
    {
        bool activeMFSubLayer;
        bool lazyNumLock;
        ptrStateLayers_DH->getLayerStates(activeLayer, activeMFSubLayer, lazyNumLock);

        //updateScrollLockLED();  LED_SCROLL_LOCK was removed, explanation in Code_LEDLock.cpp
        updateLayerSubMFLayerLEDs(activeLayer, activeMFSubLayer); //LED_MOUSE_ON
        updateNumLockLED(lazyNumLock);                            //LED_NUM_LOCK
    }
    else                                        //if right unit blinking
    {
        activeLayer = ptrStateLayers_DH->getActiveLayer();
        updateLayerLEDs(activeLayer);
    }
}
