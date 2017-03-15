#include "datapath.h"
#include "controller.h"

SC_MODULE(multiplier)
{
	sc_in<sc_logic> clk, start, rst;
	sc_inout<sc_lv<8> > databus;
	sc_out<sc_logic> lsb_out, msb_out, done;

	sc_signal<sc_logic> clr_P, load_P, load_B, sel_sum, load_A, shift_A, A0;

	datapath* datapathInst;
	controller* controllerInst;	

	SC_CTOR(multiplier)
	{
		datapathInst = new datapath("datapathInst");
			datapathInst->clk(clk);
			datapathInst->rst(rst);
			datapathInst->clr_P(clr_P);
			datapathInst->load_P(load_P);
			datapathInst->load_B(load_B);
			datapathInst->msb_out(msb_out);
			datapathInst->lsb_out(lsb_out);
			datapathInst->sel_sum(sel_sum);
			datapathInst->load_A(load_A);
			datapathInst->shift_A(shift_A);
			datapathInst->A0(A0);
			datapathInst->data(databus);
			datapathInst->start(start);

		controllerInst = new controller("controllerInst");
			controllerInst->clk(clk);
			controllerInst->rst(rst);
			controllerInst->start(start);
			controllerInst->A0(A0);
			controllerInst->clr_P(clr_P);
			controllerInst->load_P(load_P);
			controllerInst->load_B(load_B);
			controllerInst->msb_out(msb_out);
			controllerInst->lsb_out(lsb_out);
			controllerInst->sel_sum(sel_sum);
			controllerInst->load_A(load_A);
			controllerInst->shift_A(shift_A);
			controllerInst->done(done);
	}
};
