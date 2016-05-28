#ifndef CODE_NASHOLD_H
#define CODE_NASHOLD_H

#include <Code.h>
#include "LayerState_NAS.h"

/* Code_NASHold is similar to Code_LayerHold
*/
class Code_NASHold : public Code
{
    private:
        LayerState_NAS& refLayerState_NAS;
    public:
        Code_NASHold(LayerState_NAS& refLayerState_NAS)
            : refLayerState_NAS(refLayerState_NAS) {}
        virtual void press();
        virtual void release();
};
#endif
