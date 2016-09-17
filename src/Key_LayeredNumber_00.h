#ifndef KEY_LAYEREDNUMBER_00_H
#define KEY_LAYEREDNUMBER_00_H
#include <Arduino.h>
#include <inttypes.h>
#include "Key_LayeredNumber.h"
#include "LayerState_DH.h"

/* Class Key_LayeredNumber_00 sends double zero ("00" as seen on old adding machines).
*/
class Key_LayeredNumber_00 : public Key_LayeredNumber
{
    public:
        Key_LayeredNumber_00(): Key_LayeredNumber(KEY_0) { }
        virtual void press();
};
#endif
