/* -*- c++ -*- */
/* 
 * Copyright 2015 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <gnuradio/io_signature.h>
#include <itpp/comm/hammcode.h>    // for itpp 
#include <itpp/itcomm.h>

#include "hamming_impl.h"

namespace gr {
  namespace wsi {
using namespace itpp;
    hamming::sptr
    hamming::make(int m)
    {
      return gnuradio::get_initial_sptr
        (new hamming_impl(m));
    }

    /*
     * The private constructor
     */
    hamming_impl::hamming_impl(int m)
      : gr::block("hamming",
              gr::io_signature::make(1, 1, 4*sizeof(char)),
              gr::io_signature::make(1, 1, 7*sizeof(char))),
	      d_para(m)
	
    {
	decoded_bits.set_size(7);
	}

    /*
     * Our virtual destructor.
     */
    hamming_impl::~hamming_impl()
    {
    }

   
    int
    hamming_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
        const unsigned char *in = (const unsigned char *) input_items[0];
        unsigned char *out = (unsigned char *) output_items[0];

	int i ;
	// Do <+signal processing+>
	Hamming_Code code(d_para) ;
	int n = code.get_n(); 
	int k = code.get_k(); 
	int code_rate = code.get_rate();
	std::cout<<"n,k,code_rate"<< n<<'\t' << k <<'\t'<< code_rate<<std::endl;      
	//for(i=0 ; i < 4 ; i++)
	///{ 
	//	bits[i]=in[i] ; 
	//}
	std::memcpy(bits,in,ninput_items[0]*sizeof(char));
	vec rx_signal(bits);
	bvec rx_signal_bvec = to_bvec(rx_signal);
	code.encode(rx_signal_bvec,decoded_bits); 
	std::cout<<"length decoded bits"<<decoded_bits.size()<<std::endl ; 
	std::cout<<decoded_bits<<std::endl ; 
        consume_each (ninput_items[0]);

        // Tell runtime system how many output items we produced.
        return noutput_items;
    }

  } /* namespace wsi */
} /* namespace gr */

