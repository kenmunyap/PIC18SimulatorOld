#include <stdio.h>
#include "Bytecode.h"
#include "POP.h"
#include "CException.h"

unsigned char FSR[0x1000];
int PIC18Stack[32];
int PC;

int  pop(Bytecode *code) {
		int temp,value;

		int temp0 = 0b111110000000000000000;
		int temp1 = 0b000001111111100000000;
		int temp2 = 0b000000000000011111111;
		
		if(code->operand1 != -1 || code->operand2 != -1 || code->operand3 != -1){
			Throw(op_error);
		}
		
		if(FSR[STKPTR] != 0){
			temp = PIC18Stack[FSR[STKPTR]];
		
			FSR[TOSU] = ((temp & temp0)>>16); 
			FSR[TOSH] = ((temp & temp1)>>8);
			FSR[TOSL] = (temp & temp2);
			PC = (FSR[TOSU]<<16) + (FSR[TOSH]<<8) + FSR[TOSL];
		
			FSR[STKPTR]--;
			value = PIC18Stack[FSR[STKPTR]];
			
			FSR[TOSU] = ((value & temp0)>>16); 
			FSR[TOSH] = ((value & temp1)>>8);
			FSR[TOSL] = (value & temp2);
	    }else{
			Throw(op_error);
		}
}
