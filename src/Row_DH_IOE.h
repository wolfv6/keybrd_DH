#ifndef ROW_DH_IOE_H
#define ROW_DH_IOE_H

#include <Row_DH.h>
#include <Scanner_Port.h>
#include <Debouncer_Samples.h>
class PortWrite;
class PortRead;

/* Row_DH_IOE is a row connected to an Input/Output Expander.
Configuration and Instantiation instructions are in keybrd/src/Row_IOE.h
*/
class Row_DH_IOE : public Row_DH
{
    private:
        Scanner_Port scanner;
        Debouncer_Samples debouncer;
        //Debouncer_Not debouncer;
        const uint8_t readPinCount;           //number of read pins
    public:
        Row_DH_IOE(PortWrite& refPortWrite, const uint8_t strobePin,
             PortRead& refPortRead, const uint8_t readPinCount, Key *const ptrsKeys[])
            : Row_DH(ptrsKeys), scanner(refPortWrite, strobePin, refPortRead),
            readPinCount(readPinCount) { }
        void process();
};
#endif
