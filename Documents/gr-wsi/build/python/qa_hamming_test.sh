#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/iiitd/Documents/gr-wsi/python
export PATH=/home/iiitd/Documents/gr-wsi/build/python:$PATH
export LD_LIBRARY_PATH=/home/iiitd/Documents/gr-wsi/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/iiitd/Documents/gr-wsi/build/swig:$PYTHONPATH
/usr/bin/python2 /home/iiitd/Documents/gr-wsi/python/qa_hamming.py 
