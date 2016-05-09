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
* Moved sections of code from main sketch (examples/DH_2565/sketch.cpp) to:
    src/objects_ports.h
    src/objects_LEDs.h
    src/objects_codes.h
    src/objects_matrix.h

### Added
* MouseSpeed
* NumLock
* NASLock and MFLock Protected Keys
* L/R Modf Key
* Alt and Ctrl L/R toggle
* Double Strike for PRINT key
* DH_1363_bb_test sketch for unit testing
* test_keycode.md for integration testing
