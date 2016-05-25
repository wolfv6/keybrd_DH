#ifndef CODE_LAYERLOCK_MFSUB_H
#define CODE_LAYERLOCK_MFSUB_H

#include <inttypes.h>
#include <Code.h>
#include "StateLayers_DH.h"

/* Code_LayerLock_MFSub calls StateLayers_DH when pressed to change activeMFSubLayer.
*/
class Code_LayerLock_MFSub : public Code
{
    private:
        const uint8_t layer;
        StateLayers_DH& refStateLayers_DH;
    public:
        Code_LayerLock_MFSub(const uint8_t layer, StateLayers_DH& refStateLayers_DH)
            : layer(layer), refStateLayers_DH(refStateLayers_DH) {}
        virtual void press();
        virtual void release();
};
#endif
