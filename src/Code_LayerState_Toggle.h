#ifndef CODE_LAYERSTATE_TOGGLE_H
#define CODE_LAYERSTATE_TOGGLE_H

#include <inttypes.h>
#include <Code.h>
#include <StateLayersInterface.h>
#include <LEDsBlinker.h>

/* Code_LayerState_Toggle is class of LRModf.
press() toggles activeLayer between 0 and 1.
*/
class Code_LayerState_Toggle : public Code, public StateLayersInterface
{
    private:
        LEDsBlinker& blinker0;
        LEDsBlinker& blinker1;
        uint8_t activeLayer;                    //0 or 1
    public:
        Code_LayerState_Toggle(LEDsBlinker& blinker0, LEDsBlinker& blinker1)
            : blinker0(blinker0), blinker1(blinker1), activeLayer(0) {}
        virtual void press();
        virtual void release();
        virtual uint8_t getActiveLayer();
};
#endif
