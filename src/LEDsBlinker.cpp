#include "LEDsBlinker.h"

void LEDsBlinker::startBlinking()
{
    scansSinceFirstBlink = 1;
}

void LEDsBlinker::blink()
{
    if (scansSinceFirstBlink > 0)
    {
        if ( (scansSinceFirstBlink + SCANS_PER_BLINK/2) % (SCANS_PER_BLINK) == 0 )
        {
            LED0.on();
            LED1.on();
            LED2.on();
        }
        else if ( scansSinceFirstBlink % (SCANS_PER_BLINK) == 0 )
        {
            LED0.off();
            LED1.off();
            LED2.off();

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
