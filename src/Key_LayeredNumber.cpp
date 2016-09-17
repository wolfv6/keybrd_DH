#include "Key_LayeredNumber.h"

/*
from arduino-1.6.5/hardware/teensy/avr/cores/teensy/keylayouts.h
#define KEY_1           ( 30  | 0x4000 )
#define KEYPAD_1        ( 89  | 0x4000 )
                offset is 59
*/
void Key_LayeredNumber::press()
{
    setScancodeNum();
    Keyboard.press(scancodeNum);
}

void Key_LayeredNumber::release()
{
    Keyboard.release(scancodeNum);
}

void Key_LayeredNumber::setScancodeNum()
{
    numberLayer = refLayerState_DH.getNumberLayer();

    if (numberLayer)
    {
        scancodeNum = scancode + 59;            //KEYPAD
        //scancodeNum = scancode - 26;          //send letters 'a' to 'j' for debugging
    }
    else
    {
        scancodeNum = scancode;                 //KEY
    }
}
