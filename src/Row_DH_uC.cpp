#include "Row_DH_uC.h"

const bool RowScanner_PinsArray::activeHigh = 1;

read_pins_t Row_DH_uC::scan(read_pins_mask_t& rowEnd)
{
    return scanner.scan(rowEnd);
}

read_pins_t Row_DH_uC::debounce(const read_pins_t rowState, read_pins_t& debounced)
{
    return debouncer.debounce(rowState, debounced);
}
