#include "Key_LayeredNumber_00.h"

void Key_LayeredNumber_00::press()
{
    setScancodeNum();
    Keyboard.press(scancodeNum);
    Keyboard.release(scancodeNum);
    Keyboard.press(scancodeNum);
}
