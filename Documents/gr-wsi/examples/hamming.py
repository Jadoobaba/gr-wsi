#!/usr/bin/env python
##################################################
# Gnuradio Python Flow Graph
# Title: Hamming
# Generated: Sat Feb 14 12:42:50 2015
##################################################

from gnuradio import blocks
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from grc_gnuradio import wxgui as grc_wxgui
from optparse import OptionParser
import wsi
import wx

class hamming(grc_wxgui.top_block_gui):

    def __init__(self):
        grc_wxgui.top_block_gui.__init__(self, title="Hamming")
        _icon_path = "/usr/share/icons/hicolor/32x32/apps/gnuradio-grc.png"
        self.SetIcon(wx.Icon(_icon_path, wx.BITMAP_TYPE_ANY))

        ##################################################
        # Variables
        ##################################################
        self.samp_rate = samp_rate = 32000

        ##################################################
        # Blocks
        ##################################################
        self.wsi_hamming_0 = wsi.hamming(3)
        self.blocks_file_source_0 = blocks.file_source(gr.sizeof_char*4, "/home/iiitd/Desktop/junk.txt", False)
        self.blocks_file_sink_0 = blocks.file_sink(gr.sizeof_char*7, "/home/iiitd/Desktop/junk2.txt", False)
        self.blocks_file_sink_0.set_unbuffered(True)

        ##################################################
        # Connections
        ##################################################
        self.connect((self.blocks_file_source_0, 0), (self.wsi_hamming_0, 0))    
        self.connect((self.wsi_hamming_0, 0), (self.blocks_file_sink_0, 0))    


    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate

if __name__ == '__main__':
    import ctypes
    import sys
    if sys.platform.startswith('linux'):
        try:
            x11 = ctypes.cdll.LoadLibrary('libX11.so')
            x11.XInitThreads()
        except:
            print "Warning: failed to XInitThreads()"
    parser = OptionParser(option_class=eng_option, usage="%prog: [options]")
    (options, args) = parser.parse_args()
    tb = hamming()
    tb.Start(True)
    tb.Wait()
