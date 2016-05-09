#ifndef CODE_DOUBLEPRESSPROTECTED_H
#define CODE_DOUBLEPRESSPROTECTED_H
#include <Arduino.h>
#include <Code.h>

/* Code_DoublePressProtected class requires a key double strike to send code to USB.
This helps prevent accidental presses.

If a Code_DoublePressProtected object is pressed twice within DOUBLE_PRESS_MILLIS time,
 the refCode is pressed once.

Example instantiation:
    const uint8_t Code_DoublePressProtected::DOUBLE_PRESS_MILLIS = 250;
    Code_Sc s_printscreen(KEY_PRINTSCREEN);
    Code_DoublePressProtected d_printscreen(s_printscreen);

The elapsedMillis feature is built into Teensyduino.
For non-Teensy boards, it is available as a library http://playground.arduino.cc/Code/ElapsedMillis
*/
class Code_DoublePressProtected : public Code
{
    private:
        Code &refCode;                         //code to be protected by double press
        static const uint8_t DOUBLE_PRESS_MILLIS; //max time between first and second press
        elapsedMillis sinceFirstPress;         //time elapsed since first press
        bool doublePressed;                    //true if second press was within DOUBLE_PRESS_MILLIS
    public:
        Code_DoublePressProtected(Code &refCode) : refCode(refCode) {}
        virtual void press();
        virtual void release();
};
#endif
