// octalTriState: 8-bit Tri-state logic

#include <systemc.h>

SC_MODULE(octalTriState)
{
	sc_in<sc_logic> sel;
	sc_in<sc_lv<8> > ain;
	sc_out<sc_lv<8> > yout;

	SC_CTOR(octalTriState)
	{
		SC_METHOD(muxing);
		sensitive << ain << sel;
	}
	void muxing();
};
