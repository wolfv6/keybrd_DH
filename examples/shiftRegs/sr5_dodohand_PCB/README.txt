# sr5_dodohand_PCB overview
dodohand_PCB is a schematic for the full 52-key circuit used to design the DodoHand PCB.
dodohand_PCB is similar to dodohand_BB with the addition of:
* more keys
* indicator LEDs
* strobe buffer

# dodohand_PCB.sch
This is the root schematic for the DodoHand PCB.

Teensy LC controls the left and right hands.

The schematic for left and right hand keys is in row.sch.

# row.sch
This is a schematic for one row of shift registers with 26 keys.
Four SN74HC165N shift registers are daisy chained together for a total of 32 shift registers.
Refer to [tutorial_4b_split_keyboard_with_shift_registers.md](https://github.com/wolfv6/keybrd/blob/master/tutorials/tutorial_4b_split_keyboard_with_shift_registers.md) for how to daisy chain 74HC165s.

# shiftReg_8keys.sch
This is a schematic for one SN74HC165N and 8 keys.

SN74HC165N input pins are connected to pull-down resistor arrays.

Each "2keys" rectangle contains two keys.
Each key is a photointerrupter consisting of an IR LED and photo transistor.

# shiftReg_2keys.sch
Since row.sch has 26 keys and 32 shift registers, the last SN74HC165N only has 2 keys.
The last 6 input pins are grounded.

