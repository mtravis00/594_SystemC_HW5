#include "busPad.h"

void busPad::padding() {
//
//	sc_uint<9> ires;
	int stop;

	sc_lv<4> pad = (sc_lv<4>) (SC_LOGIC_0);
	cout << "pad value " << pad << endl;

	sc_lv<8> out;
	sc_lv<4> in;

	in = ain.read();
	cout << "input  " << in << endl;

	out = (pad, in);
	cout << "output " << out << endl;

	padded_out = (sc_lv<8>)out;
	cout << "padded_out " << padded_out << endl;
	cin >> stop;

}
