#include "Row_DH_IOE.h"

const bool RowScanner_PinsBitwise::activeHigh = 1;

void Row_DH_IOE::process()
{
    //these variables are all bitwise, one bit per key
    uint8_t rowState;                       //1 means pressed, 0 means released
    read_pins_mask_t rowEnd;                    //1 bit marks positioned after last key of row
    uint8_t debouncedChanged;               //1 means debounced changed
    ColPort* ptrColPort; //new

    ptrColPort = scanner.scan(rowEnd);
    rowState = getRowState(ptrColPort, rowEnd); //new
    debouncedChanged = debouncer.debounce(rowState, debounced);
    pressRelease(rowEnd, debouncedChanged);
}

uint8_t Row_DH_IOE::getRowState(ColPort* ptrColPort, read_pins_mask_t& rowEnd)
{
    uint8_t rowState = 0;           //bitwise, one key per bit, 1 means key is pressed
    uint8_t portMask;               //bitwise, 1 bit is a colPortState position

    rowEnd = 1;

    //bitwise colPins, 1 means pin is connected to column
    uint8_t colPins = ptrColPort->getColPins();

    //bitwise colPortState, pin values where set in ColPort::read(), get them now
    uint8_t colPortState = ptrColPort->getPortState();

    /*if (activeHigh) //'activeHigh' was not declared in this scope
    {
        colPortState = ~colPortState; //todo configure IOE polarity to take care of this
    }*/

    for ( portMask = 1; portMask > 0; portMask <<= 1 ) //shift portMask until overflow
    {                                       //for each pin of col port
        if (portMask & colPins)             //if pin is connected to column
        {
            if (portMask & ~colPortState)   //if pin detected a key press
            {
                rowState |= rowEnd;         //set rowState bit for that key
            }

            rowEnd <<= 1;                   //shift rowEnd to next key
        }
    }

    return rowState;
}
