#ifndef CODE_MOUSESPEED_H
#define CODE_MOUSESPEED_H
#include <Arduino.h>
#include <inttypes.h>
#include <Code.h>
#include "StateStickyMouseButtons.h"

/* Class Code_MouseSpeed is a virtual class
static configurations are defined in sketch e.g.

    //Configure START_ values (START SPEED units are mouseMove() runs sinceSlowPressed).
    //to see START_NUDGE time, make NUDGE_SPEED and Code_Mouse_Slow-up 10x bigger
    const uint8_t Code_MouseSpeed::START_NUDGE = 4;
    const uint8_t Code_MouseSpeed::START_SLOW = 16;

    //Configure _SPEED values (SPEED units are in pixels per Mouse.move sent).
    //Configure SCANS_PER_MOUSE_MOVE in class MouseMove constructor.
    //Max SPEED is 127 because Arduino Mouse.move(signed char, signed char, signed char).
    const uint8_t Code_MouseSpeed::NUDGE_SPEED = 2; //3x
    const uint8_t Code_MouseSpeed::SLOW_SPEED = 6;
    const uint8_t Code_MouseSpeed::QUICK_SPEED = 18;
    const uint8_t Code_MouseSpeed::HIGH_SPEED = 54;
*/
class Code_MouseSpeed : public Code
{
    private:
        static const uint8_t START_NUDGE;
        static const uint8_t START_SLOW;

        static const uint8_t NUDGE_SPEED;
        static const uint8_t SLOW_SPEED;
        static const uint8_t QUICK_SPEED;
        static const uint8_t HIGH_SPEED;
    protected:
        static uint8_t speedByte;
        /* speedByte is bitwise, set by Code_Mouse_Slow and Code_Mouse_Quick
           speedByte represents 8 directions-speeds in this order:
                +xSlow, +xQuick,        right
                -xSlow, -xQuick,        left
                +ySlow, +yQuick,        down
                -ySlow, -yQuick         up            */
        const uint8_t speedBit;          //bitwise, one bit of speedbyte
        static uint8_t sinceSlowPressed; //number of mouseMove() runs since Code_Mouse_Speed press
        static int8_t mouseDistance(uint8_t speedBits);
        static uint8_t magnitude(uint8_t speedBits);
        static StateStickyMouseButtons& refMouseButtons;
    public:
        Code_MouseSpeed(const uint8_t speedBit) : speedBit(speedBit) { }
        virtual void press()=0;
        virtual void release();
        static void mouseMove();                //called from MouseMove::send()
};
#endif
