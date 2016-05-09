#ifndef CODE_LAYERSTATE_NAS_H
#define CODE_LAYERSTATE_NAS_H

#include <inttypes.h>
#include <StateLayers.h>
/* StateLayers for layers TEN_KEY_ON and TEN_KEY_OFF.
Remembers activeNASLayer for next time NAS is active layer again.
Passes activeNASLayer and persistence to StateLayers_DH.
*/
class StateLayers_NAS : public StateLayers
{
    private:
        enum persistence { locked, held };
        bool persistence;
        uint8_t activeNASLayer;                 //TEN_KEY_ON or TEN_KEY_OFF
        StateLayers& refStateLayers_DH;
        void setActiveDHLayer();
    public:
        StateLayers_NAS(uint8_t activeNASLayer, StateLayers& refStateLayers_DH)
            : activeNASLayer(activeNASLayer), refStateLayers_DH(refStateLayers_DH) {}
        void NASLock();
        void NASHold();
        void NASUnhold();
        void lock(const uint8_t layer);
};
#endif

