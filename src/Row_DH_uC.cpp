#include "Row_DH_uC.h"

const bool RowScanner_PinsArray::ACTIVE_HIGH = 1;

void Row_DH_uC::process()
{
    //these variables are all bitwise, one bit per key
    uint8_t rowState;                       //1 means pressed, 0 means released
    uint8_t rowEnd;                    //1 bit marks positioned after last key of row
    uint8_t debouncedChanged;               //1 means debounced changed

    rowState = scanner.scan(rowEnd);
    debouncedChanged = debouncer.debounce(rowState, debounced);
    pressRelease(rowEnd, debouncedChanged);
}
