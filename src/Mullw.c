#include <stdio.h>
#include "Bytecode.h"
#include "Mullw.h"
#include <inttypes.h>
#include "CException.h"

unsigned char FSR[0x1000];

void  mullw(Bytecode *code) {
	
	int maskH = 0xFF00;
	int maskL = 0x00FF;
	int temp1;
	

		

	if(code->operand1 <= 0 || code->operand1 >= 255){
				Throw(overRange);
	}
	if(code->operand2 != -1 && code->operand3 != -1){
		Throw(op_error);
	}
	if(code->operand2 != -1){
			Throw(op_2error);
	}
	if(code->operand3 != -1){
			Throw(op_3error);
	}
	else{
		temp1 = (code->operand1)*(FSR[WREG]);
		
		FSR[PRODH] = ((maskH&temp1)>>8);
		FSR[PRODL] = maskL&temp1;
	}
}