#ifndef CODE_LAYEREDCODESC_MF_H
#define CODE_LAYEREDCODESC_MF_H
#include <Arduino.h>
#include <inttypes.h>
#include <Code_LayeredCodeScBase.h>
#include <LayerState_DH.h>

/* Class Code_LayeredCodeSc_MF is a 2-layer code, one object for each MF sub-layer e.g.
    layer 0: ms_up    //mouse up
    layer 1: KEY_UP   //up arrow
When the key is pressed, the active layer is retrieved from LayerState_DH,
 and the object of the active layer is sent to USB.
*/
class Code_LayeredCodeSc_MF : public Code_LayeredCodeScBase
{
    private:
        static LayerState_DH& refLayerState_DH;
    public:
        Code_LayeredCodeSc_MF(Code& refCode0, const uint16_t scancode1)
            : Code_LayeredCodeScBase(refCode0, scancode1, 0) { }
        virtual void press();
};
#endif
