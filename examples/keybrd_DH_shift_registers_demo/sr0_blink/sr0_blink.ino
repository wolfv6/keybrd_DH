/* tested on Teensy LC, 74HC595, and two blue LEDs with 4.7k current-limiting resistors
3.3 volts on 74HC595 VCC, pin 6 measured 3.3 volts while lighting Vf 3.4 typ blue LED
based on http://www.gammon.com.au/forum/?id=11518

/MR (master reset) is high so the chips are never in a reset state.
/OE (output enable) low, so the chips are always in output mode.
10K pull-down resistor on the SS keep the registers from clocking in bits while the main processor is booting, and the SS line might be "floating" and in an indeterminate state.
    I tested w/o this pull-down resistor, keybrd lib will clear LEDs during LED.begin().
*/
#include <SPI.h>

const uint8_t LED_L = 4;            //3.3v 5mA pin with 4.7k current-limiting resistor
const uint8_t LED_R = 8;            //slave select 74HC595

void setup ()
{
    pinMode(LED_L, OUTPUT);
    pinMode(LED_R, OUTPUT);
    SPI.begin();
}

//alternating left-right blink
void loop ()
{
    //blink left LED on Teensy LC
    digitalWrite(LED_L, HIGH);      //LED on
    delay(100);

    digitalWrite(LED_L, LOW);       //LED off
    delay(100);

    //blink right LED on 74HC595
    digitalWrite(LED_R, LOW);
    SPI.transfer(1<<6);             //LED on pin 6
    digitalWrite (LED_R, HIGH);
    delay(100);

    digitalWrite(LED_R, LOW);
    SPI.transfer(0);                //LED off
    digitalWrite (LED_R, HIGH);
    delay(100);
}
