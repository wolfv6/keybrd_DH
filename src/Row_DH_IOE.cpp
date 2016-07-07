#include "Row_DH_IOE.h"

const bool RowScanner_PinsBitwise::activeHigh = 1;

void Row_DH_IOE::process()
{
    //these variables are all bitwise, one bit per key
    uint8_t rowState;                       //1 means pressed, 0 means released
    uint8_t debouncedChanged;               //1 means debounced changed
    ColPort* ptrColPort; //new
    uint8_t KEY_COUNT; //new

    ptrColPort = scanner.scan();
    rowState = ptrColPort->getPortState() << (6-KEY_COUNT);
    debouncedChanged = debouncer.debounce(rowState, debounced);
    pressRelease(KEY_COUNT, debouncedChanged);
}
