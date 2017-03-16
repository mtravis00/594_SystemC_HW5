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
	octalTriState* TriState;
	dRegisterRaE* regA;
	dRegisterRaE* regB;
	dRegisterRaE* regP;
	rShifterRaEL* sRegA;      		           
         
	void datapath_func();
	void datapath_disp();
	
	SC_CTOR(datapath)
	{
		
		adder = new nBitAdder("adder_Instance");
			adder->ain(B);
			adder->bin(P);
			adder->ci(rst);
			adder->addout(sum);
			adder->co(co);
	
		TriState = new octalTriState("lsbTriState_Instance");
			TriState->sel(lsb_out);
			TriState->ain(A);
			TriState->yout(data);
		
		regA = new dRegisterRaE("regB_Instance");
			regA->rst(rst);
			regA->clk(clk);
			regA->cen(load_A);
			regA->regin(data);
			regA->regout(A);

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
