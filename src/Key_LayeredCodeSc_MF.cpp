#include "Key_LayeredCodeSc_MF.h"

void Key_LayeredCodeSc_MF::press()
{
    layer = refLayerState_DH.getActiveMFSubLayer();
    pressCode();
}
