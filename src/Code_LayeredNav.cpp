#include "Key_LayeredNav.h"

//Update layer and numLock
void Key_LayeredNav::press()
{
    layer = refStateLRModf.getActiveLayer(); //LRModf determines layer

    if (layer == 1) //only layer 1 is numLock sensitive, don't bother updating numLock for layer 0
    {
        refLayerState_DH.updateNumLock(LayerState_DH::NUMLOCK_OFF);
    }

    pressScancode();
}
