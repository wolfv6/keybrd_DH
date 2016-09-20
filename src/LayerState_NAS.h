#ifndef CODE_LAYERSTATE_NAS_H
#define CODE_LAYERSTATE_NAS_H

#include <inttypes.h>
#include <LayerState.h>
/* LayerState for layers TEN_KEY_ON and TEN_KEY_OFF.
Remembers activeNASLayer for next time NAS is active layer again.
Passes activeNASLayer and persistence to LayerState_DH.
*/
class LayerState_NAS : public LayerState
{
    private:
        enum persistence { locked, held };
        bool persistence;
        uint8_t activeNASLayer;                 //TEN_KEY_ON or TEN_KEY_OFF
        LayerState& refLayerState_DH;
        void setActiveDHLayer();
    public:
        LayerState_NAS(uint8_t activeNASLayer, LayerState& refLayerState_DH)
            : activeNASLayer(activeNASLayer), refLayerState_DH(refLayerState_DH) {}
        void NASLock();
        void NASHold();
        void NASUnhold();
        void lock(const uint8_t layerId);
};
#endif

