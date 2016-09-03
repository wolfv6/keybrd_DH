#ifndef INSTANTIATIONS_PINS_H
#define INSTANTIATIONS_PINS_H

/* This file instantiates uC pin, IOE port, and LED objects.
*/

#include <LED.h>
#include <LED_uC.h>
#include <LED_PCA9655E.h>

const uint8_t readPinCount = 6;                 //for rows with thumb keys
const uint8_t readPinCountShort = 4;            //for rows w/o thumb keys

// =============== LEFT uC MATRIX ==============
uint8_t readPins_L[] = {0,1,2,3,7,8};
uint8_t readPins_L_short[] = {0,1,2,3};

// ------------------- LEDs --------------------
//left LEDs in order of appearance
LED_uC LED_L1Yellow(
    22); //LED_2     ScrollLock (PCB uses pin 4, pin 22 is disconnected, explanation in Code_LEDLock.cpp)
LED_uC LED_L2Yellow(13); //LED_D6_3  NumLock (PCB uses pin 11, but that is Teensy's on-board LED)
LED_uC LED_L3Yellow(14); //LED_1     MOUSE_ON
LED_uC LED_L4Green(15);  //LED_0     CapsLock

LED * ptrsLEDs_L[] = { &LED_L1Yellow, &LED_L2Yellow, &LED_L3Yellow, &LED_L4Green };

// ============== RIGHT IOE MATRIX =============
#include <PortIOE.h>
#include <PortWrite_PCA9655E.h>
#include <PortRead_PCA9655E.h>

const uint8_t PortIOE::DEVICE_ADDR = 0x18;

// ------------------ PORT 1 -------------------
PortIOE port1_R(1, 0);
PortWrite_PCA9655E portWrite1_R(port1_R);

// ------------------ PORT 0 -------------------
//column and pin numbers on schematic_switch_matrix.png and schematic_pca9655_pin_assignments.png

PortIOE port0_R(0, 0);
PortWrite_PCA9655E portWrite0_R(port0_R);
PortRead_PCA9655E portRead0_R(port0_R, 1<<0 | 1<<1 | 1<<2 | 1<<3 | 1<<4 | 1<<5);

// ------------------- LEDs --------------------
//right LEDs in order of appearance
LED_PCA9655E LED_R1Blue(portWrite1_R, 1<<5);    //LED_2     NAS (TEN_KEY_OFF or TEN_KEY_ON)
LED_PCA9655E LED_R2Green(portWrite1_R, 1<<6);   //LED_D6_3  NORMAL
LED_PCA9655E LED_R3Yellow(portWrite0_R, 1<<7);  //LED_1     MF
LED_PCA9655E LED_R4Red(portWrite0_R, 1<<6);     //LED_0     TEN_KEY_ON
LED * ptrsLEDs_R[] = { &LED_R1Blue, &LED_R2Green, &LED_R3Yellow, &LED_R4Red };

#endif
