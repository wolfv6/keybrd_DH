#include "Row_DH.h"

/*
optic switches on DodoHand do not bounce, so debouncer() simply uses rowState without debouncing.
For some mechanical switches, poling I2C is slow enough to not need a debouncer.
*/
uint8_t Row_DH::debounce(const uint8_t rowState)
{
    uint8_t debounced;                          //bitwise, 1 means pressed, 0 means released
    uint8_t debouncedChanged;                   //bitwise, 1 means debounced changed

    debounced = rowState;
    debouncedChanged = debounced xor previousDebounced;
    previousDebounced = debounced;
    return debouncedChanged;
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
