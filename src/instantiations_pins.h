#ifndef INSTANTIATIONS_PINS_H
#define INSTANTIATIONS_PINS_H

/* This file instantiates uC pin, IOE port, and LED objects.
column and pin numbers on schematic_switch_matrix.png and schematic_pca9655_pin_assignments.png
*/
#include <Scanner_uC.h>

#include <PortIOE.h>
#include <PortWrite_PCA9655E.h>
#include <PortRead_PCA9655E.h>
#include <Scanner_IOE.h>

#include <LED.h>
#include <LED_uC.h>
#include <LED_PCA9655E.h>

// =============== LEFT uC MATRIX ==============
// ------------------ SCANNERS -----------------
uint8_t readPins_L[] = {0,1,2,3,7,8};
Scanner_uC scanner_L(HIGH, readPins_L, 6);

uint8_t readPins_L_short[] = {0,1,2,3};
Scanner_uC scanner_L_short(HIGH, readPins_L_short, 4);

// ------------------- LEDs --------------------
//left LEDs in order of appearance
LED_uC LED_L1Yellow(22); //LED_2     ScrollLock (PCB uses pin 4, pin 22 is disconnected,
                                        //explanation in Code_LEDLock.cpp)
LED_uC LED_L2Yellow(13); //LED_D6_3  NumLock (PCB uses pin 11, but that is Teensy's on-board LED)
LED_uC LED_L3Yellow(14); //LED_1     MOUSE_ON
LED_uC LED_L4Green(15);  //LED_0     CapsLock

LED * ptrsLEDs_L[] = { &LED_L1Yellow, &LED_L2Yellow, &LED_L3Yellow, &LED_L4Green };

// ============== RIGHT IOE MATRIX =============
// ------------------ SCANNER ------------------
const uint8_t PortIOE::DEVICE_ADDR = 0x18;

PortIOE port_R1(1, 0);
PortWrite_PCA9655E portWrite_R1(port_R1);

PortIOE port_R0(0, 0);
PortWrite_PCA9655E portWrite_R0(port_R0);
PortRead_PCA9655E portRead_R0(port_R0, 1<<0 | 1<<1 | 1<<2 | 1<<3 | 1<<4 | 1<<5);

Scanner_IOE scanner_R(HIGH, portWrite_R1, portRead_R0);

// ------------------- LEDs --------------------
//right LEDs in order of appearance
LED_PCA9655E LED_R1Blue(portWrite_R1, 1<<5);    //LED_2     NAS (TEN_KEY_OFF or TEN_KEY_ON)
LED_PCA9655E LED_R2Green(portWrite_R1, 1<<6);   //LED_D6_3  NORMAL
LED_PCA9655E LED_R3Yellow(portWrite_R0, 1<<7);  //LED_1     MF
LED_PCA9655E LED_R4Red(portWrite_R0, 1<<6);     //LED_0     TEN_KEY_ON
LED * ptrsLEDs_R[] = { &LED_R1Blue, &LED_R2Green, &LED_R3Yellow, &LED_R4Red };

#endif
