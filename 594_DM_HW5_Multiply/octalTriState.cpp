#include "octalTriState.h"

void octalTriState::muxing() {
	if(sel=='1') yout=ain; else yout="ZZZZZZZZ";
}
