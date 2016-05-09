#ifndef CODE_PROTECTED_BYMFLOCK_H
#define CODE_PROTECTED_BYMFLOCK_H
#include <Arduino.h>
#include "Code_Protected.h"
#include "Code_LayerLockMF_Protector.h"
//#include "Code_MFLock.h"

/* Hold MF key to use protected refCode.  This helps prevent accidental presses.
*/
class Code_Protected_ByMFLock : public Code_Protected
{
    private:
        static Code_LayerLockMF_Protector& refProtector;
    public:
        Code_Protected_ByMFLock(Code& refCode) : Code_Protected(refCode) {}
        virtual void press();
};
#endif
