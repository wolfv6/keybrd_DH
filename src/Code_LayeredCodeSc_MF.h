#ifndef KEY_LAYEREDCODESC_MF_H
#define KEY_LAYEREDCODESC_MF_H
#include <Arduino.h>
#include <inttypes.h>
#include <Key_LayeredCodeScBase.h>
#include <LayerState_DH.h>

/* Class Key_LayeredCodeSc_MF is a 2-layer code, one object for each MF sub-layer e.g.
    layer 0: ms_up    //mouse up
    layer 1: KEY_UP   //up arrow
When the key is pressed, the active layer is retrieved from LayerState_DH,
 and the object of the active layer is sent to USB.
*/
class Key_LayeredCodeSc_MF : public Key_LayeredCodeScBase
{
    private:
        static LayerState_DH& refLayerState_DH;
    public:
        Key_LayeredCodeSc_MF(Code& refCode0, const uint16_t scancode1)
            : Key_LayeredCodeScBase(refCode0, scancode1, 0) { }
        virtual void press();
};
#endif
