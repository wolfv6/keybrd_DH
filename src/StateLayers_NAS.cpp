#include <StateLayers_NAS.h>

// ===== functions called from Code_NASHold and Code_NASLock_Protector =======
void StateLayers_NAS::NASLock()
{
    persistence = locked;
    setActiveDHLayer();
}

void StateLayers_NAS::NASHold()
{
    persistence = held;
    setActiveDHLayer();
}

void StateLayers_NAS::NASUnhold()
{
    refStateLayers_DH.unhold(activeNASLayer);
}

// =================== function called from Code_LayerLock ===================
void StateLayers_NAS::lock(const uint8_t layer)
{
    activeNASLayer = layer;
    setActiveDHLayer();
}

// ================================ private ==================================
void StateLayers_NAS::setActiveDHLayer()
{
    if (persistence == held)
    {
        refStateLayers_DH.hold(activeNASLayer);
    }
    else
    {
        refStateLayers_DH.lock(activeNASLayer);
    }
}
