// uCounterRaEL: D Register with an asynchronous Reset and an Enable

#include <systemc.h>

SC_MODULE(uCounterRaEL)
{
	sc_in<sc_logic> rst, clk, cen, pld;
	sc_in<sc_lv<8> > parin;
	sc_out<sc_lv<8> > cntout;

	SC_CTOR(uCounterRaEL)
	{
		SC_METHOD(counting);
		sensitive << rst << clk;
	}
	void counting();
};
