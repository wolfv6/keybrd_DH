#include "StateStickyMouseButtons.h"

/* trace of isUnstickKey when mouse button is pressed
Row::send()
    Code_StickyMouseButton::press()
        StateStickyMouseButtons::press(scancode)
            StateStickyMouseButtons::releaseStuckButton()
                if (isUnstickKey)   //was set to true in last line
                    Mouse.release(stuckButton);
            Mouse.press(scancode)
            isUnstickKey = false;   //so mouse button doesn't unstick self
    Row_DH::keyWasPressed()
        StateStickyMouseButtons::unstick()
            StateStickyMouseButtons::releaseStuckButton()
                if (isUnstickKey)
                    Mouse.release(stuckButton);
            isUnstickKey = true;    //reset to default - pressing a key unsticks mouse button
*/
void StateStickyMouseButtons::press(uint16_t scancode)
{
    releaseStuckButton();               //pressing another mouse button releases stuck mouse button

    Mouse.press(scancode);

    if (refProtector.getIsPressed())    //if Mouse-Function key is being held down
    {
        stuckButton = scancode;         //stick mouse button
    }

    isUnstickKey = false;               //so that mouse button does not imediatley unstick self
}

void StateStickyMouseButtons::release(uint16_t scancode)
{
    if (stuckButton != scancode)                //if button is not stuck
    {
        Mouse.release(scancode);
    }                                           //if button is stuck, it will be released later
}

void StateStickyMouseButtons::releaseStuckButton()
{
    if (isUnstickKey)
    {
        if (stuckButton != 0)                   //if a mouse button is stuck
        {
            Mouse.release(stuckButton);
            stuckButton = 0;                    //unstick the mouse button
        }
    }
}

//before Row_UnstickMouseButtons calls unstick(),
//a Code has an oportunity to clear the isUnstickKey flag e.g. Code_Mouse_Quick
void StateStickyMouseButtons::doNotUnstick()
{
    isUnstickKey = false;
}

//called from Row_UnstickMouseButtons to unstick mouse button
void StateStickyMouseButtons::unstick()
{
    releaseStuckButton();
    isUnstickKey = true;                //reset to default - pressing a key unsticks mouse button
}
