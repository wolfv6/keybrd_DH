#include "IndicatorLEDs.h"

IndicatorLEDs::IndicatorLEDs( StateLayers_DH& stateLayers_DH,
        LED* ptrsLEDs_L[], LED* ptrsLayerLEDs[] )
            : stateLayers_DH(stateLayers_DH),
            ptrsLEDs_L(ptrsLEDs_L), ptrsLayerLEDs(ptrsLayerLEDs)
{
}

