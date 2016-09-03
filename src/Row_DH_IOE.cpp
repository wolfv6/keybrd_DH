#include "Row_DH_IOE.h"

const bool Scanner_Port::STROBE_ON = HIGH;      //active high
const bool Scanner_Port::STROBE_OFF = LOW;

void Row_DH_IOE::process()
{
    //these variables are all bitwise, one bit per key
    uint8_t readState;                          //1 means pressed, 0 means released
    uint8_t debouncedChanged;                   //1 means debounced changed

    /* What the ">> (6 - readPinCount)" shift is for
    To understand this, we look at row instantiations.  In instantiations_rows_R.h notice that:
        row_R0, row_R1, and row_R2 have readPinCount=6
        row_R3 and row_R4 have readPinCount=4
        The first 2 keys in row_R3 and row_R4 are non-existent
    readState is right shifted by 2 because Row::send() loop reads from the least significant bit.
    */
    readState = scanner.scan() >> (6 - readPinCount);

    debouncedChanged = debouncer.debounce(readState, debounced);
    send(readPinCount, debouncedChanged);
}
