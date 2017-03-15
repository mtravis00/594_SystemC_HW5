#include "uCounterRaEL.h"

void uCounterRaEL::counting()
{
	if (rst=='1')
		{
			cntout = sc_lv<8>(0);
		}
		else if (clk->event() && (clk=='1'))
		{
			if(pld=='1') cntout = parin;
			else if(cen=='1') 
				cntout=(sc_uint<8>)cntout+1;
		}
	cout <<"At: "<<sc_time_stamp()<<"counter:  "<<cntout<<'\n';
}