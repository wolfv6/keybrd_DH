#include "Code_Protected_ByMFLock.h"

void Code_Protected_ByMFLock::press()
{
    protectedPress(refProtector.getIsPressed()); //Code_MFLock is the protector
}
