#include <systemc.h>
#include "uCounterRaEL.h"

SC_MODULE (controller) {
	sc_in<sc_logic> clk, A0, start, rst;
	sc_in <sc_lv<8>> B;
	sc_out<sc_logic> clr_P, load_P, load_B,load_A, oe,  done;	
	    
	enum states {idle, init, m, rslt1, rslt2};
    sc_signal <states> p_state, n_state;	
	sc_signal <sc_logic> enable_Count, pld;
	sc_signal <sc_lv<8> > cnt_Out, parin;	
	sc_uint<8> count, limit;
   
	uCounterRaEL* counter;

    SC_CTOR (controller) {
		counter = new uCounterRaEL("counter_Instance");
			counter->cen(enable_Count);
			counter->clk(clk);
			counter->cntout(cnt_Out);
			counter->parin(parin);
			counter->pld(pld);
			counter->rst(rst);			

        SC_METHOD (comb_func);
        sensitive << p_state << start << A0 << cnt_Out;

        SC_THREAD (seq_func);
        sensitive << clk.pos();
    }
    void comb_func ();
	void seq_func ();
};
