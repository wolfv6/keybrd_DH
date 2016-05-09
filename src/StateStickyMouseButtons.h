#ifndef STATESTICKYMOUSEBUTTONS_H 
#define STATESTICKYMOUSEBUTTONS_H 
#include <Arduino.h>
#include <inttypes.h>
#include <Code_LayerLockMF_Protector.h>

/* StateStickyMouseButtons sticks and unsticks sticky mouse buttons.
Sticky Mouse Buttons are called "Mouse Click Lock" in the DataHand User's Guide.

Holding the Mouse-Function key while pressing a mouse button, makes the mouse button stuck.
Pressing any key (except Code_Mouse_Quick, Code_Mouse_Slow) unsticks the stuck mouse button.
Thus only one mouse button at a time can be stuck.
Row_UnstickMouseButtons::unstickKey() calls the unstick() function.
*/
class StateStickyMouseButtons
{
    private:
        Code_LayerLockMF_Protector& refProtector;
        uint16_t stuckButton; //scancode of currently stuck Code_StickyMouseButton, 0 if not stuck
        bool isUnstickKey; //binary semaphore, true if key that was pressed unsticks mouse buttons
                          //cleared by keys that do not unstick mouse buttons e.g. Code_Mouse_Quick
    public:
        StateStickyMouseButtons(Code_LayerLockMF_Protector& refProtector)
            : refProtector(refProtector), stuckButton(0) {}
        void press(uint16_t scancode);
        void release(uint16_t scancode);
        void releaseStuckButton();
        void doNotUnstick();
        void unstick();
};
#endif

