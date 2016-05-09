#include "Code_Protected_ByNASLock.h"

void Code_Protected_ByNASLock::press()
{
    protectedPress(refProtector.getIsPressed()); //Code_NASLock is the protector
}
