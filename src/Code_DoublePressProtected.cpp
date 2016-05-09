#include "Code_DoublePressProtected.h"

void Code_DoublePressProtected::press()
{
    if ( (sinceFirstPress < DOUBLE_PRESS_MILLIS) && (!doublePressed) ) //if second press
    {
        refCode.press();
        doublePressed = true;
    }
    else                                        //if first or third press
    {
        sinceFirstPress = 0;
        doublePressed = false;
    }
}

void Code_DoublePressProtected::release()
{
    if (doublePressed)
    {
        refCode.release();
    }
}
