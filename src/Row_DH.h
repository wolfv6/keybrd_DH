#ifndef ROW_DH_H
#define ROW_DH_H

#include <Row.h>
#include <Debouncer_Samples.h>
#include <Debouncer_Not.h>
#include <StateStickyMouseButtons.h>
#include <Code_LayeredDoublePressToggle.h>

/* Row_DH is an abstract class.
*/
class Row_DH : public Row
{
    private:
        static StateStickyMouseButtons& refMouseButtons;
        static Code_LayeredDoublePressToggle& refCtrl; 
        static Code_LayeredDoublePressToggle& refAlt; 
        virtual void keyWasPressed();
    public:
        Row_DH(Key *const ptrsKeys[]): Row(ptrsKeys) { }
};
#endif
