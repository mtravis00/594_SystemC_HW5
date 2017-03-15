#include "rShifterRaEL.h"

void rShifterRaEL::shifting()
{
	if (rst=='1')
	{
			shftout = sc_lv<8>("00000000");
	}
	else if (clk->event() && (clk=='1'))
	{
		if(pld=='1') shftout = parin;
		else if(sen=='1') shftout= (sc_lv<8>)(sin,((sc_lv<8>)shftout).range(7,1));
	}	
}