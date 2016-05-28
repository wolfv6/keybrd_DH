#include "Code_LayeredNav.h"

//Update layer and numLock
//Logic is here rather than in LayerState_DH because
//calling refStateLRModf from LayerState_DH caused circular dependency.
void Code_LayeredNav::press()
{
    layer = refStateLRModf.getActiveLayer(); //LRModf determines layer

    if (layer == 1) //only layer 1 is numLock sensitive, don't bother updating numLock for layer 0
    {
        refLayerState_DH.updateNumLock(LayerState_DH::NUMLOCK_OFF);
    }

    pressScancode();
}
