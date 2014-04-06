#include <stdio.h>
#include "Bytecode.h"
#include "dAW.h"
#include "CException.h"

unsigned char FSR[0x1000];
	
		
		/*
		*	Create a DAW function it is decimal adjust w register 
		*	save the value in WREG
		*	Throw: op_error when operand1 operand2 and operand3 is not blank
		*	Input: The 1st 4 bit of WREG check DC value and last 4 bit check C
		*	Return: return value into WREG
		*/




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
