#include "octalMux2to1.h"

void octalMux2to1::muxing() {
	if(sel=='1') 
		yout=bin;
	else yout=ain;	
}
