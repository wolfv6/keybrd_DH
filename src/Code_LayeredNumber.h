#ifndef CODE_LAYEREDNUMBER_H
#define CODE_LAYEREDNUMBER_H
#include <Arduino.h>
#include <inttypes.h>
#include <Code.h>
#include "LayerState_DH.h"

/* Class Code_LayeredNumber sends KEY or KEYPAD number
   determined by refLayerState.getNumberLayer().

example instantiation:
    Code_S s_numLock(KEY_NUM_LOCK);
    Code_LayeredNumber n_1(KEY_1);
    LayerState_DH& Code_LayeredNumber::refLayerState = layerState_DH;
*/
class Code_LayeredNumber : public Code
{
    private:
        static LayerState_DH& refLayerState;
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
