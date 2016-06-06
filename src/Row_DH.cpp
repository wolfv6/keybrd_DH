#include "Row_DH.h"

/*
process() scans the row and calls any newly pressed or released keys.
*/
void Row_DH::process()
{
    //these variables are all bitwise, one bit per key
    uint8_t rowState;                           //1 means pressed, 0 means released
    uint16_t rowEnd;                            //1 bit marks positioned after last key of row
    uint8_t debouncedChanged;                   //1 means debounced changed

    wait();
    rowState = scanner.scan(rowEnd);
    debouncedChanged = debouncer.debounce(rowState, debounced);
    pressRelease(rowEnd, debouncedChanged);
}

/* Sticky mouse buttons, Ctrl, and Alt keys are effected by other key presses.
Call these objects on every key press.
*/
void Row_DH::keyWasPressed()
{
    refMouseButtons.unstick();
    refCtrl.prevent_toggle();
    refAlt.prevent_toggle();
}
