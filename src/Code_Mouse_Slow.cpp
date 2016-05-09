#include "Code_Mouse_Slow.h"

/* 0 speed before START_NUDGE in Code_MouseSpeed::magnitude() and Mouse.move(x,y,0) below
 are experimental.  They may be removed later.
*/
void Code_Mouse_Slow::press()
{
    if (speedByte == 0)                         //if no other Code_MouseSpeed is pressed
    {
        Mouse.move(x,y,0);                      //initial pointer movement
        sinceSlowPressed = 0;                   //reset sinceSlowPressed
    }
    //if another Code_MouseSpeed is pressed, do not reset sincePress

    speedByte |= speedBit;                      //set this bit of speedByte
    refMouseButtons.doNotUnstick();
}
