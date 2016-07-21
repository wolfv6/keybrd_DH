#ifndef CODE_PROTECTED_H
#define CODE_PROTECTED_H
#include <Arduino.h>
#include <inttypes.h>
#include <Code.h>

/* Code_Protected is an abstract class.
refCode is activated by pressing refCode and its protector simlutaneously.
The protector (Code_NASLock_Protector or Code_LayerLockMF_Protector) is defined in derived classes press().
*/
class Code_Protected : public Code
{
    private:
        Code &refCode;                          //code to be protected
        bool protectorWasPressed;               //true if the protoctor was already pressed
        // when the protected code was pressed
    public:
        Code_Protected(Code &refCode)
            : refCode(refCode), protectorWasPressed(false) {}
        void protectedPress(bool protectorIsPressed);
        virtual void press()=0;
        virtual void release();
};
#endif
