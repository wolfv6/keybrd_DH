#include <Code_NumLock.h>

void Code_NumLock::press()
{
    refLayerState_DH.toggleLazyNumLock();
}

void Code_NumLock::release()
{
}
