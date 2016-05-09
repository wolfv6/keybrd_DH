#ifndef CODE_PROTECTED_BYNASLOCK_H
#define CODE_PROTECTED_BYNASLOCK_H
#include <Arduino.h>
#include "Code_Protected.h"
#include "Code_NASLock_Protector.h"

/* Hold NAS key to use protected refCode.  This helps prevent accidental presses.
*/
class Code_Protected_ByNASLock : public Code_Protected
{
    private:
        static Code_NASLock_Protector& refProtector;
    public:
        Code_Protected_ByNASLock(Code& refCode) : Code_Protected(refCode) {}
        virtual void press();
};
#endif
