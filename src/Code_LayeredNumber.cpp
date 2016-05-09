#include "Code_LayeredNumber.h"

/*
from arduino-1.6.5/hardware/teensy/avr/cores/teensy/keylayouts.h
#define KEY_1           ( 30  | 0x4000 )
#define KEYPAD_1        ( 89  | 0x4000 )
                offset is 59
*/
void Code_LayeredNumber::press()
{
    setScancodeNum();
    Keyboard.press(scancodeNum);
}

void Code_LayeredNumber::release()
{
    Keyboard.release(scancodeNum);
}

void Code_LayeredNumber::setScancodeNum()
{
    layer = refStateLayers.getNumberLayer();

    if (layer)
    {
        scancodeNum = scancode + 59;            //KEYPAD
    }
    else
    {
        scancodeNum = scancode;                 //KEY
    }
}
