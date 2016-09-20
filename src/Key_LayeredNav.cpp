#include "Key_LayeredNav.h"

//Update layerId and numLock
void Key_LayeredNav::press()
{
    layerId = refStateLRModf.getActiveLayer(); //LRModf determines layer

    if (layerId == 1) //only layer 1 is numLock sensitive, don't bother updating numLock for layer 0
    {
        refLayerState_DH.updateNumLock(LayerState_DH::NUMLOCK_OFF);
    }

    pressScancode();
}
