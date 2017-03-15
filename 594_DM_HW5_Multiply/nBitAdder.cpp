#include "nBitAdder.h"

void nBitAdder::adding() {

	sc_uint<9> ires;
	sc_lv<9> res;
	ires = (sc_uint<8>)ain + (sc_uint<8>)bin;
	if(ci=='1')
		res=ires+1;
	else res=ires;
	addout=res.range(7,0);
	co=res[8];	
}
