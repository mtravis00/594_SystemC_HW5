// dRegisterRaE: D Register with an asynchronous Reset and an Enable

#include <systemc.h>

SC_MODULE(dRegisterRaE)
{
	sc_in<sc_logic> rst, clk, cen;
	sc_in<sc_lv<8> > regin;
	sc_out<sc_lv<8> > regout;

	SC_CTOR(dRegisterRaE)
	{
		SC_METHOD(registering);
		sensitive << rst << clk;
	}
	void registering();
};
