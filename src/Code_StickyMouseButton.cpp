#include "Code_StickyMouseButton.h"

void Code_StickyMouseButton::press()
{
    refMouseButtons.press(scancode);
}

void Code_StickyMouseButton::release()
{
    refMouseButtons.release(scancode);
}
