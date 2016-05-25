#ifndef CODE_LAYERLOCK_SUBMF_H
#define CODE_LAYERLOCK_SUBMF_H

#include <inttypes.h>
#include <Code.h>
#include "StateLayers_DH.h"

/* Code_LayerLock_SubMF calls StateLayers_DH when pressed to change activeSubMFLayer.
*/
class Code_LayerLock_SubMF : public Code
{
    private:
        const uint8_t layer;
        StateLayers_DH& refStateLayers_DH;
    public:
        Code_LayerLock_SubMF(const uint8_t layer, StateLayers_DH& refStateLayers_DH)
            : layer(layer), refStateLayers_DH(refStateLayers_DH) {}
        virtual void press();
        virtual void release();
};
#endif
