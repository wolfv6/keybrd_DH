Sketches in keybrd_DH/examples/shiftRegs/ where used to develop and test shift register firmware for the Dodohand keyboard.

sr4_keys.ino demonstrates features as they would be used on the DodoHand firmware.

# 74HC165 on Arduino for single row of keys
row of keys needs 6 connecting wires to Teensy
    GND
    3.3v
    CLK
    SS
    MISO
    strobe

refer to tut4 for daisy chained 165s

## strobe
instead of LMC7101 buffer amplifier, use Schmitt-trigger buffer ??
https://www.digikey.com/product-search/en/integrated-circuits-ics/logic-buffers-drivers-receivers-transceivers/2556308?k=&pkeyword=&pv547=1&pv592=39&FV=1a40001%2C3dc002b%2C1f140000%2Cfff40027%2Cfff80194&mnonly=0&newproducts=0&ColumnSort=1000011&page=1&quantity=1&ptm=0&fid=0&pageSize=100
 http://www.diodes.com/_files/datasheets/74LVC1G17.pdf

A digital buffer can also be used to drive high current loads such as transistor switches because their output drive capability is generally much higher than their input signal requirements. In other words buffers can be used for power amplification of a digital signal as they have what is called a high “fan-out” capability.
 http://www.electronics-tutorials.ws/logic/logic_9.html


# indicator LEDs on 74HC595
74HC595 needs 2 additional connecting wires to Teensy
    SS
    MOSI

74HC595 output pins have 6mA at 5V (datasheet does not list current for 3.3V).
The 74HC595 runs on 3.3 volts from Teensy LC (5V Vin was not used because it would require a 9th connecting wire).
3.3V will reliably light red and yellow LEDs.
I tested a blue LED with 3.4 typ forward voltage and 4.7k current-limiting resistor.
It lit the LED and 74HC595 output pin measured 3.3 volts.
A blue LED with a lower forward voltage would be more reliable e.g.
    Wurth Electronics Inc, 151053BS04500, blue, 2.7 forward voltage, 20mA, 45 deg viewing angle

# indicator LEDs on Teensy LC
Indicator LEDs on Teensy LC would be implemented same as current DodoHand on Teensy 2.

# shift reg matrix
A more sophisticated design would be a shift-register matrix.
It has fewer solder joints, but would have a slower scan and take more development time.
The slower scan takes time away from monitoring the track ball.

Here is an example of 2x2 matrices on a breadboard [tutorial_4c_split_keyboard_with_IOE.md](todo link)
A breadboard is useful for testing the firmware and circuit before making the PCB.
see /home/wolfv/Documents/Arduino/keybrd_proj/keybrd_DH/DH_shiftReg_nogit.txt
    # shift reg matrix

144 fewer solder joints:
    20 fewer pull resistors per hand
    2 fewer 16-pin shift registers per hand
to have same number of connecting wires (8):
    use one SN74HC595N pin to control 74HC165 SH/LD (if that doesn't work, use 9 wires)
