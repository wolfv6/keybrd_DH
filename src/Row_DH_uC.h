#ifndef ROW_H
#define ROW_H

#include <Row_DH.h>
#include <RowScanner_PinsArray.h>
#include <Debouncer_4Samples.h>

/* Row_DH_uC is a row connected to a micro controller.
Configuration and Instantiation instructions are in keybrd/src/Row_uC.h
*/
class Row_DH_uC : public Row_DH
{
    private:
        RowScanner_PinsArray scanner;
        Debouncer_4Samples debouncer;
        //Debouncer_Not debouncer;
    public:
        Row_DH_uC(const uint8_t strobePin, const uint8_t readPins[], const uint8_t READ_PIN_COUNT,
                Key *const ptrsKeys[])
            : Row_DH(ptrsKeys), scanner(strobePin, readPins, READ_PIN_COUNT) { }
        void process();
};
#endif
