integration test left-right and KEYPAD duplicate keys.  Output is keycodes.
keycodes can be read using command 'xev' in the Linux terminal.

# ctrl alt
DataHand User's Guide page 40 - Switching Left and Right Function for Duplicate Keys
LRModf is Protected_ByMFLock

from MF
input:      ctrl =  ctrl = MF+LRMof ctrl =  ctrl alt MF+LRModf ctrl =  ctrl ctrl ctrl alt
keycode:    37   21 37   21         105  21 105  108           37   21 37   105  37   64                    pass 4/26/16

# number keys 
numLock is on TEN_KEY_OFF.  NumLock effects the TEN_KEY_ON number keys
numLock is Protected_ByMFLock and Protected_ByNASLock

layer:                         TEN_KEY_OFF          TEN_KEY_ON             TEN_KEY_ON             TEN_KEY_ON
keyness:                       KEY                  KEY                    KEYPAD                 KEY
input:      NASLock+tenKeyOff  2  NASLock+tenKeyOn  2  MF+numLock NASLock  2  MF+numLock NASLock  2
keycode:                       11                   11                     77,88                  77,11     pass 4/26/16
comment:    numLock keycode (77) never prints, but the correct number 2 keycodes (11 and 88) are printed

# LRModf and numLock
Run the following tests twice: once with Modf Left and once with Modf Right
LRModf is Code_Protected_ByMFLock

Normal mode
input:      alt ctrl shift delete             /             
keycode L:  64  37   50    119                61                                pass 4/26/16
keycode R:  108 105  62    91                 106                               pass 4/26/16

NAS tenKeyOff                                               numLockOff  numbLockOn
input:      alt ctrl shift delete    +  *  -  /             7           7
keycode L:  64  37   50    119       21 17 20 61            16          16      pass 4/26/16
keycode R:  108 105  62    91        86 63 82 106           16          16      pass 4/26/16

NAS tenKeyOn numLockOff
input:      alt ctrl shift delete    +  *  -  /     4
keycode L:  64  37   50    119       21 17 20 61    13                          pass 4/26/16
keycode R:  108 105  62    91        21 17 20 61    13                          pass 4/26/16

NAS tenKeyOn numLockOn
input:      alt ctrl shift delete    +  *  -  /     4
keycode L:  64  37   50    119       86 63 82 106   83                          pass 4/26/16
keycode R:  108 105  62    91        86 63 82 106   83                          pass 4/26/16

MF mode
input:      alt ctrl shift delete   ins pageUp PageDown End 
keycode L:  64  37   50    119      118 112    117      115                     pass 4/26/16
keycode R:  108 105  62    91       90  81     89       87                      pass 4/26/16

# enter keys
from MF mode
input:      left thumb     left middle     right ring (only has 101-keyboard mode)
keycode:    36             36              104                                 pass 4/26/16

# arrow keys
            NAS-tenKeyOn    MF-arrowOn      MF-arrowOn
            left hand       left hand       right hand
input:      up arrow        up arrow        up arrow
keycode:    111             80              111                                 pass 4/26/16
