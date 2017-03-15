// and gate

#include <systemc.h>

SC_MODULE(andGate)
{
	sc_in<sc_logic > a, b;
	sc_out<sc_logic > y;

	SC_CTOR(andGate)
	{
		SC_METHOD(andFunc);
		sensitive << a << b ;
	}
	void andFunc();
};

