#include "Row_DH.h"

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
