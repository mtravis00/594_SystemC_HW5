#include "dRegisterRaE.h"

void dRegisterRaE::registering()
{
	if (rst=='1')
		{
			regout = sc_lv<8>("00000000");
		}
		else if (clk->event() && (clk=='1'))
		{
			if(cen=='1') regout = regin;
		}	
}