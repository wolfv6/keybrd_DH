/* demo reading shift register 74HC165.  "sr" means shift register.
strobe was not used

breadboard setup:
    Teensy LC and two 74HC165 shift registers

    Teensy pin 6 (SS) connected to left 74HC165 pin 1 (SH//LD)
    left  74HC165, power pin 11 (register A)

    Teensy pin 7 (SS) connected to right 74HC165 pin 1 (SH//LD)
    right 74HC165, power pin 12 (register B)

if LOW after strobe off, but then data in parallel inputs would be old ?? todo
*/
#include <SPI.h>

//slave select
const uint8_t SS_L=6;
const uint8_t SS_R=7;

//to test a scan() function, comment all but one, run, append results
/*
void scan(const uint8_t slaveSelect)
{
    uint8_t recievedVal = 0;                    //like http://www.gammon.com.au/forum/?id=11979

    digitalWrite(slaveSelect, LOW);             //load
    digitalWrite(slaveSelect, HIGH);            //shift
    recievedVal = SPI.transfer(0);              //read 1 byte

    Serial.print(recievedVal, BIN);             // 1, pass
}
void scan(const uint8_t slaveSelect)
{
    uint8_t readState = 0;                      //bit pattern

    digitalWrite(slaveSelect, LOW);             //load
    digitalWrite(slaveSelect, HIGH);            //shift
    SPI.transfer(&readState, 1);                //read 1 byte

    Serial.print(readState, BIN);               // 1, pass
}
void scan(const uint8_t slaveSelect)
{
    uint8_t readState = 0;                      //bit pattern

    digitalWrite(slaveSelect, LOW);             //load
    SPI.transfer(&readState, 1);                //read 1 byte

    Serial.print(readState, BIN);               // 0, fail
}
void scan(const uint8_t slaveSelect)
{
    uint8_t readState = 0;                      //bit pattern

    SPI.transfer(&readState, 1);                //read 1 byte

    Serial.print(readState, BIN);               // 1, pass (even though load was never called)
}
void scan(const uint8_t slaveSelect)
{
    uint8_t readState = 0;                      //bit pattern

    digitalWrite(slaveSelect, LOW);             //load
    digitalWrite(slaveSelect, HIGH);            //shift
    digitalWrite(slaveSelect, LOW);             //stop shifting
    SPI.transfer(&readState, 1);                //read 1 byte

    Serial.print(readState, BIN);               // 0, fail
}
void scan(const uint8_t slaveSelect)
{
    uint8_t readState = 0;                      //bit pattern

    digitalWrite(slaveSelect, LOW);             //load
    digitalWrite(slaveSelect, HIGH);            //shift
    SPI.transfer(&readState, 1);                //read 1 byte

    digitalWrite(slaveSelect, LOW);             //stop shifting
    Serial.print(readState, BIN);               // 1, pass
}
*/
/*
*/

void setup()
{
    uint8_t readState;

    //setup
    delay(1000);
    Serial.print("start   ");

// ------- left --------
    //initilize
    pinMode(SS_L, OUTPUT);
    digitalWrite(SS_L, HIGH);
    SPI.begin();

    //scan
    Serial.print("SS_L register values=");
    scan(SS_L);                     //register G

/*
// ------- right -------
    //initilize SS_R
    pinMode(SS_R, OUTPUT);
    digitalWrite(SS_R, HIGH);

    //delay(10);

    //SS_R
    Serial.print("   SS_R register values=");
    scan(SS_R);                     //register H
*/
}

void loop() { }
