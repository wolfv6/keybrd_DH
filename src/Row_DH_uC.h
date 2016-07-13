#ifndef ROW_DH_UC_H
#define ROW_DH_UC_H

#include <Row_DH.h>
#include <Scanner_uC.h>
#include <Debouncer_4Samples.h>

/* Row_DH_uC is a row connected to a micro controller.
Configuration and Instantiation instructions are in keybrd/src/Row_uC.h
*/
class Row_DH_uC : public Row_DH
{
    private:
        Scanner_uC scanner;
        Debouncer_4Samples debouncer;
        //Debouncer_Not debouncer;
        const uint8_t READ_PIN_COUNT;           //number of read pins
    public:
        Row_DH_uC(const uint8_t strobePin, const uint8_t READ_PINS[], const uint8_t READ_PIN_COUNT,
                Key *const ptrsKeys[])
            : Row_DH(ptrsKeys), scanner(strobePin, READ_PINS, READ_PIN_COUNT),
            READ_PIN_COUNT(READ_PIN_COUNT) { }
        void process();
};
#endif
