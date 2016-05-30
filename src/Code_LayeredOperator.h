#ifndef CODE_LAYEREDOPERATOR_H
#define CODE_LAYEREDOPERATOR_H
#include <Arduino.h>
#include <inttypes.h>
#include <Code_LayeredCodeScBase.h>
#include "LayerState_DH.h"
#include "Code_LayerState_Toggle.h"

/* Class Code_LayeredOperator is a 2-layer code, one item for each operator sub-layer e.g.
    layer 0: s_plus
    layer 1: KEYPAD_PLUS
When the key is pressed, the active layer is determined,
 and the object of the active layer is sent to USB.
The active layer is determined by
 refLayerState_DH::activeLayer, LayerState_DH::lazyNumLock, and StateLRModf::activeLayer
*/
class Code_LayeredOperator : public Code_LayeredCodeScBase
{
    private:
        static LayerState_DH& refLayerState_DH;
        static Code_LayerState_Toggle& refStateLRModf;
        static const uint8_t TEN_KEY_ON;
    public:
        Code_LayeredOperator(Code& refCode0, const uint16_t scancode1)
            : Code_LayeredCodeScBase(refCode0, scancode1, 0) { }
        virtual void press();
};
#endif
