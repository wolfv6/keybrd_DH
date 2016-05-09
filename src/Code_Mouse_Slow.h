#ifndef CODE_MOUSE_SLOW_H
#define CODE_MOUSE_SLOW_H
#include <Arduino.h>
#include <inttypes.h>
#include <Code_MouseSpeed.h>

/* Class Code_Mouse_Slow 
Mouse movement keys on DataHand right index finger are slow.

x and y are for initial pointer movement, usually 1 or -1 for one coordinate, and 0 for the other.
If key is released before START_NUDGE, there is no other pointer movement.
*/
class Code_Mouse_Slow : public Code_MouseSpeed
{
    private:
        const int8_t x;                         //number of horizontal pixles
        const int8_t y;                         //number of vertical pixles, positive y is down
    public:
        Code_Mouse_Slow(const uint8_t speedBit, const int8_t x, const int8_t y)
            : Code_MouseSpeed(speedBit), x(x), y(y) {}
        virtual void press();
};
#endif
