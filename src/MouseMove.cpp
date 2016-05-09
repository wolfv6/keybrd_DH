#include "MouseMove.h"

void MouseMove::send()
{
    if (scansSinceLastMouseMove > SCANS_PER_MOUSE_MOVE)
    {
        scansSinceLastMouseMove = 0;
        Code_MouseSpeed::mouseMove();
    }
    scansSinceLastMouseMove++;
}
