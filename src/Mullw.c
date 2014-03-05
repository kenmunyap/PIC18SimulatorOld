#include <stdio.h>
#include "Bytecode.h"
#include "Mullw.h"
#include <inttypes.h>

char FSR[0x1000];

void  mullw(Bytecode *code) {
	
	int maskH = 0xFF00;
	int maskL = 0x00FF;
	int temp1;
	temp1 = (code->operand1)*(FSR[WREG]);

	FSR[PRODH] = ((maskH&temp1)>>8);
	FSR[PRODL] = maskL&temp1;
	
}