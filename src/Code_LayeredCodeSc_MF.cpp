#include "Code_LayeredCodeSc_MF.h"

void Code_LayeredCodeSc_MF::press()
{
    layer = refLayerState_DH.getActiveMFSubLayer();
    pressCode();
}
