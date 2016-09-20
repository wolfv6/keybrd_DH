#include "Key_LayeredCodeSc_MF.h"

void Key_LayeredCodeSc_MF::press()
{
    layerId = refLayerState_DH.getActiveMFSubLayer();
    pressCode();
}
