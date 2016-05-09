#include "Code_NASLock_Protector.h"

void Code_NASLock_Protector::press()
{
    isPressed = true;
    refStateLayers_NAS.NASLock();
}

void Code_NASLock_Protector::release()
{
    isPressed = false;
}

//called by Code_Protected_ByNASLock
bool Code_NASLock_Protector::getIsPressed()
{
    return isPressed;
}
