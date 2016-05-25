#include "Code_LayeredNav.h"

//Update layer and numLock
//Logic is here rather than in StateLayers_DH because
//calling refStateLRModf from StateLayers_DH caused circular dependency.
void Code_LayeredNav::press()
{
    layer = refStateLRModf.getActiveLayer(); //LRModf determines layer

    if (layer == 1) //only layer 1 is numLock sensitive, don't bother updating numLock for layer 0
    {
        refStateLayers_DH.updateNumLock(StateLayers_DH::NUMLOCK_OFF);
    }

    pressScancode();
}
