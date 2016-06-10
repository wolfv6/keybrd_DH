#ifndef ROWIOE_H
#define ROWIOE_H

#include <Row_DH.h>
#include <RowScanner_PinsBitwise.h>
#include <Debouncer_4Samples.h>

/*
Simlar to Row but using RowScanner_PinsBitwise.

Configuration
-------------

Instantiation
-------------
*/
class Row_DH_IOE : public Row_DH
{
    private:
        RowScanner_PinsBitwise scanner;
        Debouncer_4Samples debouncer;
        //Debouncer_Not debouncer;
    public:
        Row_DH_IOE( RowPort& refRowPort, const uint8_t strobePin,
             ColPort& refColPort, Key *const ptrsKeys[])
            : Row_DH(ptrsKeys), scanner(refRowPort, strobePin, refColPort) { }
        uint8_t scan(uint16_t& rowEnd);
        uint8_t debounce(const uint8_t rowState, uint8_t& debounced);
};
#endif
