
TEST W/O NUMLOCK
lock LED:
layer LED:              R2Green R1Blue     R1Blue                  R3Yellow
sublayer LED:                                           R4Red      L2Yellow off
layer:                  NORMAL NAS         NAS                     MF
sublayer:                      TEN_KEY_OFF TEN_KEY_OFF  TEN_KEY_ON 0        1
input:                  Normal NAS         NASLock      10KeyOn    MouseOn  ArrowOn

TEST WITH NUMLOCK
lock LED:       L3Yellow                                                              off
layer LED:              R2Green R1Blue     R1Blue                  R3Yellow
sublayer LED:                                           R4Red      L2Yellow off
layer:                  NORMAL NAS         NAS                     MF
sublayer:                      TEN_KEY_OFF TEN_KEY_OFF  TEN_KEY_ON 0        1
input:          NumLock Normal NAS         NASLock      10KeyOn    MouseOn  ArrowOn  NumLock

TEST LOCKS
lock LED:       L1Green        off      L4Yellow   off
input:          capsLock shift capsLock scrollLock scrollLock 

Scroll lock LED removed, explanation in Code_LEDLock.cpp

* For Modf, 3 LEDs on L or R side blink 4 times in 2 seconds

    MODE        LEFT INDICATOR LIGHT    LAYERS
    ----        --------------------    ------
    ScrollLock  yellow     *
    NumLock     yellow     *D11 teensy onboard LED
    MouseOn     yellow     *            mouse on (arrow off)
    CapsLock    green

    MODE        RIGHT INDICATOR LIGHT   LAYERS
    ----        ---------------------   ------
    NAS         blue       *            TEN_KEY_OFF or TEN_KEY_ON
    Normal      green      *D11         NORMAL
    MF          yellow     *            MF
    10-Key      red                     TEN_KEY_ON

test IndicatorLEDs::restoreBlinkingLEDs() =====================
press L/RModf with one LED at a time, should blink first 3 LEDs

LEFT UNIT LEDs                          RESULT
    NumLock      2 yellow
    MF+arrow MF+NumLock     L/RModf     pass

    MouseOn      3 yellow
    MF+mouse                L/RModf     pass

    CapsLock     4 green
    MF+arrow CapsLock       L/RModf     pass

RIGHT UNIT LEDs                         RESULT
    MF           3 yellow
    MF                      L/RModf     pass
