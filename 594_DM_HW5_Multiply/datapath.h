#include "dRegisterRaE.h"
#include "andGate.h"
#include "nBitAdder.h"
#include "octalMux2to1.h"
#include "octalTriState.h"
#include "rShifterRaEL.h"

SC_MODULE(datapath)
{
	sc_in<sc_logic> clk, clr_P, load_P, load_B, msb_out, lsb_out, sel_sum, load_A, shift_A, start, rst;
	sc_inout<sc_lv<8> > data;
	sc_out<sc_logic> A0;

	sc_signal<sc_lv<8> > sum, ShiftAdd, A, B, P, pIn;
	sc_lv<8> ShiftAddClr;
	sc_signal<sc_logic> co, andOut, ci, ShiftAdd0;	

	andGate* andG;
	nBitAdder* adder;
	octalMux2to1* mux;
	octalTriState* msbTriState;
	octalTriState* lsbTriState;
	dRegisterRaE* regB;
	dRegisterRaE* regP;
	rShifterRaEL* sRegA;      		           
         
	void datapath_func();
	void datapath_disp();
	
	SC_CTOR(datapath)
	{
		andG = new andGate("andG_Instance");
			andG->a(co);
			andG->b(sel_sum);
			andG->y(andOut);

		adder = new nBitAdder("adder_Instance");
			adder->ain(B);
			adder->bin(P);
			adder->ci(rst);
			adder->addout(sum);
			adder->co(co);

		mux = new octalMux2to1("mux_Instance");
			mux->sel(sel_sum);
			mux->ain(P);
			mux->bin(sum);
			mux->yout(ShiftAdd);
			
		msbTriState = new octalTriState("msbTriState_Instance");
			msbTriState->sel(msb_out);
			msbTriState->ain(P);
			msbTriState->yout(data);

		lsbTriState = new octalTriState("lsbTriState_Instance");
			lsbTriState->sel(lsb_out);
			lsbTriState->ain(A);
			lsbTriState->yout(data);

		sRegA = new rShifterRaEL("sRegA_Instance");
			sRegA->rst(rst);
			sRegA->clk(clk);
			sRegA->sen(shift_A);
			sRegA->pld(load_A);
			sRegA->sin(ShiftAdd0);
			sRegA->parin(data);
			sRegA->shftout(A);

		regB = new dRegisterRaE("regB_Instance");
			regB->rst(rst);
			regB->clk(clk);
			regB->cen(load_B);
			regB->regin(data);
			regB->regout(B);

		regP = new dRegisterRaE("regP_Instance");
			regP->rst(clr_P);
			regP->clk(clk);
			regP->cen(load_P);
			regP->regin(pIn);
			regP->regout(P);

		SC_METHOD(datapath_func); 
		sensitive << clr_P << A << ShiftAdd << andOut;

		SC_METHOD(datapath_disp); 
		sensitive << clk;
	}
};
