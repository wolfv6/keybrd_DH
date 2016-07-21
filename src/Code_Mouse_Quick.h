#ifndef CODE_MOUSEQUICK_H
#define CODE_MOUSEQUICK_H
#include <Arduino.h>
#include <inttypes.h>
#include "Code_MouseSpeed.h"

/* Class Code_Mouse_Quick
Mouse movement keys on DataHand left index finger are quick.
*/
class Code_Mouse_Quick : public Code_MouseSpeed
{
    public:
        Code_Mouse_Quick(const uint8_t speedBit) : Code_MouseSpeed(speedBit) {}
        virtual void press();
};
#endif
