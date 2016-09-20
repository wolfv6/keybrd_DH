#include "Key_LayeredDoublePressToggle.h"

void Key_LayeredDoublePressToggle::press()
{
    bool layerState = refLayerState.getActiveLayer();

    if (activeLayer != layerState)      //if Modf activeLayer changed
    {
        activeLayer = layerState;
        layerId = layerState;             //update layerId
    }
    else                                //if Modf activeLayer has not changed
    {
        if ( !otherWasPressed )         //if no other key was pressed since this code was pressed
        {
            layerId = !layerId;             //toggle layerId
        }
    }
    isOther = false;
    otherWasPressed = false;

    pressScancode();
}

void Key_LayeredDoublePressToggle::prevent_toggle()
{
    if (isOther)
    {
        otherWasPressed = true;                 //prevent toggle
    }
    isOther = true;                             //reset to default - keys are other keys
}
