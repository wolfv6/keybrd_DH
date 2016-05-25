#include "Code_LayeredCodeSc_MF.h"

void Code_LayeredCodeSc_MF::press()
{
    layer = refStateLayers_DH.getActiveMFSubLayer();
    pressCode();
}
