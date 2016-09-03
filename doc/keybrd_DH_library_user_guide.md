keybrd_DH Library User's Guide
==============================
The keybrd_DH library is an extension of the [keybrd library](https://github.com/wolfv6/keybrd) for emulating the DataHand keyboard.

The main DH sketch is in keybrd_DH/examples/keybrd_DH/keybrd_DH.ino.
It has been Alpha tested on teensy 2.0 with a PCA9655E I/O expander.

Getting started
---------------
Follow the "Getting started" in keybrd/doc/keybrd_library_user_guide.md.

For 8-bit controllers (like Teensy 2.0) edit the keybrd/src/config_keybrd.h file to typedef read_pins_t to uint8_t:

    typedef uint8_t read_pins_t;

DH QWERTY layout
----------------
101-keyboard mode (ENTER key on right ring finger sends KEYPAD_ENTER, there is no "Windows" key)
On breadboard keyboard, finger keys are on the outer 4 columns

```
            LEFT                                        RIGHT
 NORMAL
    NORTH   q      w      e      r              NORTH   u      i      o      p
    EAST    [{     b      t      g              WEST    h      y      n      ]}
    CENTER  a      s      d      f              CENTER  j      k      l      ;:
    SOUTH   z      x      c      v              SOUTH   m      ,      .      /?
    WEST    Del    Esc    `      "              EAST    '      :      Ent    \|

 NAS TEN_KEY_OFF                    NASLck proected: 10KeyOff, 10KeyOn, NumLck
    NORTH   !      @      #      $              NORTH   &      *      (      )
    EAST    ~      NumLck >      5              WEST    6      ^      ;      10KeyOff
    CENTER  1      2      3      4              CENTER  7      8      9      0
    SOUTH   =      00     %      -              SOUTH   +      ,      .      ?
    WEST    Del    Esc    <      /              EAST    _      :      Ent    10KeyOn

 NAS TEN_KEY_ON
    NORTH   !      @      #      Up             NORTH   7      8      9      *
    EAST    ~      null   >      Right          WEST    0      +      =      10KeyOff
    CENTER  ,      $      &      Home           CENTER  4      5      6      .
    SOUTH   (      )      %      Down           SOUTH   1      2      3      /
    WEST    Del    Esc    <      Left           EAST    00     -      Ent    10KeyOn

                                    MF protected: ArrowOn, MouseOn, F1-F12, NumLck, L/RModf, Print
 MF MOUSE_ON                     QUICK                  SLOW
    NORTH   F2     F4     F6     Up             NORTH   Up     F8     F10    PgUp
    EAST    ScrLck NumLck Ent    Right          WEST    Left   End    Ins    F11
    CENTER  L/RModf MB3  MouseOn MB1            CENTER  MB2    ArrowOn Print Pause
    SOUTH   F1     F3     F5     Down           SOUTH   Down   F7     F9     PgDn
    WEST    Del    Esc    =      Left           EAST    Right  Shift  Ent    F12

 MF ARROW_ON
    NORTH                        Up             NORTH   Up
    EAST                         Right          WEST    Left
    CENTER                       Home           CENTER  Home
    SOUTH                        Down           SOUTH   Down
    WEST                         Left           EAST    Right

On breadboard keyboard, thumb keys are inner 2 columns on first 3 rows
            LEFT                                        RIGHT
    NORTH   Tab    CapLck                       NORTH   NASLck BkSp
    EAST    Ctrl   Ent                          WEST    Sp     Alt
    CENTER  Shift  Normal                       CENTER  MF     NAS

PCB thumb keys
            LEFT                                        RIGHT
    TOP     Ent    Shift  Tab                   TOP     BkSp   NAS    Sp
    BOT     Normal CapLck Ctrl                  BOT     Alt    NASLck MF
```

Troubleshooting check list
--------------------------
keybrd library items to check:
* If last line in Arduino IDE compile message says "Low memory available",
  second-to-last line should say "leaving 100 bytes for local variables" or more bytes.
* In keybrd/src/config_keybrd.h file, read_pins_t defaults to uint32_t.
  For Teensy 2.0, use "typedef uint8_t read_pins_t;" which saves 150 bytes SRAM compared to uint32_t.
  Because keybrd_DH.ino global variables use almost all of Teensy 2.0 available dynamic memory.
