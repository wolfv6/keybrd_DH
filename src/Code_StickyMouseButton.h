#ifndef CODE_STICKYMOUSEBUTTON_H
#define CODE_STICKYMOUSEBUTTON_H
#include <Arduino.h>
#include <inttypes.h>
#include <Code.h>
#include "StateStickyMouseButtons.h"

/* Class Code_StickyMouseButton presses and releases Mouse buttons.
More details in StateStickyMouseButtons.h
*/
class Code_StickyMouseButton : public Code
{
    private:
        static StateStickyMouseButtons& refMouseButtons;
        const uint16_t scancode;                //MOUSE_LEFT or MOUSE_RIGHT
    public:
        Code_StickyMouseButton(const uint16_t scancode): scancode(scancode) {}
        virtual void press();
        virtual void release();
};
#endif
