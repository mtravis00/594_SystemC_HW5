// rShifterRaEL: right Shiftregister with an asynchronous
// Reset, shift Enable, and parallel Load

#include <systemc.h>

SC_MODULE(rShifterRaEL)
{
	sc_in<sc_logic> rst, clk, sen, pld;
	sc_in<sc_logic> sin;
	sc_in<sc_lv<8> > parin;
	sc_out<sc_lv<8> > shftout;

	void shifting();

	SC_CTOR(rShifterRaEL)
	{
		SC_METHOD(shifting);
		sensitive << rst << clk;
	}
};
