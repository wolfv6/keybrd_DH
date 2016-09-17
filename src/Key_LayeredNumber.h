#ifndef KEY_LAYEREDNUMBER_H
#define KEY_LAYEREDNUMBER_H
#include <Arduino.h>
#include <inttypes.h>
#include <Key.h>
#include "LayerState_DH.h"

/* Class Key_LayeredNumber is a 2-layer key, one scancode for each Number sub-layer e.g.
    layer 0: KEY_1
    layer 1: KEYPAD_1
When the key is pressed, the active layer is retrieved from LayerState_DH
 and the scancode of the active layer is sent to USB.

Only the layer-0 scancode is stored (the layer-1 scancode is computed).

Example instantiation:
    Code_S s_numLock(KEY_NUM_LOCK);
    Key_LayeredNumber n_1(KEY_1);
    LayerState_DH& Key_LayeredNumber::refLayerState_DH = layerState_DH;
*/
class Key_LayeredNumber : public Key
{
    private:
        static LayerState_DH& refLayerState_DH;
        const uint16_t scancode;                //KEY
        bool numberLayer;                       //0 for KEY, 1 for KEYPAD
    protected:
        uint16_t scancodeNum;
    public:
        Key_LayeredNumber(const uint16_t scancode): scancode(scancode), numberLayer(0) { }
        virtual void press();
        virtual void release();
        void setScancodeNum();
};
#endif
