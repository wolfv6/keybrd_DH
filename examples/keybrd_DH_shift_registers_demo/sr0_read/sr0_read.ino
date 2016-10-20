/* 
Tested on Teensy LC and one 74HC165 shift register
pull-down resitor on shift reg 3
strobe pin 16 on shift reg 3

74HC165 is not an SPI device
SH/LD is connected to Teensy SS
Shift or Load input:
    When High Data, shift the data toward a serial output
    When Low data, enable parallel inputs to registers
    datasheet p12 Fig 4. Typical Shift, Load, and Inhibit Sequence

Scanner_ShiftRegsPISOMultiRow::scan() digitalWrite(slaveSelect, HIGH) is left HIGH after strobeOff
could move LOW to after strobe off, but then data in parallel inputs would be old
see how LarryD did it
*/
// ################## GLOBAL ###################
// ================= INCLUDES ==================
#include <SPI.h>

// --------------- LEFT SCANNER ----------------
const uint8_t SS_L=10;
const uint8_t SS_R=9;

void scan(const uint8_t slaveSelect)
{
    uint8_t readState = 0;                      //bit pattern

    //LarryD uses SH/LD and CLK INH pins (I only used SH/LD)
digitalWrite(slaveSelect, LOW);
    digitalWrite(slaveSelect, HIGH);            //shift the data toward a serial output
    SPI.transfer(&readState, 1);                //read 1 byte
    digitalWrite(slaveSelect, LOW);             //enable parallel inputs to registers
digitalWrite(slaveSelect, HIGH);
    Keyboard.print(readState);
}

// ################### MAIN ####################
void setup()
{
    uint8_t readState;

    delay(3000);
    Keyboard.print("3 ");
    delay(3000);

    SPI.begin();

    //initilize SS_L
    pinMode(SS_L, OUTPUT);
    digitalWrite(SS_L, HIGH);

    //SS_L
    Keyboard.print("SS_L readState=");
    scan(SS_L);                     //8

    //initilize SS_R
    pinMode(SS_R, OUTPUT);
    digitalWrite(SS_R, HIGH);

    //delay(10);

    //SS_R
    Keyboard.print("   SS_R readState=");
    scan(SS_R);                     //2
}

void loop() { }
