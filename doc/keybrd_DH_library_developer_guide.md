keybrd_DH Library Developer's Guide
===================================
The keybrd_DH library is an extension of the [keybrd library](https://github.com/wolfv6/keybrd) for emulating the DataHand keyboard.

## Code_Layer class naming conventions
Code_Layer class names are concatenations of "Code_", layer, and persistence.
Persistence is one of:
* "Lock" - layer remains active after the layer key is released
* "Hold" - layer is active for as long as layer key is held down

## Object naming conventions
Object names are based on descriptions in DataHandProIIUserGuide.pdf, except for "modes" which are called "layers" in the keybrd library.

CODE PREFIXES

    l_   layer
    lr_  layered toggled left-right by LRModf
    mb_  mouse button
    mq_  mouse quick
    ms_  mouse slow
    mqA_ layered mouse-quick and arrow
    msA_ layered mouse-slow and arrow
    n_   number
    o_   lock for o_capsLock o_scrollLock
    p_   protected
    s_   scancode
    t_   toggle

## Class diagrams
These diagrams depict all StateLayers, Layered, and Layered classes used in DH.
The classes are found in two libraries:

    keybrd/src/
    keybrd_DH/src/

*class names tagged with '*' are located in core keybrd library

Class inheritance diagrams
```
	Row*        StateStickyMouseButtons           StateLayersInterface*
	  |                                            /           \
	Row_DH                                 StateLayers*         |
	                                        /      \            |
	                           StateLayers_DH  StateLayers_NAS  |
	Code*                                                       |
	 |____________________________________________________      |
	 |     \                 \                            \     |
	 |   Code_LayerLock*   Code_LayerLockMF_Protector   Code_LayerState_Toggle
	 |
	 |________________________________________________
	 |       \              \                         \
	 |   Code_NASHold   Code_NASLock_Protector   Code_NumLock
	 |
	 |___________
	 |           \                                           Key_LayeredKeysArray*
	 |   Code_LayeredScScBase*
	 |             \________________________________
	 |             /             \                  \
	 |   Code_LayeredScSc*  Code_LayeredNav  Code_LayeredDoublePressToggle 
	 |
	 |_____________________________________________________
	 |           \                                         \
	 |   Code_LayeredCodeScBase*                      Code_LayeredNumber
	 |             \________________                        |
	 |             /                \                 Code_LayeredNumber_00
	 |   Code_LayeredCodeSc*   Code_LayeredOperator
	 |
	 |________________________________________
	 |                          \             \
	 |                    Code_Protected   Code_DoublePressProtected
	 |                     /          \
	 |   Code_Protected_ByNASLock  Code_Protected_ByMFLock
	 |
	 |_________________________________________________
	 |               \                                 \
	 |         Code_MouseSpeed     MouseMove    Code_StickyMouseButton
	 |         /             \
	 |   Code_Mouse_Quick  Code_Mouse_Slow
	 |
	 |_________________
	       \           \
	     Code_Sc*   Code_AutoShift*
	                    |
	                Code_ScS*

```

## Association diagrams
Objects are expressed in two or more lines:

    class name on top
    object name(s) below

*class names tagged with '*' are in keybrd library

state, layers, and layered associations
```
	                        StateLayers_DH
	            ___________ stateLayer_DH ____________
	           /                |                     \
	Code_LayerLock*             |              Code_LayerLockMF_Protector
	l_NormalLock                |              l_MFLock
	                        StateLayers_NAS
	            ___________ stateLayer_NAS _____________________
	           /              /                \                \
	Code_NASHold   Code_NASLock_Protector   Code_LayerLock*  Code_LayerLock*
	l_NASHold      l_NASLock                l_tenKeyOff      l_tenKeyOn


	                        StateLayers*
	                        stateLayer_MF
	                        /         \
	              Code_LayerLock*   Code_LayerLock*
	              l_mouseOn         l_arrowOn


	               Code_NumLock    Code_LayerState_Toggle
	               t_numLock       t_LRModf ________________________
	                    \             /        \ \                \ \   
	                     \           /       Code_LayeredScSc   Code_LayeredDoublePressToggle
	                      \         /        lr_shift           t_ctrl
	                       \       /         rl_shift           t_alt
	                     StateLayers_DH     
	     _______________ stateLayer_DH _____________
	    /////               ||||                  \ \ 
	Code_LayeredNav      Code_LayeredOperator   Code_LayeredNumber
	lr_insert            lr_plus                n_0 through n_9
	lr_delete            lr_asterix             n_00
	lr_pageUp            lr_minus
	lr_pageDown          lr_slash
	lr_end

```

protected objects
```
    Code_NASLock_Protector
	l_NASLock.isPressed()
	 |
	 |_______________________________________________________
	     \                         \                         \
        Code_Protected_ByNASLock  Code_Protected_ByNASLock  Code_Protected_ByNASLock
	    p_tenKeyOn                p_tenKeyOff               pNAS_numLock
	      |                         |                         |
	    Code_LayerLock*           Code_LayerLock*           Code_NumLock
	    l_tenKeyOn                l_tenKeyOff               t_numLock

    Code_LayerLockMF_Protector
	l_MFLock.isPressed()
	 |
	 |______________________________________________________
	 |    \                        \                        \
     |   Code_Protected_ByMFLock  Code_Protected_ByMFLock  Code_Protected_ByMFLock
	 |   p_mouseOn                p_arrowOn                pMF_numLock
	 |     |                        |                        |
	 |   Code_LayerLock*          Code_LayerLock*          Code_NumLock
	 |   l_mouseOn                l_arrowOn                t_numLock
	 |
	 |______________________________________________________________________
	 |    \                           \                          \\\\\\\\\\\\
     |   Code_Protected_ByMFLock     Code_Protected_ByMFLock     Code_Protected_ByMFLock
	 |   p_printscreen               p_Modf                      p_F1 through p_F12
	 |     |                           |                          ||||||||||||
	 |   Code_Sc*                    Code_LayerState_Toggle      Code_Sc
	 |   s_printscreen               t_LRModf                    s_F1 through s_F12
	 |
	 |___________________________
	 |        \                  \
	 |   Code_Mouse_Quick   Code_Mouse_Slow
	 |   mqA_up __       __ ms_up
	 |            \     /
	 |           MouseMove
	 |           mouseMove
	 |
	 |_________________________________________
	           \                      \        \
	     Code_LayerLockMF_Protector   Code_StickyMouseButton   Row_UnstickMouseButtons
	     l_MFLock ________________    mb_1      mb_2     _____ row_L2
	                              \    |         |      /
	                              StateStickyMouseButtons
	                              mouseButtons

```

## LRModf-numLock scancode table
This table was used to figure out how LRModf and numLock determine what scancodes get sent.
tests are in:

    [test_keycode.md](../examples/keybrd_DH/test_keycode.md)
    [keybrd_DH_unit_tests.ino](../examples/keybrd_DH_unit_tests/keybrd_DH_unit_tests.ino)

LRModf keys effected by numLock are followed by either numLockOn or numLockOff

```
Code_LayerState_Toggle                          StateLayers_DH
LRModf left             LRModf right            isNumLocked false       isNumLocked true
ALL LAYERS --------------------------------------------------------------------------------------
Code_LayeredDoublePressToggle::press()
MODIFIERKEY_LEFT_ALT    MODIFIERKEY_RIGHT_ALT
MODIFIERKEY_LEFT_CTRL   MODIFIERKEY_RIGHT_CTRL
MODIFIERKEY_LEFT_SHIFT  MODIFIERKEY_RIGHT_SHIFT

Code_LayeredOperator::press() calls StateLayers_DH::getOperatorLayer()
KEY_DELETE              KEYPAD_PERIOD numLockOff

NORMAL ------------------------------------------------------------------------------------------
Code_LayeredOperator::press() calls StateLayers_DH::getOperatorLayer()
KEY_SLASH               KEYPAD_SLASH

TEN_KEY_OFF -------------------------------------------------------------------------------------
Code_LayeredOperator::press() calls StateLayers_DH::getOperatorLayer()
KEY_SLASH               KEYPAD_SLASH numLockOff
KEY_MINUS               KEYPAD_MINUS numLockOff
KEY_8+shift             KEYPAD_ASTERIX numLockOff
KEY_EQUAL+shift         KEYPAD_PLUS numLockOff

TEN_KEY_ON --------------------------------------------------------------------------------------
                                                Code_LayeredOperator::press() calls StateLayers_DH::getOperatorLayer()
                                                KEY_SLASH               KEYPAD_SLASH numLockOff
                                                KEY_MINUS               KEYPAD_MINUS numLockOff
                                                KEY_8+shift             KEYPAD_ASTERIX numLockOff
                                                KEY_EQUAL+shift         KEYPAD_PLUS numLockOff

                                                Code_LayeredNumber::press() calls StateLayers_DH::getNumberLayer()
                                                KEY_0..9                KEYPAD_0..9 numLockOn

MF ----------------------------------------------------------------------------------------------
Code_LayeredNav::press() calls StateLayers_DH::getNavLayer()
KEY_INSERT              KEYPAD_0 numLockOff
KEY_PAGE_UP             KEYPAD_9 numLockOff
KEY_PAGE_DOWN           KEYPAD_6 numLockOff
KEY_PAGE_END            KEYPAD_1 numLockOff

                                                Code_LayeredCodeSc::press() calls stateLayers_MF.getActiveLayer()
                                                MF, arrowOn, left hand, arrows are keypad
                                                            KEYPAD_2 numLockOff
                                                            KEYPAD_4 numLockOff
                                                            KEYPAD_6 numLockOff
                                                            KEYPAD_8 numLockOff

 ------------------------------------------------------------------------------------------------
```
Use lazy synNumLock because if typing keypad numbers is faster than USB keyboard_leds,
 then numLock will not synchronize with isNumLocked
This could happen when simultaneously pressing multiple Code_LayeredNumber
