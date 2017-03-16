#include "multiplier_TB.h"

int sc_main(int argc, char ** argv)
{
	multiplier_TB multTB1 ("multTB1_Instance");

	sc_trace_file* VCDFile;
	VCDFile = sc_create_vcd_trace_file("multiplier");
			sc_trace(VCDFile, multTB1.clk, "clk");
			sc_trace(VCDFile, multTB1.rst, "rst");
			sc_trace(VCDFile, multTB1.start, "start");
			sc_trace(VCDFile, multTB1.databus, "databus");
			sc_trace(VCDFile, multTB1.lsb_out, "lsb_out");
			sc_trace(VCDFile, multTB1.msb_out, "msb_out");
			sc_trace(VCDFile, multTB1.done, "done");
			

	sc_start(1700,SC_NS);
	return 0;
}
