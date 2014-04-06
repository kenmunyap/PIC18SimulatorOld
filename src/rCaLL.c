#include <stdio.h>
#include "Bytecode.h"
#include "rCALL.h"
#include "CException.h"

unsigned char FSR[0x1000];
int PC;

int  rcall(Bytecode *code) {
		/*
		*	relative call
		*	
		*	Throw: op_error if operand1 is over range -1028 to 10270
		*	Input: PC value
		*	Return: FSR[TOSH] FSR[TOSU] FSR[TOSL]
		*
		*/


		int value;
		int temp0 = 0b111110000000000000000;
		int temp1 = 0b000001111111100000000;
		int temp2 = 0b000000000000011111111;
	
	if(code->operand1<=-1028 || code->operand1 >= 1027){
			
			value = PC; 
			FSR[TOSU] = ((value & temp0)>>16); 
			FSR[TOSH] = ((value & temp1)>>8); 
			FSR[TOSL] = (value & temp2);
			printf("%d",FSR[TOSL]);
			PC = code->absoluteAddress + 2;

	}else{
		Throw(op_error);
	}
}

			