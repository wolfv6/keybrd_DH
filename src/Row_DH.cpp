#include "Row_DH.h"

/* process() scans the row and calls any newly pressed or released keys.
Simlar to Row::process() but with rightShift.
Bit patterns are 1 bit per key.
*/
void Row_DH::process()
{
    read_pins_t readState;                      //bits, 1 means key is pressed, 0 means released
    read_pins_t debouncedChanged;               //bits, 1 means debounced changed

    readState = refScanner.scan(strobePin) >> rightShift;
    debouncedChanged = debouncer.debounce(readState, debounced);
    send(keyCount, debouncedChanged);
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
