#include "multiplier.h"

SC_MODULE(multiplier_TB)
{
	sc_signal<sc_logic> start, clk, lsb_out, msb_out, done, rst;
	sc_signal_rv<8> databus, A_IN, B_IN, W;
	sc_signal<sc_lv<8> > temp_data;
	sc_lv<16>  multiplier_result;

	multiplier* mult;

	void starting();
	void resetting();
	void inputting();
	void outputting();
	void clocking();
	void bussing();
	void displaying();

	SC_CTOR(multiplier_TB)
	{
		mult = new multiplier("mult_Instance");
			mult->A_IN(A_IN);
			mult->B_IN(B_IN);
			mult->W(W);
			mult->clk(clk);
			mult->rst(rst);
			mult->start(start);
		//	mult->databus(databus);
		//	mult->lsb_out(lsb_out);
		//	mult->msb_out(msb_out);
			mult->done(done);

		SC_THREAD(starting);				
		SC_THREAD(resetting);				
		SC_THREAD(clocking);
		SC_THREAD(inputting);
		SC_THREAD(outputting);sensitive << clk;
		SC_THREAD(bussing); sensitive << temp_data;
		SC_METHOD(displaying); sensitive << done;// << msb_out << lsb_out;
	}
};
