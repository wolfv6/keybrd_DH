#include "Code_LayerLockMF_Protector.h"

void Code_LayerLockMF_Protector::press()
{
    isPressed = true;
    refLayerState.lock(layerId);
}

void Code_LayerLockMF_Protector::release()
{
    isPressed = false;
}

//called by Code_Protected_ByMFLock
bool Code_LayerLockMF_Protector::getIsPressed()
{
    return isPressed;
}
