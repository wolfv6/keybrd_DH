#include "Row_DH_IOE.h"

const bool Scanner_Port::STROBE_ON = HIGH; //active high

void Row_DH_IOE::process()
{
    //these variables are all bitwise, one bit per key
    uint8_t readState;                       //1 means pressed, 0 means released
    uint8_t debouncedChanged;               //1 means debounced changed
    //ReadPort* ptrReadPort;

    //ptrReadPort = scanner.scan();
    //readState = ptrReadPort->getPortState() >> (6-READ_PIN_COUNT);
    readState = scanner.scan() >> (6-READ_PIN_COUNT);
/*
if (READ_PIN_COUNT == 6)
{
    Keyboard.print(" readState=");
    Keyboard.print(readState);
}*/
    debouncedChanged = debouncer.debounce(readState, debounced);
    pressRelease(READ_PIN_COUNT, debouncedChanged);
}
