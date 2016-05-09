#include "Code_Mouse_Quick.h"

void Code_Mouse_Quick::press()
{
    speedByte |= speedBit;                      //set speedBit bit
    refMouseButtons.doNotUnstick();
}
