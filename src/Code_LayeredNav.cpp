#include "Code_LayeredNav.h"

//update layer and numLock
void Code_LayeredNav::press()
{
    layer = refStateLRModf.getActiveLayer(); //LRModf determines layer

    if (layer == 1) //only layer 1 is numLock sensitive, don't bother updating numLock for layer 0
    {
        refStateLayers.updateNumLock(StateLayers_DH::NUMLOCK_OFF);
    }

    pressScancode();
}
