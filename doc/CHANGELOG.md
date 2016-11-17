# Change Log for keybrd_DH library
All notable changes to the keybrd project will be documented in this file.
This project adheres to [Semantic Versioning 2.0.0](http://semver.org/).

keybrd_DH Version 0.x.x is for initial development.
Version 1.0.0 will be released when the public API is stable.

0.4.3 (2016-11-16)
------------------
* Enhancements
  * add examples/shiftRegs/

0.4.2 (2016-10-06)
------------------
* Enhancements
  * update examples/shiftRegs/

0.4.1 (2016-10-02)
------------------
* Enhancements
  * Add proof of concept for shift registers implementation in examples/shiftRegs/

0.4.0 (2016-09-28)
------------------
* Enhancements
  * Updated keybrd_DH to be compatible with keybrd library release 0.6.0

* Backward incompatible changes
  * Delete Row_DH_uC and Row_DH_IOE, and replace them with Row_DH
  * Rename instantiations_pins.h to instantiations_scannersLEDs.h
  * Currently DH firmware is about 100 bytes too large for Teensy 2.0 SRAM

0.3.2 (2016-06-21)
------------------
* Enhancements
  * Update sketch to use config_keybrd.h

0.3.2 (2016-06-10)
------------------
* Enhancements
  * Add Row_DH_uC
  * Add Row_DH_IOE

* Backward incompatible changes
  * Remove Port arrays

0.3.1 (2016-06-02)
------------------
* Enhancements
  * Add IndicatorLEDs class

* Backward incompatible changes
  * Change Row_DH::debounce()

0.3.0 (2016-04-30)
------------------
* Enhancements
  * Add MouseSpeed
  * Add NumLock
  * Add NASLock and MFLock Protected Keys
  * Add L/R Modf Key
  * Add Alt and Ctrl L/R toggle
  * Add Double Strike for Print key
  * Add keybrd_DH_unit_tests.ino
  * Add test_keycode.md for integration testing

* Backward incompatible changes
  * Replace SMB classes with StateStickyMouseButtons and Row_DH::keyWasPressed() 
  * Replace LayerManager with LayerState
  * Move keybrd_DH library from core keybrd repository to this repository
  * Move sections of code from mainSketch.cpp to:
    * src/instantiations_ports.h
    * src/instantiations_LEDs.h
    * src/instantiations_codes.h
    * src/instantiations_matrix.h
