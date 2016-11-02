/* sr3_read_loop.ino
demo reading shift register 74HC165.  "sr" means shift register.
each 74HC165 has one pin strobed
breadboard pictures in sr2_read_loop/

breadboard setup:
    Teensy LC and two 74HC165 shift registers

    Teensy pin 6 (SS) connected to left 74HC165 pin 1 (SH//LD)
    Teensy pin 16 strobe left 74HC165 pin 12 (register B)

    Teensy pin 7 (SS) connected to right 74HC165 pin 1 (SH//LD)
    Teensy pin 17 strobe right 74HC165 pin 12 (register B)    

SPI.beginTransaction() not needed
*/
#include <SPI.h>

//strobe
const uint8_t strobe_L=16;
const uint8_t strobe_R=17;

//slave select
const uint8_t SS_L=6;
const uint8_t SS_R=7;

//to test a scan() function, comment all but one, run, append results
uint8_t scan(const uint8_t strobe, const uint8_t slaveSelect) //errorCount=0
{
    uint8_t readState = 0;                      //bit pattern

    digitalWrite(strobe, HIGH);                 //strobe on
    digitalWrite(slaveSelect, HIGH);            //shift
    digitalWrite(strobe, LOW);                  //strobe off

    SPI.transfer(&readState, 1);                //read 1 byte

    digitalWrite(slaveSelect, LOW);             //load

    return readState;
}
/*
uint8_t scan(const uint8_t strobe, const uint8_t slaveSelect) //errorCount=12  loopCount=6
{
    uint8_t readState = 0;                      //bit pattern

    digitalWrite(strobe, LOW);                  //strobe off
    digitalWrite(slaveSelect, HIGH);            //shift (this is the only line that needs strobe)
    digitalWrite(strobe, HIGH);                 //strobe on

    SPI.transfer(&readState, 1);                //read 1 byte

    digitalWrite(slaveSelect, LOW);             //load

    return readState;
}
*/

void setup()
{
// ------- left --------
    //initilize strobe
    pinMode(strobe_L, OUTPUT);
    digitalWrite(strobe_L, HIGH);

    //initilize slave select
    pinMode(SS_L, OUTPUT);
    digitalWrite(SS_L, LOW);

// ------- right -------
    //initilize strobe
    pinMode(strobe_R, OUTPUT);
    digitalWrite(strobe_R, HIGH);

    //initilize slave select
    pinMode(SS_R, OUTPUT);
    digitalWrite(SS_R, LOW);

// ------- begin -------
    SPI.begin();
    delay(1000);
    Serial.println("begin");
}

uint8_t value;                      //bit pattern
uint8_t errorCount = 0;
int loopCount = 0;

void loop()
{
    value = scan(strobe_L, SS_L);
    if (value != B10)
    {
        Serial.print("SS_L=");
        Serial.print(value, BIN);
        errorCount++;
        Serial.print("  loopCount=");
        Serial.println(loopCount);
    }

    value = scan(strobe_R, SS_R);
    if (value != B10)
    {
        Serial.print("SS_R=");
        Serial.print(value, BIN);
        errorCount++;
        Serial.print("  loopCount=");
        Serial.println(loopCount);
    }

    loopCount++;
    if (loopCount > 32000 || errorCount > 10)
    {
        Serial.print("errorCount=");
        Serial.print(errorCount);
        Serial.print("  loopCount=");
        Serial.print(loopCount);
        Serial.println("  stop");
        while(1);
    }

    if (loopCount % 1000 == 0)
    {
        Serial.print("progress loopCount=");
        Serial.println(loopCount);
    }

    //delay(5); //delay(5) takes 2 minutes for 32000 loops
}
