#include <Row_DH.h>

/*
Parameter rowState is bitwise, 1 means pressed, 0 means released.
Returns debounced rowState.

Debounce uses multiple samples to debounces switch states,
where each sample contains the switch states for a row of keys, one bit per switch.

Debounce uses Marty's debounce algorithm from
 http://drmarty.blogspot.com.br/2009/05/best-switch-debounce-routine-ever.html
I2C and TWI protocals do not include any Packet Error Checking (PEC).
The goal of Marty's debounce routine is to reject spurious signals,
which is useful when conecting split keyboards with a cable using I2C or TWI.
Was tested on split keyboard with 3-meter long telephone wire to I/O expander

Marty's debounce algorithm:
 Periodically read samples and update the state when a number consecutive sample bits are equal.

samples[SAMPLE_COUNT] is a ring buffer and samplesIndex is it's current write index.
SAMPLE_COUNT is #defined in Row.h
SAMPLE_COUNT is the number of consecutive equal samples needed to debounce.
It is a macro because it is used to define array size of samples[SAMPLE_COUNT] in Row.
SAMPLE_COUNT should be at lease 2.

Multiple samples are for error correction on I2C I/O expander and shorten response time.
On keyboards without I/O expander, multiple samples only shorten response time.

Keyboards with a long I2C wire or in environment with strong electromagnetic interference (EMI)
need larger SAMPLE_COUNT for reliablity.
Larger SAMPLE_COUNTs are more reliable but consume more memory, where
     SAMPLE_COUNT*ROW_COUNT = bytes of memory consumed by keyboard
SAMPLE_COUNT = 4 is very reliable for I2C error correction.

Avoid sampling the switch input at a rate synchronous to events in the environment
 that might create periodic EMI. For instance, 50 and 60 Hz.
*/
uint8_t Row_DH::debounce(const uint8_t rowState)
{
    uint8_t all_1 = ~0;                         //bitwise
    uint8_t all_0 = 0;                          //bitwise

    delayMicroseconds(DELAY_MICROSECONDS);      //delay between Row scans to debounce key

    samples[samplesIndex] = rowState;           //insert rowState into samples[] ring buffer

    if (++samplesIndex >= SAMPLE_COUNT)
    {
        samplesIndex = 0;                       //wrap samplesIndex to beginning of ring buffer
    }

    for (uint8_t j = 0; j < SAMPLE_COUNT; j++)  //traverse the sample[] ring buffer
    {
        all_1 &= samples[j];                    //1 if all samples are 1
        all_0 |= samples[j];                    //0 if all samples are 0
    }

    // update newDebounce if all the samples agree with one another
    // if all samples=1 then newDebounced=1
    //     elseif all samples=0 then newDebounced=0
    //         else newDebounced=debounced i.e. no change
    return all_1 | (all_0 & debounced);
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
