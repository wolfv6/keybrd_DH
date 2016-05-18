#ifndef INSTANTIATIONS_LEDS_H
#define INSTANTIATIONS_LEDS_H

// ----------------- LEFT LED pins --------------------
#include <LED_AVR.h>

LED_AVR LED_LB6_1green(PORTB, 1<<6);            //LED_0     CapsLock
LED_AVR LED_LB5_2yellow(PORTB, 1<<5);           //LED_1     ScrollLock
//LED_AVR LED_LD6_3yellow(PORTD, 1<<6);           //LED_D6_3  NumLock, only Teensy's on-board LED
//LED_AVR LED_LD7_3yellow(PORTD, 1<<7);           //          NumLock, dim
LED_AVR LED_LB4_3yellow(PORTB, 1<<4);           //          NumLock
LED_AVR LED_LB7_4yellow(PORTB, 1<<7);           //LED_2     MF

// ----------------- RIGHT LED pins -------------------
#include <LED_PCA9655E.h>

LED_PCA9655E LED_R16_1green(port1_R, 1<<6);     //LED_D6_3  NORMAL
LED_PCA9655E LED_R15_2blue(port1_R, 1<<5);      //LED_2     NAS TEN_KEY_OFF (or TEN_KEY_ON)

LED_PCA9655E LED_R06_3red(port0_R, 1<<6);       //LED_0     TEN_KEY_ON
LED_PCA9655E LED_R07_4yellow(port0_R, 1<<7);    //LED_1     MOUSE_ON

#endif
