#include "Code_LayeredOperator.h"

void Code_LayeredOperator::press()
{
    layer = refStateLayers.getOperatorLayer();
    pressCode();
}
