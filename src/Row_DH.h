#ifndef ROW_DH_H
#define ROW_DH_H

#include <RowBase.h>
#include "StateStickyMouseButtons.h"
#include "Code_LayeredDoublePressToggle.h"

#define SAMPLE_COUNT 4      //number of consecutive equal bits needed to change a debounced bit

/*
#define SAMPLE_COUNT in this header file.
define and initilize DELAY_MICROSECONDS in sketch or in config file.
    const unsigned int Row_DH::DELAY_MICROSECONDS = 0;

*/
class Row_DH : public RowBase
{
    private:
        static const unsigned int DELAY_MICROSECONDS; //delay between each Row scan for debouncing
        uint8_t samples[SAMPLE_COUNT];      //bitwise, one bit per key, most recent readings
        uint8_t samplesIndex;               //samples[] current write index
        uint8_t debounce(const uint8_t rowState); //debouncer and I2C error correction

        static StateStickyMouseButtons& refMouseButtons;
        static Code_LayeredDoublePressToggle& refCtrl; 
        static Code_LayeredDoublePressToggle& refAlt; 
        virtual void keyWasPressed();
    public:
        Row_DH( RowPort &refRowPort, const uint8_t rowPin,
            ColPort *const ptrsColPorts[], const uint8_t colPortCount, Key *const ptrsKeys[])
            : RowBase(refRowPort, rowPin, ptrsColPorts, colPortCount, ptrsKeys), samplesIndex(0) { }
};
#endif
