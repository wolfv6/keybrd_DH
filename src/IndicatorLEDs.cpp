#include "IndicatorLEDs.h"

IndicatorLEDs::IndicatorLEDs( LED* ptrsLEDs_L[], LED* ptrsLayerLEDs[] )
            : ptrsLEDs_L(ptrsLEDs_L), ptrsLayerLEDs(ptrsLayerLEDs)
{
    //const uint8_t LEDsBlinker::SCANS_PER_BLINK = 62; //NUM_BLINKS * SCANS_PER_BLINK < 256
}

void IndicatorLEDs::startBlinking_L()
{
    //blinker_L.startBlinking();
}

void IndicatorLEDs::startBlinking_R()
{
    //blinker_R.startBlinking();
}
