/* keybrd_DH.ino DataHand QWERTY layout
for DodoHand project on https://github.com/dodohand/dodohand
and https://geekhack.org/index.php?topic=41422.0

If this sketch does not compile it might be because it isn't up-to date with the keybrd library.
To have the sketch updated, please submit an issue: https://github.com/wolfv6/keybrd/issues

code is in mainSketch.cpp so that Arduino IDE does not mangle directives
(directives are for trouble shooting DodoHand)
 https://github.com/arduino/Arduino/issues/1841
 http://www.gammon.com.au/forum/?id=12625
*/
// ================ INCLUDES ===================
//Code
#include <Code_Shift.h>
//#include <Code_AutoShift.h>
#include <Code_Sc.h>
#include <Code_ScS.h>
#include <Code_Null.h>
#include <Code_LEDLock.h>

//Mouse
#include <StateStickyMouseButtons.h>
#include <Code_StickyMouseButton.h>
#include <Code_Mouse_Slow.h>
#include <Code_Mouse_Quick.h>

//StateLayers
#include <StateLayers_DH.h>
#include <StateLayers_NAS.h>
#include <Code_NASHold.h>
#include <Code_NASLock_Protector.h>
//#include <IndicatorLEDs.h>

//Layer
#include <Code_LayerLock.h>
#include <Code_LayerLockMF_Protector.h>
#include <Code_LayerState_Toggle.h>

//Layered
#include <Key_LayeredKeysArray.h>
#include <Code_LayeredCodeSc.h>
#include <Code_LayeredNumber.h>
#include <Code_LayeredNumber_00.h>
#include <Code_LayeredDoublePressToggle.h>

//protected
#include <Code_Protected_ByMFLock.h>
#include <Code_Protected_ByNASLock.h>
#include <Code_DoublePressProtected.h>

//back end
#include <RowPort_AVR_Optic.h>
#include <ColPort_AVR.h>
#include <LED_AVR.h>

#include <IOExpanderPort.h>
#include <RowPort_PCA9655E.h>
#include <ColPort_PCA9655E.h>
#include <LED_PCA9655E.h>

#include <Wire.h>
#include <Row_DH.h>
#include <Matrix.h>
#include <MouseMove.h>

#include <Debug.h>
