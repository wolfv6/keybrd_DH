# Shift registers overview
The following folders where used to develop shift-register circuits and firmware.
The folders contain schematics, sketches, and pictures of breadboards.
* sr1_tri-state/
* sr2_read_loop/
* sr3_strobe_loop/
* sr4_keys/
* sr5_dodohand_PCB/

The prefix "sr" means "shift register".
The folders are numbered from fundamental to practical.
The fist three folders test components.
sr4_keys demonstrates shift-register keybrd classes as they would be used in DodoHand.
sr5_PCB contains schematics for the full 52-key circuit used to design DodoHand's PCB.

Each sketch was tested on a breadboard with Teensy LC.
The breadboard bus strips are half the breadboard's length, separated by a gap in the center.
Each breadboard half holds enough electronics for one row of 8 keys:
* one 74HC165 shift registers (DIP)
* one 74AHC1G126 tri-state buffer chip (on red breakout adapter)

# 74HC165 shift registers (sr4_keys, sr5_dodohand_PCB)
One row of keys is read by 74HC165 shift registers.
The shift registers connect to Teensy controller via 6 wires:
* GND
* 3.3v
* CLK
* Slave Select
* MISO
* strobe

# 74AHC1G126 tri-state buffer chip (sr4_keys, sr5_dodohand_PCB)
The keyboard has two rows of shift registers.
The 74AHC1G126 tri-state buffer chip only allows the active row to access the MISO line, so only one row at a time can transmit on MISO.

These pages explain tri-state buffer chips:
* http://www.dorkbotpdx.org/blog/paul/better_spi_bus_design_in_3_steps
* http://www.electronics-tutorials.ws/logic/logic_9.html  (74AHC1G126 is an active-high tri-state buffer)

# Strobe buffer (sr5_dodohand_PCB)
DodoHand is a split keyboard with 26 keys on each hand.  The scanner polls the 26 keys quickly.
Polling the switches allows for the IR LEDs to be off most of the time, preserving IR LED life.

The track ball requires constant monitoring.
The polling is fast so that the controller can spend 99% of it's time monitoring the trackball.
1% of the trackball signals are missed while polling the shift registers.

To achieve fast polling, 26 keys are strobed simultaneously.
By "strobe" I mean power to the IR LEDs is on for a short time while the shift registers read the photo transistors.
Strobing 26 IR LEDs simultaneously requires much current (high fan-out capability):

    All the IR LEDs at DigiKey are at least 20mA.
    IR LED forward voltage: typ. 1.2 at 20 mA
    26 LEDs * 20 mA/(2 LEDs in series) = 260 mA
    26 LEDs *  5 mA/(2 LEDs in series) =  65 mA

Some candidates for strobing IR LEDs are:
* digital buffer
* buffer amplifier e.g. LMC7101
* Schmitt-trigger buffer

Buffers can be connected in parallel if more current is needed.

I don't understand enough electronics to know which strobe buffer would work.
Someone that understands electronics can can figure this out.

Adding strobe buffers to the circuit does not affect the firmware.

# Indicator LEDs on Teensy LC (sr5_dodohand_PCB)
Indicator LEDs connected to Teensy LC would be implemented same as current DodoHand on Teensy 2
(if you really bright indicator LEDs, use the 20mA pins).

# Indicator LEDs on 74HC595 (sr5_dodohand_PCB)
Indicator LEDs not on Teensy are powered by 74HC595 shift registers.
The 74HC595 is connected to Teensy controller via 2 additional wires:
* SS
* MOSI

74HC595 output pins are rated at 6mA at 5V (datasheet does not list current for 3.3V).
The 74HC595 runs on 3.3 volts from Teensy LC.
74HC595 on 3.3V will reliably light red and yellow LEDs.

I tested a blue LED with 3.4 typ forward voltage and 4.7k current-limiting resistor.
74HC595 lit the blue LED; and it's output pin was 3.3 volts.
A blue LED with a lower forward voltage would be more reliable e.g.
* Wurth Electronics Inc, 151053BS04500, blue, 2.7 forward voltage, 20mA, 45 deg viewing angle

Teensy LC's 5-volt Vin was not used because it would add a 9th connecting wire.

Together, 74HC165 and 74HC595 connect to Teensy controller using a total of 8 wires.
The 8-wire "GearIT Cat 6 Ethernet Flat Patch Cable 7 Feet" is very flexible.
It's available at Walmart if you want to feel the merchandise.

74HC595 does not need a tri-state because it is the only MOSI device on the keyboard.

# Alternative designs
The track ball requires constant monitoring.
There are a few ways to do this, but the alternatives are all more complicated than the daisy-chained shift registers described above.

## Two controllers
Two separate controllers:
* one controller to emulate the DataHand layout
* one controller dedicated to monitoring the trackball

A second Teensy LC is a little pricey, but not a problem for prototyping.

## PCA9655E I/O expander with interrupts
one I/O expander per 16 keys (four I/O expanders total)
I2C-safe Bi-directional Logic Level Converter between 3.3v Teeny LC and 5v PCA9655Es.

When a key is pressed or released, PCA9655E sends an interrupt signal to Teensy, which then sends commands to the PCA9655E to read input pins.
Thus 4 milliseconds of trackball signals are missed only when a key is pressed or released.
Not a problem because people usually don't mouse and type at the same time.

An I/O expander interrupt would require IR LEDs to be on all the time so key changes can be detected.

I2C bus contention for interrupt signal might be an issue.
Although changing keys on two I/O expanders at exactly the same time would be rare.

Would have about the same number of solder joints as daisy-chained shift registers described above.

## Shift register matrix
Compared to daisy-chained shift registers described above, a shift-register matrix would have fewer solder joints, but would have a slower scan rate and take more time to develop.

144 fewer solder joints because:
* 20 fewer pull resistors per hand
* 2 fewer 16-pin shift registers per hand

The slower scan rate takes time away from monitoring the track ball.
sr4_keys.ino with two rows of shift registers consumes 63 microseconds per scan.
A 52-key DodoHand with two rows of shift registers might consume 100 microseconds per scan.
A DodoHand with a 5-row shift register matrix might consume 200 microseconds per scan.

A keyboard should be scanned at least every 10,000 microseconds (10 milliseconds).
The remaining time can be used to monitor the trackball.

    100us / 10000us = 1% of trackball signals are missed while scanning shift-register daisy chains
    200us / 10000us = 2% of trackball signals are missed while scanning shift-register matrix

To have same eight connecting wires, use one SN74HC595N pin to control 74HC165 SH/LD (if that doesn't work, use 9 wires).

Here is an example breadboard [tutorial_4c_split_keyboard_with_IOE.md](https://github.com/wolfv6/keybrd/blob/master/tutorials/tutorial_4c_split_keyboard_with_IOE.md) which is useful for testing 2x2 matrices.
