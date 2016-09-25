keybrd_DH Library Developer's Guide
===================================
The keybrd_DH firmware is reverse engineered from the DataHand Professional II Users Guide version 1.7.8, October 2003.

The keybrd_DH layer scheme
--------------------------
**Key_Layer** objects are used to select an active layer.
When a Code_Layer object is pressed, it tells layerState_DH to update the active layer.
Key_Layer objects are:
* l_NormalLock
* l_MFLock
* l_NASHold
* l_NASLock
* l_tenKeyOff (DataHand User's Guide calls this layer "NAS")
* l_tenKeyOn
* l_mouseOn
* l_arrowOn
* t_numLock

The **layerState_DH** object keeps track of the active layer.
LayerState_DH's activeLayer is always up to date.

**Key_Layered** objects contain multiple elements, one element for each layer.
Layer ids are used like indexes to send the appropriate element.
When a Key_Layered object is pressed, it gets the active layer from a LayerState object and then sends the appropriate element.
Key_LayeredNav and Key_LayeredOperator objects consult two LayerState objects to determine which element to send.

Key_LayeredKeys class has 4 primary layers:
* NORMAL
* TEN_KEY_OFF
* TEN_KEY_ON (DataHand User's Guide describes this layer as a submode of NAS)
* MF

Other Layered classes have 2 sublayers each:
* 0
* 1

The following Layered classes have 2 sublayers each:
* Key_LayeredNumber
* Key_LayeredCodeSc_MF
* Key_LayeredScSc
* Key_LayeredDoublePressToggle
* Key_LayeredNav
* Key_LayeredOperator

Thumb keys are one-layer Code objects.

Layer objects and LayerState objects are instantiated in instantiations_codes.h
Layered objects with 2 sublayers are also instantiated in instantiations_codes.h
Key_LayeredKeys objects are instantiated in instantiations_rows.h

Object naming conventions
-------------------------
Object names are based on descriptions in DataHand User's Guide, except for "modes" which are called "layers" in the keybrd library.

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

LED names are:

    LED_L1Yellow    LED_R1Blue
    LED_L2Yellow    LED_R2Green
    LED_L3Yellow    LED_R3Yellow
    LED_L4Green     LED_R4Red

where

    L=left unit     R=right unit

and numbers are LED position on DataHand unit followed by LED color.

Class inheritance diagrams
--------------------------
The classes are found in two libraries:

    keybrd/src/
    keybrd_DH/src/

Class names tagged with '*' are located in keybrd/src/

Class inheritance diagrams of DH Rows
```
	       Row*
	         |
	       Row_DH
	       /    \
	Row_DH_uC  Row_DH_IOE

```

Class inheritance diagrams of DH LayerState, Layer, and Layered classes
```
	  StateStickyMouseButtons                 LayerStateInterface*      IndicatorLEDs
	                                               /           \
	                                       LayerState*          |
	                                        /      \            |
	                             LayerState_DH  LayerState_NAS  |
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
	 |           \                                           Key_LayeredKeys*
	 |   Key_LayeredScScBase*
	 |             \________________________________
	 |             /             \                  \
	 |   Key_LayeredScSc*  Key_LayeredNav  Key_LayeredDoublePressToggle 
	 |
	 |_____________________________________________________
	 |           \                                         \
	 |   Key_LayeredCodeScBase*                      Key_LayeredNumber
	 |             \__________________                      |
	 |             /                  \               Key_LayeredNumber_00
	 |   Key_LayeredCodeSc_MF   Key_LayeredOperator
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

Dependency diagrams
-------------------
Objects are expressed in two or more lines:

    class name on top
    object name(s) below

Class names tagged with '*' are in keybrd library.

LayerState_DH dependencies (LayerState_DH depends on these Layer objects to determine layer state)
```
	LayerState_DH
	layerState_DH
	 |
	 |_________
	 |         \
	 |      Code_LayerLock*
	 |      l_NormalLock
	 |
	 |________
	 |        \
	 |      LayerState_NAS
	 |      layerState_NAS _____________________________________________
	 |         |              \                        \                \
	 |      Code_NASHold   Code_NASLock_Protector   Code_LayerLock*  Code_LayerLock*
	 |      l_NASHold      l_NASLock                l_tenKeyOff      l_tenKeyOn
	 |
	 |_________
	 |         \
	 |      Code_LayerLockMF_Protector
	 |      l_MFLock
	 |
	 |________________________________________________________
	           \                      \                       \
	        Code_LayerLock_MFSub   Code_LayerLock_MFSub    Code_NumLock
	        l_mouseOn              l_arrowOn               t_numLock
```

Layered dependencies (Layered objects depend on LayerState objects to determine which code to send)
```
	LayerState_DH     Code_LayerState_Toggle
	layerState_DH     t_LRModf ___________________________
	    |              /    \          \                  \
	    |             /      \       Key_LayeredScSc   Key_LayeredDoublePressToggle
	    |            /        \      lr_shift           t_ctrl
	    |           /          \     rl_shift           t_alt
	    |          /            \
	    |_________/____________  \
	    |    \   /             \  \
	    |   Key_LayeredNav   Key_LayeredOperator
	    |   lr_insert         lr_plus
	    |   lr_delete         lr_asterix
	    |   lr_pageUp         lr_minus
	    |   lr_pageDown       lr_slash
	    |   lr_end
	    |
	    |__________________________________________________
	    |     \                     \                      \
	    |   Key_LayeredNumber    Key_LayeredCodeSc_MF   IndicatorLEDs
	    |   n_0 through n_9       mqA_right               indicatorLEDs
	    |   n_00                  mqA_left                 |
	    |                         mqA_down                LED
	    |                         mqA_up                  LED_L1Yellow
	Key_LayeredKeys          mb1Home                 LED_L2Yellow
	all finger keys               msA_right               LED_L3Yellow
	                              msA_left                LED_L4Green
	                              msA_down                LED_R1Blue
	                              msA_up                  LED_R2Green
	                              mb2Home                 LED_R3Yellow
	                                                      LED_R4Red
```

Protected dependencies
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
	 |   Code_LayerLock_MFSub     Code_LayerLock_MFSub     Code_NumLock
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
	                                  \        \
	     Code_LayerLockMF_Protector   Code_StickyMouseButton   Row_UnstickMouseButtons
	     l_MFLock ________________    mb_1      mb_2     _____ row_L2
	                              \    |         |      /
	                              StateStickyMouseButtons
	                              mouseButtons
```

LRModf-numLock scancode table
-----------------------------
This table was used to figure out how LRModf and numLock determine what scancodes get sent.
tests are in:

    [test_keycode.md](../examples/keybrd_DH/test_keycode.md)
    [keybrd_DH_unit_tests.ino](../examples/keybrd_DH_unit_tests/keybrd_DH_unit_tests.ino)

LRModf keys effected by numLock are followed by either numLockOn or numLockOff

```
Code_LayerState_Toggle                          LayerState_DH
LRModf left             LRModf right            isNumLocked false       isNumLocked true
ALL LAYERS --------------------------------------------------------------------------------------
Key_LayeredDoublePressToggle::press()
MODIFIERKEY_LEFT_ALT    MODIFIERKEY_RIGHT_ALT
MODIFIERKEY_LEFT_CTRL   MODIFIERKEY_RIGHT_CTRL
MODIFIERKEY_LEFT_SHIFT  MODIFIERKEY_RIGHT_SHIFT

Key_LayeredOperator::press() calls LayerState_DH::getOperatorLayer()
KEY_DELETE              KEYPAD_PERIOD numLockOff

NORMAL ------------------------------------------------------------------------------------------
Key_LayeredOperator::press() calls LayerState_DH::getOperatorLayer()
KEY_SLASH               KEYPAD_SLASH

TEN_KEY_OFF -------------------------------------------------------------------------------------
Key_LayeredOperator::press() calls LayerState_DH::getOperatorLayer()
KEY_SLASH               KEYPAD_SLASH numLockOff
KEY_MINUS               KEYPAD_MINUS numLockOff
KEY_8+shift             KEYPAD_ASTERIX numLockOff
KEY_EQUAL+shift         KEYPAD_PLUS numLockOff

TEN_KEY_ON --------------------------------------------------------------------------------------
                                                Key_LayeredOperator::press() calls LayerState_DH::getOperatorLayer()
                                                KEY_SLASH               KEYPAD_SLASH numLockOff
                                                KEY_MINUS               KEYPAD_MINUS numLockOff
                                                KEY_8+shift             KEYPAD_ASTERIX numLockOff
                                                KEY_EQUAL+shift         KEYPAD_PLUS numLockOff

                                                Key_LayeredNumber::press() calls LayerState_DH::getNumberLayer()
                                                KEY_0..9                KEYPAD_0..9 numLockOn

MF ----------------------------------------------------------------------------------------------
Key_LayeredNav::press() calls LayerState_DH::getNavLayer()
KEY_INSERT              KEYPAD_0 numLockOff
KEY_PAGE_UP             KEYPAD_9 numLockOff
KEY_PAGE_DOWN           KEYPAD_6 numLockOff
KEY_PAGE_END            KEYPAD_1 numLockOff

                                                Key_LayeredCodeSc_MF::press() calls layerState_DH.getActiveMFSubLayer()
                                                MF, arrowOn, left hand, arrows are keypad
                                                            KEYPAD_2 numLockOff
                                                            KEYPAD_4 numLockOff
                                                            KEYPAD_6 numLockOff
                                                            KEYPAD_8 numLockOff

 ------------------------------------------------------------------------------------------------
```
Use lazy synNumLock because if typing keypad numbers is faster than USB keyboard_leds,
 then numLock will not synchronize with isNumLocked
This could happen when simultaneously pressing multiple Key_LayeredNumber

<br>
<a rel="license" href="https://creativecommons.org/licenses/by/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://licensebuttons.net/l/by/4.0/88x31.png" /></a><br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">keybrd tutorial</span> by <a xmlns:cc="https://creativecommons.org/ns" href="https://github.com/wolfv6/keybrd" property="cc:attributionName" rel="cc:attributionURL">Wolfram Volpi</a> is licensed under a <a rel="license" href="https://creativecommons.org/licenses/by/4.0/">Creative Commons Attribution 4.0 International License</a>.<br />Permissions beyond the scope of this license may be available at <a xmlns:cc="https://creativecommons.org/ns" href="https://github.com/wolfv6/keybrd/issues/new" rel="cc:morePermissions">https://github.com/wolfv6/keybrd/issues/new</a>.

