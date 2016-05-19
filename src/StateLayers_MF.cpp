#include "StateLayers_MF.h"

void StateLayers_MF::setActiveLayer(const uint8_t layer)
{
    activeLayer = layer;
    MouseLEDActivate();
}

void StateLayers_MF::MouseLEDActivate()
{
    if (activeLayer)                            //if arrow on
    {
        refMouseOnLED.off();
    }
    else                                        //if mouse on
    {
        refMouseOnLED.on();
    }
}

void StateLayers_MF::MouseLEDOff()
{
        refMouseOnLED.off();
}
