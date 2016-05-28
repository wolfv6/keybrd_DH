#include <LayerState_NAS.h>

// ===== functions called from Code_NASHold and Code_NASLock_Protector =======
void LayerState_NAS::NASLock()
{
    persistence = locked;
    setActiveDHLayer();
}

void LayerState_NAS::NASHold()
{
    persistence = held;
    setActiveDHLayer();
}

void LayerState_NAS::NASUnhold()
{
    refLayerState_DH.unhold(activeNASLayer);
}

// =================== function called from Code_LayerLock ===================
void LayerState_NAS::lock(const uint8_t layer)
{
    activeNASLayer = layer;
    setActiveDHLayer();
}

// ================================ private ==================================
void LayerState_NAS::setActiveDHLayer()
{
    if (persistence == held)
    {
        refLayerState_DH.hold(activeNASLayer);
    }
    else
    {
        refLayerState_DH.lock(activeNASLayer);
    }
}
