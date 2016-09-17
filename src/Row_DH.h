#ifndef ROW_DH_H
#define ROW_DH_H

#include <Row.h>
#include <Debouncer_Samples.h>
#include <Debouncer_Not.h>
#include <StateStickyMouseButtons.h>
#include <Key_LayeredDoublePressToggle.h>

/* Row_DH is an abstract class.
The left 2 keys in row_R3 and row_R4 are non-existent (right-matrix rows w/o thumb keys).
Right shift by 2 so that the two non-existent keys are skipped in Row::send().
*/
class Row_DH : public Row
{
    private:
        static StateStickyMouseButtons& refMouseButtons;
        static Key_LayeredDoublePressToggle& refCtrl;
        static Key_LayeredDoublePressToggle& refAlt;
        const uint8_t rightShift;
        virtual void keyWasPressed();
    public:
        Row_DH(ScannerInterface& refScanner, const uint8_t strobePin,
                Key* const ptrsKeys[], const uint8_t keyCount, const uint8_t rightShift)
            : Row(refScanner, strobePin, ptrsKeys, keyCount), rightShift(rightShift) {}
        virtual void process();
};
#endif
