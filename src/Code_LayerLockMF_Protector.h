#ifndef CODE_LAYERLOCKMF_PROTECTOR_H
#define CODE_LAYERLOCKMF_PROTECTOR_H

#include <inttypes.h>
#include <Code.h>
#include <LayerState.h>

/* Code_LayerLockMF_Protector is similar to Code_LayerLock with getIsPressed() function.
*/
class Code_LayerLockMF_Protector : public Code
{
    private:
        const uint8_t layer;
        LayerState& refLayerState;
        bool isPressed;
    public:
        Code_LayerLockMF_Protector(const uint8_t layer, LayerState& refLayerState)
            : layer(layer), refLayerState(refLayerState) {}
        virtual void press();
        virtual void release();
        bool getIsPressed();
};
#endif
