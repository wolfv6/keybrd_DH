#include "Row_DH_uC.h"

const bool RowScanner_PinsArray::STROBE_ON = HIGH; //active high
const bool RowScanner_PinsArray::STROBE_OFF = LOW;

void Row_DH_uC::process()
{
    //these variables are all bitwise, one bit per key
    uint8_t rowState;                       //1 means pressed, 0 means released
    uint8_t debouncedChanged;               //1 means debounced changed
    uint8_t KEY_COUNT;

    rowState = scanner.scan(KEY_COUNT);
    debouncedChanged = debouncer.debounce(rowState, debounced);
    pressRelease(KEY_COUNT, debouncedChanged);
}
