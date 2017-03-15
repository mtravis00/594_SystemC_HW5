// octalMux2to1: 8-bit 2 to 1 multiplexer

#include <systemc.h>

SC_MODULE(octalMux2to1)
{
	sc_in<sc_logic> sel;
	sc_in<sc_lv<8> > ain, bin;
	sc_out<sc_lv<8> > yout;

	SC_CTOR(octalMux2to1)
	{
		SC_METHOD(muxing);
		sensitive << ain << bin << sel;
	}
	void muxing();
};
