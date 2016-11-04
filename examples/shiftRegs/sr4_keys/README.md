# sr4_keys overview
dodohand_BB is a schematic for a proof-of-concept keyboard small enough to fit on a breadboard.
It has left and right shift registers just like 52-key DodoHand.

# dodohand_BB.sch
This is the root schematic of the breadboard.

Teensy LC controls the left and right hands.
The schematic for left and right hands is in row.sch.

# row_tactile.sch
?? use just one large schematic instead of hierarchical schematic?
    because there is nothing to reuse

# row_photointerrupter.sch
This is a schematic for one shift register with 2 keys.

A 20mA Teensy pin strobes the IR LEDs.

The "2keys" rectangle contains two keys.
Each key is a photointerrupter consisting of an IR LED and photo transistor.

Two SN74HC165N input pins are connected to pull-down resistors and photo transistors.
Unused input pins are grounded.

The keyboard has two rows of shift registers.
The 74HC125 tri-state buffer chip only allows the active row to access the MISO line, so that only one row at a time can transmit on MISO.
