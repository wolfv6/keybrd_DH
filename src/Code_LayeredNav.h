#ifndef CODE_LAYEREDNAV_H
#define CODE_LAYEREDNAV_H
#include <Arduino.h>
#include <inttypes.h>
#include <Code_LayeredScScBase.h>
#include "LayerState_DH.h"
#include "Code_LayerState_Toggle.h"

/* Class Code_LayeredNav sends one of two scancodes, determined by refLayerState_DH.getNavLayer().
*/
class Code_LayeredNav : public Code_LayeredScScBase
{
    private:
        static LayerState_DH& refLayerState_DH;
        static Code_LayerState_Toggle& refStateLRModf;
    public:
        Code_LayeredNav(const uint16_t scancode0, const uint16_t scancode1):
            Code_LayeredScScBase(scancode0, scancode1) { }
        virtual void press();
};
#endif

