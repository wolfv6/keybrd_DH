#include "Code_Protected.h"

void Code_Protected::protectedPress(bool protectorIsPressed)
{
    if (protectorIsPressed)                     //the protection
    {
        refCode.press();
        protectorWasPressed = true;
    }
    else
    {
        protectorWasPressed = false;
    }
}

void Code_Protected::release()
{
    if (protectorWasPressed)
    {
        refCode.release();
    }
}
