#ifndef CODE_MOUSEMOVE_H
#define CODE_MOUSEMOVE_H
#include <Arduino.h>
#include <inttypes.h>
#include <Code_MouseSpeed.h>

/* Class MouseMove

Example:
    MouseMove mouseMove(4);       //smaller parameter results in faster mouse
    void loop() { mouseMove.send(); }
*/
class MouseMove
{
    private:
        const uint8_t SCANS_PER_MOUSE_MOVE;     //keyboard scans per Mouse.move() sent
        uint8_t scansSinceLastMouseMove;
    public:
        MouseMove(const uint8_t SCANS_PER_MOUSE_MOVE)
            : SCANS_PER_MOUSE_MOVE(SCANS_PER_MOUSE_MOVE), scansSinceLastMouseMove(0) { }
        void send();                            //called from sketch main loop()
};
#endif
