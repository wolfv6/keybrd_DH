#include <Code_NASHold.h>

void Code_NASHold::press()
{
    refStateLayers_NAS.NASHold();
}

void Code_NASHold::release()
{
    refStateLayers_NAS.NASUnhold();
}
