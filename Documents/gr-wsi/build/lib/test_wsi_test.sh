#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/iiitd/Documents/gr-wsi/lib
export PATH=/home/iiitd/Documents/gr-wsi/build/lib:$PATH
export LD_LIBRARY_PATH=/home/iiitd/Documents/gr-wsi/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-wsi 
