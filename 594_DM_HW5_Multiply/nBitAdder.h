// nBitAdder: n Bit adder with carry in and carry out

#include <systemc.h>

SC_MODULE(nBitAdder)
{
	sc_in<sc_lv<8> > ain, bin;
	sc_in<sc_logic> ci;
	sc_out<sc_lv<8> > addout;
	sc_out<sc_logic > co;

	SC_CTOR(nBitAdder)
	{
		SC_METHOD(adding);
		sensitive << ain << bin << ci;
	}
	void adding();
};
