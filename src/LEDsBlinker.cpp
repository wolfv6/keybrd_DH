#include "LEDsBlinker.h"

/* How LEDsBlinker works:
blink() is called from sketch loop().
blink() does nothing as long as scansSinceFirstBlink is 0.
startBlinking() sets scansSinceFirstBlink to 1.
Then blink() increments scansSinceFirstBlink on every loop(), and blinks.
At end of the blink cycle, scansSinceFirstBlink is set to 0, and the LEDs' states are restored.

LEDsBlinker functions are not in IndicatorLEDs class because
calling refStateLayers_DH.restoreLEDs() from IndicatorLEDs would create a circular dependency.
*/
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
                refStateLayers_DH.restoreLEDs();
                return;
            }
        }
        scansSinceFirstBlink++;
    }
}
