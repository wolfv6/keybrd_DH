#ifndef CODE_LAYEREDOPERATOR_H
#define CODE_LAYEREDOPERATOR_H
#include <Arduino.h>
#include <inttypes.h>
#include <Code_LayeredCodeScBase.h>
#include "StateLayers_DH.h"
#include "Code_LayerState_Toggle.h"

/* Class Code_LayeredOperator sends one of two scancodes,
   determined by refStateLayers_DH.getOperatorLayer().
*/
class Code_LayeredOperator : public Code_LayeredCodeScBase
{
    private:
        static StateLayers_DH& refStateLayers_DH;
        static Code_LayerState_Toggle& refStateLRModf;
        static const uint8_t TEN_KEY_ON;
    public:
        Code_LayeredOperator(Code& refCode0, const uint16_t scancode1)
            : Code_LayeredCodeScBase(refCode0, scancode1, 0) { }
        virtual void press();
};
#endif
