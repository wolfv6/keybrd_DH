#include "IndicatorLEDs.h"

IndicatorLEDs::IndicatorLEDs( StateLayers_DH& stateLayers_DH,
        LED* ptrsLEDs_L[], LED* ptrsLayerLEDs[] )
            : stateLayers_DH(stateLayers_DH),
            ptrsLEDs_L(ptrsLEDs_L), ptrsLayerLEDs(ptrsLayerLEDs),
            blinker_L(ptrsLEDs_L), blinker_R(ptrsLayerLEDs)
{
}

void IndicatorLEDs::startBlinking_L()
{
    blinker_L.startBlinking();
}

void IndicatorLEDs::startBlinking_R()
{
    blinker_R.startBlinking();
}
void IndicatorLEDs::blink()
{
    blinker_L.blink();
    blinker_R.blink();
}

void IndicatorLEDs::restoreLEDs()
{
    //updateLayerLEDs();
    //updateNumLockLED();
    //scrollLock.updateLED(); Scroll lock LED removed, explanation in Code_LEDLock.cpp
}

