#!/bin/bash
wget -q -O /tmp/libtest.so "https://raw.githubusercontent.com/Bamzzzz/alx-low_level_programming/master/0x18-dynamic_libraries/libtest.so"
export LD_PRELOAD="$PWD/../libtest.so"
