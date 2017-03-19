#include "dRegisterRaE.h"
#include "andGate.h"
#include "nBitAdder.h"
#include "octalMux2to1.h"
#include "octalTriState.h"
#include "rShifterRaEL.h"

SC_MODULE(datapath)
{
	sc_in<sc_logic> oe,clk, clr_P, load_P, load_B,load_A, start, rst;
	sc_in<sc_lv<8> > A_IN, B_IN;

	sc_out<sc_lv<8>> W;

	sc_signal<sc_lv<8> > sum, ShiftAdd, A, B, P;
	
	sc_signal<sc_logic> co, andOut, ci, ShiftAdd0;	

	andGate* andG;
	nBitAdder* adder;
	octalMux2to1* mux;
	octalTriState* msbTriState;
	octalTriState* TriState;
	dRegisterRaE* regA;
	dRegisterRaE* regB;
	dRegisterRaE* regP;
//	rShifterRaEL* sRegA;      		           
         
	void datapath_func();
	void datapath_disp();
	
	SC_CTOR(datapath)
	{
		
		adder = new nBitAdder("adder_Instance");
			adder->ain(A);
			adder->bin(P);
			adder->ci(rst);
			adder->addout(sum);
			adder->co(co);
	
		TriState = new octalTriState("lsbTriState_Instance");
			TriState->sel(oe);
			TriState->ain(P);
			TriState->yout(W);
		
		regA = new dRegisterRaE("regA_Instance");
			regA->rst(rst);
			regA->clk(clk);
			regA->cen(load_A);
			regA->regin(A_IN);
			regA->regout(A);

		regB = new dRegisterRaE("regB_Instance");
			regB->rst(rst);
			regB->clk(clk);
			regB->cen(load_B);
			regB->regin(B_IN);
			regB->regout(B);

		regP = new dRegisterRaE("regP_Instance");
			regP->rst(clr_P);
			regP->clk(clk);
			regP->cen(load_P);
			regP->regin(sum);
			regP->regout(P);

	//	SC_METHOD(datapath_func); 
	//	sensitive << clr_P << A << ShiftAdd << andOut;

		SC_METHOD(datapath_disp); 
		sensitive << clk;
	}
};
