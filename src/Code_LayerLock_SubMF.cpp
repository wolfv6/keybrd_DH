#include "Code_LayerLock_SubMF.h"

void Code_LayerLock_SubMF::press()
{
    refStateLayers_DH.lockSubMFLayer(layer);
}

void Code_LayerLock_SubMF::release()
{
}
