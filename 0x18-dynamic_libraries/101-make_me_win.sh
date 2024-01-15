#!/bin/bash
wget -P .. https://raw.githubusercontent.com/Bamzzzz/alx-low_level_programming/master/0x18-dynamic_libraries/gigalib.so
export LD_PRELOAD="$PWD/../gigalib.so"
