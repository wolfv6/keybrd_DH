#ifndef CODE_LAYERLOCK_MFSUB_H
#define CODE_LAYERLOCK_MFSUB_H

#include <inttypes.h>
#include <Code.h>
#include "LayerState_DH.h"

/* Code_LayerLock_MFSub calls LayerState_DH when pressed to change activeMFSubLayer.
*/
class Code_LayerLock_MFSub : public Code
{
    private:
        const uint8_t layer;
        LayerState_DH& refLayerState_DH;
    public:
        Code_LayerLock_MFSub(const uint8_t layer, LayerState_DH& refLayerState_DH)
            : layer(layer), refLayerState_DH(refLayerState_DH) {}
        virtual void press();
        virtual void release();
};
#endif
