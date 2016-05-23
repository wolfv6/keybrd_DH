#include "StateLayers_MF.h"

void StateLayers_MF::setActiveLayer(const uint8_t layer)
{
    activeLayer = layer;
    refIndicatorLEDs.MouseLEDOn(activeLayer);
}

