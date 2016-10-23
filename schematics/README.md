# Overview
This README explains two sets of schematics:

1. dodohand_BB will be tested on a broadboard
2. dodohand_PCB is for the DodoHand PCB

Both dodohand_BB and dodohand_PCB use one row of daisy chained shift registers per hand. 

dodohand_BB is a schematic for a proof-of-concept keyboard that fits on a breadboard.
It has everything needed to develop and test DodoHand's scanner firmware.

dodohand_PCB is a schematic for the full DodoHand circuit used to design a PCB.
dodohand_PCB is similar to dodohand_BB with the addition of:
* more keys
* LMC7101 buffer amplifiers
* indicator LEDs

The LMC7101 does not affect the firmware.

# dodohand_breadboard
dodohand_breadboard is a split keyboard small enough to fit on a breadboard.

## dodohand_BB.sch
This is the root schematic of the breadboard.

Teensy LC controls the left and right hands.
The schematic for left and right hands is in row.sch.

## row.sch
This is a schematic for one row of shift registers with 2 keys.
Two SN74HC165N shift registers are daisy chained together for a total of 16 shift registers.

20mA Teensy pins strobe the IR LEDs.
By "strobe" I mean power to the IR LEDs is on for a short time while the shift registers read the photo transistors.
The IR LED are turned off most of the time to conserve IR LED life.

The "2keys" rectangle contains two keys.
Each key is a photointerrupter consisting of an IR LED and photo transistor.

Two SN74HC165N input pins are connected to pull-down resistors and photo transistors.
Unused input pins are grounded.

The keyboard has two rows of shift registers.
The 74HC125 tri-state buffer chip only allows the active row to access the MISO line, so that only one row at a time can transmit on MISO.

These pages explain 74HC125 tri-state buffer:
* http://www.dorkbotpdx.org/blog/paul/better_spi_bus_design_in_3_steps
* http://www.electronics-tutorials.ws/logic/logic_9.html  (74HC125 is an Active “LOW” Tri-state Buffer)

# dodohand_PCB
DodoHand is a split keyboard with 26 keys and 4 indicator LEDs on each hand.

## dodohand_PCB.sch
This is the root schematic of the DodoHand PCB.

Teensy LC controls the left and right hands.

The schematic for left and right hand keys is in row.sch.

The left hand has four indicator LEDs powered by Teensy 20mA pins.
(5mA pins could be used instead; 5mA would be bright enough for indicator lights)

The right side has four indicator LEDs powered by a 74HC595 shift registers.
74HC595 is powered by 5 volts for green or blue LEDs (is the 5 volts safe for Teensy LC?).
If only red and yellow LEDs are used, 74HC595 can be power by 3.3 volts.
74HC595 does not need a tri-state because it is the only MOSI device on the keyboard.

The left and right hands are connected by 8 wires.
The 8-wire "GearIT Cat 6 Ethernet Flat Patch Cable 7 Feet" is very flexible.
It's available at Walmart if you want to feel the merchandise.

## row.sch
This is a schematic for one row of shift registers with 26 keys.
Four SN74HC165N shift registers are daisy chained together for a total of 32 shift registers.

LMC7101 buffer amplifiers strobe the 26 IR LEDs.
By "strobe" I mean power to the IR LEDs is on for a short time while the shift registers read the photo transistors.
The IR LED are turned off most of the time to conserve IR LED life.

There are no current-limiting resistors on the IE LEDs.
Instead, current is limited by the number of LMC7101 buffer amplifiers.
1, 2 or 3 LMC7101 in parallel power 26 IR LEDs.
I don't know how many LMC7101 it will take; someone that understands buffer amplifiers should do the math.

    IR LED forward voltage: typ. 1.2 at 20 mA
    26 LEDs * 20 mA/(2 LEDs in series) = 260 mA
    26 LEDs *  5 mA/(2 LEDs in series) =  65 mA
    LMC7101 Output Short Circuit Current, while sourcing 5V, is typically 200 mA.

[LMC7101 buffer amplifiers data sheet](http://ww1.microchip.com/downloads/en/DeviceDoc/lmc7101.pdf)

One option is to design the PCB for three LMC7101, and only solder one on.
And if the IR LED doesn't get enough voltage, add a another LMC7101.

The keyboard has two rows of shift registers.
The 74HC125 tri-state buffer chip only allows the active row to access the MISO line, so that only one row at a time can transmit on MISO.

These pages explain 74HC125 tri-state buffer:
* http://www.dorkbotpdx.org/blog/paul/better_spi_bus_design_in_3_steps
* http://www.electronics-tutorials.ws/logic/logic_9.html  (74HC125 is an Active “LOW” Tri-state Buffer)

## shiftReg_8keys.sch
This is a schematic for one SN74HC165N and 8 keys.

SN74HC165N input pins are connected to pull-down resistor arrays.

Each "2keys" rectangle contains two keys.
Each key is a photointerrupter consisting of an IR LED and photo transistor.

## shiftReg_2keys.sch
Since row.sch has 26 keys and 32 shift registers, the last SN74HC165N only has 2 keys.
The last 6 input pins are grounded.
