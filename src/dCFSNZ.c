#include <stdio.h>
#include "Bytecode.h"
#include "dCFSNZ.h"
#include "CException.h"

unsigned char FSR[0x1000];

int  dcfsnz(Bytecode *code) {
	
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
	else if(code->operand2 != -1 && code->operand3 == -1){
				code->operand3 = ACCESS;
	}
	
	if(code->operand2 <-5 || code->operand2>1){
			Throw(op_2error);
	}
	if(code->operand3 == -2 || code->operand3 == -3 || code->operand3 == W || code->operand3 == F){
			Throw(op_3error);
	}
	if(code->operand1<=0){
			Throw(overRange);
	}
	if( code->operand1 > 0xfff){
		printf("you have exceed range!!");
	}
	
	
	
	else if(code->operand2 == BANKED || code->operand2 == -4){
			if(code->operand3 == -1){
				FSR[(FSR[BSR]<<8)+code->operand1] = (FSR[(FSR[BSR]<<8)+code->operand1])-1;	
			}
	}
	
	else if(code->operand2 == ACCESS || code->operand2 == -5){
			if(code->operand3 == -1){
				if(code->operand1>=80){
					FSR[((0xf)<<8)+code->operand1] = (FSR[((0xf)<<8)+code->operand1])-1;
					
				}
				else{
					FSR[code->operand1] = (FSR[code->operand1])-1;
				}
			}
	}
	else if(code->operand2 == -1 && code->operand3 == -1){
			if(code->operand1>=80){
				FSR[((0xf)<<8)+code->operand1] = (FSR[((0xf)<<8)+code->operand1])-1;
				
			}
			else{
				FSR[code->operand1] = (FSR[code->operand1])-1;
				
			}
	}
	

	else if(code->operand2 == 0 || code->operand2 == W || code->operand2 == -2){
			if(code->operand3 == 0 || code->operand3 == ACCESS || code->operand2 == -5){
				if(code->operand1>=80){
					FSR[WREG] = (FSR[((0xf)<<8)+code->operand1])-1;
				
				}
				else{
					FSR[WREG] = (FSR[code->operand1])-1;
					
				}	
			}
			else if(code->operand3 == 1 || code->operand3 == BANKED || code->operand2 == -4){
				if(FSR[BSR]>15){
					Throw(bsrRange);
				}
				else{
					FSR[WREG]=(FSR[(FSR[BSR]<<8)+code->operand1])-1;
				;
				}
			}
			else{
				Throw(op_error);
			}
	}
	

	else if(code->operand2 == 1 || code->operand2 == F || code->operand2 == -3){
			if(code->operand3 == 0 || code->operand3 == ACCESS || code->operand3 == -5){
				if(code->operand1>=80){
					FSR[((0xf)<<8)+code->operand1] = (FSR[((0xf)<<8)+code->operand1])-1;
					return (code->absoluteAddress)+1;
				}
				else{
					FSR[code->operand1] = (FSR[code->operand1])-1;
					return (code->absoluteAddress)+1;
				}	
			}
			else if(code->operand3 == 1 || code->operand3 == BANKED || code->operand2 == -4){
				if(FSR[BSR]>15){
					Throw(bsrRange);
				}
				else{
					FSR[(FSR[BSR]<<8)+code->operand1] = (FSR[(FSR[BSR]<<8)+code->operand1])-1;
				}
			}
			
			else{
				Throw(op_error);
			}
	}
	
	if(code->operand1>0x100 || code->operand1<0xf7f){
	
			if(code->operand2 == -1 && code->operand3 == -1){
				FSR[code->operand1] = (FSR[code->operand1])-1;
			}
			if((code->operand2 == 1 || code->operand2 == F) && code->operand3 == -1){
			
				FSR[(FSR[BSR]<<8)+code->operand1] = (FSR[(FSR[BSR]<<8)+code->operand1])-1;
				
			}
			if((code->operand2 == 0 || code->operand2 == W) && code->operand3 == -1){
			
				FSR[WREG]=(FSR[(FSR[BSR]<<8)+code->operand1])-1;	
			}
	}
	
	
	
	else{
			Throw(op_error);
	}
	
	/*	
		after the function only check
		check if the operand1 is not zero then skip return 1;
			  if zero not skip return 0;
	*/		  
					if(((FSR[code->operand1])-1)!= 0){
						return (code->absoluteAddress)+2;;
					}
					else if(((FSR[code->operand1])-1) == 0){
						return (code->absoluteAddress)+1;
					}
					else{
						Throw(op_error);
					}
	
}	
		
		
		
		
		
		
		
		
		
		