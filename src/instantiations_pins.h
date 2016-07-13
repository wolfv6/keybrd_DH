#ifndef INSTANTIATIONS_PINS_H
#define INSTANTIATIONS_PINS_H

const uint8_t READ_PIN_COUNT = 6;
const uint8_t READ_PIN_COUNT_SHORT = 4;

// ================= LEFT PINS =================
const uint8_t readPins_L[] = {0,1,2,3,7,8};
const uint8_t readPins_L_short[] = {0,1,2,3};

// =============== RIGHT PORTS =================
#include <IOEPort.h>
#include <StrobePort_PCA9655E.h>
#include <ReadPort_PCA9655E.h>

const uint8_t IOEPort::ADDR = 0x18;

// ----------------- ROW PORTS -----------------
IOEPort port1_R(1, 0);
StrobePort_PCA9655E strobePort1_R(port1_R);

// ----------------- COL PORTS -----------------
//column and pin numbers on schematic_switch_matrix.png and schematic_pca9655_pin_assignments.png

IOEPort port0_R(0, 0);
ReadPort_PCA9655E readPort0_R(port0_R, 1<<0 | 1<<1 | 1<<2 | 1<<3 | 1<<4 | 1<<5);

#endif
