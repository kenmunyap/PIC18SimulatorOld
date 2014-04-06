#include <stdio.h>
#include "Bytecode.h"
#include "rRCF.h"
#include "CException.h"

unsigned char FSR[0x1000];

int  rrcf(Bytecode *code) {

		/*
		*	Create a rotate with carry function for WREG to F 
		*	save the value in File Register or WREG
		*	Throw:op_2error range from -5 to 1
		*		  op_3error when having -2 -3 W or F
		*		  overRange when the range over from 0 to 255
		*	Input: FSR[STATUS] = carry
		*	Return: value into BSR,ACCESS or WREG
		*/

	
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
	if(code->operand1<=0){
			Throw(overRange);
	}
	if( code->operand1 >= 0xff){
		printf("you have exceed range!!");
	}
	else if(code->operand2 == BANKED || code->operand2 == -4){
			if(code->operand3 == -1){
				
				temp = FSR[(FSR[BSR]<<8)+code->operand1] & 0b00000001; 
				FSR[(FSR[BSR]<<8)+code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1] >> 1;		
				FSR[(FSR[BSR]<<8)+code->operand1] = ((FSR[STATUS] <<7) & 0b10000000) | FSR[(FSR[BSR]<<8)+code->operand1] ;
				FSR[STATUS]  = FSR[STATUS] | temp;
					if((temp & 0b00000001) == 1 ) { FSR[STATUS] = FSR[STATUS] | 0b00000001;}
					if(((FSR[(FSR[BSR]<<8)+code->operand1]  & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
					if(FSR[(FSR[BSR]<<8)+code->operand1] == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag
					return (code->absoluteAddress)+1;
			}
	}
	else if(code->operand2 == ACCESS || code->operand2 == -5){
			if(code->operand3 == -1){
				if(code->operand1>=80){
					temp = FSR[((0xf)<<8)+code->operand1] & 0b00000001; 
					FSR[((0xf)<<8)+code->operand1] = FSR[((0xf)<<8)+code->operand1] >> 1;		
					FSR[((0xf)<<8)+code->operand1] = ((FSR[STATUS] <<7) & 0b10000000) | FSR[((0xf)<<8)+code->operand1] ;
					FSR[STATUS]  = FSR[STATUS] | temp;
						if((temp & 0b00000001) == 1) { FSR[STATUS] = FSR[STATUS] | 0b00000001;}
						if(((FSR[((0xf)<<8)+code->operand1]  & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
						if(FSR[((0xf)<<8)+code->operand1]  == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag
						return (code->absoluteAddress)+1;
				}
				else{
					temp = FSR[code->operand1] & 0b00000001; 
					FSR[code->operand1] = FSR[code->operand1] >> 1;		
					FSR[code->operand1] = ((FSR[STATUS] <<7) & 0b10000000) | FSR[code->operand1] ;
					FSR[STATUS]  = FSR[STATUS] | temp;
						if((temp & 0b00000001) == 1) { FSR[STATUS] = FSR[STATUS] | 0b00000001;}
						if(((FSR[code->operand1]  & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
						if(FSR[code->operand1]  == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag
						return (code->absoluteAddress)+1;
				}
			}
	}
	else if(code->operand2 == -1 && code->operand3 == -1){
			if(code->operand1>=80){
				temp = FSR[((0xf)<<8)+code->operand1] & 0b00000001; 
				FSR[((0xf)<<8)+code->operand1] = FSR[((0xf)<<8)+code->operand1] >> 1;		
				FSR[((0xf)<<8)+code->operand1] = ((FSR[STATUS] <<7) & 0b10000000) | FSR[((0xf)<<8)+code->operand1] ;
				FSR[STATUS]  = FSR[STATUS] | temp;
					if((temp & 0b00000001) == 1) { FSR[STATUS] = FSR[STATUS] | 0b00000001;}
					if(((FSR[((0xf)<<8)+code->operand1]  & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
					if(FSR[((0xf)<<8)+code->operand1]  == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag
					return (code->absoluteAddress)+1;
			}
			else{
				temp = FSR[code->operand1] & 0b00000001; 
				FSR[code->operand1] = FSR[code->operand1] >> 1;		
				FSR[code->operand1] = ((FSR[STATUS] <<7) & 0b10000000) | FSR[code->operand1] ;
				FSR[STATUS]  = FSR[STATUS] | temp;
					if((temp & 0b00000001) == 1) { FSR[STATUS] = FSR[STATUS] | 0b00000001;}
					if(((FSR[code->operand1]  & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
					if(FSR[code->operand1]  == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag
					return (code->absoluteAddress)+1;
			}
	}
	

	else if(code->operand2 == 0 || code->operand2 == W || code->operand2 == -2){
			if(code->operand3 == 0 || code->operand3 == ACCESS || code->operand2 == -5){
				if(code->operand1>=80){
					temp = FSR[((0xf)<<8)+code->operand1] & 0b00000001; 
					FSR[((0xf)<<8)+code->operand1] = FSR[((0xf)<<8)+code->operand1] >> 1;		
					FSR[WREG] = ((FSR[STATUS] <<7) & 0b10000000) | FSR[((0xf)<<8)+code->operand1] ;
					FSR[STATUS]  = FSR[STATUS] | temp;
						if((temp & 0b00000001) == 1) { FSR[STATUS] = FSR[STATUS] | 0b00000001;}
						if(((FSR[WREG] & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
						if(FSR[WREG] == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag
						return (code->absoluteAddress)+1;
				}
				else{
					temp = FSR[code->operand1] & 0b00000001; 
					FSR[code->operand1] = FSR[code->operand1] >> 1;		
					FSR[WREG] = ((FSR[STATUS] <<7) & 0b10000000) | FSR[code->operand1] ;
					FSR[STATUS]  = FSR[STATUS] | temp;
						if((temp & 0b00000001) == 1) { FSR[STATUS] = FSR[STATUS] | 0b00000001;}
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
					temp = FSR[code->operand1] & 0b00000001; 
					FSR[code->operand1] = FSR[code->operand1] >> 1;		
					FSR[WREG] = ((FSR[STATUS] <<7) & 0b10000000) | FSR[code->operand1] ;
					FSR[STATUS]  = FSR[STATUS] | temp;
						if((temp & 0b00000001) == 1) { FSR[STATUS] = FSR[STATUS] | 0b00000001;}
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
					temp = FSR[((0xf)<<8)+code->operand1] & 0b00000001; 
					FSR[((0xf)<<8)+code->operand1] = FSR[((0xf)<<8)+code->operand1] >> 1;		
					FSR[((0xf)<<8)+code->operand1] = ((FSR[STATUS] <<7) & 0b10000000) | FSR[((0xf)<<8)+code->operand1] ;
					FSR[STATUS]  = FSR[STATUS] | temp;
						if((temp & 0b00000001) == 1) { FSR[STATUS] = FSR[STATUS] | 0b00000001;}
						if(((FSR[((0xf)<<8)+code->operand1]  & 0b10000000)>>7) == 1) {	FSR[STATUS] = FSR[STATUS] | 0b10000000; } // check N flag
						if(FSR[((0xf)<<8)+code->operand1]  == 0) {FSR[STATUS] = FSR[STATUS] | 0b00000100;} // check Z flag
						return (code->absoluteAddress)+1;
				}
				else{
					temp = FSR[code->operand1] & 0b00000001; 
					FSR[code->operand1] = FSR[code->operand1] >> 1;		
					FSR[code->operand1] = ((FSR[STATUS] <<7) & 0b10000000) | FSR[code->operand1] ;
					FSR[STATUS]  = FSR[STATUS] | temp;
						if((temp & 0b00000001) == 1) { FSR[STATUS] = FSR[STATUS] | 0b00000001;}
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
					temp = FSR[(FSR[BSR]<<8)+code->operand1] & 0b00000001; 
					FSR[(FSR[BSR]<<8)+code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1] >> 1;		
					FSR[(FSR[BSR]<<8)+code->operand1] = ((FSR[STATUS] <<7) & 0b10000000) | FSR[(FSR[BSR]<<8)+code->operand1] ;
					FSR[STATUS]  = FSR[STATUS] | temp;
						if((temp & 0b00000001) == 1) { FSR[STATUS] = FSR[STATUS] | 0b00000001;}
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


	
		
