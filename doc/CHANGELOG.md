# Change Log for keybrd_DH library
All notable changes to the keybrd project will be documented in this file.
This project adheres to [Semantic Versioning 2.0.0](http://semver.org/).

keybrd_DH Version 0.x.x is for initial development.
Version 1.0.0 will be released when the public API is stable.

<!--
Unreleased
----------
-->

0.3.2 (2016-06-21)
------------------
* Enhancements
  * Update sketch to use config_keybrd.h

0.3.2 (2016-06-10)
------------------
* Backward incompatible changes
  * Remove Port arrays

* Enhancements
  * Add Row_DH_uC
  * Add Row_DH_IOE

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
