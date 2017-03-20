#include "controller.h"

void controller::comb_func ()
{
   n_state = idle; 
   oe = SC_LOGIC_0;
   clr_P = SC_LOGIC_0;
   load_P = SC_LOGIC_0;
   load_B = SC_LOGIC_0; 
 //  msb_out = SC_LOGIC_0;
 //  lsb_out = SC_LOGIC_0; 
 //  sel_sum = SC_LOGIC_0;
   load_A = SC_LOGIC_0;
 //  shift_A = SC_LOGIC_0;
   done = SC_LOGIC_0;
   enable_Count = SC_LOGIC_0;
   pld = SC_LOGIC_0;
   parin = "00000000";

   int pause;

   switch (p_state) {
		 case (idle)	: 
			 if(start == '0'){				 
				 n_state = idle;
			 }else if (start == '1') {
				 load_A = SC_LOGIC_1;
				 load_B = SC_LOGIC_1;
				 clr_P = SC_LOGIC_1;
				 load_P = SC_LOGIC_1;
				 n_state = m;
			 }
			 break;
	//	 case (init)	: 
	//		 load_B = SC_LOGIC_1;
	//		 n_state = m;
	//		 break;
		 case (m)		: 			  
			 count = cnt_Out.read();
			 limit = B.read();
			// cout << "bout is  **********************" << limit << endl;
		//	 cout << "count is **********************" << count << endl;
			// cin >> pause;
			 // if(cnt_Out.read() == "00000111"){
			 if(count  == limit ){
				 
				 load_P = SC_LOGIC_0;
				 n_state = rslt1;
				 enable_Count = SC_LOGIC_0;
			 }else{
				 //shift_A = SC_LOGIC_1;
				 load_P = SC_LOGIC_1;
				 enable_Count = SC_LOGIC_1;
				 n_state = m;
			 }
			 break;
		 case (rslt1)	: 
			 oe = SC_LOGIC_1;
			 done = SC_LOGIC_1;
			 n_state = idle;
			 break;
	/*	 case (rslt2)	: 
			 msb_out = SC_LOGIC_1;
			 done = SC_LOGIC_1;
			 n_state = idle;
			 break;*/
		 default		:
			 clr_P = SC_LOGIC_0;
			 load_P = SC_LOGIC_0;
			 load_B = SC_LOGIC_0; 
		//	 msb_out = SC_LOGIC_0;
		//	 lsb_out = SC_LOGIC_0; 
		//	 sel_sum = SC_LOGIC_0;
			 load_A = SC_LOGIC_0;
		//	 shift_A = SC_LOGIC_0;
			 enable_Count = SC_LOGIC_0;
			 done = SC_LOGIC_0;
			 break;		
   }   
}


void controller::seq_func ()
{
   while (1) {
      if (rst == '1') 
		  p_state = idle;
      else		  
		  p_state = n_state;
      wait ();
   }
}
      
   