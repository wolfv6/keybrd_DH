#include "Row_DH.h"

/*
Parameter rowState is bitwise, 1 means pressed, 0 means released.
Returns debounced rowState.

Debounce uses multiple samples to debounces switch states,
where each sample contains the switch states for a row of switches, one bit per switch.

Debounce uses Marty's debounce algorithm from
 http://drmarty.blogspot.com.br/2009/05/best-switch-debounce-routine-ever.html
I2C and TWI protocols do not include any Packet Error Checking (PEC).
The goal of Marty's debounce routine is to reject spurious signals,
which is useful when connecting split keyboards with a cable using I2C or TWI.
Was tested on split keyboard with 3-meter long telephone wire to I/O expander

Marty's debounce algorithm:
 Periodically read samples and update the state when a number consecutive sample bits are equal.

Output from keybrd/examples/debounce_unit_test.cpp with SAMPLE_COUNT 4:
    button pressed:            100000001111111110000
    bouncy signal:             100001001111011110000
    debounced signal:          000000000001111111110
    isFallingEdge:             000000000000000000001
    isRisingEdge:              000000000001000000000
There is a latency equal to SAMPLE_COUNT, between button press and debounced signal.
 
samples[SAMPLE_COUNT] is a ring buffer.  samplesIndex is it's current write index.
SAMPLE_COUNT is the number of consecutive equal samples needed to debounce.
SAMPLE_COUNT is a macro because it defines samples[SAMPLE_COUNT] array size at compile time.
SAMPLE_COUNT should be at lease 1.

Keyboards with a long I2C wire or in environment with strong electromagnetic interference (EMI)
need a larger SAMPLE_COUNT for reliability.
Larger SAMPLE_COUNTs are more reliable but consume more memory, where
     SAMPLE_COUNT*ROW_COUNT = bytes of memory consumed by keyboard
SAMPLE_COUNT = 4 is very reliable for a keyboard.

Avoid sampling the switch input at a rate synchronous to events in the environment
 that might create periodic EMI. For instance, 50 and 60 Hz.

A keyboard with a faster scan rate responds faster.
Follow these step to tune DELAY_MICROSECONDS for maximum scan rate for a given SAMPLE_COUNT:
Initialize DELAY_MICROSECONDS in your sketch:
    const unsigned int Row::DELAY_MICROSECONDS = 1000;
Add this to the sketch's loop() function:
    debug.print_microseconds_per_scan();
Compile and load the sketch into the microcontroller; microseconds_per_scan is printed every second.
Adjust the value of DELAY_MICROSECONDS and repeat until:
    debug.print_microseconds_per_scan() <= DEBOUNCE_TIME / SAMPLE_COUNT

DEBOUNCE_TIME can be obtained from the switch's datasheet.  Some switch bounce times are:
Cherry MX specifies 5msec bounce time http://www.cherrycorp.com/english/switches/key/mx.htm
hasu measured Cherry MX bounce times .3ms to 1.4ms http://geekhack.org/index.php?topic=42385.0
Tactile switch MJTP series bounce 10 ms http://www.apem.com/files/apem/brochures/MJTP_6MM.pdf 

Polling I2C may slow the scan rate enough so that no additional delay is needed:
    const unsigned int Row::DELAY_MICROSECONDS = 0;

Slow-scan trick for debug messages that print too fast:
    change DELAY_MICROSECONDS to a large number like 10000
That way debug messages are printed at a managable rate.
*/
uint8_t Row_DH::debounce(const uint8_t rowState)
{
    uint8_t debounced;                          //bitwise, 1 means pressed, 0 means released
    uint8_t debouncedChanged;                   //bitwise, 1 means debounced changed
    uint8_t all_1 = ~0;                         //bitwise
    uint8_t all_0 = 0;                          //bitwise

    delayMicroseconds(DELAY_MICROSECONDS);      //delay between Row scans to debounce key

    samples[samplesIndex] = rowState;           //insert rowState into samples[] ring buffer

    if (++samplesIndex >= SAMPLE_COUNT)         //if end of ring buffer
    {
        samplesIndex = 0;                       //wrap samplesIndex to beginning of ring buffer
    }

    for (uint8_t j = 0; j < SAMPLE_COUNT; j++)  //traverse the sample[] ring buffer
    {
        all_1 &= samples[j];                    //1 if all samples are 1
        all_0 |= samples[j];                    //0 if all samples are 0
    }

    // update newDebounce if all the samples agree with one another
    // if all samples=1 then debounced=1
    //     elseif all samples=0 then debounced=0
    //         else debounced=previousDebounced i.e. no change
    debounced = all_1 | (all_0 & previousDebounced);

    debouncedChanged = debounced xor previousDebounced;
    previousDebounced = debounced;
    return debouncedChanged;
}

/* Sticky mouse buttons, Ctrl, and Alt keys are effected by other key presses.
Call these objects on every key press.
*/
void Row_DH::keyWasPressed()
{
    refMouseButtons.unstick();
    refCtrl.prevent_toggle();
    refAlt.prevent_toggle();
}
