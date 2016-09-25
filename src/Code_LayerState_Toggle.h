#ifndef CODE_LAYERSTATE_TOGGLE_H
#define CODE_LAYERSTATE_TOGGLE_H

#include <inttypes.h>
#include <Code.h>
#include <LayerStateInterface.h>
#include <LEDInterface.h>
#include <IndicatorLEDs.h>

/* Code_LayerState_Toggle is class of LRModf.
press() toggles activeLayer between 0 and 1.
*/
class Code_LayerState_Toggle : public Code, public LayerStateInterface
{
    private:
        IndicatorLEDs& refIndicatorLEDs;
        LEDInterface*const *const ptrsLEDs_L;   //pointer to  left-indicator LEDs pointer array
        LEDInterface*const *const ptrsLEDs_R;   //pointer to right-indicator LEDs pointer array
        uint8_t activeLayer;                    //0 or 1
    public:
        Code_LayerState_Toggle(IndicatorLEDs& refIndicatorLEDs,
                               LEDInterface*const ptrsLEDs_L[], LEDInterface*const ptrsLEDs_R[])
            : refIndicatorLEDs(refIndicatorLEDs),
              ptrsLEDs_L(ptrsLEDs_L), ptrsLEDs_R(ptrsLEDs_R), activeLayer(0) {}
        virtual void press();
        virtual void release();
        virtual uint8_t getActiveLayer();
};
#endif
