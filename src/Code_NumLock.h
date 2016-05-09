#ifndef CODE_NUMLOCK_H
#define CODE_NUMLOCK_H

#include <Code.h>
#include "StateLayers_DH.h"

/* Code_NumLock calls StateLayers when pressed.
*/
class Code_NumLock : public Code
{
    private:
        StateLayers_DH& refStateLayers;
    public:
        Code_NumLock(StateLayers_DH& refStateLayers): refStateLayers(refStateLayers) {}
        virtual void press();
        virtual void release();
};
#endif
