#include "Code_LayeredOperator.h"

//Update layer and numLock
//Logic is here rather than in LayerState_DH because
//calling refStateLRModf from LayerState_DH caused circular dependency.
void Code_LayeredOperator::press()
{
    if (refLayerState_DH.getActiveLayer() == TEN_KEY_ON)
    {
        layer = refLayerState_DH.getLazyNumLock(); //in TEN_KEY_ON, lazyNumLock determines layer
    }
    else
    {
        layer = refStateLRModf.getActiveLayer(); //in TEN_KEY_OFF, LRModf determines layer
    }

    if (layer == 1) //only layer 1 is numLock sensitive, don't bother updating numLock for layer 0
    {
        refLayerState_DH.updateNumLock(LayerState_DH::NUMLOCK_OFF);
    }
    
    pressCode();
}
