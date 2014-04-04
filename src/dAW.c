#include <stdio.h>
#include "Bytecode.h"
#include "dAW.h"
#include "CException.h"

unsigned char FSR[0x1000];

int  daw(Bytecode *code) {
	int tempH = 0xF0;
	int tempL = 0x0F;
	int valueH = 0,valueL = 0;
	
	valueH = (FSR[WREG]&tempH)>>4;
	valueL = FSR[WREG]&tempL;
		
		if(code->operand1 != -1 || code->operand2 != -1 ||code->operand3 != -1){
			Throw(op_error);
		}else{
		
			if(valueL>9 || (FSR[STATUS]&0x01) == 0x01){
				valueL = valueL+6;
			}
			else{
				valueL = valueL;	
			}
			
			if(valueH>9 || (FSR[STATUS]&0x02) == 0x02){
				valueH = valueH+6;
				valueH = valueH<<4;	
			}
			else{
				valueH = valueH<<4;
			}
	
			FSR[WREG]=valueH+valueL;
			return (code->absoluteAddress)+1;
		}
		
	
}
