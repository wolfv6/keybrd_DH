#include "Code_LayerLock_MFSub.h"

void Code_LayerLock_MFSub::press()
{
    refLayerState_DH.lockMFSubLayer(layer);
}

void Code_LayerLock_MFSub::release()
{
}
