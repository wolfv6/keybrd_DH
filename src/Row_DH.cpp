#include "Row_DH.h"

/* process() scans the row and calls any newly pressed or released keys.
Simlar to Row::process() but with rightShift.
Bitwise variables are 1 bit per key.
*/
void Row_DH::process()
{
    read_pins_t readState;                      //bitwise, 1 means key is pressed, 0 means released
    read_pins_t debouncedChanged;               //bitwise, 1 means debounced changed

    readState = refScanner.scan(strobePin) >> rightShift;
    debouncedChanged = debouncer.debounce(readState, debounced);
    send(readPinCount, debouncedChanged);
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
