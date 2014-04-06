#include <stdio.h>
#include "Bytecode.h"
#include "iOR.h"
#include "CException.h"

unsigned char FSR[0x1000];

int iorwf(Bytecode *code) {

		/*
		*	Create a ior gate function WREG to F 
		*	save the value in File Register or WREG
		*	Throw:op_2error range from -5 to 1
		*		  op_3error when having -2 -3 W or F
		*		  overRange when the range over from 0 to 255
		*	Input: BSR value,ACCESS value and FSR[code.operand1] value
		*	Return: value into BSR,ACCESS or WREG
		*/


	int temp;
	FSR[STATUS] = 0;
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
	if(code->operand1<0x000){
			Throw(overRange);
	}
	if( code->operand1>0xfff){
		printf("you have exceed range!!");
	}
	

	else if(code->operand2 == BANKED || code->operand2 == -4){
			if(code->operand3 == -1){
				FSR[(FSR[BSR]<<8)+code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]|FSR[WREG];
					if(((FSR[(FSR[BSR]<<8)+code->operand1]  & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
					if(FSR[(FSR[BSR]<<8)+code->operand1] == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag 
					return (code->absoluteAddress)+1;
			}
	}
	else if(code->operand2 == ACCESS || code->operand2 == -5){
			if(code->operand3 == -1){
					if(code->operand1>=80){
						FSR[((0xf)<<8)+code->operand1] = FSR[((0xf)<<8)+code->operand1]|FSR[WREG];
							if(((FSR[((0xf)<<8)+code->operand1]  & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
							if(FSR[((0xf)<<8)+code->operand1]  == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag
							return (code->absoluteAddress)+1;						
					}
					else{
						FSR[code->operand1] = FSR[code->operand1]|FSR[WREG];
							if(((FSR[code->operand1]  & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
							if(FSR[code->operand1]  == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag
							return (code->absoluteAddress)+1;
					}
				}
			
	}
	else if(code->operand2 == -1 && code->operand3 == -1){
			if(code->operand1>=80){
				FSR[((0xf)<<8)+code->operand1] = FSR[((0xf)<<8)+code->operand1]|FSR[WREG];
					if(((FSR[((0xf)<<8)+code->operand1]  & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
					if(FSR[((0xf)<<8)+code->operand1]  == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag 
					return (code->absoluteAddress)+1;
			}
			else{
				FSR[code->operand1] = FSR[code->operand1]|FSR[WREG];
					if(((FSR[code->operand1]  & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
					if(FSR[code->operand1]  == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag
					return (code->absoluteAddress)+1;
			}
	}
	

	else if(code->operand2 == 0 || code->operand2 == W || code->operand2 == -2){
			if(code->operand3 == 0 || code->operand3 == ACCESS || code->operand2 == -5){
				if(code->operand1>=80){
					FSR[WREG] = FSR[((0xf)<<8)+code->operand1]|FSR[WREG];
						if(((FSR[WREG] & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
						if(FSR[WREG] == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag
						return (code->absoluteAddress)+1;
				}
				else{
					FSR[WREG] = FSR[code->operand1]|FSR[WREG];
						if(((FSR[WREG] & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
						if(FSR[WREG] == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag
						return (code->absoluteAddress)+1;
				}	
			}
			else if(code->operand3 == 1 || code->operand3 == BANKED || code->operand2 == -4){
				if(FSR[BSR]>15){
					Throw(bsrRange);
				}
				else{
					FSR[WREG]=FSR[(FSR[BSR]<<8)+code->operand1]|FSR[WREG];
						if(((FSR[WREG] & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
						if(FSR[WREG] == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag
						return (code->absoluteAddress)+1;
				}
			}
			else{
				Throw(op_error);
			}
	}
	

	else if(code->operand2 == 1 || code->operand2 == F || code->operand2 == -3){
			if(code->operand3 == 0 || code->operand3 == ACCESS || code->operand3 == -5){
				if(code->operand1>=80){
					FSR[((0xf)<<8)+code->operand1] = FSR[((0xf)<<8)+code->operand1]|FSR[WREG];
						if(((FSR[((0xf)<<8)+code->operand1]  & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
						if(FSR[((0xf)<<8)+code->operand1]  == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag 
						return (code->absoluteAddress)+1;
				}
				else{
					FSR[code->operand1] = FSR[code->operand1]|FSR[WREG];
						if(((FSR[code->operand1]  & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
						if(FSR[code->operand1]  == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag
						return (code->absoluteAddress)+1;
				}	
			}
			else if(code->operand3 == 1 || code->operand3 == BANKED || code->operand2 == -4){
				if(FSR[BSR]>15){
					Throw(bsrRange);
				}
				else{
					FSR[(FSR[BSR]<<8)+code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]|FSR[WREG];
						if(((FSR[(FSR[BSR]<<8)+code->operand1]  & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
						if(FSR[(FSR[BSR]<<8)+code->operand1] == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag 
						return (code->absoluteAddress)+1;
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

			
			
		
			// if(code->operand1>0x100 || code->operand1<0xf7f){
		// if(code->operand3 == ACCESS || code->operand2 == ACCESS){
			// Throw(op_error);
		// }
		// else if(code->operand3 == -1 || code->operand2 == -1){
			// FSR[code->operand1] = FSR[code->operand1]|FSR[WREG];
		// }
	// }
		
		
		
		
	

	

	
