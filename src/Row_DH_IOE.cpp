#include "Row_DH_IOE.h"

const bool RowScanner_PinsBitwise::activeHigh = 1;

read_pins_t Row_DH_IOE::scan(read_pins_mask_t& rowEnd)
{
    return scanner.scan(rowEnd);
}

read_pins_t Row_DH_IOE::debounce(const read_pins_t rowState, read_pins_t& debounced)
{
    return debouncer.debounce(rowState, debounced);
}
