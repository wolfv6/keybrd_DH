#ifndef CODE_NASHOLD_H
#define CODE_NASHOLD_H

#include <Code.h>
#include "StateLayers_NAS.h"

/* Code_NASHold is similar to Code_LayerHold
*/
class Code_NASHold : public Code
{
    private:
        StateLayers_NAS& refStateLayers_NAS;
    public:
        Code_NASHold(StateLayers_NAS& refStateLayers_NAS)
            : refStateLayers_NAS(refStateLayers_NAS) {}
        virtual void press();
        virtual void release();
};
#endif
