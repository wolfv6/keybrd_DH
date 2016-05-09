#include "Code_LayerState_Toggle.h"

/* Class-design discussion:
Code_LayerState_Toggle contains its own state
 because there is no reason for another Code_Layer to change toggle layers.
*/
void Code_LayerState_Toggle::press()
{
    activeLayer = !activeLayer;
}

void Code_LayerState_Toggle::release()
{
}

uint8_t Code_LayerState_Toggle::getActiveLayer()
{
    return activeLayer;
}
