#ifndef CODE_NASLOCK_PROTECTOR_H
#define CODE_NASLOCK_PROTECTOR_H

#include <inttypes.h>
#include <Code.h>
#include <LayerState_NAS.h>

/* Code_NASLock_Protector is similar to Code_LayerLock with getIsPressed() function.
*/
class Code_NASLock_Protector : public Code
{
    private:
        LayerState_NAS& refLayerState_NAS;
        bool isPressed;
    public:
        Code_NASLock_Protector(LayerState_NAS& refLayerState_NAS)
            : refLayerState_NAS(refLayerState_NAS) {}
        virtual void press();
        virtual void release();
        bool getIsPressed();
};
#endif
