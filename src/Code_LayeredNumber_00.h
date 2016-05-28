#ifndef CODE_LAYEREDNUMBER_00_H
#define CODE_LAYEREDNUMBER_00_H
#include <Arduino.h>
#include <inttypes.h>
#include "Code_LayeredNumber.h"
#include "LayerState_DH.h"

/* Class Code_LayeredNumber_00 sends double zero ("00" as seen on old adding machines).
*/
class Code_LayeredNumber_00 : public Code_LayeredNumber
{
    public:
        Code_LayeredNumber_00(): Code_LayeredNumber(KEY_0) { }
        virtual void press();
};
#endif
