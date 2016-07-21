#include "Code_MouseSpeed.h"

//define static members http://playground.arduino.cc/Code/ElapsedMillis
uint8_t Code_MouseSpeed::speedByte = 0;
uint8_t Code_MouseSpeed::sinceSlowPressed = 0;

void Code_MouseSpeed::release()
{
    speedByte &= ~speedBit;                     //clear speedBit bit
}

void Code_MouseSpeed::mouseMove()
{
    int8_t x = mouseDistance(speedByte);
    int8_t y = mouseDistance(speedByte >> 4);
    Mouse.move(x,y,0);                          //https://www.arduino.cc/en/Reference/MouseMove

    if (sinceSlowPressed != 255)                //roll-over guard
    {
        sinceSlowPressed++;
    }
}

/* The 4 least-significant bits of speedBits are for either x or y axis.
Return negative or positive distance to move mouse pointer.
*/
int8_t Code_MouseSpeed::mouseDistance(uint8_t speedBits)
{
    return magnitude(speedBits) - magnitude(speedBits >> 2);
}

/* The 3 least-significant bits of speedBits are for one of x, -x, -y, or y directions.
Return number of pixels to move mouse pointer.
*/
uint8_t Code_MouseSpeed::magnitude(uint8_t speedBits)
{
    enum speedBitsPlace {SLOW_BIT=1, QUICK_BIT=2}; //enum because switch case not work with const

    switch (speedBits & (SLOW_BIT + QUICK_BIT)) //read two bits
    {
    case (SLOW_BIT + QUICK_BIT):            //high speed
    {
        return HIGH_SPEED;
    }
    case QUICK_BIT:                         //quick
    {
        return QUICK_SPEED;
    }
    case SLOW_BIT:                          //slow
    {
        if (sinceSlowPressed >= START_SLOW)
        {
            return SLOW_SPEED;
        }
        if (sinceSlowPressed >= START_NUDGE)
        {
            return NUDGE_SPEED;
        }
        return 0;
    }
    default:
    {
        return 0;
    }
    }
}
