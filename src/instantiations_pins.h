#ifndef INSTANTIATIONS_PINS_H
#define INSTANTIATIONS_PINS_H

const uint8_t READ_PIN_COUNT = 6;               //for rows with thumb keys
const uint8_t READ_PIN_COUNT_SHORT = 4;         //for rows w/o thumb keys

// ================= LEFT PINS =================
const uint8_t readPins_L[] = {0,1,2,3,7,8};
const uint8_t readPins_L_short[] = {0,1,2,3};

// =============== RIGHT PORTS =================
#include <PortIOE.h>
#include <PortWrite_PCA9655E.h>
#include <PortRead_PCA9655E.h>

const uint8_t PortIOE::ADDR = 0x18;

// ----------------- ROW PORTS -----------------
PortIOE port1_R(1, 0);
PortWrite_PCA9655E portWrite1_R(port1_R);

// ----------------- COL PORTS -----------------
//column and pin numbers on schematic_switch_matrix.png and schematic_pca9655_pin_assignments.png

PortIOE port0_R(0, 0);
PortWrite_PCA9655E portWrite0_R(port0_R);
PortRead_PCA9655E portRead0_R(port0_R, 1<<0 | 1<<1 | 1<<2 | 1<<3 | 1<<4 | 1<<5);

#endif
