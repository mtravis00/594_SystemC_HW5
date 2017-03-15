#include "multiplier_TB.h"

void multiplier_TB::clocking() {
	int i;
	wait(0,SC_NS);
	clk=sc_logic('0');
	wait(50,SC_NS);
	for(i=0;i<=20;i++) {
			clk = (sc_logic)'1';
		wait(50,SC_NS);
			clk = (sc_logic)'0';
		wait(50,SC_NS);
    }
}
void multiplier_TB::outputting() {
	if (msb_out == '1') 
		multiplier_result(15,8) = databus.read();
	if (lsb_out == '1')
		multiplier_result(7,0) = databus.read();

}

void multiplier_TB::bussing() {
	//databus = temp_data;
	
}

void multiplier_TB::resetting(){			
	rst = (sc_logic)'0';	
	wait(30,SC_NS);
	rst = (sc_logic)'1';
	wait(30,SC_NS);
	rst = (sc_logic)'0';	
}

void multiplier_TB::starting() {
	start = (sc_logic)'0';
	//temp_data = "zzzzzzzz";
	wait(110,SC_NS);
	for(int i = 0; i < 1; i++){		
			start = (sc_logic)'1';
		wait(70,SC_NS);
			start = (sc_logic)'0';
		wait(1350,SC_NS);
	}	
	/*wait(2257,SC_NS);
		start=(sc_logic)'1';
	wait(102,SC_NS);
		start=(sc_logic)'0';*/
}

void multiplier_TB::inputting() {
	int i, val; 
	//temp_data = "zzzzzzzz";
	databus = "zzzzzzzz";
	for(i=0; i < 1; i++) {
		wait(150,SC_NS);
		/*val = abs(rand()) % 255;
		databus = (sc_lv<8>)val;
		wait(1000,SC_NS);*/
		databus = "00001001";
		
		wait(90,SC_NS);		
		databus = "00001101";
		
		wait(120,SC_NS);		
		databus = "zzzzzzzz";
		
	}
	wait(200,SC_NS);		
}

void multiplier_TB::displaying() {
	cout <<"At: "<<sc_time_stamp()<<" multiplier result changes to: "<<multiplier_result<<'\n';
}