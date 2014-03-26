#include <stdio.h>
#include "Bytecode.h"
#include "iOR.h"
#include "CException.h"

unsigned char FSR[0x1000];

void  iorwf(Bytecode *code) {
	int temp;
	
	if(code->operand2 == -1 && code->operand3 == -1){
				code->operand2 = F;
				code->operand3 = ACCESS;
	}
	else if(code->operand2 == BANKED && code->operand3 == -1){
				code->operand2 = BANKED;
				code->operand2 = -4;
	}
	else if(code->operand2 == ACCESS && code->operand3 == -1){
				code->operand2 = ACCESS;
				code->operand2 = -5;
	}
	else if(code->operand2 == -1 && code->operand3 != -1){
				code->operand2 = F;
	}
	else if(code->operand2 != -1 && code->operand3 == -1){
				code->operand3 = ACCESS;
	}
	
	if(code->operand2 <-5 || code->operand2>1){
			Throw(op_2error);
	}
	if(code->operand3 == -2 || code->operand3 == -3 || code->operand3 == W || code->operand3 == F){
			Throw(op_3error);
	}
	if(code->operand1<=0 || code->operand1>=255){
			Throw(overRange);
	}
	else if(code->operand2 == BANKED || code->operand2 == -4){
			if(code->operand3 == -1){
				FSR[code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^FSR[WREG];
			}
	}
	else if(code->operand2 == ACCESS || code->operand2 == -5){
			if(code->operand3 == -1){
				if(code->operand1>=80){
					FSR[code->operand1] = FSR[((0xf)<<8)+code->operand1]^FSR[WREG];
				}
				else{
					FSR[code->operand1] = FSR[code->operand1]^FSR[WREG];
				}
			}
	}
	else if(code->operand2 == -1 && code->operand3 == -1){
			if(code->operand1>=80){
				FSR[code->operand1] = FSR[((0xf)<<8)+code->operand1]^FSR[WREG];
			}
			else{
				FSR[code->operand1] = FSR[code->operand1]^FSR[WREG];
			}
	}
	
	//op2 == 0, op3 == 0
	else if(code->operand2 == 0 || code->operand2 == W || code->operand2 == -2){
			if(code->operand3 == 0 || code->operand3 == ACCESS || code->operand2 == -5){
				if(code->operand1>=80){
					FSR[WREG] = FSR[((0xf)<<8)+code->operand1]^FSR[WREG];
				}
				else{
					FSR[WREG] = FSR[code->operand1]^FSR[WREG];
				}	
			}
			else if(code->operand3 == 1 || code->operand3 == BANKED || code->operand2 == -4){
				if(FSR[BSR]>15){
					Throw(bsrRange);
				}
				else{
					temp = FSR[(FSR[BSR]<<8)+code->operand1]^FSR[WREG];
					FSR[WREG] = temp;
				}
			}
			else{
				Throw(op_error);
			}
	}
	
	//op2 == 1, op3 == 0
	else if(code->operand2 == 1 || code->operand2 == F || code->operand2 == -3){
			if(code->operand3 == 0 || code->operand3 == ACCESS || code->operand3 == -5){
				if(code->operand1>=80){
					FSR[code->operand1] = FSR[((0xf)<<8)+code->operand1]^FSR[WREG];
				}
				else{
					FSR[code->operand1] = FSR[code->operand1]^FSR[WREG];
				}	
			}
			else if(code->operand3 == 1 || code->operand3 == BANKED || code->operand2 == -4){
				if(FSR[BSR]>15){
					Throw(bsrRange);
				}
				else{
					temp = FSR[(FSR[BSR]<<8)+code->operand1]^FSR[WREG];
					FSR[code->operand1] = temp;
				}
			}
			
			else{
				Throw(op_error);
			}
	}
	
	else{
			Throw(op_error);
	}
	

}

			
			
		
		
		
		
		
		
	

	

	
