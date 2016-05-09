# Change Log
All notable changes to the keybrd project will be documented in this file.
This project adheres to [Semantic Versioning 2.0.0](http://semver.org/).

Version 0.x.x is for initial development. The public API should not be considered stable.
Version 1.0.0 will be released when the public API is stable.

## [Unreleased][unreleased]

## [0.3.0] - 2016-04-30
### Changed
* Replaced SMB classes with StateStickyMouseButtons and Row_DH::keyWasPressed() 
* Replaced LayerManager with StateLayers
* Moved keybrd_DH library (DodoHand) from keybrd repository to this repository
* Moved sections of code from mainSketch.cpp to:

    src/objects_ports.h<br>
    src/objects_LEDs.h<br>
    src/objects_codes.h<br>
    src/objects_matrix.h

### Added
* MouseSpeed
* NumLock
* NASLock and MFLock Protected Keys
* L/R Modf Key
* Alt and Ctrl L/R toggle
* Double Strike for Print key
* keybrd_DH_unit_tests.ino
* test_keycode.md for integration testing
