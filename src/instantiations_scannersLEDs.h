#ifndef INSTANTIATIONS_SCANNERSLEDS_H
#define INSTANTIATIONS_SCANNERSLEDS_H

/* This file instantiates uC pin, IOE port, and LED objects.
column and pin numbers on schematic_switch_matrix.png and schematic_pca9655_pin_assignments.png
*/
#include <Scanner_uC.h>

#include <PortPCA9655E.h>
#include <PortPCA9655E.h>
#include <Scanner_IOE.h>

#include <LED.h>
#include <LED_uC.h>
#include <LED_IOE.h>

// --------------- LEFT SCANNER ----------------
uint8_t readPins_L[] = {0,1,2,3,7,8};
Scanner_uC scanner_L(HIGH, readPins_L, 6);

uint8_t readPins_L_short[] = {0,1,2,3};
Scanner_uC scanner_L_short(HIGH, readPins_L_short, 4);

// ----------------- LEFT LEDs -----------------
//left LEDs in order of appearance on PCB
LED_uC LED_L1Yellow(22); //LED_2     ScrollLock (PCB uses pin 4, pin 22 is disconnected,
                                        //explanation in Code_LEDLock.cpp)
LED_uC LED_L2Yellow(13); //LED_D6_3  NumLock (PCB uses pin 11, but that is Teensy's on-board LED)
LED_uC LED_L3Yellow(14); //LED_1     MOUSE_ON
LED_uC LED_L4Green(15);  //LED_0     CapsLock

LED * ptrsLEDs_L[] = { &LED_L1Yellow, &LED_L2Yellow, &LED_L3Yellow, &LED_L4Green };

// --------------- RIGHT SCANNER ---------------
const uint8_t IOE_ADDR = 0x18;

PortPCA9655E port1(IOE_ADDR, 1, 0);             //for strobe and LEDs

PortPCA9655E port0(IOE_ADDR, 0, 1<<0 | 1<<1 | 1<<2 | 1<<3 | 1<<4 | 1<<5); //for read

Scanner_IOE scanner_R(HIGH, port1, port0);

// ---------------- RIGHT LEDs -----------------
//right LEDs in order of appearance on PCB
LED_IOE LED_R1Blue(port1, 1<<5);     //LED_2     NAS (TEN_KEY_OFF or TEN_KEY_ON)
LED_IOE LED_R2Green(port1, 1<<6);    //LED_D6_3  NORMAL
LED_IOE LED_R3Yellow(port0, 1<<7);   //LED_1     MF
LED_IOE LED_R4Red(port0, 1<<6);      //LED_0     TEN_KEY_ON
LED * ptrsLEDs_R[] = { &LED_R1Blue, &LED_R2Green, &LED_R3Yellow, &LED_R4Red };

#endif
