#ifndef ROWIOE_H
#define ROWIOE_H

#include <Row_DH.h>
#include <RowScanner_PinsBitwise.h>
#include <Debouncer_4Samples.h>

/* Row_DH_IOE is a row connected to an Input/Output Expander.
Configuration and Instantiation instructions are in keybrd/src/Row_IOE.h
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
        read_pins_t scan(read_pins_mask_t& rowEnd);
        read_pins_t debounce(const read_pins_t rowState, read_pins_t& debounced);
};
#endif
