#ifndef INSTANTIATIONS_PORTS_H
#define INSTANTIATIONS_PORTS_H

// ================ LEFT PORTS =================
#include <RowPort_AVR_Optic.h>
#include <ColPort_AVR.h>

// ----------------- ROW PORT ------------------
RowPort_AVR_Optic rowPortF_L(DDRF, PORTF);

// ----------------- COL PORT ------------------
ColPort_AVR colPortB_L(DDRB, PORTB, PINB, 1<<0 | 1<<1 | 1<<2 | 1<<3 );
ColPort_AVR colPortD_L(DDRD, PORTD, PIND, 1<<2 | 1<<3 );

ColPort* const ptrsColPorts_L[] = { &colPortB_L, &colPortD_L };
const uint8_t COL_PORT_L_COUNT = sizeof(ptrsColPorts_L)/sizeof(*ptrsColPorts_L);

ColPort* const ptrsColPorts_L_short[] = { &colPortB_L };
const uint8_t COL_PORT_L_SHORT_COUNT = sizeof(ptrsColPorts_L_short)/sizeof(*ptrsColPorts_L_short);

// =============== RIGHT PORTS =================
#include <IOExpanderPort.h>
#include <RowPort_PCA9655E.h>
#include <ColPort_PCA9655E.h>

const uint8_t IOExpanderPort::ADDR = 0x18;

// ----------------- ROW PORTS -----------------
IOExpanderPort port1_R(1, 0);
RowPort_PCA9655E rowPort1_R(port1_R);

// ----------------- COL PORTS -----------------
//column and pin numbers on schematic_switch_matrix.png and schematic_pca9655_pin_assignments.png

IOExpanderPort port0_R(0, 0);
ColPort_PCA9655E colPort0_R(port0_R, 1<<0 | 1<<1 | 1<<2 | 1<<3 | 1<<4 | 1<<5 );
//ColPort* const ptrsColPorts_R[] = { &colPort0_R };
//const uint8_t COL_PORT_R_COUNT = sizeof(ptrsColPorts_R)/sizeof(*ptrsColPorts_R);

ColPort_PCA9655E colPort0_R_short(port0_R, 1<<2 | 1<<3 | 1<<4 | 1<<5 );
//ColPort* const ptrsColPorts_R_short[] = { &colPort0_R_short };
//const uint8_t COL_PORT_R_SHORT_COUNT = sizeof(ptrsColPorts_R_short)/sizeof(*ptrsColPorts_R_short);

#endif
