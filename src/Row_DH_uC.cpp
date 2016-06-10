#include "Row_DH_uC.h"

uint8_t Row_DH_uC::scan(uint16_t& rowEnd)
{
    return scanner.scan(rowEnd);
}

uint8_t Row_DH_uC::debounce(const uint8_t rowState, uint8_t& debounced)
{
    return debouncer.debounce(rowState, debounced);
}
