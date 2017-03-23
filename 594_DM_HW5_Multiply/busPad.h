

#include <systemc.h>

SC_MODULE(busPad)
{
	sc_in<sc_lv<4> > ain;
	sc_out<sc_lv<8> > padded_out;
	

	SC_CTOR(busPad)
	{
		SC_METHOD(padding);
		sensitive << ain ;
	}
	void padding();
};
