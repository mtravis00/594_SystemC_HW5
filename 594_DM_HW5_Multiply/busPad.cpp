#include "busPad.h"

void busPad::padding() {
//
//	sc_uint<9> ires;
	int stop;

	//sc_lv<8> var;

//	var = (sc_lv<4>)ain;
	//cout << "var " << var << endl;
	padded_out = (sc_lv<4>)ain;
	cout << "padded_out " << padded_out << endl;
	cin >> stop;

}
