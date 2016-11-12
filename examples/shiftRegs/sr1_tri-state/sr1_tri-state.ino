/* sr1_tri-state.ino
test Tri-State Behavior
from http://www.dorkbotpdx.org/blog/paul/better_spi_bus_design_in_3_steps
    Step 2: Proper MISO Tri-State Behavior
    MISO line was 1.63 volts = 3.3v/2

breadboard has Teensy LC and two sets of 74AHC1G126 tri-state buffer chip + 74HC165
picture shows two oposing pull resitors on right 74AHC1G126
*/
#include <SPI.h>

//slave select
const uint8_t SS_L=6;
const uint8_t SS_R=7;

void setup()
{
    delay(1000);
    Serial.println("sr1_tri-state.ino");

// ------- left --------
    //initialize slave select
    pinMode(SS_L, OUTPUT);
    digitalWrite(SS_L, LOW);

// ------- right -------
    //initialize slave select
    pinMode(SS_R, OUTPUT);
    digitalWrite(SS_R, LOW);

// ------- begin -------
    //SPI.begin(); //does not change volt readings
}

void loop() {}
