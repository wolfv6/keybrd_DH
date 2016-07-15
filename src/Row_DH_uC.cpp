#include "Row_DH_uC.h"

const bool Scanner_uC::STROBE_ON = HIGH; //active high
const bool Scanner_uC::STROBE_OFF = LOW;

void Row_DH_uC::process()
{
    //these variables are all bitwise, one bit per key
    uint8_t readState;                       //1 means pressed, 0 means released
    uint8_t debouncedChanged;               //1 means debounced changed

    readState = scanner.scan();
    debouncedChanged = debouncer.debounce(readState, debounced);
    send(readPinCount, debouncedChanged);
}
