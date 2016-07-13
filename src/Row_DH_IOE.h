#ifndef ROW_DH_IOE_H
#define ROW_DH_IOE_H

#include <Row_DH.h>
#include <Scanner_Port.h>
#include <Debouncer_4Samples.h>

/* Row_DH_IOE is a row connected to an Input/Output Expander.
Configuration and Instantiation instructions are in keybrd/src/Row_IOE.h
*/
class Row_DH_IOE : public Row_DH
{
    private:
        Scanner_Port scanner;
        Debouncer_4Samples debouncer;
        //Debouncer_Not debouncer;
        const uint8_t READ_PIN_COUNT;           //number of read pins
    public:
        Row_DH_IOE( StrobePort& refStrobePort, const uint8_t strobePin,
             ReadPort& refReadPort, const uint8_t READ_PIN_COUNT, Key *const ptrsKeys[])
            : Row_DH(ptrsKeys), scanner(refStrobePort, strobePin, refReadPort),
            READ_PIN_COUNT(READ_PIN_COUNT) { }
        void process();
};
#endif
