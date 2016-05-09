#include "Code_LayeredNumber_00.h"

void Code_LayeredNumber_00::press()
{
    setScancodeNum();
    Keyboard.press(scancodeNum);
    Keyboard.release(scancodeNum);
    Keyboard.press(scancodeNum);
}
