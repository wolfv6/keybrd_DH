/* demo reading shift register 74HC165.  "sr" means shift register.
strobe is on for 74HC165 shift

breadboard setup:
    Teensy LC and two 74HC165 shift registers

    Teensy pin 6 (SS) connected to left 74HC165 pin 1 (SH//LD)
    Teensy pin 0 strobe left  74HC165, power pin 11 (register A)

    Teensy pin 7 (SS) connected to right 74HC165 pin 1 (SH//LD)
    Teensy pin 1 strobe right 74HC165, power pin 12 (register B)

if LOW after strobe off, but then data in parallel inputs would be old ?? todo
*/
#include <SPI.h>

//strobe
const uint8_t strobe_L=17;
const uint8_t strobe_R=21;

//slave select
const uint8_t SS_L=15;
const uint8_t SS_R=19;

//to test a scan() function, comment all but one, run, append results
/*
void scan(const uint8_t strobe, const uint8_t slaveSelect)
{
    uint8_t recievedVal = 0;                    //like http://www.gammon.com.au/forum/?id=11979


    digitalWrite(slaveSelect, LOW);             //load

    digitalWrite(strobe, HIGH);                 //strobe on
    digitalWrite(slaveSelect, HIGH);            //shift
    digitalWrite(strobe, LOW);                  //strobe off

    recievedVal = SPI.transfer(0);              //read 1 byte

    Serial.print(recievedVal, BIN);             // 1, pass
}
*/
void scan(const uint8_t strobe, const uint8_t slaveSelect) //use this scan()
{
    uint8_t readState = 0;                      //bit pattern

    digitalWrite(slaveSelect, LOW);             //load

    digitalWrite(strobe, HIGH);                 //strobe on
    digitalWrite(slaveSelect, HIGH);            //shift
    digitalWrite(strobe, LOW);                  //strobe off

    SPI.transfer(&readState, 1);                //read 1 byte

    Serial.print(readState, BIN);               // 1, pass
}
/*
void scan(const uint8_t strobe, const uint8_t slaveSelect)
{
    uint8_t readState = 0;                      //bit pattern

    digitalWrite(strobe, HIGH);                 //strobe on
    SPI.transfer(&readState, 1);                //read 1 byte

    Serial.print(readState, BIN);               // 0, fail because slaveSelect is never LOW
    digitalWrite(strobe, LOW);                  //strobe off
}
//this scan stops shifting after SPI.transfer()
//it won't work with multiple SPI devices because slaveSelect is left low
void scan(const uint8_t strobe, const uint8_t slaveSelect)
{
    uint8_t readState = 0;                      //bit pattern

    digitalWrite(slaveSelect, LOW);             //load (not needed if slaveSelect init to LOW)

    digitalWrite(strobe, HIGH);                 //strobe on
    //delay();                                  //if photo transistor needs more time to stablize
    digitalWrite(slaveSelect, HIGH);            //shift
    digitalWrite(strobe, LOW);                  //strobe off

    SPI.transfer(&readState, 1);                //read 1 byte

    digitalWrite(slaveSelect, LOW);             //stop shifting
    Serial.print(readState, BIN);               // 1, pass
}
//slaveSelect wire is connected to buffer amplifier and SH//LD, needs inverter on buffer amplifier
//slaveSelect controlls both strobe and SH//LD.
//this will work only if 74HC165 starts shift faster than LMC7101 turns off strobe
void scan(const uint8_t strobe, const uint8_t slaveSelect)
{
    uint8_t readState = 0;                      //bit pattern

    digitalWrite(slaveSelect, LOW);             //strobe on and load
    //delay();                                  //if photo transistor needs more time to stablize
    digitalWrite(slaveSelect, HIGH);            //strobe off and shift

    SPI.transfer(&readState, 1);                //read 1 byte

    Serial.print(readState, BIN);               // not tested yet
}
*/

void setup()
{
    //setup
    delay(1000);
    Serial.print("start   ");

// ------- left --------
    //initilize strobe
    pinMode(strobe_L, OUTPUT);
    digitalWrite(strobe_L, LOW);

    //initilize SPI
    pinMode(SS_L, OUTPUT);
    digitalWrite(SS_L, HIGH);
    SPI.begin();

    //scan
    Serial.print("SS_L register values=");
    scan(strobe_L, SS_L);                     //register G

/*
// ------- right -------
    //initilize SPI
    pinMode(SS_R, OUTPUT);
    digitalWrite(SS_R, HIGH);

    //scan
    Serial.print("   SS_R register values=");
    scan(strobe_R, SS_R);                     //register H
*/
}

void loop() { }
