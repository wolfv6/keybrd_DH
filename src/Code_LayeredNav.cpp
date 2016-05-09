#include "Code_LayeredNav.h"

void Code_LayeredNav::press()
{
    layer = refStateLayers.getNavLayer();
    pressScancode();
}
