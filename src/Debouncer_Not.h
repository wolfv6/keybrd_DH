#ifndef DEBOUNCER_NOT_H
#define DEBOUNCER_NOT_H
#include <Arduino.h>
#include <inttypes.h>
#include <DebouncerInterface.h>

/* Debouncer_Not does not debource.
debounce() returns raw signal, no debouncing is performed.

A keyboard does not need a debouncing if one of the following is true:
    * keypad has hardware debouncers
    * poling I2C makes scan rate slower than debounce time
    * optic switches are used (because they don't bounce)
*/
class Debouncer_Not : public DebouncerInterface
{
    public:
        virtual uint8_t debounce(const uint8_t rawSignal, uint8_t& debounced);
};
#endif
