#include "Code_LayeredOperator.h"

//update layer and numLock
void Code_LayeredOperator::press()
{
    if (refStateLayers.getActiveLayer() == TEN_KEY_ON)
    {
        layer = refStateLayers.getLazyNumLock(); //in TEN_KEY_ON, lazyNumLock determines layer
    }
    else
    {
        layer = refStateLRModf.getActiveLayer(); //in TEN_KEY_OFF, LRModf determines layer
    }

    if (layer == 1) //only layer 1 is numLock sensitive, don't bother updating numLock for layer 0
    {
        refStateLayers.updateNumLock(StateLayers_DH::NUMLOCK_OFF);
    }
    
    pressCode();
}
