#ifndef ROW_DH_H
#define ROW_DH_H

#include <RowBase.h>
#include "StateStickyMouseButtons.h"
#include "Code_LayeredDoublePressToggle.h"

/* class Row_DH

*/
class Row_DH : public RowBase
{
    private:
        virtual uint8_t debounce(const uint8_t rowState);

        static StateStickyMouseButtons& refMouseButtons;
        static Code_LayeredDoublePressToggle& refCtrl; 
        static Code_LayeredDoublePressToggle& refAlt; 
        virtual void keyWasPressed();
    public:
        Row_DH( RowPort &refRowPort, const uint8_t rowPin,
            ColPort *const ptrsColPorts[], const uint8_t colPortCount, Key *const ptrsKeys[])
            : RowBase(refRowPort, rowPin, ptrsColPorts, colPortCount, ptrsKeys) { }
};
#endif
