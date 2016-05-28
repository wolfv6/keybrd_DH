#include <Code_NASHold.h>

void Code_NASHold::press()
{
    refLayerState_NAS.NASHold();
}

void Code_NASHold::release()
{
    refLayerState_NAS.NASUnhold();
}
