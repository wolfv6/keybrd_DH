#include "LEDsBlinker.h"

void LEDsBlinker::startBlinking()
{
    scansSinceFirstBlink = 1;
}

void LEDsBlinker::blink()
{
    if (scansSinceFirstBlink > 0)               //continue blinking
    {
        if ( (scansSinceFirstBlink + SCANS_PER_BLINK/2) % (SCANS_PER_BLINK) == 0 )
        {
            ptrsLEDs[0]->on();
            ptrsLEDs[1]->on();
            ptrsLEDs[2]->on();
        }
        else if ( scansSinceFirstBlink % (SCANS_PER_BLINK) == 0 )
        {
            ptrsLEDs[0]->off();
            ptrsLEDs[1]->off();
            ptrsLEDs[2]->off();

            if (scansSinceFirstBlink == NUM_BLINKS * SCANS_PER_BLINK)
            {
                scansSinceFirstBlink = 0;       //stop blinking
                refStateLayers.restoreLEDs();
                return;
            }
        }
        scansSinceFirstBlink++;
    }
}
