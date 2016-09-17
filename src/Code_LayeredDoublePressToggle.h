#ifndef KEY_LAYEREDDOUBLEPRESSTOGGLE_H
#define KEY_LAYEREDDOUBLEPRESSTOGGLE_H
#include <Arduino.h>
#include <Key_LayeredScScBase.h>
#include "Code_LayerState_Toggle.h"

/* Key_LayeredDoublePressToggle
Double press toggles between scancode0 and scancode1.
It can also be toggled by Code_LayerState_Toggle.

Feature is based on https://geekhack.org/index.php?topic=41422.500 Reply #528 #531 by arisian.
Given one CTRL switch that toggles between CTRL-L and CTRL-R.
Strike CTRL-L a second time, without striking any other keys in between, CTRL-R is sent instead.
When the CTRL-R is released, the CTRL key automatically reverts back CTRL-L.
*/
class Key_LayeredDoublePressToggle : public Key_LayeredScScBase
{
    private:
        static Code_LayerState_Toggle& refLayerState; //LRModf
        bool isOther;            //binary semaphore, true if key that was pressed is not this key
        bool otherWasPressed;    //true if another key was pressed since this key was last pressed
        bool activeLayer;        //set by LRModf
    public:
        Key_LayeredDoublePressToggle(const uint16_t scancode0, const uint16_t scancode1)
            : Key_LayeredScScBase(scancode0, scancode1), otherWasPressed(true) {}
        virtual void press();
        void prevent_toggle();
};
#endif
