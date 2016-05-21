#include "Code_LayerState_Toggle.h"

/* Class-design discussion:
Code_LayerState_Toggle contains its own state
 because there is no reason for another Code_Layer to change toggle layers.
*/
void Code_LayerState_Toggle::press()
{
    if (activeLayer == 1)
    {
        activeLayer = 0;
        blinker0.startBlinking();
}
    else
    {
        activeLayer = 1;
        blinker1.startBlinking();
    }
}

void Code_LayerState_Toggle::release()
{
}

uint8_t Code_LayerState_Toggle::getActiveLayer()
{
    return activeLayer;
}
