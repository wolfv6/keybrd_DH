#include "Row_DH.h"

/*
process() scans the row and calls any newly pressed or released keys.
*/
void Row_DH::process(const bool activeHigh)
{
    //these variables are all bitwise, one bit per key
    uint8_t rowState;                           //1 means pressed, 0 means released
    uint16_t rowEnd;                            //1 bit marks positioned after last key of row
    uint8_t debouncedChanged;                   //1 means debounced changed

    wait();
    scan(activeHigh);                           //save column-port-pin values to portState
    rowState = getRowState(rowEnd, activeHigh);
    debouncedChanged = debounce(rowState);
    pressRelease(rowEnd, debouncedChanged);
}

/* debounce() sets debounced and returns debouncedChanged.  All variables are bitwise.
For parameter, 1 means pressed, 0 means released.
For return, 1 means debounced changed.
*/
uint8_t Row_DH::debounce(const uint8_t rowState)
{
    return debouncer.debounce(rowState, debounced);
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
