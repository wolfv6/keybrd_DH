#ifndef CODE_NUMLOCK_H
#define CODE_NUMLOCK_H

#include <Code.h>
#include "LayerState_DH.h"

/* Code_NumLock calls LayerState when pressed.
*/
class Code_NumLock : public Code
{
    private:
        LayerState_DH& refLayerState_DH;
    public:
        Code_NumLock(LayerState_DH& refLayerState_DH): refLayerState_DH(refLayerState_DH) {}
        virtual void press();
        virtual void release();
};
#endif
