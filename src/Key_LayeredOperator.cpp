#include "Key_LayeredOperator.h"

//Update layer and numLock
void Key_LayeredOperator::press()
{
    if (refLayerState_DH.getActiveLayer() == TEN_KEY_ON)
    {
        layerId = refLayerState_DH.getLazyNumLock(); //in TEN_KEY_ON, lazyNumLock determines layer
    }
    else
    {
        layerId = refStateLRModf.getActiveLayer(); //in TEN_KEY_OFF, LRModf determines layer
    }

    if (layerId == 1) //only layer 1 is numLock sensitive, don't bother updating numLock for layer 0
    {
        refLayerState_DH.updateNumLock(LayerState_DH::NUMLOCK_OFF);
    }

    pressCode();
}
