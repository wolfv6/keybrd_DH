#ifndef LAYERSTATE_MF_H
#define LAYERSTATE_MF_H

#include <Arduino.h>
#include <inttypes.h>
#include <StateLayers.h>
#include <IndicatorLEDs.h>

/* StateLayers for DH sub-layers: mouseOn and arrowOn
StateLayers is part of a layer scheme explained in keybrd_DH/doc/keybrd_DH_library_developer_guide.md
When pressed, Code_LayerLock objects call StateLayers_MF function lock().
When pressed, Layered objects call StateLayers_MF function getActiveLayer().
*/
class StateLayers_MF : public StateLayers
{
    private:
        IndicatorLEDs& refIndicatorLEDs;
        virtual void setActiveLayer(const uint8_t layer);
    public:
        StateLayers_MF(IndicatorLEDs& refIndicatorLEDs) : refIndicatorLEDs(refIndicatorLEDs) {}
};
#endif
