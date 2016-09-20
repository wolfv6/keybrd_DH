#ifndef KEY_LAYEREDNAV_H
#define KEY_LAYEREDNAV_H
#include <Arduino.h>
#include <inttypes.h>
#include <Key_LayeredScScBase.h>
#include "LayerState_DH.h"
#include "Code_LayerState_Toggle.h"

/* Class Key_LayeredNav is a 2-layer code, one scancode for each Nav sub-layer e.g.
    layer 0: KEY_PAGE_UP
    layer 1: KEYPAD_9
When the key is pressed, the active layerId is retrieved from StateLRModf
 and the scancode of the active layer is sent to USB.
*/
class Key_LayeredNav : public Key_LayeredScScBase
{
    private:
        static LayerState_DH& refLayerState_DH;
        static Code_LayerState_Toggle& refStateLRModf;
    public:
        Key_LayeredNav(const uint16_t scancode0, const uint16_t scancode1):
            Key_LayeredScScBase(scancode0, scancode1) { }
        virtual void press();
};
#endif
