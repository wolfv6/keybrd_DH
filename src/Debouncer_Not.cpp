#include "Debouncer_Not.h"

/* debounce() sets debounced and returns debouncedChanged.  All variables are bitwise.
For parameters, 1 means pressed, 0 means released.
For return, 1 means debounced changed.
*/
uint8_t Debouncer_Not::debounce(const uint8_t rawSignal, uint8_t& debounced)
{
    uint8_t previousDebounced;                  //bitwise, 1 means pressed, 0 means released

    previousDebounced = debounced;
    debounced = rawSignal;
    return debounced xor previousDebounced;
}

