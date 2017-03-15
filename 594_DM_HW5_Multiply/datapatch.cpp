#include "datapath.h"

void datapath::datapath_func() {
	/*if(start == '1')
		sum = "00000000";*/
	if(clr_P == '1')
		ShiftAddClr = ("00000000");
	else
		ShiftAddClr = ShiftAdd;
	A0 = A.read()[0];
	ShiftAdd0 = ShiftAddClr[0];	
	ci = SC_LOGIC_0;
	pIn = (andOut.read(), ShiftAddClr.range(7,1));
}

void datapath::datapath_disp(){
	cout <<"At: "<<sc_time_stamp()<<"	dp:	data	"<<data<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	clr_P	"<<clr_P<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	load_P	"<<load_P<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	load_B	"<<load_B<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	msb_out	"<<msb_out<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	lsb_out	"<<lsb_out<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	sel_sum	"<<sel_sum<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	load_A	"<<load_A<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	shift_A	"<<shift_A<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	start	"<<start<<'\n';	
	cout <<"At: "<<sc_time_stamp()<<"	dp:	A0		"<<A0<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	sum		"<<sum<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	shiftAdd	"<<ShiftAdd<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	shiftAddClr	"<<ShiftAddClr<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	A		"<<A<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	P		"<<P<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	B		"<<B<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	pIn		"<<pIn<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	co		"<<co<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	andOut	"<<andOut<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	ci		"<<ci<<'\n';
	cout <<"At: "<<sc_time_stamp()<<"	dp:	shiftAdd0	"<<ShiftAdd0<<'\n';
	
}
