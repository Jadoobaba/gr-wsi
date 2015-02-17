/* -*- c++ -*- */

#define WSI_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "wsi_swig_doc.i"

%{
#include "wsi/hamming.h"
%}


%include "wsi/hamming.h"
GR_SWIG_BLOCK_MAGIC2(wsi, hamming);

