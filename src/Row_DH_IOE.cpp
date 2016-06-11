#include "Row_DH_IOE.h"

const bool RowScanner_PinsBitwise::activeHigh = 1;

uint8_t Row_DH_IOE::scan(uint16_t& rowEnd)
{
    return scanner.scan(rowEnd);
}

uint8_t Row_DH_IOE::debounce(const uint8_t rowState, uint8_t& debounced)
{
    return debouncer.debounce(rowState, debounced);
}
