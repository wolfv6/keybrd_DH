#ifndef CODE_LAYEREDNUMBER_H
#define CODE_LAYEREDNUMBER_H
#include <Arduino.h>
#include <inttypes.h>
#include <Code.h>
#include "LayerState_DH.h"

/* Class Code_LayeredNumber is a 2-layer code, one scancode for each Number sub-layer e.g.
    layer 0: KEY_1
    layer 1: KEYPAD_1
When the key is pressed, the active layer is retrieved from LayerState_DH
 and the scancode of the active layer is sent to USB.
 
Only the layer-0 scancode is stored (the layer-1 scancode is computed).

Example instantiation:
    Code_S s_numLock(KEY_NUM_LOCK);
    Code_LayeredNumber n_1(KEY_1);
    LayerState_DH& Code_LayeredNumber::refLayerState_DH = layerState_DH;
*/
class Code_LayeredNumber : public Code
{
    private:
        static LayerState_DH& refLayerState_DH;
        const uint16_t scancode;                //KEY
        bool numberLayer;                       //0 for KEY, 1 for KEYPAD
    protected:
        uint16_t scancodeNum;
    public:
        Code_LayeredNumber(const uint16_t scancode): scancode(scancode), numberLayer(0) { }
        virtual void press();
        virtual void release();
        void setScancodeNum();
};
#endif
