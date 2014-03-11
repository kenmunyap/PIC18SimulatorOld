#include <stdio.h>
#include "Bytecode.h"
#include "dCFSNZ.h"


unsigned char FSR[0x1000];

void  dcfsnz(Bytecode *code) {

	
	if(code->operand2 == 0){
		if(code->operand3 == 0){
			if((code->operand1)-1){
				code->operand1 != 0;
				}
			else{
				code->operand1 == 0;
				FSR[WREG] = FSR[code->operand1];
				}
		}
		else{
			if((code->operand1)-1){
				code->operand1 != 0;
				}
			else{
				code->operand1 == 0;
				FSR[WREG] =  FSR[(FSR[BSR]<<8)+code->operand1];
				}
		}
	}
	else{
		if(code->operand3 == 1){
			if((code->operand1)-1){
				code->operand1 != 0;
				}
			else{
				code->operand1 == 0;
				FSR[code->operand1] = FSR[code->operand1];
				}
		}
		else{
			if((code->operand1)-1){
				code->operand1 != 0;
				}
			else{
				code->operand1 == 0;
				FSR[code->operand1] =  FSR[(FSR[BSR]<<8)+code->operand1];
				}
		}
	}
	
}		
		
		
		
		
		
		
		
		
		
		
		