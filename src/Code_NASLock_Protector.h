#ifndef CODE_NASLOCK_PROTECTOR_H
#define CODE_NASLOCK_PROTECTOR_H

#include <inttypes.h>
#include <Code.h>
#include <StateLayers_NAS.h>

/* Code_NASLock_Protector is similar to Code_LayerLock with getIsPressed() function.
*/
class Code_NASLock_Protector : public Code
{
    private:
        StateLayers_NAS& refStateLayers_NAS;
        bool isPressed;
    public:
        Code_NASLock_Protector(StateLayers_NAS& refStateLayers_NAS)
            : refStateLayers_NAS(refStateLayers_NAS) {}
        virtual void press();
        virtual void release();
        bool getIsPressed();
};
#endif
